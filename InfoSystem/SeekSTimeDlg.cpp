// SeekSTimeDlg.cpp: 实现文件
//

#include "pch.h"
#include "InfoSystem.h"
#include "SeekSTimeDlg.h"
#include "afxdialogex.h"


// SeekSTimeDlg 对话框

IMPLEMENT_DYNAMIC(SeekSTimeDlg, CDialogEx)

SeekSTimeDlg::SeekSTimeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SeekSTimeDlg, pParent)
	, m_RecordTime(_T(""))
{

}

SeekSTimeDlg::~SeekSTimeDlg()
{
}

void SeekSTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_RecordTime);
}


BEGIN_MESSAGE_MAP(SeekSTimeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SeekSTimeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SeekSTimeDlg 消息处理程序


void SeekSTimeDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);	//把编辑框的内容更新到变量上

	if (m_RecordTime == TEXT(""))
	{
		MessageBox(TEXT("您的输入为空"), TEXT("提示"));
		return;
	}
	CDialogEx::OnOK();
}
