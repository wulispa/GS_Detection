#include "pch.h"
#include "MyThreadPool.h"


//*************一般线程类******************//
MyThread::MyThread()
	: bIsWorking(FALSE)
	, jobFun(NULL)
	, jobCallback(NULL)
	, wParam(0)
	, lParam(0)

{
	hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ThreadProc, this, 0, 0);
}


MyThread::~MyThread()
{
	if (hThread != INVALID_HANDLE_VALUE)
	{
		jobFun = (TJobFun)INVALID_HANDLE_VALUE;
		jobCallback = (TJobCallback)INVALID_HANDLE_VALUE;
	}
	ResumeThread(hThread);
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
}

BOOL MyThread::IsWorking()
{
	return bIsWorking;
}

BOOL MyThread::SetWorking()
{
	bIsWorking = TRUE;
	return 0;
}


VOID MyThread::DoJob(TJobFun fun, WPARAM wp, LPARAM lp, TJobCallback cb)
{
	jobFun = fun;
	wParam = wp;
	lParam = lp;
	jobCallback = cb;
	ResumeThread(hThread);
	return VOID();
}

VOID MyThread::jobDone()
{
	bIsWorking = FALSE;
	SuspendThread(hThread);
	return VOID();
}

DWORD MyThread::ThreadProc(LPARAM lParam)
{
	MyThread *pThis = (MyThread *)lParam;
	while (true)
	{
		Sleep(10);
		if (pThis->jobFun == INVALID_HANDLE_VALUE || pThis->jobCallback == INVALID_HANDLE_VALUE)
		{
			break;
		}
		if (pThis->jobFun == NULL && pThis->jobCallback == NULL)
		{
			pThis->jobDone();
			continue;
		}
		UINT ret = pThis->jobFun(pThis->wParam, pThis->lParam);
		if (pThis->jobCallback)
		{
			pThis->jobCallback(ret);
		}
		pThis->jobDone();
	}
	return 0;
}

//*************一般线程池类******************//
MyThreadPool::MyThreadPool(int size)
{
	threadVector.clear();
	for (int i = 0; i < size; i++)
	{
		MyThread *thread = new MyThread();
		threadVector.push_back(thread);
	}
}


MyThreadPool::~MyThreadPool()
{
	vector<MyThread *>::iterator it = threadVector.begin();
	for ( ; it != threadVector.end(); )
	{
		MyThread *thread = *it++;
		delete thread;
	}
}

BOOL MyThreadPool::PushJob(TJobFun jobFun, WPARAM wParam, LPARAM lParam, TJobCallback callback)
{
	vector<MyThread *>::iterator it = threadVector.begin();
	for (; it != threadVector.end(); it++)
	{
		MyThread *thread = *it;
		if (!thread->IsWorking())
		{
			thread->SetWorking();
			thread->DoJob(jobFun, wParam, lParam, callback);
			return TRUE;
		}
	}

	//如果线程都忙，重新创建线程执行任务
	MyThread *thread = new MyThread();
	thread->SetWorking();
	threadVector.push_back(thread);
	thread->DoJob(jobFun, wParam, lParam, callback);
	return TRUE;
}

int MyThreadPool::GetPoolSeze()
{
	return threadVector.size();
}











