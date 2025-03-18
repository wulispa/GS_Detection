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
	LoginDlg(CWnd* pParent = nullptr);   
	LoginDlg(CWnd* pParent,DataManager* pdata);   
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
	afx_msg void OnBnClickedBtnLogin();
	CString m_username; // 用户名字符串
	CString name;//用户名
	CString password;//密码
	bool state;//状态
	CString datetime;//时间
	CString m_password; // 密码字符串
	int wrongtimes;//错误次数
	DataManager* m_pData;//参数管理



	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CComboBox m_ComBox1;		//登录用户绑件
	
public:
	vector<CString> passWord;
	SQLInterface SQL; //数据库接口
	MYSQL mysql;  //mysql连接句柄
	vector<std::vector<std::string> > data;
	int UserSelectindex;//管理员  0  操作员1
	void ReadConfiger();
	void WriteConfiger();
	HBRUSH m_brush;
public:

	afx_msg void OnPaint();
protected:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
public:
	
	afx_msg void OnBnClickedBtnRegist();
	afx_msg void OnBnClickedBtnChangepassword();
};
