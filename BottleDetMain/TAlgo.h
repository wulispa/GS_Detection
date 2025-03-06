#pragma once
#pragma comment(lib, "TraditionAlgo.lib")
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include <opencv2/opencv.hpp>
#include "HalconCpp.h"

using namespace std;
using namespace cv;
using namespace HalconCpp;

struct TraditionPara
{
	//ƿ����Բ�뾶��Ĭ��350pix��
	int outer_radius;
	//ƿ����Բ�뾶��Ĭ��270pix��
	vector<int> inner_radius;
	//��̬��ֵ��ֵԽС��Խ������ԱȶȵͲ����Ե�ȱ�ݣ�Ĭ��10��
	vector<int> dyn_threshold_val;
	//ȱ�������ֵ�����С�ڸ�ֵ��ȱ�����򲻻ᱻ��⵽��Ĭ��150��
	vector<int> area_threshold_val;

	//const char*  maskpath;
	vector<HObject>  ho_mask;

};
//extern "C" _declspec(dllimport) void TraditionAlgorithm(HObject & image, TraditionPara & param, vector<cv::Rect> &Tradition_result_rect);
extern "C" _declspec(dllimport) vector<cv::Rect> TraditionAlgorithm(HObject& image, TraditionPara &param, vector<cv::Rect> &Tradition_result_rect);
