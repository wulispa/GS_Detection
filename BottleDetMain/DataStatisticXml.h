#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Markup.h"
#include <sstream>

using namespace std;

/************************************************
*   ���ܣ���д�����ļ�����������ͳ��XML�ļ������в���
*	���ڣ�2022/12/12
************************************************/

class DataStatisticXml
{
public:
	DataStatisticXml();
	~DataStatisticXml();
private:
	CMarkup xml;
	CString FileName;

public:
	void OpenFile(CString filename);
	void CloseFile();

	unordered_map<int, vector<int>> GetMonthData(int Year, int Month);
	/*-------------------------��ȡϵͳ����---------------------------
	ϵͳ������DatDetect�� Year�� Month��Day��Data
	-----------------------------------------------------------------*/
public:
	void UpdateYear(int YearNow);
	/************************************************
	*   ���ܣ�д�ļ��ڵ������
	*	������
	*	����ֵ��
	************************************************/
	void WriteNodeTxt(CString Year, CString Month, CString Day, CString Type, int Write_Content);


	CString rootName ;//���ڵ�����

	/************************************************
	*   ���ܣ���ȡ��ǰ���
	*	������
	*	����ֵ��
	************************************************/
	int ReadYear();

	/************************************************
	*   ���ܣ���ȡ�ļ��ڵ������
	*	��������OK/NG����
	*	����ֵ��
	************************************************/
	int ReadTypeData(CString Year, CString Month, CString Day, CString Type);

	/************************************************
	*   ���ܣ���ӹ�λ���
	*	��������
	*	����ֵ��
	************************************************/
	void AddState(int Year);

	/************************************************
	*   ���ܣ�ɾ����Ŀ�ڵ�ͽڵ��µ���������
	*	��������
	*	����ֵ��ɾ��״̬ 0����  -1��Ŀ������
	************************************************/
	int DeleteProjNode(int Year);

	/************************************************
	*   ���ܣ�ɾ����Ŀ�ڵ�ͽڵ��µ���������
	*	��������
	*	����ֵ��ɾ��״̬ 0����  -1��Ŀ������
	************************************************/
	int DeleteProjNode(int Year, int Month);

	/************************************************
	*   ���ܣ�ɾ����Ŀ�ڵ�ͽڵ��µ���������
	*	��������
	*	����ֵ��ɾ��״̬ 0����  -1��Ŀ������``
	************************************************/
	int DeleteProjNode(CString Year, CString Month, CString Day);

	/************************************************
	*   ���ܣ�ɾ����Ŀ�ڵ�ͽڵ��µ���������
	*	������OK.NG
	*	����ֵ��ɾ��״̬ 0����  -1��Ŀ������
	************************************************/
	int DeleteProjNode(CString Year, CString Month, CString Day, CString Type);

	/************************************************
	*   ���ܣ�дһ���ڵ�����
	*	������
	*	����ֵ��
	************************************************/
	void WriteYear(int YearNow);



	/************************************************
	*   ���ܣ���д��Ŀ�ڵ�����
	*	�������������ڵ�����
	*	����ֵ��
	************************************************/
	int RenameBottleName(CString src, CString dst);

	int str2int(string str);

	string int2str(int n);

	CString Year2CStr(int Year);

	CString Month2CStr(int Month);

	CString Day2CStr(int Day);

};

