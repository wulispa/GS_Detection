#pragma once
#include <Windows.h>

#include <atlstr.h>
#include <TlHelp32.h>
#include <iostream>

#define BUF_SIZE 40960




/*********************************************
 * @name		: ���̼�ͨ��
	ʹ���ź����������ڴ�ʵ�ֽ��̼�ͨ��
 ********************************************/
class FatherSingle
{
public:
	FatherSingle();
	//FatherSingle(bool mySQL);
	~FatherSingle();

private:
	//�����ڴ�
	//����ͼ��
	HANDLE hMapFile;
	LPVOID lpBase;
	LPVOID lpBase0;
	
	//������ֵ�ڴ�
	HANDLE hMapResult;

	//�ź���
	HANDLE Father;
	HANDLE Child;
	

	//�ӽ�������
	CString ChildProgressName;

	//�ӽ���״̬
	bool isOpen;

	//���ý��̴��ڴ򿪷�ʽ
	STARTUPINFO si;
	//�ӽ��̾��
	PROCESS_INFORMATION pi;

	

public:
	VOID Init();

	//���ӽ���
	VOID OpenProgress();

	//�ر��ӽ���
	VOID CloseProgress();

	//��ȡ�ӽ���״̬
	bool is_Open();

	//֪ͨ�ӽ��̹���
	BOOL ComWithoChild(int result);
	BOOL ComWithoChild(int* ptr_PLC_result,bool PickBottle);

	VOID SendResult(int result);
	VOID SendResult(int* ptr_PLC_result);


	//��ȡ�ӽ����ź�
	int ReadFromChild();

	//����ͼƬ
	//VOID SendImage(cv::Mat &image);
	BOOL ReadResult();

	//�ͷŹ����ڴ�

	int Result;

	DWORD FatherSingle::GetProcessIDFromName(const WCHAR * name);



};

