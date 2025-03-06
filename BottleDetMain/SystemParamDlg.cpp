// SystemParamDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "SystemParamDlg.h"
#include "afxdialogex.h"


// SystemParamDlg 对话框
vector<CString>ImageType = { TEXT("jpg"),TEXT("bmp"),TEXT("png") };
vector<string>ImageTypes = { "jpg","bmp","png" };


IMPLEMENT_DYNAMIC(SystemParamDlg, CDialogEx)

SystemParamDlg::SystemParamDlg(CWnd* pParent,  DataManager* pdata /*=nullptr*/)
	: CDialogEx(IDD_SYSTEM_PARAM_DIALOG, pParent),
	m_pData(pdata)
{
	m_pData->LoadSystemParam();
	m_param = m_pData->GetSystemParam();//初始化参数列表
}

SystemParamDlg::~SystemParamDlg()
{
	m_font->DeleteObject();

}

void SystemParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMG_FORM, m_ImageTypeCom);
}


BEGIN_MESSAGE_MAP(SystemParamDlg, CDialogEx)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUT_CERTION_SYSTEM_PARAM, &SystemParamDlg::OnBnClickedButCertionSystemParam)
	ON_BN_CLICKED(IDC_BUT_EXIT_SYSTEM_PARAM, &SystemParamDlg::OnBnClickedButExitSystemParam)
END_MESSAGE_MAP()


// SystemParamDlg 消息处理程序


BOOL SystemParamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
	//初始化剔瓶模式
	if (m_param->ThrowModel == "NORMAL")
	{
		((CButton*)GetDlgItem(IDC_RADIO_THROW_NORMAL))->SetCheck(TRUE);
	}
	else if (m_param->ThrowModel == "SUSTAIN")
	{
		((CButton*)GetDlgItem(IDC_RADIO_THROW_STILL))->SetCheck(TRUE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO_THROW_NO))->SetCheck(TRUE);
	}
	//初始化显示模式
	if (m_param->ShowModel == "SUSTAIN")
	{
		((CButton*)GetDlgItem(IDC_RADIO_SHOW_STILL))->SetCheck(TRUE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO_SHOW_BAD))->SetCheck(TRUE);
	}
	//初始化存图模式
	if (m_param->SaveModel=="NO")
	{
		((CButton*)GetDlgItem(IDC_RADIO_SAVE_AUTO_OFF))->SetCheck(TRUE);
	}
	else if (m_param->SaveModel == "AUTO")
	{
		((CButton*)GetDlgItem(IDC_RADIO_SAVE_AUTO_ON))->SetCheck(TRUE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO_SAVE_AUTO_BAD))->SetCheck(TRUE);
	}

	//初始化自动锁定功能
	if (m_param->AutoLock == "TRUE")
	{
		((CButton*)GetDlgItem(IDC_CHECK_AUTO_LOCK))->SetCheck(TRUE);
		CString str;
		str.Format(TEXT("%d"), m_param->AutoLockTime);
		SetDlgItemText(IDC_EDIT_AUTO_LOCK_TIME, str);
	}
	int num = 0;
	for (int i = 0; i < ImageType.size(); i++) {
		m_ImageTypeCom.AddString(ImageType[i]);
		if (ImageTypes[i] == m_param->ImageType) {
			num = i;
		}
	}
	m_ImageTypeCom.SetCurSel(num);
	m_font = new CFont();
	InitWindowFront();//初始化字体

	GetDlgItem(IDC_BAD_SHOW_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_SHOW_STILL)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_SHOW_BAD)->ShowWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SystemParamDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


HBRUSH SystemParamDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void SystemParamDlg::OnBnClickedButCertionSystemParam()
{
	// TODO: 在此添加控件通知处理程序代码
	//上传参数至配置文件
	if (((CButton*)GetDlgItem(IDC_RADIO_THROW_NORMAL))->GetCheck()) {
		m_pData->SetThrowModel(TEXT("NORMAL"));
	}
	else if (((CButton*)GetDlgItem(IDC_RADIO_THROW_STILL))->GetCheck())
	{
		m_pData->SetThrowModel(TEXT("SUSTAIN"));
	}
	else
	{
		m_pData->SetThrowModel(TEXT("NO"));
	}
	
	//显示模式
	if (((CButton*)GetDlgItem(IDC_RADIO_SHOW_STILL))->GetCheck()) 
	{
		m_pData->SetShowModel(TEXT("SUSTAIN"));
	}
	else
	{
		m_pData->SetShowModel(TEXT("ONLYBAD"));
	}
	//存图模式
	if (((CButton*)GetDlgItem(IDC_RADIO_SAVE_AUTO_OFF))->GetCheck())
	{
		m_pData->SetSaveModel(TEXT("NO"));
	}
	else if (((CButton*)GetDlgItem(IDC_RADIO_SAVE_AUTO_ON))->GetCheck())
	{
		m_pData->SetSaveModel(TEXT("AUTO"));
	}
	else
	{
		m_pData->SetSaveModel(TEXT("AUTOBAD"));
	}
	//初始化自动锁定功能
	if(((CButton*)GetDlgItem(IDC_CHECK_AUTO_LOCK))->GetCheck())
	{
		m_pData->SetAutoLock(TEXT("TRUE"));
		CString str;
		GetDlgItemText(IDC_EDIT_AUTO_LOCK_TIME, str);
		m_pData->SetAutoLockTime(str);
	}
	else
	{
		m_pData->SetAutoLock(TEXT("FALSE"));
	}

	CString Type_Select;
	int index=0;
	m_ImageTypeCom.GetCurSel();
	m_ImageTypeCom.GetLBText(index, Type_Select);
	m_pData->SetImageType(Type_Select);

	CDialogEx::OnCancel();//退出
}

void SystemParamDlg::InitWindowFront()
{
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 2;
	lfCtrl.lfHeight = 14;
	lfCtrl.lfItalic = false;
	lfCtrl.lfUnderline = false;
	lfCtrl.lfStrikeOut = false;
	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lfCtrl.lfFaceName, L"新宋体");
	lfCtrl.lfWeight = FW_HEAVY;
	m_font->CreateFontIndirectW(&lfCtrl);

	GetDlgItem(IDC_THROW_MODEL_BOX)->SetFont(m_font);
	GetDlgItem(IDC_BAD_SHOW_BOX)->SetFont(m_font);
	GetDlgItem(IDC_SAVE_IMAGE_BOX)->SetFont(m_font);
	GetDlgItem(IDC_BUT_CERTION_SYSTEM_PARAM)->SetFont(m_font);
	GetDlgItem(IDC_BUT_EXIT_SYSTEM_PARAM)->SetFont(m_font);
	
}


void SystemParamDlg::OnBnClickedButExitSystemParam()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
