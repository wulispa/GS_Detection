#pragma once
//#include "DlModel.h"
#include "publicspace.h"
#include <opencv.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include "DataManager.h"
#include "MyXml.h"
//#include "MyThreadPool.h"
//
//
//using namespace std;
//using namespace cv;
//using namespace bodet;
//
///************************************************
//*   功能：AI算法接口
//*	日期：2022-12-12
//*	修改：添加传统检测算法，传统算法和AI算法并行，检测完成后综合检测结果返回。
//*	修改日期：2022-12-27  QJJ
//************************************************/
//
//
//class AlgorithmIdentify
//{
//public:
//	AlgorithmIdentify();
//	AlgorithmIdentify(DataManager* pdata);
//	AlgorithmIdentify(const AlgorithmIdentify& obj);//拷贝构造
//	AlgorithmIdentify& operator=(const AlgorithmIdentify& obj);//重载=
//	~AlgorithmIdentify();
//public:
//	Classification cls_model;
//	ObjectDetection obj_model;
//	int cur_model_type_flag;  // 0(分类）、1（目标检测）
//	string cur_txt_order;   // 当前txt序列号
//	int infer_time;
//	cv::Mat result_img;
//	vector<cv::Rect> result_rect_vec;
//	unordered_map<int, vector<cv::Rect>>AI_result_rect_table;
//
//	string Frofile_Path;
//	DataManager* m_pData;//参数管理
//	int result;//1 ok  -1 ng  
//	string bottle_type;//00011101
//	//string model;//查询的模板
//	vector<int> TargetID;//查询的模板
//
//	MyXml bottle_xml;
//	cv::Mat image_bgr;
//	/************************************************
//	*   功能：返回检测结果 1 ok, -1 ng
//	*	参数：
//	*	返回值：
//	************************************************/
//	int GetCheckResult();
//
//	/************************************************
//	*   功能：返回目标检测结果矩形框
//	*	参数：
//	*	返回值：
//	************************************************/
//	vector<cv::Rect> GetDetRects();
//
//	/************************************************
//	*   功能：返回检测结果图像，暂未使用
//	*	参数：
//	*	返回值：
//	************************************************/
//	cv::Mat GetObjDetResultImg();
//
//	/************************************************
//	*   功能：返回检测时间，单位ms
//	*	参数：
//	*	返回值：
//	************************************************/
//	int GetDetCostTime();
//
//	/************************************************
//	*   功能：加载检测参数
//	*	参数：
//	*	返回值：
//	************************************************/
//	int LoadAlgorithmParam();
//
//	/************************************************
//	*   功能：加载检测模型
//	*	参数：
//	*	返回值：
//	************************************************/
//	int LoadAlgorithmModel();
//
//	/************************************************
//	*   功能：执行检测
//	*	参数：图像数据/分为单张检测和组检测
//	*	返回值：
//	************************************************/
//	void DoJob(Mat& image);
//	void DoJob(vector<Mat>& images, int num);//重载一次
//
///************************************************
//*   功能：更新检测算法//每次更新参数之后修改检测模型
//*	参数：
//*	返回值：
//************************************************/
//	bool UpdateAlgorithm();
//
//	string sub(string s1, string s2);
//	vector<int> Str2Vec(string str);
//	int str2int(string str);
//
//
//
//};
//
