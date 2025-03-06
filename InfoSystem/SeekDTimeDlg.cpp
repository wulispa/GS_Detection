// SeekDTimeDlg.cpp: 实现文件
//

#include "pch.h"
#include "InfoSystem.h"
#include "SeekDTimeDlg.h"
#include "afxdialogex.h"


// SeekDTimeDlg 对话框

IMPLEMENT_DYNAMIC(SeekDTimeDlg, CDialogEx)

SeekDTimeDlg::SeekDTimeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SeekDTimeDlg, pParent)
	, m_ExpiringDate(_T(""))
{

}

SeekDTimeDlg::~SeekDTimeDlg()
{
}

void SeekDTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_ExpiringDate);
	DDX_Text(pDX, IDC_EDIT1, m_ExpiringDate);
}


BEGIN_MESSAGE_MAP(SeekDTimeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SeekDTimeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SeekDTimeDlg 消息处理程序


void SeekDTimeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);	//把编辑框的内容更新到变量上

	if (m_ExpiringDate == TEXT(""))
	{
		MessageBox(TEXT("您的输入为空"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
