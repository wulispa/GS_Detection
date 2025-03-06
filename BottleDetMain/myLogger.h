//
//  日志纪录类，由于其设计的特性，在任何地方调用LOG()即可进行日志记录
//  需要注意的是，在程序主界面必须建立一个CWriter对象，以便程序退出时调用其析构函数，防止内存泄漏

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

Debug	调试日志
Info	普通日志
Notice	注意日志
Warn	警告日志
Error	错误日志
Fatal	致命日志

*************************/
enum LogtType {
	_MissCamera_ = 0,  //丢失相机
	_LightControl_,	   //调整光源的错误
	_Detection_,	   //检测算法异常或错误（主要是非标准图像）
	_WriteImage_,	   //保存照片的错误
	_UserCapture_,	   //用户拍照
	_Dongle_,		   //加密狗验证失败的各种错误
};

class myLogger//日志生成文件
{
public:
	myLogger();
public:
	virtual ~myLogger();

public:
	int Start();  //开始logger
	int Stop();   //停止运行
public:
	int Write(const CString& sLog);  //实际上不再使用
	int WriteEx(const std::string& sLog);  //相比Write()多了删除4周前数据这一步
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
	std::queue<CString> m_queCacheLog; //cstring队列
	std::queue<std::string> m_queCacheLogEx;//string队列
private:
	CStdioFile m_LogFile;  //流式文件，实际上不再使用
	fstream m_LogFstream;  //文件流
};


LOGGER_API void __StartLog(void);
LOGGER_API void __StopLog(void);
LOGGER_API void __WriteLog(const char* szFileName, long lLine, long lType, const char* format, const va_list& argp);//变长参数函数

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
	static myLogger* m_pmyLogger; //单例模式
	bool deletemyLogger;
};

//在任何地方调用LOG()即可进行日志记录
#define LOG (CWriter(__FILE__, __LINE__))