// ChangePassWordDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "ChangePassWordDlg.h"
#include "afxdialogex.h"
#include "LoginDlg.h"


// ChangePassWordDlg 对话框

IMPLEMENT_DYNAMIC(ChangePassWordDlg, CDialogEx)

ChangePassWordDlg::ChangePassWordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDIT_PASS_DLG, pParent),
	pwin(pParent)
{
}

ChangePassWordDlg::~ChangePassWordDlg()
{
}

void ChangePassWordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChangePassWordDlg, CDialogEx)
	ON_BN_CLICKED(IDOK_PASSWORLD, &ChangePassWordDlg::OnBnClickedPassworld)
	ON_BN_CLICKED(IDCANCEL_PASSWORD, &ChangePassWordDlg::OnBnClickedPassword)
END_MESSAGE_MAP()


// ChangePassWordDlg 消息处理程序


void ChangePassWordDlg::OnBnClickedPassworld()
{
	// TODO: 在此添加控件通知处理程序代码
	LoginDlg* win = (LoginDlg*)pwin;
	CString password;
	GetDlgItemText(IDC_EDIT_WRITE_PASSWORD, password);
	win->passWord[win->UserSelectindex] = password;
	CDialogEx::OnOK();
}


void ChangePassWordDlg::OnBnClickedPassword()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
