#pragma once
#include "publicspace.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

#include "MyXml.h"

using namespace std;
using namespace bodet;


/************************************************
*   ���ܣ���������ӿ�
*	���ڣ�2022-11-30
************************************************/

class DataManager
{
public:
	DataManager();
	~DataManager();
	CString xmlPath;
	MyXml myxml;

public:
	/************************************************
	*   ���ܣ�string���͵��ַ�������
	*	������
	*	����ֵ��
	************************************************/
	vector<string> split(const string& str, const string& pattern);


public:
/*------------------------------ƿ��Ʒ�ֲ���-------------------------------*/
	vector<string>BottleClasses;//ƿ�������б�
	string SelectBottleName;//ѡ�����ƿ������

	/************************************************
	*   ���ܣ�����ƿ��Ʒ�ֲ���
	*	������
	*	����ֵ��
	************************************************/
	void LoadBottleParam();

	/************************************************
	*   ���ܣ���ȡƿ�������б�
	*	������
	*	����ֵ��
	************************************************/
	void ReadBottleClasses();

	/************************************************
	*   ���ܣ�����������б���д�������ļ�
	*	������
	*	����ֵ��
	************************************************/
	void AddBottleClasses(CString bottleName);

	/************************************************
	*   ���ܣ����б���ɾ�����Ʋ��������ļ�
	*	������
	*	����ֵ��
	************************************************/
	void DeleteBottleClasses(CString bottleName);

	/************************************************
	*   ���ܣ�
	*	������
	*	����ֵ��
	************************************************/
	vector<string> GetBottleClasses() {return BottleClasses;}

	/************************************************
	*   ���ܣ���ȡѡ������
	*	������
	*	����ֵ��
	************************************************/
	string GetSelectBottleName() { return SelectBottleName; }

	/************************************************
	*   ���ܣ���ȡѡ������
	*	������
	*	����ֵ��
	************************************************/
	void ReadSelectBottleName();

	/************************************************
	*   ���ܣ�����ѡ�����ƣ���д�������ļ�
	*	������
	*	����ֵ��
	************************************************/
	void SetSelectBottleName(CString selectName);

	/************************************************
	*   ���ܣ��������ڵ�
	*	������
	*	����ֵ��
	************************************************/
	void ReNameBottleName(CString name, CString name2);
	
/*------------------------------ϵͳ����------------------------------*/
	//struct SystemParam
	//{
	//	//ϵͳ����
	//	string ThrowModel;//NORMAL  SUSTAIN  NO
	//	string ShowModel;//SUSTAIN  ONLYBAD
	//	string SaveModel;//NO AUTO AUTOBAD
	//	bool AutoLock;//true false
	//	int AutoLockTime;//
	//};
	SystemParam m_SystemParam;

	/************************************************
	*   ���ܣ�����ϵͳ����
	*	������
	*	����ֵ��
	************************************************/
	void LoadSystemParam();

	/************************************************
	*   ���ܣ���ȡϵͳ����
	*	������
	*	����ֵ��
	************************************************/
	SystemParam* GetSystemParam() {return &m_SystemParam;}

	/************************************************
	*   ���ܣ�������ƿ��ʽ
	*	������
	*	����ֵ��
	************************************************/
	void SetThrowModel(CString throwModel);

	/************************************************
	*   ���ܣ�������ʾģʽ
	*	������
	*	����ֵ��
	************************************************/
	void SetShowModel(CString showModel);

	/************************************************
	*   ���ܣ����ñ���ģʽ
	*	������
	*	����ֵ��
	************************************************/
	void SetSaveModel(CString saveModel);

	/************************************************
	*   ����:����ͼƬ����
	*	������
	*	����ֵ��
	************************************************/
	void SetImageType(CString imageType);

	/************************************************
	*   ����:��������ģʽ
	*	������
	*	����ֵ��
	************************************************/
	void SetAutoLock(CString autoLock);

	/************************************************
	*   ���ܣ���������ʱ��
	*	������
	*	����ֵ��
	************************************************/
	void SetAutoLockTime(CString autoLockTime);

	/************************************************
	*   ���ܣ�������������
	*	������
	*	����ֵ��
	************************************************/
	void SetBanSelect(CString BanSelect);
	/************************************************
	*   ���ܣ����õ�ǰ���
	*	������
	*	����ֵ��
	************************************************/
	void SetBanNumber(CString BanNumber);


/*---------------------------------������-----------------------------*/
	//struct BottleDetParam
	//{
	//	//�������
	//	int ExpostTime;
	//	string GainValue;
	//	string AutoSaveImage;
	//	//������
	//	string Model_Path;
	//	string Profile_Path;
	//	string ThreadValue;
	//	string Show_Region;
	//};
	BottleDetParam m_BottleDetParam;
	int GrabNum;//���Ų�ͼ/������ͼ
	vector<Mat> CamImages;
	/************************************************
	*   ���ܣ�
	*	������
	*	����ֵ��
	************************************************/
	//int GetNumImage();


	/************************************************
	*   ���ܣ����ؼ�����
	*	������
	*	����ֵ��
	************************************************/
	void LoadBottleDetParam();
	/************************************************
	*   ���ܣ�ʹ�ð�ťʱ���ڶ��ͼ��ؼ�����
	*	������
	*	����ֵ��
	************************************************/
	void LoadProductData();


	/************************************************
	*   ���ܣ���ȡ������
	*	������
	*	����ֵ��
	************************************************/
	BottleDetParam* GetBottleDetParam() { return &m_BottleDetParam; }

	

	/************************************************
	*   ���ܣ�
	*	������
	*	����ֵ��
	************************************************/
	//***********************ƿ�����**********
	void SetCameraOut(CString CameraOut);
	void SetTrigger(CString TriggerMode);
	void SetNumImage(CString GrabNum);
	void SetExpostTime(CString expostTime);
	void SetGainValue(CString gainValue);
	void SetAutoSaveImage(CString autoSaveImage);
	//***********************ģ�����**********
	void SetCameraOut1(CString CameraOut);
	void SetTrigger1(CString TriggerMode);
	void SetExpostTime1(CString expostTime);
	void SetGainValue1(CString gainValue);
	void SetAutoSaveImage1(CString autoSaveImage);
	//*************************������*************
	void SetModel_Path(CString model_Path);
	void SetProfile_Path(CString profile_Path);
	void SetThreadValue(CString threadValue);
	void SetThreadValueLW(CString threadValueLW);
	void SetThreadValueModel(CString threadValueModel);
	void SetChoseModel(CString ChoseModel);
	void SetGrayValue(CString GrayValue);
	void SetGrayThresh(CString GrayModel);
	void SetShow_Region(CString show_Region);
	void SetMoldRecognition(CString moldrecognition);	
	void SetSelectedMold(CString selectedmold);		
	void SetMoldModel_Path(CString moldmodel_path);
	void SetMoldProfile_Path(CString moldprofile_path);
	//GS����Ŀ
	void SetProductDate(CString productdata);  //GS�룺������������
	void SetCullParameters(CString TriggerDistance, CString PhotoelectricDistance);
	void SetPersonUse(CString Person);
	//****************��ͳ�㷨
	void SetTraditionalPara(CString contra_val, CString area_va, CString gray_val);//��ͳ�㷨����

};

