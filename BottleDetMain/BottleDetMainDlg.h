
// BottleDetMainDlg.h: 头文件
//

#pragma once
#include "BtnST.h"
#include "ScreenRect.h"
#include "OpencvWin.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include "CvvImage.h"
#include "publicspace.h"
#include "SystemParamDlg.h"
#include "CheckParamDlg.h"
#include "CameraParamDlg.h"
#include "ChangeClassDlg.h"
#include "DataManager.h"
#include "publicspace.h"
#include "Detection.h"
#include "LoginDlg.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include <deque>
#include "DataStatisticXml.h"
#include"ConnDB.h"
//#include"ConnDB1.h"
#include <TlHelp32.h>
#include "MoldParaDlg.h"
#include <windows.h>

using namespace std;
//#define _AFXDLL

#define N_TIME_SEC 1000 //一秒时间间隔
#define N_TIME_SHOW 200 //0.2s刷新显示
#define N_TIME_SHOWLOG 5000 //双击日志，显示异常图像，停留5s
#define N_TIME_WRITE_STAT  120000//10分钟->5分钟->2
#define N_TIMER_SEC 1
#define N_TIMER_SHOW 2
#define N_TIMER_SHOWLOG 4
#define N_TIME_LOCALSHOW 3		//0.2s刷新显示
#define N_TIMER_WRITE_STAT 5	//每隔10分钟刷新一次数据库统计,10->5->2
#define N_TIMER_LOCK 6			//自动锁定功能定时

#define M_LABEL_COLOR RGB(40,2,247);
// CBottleDetMainDlg 对话框
class CBottleDetMainDlg : public CDialogEx
{
// 构造
public:
	CBottleDetMainDlg(CWnd* pParent = nullptr);	// 标准构造函数
	~CBottleDetMainDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOTTLEDETMAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

private:
	BOOL  IsProccessRunning(CString strProccess);
	BOOL KillProcess(CString sExeName);
	
public:
	POINT Old;
	HBRUSH m_brushBack;
	HBRUSH m_brushBule;
	CRect winRect;
	CFont *m_font;
	bool ChangeFront;
	OpencvWin* ImageWin;
	CButton m_StartButton, m_LockButton, m_SystemButton, m_CamButton, m_DetButton,
		 m_ExitButton, m_zero;
	CButton m_ChangeClsButton, m_SearchButton;
	CStatic m_picture;
	bool RunState;
	bool LockState;
	DataManager* m_pData;
	Detection* m_Detection;//
	//CameraParamDlg CamDlg;
	//vector<Mat> CamDlgImages;
	long int num_good;//良品总数
	long int num_bad;//次品总数
	int old_num;//每分钟检测数量
	long int num_mold;//模号统计数
	long int num_id;//
	const char* name;
	int num_ng1, num_ng2, num_ng3, num_ng4;
	bool PassLogin;
	bool ExitFlag;
	ConnDB data;
	int Step;
	string DetectionType;
	CString CStrProductBatch;
	/************************************************
	*   功能：得到产品批次
	*	参数：无
	*	返回值：无
	************************************************/
	CString GetCStrProductBatch();


	/************************************************
	*   功能：更改按钮是否使能状态图片
	*	参数：控件ID,颜色、图片
	*	返回值：无
	************************************************/
	void UpdateBtnPic();
	HBITMAP hBmp1, hBmp2, hBmp3, hBmp4, hBmp5, hBmp6, hBmp7, hBmp8, hBmp9, hBmp10,
		hBmp11, hBmp12, hBmp13, hBmp14, hBmp15, hBmp16, hBmp17, hBmp18, hBmp19, hBmp20;

	/************************************************
	*   功能：更改口大小
	*	参数：控件ID,颜色
	*	返回值：无
	************************************************/

	
	void ResizeWindow();

	/************************************************
	*   功能：初始化静态控件颜色
	*	参数：控件ID,颜色
	*	返回值：无
	************************************************/
	void InitControlColor(int ID, COLORREF rgb);

	/************************************************
	*   功能：设置按钮颜色
	*	参数:  控件ID  控件颜色
	*	返回值：无
	************************************************/
	void SetButtonColor(CButtonST* butPtr, COLORREF rgbOut, COLORREF rgbFcous, COLORREF rgbIn);
	void SetButtonColor(CButtonST* butPtr, COLORREF color);//重载一次
	/************************************************
	*   功能：初始化窗口布局
	*	参数：
	*	返回值：
	************************************************/
	VOID InitWindowRect();

	/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	VOID InitWindowFront();


	/*-------------------------------UI交互使用-----------------------------*/

/*********************************************
 * @name		: 启动/停止检测设置界面风格
 * @in param input_para	: none
 * @out param output_para : none
 * @return : none
 ********************************************/
	void SetStartStyle();
	void SetStopStyle();

/*********************************************
* @name		: 锁定/解锁时检测设置界面风格
* @in param input_para	: none
* @out param output_para : none
* @return : none
********************************************/
	void SetLockStyle();
	void SetUnlockStyle();

	/************************************************
	*   功能：更新瓶子类别框内容
	*	参数：
	*	返回值：
	************************************************/
	void UpdateBottleClass();

	/************************************************
	*   功能：刷新检测统计结果
	*	参数：
	*	返回值：
	************************************************/
	void UpdateResultBox();

	/************************************************
	*   功能：添加一条次品记录
	*	参数：
	*	返回值：
	************************************************/
	void UpDateLOGbox(CString name);
	void UpDateLOGbox(CString name, string DetectionType);
	int now_index;
	int select_index;
	int LastTime;
	int StopShow;

	/************************************************
	*   功能：刷新检测图像
	*	参数：
	*	返回值：
	************************************************/
	void UpdateProduct(Mat& image, string ID, int identify_res);//重载一次，单独模号
	void UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string res_name);//重载一次，去掉模号
	void UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string ID, int identify_res, string res_name);//重载一次添加模号剔瓶结果
	void UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string ID,int identify_res);//重载一次添加模号剔瓶结果
	//void UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string ID);//重载一次添加模号检测
	void UpdateProduct(Mat& image, vector<cv::Rect> points, int result,int DeTime);//重载一次添加检测耗时
	void UpdateProduct(Mat& image,vector<cv::Rect> points, int result,string deadline, string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult);
	void UpdateProduct(vector<Mat>& images, vector<cv::Rect> points, int result);
	void UpdateProduct(Mat& image, int result);
	void UpdateProduct(vector<Mat>& images, int result);
	/************************************************
	*   功能：刷新图片显示
	*	参数：
	*	返回值：
	************************************************/
	void show_image(cv::Mat& image, int result);
	void show_image(cv::Mat& image, int result,vector<cv::Rect> points);//重载一次
	void show_image(cv::Mat image, int result, vector<cv::Rect> points, string detect_ID);//重载一次 添加模号检测
	void show_image(cv::Mat image, int result, vector<cv::Rect> points, string detect_ID, string Name);//重载一次 添加模号检测
	Mat Trans2RGB(Mat& image);//单通道转三通道
	vector<int> Str2Vec(string str);
	int str2int(string str);

	/************************************************
	*   功能：保存图像
	*	参数：图片变量、结果
	*	返回值：返回图片路径
	************************************************/
	CString SaveImage(vector<Mat>& images, int result,string Type);

/*--------------------------------检测主线程--------------------------------*/
public:
	/************************************************
	*   功能：启动检测
	*	参数：
	*	返回值：
	************************************************/
	bool StartRun();

	/************************************************
	*   功能：停止检测
	*	参数：
	*	返回值：
	************************************************/
	void StopRun();

/*----------------------------------计时器--------------------------------*/								
	int n_hour;
	int n_minute;
	int n_second;
	CString s_hour;
	CString s_minute;
	CString s_second;
	bool b_Stop;
	int m_duration;//检测时长(分钟为单位)
	/************************************************
	*   功能：启动计时
	*	参数：
	*	返回值：
	************************************************/
	void TimeStart();
	void LockTimeStart();
	/************************************************
	*   功能：停止计时
	*	参数：
	*	返回值：
	************************************************/
	void TimeStop();
	void LockTimeStop();

	/************************************************
	*   功能：计时清0
	*	参数：
	*	返回值：
	************************************************/
	void TimeReset();

	/************************************************
	*   功能：刷新本地时间
	*	参数：
	*	返回值：
	************************************************/
	void UpdateLocalTime();
public:
	/*-----------------------------------异常图像列表-----------------------------------*/
	unordered_map<int, CString>BadImageList;//图像列表，保存异常图像名称
	deque<vector<Mat>> ProductsImage;//缓存检测结果，用于显示和保存，瓶底
	deque<vector<Mat>> ProductsImage1;//缓存检测结果，用于显示和保存，模号

	deque<int> ProductsResult;
	vector<Mat> dst;		//瓶底
	vector<Mat> dst1;		//模号

	HANDLE hSaveThread;
	//HANDLE hSaveThread1;

	//Mat RGBimage;//添加图像变量，用于三通道图像转换
	deque<vector<cv::Rect>>DetResultRects;//缓存检测矩形框
	deque<int>DetTimeCost;//缓存检测时间
	deque<string>DetID;//模号检测ID
	deque<int>DetIdentifyRes;//模号剔瓶结果
	deque<string>DetName;//缺陷检测名
	/*-----------------------------------界面GS码结果显示列表-----------------------------------*/
	deque<string>DeadlineName;
	deque<string>UpCodeName;
	deque<string>DownCodeName;
	deque<string>UpNumberName;
	deque<string>DownNumberName;
	deque<string>UpResultName;
	deque<string>DownResultName;
	void UpDateDlgtext(string DeadlineName, string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult);

public:
	/*-----------------------------------数据统计----------------------------------------*/
	DataStatisticXml m_DataStat;//数据库对象
	int oldNumGood, oldNumBad;
	int oldNg1, oldNg2, oldNg3, oldNg4;
	/************************************************
	*   功能：更新数据库数据，每隔10分钟更新一次统计结果,写入数据库
	*	参数：
	*	返回值：
	************************************************/
	void UpdateDataSat(int num_OK, int num_NG);
	void UpdateDataSat(int num_OK, int num_NG1, int num_NG2, int num_NG3, int num_NG4);

	/*-----------------------------------更新检测时间---------------------------------------*/
	void UpDateDetectTime(int n_time);


	


// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数000
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButAutoDet();
	afx_msg void OnBnClickedButLock();
	afx_msg void OnBnClickedButDetParam();
	afx_msg void OnBnClickedButCamParam();
	afx_msg void OnBnClickedButChangeClass();
	afx_msg void OnBnClickedButSystemParam();
	afx_msg void OnBnClickedButStat();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedButExit();
	afx_msg void OnBnClickedButClear();
	CListBox m_BadLogList;
	afx_msg void OnLbnSelchangeListBadBottle();
	afx_msg void OnLbnDblclkListBadBottle();
	//afx_msg void OnBnClickedButPingdi();
	//afx_msg void OnBnClickedButMohao();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);

	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
};
