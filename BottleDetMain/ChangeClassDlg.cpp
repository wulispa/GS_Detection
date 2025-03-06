// ChangeClassDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "ChangeClassDlg.h"
#include "afxdialogex.h"


// ChangeClassDlg 对话框

IMPLEMENT_DYNAMIC(ChangeClassDlg, CDialogEx)

ChangeClassDlg::ChangeClassDlg(CWnd* pParent , DataManager* pdata/*=nullptr*/)
	: CDialogEx(IDD_CHANGE_CLASS_DIALOG, pParent),
	m_pData(pdata)
{
	m_pData->LoadBottleParam();
}

ChangeClassDlg::~ChangeClassDlg()
{
	m_font->DeleteObject();

}

void ChangeClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLASS_LIST, m_bottleList);
}


BEGIN_MESSAGE_MAP(ChangeClassDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUT_SELECT, &ChangeClassDlg::OnBnClickedButSelect)
	ON_BN_CLICKED(IDC_BUT_DELETE, &ChangeClassDlg::OnBnClickedButDelete)
	ON_BN_CLICKED(IDC_BUT_RENAME, &ChangeClassDlg::OnBnClickedButRename)
	ON_BN_CLICKED(IDC_BUT_CREATE, &ChangeClassDlg::OnBnClickedButCreate)
	ON_BN_CLICKED(IDC_BUT_CERTAIN_NAME, &ChangeClassDlg::OnBnClickedButCertainName)
END_MESSAGE_MAP()


// ChangeClassDlg 消息处理程序


BOOL ChangeClassDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_font = new CFont();
	InitWindowFront();

	vector<string> bottles = m_pData->GetBottleClasses();
	for (int index = 0; index < bottles.size(); index++)
	{
		CString str(bottles[index].c_str());
		m_bottleList.AddString(str);
	}
	vector<string> bottle_names = m_pData->GetBottleClasses();
	if (bottle_names.size() == 1) {
		GetDlgItem(IDC_BUT_DELETE)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH ChangeClassDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void ChangeClassDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void ChangeClassDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
		//绘制背景

}


void ChangeClassDlg::OnBnClickedButSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int select_index;
	CString select_class;
	select_index=m_bottleList.GetCurSel();
	m_bottleList.GetText(select_index, select_class);
	m_pData->SetSelectBottleName(select_class);
	CDialogEx::OnCancel();

}
VOID ChangeClassDlg::InitWindowFront()
{
	GetClientRect(&winRect);
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 0;
	lfCtrl.lfHeight = winRect.Height() / 24;
	lfCtrl.lfItalic = false;
	lfCtrl.lfUnderline = false;
	lfCtrl.lfStrikeOut = false;
	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lfCtrl.lfFaceName, L"Times New Roman");
	lfCtrl.lfWeight = FW_HEAVY;
	m_font->CreateFontIndirectW(&lfCtrl);
	GetDlgItem(IDC_CLASS_LIST)->SetFont(m_font);
	GetDlgItem(IDC_EDIT_CLASS_NAME)->SetFont(m_font);
	GetDlgItem(IDC_CHANGE_LABEL)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SELECT)->SetFont(m_font);
	GetDlgItem(IDC_BUT_DELETE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_RENAME)->SetFont(m_font);
	GetDlgItem(IDC_BUT_CREATE)->SetFont(m_font);
	return VOID();
}

void ChangeClassDlg::OnBnClickedButDelete()
{
	// TODO: 在此添加控件通知处理程序代码

	int select_index;
	CString select_class;
	select_index = m_bottleList.GetCurSel();
	m_bottleList.GetText(select_index, select_class);
	CString str_now;
	str_now.Format(TEXT("%S"), m_pData->SelectBottleName.c_str());
	if (select_class == str_now) {
		AfxMessageBox(TEXT("当前项不可删除"));
		return;
	}
	m_pData->DeleteBottleClasses(select_class);
	m_bottleList.DeleteString(select_index);
	m_pData->LoadBottleParam();
	vector<string> bottle_names = m_pData->GetBottleClasses();
	if (bottle_names.size() == 1) {
		GetDlgItem(IDC_BUT_DELETE)->EnableWindow(FALSE);
	}
}


void ChangeClassDlg::OnBnClickedButRename()
{
	// TODO: 在此添加控件通知处理程序代码
	int select_index;
	CString select_class;
	select_index = m_bottleList.GetCurSel();
	m_bottleList.GetText(select_index, select_class);
	//CString str;
	//GetDlgItemText(IDC_EDIT_CLASS_NAME, str);
	if (new_name == TEXT("")) {
		AfxMessageBox(TEXT("编辑名称后确定"));
		return;
	}
	else {
		vector<string> bottle_names = m_pData->GetBottleClasses();
		string L = CW2A(new_name.GetString());
		vector<string>::iterator iter = std::find(bottle_names.begin(), bottle_names.end(), L);
		if (iter != bottle_names.end())
		{
			AfxMessageBox(TEXT("名称重复，无法重命名"));
			SetDlgItemText(IDC_EDIT_CLASS_NAME, TEXT(""));
			new_name = TEXT("");
			return;
		}
		string s_str = m_pData->GetSelectBottleName();
		if (new_name == s_str.c_str())
		{
			m_pData->SetSelectBottleName(new_name);
		}
		m_pData->ReNameBottleName(select_class, new_name);
		SetDlgItemText(IDC_EDIT_CLASS_NAME, TEXT(""));
		new_name = TEXT("");
	}
	m_pData->LoadBottleParam();
}


void ChangeClassDlg::OnBnClickedButCreate()
{
	// TODO: 在此添加控件通知处理程序代码
	if (new_name == TEXT("")) {
		AfxMessageBox(TEXT("编辑名称后确定"));
		return;
	}
	else {
		vector<string> bottle_names = m_pData->GetBottleClasses(); 
		string L = CW2A(new_name.GetString());
		vector<string>::iterator iter= std::find(bottle_names.begin(), bottle_names.end(), L);
		if (iter != bottle_names.end())
		{
			AfxMessageBox(TEXT("名称重复"));
			SetDlgItemText(IDC_EDIT_CLASS_NAME, TEXT(""));
			new_name = TEXT("");
			return;
		}
		else
		{
			m_bottleList.AddString(new_name);
			m_pData->AddBottleClasses(new_name);
			SetDlgItemText(IDC_EDIT_CLASS_NAME, TEXT(""));
			new_name = TEXT("");
		}
	}
	m_pData->LoadBottleParam();
	vector<string> bottle_names = m_pData->GetBottleClasses();
	if (bottle_names.size() == 1) {
		GetDlgItem(IDC_BUT_DELETE)->EnableWindow(FALSE);
	}
	else {
		GetDlgItem(IDC_BUT_DELETE)->EnableWindow(TRUE);
	}

}


void ChangeClassDlg::OnBnClickedButCertainName()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT_CLASS_NAME, new_name);

}
