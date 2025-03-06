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
	//瓶底外圆半径（默认350pix）
	int outer_radius;
	//瓶底内圆半径（默认270pix）
	vector<int> inner_radius;
	//动态阈值，值越小，越会检测出对比度低不明显的缺陷（默认10）
	vector<int> dyn_threshold_val;
	//缺陷面积阈值，面积小于该值的缺陷区域不会被检测到（默认150）
	vector<int> area_threshold_val;

	//const char*  maskpath;
	vector<HObject>  ho_mask;

};
//extern "C" _declspec(dllimport) void TraditionAlgorithm(HObject & image, TraditionPara & param, vector<cv::Rect> &Tradition_result_rect);
extern "C" _declspec(dllimport) vector<cv::Rect> TraditionAlgorithm(HObject& image, TraditionPara &param, vector<cv::Rect> &Tradition_result_rect);
