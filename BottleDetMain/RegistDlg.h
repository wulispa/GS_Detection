#pragma once
#include "afxdialogex.h"
#include "resource.h"
#include <string>
#include "SQLInterface.h"
#include <iostream>  
#include <atlconv.h>
#include "LoginDlg.h"
#include <atlstr.h>
// RegistDlg 对话框

class RegistDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RegistDlg)

public:
	RegistDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RegistDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGIST_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL RegistDlg::OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComBox1;		//注册用户ID绑件
	SQLInterface SQL; //数据库接口
	HBRUSH m_brush;
	MYSQL mysql;  //mysql连接句柄
public:
	CString registname;//注册用户名
	CString password;//密码
	CString confirmpassword;//确认密码
	CString ID;//注册身份
	int IDindex;//注册身份索引
	CString IDcode;//权限码
	CString permissionCode = _T("XXX"); //权限码
	
	vector<std::vector<std::string> > data;


public:
	afx_msg void OnBnClickedBtnRegist();
	int getIDindex(CString ID);//功能: 获取身份索引 用于身份和索引的转换以保存到数据库
};
