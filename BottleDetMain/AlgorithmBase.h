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

//***********v8���ͷ�ļ�***************
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
*   ���ܣ�AI�㷨�ӿ�
*	���ڣ�2022-12-12
*	�޸ģ���Ӵ�ͳ����㷨����ͳ�㷨��AI�㷨���У������ɺ��ۺϼ�������ء�
*	�޸����ڣ�2022-12-27  QJJ
************************************************/


class AlgorithmBase
{
public:
	AlgorithmBase();
	AlgorithmBase(DataManager* pdata);
	AlgorithmBase(const AlgorithmBase& obj);//��������
	AlgorithmBase& operator=(const AlgorithmBase& obj);//����=
	~AlgorithmBase();
public:
	//YOLOV8* yolo[MUTIL_NUM];
	//YOLOV8* yolo;
	// ����ģ�Ͳ���
	//dl_utils::InitParameter param;
	//bool build_trt_model(const char* onnx_path, const char* trt_save_path);		//����trt�ļ�
	//nvinfer1::ICudaEngine* engine;
	//void setParameters(dl_utils::InitParameter& initParameters);		//v8��ʼ������
	//unordered_map<int, vector<Rect>> task(YOLOV8& yolo, const dl_utils::InitParameter& param, std::vector<cv::Mat>& imgsBatch, const int& delayTime, const int& batchi,
	//	const bool& isShow, const bool& isSave, float ThreshValue);		//v8����
	//unordered_map<int, vector<Rect>> task(YOLOV8* yolo, const dl_utils::InitParameter& param, std::vector<cv::Mat>& imgsBatch, const int& delayTime, const int& batchi,
	//	const bool& isShow, const bool& isSave, float ThreshValue);		//v8����

	//Classification cls_model;
	//ObjectDetection obj_model;
	//ObjectDetection obj_models[MUTIL_NUM];//���Ӽ��ģ�Ͷ�������
	int cur_model_type_flag;  // 0(���ࣩ��1��Ŀ���⣩
	string cur_txt_order;   // ��ǰtxt���к�
	int infer_time;
	cv::Mat result_img;
	//cv::Mat Product_Image;
	vector<cv::Rect> result_rect_vec;
	unordered_map<int ,vector<cv::Rect>>AI_result_rect_table;
	vector<cv::Rect> Tradition_result_rect;

	string DetectionType;

	string WriteProductBatch;	//д����������
	string ReadProductBatch;	//������������
	string Deadline;			//ʹ������
	string UpCode;				//�ϲ����
	string DownCode;			//�²����
	string UpNumber;			//�ϲ����
	string DownNumber;			//�²����
	string UpResult;			//�ϲ�����ԱȽ��
	string DownResult;			//�²�����ԱȽ��
	string PersonUse;			//�²�����ԱȽ��
	string isOkSignal;          //�Ƿ�Ϊ��Ʒ
	//���ݿ����
	SQLInterface SQL;
	//*********************ƿ�׽��************************
	unordered_map<int, vector<cv::Rect>>AI_result_rect_vec;	//�����
	unordered_map<int, int> results;		//1 ok  -1 ng 
	unordered_map<int, string> res_names;

	//int DetectResult;//�����
	/**************************���Խ����*************************/
	int test_infer_time;
	int test_result;
	int test_ID_result;
	string test_bottle_type;
	string test_res_name;
	vector<cv::Rect> test_result_rect_vec;

	/**************************���Խ����*************************/

	string Frofile_Path;
	DataManager* m_pData;//��������
	int result;//1 ok  -1 ng  
	int IDresult;//1 ok  -1 ng  
	string bottle_type;//00011101
	//vector<int> TargetID;//��ѯ��ģ��
	string res_name;

	MyXml bottle_xml;

	bool MutilFlag;

	//�����ֵ
	double ThreadArea, ThreadLBW;
	vector<int> ThreadArea1;
	string ThreadModel;
	int GrayValue;
	string GrayModel;

	//�������
	string ChoseModel;
	string test_ChoseModel;

	/*----------------------------��ͳ����㷨����---------------------------*/
	//ƿ����Բ�뾶��Ĭ��350pix��
	int outer_radius;
	//ƿ����Բ�뾶��Ĭ��270pix��
	int inner_radius;
	//��̬��ֵ��ֵԽС��Խ������ԱȶȵͲ����Ե�ȱ�ݣ�Ĭ��10��
	vector<int> dyn_threshold_val;
	//ȱ�������ֵ�����С�ڸ�ֵ��ȱ�����򲻻ᱻ��⵽��Ĭ��150��
	vector<int> area_threshold_val;
	//TraditionPara* mpara;

	TraditionPara mpara0;
		//= (TraditionPara*)malloc(sizeof(TraditionPara));

	/************************************************
	*   ���ܣ����ؼ���� 1 ok, -1 ng
	*	������
	*	����ֵ��
	************************************************/
	int GetCheckResult();
	int GetCheckResult(bool test);

	int GetIDResult();
	
	/************************************************
	*   ���ܣ�����Ŀ���������ο�
	*	������
	*	����ֵ��
	************************************************/
	vector<cv::Rect> GetDetRects();

	/************************************************
	*   ���ܣ����ؼ����ͼ����δʹ��
	*	������
	*	����ֵ��
	************************************************/
	cv::Mat GetObjDetResultImg();

	/************************************************
	*   ���ܣ����ؼ��ʱ�䣬��λms
	*	������
	*	����ֵ��
	************************************************/
	int GetDetCostTime();

	/************************************************
	*   ���ܣ����ؼ�����
	*	������
	*	����ֵ��
	************************************************/
	int LoadAlgorithmParam();
	int LoadAlgorithmParam(bool test);
	int LoadIdentifyAlgorithmParam();

	/************************************************
	*   ���ܣ����ؼ��ģ��
	*	������
	*	����ֵ��
	************************************************/
	int LoadAlgorithmModel();
	int LoadAlgorithmModel(bool test);

	int LoadIdentifyAlgorithmModel();

	/************************************************
	*   ���ܣ�ִ�м��
	*	������ͼ������/��Ϊ���ż�������
	*	����ֵ��
	************************************************/
	void DoJob(Mat& image);
	int DoJob(vector<Mat>& images, int num);//����һ��
	int DoJob(vector<Mat>& images, int num, bool test);//����һ��

/************************************************
*   ���ܣ����¼���㷨//ÿ�θ��²���֮���޸ļ��ģ��
*	������
*	����ֵ��
************************************************/
	//void UpdateAImodel();
	//void UpdateAImodel(bool test);

	vector<int> Str2Vec(string str);
	bool UpdateAlgorithm();
	bool UpdateAlgorithm(vector<int> contra_val_vec, vector<int> area_val_vec, vector<int> gray_val_vec);
	bool UpdateAlgorithm(vector<int> contra_val_vec, vector<int> area_val_vec, vector<int> gray_val_vec, CString choosemodel);

	/************************************************
	*   ���ܣ���Ӽ�������˷�����������ֵ���Լ��������
	*	������
	*	����ֵ��
	************************************************/
	void FilterResult(vector<cv::Rect> mrect);

	void FilterResult(Mat img,unordered_map<int, vector<cv::Rect>> mrect);//����һ�Σ���ӻҶ�ɸѡ
	string FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect,string Show);//����һ�Σ���ӷ���ȱ������
	string FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, string Show, bool test);
	void AIFilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect, int step);
	//����һ�Σ���ӷ���ȱ������

	void FilterResult(Mat img, unordered_map<int, vector<cv::Rect>> mrect,bool Test);//����һ�Σ��������б�־

	string FilterID(unordered_map<int, vector<cv::Rect>> mrect);
	string FilterID(vector<cv::Rect> mrect);
	string FilterID(vector<cv::Rect> mrect, bool test);

	/************************************************
	*   ���ܣ��Ҷ���ֵɸѡ
	*	������
	*	����ֵ��
	************************************************/
	bool GrayFilter(Mat& mimg, cv::Rect mrect, bool areaFlag);

public:
	/*-----------------------------------��������̲߳���ִ��---------------------------------------*/
	HANDLE AIThread, TraditionThread, IdentifyThread;
	//����¼�
	HANDLE CHECK_AI_EVENT, COMPLETE_AI_EVENT, CHECK_TRADITION_EVENT, COMPLETE_TRADITION_EVENT, CHECK_IDENTIFY_EVENT, COMPLETE_IDENTIFY_EVENT;
	//ͼƬ�洢�ռ�
	Mat Image;
	vector<Mat> Images;
	vector<Mat> CImages;//�ü���ͼƬ
	HObject ho_SingleMaskImage;
	vector<HObject>	ho_MaskImage;	//maskͼ��
	vector<vector<HObject>> ho_MaskImages;
	HObject	ho_Mask1;
	//�˳��ź�
	bool m_Exit;

	/************************************************
	*   ���ܣ������߳�
	*	������
	*	����ֵ��bool
	************************************************/
	bool InitThread();

	/************************************************
	*   ���ܣ��ͷ��߳�
	*	������
	*	����ֵ��
	************************************************/
	void RelaseThread();

	/************************************************
	*   ���ܣ�AI����㷨
	*	������
	*	����ֵ��
	************************************************/
	void CheckByAIAlgorithm(Mat& image);
	void CheckByAIAlgorithm(Mat& image, int index);//����һ��
	void CheckByAIAlgorithm(vector<Mat>& images);

	/************************************************
	*   ���ܣ���ͳ����㷨
	*	������
	*	����ֵ��
	************************************************/
	void CheckByTraditionAlgorithm(Mat& image);
	void CheckByTraditionAlgorithm(Mat image, int index);//����һ��

	void CheckByIdentifyAlgorithm(Mat& image, int index);
	void CheckByIdentifyAlgorithm(vector<Mat>& images);

	/************************************************
	*   ���ܣ���ͳ����㷨
	*	������
	*	����ֵ��
	************************************************/
	void CheckByModeAlgorithm(Mat& image);

	/************************************************
	*   ���ܣ�MatתHObject
	*	������
	*	����ֵ��
	************************************************/
	HObject Mat2HObject(cv::Mat& cv_img);

	/************************************************
	*   ���ܣ�HTupleתString
	*	������
	*	����ֵ��
	************************************************/
	string HTupleToString(const HTuple& hTuple);

	vector<int> Str2Vec1(string str);

	int str2int1(string str);

public:
	/*---------------------------����ģ�ż�⹦��-----------------------------*/
	//ObjectDetection Identify_models[MUTIL_NUM];//ģ�ż��ģ��
	//ObjectDetection Identify_model;


public:
	/*------------------------------�����̳߳ز��д���------------------------------*/
	MyThreadPool m_AIthreadPool;//���ѧϰ�㷨����̳߳�
	MyThreadPool  m_TraditionThreadPool;//��ͳ�㷨����̳߳�
	MyThreadPool m_AIthreadPool_test;
	MyThreadPool  m_TraditionThreadPool_test;

	//����¼�
	HANDLE AI_COMPLETE_EVENT[MUTIL_NUM];
	HANDLE Tradition_COMPLETE_EVENT[MUTIL_NUM];
	HANDLE IDENTIFY_COMPLETE_EVENT[MUTIL_NUM];
	HANDLE AI_COMPLETE_EVENT_TEST[MUTIL_NUM];
	HANDLE Tradition_COMPLETE_EVENT_TEST[MUTIL_NUM];

	//���Ӳ��������
	unordered_map<int, unordered_map<int, vector<cv::Rect>>> AI_check;
	unordered_map<int, vector<cv::Rect>> Tradition_check;
	unordered_map<int, unordered_map<int, vector<cv::Rect>>> ID_check;

	/***********************************��ģ�Ͷ���****************************/
	vector<unordered_map<int, vector<cv::Rect>>> AI_RESULT;
	vector<unordered_map<int, vector<cv::Rect>>> AID_RESULT;
	bool check;//�������������б�־
};

