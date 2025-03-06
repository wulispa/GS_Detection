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
//#include "AlgorithmIdentify.h"
#include "MoldSelectDlg.h"
#include "CameraBasler.h"
#include "Detection.h"


using namespace std;
using namespace cv;
using namespace HalconCpp;

// CheckParamDlg 对话框

class CheckParamDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CheckParamDlg)

public:
	CheckParamDlg(CWnd* pParent, DataManager* pdata);   // 标准构造函数	
	CheckParamDlg(CWnd* pParent, DataManager* pdata, Mat img);   // 标准构造函数
	CheckParamDlg(CWnd* pParent, DataManager* pdata, vector<Mat> imgs);   // 标准构造函数
	CheckParamDlg(CWnd* pParent, DataManager* pdata, vector<Mat> imgs, Detection* m_Detection);   // 标准构造函数
	CheckParamDlg(CWnd* pParent, DataManager* pdata, vector<Mat> imgs, 
		Detection* m_Detection, AlgorithmBase m_algo);   // 标准构造函数

	virtual ~CheckParamDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHECK_PARAM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButLoadModel();

public:
	CString model_path;//模型路径
	CString Profile_path;//配置文件路径
	CString Image_path;//图像路径
	double ThreadValue;//检测阈值
	double ThreadValueLW;
	CString ThreadModel;
	int GrayValue;
	CString GrayModel;
	CString ChoseModel;
	BOOL Show_region;//显示缺陷轮廓
	//BOOL Mold_Recognition;
	DataManager* m_pData;
	vector<int> contra_val_vec, area_val_vec, gray_val_vec;
	CameraBasler m_Cam;
	Detection *m_Det;
	//GS码
	CString TriggerDistance;
	CString	PhotoelectricDistance;
	int PickBottle;
	CString DeadLine;
	CString UpNumber;
	CString UpMold;
	CString DownNumber;
	CString DownMold;
	CString UpResult;
	CString DownResult;


	/************************************************
	*   功能：更新界面参数，每次启动界面根据配置文件刷新界面参数
	*	参数：
	*	返回值：
	************************************************/
	void DownLoadParam();

	/************************************************
	*   功能：上传界面参数，确认参数时将界面参数上传至配置文件
	*	参数：
	*	返回值：
	************************************************/
	void UpLoadParam();
	/*-------------------------------显示窗口----------------------------------*/
	OpencvWin m_win;
	HalconWin m_HalconWin;
	Mat Image;
	vector<Mat>Images;
	int number;
	HObject ho_Image;
	bool isHalconWinOpen = false;
	void OpenHalconWin();
	bool isImage;
	bool draw_done = true;
	int Mask_flag;
	bool NotEmpty;
	vector<Mat> GetDetImages;
	/************************************************
	*   功能：显示图像
	*	参数：
	*	返回值：
	************************************************/
	void ShowImage(Mat& image);
	void InitControlColor(int ID, COLORREF rgb);

	/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	void InitWindowFront();
	CFont* m_font;

	/************************************************
	*   功能：算法检测
	************************************************/
	HANDLE hTestThreaed;
	AlgorithmBase m_algorithm;
	//AlgorithmIdentify m_AlgorithmIdentify;
	HANDLE CHECK_EVENT;
	int result;//1 OK -1 NG 
	vector<pair<int, int>> m_points;//轮廓坐标
	bool m_Exit;
	bool isChecking;
	bool isChanged;
	//CString model_path;

	/************************************************
	*   功能：检测函数
	*	参数：
	*	返回值：
	************************************************/
	void CheckByAlgorithm();

	/************************************************
	*   功能：显示检测结果
	*	参数：
	*	返回值：
	************************************************/
	void ShowCheckResult(Mat image, vector<cv::Rect> m_points, int result, string detect_ID, string Name);
	void ShowCheckResult(Mat image, vector<cv::Rect> m_points, int result, string detect_ID);
	void ShowCheckResult(Mat image, int result);
	CString GetArrayFromCstringBySep(const CString& str, const TCHAR cSep);

	void ShowAndTrans(Mat img);
	/************************************************
	*   功能：单通道转三通道
	*	参数：
	*	返回值：
	************************************************/
	Mat Trans2RGB(Mat& image);
	HObject Mat2HObject(cv::Mat& cv_img);
	vector<int> Str2Vec(string str);
	int str2int(string str);
	int CStr2int(CString strr);
	CString Vec2CStr(vector<int> vals);
	void SaveLast(int MaskFlag);

	afx_msg void OnBnClickedButLoadParamFile();
	afx_msg void OnBnClickedButLoadImage();
	CButton m_RadioShowRegion;
	afx_msg void OnBnClickedButSaveParam();
	afx_msg void OnBnClickedButExitDetParam();
	afx_msg void OnBnClickedButRunTest();
	afx_msg void OnBnClickedButChangeClassDet();
	afx_msg void OnBnClickedButMoldSelect();
	//afx_msg void OnBnClickedButOuterRectangle();
	afx_msg void OnBnClickedButOuterCycle();
	//afx_msg void OnBnClickedButOuterPolygon();
	//afx_msg void OnBnClickedButInnerRectangle();
	afx_msg void OnBnClickedButInnerCycle();
	//afx_msg void OnBnClickedButInnerPolygon();
	afx_msg void OnBnClickedButDeleteRegion();
	afx_msg void OnBnClickedButSaveRegion();
	//afx_msg void OnBnClickedBtnLast();
	//afx_msg void OnBnClickedBtnNext();
	afx_msg void OnBnClickedButAitool();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	CComboBox Image_num_box;
	afx_msg void OnCbnSelchangeComboImageNum();
	afx_msg void OnBnClickedButGrabTest();
	afx_msg void OnBnClickedRadioMask1();
	afx_msg void OnBnClickedRadioMask2();
	afx_msg void OnBnClickedRadioMask3();
	afx_msg void OnBnClickedRadioMask4();
	afx_msg void OnBnClickedRadioPic1();
	afx_msg void OnBnClickedRadioPic2();
	afx_msg void OnBnClickedRadioPic3();
	afx_msg void OnBnClickedRadioPic4();
	afx_msg void OnBnClickedRadioPic5();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonCullingtest();
};
