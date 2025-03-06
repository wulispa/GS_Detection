#pragma once
#include "SystemParamDlg.h"
#include "CheckParamDlg.h"
#include "CameraParamDlg.h"
#include "ChangeClassDlg.h"
#include "BottleDetMainDlg.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "DataManager.h"
#include "tinyxml2.h"
#include <atlconv.h> 

using namespace std;

// LoginDlg 对话框

class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	LoginDlg(CWnd* pParent,DataManager* pdata);   // 标准构造函数
	virtual ~LoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DIALOG };
#endif

protected:
	CWnd* parent_win;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();			//初始化


	CFont cfont;
	CFont m_oFont;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnLogin();
	CString m_username; // 用户名字符串
	CString m_password; // 密码字符串
	CString r_username; // 注册用户名字符串
	CString r_password; // 注册密码字符串
	CString r_confirm_password; // 确认密码字符串
	CString IDcode_password; // 权限码字符串
	DataManager* m_pData;//参数管理



	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CComboBox m_ComBox1;		//登录用户绑件
	CComboBox m_ComBox2;		// 录入用户绑件
	
	afx_msg void OnEnChangeEditPassword();
public:
	vector<CString> passWord;
	int UserSelectindex;//管理员  0  操作员1
	void ReadConfiger();
	void WriteConfiger();
	HBRUSH m_brush;
public:
	afx_msg void OnBnClickedButChangePassword();
	afx_msg void OnPaint();
protected:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
public:
	afx_msg void OnBnClickedBtnReigst();
	

	

};
