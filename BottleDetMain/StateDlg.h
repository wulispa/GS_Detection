#pragma once
#include "ChartCtrl.h"
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "DataStatisticXml.h"
#include "DrawBing.h"
#include"ConnDB.h"
#include "DataManager.h"
//#include"ConnDB1.h"

using namespace std;
// StateDlg 对话框

class StateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StateDlg)

public:
	StateDlg(CWnd* pParent, DataStatisticXml* pdatastat);   // 标准构造函数
	StateDlg(CWnd* pParent, DataManager* p_data);   // 标准构造函数
	virtual ~StateDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STATE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CChartCtrl m_Chart;
	afx_msg void OnBnClickedButInquire();
	/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	void InitWindowFront();
	CFont* m_font;
	ConnDB data;
public:
	/*-------------------------------更新数据显示---------------------------------*/
	unordered_map<int, vector<int>> MothData;//每个月的数据
	vector<int> BanData;
	int HourStart, Num;
	//当前日期信息
	int m_Year, m_Moth, m_Day, m_Hour;
	DataStatisticXml* p_mDatastat;
	DataManager* p_Data;
	//DrawBing PiePicture;
	DrawBing bingTu;

	/************************************************
	*   功能：月份数据显示
	*	参数：
	*	返回值：
	************************************************/
	void UpDateMothData();

	/************************************************
	*   功能：每日数据显示
	*	参数：
	*	返回值：
	************************************************/
	void UpdateDayData();

	CWnd* m_picwin;
	CMonthCalCtrl m_mothCtrl;
	afx_msg void OnPaint();
	CComboBox m_BanNum;
	afx_msg void OnCbnSelchangeComboPartNum();
};
