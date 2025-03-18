#pragma once
#include "afxdialogex.h"
#include "RegistDlg.h"
#include "resource.h"
#include "DataManager.h"

// ChangePasswordDlg 对话框

class ChangePasswordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePasswordDlg)

public:
	ChangePasswordDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangePasswordDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Change_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL ChangePasswordDlg::OnInitDialog();

public:
	MYSQL mysql;  //mysql连接句柄
	SQLInterface SQL; //数据库接口
	HBRUSH m_brush;

	vector<std::vector<std::string> > data;

private:
	CString sys_name;//数据库保存用户名
	CString sys_password;//数据库保存密码
public:
	CComboBox m_ComBox1;		//登录用户绑件
	CString name;//用户名
	CString used_password;//原始密码
	CString change_password;//新密码
	CString confirmpassword;//确认密码
	

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedOk();
};
