//
//  ��־��¼�࣬��������Ƶ����ԣ����κεط�����LOG()���ɽ�����־��¼
//  ��Ҫע����ǣ��ڳ�����������뽨��һ��CWriter�����Ա�����˳�ʱ������������������ֹ�ڴ�й©

#pragma once                     

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <Windows.h>

using namespace std;

#define RES_SUCCESS 0
#define RES_FAILED -1

#define MAX_SEMAPHORE 256
#define MAX_LOG_LENGTH 1024

#define LOGGER_API

/************************

Debug	������־
Info	��ͨ��־
Notice	ע����־
Warn	������־
Error	������־
Fatal	������־

*************************/
enum LogtType {
	_MissCamera_ = 0,  //��ʧ���
	_LightControl_,	   //������Դ�Ĵ���
	_Detection_,	   //����㷨�쳣�������Ҫ�ǷǱ�׼ͼ��
	_WriteImage_,	   //������Ƭ�Ĵ���
	_UserCapture_,	   //�û�����
	_Dongle_,		   //���ܹ���֤ʧ�ܵĸ��ִ���
};

class myLogger//��־�����ļ�
{
public:
	myLogger();
public:
	virtual ~myLogger();

public:
	int Start();  //��ʼlogger
	int Stop();   //ֹͣ����
public:
	int Write(const CString& sLog);  //ʵ���ϲ���ʹ��
	int WriteEx(const std::string& sLog);  //���Write()����ɾ��4��ǰ������һ��
	int WriteCache(const char* szFile, long lLine, long lType, const char* format, va_list argp);


private:
	static DWORD CALLBACK ThreadEntry(LPVOID lpvoid);
	static DWORD CALLBACK ThreadEntry2(LPVOID lpvoid);
public:
	CString GetLevelString(long lType) const;
	CString GetExtraInfo(long lType) const;
	CString GetAppName() const;
	CString GetLogFolderPath() const;
	CString GetLogFilePath();
	CString GetLogFilePathPass();
public:
	int CheckLogFile();
public:
	std::string FormatString(CString& src);
public:
	int AddCatchLogInfo(CString& sLog);
	int GetCatchLogInfo(CString& sLog);
	int AddCatchLogInfoEx(std::string& sLog);
	int GetCatchLogInfoEx(std::string& sLog);
	int Resetsfream();
private:
	bool m_bRun;
	bool m_bAllowWrite;
	CString m_sLogFilePath;
	CString m_sServerName;
private:
	HANDLE m_hWriteThread;
	HANDLE m_hCacheLogMutex;
	HANDLE m_hCheckThread;

private:
	std::queue<CString> m_queCacheLog; //cstring����
	std::queue<std::string> m_queCacheLogEx;//string����
private:
	CStdioFile m_LogFile;  //��ʽ�ļ���ʵ���ϲ���ʹ��
	fstream m_LogFstream;  //�ļ���
};


LOGGER_API void __StartLog(void);
LOGGER_API void __StopLog(void);
LOGGER_API void __WriteLog(const char* szFileName, long lLine, long lType, const char* format, const va_list& argp);//�䳤��������

LOGGER_API string LOGSTRING(CString src);

class CWriter
{
public:
	CWriter() { deletemyLogger = true; }
	CWriter(const char* file, long line)
	{
		m_file_ = file;
		m_line_ = line;
		deletemyLogger = false;
	}
	~CWriter() {
		if (deletemyLogger) {
			DeletemyLoggerInstance();
		}
	}
	void operator()(long type, const char* format, ...)
	{
		va_list argp;
		va_start(argp, format);
		__WriteLog(m_file_, m_line_, type, format, argp);
		va_end(argp);
	}
	const char* m_file_;
	long m_line_;

public:
	static myLogger* GetmyLoggerInstance();
	static void DeletemyLoggerInstance();
private:
	static myLogger* m_pmyLogger; //����ģʽ
	bool deletemyLogger;
};

//���κεط�����LOG()���ɽ�����־��¼
#define LOG (CWriter(__FILE__, __LINE__))