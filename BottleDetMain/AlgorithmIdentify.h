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
//*   ���ܣ�AI�㷨�ӿ�
//*	���ڣ�2022-12-12
//*	�޸ģ���Ӵ�ͳ����㷨����ͳ�㷨��AI�㷨���У������ɺ��ۺϼ�������ء�
//*	�޸����ڣ�2022-12-27  QJJ
//************************************************/
//
//
//class AlgorithmIdentify
//{
//public:
//	AlgorithmIdentify();
//	AlgorithmIdentify(DataManager* pdata);
//	AlgorithmIdentify(const AlgorithmIdentify& obj);//��������
//	AlgorithmIdentify& operator=(const AlgorithmIdentify& obj);//����=
//	~AlgorithmIdentify();
//public:
//	Classification cls_model;
//	ObjectDetection obj_model;
//	int cur_model_type_flag;  // 0(���ࣩ��1��Ŀ���⣩
//	string cur_txt_order;   // ��ǰtxt���к�
//	int infer_time;
//	cv::Mat result_img;
//	vector<cv::Rect> result_rect_vec;
//	unordered_map<int, vector<cv::Rect>>AI_result_rect_table;
//
//	string Frofile_Path;
//	DataManager* m_pData;//��������
//	int result;//1 ok  -1 ng  
//	string bottle_type;//00011101
//	//string model;//��ѯ��ģ��
//	vector<int> TargetID;//��ѯ��ģ��
//
//	MyXml bottle_xml;
//	cv::Mat image_bgr;
//	/************************************************
//	*   ���ܣ����ؼ���� 1 ok, -1 ng
//	*	������
//	*	����ֵ��
//	************************************************/
//	int GetCheckResult();
//
//	/************************************************
//	*   ���ܣ�����Ŀ���������ο�
//	*	������
//	*	����ֵ��
//	************************************************/
//	vector<cv::Rect> GetDetRects();
//
//	/************************************************
//	*   ���ܣ����ؼ����ͼ����δʹ��
//	*	������
//	*	����ֵ��
//	************************************************/
//	cv::Mat GetObjDetResultImg();
//
//	/************************************************
//	*   ���ܣ����ؼ��ʱ�䣬��λms
//	*	������
//	*	����ֵ��
//	************************************************/
//	int GetDetCostTime();
//
//	/************************************************
//	*   ���ܣ����ؼ�����
//	*	������
//	*	����ֵ��
//	************************************************/
//	int LoadAlgorithmParam();
//
//	/************************************************
//	*   ���ܣ����ؼ��ģ��
//	*	������
//	*	����ֵ��
//	************************************************/
//	int LoadAlgorithmModel();
//
//	/************************************************
//	*   ���ܣ�ִ�м��
//	*	������ͼ������/��Ϊ���ż�������
//	*	����ֵ��
//	************************************************/
//	void DoJob(Mat& image);
//	void DoJob(vector<Mat>& images, int num);//����һ��
//
///************************************************
//*   ���ܣ����¼���㷨//ÿ�θ��²���֮���޸ļ��ģ��
//*	������
//*	����ֵ��
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
