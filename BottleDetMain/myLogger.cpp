#include "pch.h"
#include "myLogger.h"

myLogger* CWriter::m_pmyLogger = NULL;  //应该也可以将初始化放在Test0Dlg中

HANDLE m_hCatchLogSemaphore = ::CreateSemaphore(NULL, 0, MAX_SEMAPHORE, NULL);     //定义一个日记信号并初始化
HANDLE m_hCheckWMutex;
myLogger::myLogger()
{
	try//初始化
	{
		m_bRun = false;
		m_bAllowWrite = false;

		m_sLogFilePath = GetLogFilePath();//log文件
		m_sServerName = GetAppName();//进程名

		m_hWriteThread = NULL;//写线程
		m_hCheckThread = NULL;//检查线程
		m_hCacheLogMutex = ::CreateMutex(NULL, FALSE, NULL);//互斥量对象创建(记载日志用)
		m_hCheckWMutex = ::CreateMutex(NULL, FALSE, NULL);//互斥量对象创建(检查或写入用)

		setlocale(LC_CTYPE, ("chs"));

		Start();
	}
	catch (...)//失败处理
	{
		AfxMessageBox(L"Create the logger object failed");
	}
}

myLogger::~myLogger()
{
	try
	{
		Stop();//停止
		if (NULL != m_hWriteThread)
		{
			(void)::CloseHandle(m_hWriteThread);//关闭句柄
			m_hWriteThread = NULL;
		}
		if (NULL != m_hCacheLogMutex)
		{
			(void)::CloseHandle(m_hCacheLogMutex);
			m_hCacheLogMutex = NULL;
		}

		if (NULL != m_hCheckThread)
		{
			(void)::CloseHandle(m_hCheckThread);//关闭句柄
			m_hCheckThread = NULL;
		}
		if (NULL != m_hCheckWMutex)
		{
			(void)::CloseHandle(m_hCheckWMutex);
			m_hCheckWMutex = NULL;
		}
		if (m_LogFstream)
		{
			m_LogFstream.close();
		}
	}
	catch (...)
	{
		AfxMessageBox(L"Clear the logger object failed");
	}
}
int myLogger::Start()
{
	if (m_bRun)
	{
		m_bAllowWrite = true;
		return RES_SUCCESS;
	}



	string strFile = FormatString(m_sLogFilePath);
	m_LogFstream.open(strFile.c_str(), ios::app | ios::out);//打开文件，模式为追加和输出方式
	if (!m_LogFstream)                                    //无法打开文件，返回RES_FAILED
	{
		AfxMessageBox(L"Open log file failed");
		return RES_FAILED;
	}

	m_bRun = true;

	unsigned long ulThreadID = 0;
	unsigned long ulThreadID2 = 1;
	m_hWriteThread = ::CreateThread(NULL, NULL, ThreadEntry, this, 0, &ulThreadID);//创建一个线程
	m_hCheckThread = ::CreateThread(NULL, NULL, ThreadEntry2, this, 0, &ulThreadID2);
	if (NULL == m_hWriteThread)      //如果创建线程失败，设置m_bRun为false
	{
		m_bRun = false;
		return RES_FAILED;
	}

	m_bAllowWrite = true;      //设置可写

	return RES_SUCCESS;
}

myLogger* CWriter::GetmyLoggerInstance()   //获得该类的指针
{
	if (NULL == m_pmyLogger)
	{
		m_pmyLogger = new myLogger;
	}
	return m_pmyLogger;
}

void CWriter::DeletemyLoggerInstance()   //删除该类指针
{
	if (NULL != m_pmyLogger)
	{
		m_pmyLogger->Stop();

		delete m_pmyLogger;
		m_pmyLogger = NULL;
	}
}

DWORD CALLBACK myLogger::ThreadEntry(LPVOID lpvoid)    //指向线程函数
{
	myLogger* pmyLogger = (myLogger*)lpvoid;

	while (true)
	{
		WaitForSingleObject(m_hCatchLogSemaphore, INFINITE);//挂起
		string sLog = "";
		pmyLogger->GetCatchLogInfoEx(sLog);    //获得日记信息，存放在sLog中
		if (!sLog.empty())               //将获得的日记写入文本
		{
			pmyLogger->WriteEx(sLog);
		}
	}

	return 0;
}
DWORD CALLBACK myLogger::ThreadEntry2(LPVOID lpvoid)    //指向线程函数
{
	myLogger* pmyLoggers = (myLogger*)lpvoid;

	while (true)
	{
		Sleep(60 * 60 * 1000);
		WaitForSingleObject(m_hCheckWMutex, INFINITE);
		pmyLoggers->CheckLogFile();
		pmyLoggers->Resetsfream();
		ReleaseMutex(m_hCheckWMutex);
	}

	return 0;
}
int myLogger::Resetsfream()
{
	m_LogFstream.close();
	string strFile = FormatString(m_sLogFilePath);
	m_LogFstream.open(strFile.c_str(), ios::app | ios::out);//打开文件，模式为追加和输出方式
	if (!m_LogFstream)                                    //无法打开文件，返回RES_FAILED
	{
		AfxMessageBox(L"Open log file failed");
		return RES_FAILED;
	}
	return RES_SUCCESS;

}
int myLogger::WriteCache(const char* szFile, long lLine, long lType, const char* format, va_list argp)
{
	if (!m_bRun)//若未运行
	{
		return RES_FAILED;
	}

	if (!m_bAllowWrite)//若不允许写入
	{
		AfxMessageBox(L"log forbid to write");
		return RES_FAILED;
	}

	char cLogTmp[MAX_LOG_LENGTH] = { 0 };

	_vsnprintf_s(cLogTmp, sizeof(cLogTmp), format, argp);

	string sLogInfo = "";
	sLogInfo = cLogTmp;
	AddCatchLogInfoEx(sLogInfo);        //将日记信息添加到队列中

	ReleaseSemaphore(m_hCatchLogSemaphore, 1, NULL);     //释放m_hCatchLogSemaphore信号量

	return RES_SUCCESS;
}

int myLogger::Write(const CString& sLog)
{
	CheckLogFile();
	//确认文件存在，若不存在就创建

	if (!m_LogFile.Open(m_sLogFilePath, CFile::modeNoTruncate | CFile::modeWrite))   //打开文件，如果失败弹出信息并返回错误
	{
		AfxMessageBox(L"Open log file failed");
		return RES_FAILED;
	}
	else     //将信息写入文件
	{
		m_LogFile.SeekToEnd();

		m_LogFile.WriteString(sLog);
		m_LogFile.Close();
		return RES_SUCCESS;
	}
}

int myLogger::WriteEx(const std::string& sLog)
{
	//写之前确认删除4周前数据及当日文件是否存在
	WaitForSingleObject(m_hCheckWMutex, INFINITE);
	if (sLog.empty())         //没信息可写就返回RES_SUCCESS
	{
		return RES_SUCCESS;
		ReleaseMutex(m_hCheckWMutex);
	}
	if (!m_bRun)       //若m_bRun不为真，重新初始化文件流
	{

		string strFile = FormatString(m_sLogFilePath);
		m_LogFstream.open(strFile.c_str(), ios::app | ios::out);
		if (!m_LogFstream)
		{
			AfxMessageBox(L"Open log file failed");
			return RES_FAILED;
		}
		m_LogFstream.seekp(ios::end);  //将文件流定位到末位置
		ReleaseMutex(m_hCheckWMutex);
	}
	else         //m_bRun为真，向文件输出数据并刷新
	{
		m_LogFstream << sLog << endl;
		m_LogFstream.flush();
		ReleaseMutex(m_hCheckWMutex);
	}

	return RES_SUCCESS;
}

int myLogger::Stop()
{
	m_bAllowWrite = false;      //关闭可写

	if (!m_bRun)                 //若已不在运行，返回错误
	{
		return RES_SUCCESS;
	}

	m_bRun = false;           //关闭运行

	if (NULL != m_hWriteThread)     //写入线程运行中，终止该线程，并关闭句柄
	{
		(void)::TerminateThread(m_hWriteThread, 0);
		(void)::CloseHandle(m_hWriteThread);
		m_hWriteThread = NULL;
	}

	if (NULL != m_hCacheLogMutex)       //关闭互斥量
	{
		(void)::CloseHandle(m_hCacheLogMutex);
		m_hCacheLogMutex = NULL;
	}

	if (NULL != m_hCheckThread)
	{
		(void)::TerminateThread(m_hCheckThread, 0);
		(void)::CloseHandle(m_hCheckThread);//关闭句柄
		m_hCheckThread = NULL;
	}
	if (NULL != m_hCheckWMutex)
	{
		(void)::CloseHandle(m_hCheckWMutex);
		m_hCheckWMutex = NULL;
	}
	if (m_LogFstream)
	{
		m_LogFstream.close();
	}

	return RES_SUCCESS;
}

CString myLogger::GetLevelString(long lType) const     //获得日记等级信息
{
	CString strLevel = L"";
	switch (lType)
	{
	case _MissCamera_:
		strLevel = L"MissCamera";
		break;
	case _LightControl_:
		strLevel = L"LightControl";
		break;
	case _Detection_:
		strLevel = L"Detection";
		break;
	case _WriteImage_:
		strLevel = L"WriteImage";
		break;
	case _UserCapture_:
		strLevel = L"UserCapture";
		break;
	case _Dongle_:
		strLevel = L"Dongle";
		break;
	default:
		strLevel = L"Unknown";
		break;
	}
	return strLevel;
}

CString myLogger::GetExtraInfo(long lType) const               //获得额外信息
{
	CString sExtraInfo = L"";
	CString sTm = L"";
	CString sType = L"";
	SYSTEMTIME systm;
	::GetLocalTime(&systm);
	sTm.Format(L"%04d-%02d-%02d %02d:%02d:%02d", systm.wYear, systm.wMonth, systm.wDay, systm.wHour, systm.wMinute, systm.wSecond);     //获得系统信息
	sType = GetLevelString(lType);                        //获得日记等级信息
	sExtraInfo = L"Log " + sTm + L" " + m_sServerName + L"[" + sType + L"]: ";
	return sExtraInfo;
}

CString myLogger::GetAppName() const
{
	CString sProcessName, sName;
	GetModuleFileName(NULL, sProcessName.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);   //获得当前进程已加载模块的文件的完整路径
	sProcessName.ReleaseBuffer();         //解除锁定

	//获取进程名
	int posPath = sProcessName.ReverseFind('\\');
	sProcessName = sProcessName.Right(sProcessName.GetLength() - posPath - 1);
	int posName = sProcessName.ReverseFind('.');
	sName = sProcessName.Left(posName);
	return sName;
}

CString myLogger::GetLogFolderPath() const    //获得日记文件路径
{
	CString sProcessPath, sLogFolderPath;
	GetModuleFileName(NULL, sProcessPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);  //获取当前进程已加载模块的文件的完整路径
	sProcessPath.ReleaseBuffer();
	int posPath = sProcessPath.ReverseFind('\\');
	sProcessPath = sProcessPath.Left(posPath);
	sLogFolderPath = sProcessPath + L"\\Log";
	if (!PathIsDirectory(sLogFolderPath))     //检查指定的目录是否存在，入不存在则创建
	{
		if (!CreateDirectory(sLogFolderPath, NULL))
		{
			AfxMessageBox(L"Create Log folder failed");
		}
	}
	return sLogFolderPath;
}

CString myLogger::GetLogFilePath()       //获得文件完整路径信息
{
	CString sTm = L"";
	SYSTEMTIME systm;
	::GetLocalTime(&systm);
	sTm.Format(L"%04d-%02d-%02d", systm.wYear, systm.wMonth, systm.wDay);
	CString sName = GetAppName();
	CString sLogFile = sName + "_" + sTm + L".log";
	CString sLogFolder = GetLogFolderPath();
	return (sLogFolder + L"\\" + sLogFile);
}

CString myLogger::GetLogFilePathPass()       //获得过去的文件完整路径信息
{
	CString sTm = L"";
	SYSTEMTIME systm;
	::GetLocalTime(&systm);
	WORD pwYear, pwMonth, pwDay;
	pwYear = systm.wYear;
	pwMonth = systm.wMonth;
	pwDay = systm.wDay;
	//处理28天前的日期
	if (pwDay > 28)
	{
		pwDay -= 28;
	}


	else if (pwDay <= 28)
	{
		pwDay = 28 - pwDay;
		pwMonth = pwMonth - 1;
		if (pwMonth == 0)
		{
			pwYear -= 1; pwMonth = 12;
		}
		if (pwMonth == 4 || pwMonth == 6 || pwMonth == 9 || pwMonth == 11)
		{
			pwDay = 30 - pwDay;
		}
		else if (pwMonth == 1 || pwMonth == 3 || pwMonth == 5 || pwMonth == 7 || pwMonth == 8 || pwMonth == 10 || pwMonth == 12)
		{
			pwDay = 31 - pwDay;
		}
		else if (pwMonth == 2)
		{
			if (pwYear % 400 == 0 || (pwYear % 4 == 0 && pwYear % 100 != 0))pwDay = 29 - pwDay;
			else pwDay = 28 - pwDay;
		}
	}

	sTm.Format(L"%04d%02d%02d", pwYear, pwMonth, pwDay);
	CString sName = GetAppName();
	CString sLogFile = sName + sTm + L".log";
	CString sLogFolder = GetLogFolderPath();
	return (sLogFolder + L"\\" + sLogFile);
}
int myLogger::CheckLogFile()
{

	CFileFind ss;
	CString spastFiles = GetLogFilePathPass();

	if (ss.FindFile(spastFiles))
	{
		ss.Close();
		DeleteFile(spastFiles);
	}

	m_sLogFilePath = GetLogFilePath();
	CFileFind ff;
	if (!ff.FindFile(m_sLogFilePath))   //如果没找到该文件，就创建该文件
	{
		CStdioFile sf;
		CString sLogFile = GetLogFilePath();
		sf.Open(sLogFile, CFile::modeCreate);
		sf.Close();
	}
	ff.Close();



	return RES_SUCCESS;
}

int myLogger::AddCatchLogInfo(CString& sLog)         //添加日记信息到m_queCacheLog队列中
{
	WaitForSingleObject(m_hCacheLogMutex, INFINITE);
	m_queCacheLog.push(sLog);
	ReleaseMutex(m_hCacheLogMutex);
	return RES_SUCCESS;
}

int myLogger::AddCatchLogInfoEx(std::string& sLog)
{
	if (sLog.empty())       //若参数为空，返回失败
	{
		return RES_SUCCESS;
	}
	WaitForSingleObject(m_hCacheLogMutex, INFINITE);    //挂起
	m_queCacheLogEx.push(sLog);        //将信息添加到m_queCacheLogEx队列中
	ReleaseMutex(m_hCacheLogMutex);    //释放互斥锁
	return RES_SUCCESS;
}

int myLogger::GetCatchLogInfo(CString& sLog)      //从m_queCacheLog队列中获得日记信息
{
	WaitForSingleObject(m_hCacheLogMutex, INFINITE);
	if (!m_queCacheLog.empty())
	{
		sLog = m_queCacheLog.front();
		m_queCacheLog.pop();
		ReleaseMutex(m_hCacheLogMutex);
	}
	return RES_SUCCESS;
}

int myLogger::GetCatchLogInfoEx(std::string& sLog)    //从m_queCacheLogEx队列中获得日记信息
{
	WaitForSingleObject(m_hCacheLogMutex, INFINITE);
	if (!m_queCacheLogEx.empty())
	{
		sLog = m_queCacheLogEx.front();
		m_queCacheLogEx.pop();
	}
	ReleaseMutex(m_hCacheLogMutex);
	return RES_SUCCESS;
}

std::string myLogger::FormatString(CString& src)       //将CString转成标准string型
{
	USES_CONVERSION;
	string InfoString;
	InfoString = T2A(src.GetBuffer(0));
	return InfoString;
}

LOGGER_API void __WriteLog(const char* szFileName, long lLine, long lType, const char* format, const va_list& argp)
{
	myLogger* pmyLogger = CWriter::GetmyLoggerInstance();
	pmyLogger->WriteCache(szFileName, lLine, lType, format, argp);
}

LOGGER_API string LOGSTRING(CString src)
{
	USES_CONVERSION;
	string InfoString;
	InfoString = T2A(src.GetBuffer(0));
	return InfoString;
}
