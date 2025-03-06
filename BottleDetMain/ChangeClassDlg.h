#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "DataManager.h"
#include <algorithm>

using namespace std;

// ChangeClassDlg 对话框

class ChangeClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeClassDlg)

public:
	ChangeClassDlg(CWnd* pParent , DataManager* pdata);   // 标准构造函数
	virtual ~ChangeClassDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGE_CLASS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButSelect();
	///************************************************
	//*   功能：初始化字体
	//*	参数：
	//*	返回值：
	//************************************************/
	//void InitWindowFront();
	//CFont* m_font;

public:
	DataManager* m_pData;
	CListBox m_bottleList;
	CFont* m_font;
	CRect winRect;
	CString new_name;
	/************************************************
	*   功能：初始化窗口字体
	*	参数：
	*	返回值：
	************************************************/
	VOID ChangeClassDlg::InitWindowFront();
	afx_msg void OnBnClickedButDelete();
	afx_msg void OnBnClickedButRename();
	afx_msg void OnBnClickedButCreate();
	afx_msg void OnBnClickedButCertainName();
};
