#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Markup.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;

using namespace std;

/************************************************
*   ���ܣ���д�����ļ�������ʵ����XML�ļ������в���
*	���ڣ�2022/10/21
************************************************/

class MyXml
{
public:
	MyXml();
	~MyXml();
	CMarkup xml;
	CString FileName;
	unordered_map<string, string> Code_Vec_type2code;
	unordered_map<string, string> Code_Vec_code2type;
	string Code_Cur;
public:
	/************************************************
	*   ���ܣ�string���͵��ַ�������
	*	������
	*	����ֵ��
	************************************************/
	vector<string> split(const string& str, const string& pattern);

public:
	void OpenFile(CString filename);
	void CloseFile();

	/*-------------------------��ȡϵͳ����---------------------------
	ϵͳ������ProjectNums�� CameraList�� LightControlList��PreAlgList��
	DetAlgList�� OutPutList
	-----------------------------------------------------------------*/
public:
	CString rootName ;//���ڵ�����
	/************************************************
	*   ���ܣ�ö�������ӽڵ�����
	*	���������ڵ�����
	*	����ֵ��
	************************************************/
	vector<string> GetAllNodeName(string Father_name);



	/************************************************
	*   ���ܣ���ȡһ���ڵ�����
	*	������
	*	����ֵ��
	************************************************/
	string ReadNodeTxt(CString First_NodeName);

	/************************************************
	*   ���ܣ���ȡ�����ڵ�����
	*	������
	*	����ֵ��
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName);

	/************************************************
	*   ���ܣ���ȡ�����ڵ������
	*	������
	*	����ֵ��
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName);

	/************************************************
	*   ���ܣ���ȡ�ļ��ڵ������
	*	������
	*	����ֵ��
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName);

	/************************************************
	*   ���ܣ���ȡ�弶�ڵ������
	*	������
	*	����ֵ��
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Five_NodeName);

	/************************************************
	*   ���ܣ������Ŀ�ڵ�
	*	��������Ŀ����
	*	����ֵ��
	************************************************/
	void AddProject(CString ProjectName);

	/************************************************
	*   ���ܣ���ӹ�λ���
	*	��������Ŀ���ڵ�����
	*	����ֵ��
	************************************************/
	void AddState(CString ProjectName);

	/************************************************
	*   ���ܣ�ɾ����Ŀ�ڵ�ͽڵ��µ���������
	*	��������Ŀ����
	*	����ֵ��ɾ��״̬ 0����  -1��Ŀ������
	************************************************/
	int DeleteProjNode(CString ProjectName);

	/************************************************
	*   ���ܣ�дһ���ڵ�����
	*	������
	*	����ֵ��
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Write_Content);

	/************************************************
	*   ���ܣ�д�����ڵ�����
	*	������
	*	����ֵ��
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Write_Content);

	/************************************************
	*   ���ܣ�д�����ڵ������
	*	������
	*	����ֵ��
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Write_Content);

	/************************************************
	*   ���ܣ�д�ļ��ڵ������
	*	������
	*	����ֵ��
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Write_Content);

	/************************************************
	*   ���ܣ�д�ļ��ڵ������
	*	������
	*	����ֵ��
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Five_NodeName, CString Write_Content);

	/************************************************
	*   ���ܣ���д��Ŀ�ڵ�����
	*	������������ƿ�����ƺ����Ӧ�ļ������ڵ�����
	*	����ֵ��
	************************************************/
	int RenameBottleName(CString src, CString dst);

	/************************************************
	*   ���ܣ���ȡ�ͺű���
	*	������
	*	����ֵ��
	************************************************/
	unordered_map<string, string> Read_Code(CString xml_path);

	/************************************************
	*   ���ܣ�����ת����
	*	����������9������
	*	����ֵ��
	************************************************/
	string Coordinate2Code(std::vector<pair<int, int>> points, bool codeORtype);

	/************************************************
	*   ���ܣ�����ת�ͺ�
	*	������
	*	����ֵ��
	************************************************/
	string Code2Type(string code);

	/************************************************
	*   ���ܣ�������Բ
	*	������
	*	����ֵ��
	************************************************/
	bool circleLeastFit(const std::vector<pair<int, int>>& points, double& center_x, double& center_y, double& radius);

	/************************************************
	*   ���ܣ�������֮��ļн�
	*	������
	*	����ֵ��
	************************************************/
	double get_angle(double x1, double y1, double x2, double y2, double x3, double y3);
};

