#pragma once
#include<mysql.h>
#include<string>
#include <vector>
#include <unordered_map>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>


using namespace std;


/************************************************
	*   ���ܣ�����ȱ�ݿ�ģ�Ž��
	*	������
	*	����ֵ��unordered_map<int, vector<int>>
************************************************/
unordered_map<vector<cv::Rect>, string> GetBadData(CString name);


/************************************************
	*   ���ܣ�����ȱ�ݿ�ģ�Ž������
	*	�������ļ�����ȱ�ݿ�ģ�Ž��
	*	����ֵ����
************************************************/
void InsertData(CString name, vector<cv::Rect> points, string detect_ID);
