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
	CameraHK1(const CameraHK1& obj);//��������
	CameraHK1& operator=(const CameraHK1& obj);//����=
	~CameraHK1();
private:
	HObject sImage;
	//vector<HObject>ProductImages12;
	Mat SingleImage;//����ͼƬ
	vector<Mat>ProductImages;//һ��ͼƬ
	bool isOpen;
	int nRet;
	void* Handle;			//�豸���ӱ�־
	int CameraType;//��ͼ��ʽ �����ɼ��������ɼ�
	bool missCamera;//������߱�־
	bool GraphSuccess;
	DataManager* m_pData;//��������
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
	int GraphImage();

	/************************************************
	*   ���ܣ�ֹͣץͼ
	*	������
	*	����ֵ��
	************************************************/
	int StopGraphImage();

	/************************************************
	*   ���ܣ������
	*	������
	*	����ֵ��
	************************************************/
	bool OpenCamera();

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
	Mat GetImage();//����һ��ͼƬ
	vector<Mat> GetImages();//����һ��ͼƬ
	//HObject GetImage();//����һ��ͼƬ
	//vector<HObject> GetImages(int num);//����һ��ͼƬ

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
	bool UpdateCamera();

	void OutPutResult();

	void SetTriggerModel(bool Soft);

	//int SavelmageToFile(void* handle, unsigned char* p_BufAddr, unsigned short n_Width, unsigned short n_Height, MvGvspPixelType en_PixelType, unsigned int n_FrameLen);
	//int SaveImageToFile(void* handle, unsigned char* p_BufAddr, unsigned short n_Width, unsigned short n_Height, enum MvGvspPixelType en_PixelType, unsigned int n_FrameLen);
	unsigned char* pImage;
	cv::Mat HImageToMat(HalconCpp::HObject& H_img);
public:
	HANDLE hCameraThread;//��ͼ�߳�

	/************************************************
	*   ���ܣ�Ϊ�����ͼ���������̣߳�����ϵͳֹͣ�������ͼ��ͻ�����⡣
	* ����ʵ��˼·���£�
	* �����µ��̣߳�����ͼ��ӿڲɼ�ͼ��ֹͣ�ɼ�ʱ�����̣߳���ʼ�ɼ�ʱ�����̡߳�
	************************************************/

};

