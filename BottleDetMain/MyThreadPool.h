#pragma once
#include "pch.h"
#include <vector>

using namespace std;

//工作函数-----分配给线程对象的任务
typedef UINT(*TJobFun)(WPARAM wParam, LPARAM lParam);

//回调函数-----工作函数完成后的回调函数
typedef VOID(*TJobCallback)(UINT result);

//普通线程
class MyThread
{
public:
	MyThread();
	~MyThread();
	BOOL IsWorking();  //是否有任务正在运行
	BOOL SetWorking();  //是否有任务正在运行
	/************************************************
	*   功能：执行一个工作函数
	*	参数：
			fun：工作函数
			wp：工作函数第一个参数
			lp：工作函数第二个参数
			cb：执行完工作函数的回调函数
	*	返回值：VOID
	* 	修改日期：2022年11月08日
	************************************************/
	VOID DoJob(TJobFun fun, WPARAM wp, LPARAM lp, TJobCallback cb);    //执行一个工作函数

private:
	BOOL bIsWorking;
	TJobFun jobFun;             //工作函数
	TJobCallback jobCallback;   //回调函数
	WPARAM wParam;              //参数1
	LPARAM lParam;              //参数2
	HANDLE hThread;             //线程句柄
	VOID jobDone();             //任务已完成
	static DWORD WINAPI ThreadProc(LPARAM lParam);  //真正的线程函数
};

class MyThreadPool
{
public:
	MyThreadPool(int size = 2);
	~MyThreadPool();
	BOOL PushJob(TJobFun jobFun, WPARAM wParam = NULL, LPARAM lParam = NULL, TJobCallback callback = NULL);
	int GetPoolSeze();
private:
	vector<MyThread *> threadVector;
	
};

