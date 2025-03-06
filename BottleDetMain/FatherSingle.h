#pragma once
#include <Windows.h>

#include <atlstr.h>
#include <TlHelp32.h>
#include <iostream>

#define BUF_SIZE 40960




/*********************************************
 * @name		: 进程间通信
	使用信号量、共享内存实现进程间通信
 ********************************************/
class FatherSingle
{
public:
	FatherSingle();
	//FatherSingle(bool mySQL);
	~FatherSingle();

private:
	//共享内存
	//共享图像
	HANDLE hMapFile;
	LPVOID lpBase;
	LPVOID lpBase0;
	
	//共享返回值内存
	HANDLE hMapResult;

	//信号量
	HANDLE Father;
	HANDLE Child;
	

	//子进程名称
	CString ChildProgressName;

	//子进程状态
	bool isOpen;

	//设置进程窗口打开方式
	STARTUPINFO si;
	//子进程句柄
	PROCESS_INFORMATION pi;

	

public:
	VOID Init();

	//打开子进程
	VOID OpenProgress();

	//关闭子进程
	VOID CloseProgress();

	//获取子进程状态
	bool is_Open();

	//通知子进程工作
	BOOL ComWithoChild(int result);
	BOOL ComWithoChild(int* ptr_PLC_result,bool PickBottle);

	VOID SendResult(int result);
	VOID SendResult(int* ptr_PLC_result);


	//读取子进程信号
	int ReadFromChild();

	//发送图片
	//VOID SendImage(cv::Mat &image);
	BOOL ReadResult();

	//释放共享内存

	int Result;

	DWORD FatherSingle::GetProcessIDFromName(const WCHAR * name);



};

