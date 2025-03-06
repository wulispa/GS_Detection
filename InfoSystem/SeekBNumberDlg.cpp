// SeekBNumberDlg.cpp: 实现文件
//

#include "pch.h"
#include "InfoSystem.h"
#include "SeekBNumberDlg.h"
#include "afxdialogex.h"


// SeekBNumberDlg 对话框

IMPLEMENT_DYNAMIC(SeekBNumberDlg, CDialogEx)

SeekBNumberDlg::SeekBNumberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SeekBNumberDlg, pParent)
	, m_BatchNumber(_T(""))
{

}

SeekBNumberDlg::~SeekBNumberDlg()
{
}

void SeekBNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_BatchNumber);
}


BEGIN_MESSAGE_MAP(SeekBNumberDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SeekBNumberDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SeekBNumberDlg 消息处理程序


void SeekBNumberDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);	//把编辑框的内容更新到变量上

	if (m_BatchNumber == TEXT(""))
	{
		MessageBox(TEXT("您的输入为空"), TEXT("提示"));
		return;
	}

	CDialogEx::OnOK();
}
