#pragma once
#include "ChartCtrl.h"

// StatShowDlg 对话框

class StatShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StatShowDlg)

public:
	StatShowDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StatShowDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAT_DLG };
#endif

public:
	void InitControlColor(int ID, COLORREF rgb);

//public:
	//CChartCtrl m_Chart;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();


};
