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
 * @name		: opencv������ʾ��
 * @time		��2022-11-28
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
	 * @name		: ����ͼ�񴰿�
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	void OpenWindow(CWnd* win);

	/*********************************************
	 * @name		: ��ʾͼƬ
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	void DispImage(Mat image);

	/*********************************************
	 * @name		: ��մ���
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	void ClearWindow();

	/*********************************************
	 * @name		: ��ͼƬ�ϻ�������
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	Mat PaintTxt(Mat& Image, string txt);

	/*********************************************
	 * @name		: ��ͼƬ�ϻ����ַ�  ����һ��
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	Mat PaintTxt(Mat& Image, string txt, Point pos , Scalar clor);

	/*********************************************
	 * @name		: ��ͼƬ�ϻ��ƾ���
	 * @in param input_para	: none
	 * @out param output_para : none
	 * @return : none
	 ********************************************/
	Mat PaintRectangle(Mat& Image, Rect& rect, cv::Scalar clor);

	Mat putTextZH(Mat& Image, const char* str, Point org, Scalar color, int fontsize,
		const char* fn = "΢���ź�", bool italic = false, bool underline = false);

};
