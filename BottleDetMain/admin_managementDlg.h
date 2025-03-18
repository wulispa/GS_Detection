#pragma once
#include "afxdialogex.h"
#include "resource.h"
#include "BottleDetMainDlg.h"

// admin_managementDlg 对话框

class admin_managementDlg : public CDialogEx
{
	DECLARE_DYNAMIC(admin_managementDlg)

public:
	admin_managementDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~admin_managementDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_admin_management };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	BOOL admin_managementDlg::OnInitDialog();  //初始化

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_list;//列表控件
	SQLInterface SQL; //数据库接口
	MYSQL mysql;  //mysql连接句柄
	CString choose_username;//选择的用户名
	CString message;//提示信息
	int Selected_user; //ListCtrl选中标识符
	int showbutton = 0;//显示密码按钮状态
	vector<std::vector<std::string> > data;


public:
	CString change_password;//新密码
	CString confirmpassword;//确认密码


public:
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedshow();
	afx_msg void OnBnClickedConfirm();
	afx_msg void OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedActivate();
	afx_msg void OnBnClickedLock();
};
