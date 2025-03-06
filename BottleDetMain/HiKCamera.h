#pragma once
//#include "stdafx.h"
//#include "HalconCpp.h"
#include "MvCameraControl.h"
#include <vector>

//using namespace HalconCpp;
//using namespace std;

#ifndef MV_NULL
#define MV_NULL    0
#endif

class HiKCamera{
public:
	HiKCamera();
	~HiKCamera();

public:
	void InitLib();			///����ӿڳ�ʼ��
	
private:
	int nRet;
	void* Handle;			//�豸���ӱ�־
	//bool CamConnected;		

public:
	//int EnumDevices(MV_CC_DEVICE_INFO_LIST* pstDevList);	///ö���豸

	void OpenCam();			///��or���ӵ����
		
	bool isOpen;			///���������־λ
	
	int StartGrabbing();	///����ץͼ

	int StopGrabbing();		///ֹͣץͼ

	void GetImage();		///��ȡͼ��
	
	//HObject H_image;		///ͼ�����
	
	//std::vector<HObject> images;			///ͼ������

	void CloseCam();		///�ر����
	
	bool SaveImage(CString folder_path);	///����ͼ��
	
	//HTuple CString2HTuple(CString cString);	///��������ת��

	///�ع�ʱ������****���������ã���ʹ��Ĭ���ع�ʱ��
	//void SetExposureTime(CGXFeatureControlPointer& objFeatureControlPtrint, double time);
	void SetExposureTime(float ExposureTimeNum);
};











