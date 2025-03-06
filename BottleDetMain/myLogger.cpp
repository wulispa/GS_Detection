#include "pch.h"
#include "myLogger.h"

myLogger* CWriter::m_pmyLogger = NULL;  //Ӧ��Ҳ���Խ���ʼ������Test0Dlg��

HANDLE m_hCatchLogSemaphore = ::CreateSemaphore(NULL, 0, MAX_SEMAPHORE, NULL);     //����һ���ռ��źŲ���ʼ��
HANDLE m_hCheckWMutex;
myLogger::myLogger()
{
	try//��ʼ��
	{
		m_bRun = false;
		m_bAllowWrite = false;

		m_sLogFilePath = GetLogFilePath();//log�ļ�
		m_sServerName = GetAppName();//������

		m_hWriteThread = NULL;//д�߳�
		m_hCheckThread = NULL;//����߳�
		m_hCacheLogMutex = ::CreateMutex(NULL, FALSE, NULL);//���������󴴽�(������־��)
		m_hCheckWMutex = ::CreateMutex(NULL, FALSE, NULL);//���������󴴽�(����д����)

		setlocale(LC_CTYPE, ("chs"));

		Start();
	}
	catch (...)//ʧ�ܴ���
	{
		AfxMessageBox(L"Create the logger object failed");
	}
}

myLogger::~myLogger()
{
	try
	{
		Stop();//ֹͣ
		if (NULL != m_hWriteThread)
		{
			(void)::CloseHandle(m_hWriteThread);//�رվ��
			m_hWriteThread = NULL;
		}
		if (NULL != m_hCacheLogMutex)
		{
			(void)::CloseHandle(m_hCacheLogMutex);
			m_hCacheLogMutex = NULL;
		}

		if (NULL != m_hCheckThread)
		{
			(void)::CloseHandle(m_hCheckThread);//�رվ��
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
	m_LogFstream.open(strFile.c_str(), ios::app | ios::out);//���ļ���ģʽΪ׷�Ӻ������ʽ
	if (!m_LogFstream)                                    //�޷����ļ�������RES_FAILED
	{
		AfxMessageBox(L"Open log file failed");
		return RES_FAILED;
	}

	m_bRun = true;

	unsigned long ulThreadID = 0;
	unsigned long ulThreadID2 = 1;
	m_hWriteThread = ::CreateThread(NULL, NULL, ThreadEntry, this, 0, &ulThreadID);//����һ���߳�
	m_hCheckThread = ::CreateThread(NULL, NULL, ThreadEntry2, this, 0, &ulThreadID2);
	if (NULL == m_hWriteThread)      //��������߳�ʧ�ܣ�����m_bRunΪfalse
	{
		m_bRun = false;
		return RES_FAILED;
	}

	m_bAllowWrite = true;      //���ÿ�д

	return RES_SUCCESS;
}

myLogger* CWriter::GetmyLoggerInstance()   //��ø����ָ��
{
	if (NULL == m_pmyLogger)
	{
		m_pmyLogger = new myLogger;
	}
	return m_pmyLogger;
}

void CWriter::DeletemyLoggerInstance()   //ɾ������ָ��
{
	if (NULL != m_pmyLogger)
	{
		m_pmyLogger->Stop();

		delete m_pmyLogger;
		m_pmyLogger = NULL;
	}
}

DWORD CALLBACK myLogger::ThreadEntry(LPVOID lpvoid)    //ָ���̺߳���
{
	myLogger* pmyLogger = (myLogger*)lpvoid;

	while (true)
	{
		WaitForSingleObject(m_hCatchLogSemaphore, INFINITE);//����
		string sLog = "";
		pmyLogger->GetCatchLogInfoEx(sLog);    //����ռ���Ϣ�������sLog��
		if (!sLog.empty())               //����õ��ռ�д���ı�
		{
			pmyLogger->WriteEx(sLog);
		}
	}

	return 0;
}
DWORD CALLBACK myLogger::ThreadEntry2(LPVOID lpvoid)    //ָ���̺߳���
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
	m_LogFstream.open(strFile.c_str(), ios::app | ios::out);//���ļ���ģʽΪ׷�Ӻ������ʽ
	if (!m_LogFstream)                                    //�޷����ļ�������RES_FAILED
	{
		AfxMessageBox(L"Open log file failed");
		return RES_FAILED;
	}
	return RES_SUCCESS;

}
int myLogger::WriteCache(const char* szFile, long lLine, long lType, const char* format, va_list argp)
{
	if (!m_bRun)//��δ����
	{
		return RES_FAILED;
	}

	if (!m_bAllowWrite)//��������д��
	{
		AfxMessageBox(L"log forbid to write");
		return RES_FAILED;
	}

	char cLogTmp[MAX_LOG_LENGTH] = { 0 };

	_vsnprintf_s(cLogTmp, sizeof(cLogTmp), format, argp);

	string sLogInfo = "";
	sLogInfo = cLogTmp;
	AddCatchLogInfoEx(sLogInfo);        //���ռ���Ϣ��ӵ�������

	ReleaseSemaphore(m_hCatchLogSemaphore, 1, NULL);     //�ͷ�m_hCatchLogSemaphore�ź���

	return RES_SUCCESS;
}

int myLogger::Write(const CString& sLog)
{
	CheckLogFile();
	//ȷ���ļ����ڣ��������ھʹ���

	if (!m_LogFile.Open(m_sLogFilePath, CFile::modeNoTruncate | CFile::modeWrite))   //���ļ������ʧ�ܵ�����Ϣ�����ش���
	{
		AfxMessageBox(L"Open log file failed");
		return RES_FAILED;
	}
	else     //����Ϣд���ļ�
	{
		m_LogFile.SeekToEnd();

		m_LogFile.WriteString(sLog);
		m_LogFile.Close();
		return RES_SUCCESS;
	}
}

int myLogger::WriteEx(const std::string& sLog)
{
	//д֮ǰȷ��ɾ��4��ǰ���ݼ������ļ��Ƿ����
	WaitForSingleObject(m_hCheckWMutex, INFINITE);
	if (sLog.empty())         //û��Ϣ��д�ͷ���RES_SUCCESS
	{
		return RES_SUCCESS;
		ReleaseMutex(m_hCheckWMutex);
	}
	if (!m_bRun)       //��m_bRun��Ϊ�棬���³�ʼ���ļ���
	{

		string strFile = FormatString(m_sLogFilePath);
		m_LogFstream.open(strFile.c_str(), ios::app | ios::out);
		if (!m_LogFstream)
		{
			AfxMessageBox(L"Open log file failed");
			return RES_FAILED;
		}
		m_LogFstream.seekp(ios::end);  //���ļ�����λ��ĩλ��
		ReleaseMutex(m_hCheckWMutex);
	}
	else         //m_bRunΪ�棬���ļ�������ݲ�ˢ��
	{
		m_LogFstream << sLog << endl;
		m_LogFstream.flush();
		ReleaseMutex(m_hCheckWMutex);
	}

	return RES_SUCCESS;
}

int myLogger::Stop()
{
	m_bAllowWrite = false;      //�رտ�д

	if (!m_bRun)                 //���Ѳ������У����ش���
	{
		return RES_SUCCESS;
	}

	m_bRun = false;           //�ر�����

	if (NULL != m_hWriteThread)     //д���߳������У���ֹ���̣߳����رվ��
	{
		(void)::TerminateThread(m_hWriteThread, 0);
		(void)::CloseHandle(m_hWriteThread);
		m_hWriteThread = NULL;
	}

	if (NULL != m_hCacheLogMutex)       //�رջ�����
	{
		(void)::CloseHandle(m_hCacheLogMutex);
		m_hCacheLogMutex = NULL;
	}

	if (NULL != m_hCheckThread)
	{
		(void)::TerminateThread(m_hCheckThread, 0);
		(void)::CloseHandle(m_hCheckThread);//�رվ��
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

CString myLogger::GetLevelString(long lType) const     //����ռǵȼ���Ϣ
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

CString myLogger::GetExtraInfo(long lType) const               //��ö�����Ϣ
{
	CString sExtraInfo = L"";
	CString sTm = L"";
	CString sType = L"";
	SYSTEMTIME systm;
	::GetLocalTime(&systm);
	sTm.Format(L"%04d-%02d-%02d %02d:%02d:%02d", systm.wYear, systm.wMonth, systm.wDay, systm.wHour, systm.wMinute, systm.wSecond);     //���ϵͳ��Ϣ
	sType = GetLevelString(lType);                        //����ռǵȼ���Ϣ
	sExtraInfo = L"Log " + sTm + L" " + m_sServerName + L"[" + sType + L"]: ";
	return sExtraInfo;
}

CString myLogger::GetAppName() const
{
	CString sProcessName, sName;
	GetModuleFileName(NULL, sProcessName.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);   //��õ�ǰ�����Ѽ���ģ����ļ�������·��
	sProcessName.ReleaseBuffer();         //�������

	//��ȡ������
	int posPath = sProcessName.ReverseFind('\\');
	sProcessName = sProcessName.Right(sProcessName.GetLength() - posPath - 1);
	int posName = sProcessName.ReverseFind('.');
	sName = sProcessName.Left(posName);
	return sName;
}

CString myLogger::GetLogFolderPath() const    //����ռ��ļ�·��
{
	CString sProcessPath, sLogFolderPath;
	GetModuleFileName(NULL, sProcessPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);  //��ȡ��ǰ�����Ѽ���ģ����ļ�������·��
	sProcessPath.ReleaseBuffer();
	int posPath = sProcessPath.ReverseFind('\\');
	sProcessPath = sProcessPath.Left(posPath);
	sLogFolderPath = sProcessPath + L"\\Log";
	if (!PathIsDirectory(sLogFolderPath))     //���ָ����Ŀ¼�Ƿ���ڣ��벻�����򴴽�
	{
		if (!CreateDirectory(sLogFolderPath, NULL))
		{
			AfxMessageBox(L"Create Log folder failed");
		}
	}
	return sLogFolderPath;
}

CString myLogger::GetLogFilePath()       //����ļ�����·����Ϣ
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

CString myLogger::GetLogFilePathPass()       //��ù�ȥ���ļ�����·����Ϣ
{
	CString sTm = L"";
	SYSTEMTIME systm;
	::GetLocalTime(&systm);
	WORD pwYear, pwMonth, pwDay;
	pwYear = systm.wYear;
	pwMonth = systm.wMonth;
	pwDay = systm.wDay;
	//����28��ǰ������
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
	if (!ff.FindFile(m_sLogFilePath))   //���û�ҵ����ļ����ʹ������ļ�
	{
		CStdioFile sf;
		CString sLogFile = GetLogFilePath();
		sf.Open(sLogFile, CFile::modeCreate);
		sf.Close();
	}
	ff.Close();



	return RES_SUCCESS;
}

int myLogger::AddCatchLogInfo(CString& sLog)         //����ռ���Ϣ��m_queCacheLog������
{
	WaitForSingleObject(m_hCacheLogMutex, INFINITE);
	m_queCacheLog.push(sLog);
	ReleaseMutex(m_hCacheLogMutex);
	return RES_SUCCESS;
}

int myLogger::AddCatchLogInfoEx(std::string& sLog)
{
	if (sLog.empty())       //������Ϊ�գ�����ʧ��
	{
		return RES_SUCCESS;
	}
	WaitForSingleObject(m_hCacheLogMutex, INFINITE);    //����
	m_queCacheLogEx.push(sLog);        //����Ϣ��ӵ�m_queCacheLogEx������
	ReleaseMutex(m_hCacheLogMutex);    //�ͷŻ�����
	return RES_SUCCESS;
}

int myLogger::GetCatchLogInfo(CString& sLog)      //��m_queCacheLog�����л���ռ���Ϣ
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

int myLogger::GetCatchLogInfoEx(std::string& sLog)    //��m_queCacheLogEx�����л���ռ���Ϣ
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

std::string myLogger::FormatString(CString& src)       //��CStringת�ɱ�׼string��
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
