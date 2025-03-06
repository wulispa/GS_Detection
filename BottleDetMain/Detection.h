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
*   功能：检测主流程
*	日期：2022-11-30
************************************************/

class Detection
{
public:
	Detection(DataManager* pdata,CWnd* pwin);
	Detection(DataManager* pdata, BottleDetParam* m_param, CWnd* pwin);
	
	~Detection();

public:
	//主界面
	CWnd* m_pWin;
	//检测主线程
	HANDLE hThreadDetection;
	//HANDLE hThreadDetection1;

	//模号识别
	HANDLE hThreadIdentify;
	
	//异常检测线程
	HANDLE hThreadErrorCheck;


	//图像保存线程
	
	//PLC通信进程
	//FatherSingle father;

public:
	Mat ProductImage;//保存生产图片
	vector<Mat>ProductImages;//保存图像组
	vector<Mat> PImages;
	int m_DetResult;//检测结果
	bool RunState;//检测状态
	CameraBasler m_Camera;//相机对象
	CameraHK1 m_Camera1;//相机对象

	//HiKCamera m_Camera;
	AlgorithmBase m_Algorithm;//算法对象
	//AlgorithmIdentify m_AlgorithmIdentify;
	DataManager* m_pData;//参数管理
	//BottleDetParam* m_param;
	int IdentifyResult;
	bool isTrigger;
	int SignalTotal=0;//信号总数


public:
	//检测事件
	HANDLE CHECK_EVENT;		//瓶底
	//HANDLE CHECK_EVENT1;	//模号

	//拍照事件
	HANDLE GRAPH_EVENT;
	//HANDLE GRAPH_EVENT1;		//模号

	//模号检测事件
	HANDLE IDENTIFY_EVENT;

public:
	/************************************************
	*   功能：启动检测
	*	参数：检测模式，FIRSTSTART  RESTART  CONTINUE
	*	返回值：
	************************************************/
	void StartRun(string model);

	/************************************************
	*   功能：停止检测
	*	参数：
	*	返回值：
	************************************************/
	void StopRun();

	/************************************************
	*   功能：第一次启动初始化参数
	*	参数：
	*	返回值：
	************************************************/
	bool FirstStartCheck();

	/************************************************
	*   功能：重启时刷新参数
	*	参数：
	*	返回值：
	************************************************/
	bool RestartCheck();

	/************************************************
	*   功能：继续运行时唤醒检测
	*	参数：
	*	返回值：
	************************************************/
	bool ContinueCheck();
public:
	//线程管理
	/************************************************
	*   功能：初始化线程
	*	参数：
	*	返回值：
	************************************************/
	BOOL InitThread();

	/************************************************
	*   功能：关闭线程句柄
	*	参数：
	*	返回值：
	************************************************/
	void CloseThreadHandle();

	/************************************************
	*   功能：检测函数
	*	参数：
	*	返回值：
	************************************************/
	int CheckByAlgorithm();
	int CheckByAlgorithmMode();

	/************************************************
	*   功能：
	*	参数：
	*	返回值：
	************************************************/
	int IdentifyByAlgorithm();
	/************************************************
	*   功能：刷新检测结果
	*	参数：
	*	返回值：
	************************************************/
	VOID UpdateProductImageShow(Mat Image, int result);
	VOID UpdateProductImageShow(vector<Mat> Images, int result);//重载一次
	VOID UpdateProductImageShow(Mat Image,vector<cv::Rect>points, int result,string deadline, string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult);//重载一次
	VOID UpdateProductImageShow(vector<Mat> Images, vector<cv::Rect>points, int result);//重载一次
	VOID UpdateProductImageShow(vector<Mat> Images, vector<cv::Rect>points, int result,int DeTime);//重载一次
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result,int DeTime);//重载一次
	//VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string detect_ID);//重载一次
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string detect_ID, int detect_Result);//重载一次
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string detect_ID, int detect_Result, string res_name);//重载一次
	VOID UpdateProductImageShow(Mat Image, vector<cv::Rect>points, int result, int DeTime, string res_name);//重载一次，去掉模号
	VOID UpdateProductImageShow(Mat Image, string detect_ID, int detect_Result);//重载一次，单独模号

	VOID UpdateProductResult(int result);
public:

	/************************************************
	*   功能：对外部提供相机和算法的对象指针，主要提供给相机参数窗口使用
	*	参数：
	*	返回值：相机对象指针
	************************************************/
	CameraBasler* GetCamera_ptr();
	CameraHK1* GetCamera1_ptr();

	AlgorithmBase* GetAlgorithm_ptr();
	//AlgorithmIdentify* GetIdentifyAlgorithm_ptr();
	int DetectTime;

	int str2intd(string str);
	CString SaveImaged(vector<Mat>& images);//保存图像

	/************************************************
	*   功能：GS返回结果
	*	参数：
	*	返回值：
	************************************************/
	string DetectionDeadline;			//使用期限
	string DetectionUpCode;				//上层读码
	string DetectionDownCode;			//下层读码
	string DetectionUpNumber;			//上层读数
	string DetectionDownNumber;			//下层读数
	string DetectionUpResult;			//上层条码对比结果
	string DetectionDownResult;			//下层条码对比结果


};

