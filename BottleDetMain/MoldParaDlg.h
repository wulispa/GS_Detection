#pragma once
#include "OpencvWin.h"
#include "HalconCpp.h"
#include "HalconWin.h"
#include <iostream>
#include <opencv.hpp>
#include <vector>
#include <string>
#include "DataManager.h"
#include "AlgorithmBase.h"
#include "ChangeClassDlg.h"
#include "MoldSelectDlg.h"
#include "CameraBasler.h"
#include "Detection.h"

using namespace std;
using namespace cv;
using namespace HalconCpp;

// MoldParaDlg 对话框

class MoldParaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MoldParaDlg)

public:
	MoldParaDlg(CWnd* pParent = nullptr);   // 标准构造函数
	MoldParaDlg(CWnd* pParent, DataManager* pdata);   // 标准构造函数
	MoldParaDlg(CWnd* pParent, DataManager* pdata, Mat img);   // 标准构造函数

	virtual ~MoldParaDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOLD_PARAM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	MyXml bottle_xml;

	DataManager* m_pData;
	Mat Image;
	CString Image_path;//图像路径
	OpencvWin m_win;
	HalconWin m_HalconWin;
	HObject ho_Image;
	bool isHalconWinOpen = false;
	bool isImage;
	//HANDLE CHECK_EVENT;
	//HANDLE hTestThreaed;
	CFont* m_font;

	int result;//1 OK -1 NG 
	string IDresult;
	bool isChecking;
	bool m_Exit;
	int left_val, right_val;//左右裁剪值

	void InitControlColor(int ID, COLORREF rgb);
	void ShowAndTrans(Mat img);
	void ShowImage(Mat& image);
	void OpenHalconWin();
	HObject Mat2HObject(cv::Mat& cv_img);
	void ShowCheckResult(Mat image, string detect_ID);
	Mat Trans2RGB(Mat& image);
	vector<int> Str2Vec(string str);
	int str2int(string str);

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
	/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	void InitWindowFront();
	/************************************************
	*   功能：检测函数
	*	参数：
	*	返回值：
	************************************************/
	void CheckByAlgorithm();


	afx_msg void OnBnClickedButMoldExit();
	afx_msg void OnBnClickedButSelect();
	afx_msg void OnBnClickedButReadMoldImage();
	afx_msg void OnBnClickedButMoldRunTest();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);//不给移动
	afx_msg void OnBnClickedButMoldSave();
};
