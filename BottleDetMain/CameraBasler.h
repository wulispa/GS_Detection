#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <opencv.hpp>
#include "DataManager.h"
//#include "MvCameraControl.h"
#include "HalconCpp.h"
//#include "TypeTrans.h"
#include <pylon/PylonIncludes.h>
//#include <pylon/TlFactory.h>

#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif
//#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/usb/_UsbStreamParams.h>
#include <pylon/usb/BaslerUsbInstantCamera.h>
#include <pylon/usb/_BaslerUsbCameraParams.h>

using namespace std;
using namespace cv;
using namespace HalconCpp;
using namespace Pylon;
//using namespace Basler_GigECamera;
using namespace Basler_UsbCameraParams;
using namespace GenApi;

/************************************************
*   功能：相机接口
*	日期：2023
************************************************/

class CameraBasler
{
public:
	CameraBasler();
	CameraBasler(DataManager* pdata);
	CameraBasler(const CameraBasler& obj);//拷贝构造
	CameraBasler& operator=(const CameraBasler& obj);//重载=
	~CameraBasler();
private:
	HObject sImage;
	vector<HObject>ProductImages12;
	Mat SingleImage;//单张图片
	vector<Mat>ProductImages;//一组图片
	bool isOpen;
	int nRet;
	void* Handle;			//设备连接标志
	int CameraType;//采图方式 单步采集，连续采集
	bool missCamera;//相机离线标志
	bool GraphSuccess;
	string CurrentIp;
	string NetExportIp;
	unsigned char* pData;
	float ExposureTimeNum, GainNum, AcquisitionLineRateNum;

//private:
	//CBaslerGigEInstantCamera camera;
	//CBaslerGigECamera camera;
	//CInstantCamera camera;
	CBaslerUsbInstantCamera camera;

	//CGrabResultPtr ptrGrabResult;	//数据流
	//INodeMap& nodemap;//参数
	//MV_CC_DEVICE_INFO_LIST stDeviceList;
	//unsigned int SelectCamIndex;
	//std::string CamId;
public:
	DataManager* m_pData;//参数管理

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
	int GraphImage(int choose);

	/************************************************
	*   功能：停止抓图
	*	参数：
	*	返回值：
	************************************************/
	void StopGraphImage();

	/************************************************
	*   功能：打开相机
	*	参数：
	*	返回值：
	************************************************/
	bool OpenCamera();
	bool OpenCamera(string CamID, int step);

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
	Mat GetImage(int Choose_Cam);//返回一张图片
	HObject Get_Image(int n);//返回一张图片

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
	//bool UpdateCamera();
	bool UpdateCamera();

	/*相机直接输出信号给PLC*/
	void OutPutResult(); //(使用中）
	void OutPutResult(int step);

	void SetTriggerModel(bool Soft);
	void SetTriggerModel(bool Soft, int step);

	unsigned char* pImage;
public:
	HANDLE hCameraThread;//采图线程
	int64_t Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc);
	cv::Mat HImage2Mat(HalconCpp::HObject& H_img);
	/************************************************
	*   功能：为相机采图单独开辟线程，避免系统停止后，相机采图冲突的问题。
	* 具体实现思路如下：
	* 开辟新的线程，调用图像接口采集图像，停止采集时挂起线程，开始采集时唤醒线程。
	************************************************/

	/************************************************
	*   功能：图像采集线程
	*	参数：
	*	返回值：
	************************************************/



	/************************************************
	*   功能：读取XML文件
	*	参数：
	*	返回值：
	************************************************/
	std::vector<int> Read_XML();

};

