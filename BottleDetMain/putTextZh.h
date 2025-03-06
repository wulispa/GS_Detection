#pragma once
#ifndef PUTTEXTZH_H_
#define PUTTEXTZH_H_

#include <windows.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

void GetStringSize(HDC hDC, const char* str, int* w, int* h);
void putTextZh(Mat& dst, const char* str, Point org, Scalar color, int fontSize,
	const char* fn = "Arial", bool italic = false, bool underline = false);

#endif // PUTTEXTZH_H_