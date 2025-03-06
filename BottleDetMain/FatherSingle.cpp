#include "pch.h"
#include "FatherSingle.h"
using namespace std;


FatherSingle::FatherSingle()
{
	ChildProgressName = TEXT("D:\\OcrDetect\\ConsoleApplication1\\x64\\Debug\\ConsoleApplication1.exe");

	DWORD pid = GetProcessIDFromName(_T("ConsoleApplication1.exe"));
	if (-1 != pid)
	{
		TerminateProcess(OpenProcess(PROCESS_TERMINATE, false, pid), 0);
	}




	Result=0;
	isOpen = false;
	
	Init();
	

	
}

//FatherSingle::FatherSingle(bool mySQL)
//{
//	ChildProgressName = TEXT("D:\\InfoSystem\\x64\\Debug\\InfoSystem.exe");
//
//}


FatherSingle::~FatherSingle()
{
	//关闭信号句柄
	CloseHandle(Father);
	CloseHandle(Child);
	CloseHandle(hMapResult);
	//关闭进程句柄
	CloseHandle(pi.hProcess);
	//关闭子进程主线程句柄
	CloseHandle(pi.hThread);
	CloseHandle(hMapFile);


	DWORD pid = GetProcessIDFromName(_T("ConsoleApplication2.exe"));
	if (-1 != pid)
	{
		TerminateProcess(OpenProcess(PROCESS_TERMINATE, false, pid), 0);
	}

	DWORD pid1 = GetProcessIDFromName(_T("InfoSystem.exe"));
	if (-1 != pid1)
	{
		TerminateProcess(OpenProcess(PROCESS_TERMINATE, false, pid1), 0);
	}
	
}

VOID FatherSingle::Init()
{
	//创建信号量
	Father = CreateSemaphore(NULL, FALSE, TRUE, TEXT("TOCHILD"));


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	//Sleep(200);
	
	OpenProgress();

	//共享内存
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,   // 物理文件句柄
		NULL,   // 默认安全级别
		PAGE_READWRITE,   // 可读可写
		0,   // 高位文件大小
		BUF_SIZE,   // 低位文件大小
		L"ShareImage"   // 共享内存名称
	);
	
	Sleep(400);
	//创建信号量
	//读取结果
	if (isOpen) {
		Child = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, TEXT("FROMCHILD")); 
		//打开名为 "FROMCHILD" 的信号量
	}
	
	if ((Father == NULL) ) {
		std::cout << "信号通道获取失败"<<std::endl;
		//AfxMessageBox(TEXT("信号通道获取失败"));
	}
	if ((Child == NULL)) {
		//AfxMessageBox(TEXT("信号通道获取失败2"));
		std::cout << "信号通道获取失败2"<<std::endl;
	}

	hMapResult = OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"ShareResult");
	if (hMapResult) {}
	else {
		cout << "dakaishiba";
	}

	std::cout << "初始化成功" << std::endl;
}

VOID FatherSingle::OpenProgress()
{
	//打开子进程
	if (CreateProcess(ChildProgressName,NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		isOpen = true;
	}
	else
	{
		isOpen = false;
	}
}

VOID FatherSingle::CloseProgress()
{
	return VOID();
}

bool FatherSingle::is_Open()
{
	return isOpen;
}

BOOL FatherSingle::ComWithoChild(int result)
{
	if (!isOpen) {
		OpenProgress();
	}
	Result=0;
	//std::cout << "向子进程发送消息";
	SendResult(result);
	ReleaseSemaphore(Father, 1, NULL);

	//发送图片
	//SendImage(image);
	Sleep(5);
	//do something
	
	//WaitForSingleObject(Child, INFINITE);
	//Result = ReadFromChild();
	//关闭共享内存
	//UnmapViewOfFile(lpBase);
	//do something
	
	//std::cout << "收到子进程回复";
	//AfxMessageBox(TEXT("收到回复"));
	return TRUE;
}

BOOL FatherSingle::ComWithoChild(int* ptr_PLC_result, bool PickBottle)
{
	if (!isOpen) {
		OpenProgress();
	}
	Result = 0;
	//std::cout << "向子进程发送消息";
	SendResult(ptr_PLC_result); //放到共享内存
	ReleaseSemaphore(Father, 1, NULL); //父发送一个信号给子

	//发送图片
	//SendImage(image);
	Sleep(5);
	//do something

	WaitForSingleObject(Child, INFINITE);//父等子接受完，子发送回一个信号
	Sleep(5);

	if (PickBottle)
	{
		ReleaseSemaphore(Father, 1, NULL);
		Sleep(5);
		WaitForSingleObject(Child, INFINITE);
	}

	//ReadResult = ReadFromChild();
	//解除内存映射
	//UnmapViewOfFile(hMapResult);
	//do something
	//std::cout << "收到子进程回复";
	//AfxMessageBox(TEXT("收到回复"));
	return TRUE;



	
}

int FatherSingle::ReadFromChild()
{
	//std::cout << "接受检测结果" << std::endl;
	LPVOID lpBase1 = MapViewOfFile(hMapResult, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	int result;
	memcpy(&result, lpBase1, 4);
	//std::cout << "检测结果：" << result << std::endl;
	//解除内存映射
	UnmapViewOfFile(lpBase1);
	return result;
}

VOID FatherSingle::SendResult(int result)
{

	//int a = 10;
	//memcpy(lpBase, &a, 4);
	lpBase = MapViewOfFile(
		hMapResult,            // 共享内存的句柄
		FILE_MAP_ALL_ACCESS, // 可读写许可
		0,
		0,
		BUF_SIZE
	);

	memcpy(lpBase, &result, sizeof(result));
	UnmapViewOfFile(lpBase);


}

VOID FatherSingle::SendResult(int* ptr_PLC_result)
{
	// 0-5 剔瓶位置， 6 光电距离
	int WRITE_IN[2];
	for (int i = 0; i < 2; i++)
	{
		WRITE_IN[i] = ptr_PLC_result[i];
	}

	lpBase0 = MapViewOfFile(
		hMapResult,            // 共享内存的句柄
		FILE_MAP_ALL_ACCESS, // 可读写许可
		0,
		0,
		BUF_SIZE
	);
	if (lpBase0 != NULL) {
		memcpy(lpBase0, &WRITE_IN, sizeof(WRITE_IN));//写入
		UnmapViewOfFile(lpBase0);  //关闭
	}
}

//VOID FatherSingle::SendImage(cv::Mat &image)
//{
//	cv::Mat dst_mat = image(cv::Rect(0, 0, 250, 250));
//	std::vector<uchar> jpg_buff;
//	//图像编码
//	bool ret = cv::imencode(".jpg", dst_mat, jpg_buff);
//		lpBase = MapViewOfFile(
//			hMapFile,            // 共享内存的句柄
//			FILE_MAP_ALL_ACCESS, // 可读写许可
//			0,
//			0,
//			BUF_SIZE
//		);
//		memcpy(lpBase, &jpg_buff[0], 15676);
//		//Sleep(15000);
//		// 解除文件映射
//		//UnmapViewOfFile(lpBase);
//}

DWORD FatherSingle::GetProcessIDFromName(const WCHAR * name)
{
	HANDLE snapshot;
	PROCESSENTRY32 processinfo;
	processinfo.dwSize = sizeof(processinfo);
	snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot == NULL)
		return FALSE;

	BOOL status = Process32First(snapshot, &processinfo);
	while (status)
	{
		if (_wcsicmp(name, processinfo.szExeFile) == 0)
			return processinfo.th32ProcessID;
		status = Process32Next(snapshot, &processinfo);
	}
	return -1;
}
