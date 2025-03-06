#pragma once
#include <iostream>
#include <opencv.hpp>
#include <vector>
#include <string>
#include "publicspace.h"
#include "DataManager.h"
#include "CameraBasler.h"
#include "AlgorithmBase.h"
#include "HiKCamera.h"
#include "myLogger.h"
#include "AlgorithmIdentify.h"
#include "FatherSingle.h"
#include "CameraHK1.h"


using namespace std;
using namespace cv;
using namespace bodet;


/************************************************
*   ���ܣ����������
*	���ڣ�2022-11-30
************************************************/

class Detection
{
public:
	Detection(DataManager* pdata,CWnd* pwin);
	Detection(DataManager* pdata, BottleDetParam* m_param, CWnd* pwin);
	
	~Detection();

public:
	//������
	CWnd* m_pWin;
	//������߳�
	HANDLE hThreadDetection;
	//HANDLE hThreadDetection1;

	//ģ��ʶ��
	HANDLE hThreadIdentify;
	
	//�쳣����߳�
	HANDLE hThreadErrorCheck;


	//ͼ�񱣴��߳�
	
	//PLCͨ�Ž���
	//FatherSingle father;

public:
	Mat ProductImage;//��������ͼƬ
	vector<Mat>ProductImages;//����ͼ����
	vector<Mat> PImages;
	int m_DetResult;//�����
	bool RunState;//���״̬
	CameraBasler m_Camera;//�������
	CameraHK1 m_Camera1;//�������

	//HiKCamera m_Camera;
	AlgorithmBase m_Algorithm;//�㷨����
	//AlgorithmIdentify m_AlgorithmIdentify;
	DataManager* m_pData;//��������
	//BottleDetParam* m_param;
	int IdentifyResult;
	bool isTrigger;
	int SignalTotal=0;//�ź�����


public:
	//����¼�
	HANDLE CHECK_EVENT;		//ƿ��
	//HANDLE CHECK_EVENT1;	//ģ��

	//�����¼�
	HANDLE GRAPH_EVENT;
	//HANDLE GRAPH_EVENT1;		//ģ��

	//ģ�ż���¼�
	HANDLE IDENTIFY_EVENT;

public:
	/************************************************
	*   ���ܣ��������
	*	���������ģʽ��FIRSTSTART  RESTART  CONTINUE
	*	����ֵ��
	************************************************/
	void StartRun(string model);

	/************************************************
	*   ���ܣ�ֹͣ���
	*	������
	*	����ֵ��
	************************************************/
	void StopRun();

	/************************************************
	*   ���ܣ���һ��������ʼ������
	*	������
	*	����ֵ��
	************************************************/
	bool FirstStartCheck();

	/************************************************
	*   ���ܣ�����ʱˢ�²���
	*	������
	*	����ֵ��
	************************************************/
	bool RestartCheck();

	/************************************************
	*   ���ܣ���������ʱ���Ѽ��
	*	������
	*	����ֵ��
	************************************************/
	bool ContinueCheck();
public:
	//�̹߳���
	/************************************************
	*   ���ܣ���ʼ���߳�
	*	������
	*	����ֵ��
	************************************************/
	BOOL InitThread();

	/************************************************
	*   ���ܣ��ر��߳̾��
	*	������
	*	����ֵ��
	************************************************/
	void CloseThreadHandle();

	/************************************************
	*   ���ܣ���⺯��
	*	������
	*	����ֵ��
	************************************************/
	int CheckByAlgorithm();
	int CheckByAlgorithmMode();

	/************************************************
	*   ���ܣ�
	*	������
	*	����ֵ��
	************************************************/
	int IdentifyByAlgorithm();
	/************************************************
	*   ���ܣ�ˢ�¼����
	*	������
	*	����ֵ��
	************************************************/
	VOID UpdateProductImageShow(Mat Image, int result);
	VOID UpdateProductImageShow(vector<Mat> Images, int result);//����һ��
	VOID UpdateProductImageShow(Mat Image,vector<cv::Rect>points, int result,string deadline, string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult);//����һ��
	VOID UpdateProductImageShow(vector<Mat> Images, vector<cv::Rect>points, int result);//����һ��
	VOID UpdateProductImageShow(vector<Mat> Images, vector<cv::Rect>points, int result,int DeTime);//����һ��
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result,int DeTime);//����һ��
	//VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string detect_ID);//����һ��
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string detect_ID, int detect_Result);//����һ��
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string detect_ID, int detect_Result, string res_name);//����һ��
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string res_name);//����һ�Σ�ȥ��ģ��
	VOID UpdateProductImageShow(Mat Image, string detect_ID, int detect_Result);//����һ�Σ�����ģ��

	VOID UpdateProductResult(int result);
public:

	/************************************************
	*   ���ܣ����ⲿ�ṩ������㷨�Ķ���ָ�룬��Ҫ�ṩ�������������ʹ��
	*	������
	*	����ֵ���������ָ��
	************************************************/
	CameraBasler* GetCamera_ptr();
	CameraHK1* GetCamera1_ptr();

	AlgorithmBase* GetAlgorithm_ptr();
	//AlgorithmIdentify* GetIdentifyAlgorithm_ptr();
	int DetectTime;

	int str2intd(string str);
	CString SaveImaged(vector<Mat>& images);//����ͼ��

	/************************************************
	*   ���ܣ�GS���ؽ��
	*	������
	*	����ֵ��
	************************************************/
	string DetectionDeadline;			//ʹ������
	string DetectionUpCode;				//�ϲ����
	string DetectionDownCode;			//�²����
	string DetectionUpNumber;			//�ϲ����
	string DetectionDownNumber;			//�²����
	string DetectionUpResult;			//�ϲ�����ԱȽ��
	string DetectionDownResult;			//�²�����ԱȽ��


};

