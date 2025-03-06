#pragma once
//#include "DlModel.h"
#include "publicspace.h"
#include <opencv.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include "DataManager.h"
#include "HalconCpp.h"
#include "MyThreadPool.h"
#include "TAlgo.h"
#include"SQLInterface.h"

//***********v8添加头文件***************
//#include "utils/utils.h"
//#include "yolox/yolox.h"
//#include "yolov8/yolov8.h"
//#include "utils/common_include.h"
//#include <locale>
//#include <codecvt>


using namespace std;
//using namespace cv;
using namespace bodet;
using namespace HalconCpp;


/************************************************
*   功能：AI算法接口
*	日期：2022-12-12
*	修改：添加传统检测算法，传统算法和AI算法并行，检测完成后综合检测结果返回。
*	修改日期：2022-12-27  QJJ
************************************************/


class AlgorithmBase
{
public:
	AlgorithmBase();
	AlgorithmBase(DataManager* pdata);
	AlgorithmBase(const AlgorithmBase& obj);//拷贝构造
	AlgorithmBase& operator=(const AlgorithmBase& obj);//重载=
	~AlgorithmBase();
public:
	//YOLOV8* yolo[MUTIL_NUM];
	//YOLOV8* yolo;
	// 配置模型参数
	//dl_utils::InitParameter param;
	//bool build_trt_model(const char* onnx_path, const char* trt_save_path);		//创建trt文件
	//nvinfer1::ICudaEngine* engine;
	//void setParameters(dl_utils::InitParameter& initParameters);		//v8初始化参数
	//unordered_map<int, vector<Rect>> task(YOLOV8& yolo, const dl_utils::InitParameter& param, std::vector<cv::Mat>& imgsBatch, const int& delayTime, const int& batchi,
	//	const bool& isShow, const bool& isSave, float ThreshValue);		//v8推理
	//unordered_map<int, vector<Rect>> task(YOLOV8* yolo, const dl_utils::InitParameter& param, std::vector<cv::Mat>& imgsBatch, const int& delayTime, const int& batchi,
	//	const bool& isShow, const bool& isSave, float ThreshValue);		//v8推理

	//Classification cls_model;
	//ObjectDetection obj_model;
	//ObjectDetection obj_models[MUTIL_NUM];//增加检测模型对象数组
	int cur_model_type_flag;  // 0(分类）、1（目标检测）
	string cur_txt_order;   // 当前txt序列号
	int infer_time;
	cv::Mat result_img;
	//cv::Mat Product_Image;
	vector<cv::Rect> result_rect_vec;
	unordered_map<int ,vector<cv::Rect>>AI_result_rect_table;
	vector<cv::Rect> Tradition_result_rect;

	string DetectionType;

	string WriteProductBatch;	//写入生产批次
	string ReadProductBatch;	//读出生产批次
	string Deadline;			//使用期限
	string UpCode;				//上层读码
	string DownCode;			//下层读码
	string UpNumber;			//上层读数
	string DownNumber;			//下层读数
	string UpResult;			//上层条码对比结果
	string DownResult;			//下层条码对比结果
	string PersonUse;			//下层条码对比结果
	string isOkSignal;          //是否为良品
	//数据库对象
	SQLInterface SQL;
	//*********************瓶底结果************************
	unordered_map<int, vector<cv::Rect>>AI_result_rect_vec;	//检测结果
	unordered_map<int, int> results;		//1 ok  -1 ng 
	unordered_map<int, string> res_names;

	//int DetectResult;//检测结果
	/**************************测试结果用*************************/
	int test_infer_time;
	int test_result;
	int test_ID_result;
	string test_bottle_type;
	string test_res_name;
	vector<cv::Rect> test_result_rect_vec;

	/**************************测试结果用*************************/

	string Frofile_Path;
	DataManager* m_pData;//参数管理
	int result;//1 ok  -1 ng  
	int IDresult;//1 ok  -1 ng  
	string bottle_type;//00011101
	//vector<int> TargetID;//查询的模板
	string res_name;

	MyXml bottle_xml;

	bool MutilFlag;

	//检测阈值
	double ThreadArea, ThreadLBW;
	vector<int> ThreadArea1;
	string ThreadModel;
	int GrayValue;
	string GrayModel;

	//检测区域
	string ChoseModel;
	string test_ChoseModel;

	/*----------------------------传统检测算法参数---------------------------*/
	//瓶底外圆半径（默认350pix）
	int outer_radius;
	//瓶底内圆半径（默认270pix）
	int inner_radius;
	//动态阈值，值越小，越会检测出对比度低不明显的缺陷（默认10）
	vector<int> dyn_threshold_val;
	//缺陷面积阈值，面积小于该值的缺陷区域不会被检测到（默认150）
	vector<int> area_threshold_val;
	//TraditionPara* mpara;

	TraditionPara mpara0;
		//= (TraditionPara*)malloc(sizeof(TraditionPara));

	/************************************************
	*   功能：返回检测结果 1 ok, -1 ng
	*	参数：
	*	返回值：
	************************************************/
	int GetCheckResult();
	int GetCheckResult(bool test);

	int GetIDResult();
	
	/************************************************
	*   功能：返回目标检测结果矩形框
	*	参数：
	*	返回值：
	************************************************/
	vector<cv::Rect> GetDetRects();

	/************************************************
	*   功能：返回检测结果图像，暂未使用
	*	参数：
	*	返回值：
	************************************************/
	cv::Mat GetObjDetResultImg();

	/************************************************
	*   功能：返回检测时间，单位ms
	*	参数：
	*	返回值：
	************************************************/
	int GetDetCostTime();

	/************************************************
	*   功能：加载检测参数
	*	参数：
	*	返回值：
	************************************************/
	int LoadAlgorithmParam();
	int LoadAlgorithmParam(bool test);
	int LoadIdentifyAlgorithmParam();

	/************************************************
	*   功能：加载检测模型
	*	参数：
	*	返回值：
	************************************************/
	int LoadAlgorithmModel();
	int LoadAlgorithmModel(bool test);

	int LoadIdentifyAlgorithmModel();

	/************************************************
	*   功能：执行检测
	*	参数：图像数据/分为单张检测和组检测
	*	返回值：
	************************************************/
	void DoJob(Mat& image);
	int DoJob(vector<Mat>& images, int num);//重载一次
	int DoJob(vector<Mat>& images, int num, bool test);//重载一次

/************************************************
*   功能：更新检测算法//每次更新参数之后修改检测模型
*	参数：
*	返回值：
************************************************/
	//void UpdateAImodel();
	//void UpdateAImodel(bool test);

	vector<int> Str2Vec(string str);
	bool UpdateAlgorithm();
	bool UpdateAlgorithm(vector<int> contra_val_vec, vector<int> area_val_vec, vector<int> gray_val_vec);
	bool UpdateAlgorithm(vector<int> contra_val_vec, vector<int> area_val_vec, vector<int> gray_val_vec, CString choosemodel);

	/************************************************
	*   功能：添加检测结果过滤方法，根据阈值，对检测结果后处理。
	*	参数：
	*	返回值：
	************************************************/
	void FilterResult(vector<cv::Rect> mrect);

	void FilterResult(Mat img,unordered_map<int, vector<cv::Rect>> mrect);//重载一次，添加灰度筛选
	string FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect,string Show);//重载一次，添加返回缺陷类型
	string FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, string Show, bool test);
	void AIFilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, int step);
	//重载一次，添加返回缺陷类型

	void FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect,bool Test);//重载一次，测试运行标志

	string FilterID(unordered_map<int, vector<cv::Rect>> mrect);
	string FilterID(vector<cv::Rect> mrect);
	string FilterID(vector<cv::Rect> mrect, bool test);

	/************************************************
	*   功能：灰度阈值筛选
	*	参数：
	*	返回值：
	************************************************/
	bool GrayFilter(Mat& mimg, cv::Rect mrect, bool areaFlag);

public:
	/*-----------------------------------添加两个线程并行执行---------------------------------------*/
	HANDLE AIThread, TraditionThread, IdentifyThread;
	//检测事件
	HANDLE CHECK_AI_EVENT, COMPLETE_AI_EVENT, CHECK_TRADITION_EVENT, COMPLETE_TRADITION_EVENT, CHECK_IDENTIFY_EVENT, COMPLETE_IDENTIFY_EVENT;
	//图片存储空间
	Mat Image;
	vector<Mat> Images;
	vector<Mat> CImages;//裁剪后图片
	HObject ho_SingleMaskImage;
	vector<HObject>	ho_MaskImage;	//mask图像
	vector<vector<HObject>> ho_MaskImages;
	HObject	ho_Mask1;
	//退出信号
	bool m_Exit;

	/************************************************
	*   功能：创建线程
	*	参数：
	*	返回值：bool
	************************************************/
	bool InitThread();

	/************************************************
	*   功能：释放线程
	*	参数：
	*	返回值：
	************************************************/
	void RelaseThread();

	/************************************************
	*   功能：AI检测算法
	*	参数：
	*	返回值：
	************************************************/
	void CheckByAIAlgorithm(Mat& image);
	void CheckByAIAlgorithm(Mat& image, int index);//重载一次
	void CheckByAIAlgorithm(vector<Mat>& images);

	/************************************************
	*   功能：传统检测算法
	*	参数：
	*	返回值：
	************************************************/
	void CheckByTraditionAlgorithm(Mat& image);
	void CheckByTraditionAlgorithm(Mat image, int index);//重载一次

	void CheckByIdentifyAlgorithm(Mat& image, int index);
	void CheckByIdentifyAlgorithm(vector<Mat>& images);

	/************************************************
	*   功能：传统检测算法
	*	参数：
	*	返回值：
	************************************************/
	void CheckByModeAlgorithm(Mat& image);

	/************************************************
	*   功能：Mat转HObject
	*	参数：
	*	返回值：
	************************************************/
	HObject Mat2HObject(cv::Mat& cv_img);

	/************************************************
	*   功能：HTuple转String
	*	参数：
	*	返回值：
	************************************************/
	string HTupleToString(const HTuple& hTuple);

	vector<int> Str2Vec1(string str);

	int str2int1(string str);

public:
	/*---------------------------增加模号检测功能-----------------------------*/
	//ObjectDetection Identify_models[MUTIL_NUM];//模号检测模型
	//ObjectDetection Identify_model;


public:
	/*------------------------------增加线程池并行处理------------------------------*/
	MyThreadPool m_AIthreadPool;//深度学习算法检测线程池
	MyThreadPool  m_TraditionThreadPool;//传统算法检测线程池
	MyThreadPool m_AIthreadPool_test;
	MyThreadPool  m_TraditionThreadPool_test;

	//检测事件
	HANDLE AI_COMPLETE_EVENT[MUTIL_NUM];
	HANDLE Tradition_COMPLETE_EVENT[MUTIL_NUM];
	HANDLE IDENTIFY_COMPLETE_EVENT[MUTIL_NUM];
	HANDLE AI_COMPLETE_EVENT_TEST[MUTIL_NUM];
	HANDLE Tradition_COMPLETE_EVENT_TEST[MUTIL_NUM];

	//增加并发检测结果
	unordered_map<int, unordered_map<int, vector<cv::Rect>>> AI_check;
	unordered_map<int, vector<cv::Rect>> Tradition_check;
	unordered_map<int, unordered_map<int, vector<cv::Rect>>> ID_check;

	/***********************************单模型多张****************************/
	vector<unordered_map<int, vector<cv::Rect>>> AI_RESULT;
	vector<unordered_map<int, vector<cv::Rect>>> AID_RESULT;
	bool check;//检测参数测试运行标志
};

