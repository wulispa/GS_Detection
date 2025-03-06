#pragma once
#include <opencv.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

#define M_COLOR_R Scalar(0, 0, 255)
#define M_COLOR_G Scalar(255, 0, 0)
#define MUTIL_NUM 9

namespace bodet {
	struct BottleDetParam
	{
		//�������
		//***************ƿ�����
		int ExpostTime;
		double GainValue;
		string AutoSaveImage;
		int GrabNum;
		string Trigger;
		string CamOut;
		//***************ģ�����
		int ExpostTime1;
		double GainValue1;
		string AutoSaveImage1;
		string Trigger1;
		string CamOut1;

		//������
		string Model_Path;
		string Profile_Path;
		double ThreadValue;
		double ThreadValueLW;//�������ֵ
		string ThreadModel;//��ֵģʽ  AREA  LW  BOTH
		int GrayValue;		//�Ҷ���ֵ
		string GrayModel;  //�Ҷ���ֵ TRUE FALSE
		string ChoseModel; //AI                     //&AI  AI&TRA  NONE&AI NONE&TRA
		float ConfidenceVal1;
		float ConfidenceVal2;
		float NMSThreshVal;
		string Show_Region;
		string MoldRecognition;
		string SelectedMold;
		string MoldModel_Path;
		string MoldProfile_Path;
		//GS
		string ProductData;
		string TriggerDistance;
		string PhotoelectricDistance;
		string PersonUse;

		//��ͳ�㷨����
		int outer_radius;
		int inner_radius;
		int dyn_threshold_val;
		int area_threshold_val;
		string contra_val;
		string area_val;
		string gray_val;
	};
	struct SystemParam
	{
		//ϵͳ����
		string ThrowModel;//NORMAL  SUSTAIN  NO
		string ShowModel;//SUSTAIN  ONLYBAD
		string SaveModel;//NO AUTO AUTOBAD
		string ImageType;//JPG 
		string AutoLock;//true false
		int AutoLockTime;//
		string BanSelect;
		string BanNumber;
	};


}