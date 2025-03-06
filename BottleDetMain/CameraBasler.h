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
*   ���ܣ�����ӿ�
*	���ڣ�2023
************************************************/

class CameraBasler
{
public:
	CameraBasler();
	CameraBasler(DataManager* pdata);
	CameraBasler(const CameraBasler& obj);//��������
	CameraBasler& operator=(const CameraBasler& obj);//����=
	~CameraBasler();
private:
	HObject sImage;
	vector<HObject>ProductImages12;
	Mat SingleImage;//����ͼƬ
	vector<Mat>ProductImages;//һ��ͼƬ
	bool isOpen;
	int nRet;
	void* Handle;			//�豸���ӱ�־
	int CameraType;//��ͼ��ʽ �����ɼ��������ɼ�
	bool missCamera;//������߱�־
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

	//CGrabResultPtr ptrGrabResult;	//������
	//INodeMap& nodemap;//����
	//MV_CC_DEVICE_INFO_LIST stDeviceList;
	//unsigned int SelectCamIndex;
	//std::string CamId;
public:
	DataManager* m_pData;//��������

	/************************************************
	*   ���ܣ���ȡ�������״̬
	*	������
	*	����ֵ��
	************************************************/
	bool IsOpen();

	/************************************************
	*   ���ܣ�
	*	������
	*	����ֵ��
	************************************************/
	void SetCameraParam();

	/************************************************
	*   ���ܣ�ץͼ
	*	������
	*	����ֵ��1 �ɹ�  -1ʧ��
	************************************************/
	int GraphImage(int choose);

	/************************************************
	*   ���ܣ�ֹͣץͼ
	*	������
	*	����ֵ��
	************************************************/
	void StopGraphImage();

	/************************************************
	*   ���ܣ������
	*	������
	*	����ֵ��
	************************************************/
	bool OpenCamera();
	bool OpenCamera(string CamID, int step);

	/************************************************
	*   ���ܣ��������
	*	������
	*	����ֵ��
	************************************************/
	bool RestartCamera();

	/************************************************
	*   ���ܣ��ر����
	*	������
	*	����ֵ��
	************************************************/
	bool CloseCamera();

	/************************************************
	*   ���ܣ�����ͼ��
	*	������
	*	����ֵ��
	************************************************/
	Mat GetImage(int Choose_Cam);//����һ��ͼƬ
	HObject Get_Image(int n);//����һ��ͼƬ

	/************************************************
	*   ���ܣ��������
	*	������
	*	����ֵ��
	************************************************/
	bool isMissCamera();

	/************************************************
	*   ���ܣ������ͼ�ɹ�
	*	������
	*	����ֵ��
	************************************************/
	bool isSuccessGraph();

	/************************************************
	*   ���ܣ�ˢ���������
	*	������
	*	����ֵ��
	************************************************/
	//bool UpdateCamera();
	bool UpdateCamera();

	/*���ֱ������źŸ�PLC*/
	void OutPutResult(); //(ʹ���У�
	void OutPutResult(int step);

	void SetTriggerModel(bool Soft);
	void SetTriggerModel(bool Soft, int step);

	unsigned char* pImage;
public:
	HANDLE hCameraThread;//��ͼ�߳�
	int64_t Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc);
	cv::Mat HImage2Mat(HalconCpp::HObject& H_img);
	/************************************************
	*   ���ܣ�Ϊ�����ͼ���������̣߳�����ϵͳֹͣ�������ͼ��ͻ�����⡣
	* ����ʵ��˼·���£�
	* �����µ��̣߳�����ͼ��ӿڲɼ�ͼ��ֹͣ�ɼ�ʱ�����̣߳���ʼ�ɼ�ʱ�����̡߳�
	************************************************/

	/************************************************
	*   ���ܣ�ͼ��ɼ��߳�
	*	������
	*	����ֵ��
	************************************************/



	/************************************************
	*   ���ܣ���ȡXML�ļ�
	*	������
	*	����ֵ��
	************************************************/
	std::vector<int> Read_XML();

};

