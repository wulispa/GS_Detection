#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "OpencvWin.h"
#include "DataManager.h"
#include "publicspace.h"
#include "CameraBasler.h"
#include "CameraHK1.h"
#include "opencv.hpp"

using namespace bodet;
using namespace std;

// CameraParamDlg 对话框

class CameraParamDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CameraParamDlg)

public:
	CameraParamDlg(CWnd* pParent , DataManager* pdata, CameraBasler* cam);   // 标准构造函数
	CameraParamDlg(CWnd* pParent, DataManager* pdata, CameraHK1* cam);   // 标准构造函数

	virtual ~CameraParamDlg();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAMERA_PARAM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();

public:
	/*---------------------------------界面参数----------------------------------*/
	/*int ExposeTime;
	double GainValue;*/
	//string AutoSave;
	bool isChange;//参数是否更新
	DataManager* m_pData;
	BottleDetParam* m_param;
	void InitControlColor(int ID, COLORREF rgb);
	CameraBasler* m_Camera;//相机指针
	CameraHK1* m_Camera1;//相机指针

	int Step;//0为瓶底；1为模号
	bool isTrigger, isAutoSave;
	int GrabNum;
	/************************************************
	*   功能：更新界面参数，每次启动界面根据配置文件刷新界面参数
	*	参数：
	*	返回值：
	************************************************/
	void DownLoadParam();

	/************************************************
	*   功能：上传面参数，确认参数时将界面参数上传至配置文件
	*	参数：
	*	返回值：
	************************************************/
	void UpLoadParam();
	/*-------------------------------显示窗口----------------------------------*/
	OpencvWin m_win;
	Mat Image;
	vector<Mat>Images;
	deque<vector<Mat>> CImages;//图像变量容器
	bool ExitFlag;

	/************************************************
	*   功能：显示图像
	*	参数：
	*	返回值：
	************************************************/
	void ShowImage(Mat& image);

	/************************************************
	*   功能：图像采集
	************************************************/
	HANDLE hCaptureImageThread;
	//HANDLE hCSaveImageThread;

	HANDLE CAPTURE_EVENT;
	HANDLE COMPLETE_EVENT;
	int Capture_flag;//采图行为，0 退出时补充信号 1单张采集 2单次多张 3连续采集
	bool Sustain;
	CString SaveImage(Mat& image);//保存图像
	CString SaveImage(vector<Mat> &images);
	void WriteImage1(vector<Mat> images, CString name, int i);
	//保存图像
	
	/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	void InitWindowFront();
	CFont* m_font;

	void ConnectCam();
	void OutConnect();

	afx_msg void OnBnClickedButSaveCamParam();
	afx_msg void OnBnClickedButExitCamParam();
	//afx_msg void OnBnClickedButConnectionTest();
	//afx_msg void OnBnClickedButGraySingle();
	afx_msg void OnBnClickedButGrayStill();
	//afx_msg void OnBnClickedButDisconnextion();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
};
