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
	//�ر��źž��
	CloseHandle(Father);
	CloseHandle(Child);
	CloseHandle(hMapResult);
	//�رս��̾��
	CloseHandle(pi.hProcess);
	//�ر��ӽ������߳̾��
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
	//�����ź���
	Father = CreateSemaphore(NULL, FALSE, TRUE, TEXT("TOCHILD"));


	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	//Sleep(200);
	
	OpenProgress();

	//�����ڴ�
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,   // �����ļ����
		NULL,   // Ĭ�ϰ�ȫ����
		PAGE_READWRITE,   // �ɶ���д
		0,   // ��λ�ļ���С
		BUF_SIZE,   // ��λ�ļ���С
		L"ShareImage"   // �����ڴ�����
	);
	
	Sleep(400);
	//�����ź���
	//��ȡ���
	if (isOpen) {
		Child = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, TEXT("FROMCHILD")); 
		//����Ϊ "FROMCHILD" ���ź���
	}
	
	if ((Father == NULL) ) {
		std::cout << "�ź�ͨ����ȡʧ��"<<std::endl;
		//AfxMessageBox(TEXT("�ź�ͨ����ȡʧ��"));
	}
	if ((Child == NULL)) {
		//AfxMessageBox(TEXT("�ź�ͨ����ȡʧ��2"));
		std::cout << "�ź�ͨ����ȡʧ��2"<<std::endl;
	}

	hMapResult = OpenFileMapping(FILE_MAP_ALL_ACCESS, NULL, L"ShareResult");
	if (hMapResult) {}
	else {
		cout << "dakaishiba";
	}

	std::cout << "��ʼ���ɹ�" << std::endl;
}

VOID FatherSingle::OpenProgress()
{
	//���ӽ���
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
	//std::cout << "���ӽ��̷�����Ϣ";
	SendResult(result);
	ReleaseSemaphore(Father, 1, NULL);

	//����ͼƬ
	//SendImage(image);
	Sleep(5);
	//do something
	
	//WaitForSingleObject(Child, INFINITE);
	//Result = ReadFromChild();
	//�رչ����ڴ�
	//UnmapViewOfFile(lpBase);
	//do something
	
	//std::cout << "�յ��ӽ��̻ظ�";
	//AfxMessageBox(TEXT("�յ��ظ�"));
	return TRUE;
}

BOOL FatherSingle::ComWithoChild(int* ptr_PLC_result, bool PickBottle)
{
	if (!isOpen) {
		OpenProgress();
	}
	Result = 0;
	//std::cout << "���ӽ��̷�����Ϣ";
	SendResult(ptr_PLC_result); //�ŵ������ڴ�
	ReleaseSemaphore(Father, 1, NULL); //������һ���źŸ���

	//����ͼƬ
	//SendImage(image);
	Sleep(5);
	//do something

	WaitForSingleObject(Child, INFINITE);//�����ӽ����꣬�ӷ��ͻ�һ���ź�
	Sleep(5);

	if (PickBottle)
	{
		ReleaseSemaphore(Father, 1, NULL);
		Sleep(5);
		WaitForSingleObject(Child, INFINITE);
	}

	//ReadResult = ReadFromChild();
	//����ڴ�ӳ��
	//UnmapViewOfFile(hMapResult);
	//do something
	//std::cout << "�յ��ӽ��̻ظ�";
	//AfxMessageBox(TEXT("�յ��ظ�"));
	return TRUE;



	
}

int FatherSingle::ReadFromChild()
{
	//std::cout << "���ܼ����" << std::endl;
	LPVOID lpBase1 = MapViewOfFile(hMapResult, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	int result;
	memcpy(&result, lpBase1, 4);
	//std::cout << "�������" << result << std::endl;
	//����ڴ�ӳ��
	UnmapViewOfFile(lpBase1);
	return result;
}

VOID FatherSingle::SendResult(int result)
{

	//int a = 10;
	//memcpy(lpBase, &a, 4);
	lpBase = MapViewOfFile(
		hMapResult,            // �����ڴ�ľ��
		FILE_MAP_ALL_ACCESS, // �ɶ�д���
		0,
		0,
		BUF_SIZE
	);

	memcpy(lpBase, &result, sizeof(result));
	UnmapViewOfFile(lpBase);


}

VOID FatherSingle::SendResult(int* ptr_PLC_result)
{
	// 0-5 ��ƿλ�ã� 6 ������
	int WRITE_IN[2];
	for (int i = 0; i < 2; i++)
	{
		WRITE_IN[i] = ptr_PLC_result[i];
	}

	lpBase0 = MapViewOfFile(
		hMapResult,            // �����ڴ�ľ��
		FILE_MAP_ALL_ACCESS, // �ɶ�д���
		0,
		0,
		BUF_SIZE
	);
	if (lpBase0 != NULL) {
		memcpy(lpBase0, &WRITE_IN, sizeof(WRITE_IN));//д��
		UnmapViewOfFile(lpBase0);  //�ر�
	}
}

//VOID FatherSingle::SendImage(cv::Mat &image)
//{
//	cv::Mat dst_mat = image(cv::Rect(0, 0, 250, 250));
//	std::vector<uchar> jpg_buff;
//	//ͼ�����
//	bool ret = cv::imencode(".jpg", dst_mat, jpg_buff);
//		lpBase = MapViewOfFile(
//			hMapFile,            // �����ڴ�ľ��
//			FILE_MAP_ALL_ACCESS, // �ɶ�д���
//			0,
//			0,
//			BUF_SIZE
//		);
//		memcpy(lpBase, &jpg_buff[0], 15676);
//		//Sleep(15000);
//		// ����ļ�ӳ��
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
