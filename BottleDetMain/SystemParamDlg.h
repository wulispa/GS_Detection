#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "DataManager.h"
#include "publicspace.h"

// SystemParamDlg 对话框

class SystemParamDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SystemParamDlg)

public:
	SystemParamDlg(CWnd* pParent ,DataManager* pdata);   // 标准构造函数
	virtual ~SystemParamDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYSTEM_PARAM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButCertionSystemParam();
	/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	void InitWindowFront();
	CFont* m_font;
public:
	DataManager* m_pData;//参数管理
	SystemParam* m_param;
	CComboBox m_ImageTypeCom;
	afx_msg void OnBnClickedButExitSystemParam();
};
