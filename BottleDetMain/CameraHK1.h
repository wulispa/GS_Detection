#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <opencv.hpp>
#include "DataManager.h"
#include "MvCameraControl.h"
#include "HalconCpp.h"

using namespace std;
using namespace cv;
using namespace HalconCpp;

class CameraHK1
{
public:
	CameraHK1();
	CameraHK1(DataManager* pdata);
	CameraHK1(const CameraHK1& obj);//拷贝构造
	CameraHK1& operator=(const CameraHK1& obj);//重载=
	~CameraHK1();
private:
	HObject sImage;
	//vector<HObject>ProductImages12;
	Mat SingleImage;//单张图片
	vector<Mat>ProductImages;//一组图片
	bool isOpen;
	int nRet;
	void* Handle;			//设备连接标志
	int CameraType;//采图方式 单步采集，连续采集
	bool missCamera;//相机离线标志
	bool GraphSuccess;
	DataManager* m_pData;//参数管理
	//string CurrentIp;
	//string NetExportIp;
	unsigned char* pData;
	float ExposureTimeNum, GainNum;
	//int CamGrabNum;

private:
	MV_CC_DEVICE_INFO_LIST stDeviceList;
	unsigned int SelectCamIndex;
	std::string CamId;
public:
	/************************************************
	*   功能：获取相机连接状态
	*	参数：
	*	返回值：
	************************************************/
	bool IsOpen();

	/************************************************
	*   功能：
	*	参数：
	*	返回值：
	************************************************/
	void SetCameraParam();

	/************************************************
	*   功能：抓图
	*	参数：
	*	返回值：1 成功  -1失败
	************************************************/
	int GraphImage();

	/************************************************
	*   功能：停止抓图
	*	参数：
	*	返回值：
	************************************************/
	int StopGraphImage();

	/************************************************
	*   功能：打开相机
	*	参数：
	*	返回值：
	************************************************/
	bool OpenCamera();

	/************************************************
	*   功能：重启相机
	*	参数：
	*	返回值：
	************************************************/
	bool RestartCamera();

	/************************************************
	*   功能：关闭相机
	*	参数：
	*	返回值：
	************************************************/
	bool CloseCamera();

	/************************************************
	*   功能：返回图像
	*	参数：
	*	返回值：
	************************************************/
	Mat GetImage();//返回一张图片
	vector<Mat> GetImages();//返回一组图片
	//HObject GetImage();//返回一张图片
	//vector<HObject> GetImages(int num);//返回一组图片

	/************************************************
	*   功能：相机离线
	*	参数：
	*	返回值：
	************************************************/
	bool isMissCamera();

	/************************************************
	*   功能：相机采图成功
	*	参数：
	*	返回值：
	************************************************/
	bool isSuccessGraph();

	/************************************************
	*   功能：刷新相机参数
	*	参数：
	*	返回值：
	************************************************/
	bool UpdateCamera();

	void OutPutResult();

	void SetTriggerModel(bool Soft);

	//int SavelmageToFile(void* handle, unsigned char* p_BufAddr, unsigned short n_Width, unsigned short n_Height, MvGvspPixelType en_PixelType, unsigned int n_FrameLen);
	//int SaveImageToFile(void* handle, unsigned char* p_BufAddr, unsigned short n_Width, unsigned short n_Height, enum MvGvspPixelType en_PixelType, unsigned int n_FrameLen);
	unsigned char* pImage;
	cv::Mat HImageToMat(HalconCpp::HObject& H_img);
public:
	HANDLE hCameraThread;//采图线程

	/************************************************
	*   功能：为相机采图单独开辟线程，避免系统停止后，相机采图冲突的问题。
	* 具体实现思路如下：
	* 开辟新的线程，调用图像接口采集图像，停止采集时挂起线程，开始采集时唤醒线程。
	************************************************/

};

