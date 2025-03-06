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
	void InitLib();			///相机接口初始化
	
private:
	int nRet;
	void* Handle;			//设备连接标志
	//bool CamConnected;		

public:
	//int EnumDevices(MV_CC_DEVICE_INFO_LIST* pstDevList);	///枚举设备

	void OpenCam();			///打开or连接到相机
		
	bool isOpen;			///相机开启标志位
	
	int StartGrabbing();	///开启抓图

	int StopGrabbing();		///停止抓图

	void GetImage();		///获取图像
	
	//HObject H_image;		///图像变量
	
	//std::vector<HObject> images;			///图像数组

	void CloseCam();		///关闭相机
	
	bool SaveImage(CString folder_path);	///保存图像
	
	//HTuple CString2HTuple(CString cString);	///变量类型转换

	///曝光时间设置****若不做设置，则使用默认曝光时间
	//void SetExposureTime(CGXFeatureControlPointer& objFeatureControlPtrint, double time);
	void SetExposureTime(float ExposureTimeNum);
};











