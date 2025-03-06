#pragma once
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv.hpp>
#include <iostream>
#include "CvvImage.h"
#include "publicspace.h"
#include "putText.h"

using namespace cv;
using namespace std;



/*********************************************
 * @name		: opencv窗口显示类
 * @time		：2022-11-28
 ********************************************/
class OpencvWin
{
public:
	OpencvWin();
	~OpencvWin();
private:

	CWnd* m_Win;
	HWND h_Mwin;
	Mat m_Image;
	CRect rect;
	putText00 put11;
public:
	/*********************************************
	 * @name		: 创建图像窗口
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	void OpenWindow(CWnd* win);

	/*********************************************
	 * @name		: 显示图片
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	void DispImage(Mat image);

	/*********************************************
	 * @name		: 清空窗口
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	void ClearWindow();

	/*********************************************
	 * @name		: 在图片上绘制文字
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	Mat PaintTxt(Mat& Image, string txt);

	/*********************************************
	 * @name		: 在图片上绘制字符  重载一次
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	Mat PaintTxt(Mat& Image, string txt, Point pos , Scalar clor);

	/*********************************************
	 * @name		: 在图片上绘制矩形
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	Mat PaintRectangle(Mat& Image, Rect& rect, cv::Scalar clor);

	Mat putTextZH(Mat& Image, const char* str, Point org, Scalar color, int fontsize,
		const char* fn = "微软雅黑", bool italic = false, bool underline = false);

};
