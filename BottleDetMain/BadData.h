#pragma once
#include<mysql.h>
#include<string>
#include <vector>
#include <unordered_map>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>


using namespace std;


/************************************************
	*   功能：返回缺陷框、模号结果
	*	参数：
	*	返回值：unordered_map<int, vector<int>>
************************************************/
unordered_map<vector<cv::Rect>, string> GetBadData(CString name);


/************************************************
	*   功能：插入缺陷框、模号结果数据
	*	参数：文件名、缺陷框、模号结果
	*	返回值：无
************************************************/
void InsertData(CString name, vector<cv::Rect> points, string detect_ID);
