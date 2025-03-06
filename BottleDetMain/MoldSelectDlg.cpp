// MoldSelectDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "MoldSelectDlg.h"
#include "afxdialogex.h"
#include <winnt.rh>


// MoldSelectDlg 对话框

IMPLEMENT_DYNAMIC(MoldSelectDlg, CDialogEx)

MoldSelectDlg::MoldSelectDlg(CWnd* pParent, DataManager* pdata/*=nullptr*/)
	: CDialogEx(IDD_MOLD_SELECT_DIALOG, pParent),
	m_pData(pdata)
{
	m_pData->LoadBottleDetParam();

}

MoldSelectDlg::~MoldSelectDlg()
{
	m_font->DeleteObject();

}

void MoldSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUT_MOLD1, m_Mold1);
	DDX_Control(pDX, IDC_BUT_MOLD2, m_Mold2);
	DDX_Control(pDX, IDC_BUT_MOLD3, m_Mold3);
	DDX_Control(pDX, IDC_BUT_MOLD4, m_Mold4);
	DDX_Control(pDX, IDC_BUT_MOLD5, m_Mold5);
	DDX_Control(pDX, IDC_BUT_MOLD6, m_Mold6);
	DDX_Control(pDX, IDC_BUT_MOLD7, m_Mold7);
	DDX_Control(pDX, IDC_BUT_MOLD8, m_Mold8);
	DDX_Control(pDX, IDC_BUT_MOLD9, m_Mold9);
	DDX_Control(pDX, IDC_BUT_MOLD10, m_Mold10);
	DDX_Control(pDX, IDC_BUT_MOLD11, m_Mold11);
	DDX_Control(pDX, IDC_BUT_MOLD12, m_Mold12);
	DDX_Control(pDX, IDC_BUT_MOLD13, m_Mold13);
	DDX_Control(pDX, IDC_BUT_MOLD14, m_Mold14);
	DDX_Control(pDX, IDC_BUT_MOLD15, m_Mold15);
	DDX_Control(pDX, IDC_BUT_MOLD16, m_Mold16);
	DDX_Control(pDX, IDC_BUT_MOLD17, m_Mold17);
	DDX_Control(pDX, IDC_BUT_MOLD18, m_Mold18);
	DDX_Control(pDX, IDC_BUT_MOLD19, m_Mold19);
	DDX_Control(pDX, IDC_BUT_MOLD20, m_Mold20);
	DDX_Control(pDX, IDC_BUT_MOLD21, m_Mold21);
	DDX_Control(pDX, IDC_BUT_MOLD22, m_Mold22);
	DDX_Control(pDX, IDC_BUT_MOLD23, m_Mold23);
	DDX_Control(pDX, IDC_BUT_MOLD24, m_Mold24);
	DDX_Control(pDX, IDC_BUT_MOLD25, m_Mold25);
	DDX_Control(pDX, IDC_BUT_MOLD26, m_Mold26);
	DDX_Control(pDX, IDC_BUT_MOLD27, m_Mold27);
	DDX_Control(pDX, IDC_BUT_MOLD28, m_Mold28);
	DDX_Control(pDX, IDC_BUT_MOLD29, m_Mold29);
	DDX_Control(pDX, IDC_BUT_MOLD30, m_Mold30);
	DDX_Control(pDX, IDC_BUT_MOLD31, m_Mold31);
	DDX_Control(pDX, IDC_BUT_MOLD32, m_Mold32);
	DDX_Control(pDX, IDC_BUT_MOLD33, m_Mold33);
	DDX_Control(pDX, IDC_BUT_MOLD34, m_Mold34);
	DDX_Control(pDX, IDC_BUT_MOLD35, m_Mold35);
	DDX_Control(pDX, IDC_BUT_MOLD36, m_Mold36);
	DDX_Control(pDX, IDC_BUT_MOLD37, m_Mold37);
	DDX_Control(pDX, IDC_BUT_MOLD38, m_Mold38);
	DDX_Control(pDX, IDC_BUT_MOLD39, m_Mold39);
	DDX_Control(pDX, IDC_BUT_MOLD40, m_Mold40);
	DDX_Control(pDX, IDC_BUT_MOLD41, m_Mold41);
	DDX_Control(pDX, IDC_BUT_MOLD42, m_Mold42);
	DDX_Control(pDX, IDC_BUT_MOLD43, m_Mold43);
	DDX_Control(pDX, IDC_BUT_MOLD44, m_Mold44);
	DDX_Control(pDX, IDC_BUT_MOLD45, m_Mold45);
	DDX_Control(pDX, IDC_BUT_MOLD46, m_Mold46);
	DDX_Control(pDX, IDC_BUT_MOLD47, m_Mold47);
	DDX_Control(pDX, IDC_BUT_MOLD48, m_Mold48);
	DDX_Control(pDX, IDC_BUT_MOLD49, m_Mold49);
	DDX_Control(pDX, IDC_BUT_MOLD50, m_Mold50);
	DDX_Control(pDX, IDC_BUT_MOLD51, m_Mold51);
	DDX_Control(pDX, IDC_BUT_MOLD52, m_Mold52);
	DDX_Control(pDX, IDC_BUT_MOLD53, m_Mold53);
	DDX_Control(pDX, IDC_BUT_MOLD54, m_Mold54);
	DDX_Control(pDX, IDC_BUT_MOLD55, m_Mold55);
	DDX_Control(pDX, IDC_BUT_MOLD56, m_Mold56);
	DDX_Control(pDX, IDC_BUT_MOLD57, m_Mold57);
	DDX_Control(pDX, IDC_BUT_MOLD58, m_Mold58);
	DDX_Control(pDX, IDC_BUT_MOLD59, m_Mold59);
	DDX_Control(pDX, IDC_BUT_MOLD60, m_Mold60);
	DDX_Control(pDX, IDC_BUT_MOLD61, m_Mold61);
	DDX_Control(pDX, IDC_BUT_MOLD62, m_Mold62);
	DDX_Control(pDX, IDC_BUT_MOLD63, m_Mold63);
	DDX_Control(pDX, IDC_BUT_MOLD64, m_Mold64);
	DDX_Control(pDX, IDC_BUT_MOLD65, m_Mold65);
	DDX_Control(pDX, IDC_BUT_MOLD66, m_Mold66);
	DDX_Control(pDX, IDC_BUT_MOLD67, m_Mold67);
	DDX_Control(pDX, IDC_BUT_MOLD68, m_Mold68);
	DDX_Control(pDX, IDC_BUT_MOLD69, m_Mold69);
	DDX_Control(pDX, IDC_BUT_MOLD70, m_Mold70);
	DDX_Control(pDX, IDC_BUT_MOLD71, m_Mold71);
	DDX_Control(pDX, IDC_BUT_MOLD72, m_Mold72);
	DDX_Control(pDX, IDC_BUT_MOLD73, m_Mold73);
	DDX_Control(pDX, IDC_BUT_MOLD74, m_Mold74);
	DDX_Control(pDX, IDC_BUT_MOLD75, m_Mold75);
	DDX_Control(pDX, IDC_BUT_MOLD76, m_Mold76);
	DDX_Control(pDX, IDC_BUT_MOLD77, m_Mold77);
	DDX_Control(pDX, IDC_BUT_MOLD78, m_Mold78);
	DDX_Control(pDX, IDC_BUT_MOLD79, m_Mold79);
	DDX_Control(pDX, IDC_BUT_MOLD80, m_Mold80);
	DDX_Control(pDX, IDC_BUT_MOLD81, m_Mold81);
	DDX_Control(pDX, IDC_BUT_MOLD82, m_Mold82);
	DDX_Control(pDX, IDC_BUT_MOLD83, m_Mold83);
	DDX_Control(pDX, IDC_BUT_MOLD84, m_Mold84);
	DDX_Control(pDX, IDC_BUT_MOLD85, m_Mold85);
	DDX_Control(pDX, IDC_BUT_MOLD86, m_Mold86);
	DDX_Control(pDX, IDC_BUT_MOLD87, m_Mold87);
	DDX_Control(pDX, IDC_BUT_MOLD88, m_Mold88);
	DDX_Control(pDX, IDC_BUT_MOLD89, m_Mold89);
	DDX_Control(pDX, IDC_BUT_MOLD90, m_Mold90);
	DDX_Control(pDX, IDC_BUT_MOLD0, m_Mold0);

}


BEGIN_MESSAGE_MAP(MoldSelectDlg, CDialogEx)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUT_SELECT_EXIT, &MoldSelectDlg::OnBnClickedButSelectExit)
	ON_BN_CLICKED(IDC_BUT_SELECT_SAVE, &MoldSelectDlg::OnBnClickedButSelectSave)
	ON_BN_CLICKED(IDC_BUT_LOAD_MOLD_MODEL, &MoldSelectDlg::OnBnClickedButLoadMoldModel)
	ON_BN_CLICKED(IDC_BUT_MOLD1, &MoldSelectDlg::OnBnClickedButMold1)
	ON_BN_CLICKED(IDC_BUT_MOLD2, &MoldSelectDlg::OnBnClickedButMold2)
	ON_BN_CLICKED(IDC_BUT_MOLD3, &MoldSelectDlg::OnBnClickedButMold3)
	ON_BN_CLICKED(IDC_BUT_MOLD4, &MoldSelectDlg::OnBnClickedButMold4)
	ON_BN_CLICKED(IDC_BUT_MOLD5, &MoldSelectDlg::OnBnClickedButMold5)
	ON_BN_CLICKED(IDC_BUT_MOLD6, &MoldSelectDlg::OnBnClickedButMold6)
	ON_BN_CLICKED(IDC_BUT_MOLD7, &MoldSelectDlg::OnBnClickedButMold7)
	ON_BN_CLICKED(IDC_BUT_MOLD8, &MoldSelectDlg::OnBnClickedButMold8)
	ON_BN_CLICKED(IDC_BUT_MOLD9, &MoldSelectDlg::OnBnClickedButMold9)
	ON_BN_CLICKED(IDC_BUT_MOLD10, &MoldSelectDlg::OnBnClickedButMold10)
	ON_BN_CLICKED(IDC_BUT_MOLD11, &MoldSelectDlg::OnBnClickedButMold11)
	ON_BN_CLICKED(IDC_BUT_MOLD12, &MoldSelectDlg::OnBnClickedButMold12)
	ON_BN_CLICKED(IDC_BUT_MOLD13, &MoldSelectDlg::OnBnClickedButMold13)
	ON_BN_CLICKED(IDC_BUT_MOLD14, &MoldSelectDlg::OnBnClickedButMold14)
	ON_BN_CLICKED(IDC_BUT_MOLD15, &MoldSelectDlg::OnBnClickedButMold15)
	ON_BN_CLICKED(IDC_BUT_MOLD16, &MoldSelectDlg::OnBnClickedButMold16)
	ON_BN_CLICKED(IDC_BUT_MOLD17, &MoldSelectDlg::OnBnClickedButMold17)
	ON_BN_CLICKED(IDC_BUT_MOLD18, &MoldSelectDlg::OnBnClickedButMold18)
	ON_BN_CLICKED(IDC_BUT_MOLD19, &MoldSelectDlg::OnBnClickedButMold19)
	ON_BN_CLICKED(IDC_BUT_MOLD20, &MoldSelectDlg::OnBnClickedButMold20)
	ON_BN_CLICKED(IDC_BUT_MOLD21, &MoldSelectDlg::OnBnClickedButMold21)
	ON_BN_CLICKED(IDC_BUT_MOLD22, &MoldSelectDlg::OnBnClickedButMold22)
	ON_BN_CLICKED(IDC_BUT_MOLD23, &MoldSelectDlg::OnBnClickedButMold23)
	ON_BN_CLICKED(IDC_BUT_MOLD24, &MoldSelectDlg::OnBnClickedButMold24)
	ON_BN_CLICKED(IDC_BUT_MOLD25, &MoldSelectDlg::OnBnClickedButMold25)
	ON_BN_CLICKED(IDC_BUT_MOLD26, &MoldSelectDlg::OnBnClickedButMold26)
	ON_BN_CLICKED(IDC_BUT_MOLD27, &MoldSelectDlg::OnBnClickedButMold27)
	ON_BN_CLICKED(IDC_BUT_MOLD28, &MoldSelectDlg::OnBnClickedButMold28)
	ON_BN_CLICKED(IDC_BUT_MOLD29, &MoldSelectDlg::OnBnClickedButMold29)
	ON_BN_CLICKED(IDC_BUT_MOLD30, &MoldSelectDlg::OnBnClickedButMold30)
	ON_BN_CLICKED(IDC_BUT_MOLD31, &MoldSelectDlg::OnBnClickedButMold31)
	ON_BN_CLICKED(IDC_BUT_MOLD32, &MoldSelectDlg::OnBnClickedButMold32)
	ON_BN_CLICKED(IDC_BUT_MOLD33, &MoldSelectDlg::OnBnClickedButMold33)
	ON_BN_CLICKED(IDC_BUT_MOLD34, &MoldSelectDlg::OnBnClickedButMold34)
	ON_BN_CLICKED(IDC_BUT_MOLD35, &MoldSelectDlg::OnBnClickedButMold35)
	ON_BN_CLICKED(IDC_BUT_MOLD36, &MoldSelectDlg::OnBnClickedButMold36)
	ON_BN_CLICKED(IDC_BUT_MOLD37, &MoldSelectDlg::OnBnClickedButMold37)
	ON_BN_CLICKED(IDC_BUT_MOLD38, &MoldSelectDlg::OnBnClickedButMold38)
	ON_BN_CLICKED(IDC_BUT_MOLD39, &MoldSelectDlg::OnBnClickedButMold39)
	ON_BN_CLICKED(IDC_BUT_MOLD40, &MoldSelectDlg::OnBnClickedButMold40)
	ON_BN_CLICKED(IDC_BUT_MOLD41, &MoldSelectDlg::OnBnClickedButMold41)
	ON_BN_CLICKED(IDC_BUT_MOLD42, &MoldSelectDlg::OnBnClickedButMold42)
	ON_BN_CLICKED(IDC_BUT_MOLD43, &MoldSelectDlg::OnBnClickedButMold43)
	ON_BN_CLICKED(IDC_BUT_MOLD44, &MoldSelectDlg::OnBnClickedButMold44)
	ON_BN_CLICKED(IDC_BUT_MOLD45, &MoldSelectDlg::OnBnClickedButMold45)
	ON_BN_CLICKED(IDC_BUT_MOLD46, &MoldSelectDlg::OnBnClickedButMold46)
	ON_BN_CLICKED(IDC_BUT_MOLD47, &MoldSelectDlg::OnBnClickedButMold47)
	ON_BN_CLICKED(IDC_BUT_MOLD48, &MoldSelectDlg::OnBnClickedButMold48)
	ON_BN_CLICKED(IDC_BUT_MOLD49, &MoldSelectDlg::OnBnClickedButMold49)
	ON_BN_CLICKED(IDC_BUT_MOLD50, &MoldSelectDlg::OnBnClickedButMold50)
	ON_BN_CLICKED(IDC_BUT_MOLD51, &MoldSelectDlg::OnBnClickedButMold51)
	ON_BN_CLICKED(IDC_BUT_MOLD52, &MoldSelectDlg::OnBnClickedButMold52)
	ON_BN_CLICKED(IDC_BUT_MOLD53, &MoldSelectDlg::OnBnClickedButMold53)
	ON_BN_CLICKED(IDC_BUT_MOLD54, &MoldSelectDlg::OnBnClickedButMold54)
	ON_BN_CLICKED(IDC_BUT_MOLD55, &MoldSelectDlg::OnBnClickedButMold55)
	ON_BN_CLICKED(IDC_BUT_MOLD56, &MoldSelectDlg::OnBnClickedButMold56)
	ON_BN_CLICKED(IDC_BUT_MOLD57, &MoldSelectDlg::OnBnClickedButMold57)
	ON_BN_CLICKED(IDC_BUT_MOLD58, &MoldSelectDlg::OnBnClickedButMold58)
	ON_BN_CLICKED(IDC_BUT_MOLD59, &MoldSelectDlg::OnBnClickedButMold59)
	ON_BN_CLICKED(IDC_BUT_MOLD60, &MoldSelectDlg::OnBnClickedButMold60)
	ON_BN_CLICKED(IDC_BUT_MOLD61, &MoldSelectDlg::OnBnClickedButMold61)
	ON_BN_CLICKED(IDC_BUT_MOLD62, &MoldSelectDlg::OnBnClickedButMold62)
	ON_BN_CLICKED(IDC_BUT_MOLD63, &MoldSelectDlg::OnBnClickedButMold63)
	ON_BN_CLICKED(IDC_BUT_MOLD64, &MoldSelectDlg::OnBnClickedButMold64)
	ON_BN_CLICKED(IDC_BUT_MOLD65, &MoldSelectDlg::OnBnClickedButMold65)
	ON_BN_CLICKED(IDC_BUT_MOLD66, &MoldSelectDlg::OnBnClickedButMold66)
	ON_BN_CLICKED(IDC_BUT_MOLD67, &MoldSelectDlg::OnBnClickedButMold67)
	ON_BN_CLICKED(IDC_BUT_MOLD68, &MoldSelectDlg::OnBnClickedButMold68)
	ON_BN_CLICKED(IDC_BUT_MOLD69, &MoldSelectDlg::OnBnClickedButMold69)
	ON_BN_CLICKED(IDC_BUT_MOLD70, &MoldSelectDlg::OnBnClickedButMold70)
	ON_BN_CLICKED(IDC_BUT_MOLD71, &MoldSelectDlg::OnBnClickedButMold71)
	ON_BN_CLICKED(IDC_BUT_MOLD72, &MoldSelectDlg::OnBnClickedButMold72)
	ON_BN_CLICKED(IDC_BUT_MOLD73, &MoldSelectDlg::OnBnClickedButMold73)
	ON_BN_CLICKED(IDC_BUT_MOLD74, &MoldSelectDlg::OnBnClickedButMold74)
	ON_BN_CLICKED(IDC_BUT_MOLD75, &MoldSelectDlg::OnBnClickedButMold75)
	ON_BN_CLICKED(IDC_BUT_MOLD76, &MoldSelectDlg::OnBnClickedButMold76)
	ON_BN_CLICKED(IDC_BUT_MOLD77, &MoldSelectDlg::OnBnClickedButMold77)
	ON_BN_CLICKED(IDC_BUT_MOLD78, &MoldSelectDlg::OnBnClickedButMold78)
	ON_BN_CLICKED(IDC_BUT_MOLD79, &MoldSelectDlg::OnBnClickedButMold79)
	ON_BN_CLICKED(IDC_BUT_MOLD80, &MoldSelectDlg::OnBnClickedButMold80)
	ON_BN_CLICKED(IDC_BUT_MOLD81, &MoldSelectDlg::OnBnClickedButMold81)
	ON_BN_CLICKED(IDC_BUT_MOLD82, &MoldSelectDlg::OnBnClickedButMold82)
	ON_BN_CLICKED(IDC_BUT_MOLD83, &MoldSelectDlg::OnBnClickedButMold83)
	ON_BN_CLICKED(IDC_BUT_MOLD84, &MoldSelectDlg::OnBnClickedButMold84)
	ON_BN_CLICKED(IDC_BUT_MOLD85, &MoldSelectDlg::OnBnClickedButMold85)
	ON_BN_CLICKED(IDC_BUT_MOLD86, &MoldSelectDlg::OnBnClickedButMold86)
	ON_BN_CLICKED(IDC_BUT_MOLD87, &MoldSelectDlg::OnBnClickedButMold87)
	ON_BN_CLICKED(IDC_BUT_MOLD88, &MoldSelectDlg::OnBnClickedButMold88)
	ON_BN_CLICKED(IDC_BUT_MOLD89, &MoldSelectDlg::OnBnClickedButMold89)
	ON_BN_CLICKED(IDC_BUT_MOLD90, &MoldSelectDlg::OnBnClickedButMold90)
	ON_BN_CLICKED(IDC_BUT_MOLD0, &MoldSelectDlg::OnBnClickedButMold0)
END_MESSAGE_MAP()


// MoldSelectDlg 消息处理程序


CString MoldSelectDlg::GetArrayFromCstringBySep(const CString& str, const TCHAR cSep)
{
	CString CurrStr = str;
	std::vector<CString> DataList;
	int CurrPos;
	CString res;
	while ((CurrPos = CurrStr.Find(cSep)) != -1)
	{
		res = res + CurrStr.Left(CurrPos) + TEXT("\\");
		DataList.push_back(CurrStr.Left(CurrPos));
		CurrStr = CurrStr.Right(CurrStr.GetLength() - CurrPos - 1);
	}
	if (!str.IsEmpty())
	{
		DataList.push_back(str.Left(CurrPos));
	}
	res - DataList[DataList.size() - 1];
	res = res + TEXT("Profile.txt");


	return res;
}

vector<int> MoldSelectDlg::Str2Vec(string str)
{
	//string s = CT2A(CS.GetString()); 
	int start = 0;
	int num = 0;
	vector<int> nums;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			string temp = str.substr(start, i - start);
			nums.push_back(atoi(temp.c_str()));
			num++;
			start = i + 1;
		}
	}
	string temp = str.substr(start, str.size() - start + 1);
	nums.push_back(atoi(temp.c_str()));
	return nums;
}

void MoldSelectDlg::SetButtonColor(CButtonST* butPtr, COLORREF rgbOut, COLORREF rgbFcous, COLORREF rgbIn)
{
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_OUT, rgbOut);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, rgbFcous);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_IN, rgbIn);
}

void MoldSelectDlg::SetButtonColor(CButtonST* butPtr, COLORREF color)
{
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_OUT, color);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, color);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_IN, color);
}

void MoldSelectDlg::InitWindowFront()
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

	GetDlgItem(IDC_MOLD_SELECT_BOX)->SetFont(m_font);
	GetDlgItem(IDC_MOLD_DO_BOX)->SetFont(m_font);
	GetDlgItem(IDC_STATIC_SELECT_DONE)->SetFont(m_font);
	GetDlgItem(IDC_STATIC_SELECT_MOLD_MODEL)->SetFont(m_font);
	GetDlgItem(IDC_STATIC_SHOW_MOLD_SELECTED)->SetFont(m_font);
	GetDlgItem(IDC_BUT_LOAD_MOLD_MODEL)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SELECT_SAVE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SELECT_EXIT)->SetFont(m_font);
}

void MoldSelectDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}

HBRUSH MoldSelectDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void MoldSelectDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}

BOOL MoldSelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	InitMoldBtnState();
	SetMoldBtnState();
	if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON")
	{
		((CButton*)GetDlgItem(IDC_CHECK_MOLDRECOGNIZE))->SetCheck(TRUE);
	}
	else if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDOFF") {
		((CButton*)GetDlgItem(IDC_CHECK_MOLDRECOGNIZE))->SetCheck(FALSE);
	}
	ShowSelectedMold();//显示

	Moldmodel_path = (m_pData->GetBottleDetParam()->MoldModel_Path).c_str();
	MoldProfile_path = (m_pData->GetBottleDetParam()->MoldProfile_Path).c_str();
	SetDlgItemText(IDC_MOLD_PARAM_FILE_BOX, MoldProfile_path);

	m_font = new CFont();
	InitWindowFront();//初始化字体
	//else {
	//	SetDlgItemText(IDC_STATIC_SHOW_MOLD_SELECTED, TEXT("34235\n"));
	//}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void MoldSelectDlg::OnBnClickedButSelectExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void MoldSelectDlg::OnBnClickedButSelectSave()
{
	// TODO: 在此添加控件通知处理程序代码
	OnMold = ((CButton*)GetDlgItem(IDC_CHECK_MOLDRECOGNIZE))->GetCheck();
	if (OnMold) {
		m_pData->SetMoldRecognition(TEXT("MOLDON"));
	}
	else {
		m_pData->SetMoldRecognition(TEXT("MOLDOFF"));
	}
	ShowSelectedMold();//显示

	//m_pData->LoadBottleParam();//
	//m_pData->LoadBottleDetParam();
	m_pData->SetSelectedMold(mold_str);//上传至xml
	m_pData->SetMoldModel_Path(Moldmodel_path);
	m_pData->SetMoldProfile_Path(MoldProfile_path);
	//CDialogEx::OnCancel();
}

void MoldSelectDlg::OnBnClickedButLoadMoldModel()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("param files(*.txt)|*.jpg|Worksheet Files|*.xls|All Files(*.*)|*.*||"),
		NULL);                            // 构造文件打开对话框  
	dlg.m_ofn.lpstrTitle = _T("添加模号模型文件");  // 文件打开对话框标题  
	if (IDOK != dlg.DoModal())                 // 判断是否成功选中文件  
		return;
	MoldProfile_path = dlg.GetPathName();         // 获取文件路径
	//SetDlgItemText(IDC_PARAM_FILE_BOX, Profile_path);
	Moldmodel_path = GetArrayFromCstringBySep(MoldProfile_path, '\\');
	SetDlgItemText(IDC_PARAM_FILE_BOX, MoldProfile_path);
}

void MoldSelectDlg::ShowSelectedMold()
{
	if (Selected.empty()) {
		SetDlgItemText(IDC_STATIC_SHOW_MOLD_SELECTED, TEXT("null"));
	}
	else {
		sort(Selected.begin(), Selected.end());
		//string str;
		//str.assign(Selected.begin(), Selected.end());
		//stringstream ss;
		//copy(Selected.begin(), Selected.end(), ostream_iterator<int>(ss, ""));
		//str = ss.str();
		string strData;
		for (int data : Selected) {
			strData += std::to_string(data) + ",";
		}
		strData = strData.substr(0, strData.size() - 1);
		int str_leng = sizeof(strData);

		mold_str = CA2T(strData.c_str());
		if (!((CButton*)GetDlgItem(IDC_CHECK_MOLDRECOGNIZE))->GetCheck()) {
			SetDlgItemText(IDC_STATIC_SHOW_MOLD_SELECTED, TEXT("未启用模号识别，不显示已选择模号。"));
			//SetDlgItemText(IDC_STATIC_SHOW_MOLD_SELECTED, mold_str);
		}
		else {
			//CWnd* pTextControl = GetDlgItem(IDC_STATIC_SHOW_MOLD_SELECTED);
			//if (pTextControl != nullptr && pTextControl->GetSafeHwnd() != nullptr)
			//{
			//	DWORD dwStyle = pTextControl->GetStyle();
			//	dwStyle |= ES_MULTILINE;      // 设置为多行文本控件
			//	//dwStyle |= ES_AUTOVSCROLL;    // 启用垂直自动滚动
			//	//dwStyle |= WS_VSCROLL;        // 显示垂直滚动条
			//	pTextControl->ModifyStyle(0, dwStyle);
			//	pTextControl->SetWindowText(mold_str);
			//}

			SetDlgItemText(IDC_STATIC_SHOW_MOLD_SELECTED, mold_str);
			//SetDlgItemText(IDC_STATIC_SHOW_MOLD_SELECTED, TEXT("未启用模号识别"));
		}
	}
}

void MoldSelectDlg::SetMoldBtnState()
{
	string moldstate = m_pData->GetBottleDetParam()->SelectedMold;
	vector<int> Moldstate;
	if (moldstate == "0") {
		Moldstate = vector<int>();
		Selected = Moldstate;
	}
	else {
		Moldstate = Str2Vec(moldstate);
		Selected = Str2Vec(moldstate);
	}
	if (find(Moldstate.begin(), Moldstate.end(), 0) != Moldstate.end()) {
		Mold_state0 = true;
		SetButtonColor(&m_Mold0, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD0, TEXT("0号已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 1) != Moldstate.end()) {
		Mold_state1 = true;
		SetButtonColor(&m_Mold1, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD1, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 2) != Moldstate.end()) {
		Mold_state2 = true;
		SetButtonColor(&m_Mold2, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD2, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 3) != Moldstate.end()) {
		Mold_state3 = true;
		SetButtonColor(&m_Mold3, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD3, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 4) != Moldstate.end()) {
		Mold_state4 = true;
		SetButtonColor(&m_Mold4, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD4, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 5) != Moldstate.end()) {
		Mold_state5 = true;
		SetButtonColor(&m_Mold5, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD5, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 6) != Moldstate.end()) {
		Mold_state6 = true;
		SetButtonColor(&m_Mold6, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD6, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 7) != Moldstate.end()) {
		Mold_state7 = true;
		SetButtonColor(&m_Mold7, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD7, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 8) != Moldstate.end()) {
		Mold_state8 = true;
		SetButtonColor(&m_Mold8, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD8, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 9) != Moldstate.end()) {
		Mold_state9 = true;
		SetButtonColor(&m_Mold9, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD9, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 10) != Moldstate.end()) {
		Mold_state10 = true;
		SetButtonColor(&m_Mold10, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD10, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 11) != Moldstate.end()) {
		Mold_state11 = true;
		SetButtonColor(&m_Mold11, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD11, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 12) != Moldstate.end()) {
		Mold_state12 = true;
		SetButtonColor(&m_Mold12, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD12, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 13) != Moldstate.end()) {
		Mold_state13 = true;
		SetButtonColor(&m_Mold13, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD13, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 14) != Moldstate.end()) {
		Mold_state14 = true;
		SetButtonColor(&m_Mold14, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD14, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 15) != Moldstate.end()) {
		Mold_state15 = true;
		SetButtonColor(&m_Mold15, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD15, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 16) != Moldstate.end()) {
		Mold_state16 = true;
		SetButtonColor(&m_Mold16, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD16, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 17) != Moldstate.end()) {
		Mold_state17 = true;
		SetButtonColor(&m_Mold17, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD17, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 18) != Moldstate.end()) {
		Mold_state18 = true;
		SetButtonColor(&m_Mold18, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD18, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 19) != Moldstate.end()) {
		Mold_state19 = true;
		SetButtonColor(&m_Mold19, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD19, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 20) != Moldstate.end()) {
		Mold_state20 = true;
		SetButtonColor(&m_Mold20, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD20, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 21) != Moldstate.end()) {
		Mold_state21 = true;
		SetButtonColor(&m_Mold21, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD21, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 22) != Moldstate.end()) {
		Mold_state22 = true;
		SetButtonColor(&m_Mold22, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD22, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 23) != Moldstate.end()) {
		Mold_state23 = true;
		SetButtonColor(&m_Mold23, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD23, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 24) != Moldstate.end()) {
		Mold_state24 = true;
		SetButtonColor(&m_Mold24, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD24, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 25) != Moldstate.end()) {
		Mold_state25 = true;
		SetButtonColor(&m_Mold25, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD25, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 26) != Moldstate.end()) {
		Mold_state26 = true;
		SetButtonColor(&m_Mold26, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD26, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 27) != Moldstate.end()) {
		Mold_state27 = true;
		SetButtonColor(&m_Mold27, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD27, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 28) != Moldstate.end()) {
		Mold_state28 = true;
		SetButtonColor(&m_Mold28, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD28, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 29) != Moldstate.end()) {
		Mold_state29 = true;
		SetButtonColor(&m_Mold29, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD29, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 30) != Moldstate.end()) {
		Mold_state30 = true;
		SetButtonColor(&m_Mold30, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD30, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 31) != Moldstate.end()) {
		Mold_state31 = true;
		SetButtonColor(&m_Mold31, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD31, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 32) != Moldstate.end()) {
		Mold_state32 = true;
		SetButtonColor(&m_Mold32, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD32, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 33) != Moldstate.end()) {
		Mold_state33 = true;
		SetButtonColor(&m_Mold33, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD33, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 34) != Moldstate.end()) {
		Mold_state34 = true;
		SetButtonColor(&m_Mold34, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD34, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 35) != Moldstate.end()) {
		Mold_state35 = true;
		SetButtonColor(&m_Mold35, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD35, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 36) != Moldstate.end()) {
		Mold_state36 = true;
		SetButtonColor(&m_Mold36, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD36, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 37) != Moldstate.end()) {
		Mold_state37 = true;
		SetButtonColor(&m_Mold37, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD37, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 38) != Moldstate.end()) {
		Mold_state38 = true;
		SetButtonColor(&m_Mold38, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD38, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 39) != Moldstate.end()) {
		Mold_state39 = true;
		SetButtonColor(&m_Mold39, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD39, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 40) != Moldstate.end()) {
		Mold_state40 = true;
		SetButtonColor(&m_Mold40, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD40, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 41) != Moldstate.end()) {
		Mold_state41 = true;
		SetButtonColor(&m_Mold41, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD41, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 42) != Moldstate.end()) {
		Mold_state42 = true;
		SetButtonColor(&m_Mold42, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD42, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 43) != Moldstate.end()) {
		Mold_state43 = true;
		SetButtonColor(&m_Mold43, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD43, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 44) != Moldstate.end()) {
		Mold_state44 = true;
		SetButtonColor(&m_Mold44, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD44, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 45) != Moldstate.end()) {
		Mold_state45 = true;
		SetButtonColor(&m_Mold45, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD45, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 46) != Moldstate.end()) {
		Mold_state46 = true;
		SetButtonColor(&m_Mold46, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD46, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 47) != Moldstate.end()) {
		Mold_state47 = true;
		SetButtonColor(&m_Mold47, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD47, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 48) != Moldstate.end()) {
		Mold_state48 = true;
		SetButtonColor(&m_Mold48, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD48, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 49) != Moldstate.end()) {
		Mold_state49 = true;
		SetButtonColor(&m_Mold49, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD49, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 50) != Moldstate.end()) {
		Mold_state50 = true;
		SetButtonColor(&m_Mold50, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD50, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 51) != Moldstate.end()) {
		Mold_state51 = true;
		SetButtonColor(&m_Mold51, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD51, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 52) != Moldstate.end()) {
		Mold_state52 = true;
		SetButtonColor(&m_Mold52, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD52, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 53) != Moldstate.end()) {
		Mold_state53 = true;
		SetButtonColor(&m_Mold53, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD53, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 54) != Moldstate.end()) {
		Mold_state54 = true;
		SetButtonColor(&m_Mold54, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD54, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 55) != Moldstate.end()) {
		Mold_state55 = true;
		SetButtonColor(&m_Mold55, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD55, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 56) != Moldstate.end()) {
		Mold_state56 = true;
		SetButtonColor(&m_Mold56, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD56, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 57) != Moldstate.end()) {
		Mold_state57 = true;
		SetButtonColor(&m_Mold57, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD57, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 58) != Moldstate.end()) {
		Mold_state58 = true;
		SetButtonColor(&m_Mold58, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD58, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 59) != Moldstate.end()) {
		Mold_state59 = true;
		SetButtonColor(&m_Mold59, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD59, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 60) != Moldstate.end()) {
		Mold_state60 = true;
		SetButtonColor(&m_Mold60, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD60, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 61) != Moldstate.end()) {
		Mold_state61 = true;
		SetButtonColor(&m_Mold61, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD61, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 62) != Moldstate.end()) {
		Mold_state62 = true;
		SetButtonColor(&m_Mold62, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD62, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 63) != Moldstate.end()) {
		Mold_state63 = true;
		SetButtonColor(&m_Mold63, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD63, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 64) != Moldstate.end()) {
		Mold_state64 = true;
		SetButtonColor(&m_Mold64, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD64, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 65) != Moldstate.end()) {
		Mold_state65 = true;
		SetButtonColor(&m_Mold65, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD65, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 66) != Moldstate.end()) {
		Mold_state66 = true;
		SetButtonColor(&m_Mold66, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD66, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 67) != Moldstate.end()) {
		Mold_state67 = true;
		SetButtonColor(&m_Mold67, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD67, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 68) != Moldstate.end()) {
		Mold_state68 = true;
		SetButtonColor(&m_Mold68, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD68, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 69) != Moldstate.end()) {
		Mold_state69 = true;
		SetButtonColor(&m_Mold69, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD69, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 70) != Moldstate.end()) {
		Mold_state70 = true;
		SetButtonColor(&m_Mold70, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD70, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 71) != Moldstate.end()) {
		Mold_state71 = true;
		SetButtonColor(&m_Mold71, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD71, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 72) != Moldstate.end()) {
		Mold_state72 = true;
		SetButtonColor(&m_Mold72, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD72, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 73) != Moldstate.end()) {
		Mold_state73 = true;
		SetButtonColor(&m_Mold73, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD73, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 74) != Moldstate.end()) {
		Mold_state74 = true;
		SetButtonColor(&m_Mold74, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD74, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 75) != Moldstate.end()) {
		Mold_state75 = true;
		SetButtonColor(&m_Mold75, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD75, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 76) != Moldstate.end()) {
		Mold_state76 = true;
		SetButtonColor(&m_Mold76, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD76, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 77) != Moldstate.end()) {
		Mold_state77 = true;
		SetButtonColor(&m_Mold77, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD77, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 78) != Moldstate.end()) {
		Mold_state78 = true;
		SetButtonColor(&m_Mold78, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD78, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 79) != Moldstate.end()) {
		Mold_state79 = true;
		SetButtonColor(&m_Mold79, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD79, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 80) != Moldstate.end()) {
		Mold_state80 = true;
		SetButtonColor(&m_Mold80, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD80, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 81) != Moldstate.end()) {
		Mold_state81 = true;
		SetButtonColor(&m_Mold81, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD81, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 82) != Moldstate.end()) {
		Mold_state82 = true;
		SetButtonColor(&m_Mold82, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD82, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 83) != Moldstate.end()) {
		Mold_state83 = true;
		SetButtonColor(&m_Mold83, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD83, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 84) != Moldstate.end()) {
		Mold_state84 = true;
		SetButtonColor(&m_Mold84, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD84, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 85) != Moldstate.end()) {
		Mold_state85 = true;
		SetButtonColor(&m_Mold85, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD85, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 86) != Moldstate.end()) {
		Mold_state86 = true;
		SetButtonColor(&m_Mold86, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD86, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 87) != Moldstate.end()) {
		Mold_state87 = true;
		SetButtonColor(&m_Mold87, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD87, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 88) != Moldstate.end()) {
		Mold_state88 = true;
		SetButtonColor(&m_Mold88, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD88, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 89) != Moldstate.end()) {
		Mold_state89 = true;
		SetButtonColor(&m_Mold89, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD89, TEXT("已选"));
	}
	if (find(Moldstate.begin(), Moldstate.end(), 90) != Moldstate.end()) {
		Mold_state90 = true;
		SetButtonColor(&m_Mold90, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD90, TEXT("已选"));
	}
}

void MoldSelectDlg::InitMoldBtnState()
{
	SetButtonColor(&m_Mold1, RGB(218, 218, 218));
	SetButtonColor(&m_Mold2, RGB(218, 218, 218));
	SetButtonColor(&m_Mold3, RGB(218, 218, 218));
	SetButtonColor(&m_Mold4, RGB(218, 218, 218));
	SetButtonColor(&m_Mold5, RGB(218, 218, 218));
	SetButtonColor(&m_Mold6, RGB(218, 218, 218));
	SetButtonColor(&m_Mold7, RGB(218, 218, 218));
	SetButtonColor(&m_Mold8, RGB(218, 218, 218));
	SetButtonColor(&m_Mold9, RGB(218, 218, 218));
	SetButtonColor(&m_Mold10, RGB(218, 218, 218));
	SetButtonColor(&m_Mold11, RGB(218, 218, 218));
	SetButtonColor(&m_Mold12, RGB(218, 218, 218));
	SetButtonColor(&m_Mold13, RGB(218, 218, 218));
	SetButtonColor(&m_Mold14, RGB(218, 218, 218));
	SetButtonColor(&m_Mold15, RGB(218, 218, 218));
	SetButtonColor(&m_Mold16, RGB(218, 218, 218));
	SetButtonColor(&m_Mold17, RGB(218, 218, 218));
	SetButtonColor(&m_Mold18, RGB(218, 218, 218));
	SetButtonColor(&m_Mold19, RGB(218, 218, 218));
	SetButtonColor(&m_Mold20, RGB(218, 218, 218));
	SetButtonColor(&m_Mold21, RGB(218, 218, 218));
	SetButtonColor(&m_Mold22, RGB(218, 218, 218));
	SetButtonColor(&m_Mold23, RGB(218, 218, 218));
	SetButtonColor(&m_Mold24, RGB(218, 218, 218));
	SetButtonColor(&m_Mold25, RGB(218, 218, 218));
	SetButtonColor(&m_Mold26, RGB(218, 218, 218));
	SetButtonColor(&m_Mold27, RGB(218, 218, 218));
	SetButtonColor(&m_Mold28, RGB(218, 218, 218));
	SetButtonColor(&m_Mold29, RGB(218, 218, 218));
	SetButtonColor(&m_Mold30, RGB(218, 218, 218));
	SetButtonColor(&m_Mold31, RGB(218, 218, 218));
	SetButtonColor(&m_Mold32, RGB(218, 218, 218));
	SetButtonColor(&m_Mold33, RGB(218, 218, 218));
	SetButtonColor(&m_Mold34, RGB(218, 218, 218));
	SetButtonColor(&m_Mold35, RGB(218, 218, 218));
	SetButtonColor(&m_Mold36, RGB(218, 218, 218));
	SetButtonColor(&m_Mold37, RGB(218, 218, 218));
	SetButtonColor(&m_Mold38, RGB(218, 218, 218));
	SetButtonColor(&m_Mold39, RGB(218, 218, 218));
	SetButtonColor(&m_Mold40, RGB(218, 218, 218));
	SetButtonColor(&m_Mold41, RGB(218, 218, 218));
	SetButtonColor(&m_Mold42, RGB(218, 218, 218));
	SetButtonColor(&m_Mold43, RGB(218, 218, 218));
	SetButtonColor(&m_Mold44, RGB(218, 218, 218));
	SetButtonColor(&m_Mold45, RGB(218, 218, 218));
	SetButtonColor(&m_Mold46, RGB(218, 218, 218));
	SetButtonColor(&m_Mold47, RGB(218, 218, 218));
	SetButtonColor(&m_Mold48, RGB(218, 218, 218));
	SetButtonColor(&m_Mold49, RGB(218, 218, 218));
	SetButtonColor(&m_Mold50, RGB(218, 218, 218));
	SetButtonColor(&m_Mold51, RGB(218, 218, 218));
	SetButtonColor(&m_Mold52, RGB(218, 218, 218));
	SetButtonColor(&m_Mold53, RGB(218, 218, 218));
	SetButtonColor(&m_Mold54, RGB(218, 218, 218));
	SetButtonColor(&m_Mold55, RGB(218, 218, 218));
	SetButtonColor(&m_Mold56, RGB(218, 218, 218));
	SetButtonColor(&m_Mold57, RGB(218, 218, 218));
	SetButtonColor(&m_Mold58, RGB(218, 218, 218));
	SetButtonColor(&m_Mold59, RGB(218, 218, 218));
	SetButtonColor(&m_Mold60, RGB(218, 218, 218));
	SetButtonColor(&m_Mold61, RGB(218, 218, 218));
	SetButtonColor(&m_Mold62, RGB(218, 218, 218));
	SetButtonColor(&m_Mold63, RGB(218, 218, 218));
	SetButtonColor(&m_Mold64, RGB(218, 218, 218));
	SetButtonColor(&m_Mold65, RGB(218, 218, 218));
	SetButtonColor(&m_Mold66, RGB(218, 218, 218));
	SetButtonColor(&m_Mold67, RGB(218, 218, 218));
	SetButtonColor(&m_Mold68, RGB(218, 218, 218));
	SetButtonColor(&m_Mold69, RGB(218, 218, 218));
	SetButtonColor(&m_Mold70, RGB(218, 218, 218));
	SetButtonColor(&m_Mold71, RGB(218, 218, 218));
	SetButtonColor(&m_Mold72, RGB(218, 218, 218));
	SetButtonColor(&m_Mold73, RGB(218, 218, 218));
	SetButtonColor(&m_Mold74, RGB(218, 218, 218));
	SetButtonColor(&m_Mold75, RGB(218, 218, 218));
	SetButtonColor(&m_Mold76, RGB(218, 218, 218));
	SetButtonColor(&m_Mold77, RGB(218, 218, 218));
	SetButtonColor(&m_Mold78, RGB(218, 218, 218));
	SetButtonColor(&m_Mold79, RGB(218, 218, 218));
	SetButtonColor(&m_Mold80, RGB(218, 218, 218));
	SetButtonColor(&m_Mold81, RGB(218, 218, 218));
	SetButtonColor(&m_Mold82, RGB(218, 218, 218));
	SetButtonColor(&m_Mold83, RGB(218, 218, 218));
	SetButtonColor(&m_Mold84, RGB(218, 218, 218));
	SetButtonColor(&m_Mold85, RGB(218, 218, 218));
	SetButtonColor(&m_Mold86, RGB(218, 218, 218));
	SetButtonColor(&m_Mold87, RGB(218, 218, 218));
	SetButtonColor(&m_Mold88, RGB(218, 218, 218));
	SetButtonColor(&m_Mold89, RGB(218, 218, 218));
	SetButtonColor(&m_Mold90, RGB(218, 218, 218));
	SetButtonColor(&m_Mold0, RGB(218, 218, 218));

}

void MoldSelectDlg::OnBnClickedButMold1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state1) {
		//Selected.erase(Selected.begin());
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 1);
		Selected.erase(no);
		SetButtonColor(&m_Mold1, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD1, TEXT("1"));
		Mold_state1 = !Mold_state1;
	}
	else {
		Selected.insert(Selected.begin(), 1);
		SetButtonColor(&m_Mold1, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD1, TEXT("已选"));
		Mold_state1 = !Mold_state1;
	}
}

void MoldSelectDlg::OnBnClickedButMold2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state2) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 2);
		Selected.erase(no);
		SetButtonColor(&m_Mold2, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD2, TEXT("2"));
		Mold_state2 = !Mold_state2;
	}
	else {
		Selected.push_back(2);
		SetButtonColor(&m_Mold2, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD2, TEXT("已选"));
		Mold_state2 = !Mold_state2;
	}
}

void MoldSelectDlg::OnBnClickedButMold3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state3) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 3);
		Selected.erase(no);
		SetButtonColor(&m_Mold3, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD3, TEXT("3"));
		Mold_state3 = !Mold_state3;
	}
	else {
		Selected.push_back(3);
		SetButtonColor(&m_Mold3, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD3, TEXT("已选"));
		Mold_state3 = !Mold_state3;
	}
}

void MoldSelectDlg::OnBnClickedButMold4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state4) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 4);
		Selected.erase(no);
		SetButtonColor(&m_Mold4, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD4, TEXT("4"));
		Mold_state4 = !Mold_state4;
	}
	else {
		Selected.push_back(4);
		SetButtonColor(&m_Mold4, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD4, TEXT("已选"));
		Mold_state4 = !Mold_state4;
	}
}

void MoldSelectDlg::OnBnClickedButMold5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state5) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 5);
		Selected.erase(no);
		SetButtonColor(&m_Mold5, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD5, TEXT("5"));
		Mold_state5 = !Mold_state5;
	}
	else {
		Selected.push_back(5);
		SetButtonColor(&m_Mold5, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD5, TEXT("已选"));
		Mold_state5 = !Mold_state5;
	}
}

void MoldSelectDlg::OnBnClickedButMold6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state6) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 6);
		Selected.erase(no);
		SetButtonColor(&m_Mold6, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD6, TEXT("6"));
		Mold_state6 = !Mold_state6;
	}
	else {
		Selected.push_back(6);
		SetButtonColor(&m_Mold6, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD6, TEXT("已选"));
		Mold_state6 = !Mold_state6;
	}
}

void MoldSelectDlg::OnBnClickedButMold7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state7) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 7);
		Selected.erase(no);
		SetButtonColor(&m_Mold7, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD7, TEXT("7"));
		Mold_state7 = !Mold_state7;
	}
	else {
		Selected.push_back(7);
		SetButtonColor(&m_Mold7, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD7, TEXT("已选"));
		Mold_state7 = !Mold_state7;
	}
}

void MoldSelectDlg::OnBnClickedButMold8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state8) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 8);
		Selected.erase(no);
		SetButtonColor(&m_Mold8, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD8, TEXT("8"));
		Mold_state8 = !Mold_state8;
	}
	else {
		Selected.push_back(8);
		SetButtonColor(&m_Mold8, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD8, TEXT("已选"));
		Mold_state8 = !Mold_state8;
	}
}

void MoldSelectDlg::OnBnClickedButMold9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state9) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 9);
		Selected.erase(no);
		SetButtonColor(&m_Mold9, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD9, TEXT("9"));
		Mold_state9 = !Mold_state9;
	}
	else {
		Selected.push_back(9);
		SetButtonColor(&m_Mold9, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD9, TEXT("已选"));
		Mold_state9 = !Mold_state9;
	}
}

void MoldSelectDlg::OnBnClickedButMold10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state10) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 10);
		Selected.erase(no);
		SetButtonColor(&m_Mold10, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD10, TEXT("10"));
		Mold_state10 = !Mold_state10;
	}
	else {
		Selected.push_back(10);
		SetButtonColor(&m_Mold10, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD10, TEXT("已选"));
		Mold_state10 = !Mold_state10;
	}
}

void MoldSelectDlg::OnBnClickedButMold11()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state11) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 11);
		Selected.erase(no);
		SetButtonColor(&m_Mold11, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD11, TEXT("11"));
		Mold_state11 = !Mold_state11;
	}
	else {
		Selected.push_back(11);
		SetButtonColor(&m_Mold11, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD11, TEXT("已选"));
		Mold_state11 = !Mold_state11;
	}
}

void MoldSelectDlg::OnBnClickedButMold12()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state12) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 12);
		Selected.erase(no);
		SetButtonColor(&m_Mold12, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD12, TEXT("12"));
		Mold_state12 = !Mold_state12;
	}
	else {
		Selected.push_back(12);
		SetButtonColor(&m_Mold12, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD12, TEXT("已选"));
		Mold_state12 = !Mold_state12;
	}
}

void MoldSelectDlg::OnBnClickedButMold13()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state13) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 13);
		Selected.erase(no);
		SetButtonColor(&m_Mold13, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD13, TEXT("13"));
		Mold_state13 = !Mold_state13;
	}
	else {
		Selected.push_back(13);
		SetButtonColor(&m_Mold13, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD13, TEXT("已选"));
		Mold_state13 = !Mold_state13;
	}
}

void MoldSelectDlg::OnBnClickedButMold14()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state14) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 14);
		Selected.erase(no);
		SetButtonColor(&m_Mold14, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD14, TEXT("14"));
		Mold_state14 = !Mold_state14;
	}
	else {
		Selected.push_back(14);
		SetButtonColor(&m_Mold14, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD14, TEXT("已选"));
		Mold_state14 = !Mold_state14;
	}
}

void MoldSelectDlg::OnBnClickedButMold15()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state15) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 15);
		Selected.erase(no);
		SetButtonColor(&m_Mold15, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD15, TEXT("15"));
		Mold_state15 = !Mold_state15;
	}
	else {
		Selected.push_back(15);
		SetButtonColor(&m_Mold15, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD15, TEXT("已选"));
		Mold_state15 = !Mold_state15;
	}
}

void MoldSelectDlg::OnBnClickedButMold16()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state16) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 16);
		Selected.erase(no);
		SetButtonColor(&m_Mold16, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD16, TEXT("16"));
		Mold_state16 = !Mold_state16;
	}
	else {
		Selected.push_back(16);
		SetButtonColor(&m_Mold16, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD16, TEXT("已选"));
		Mold_state16 = !Mold_state16;
	}
}

void MoldSelectDlg::OnBnClickedButMold17()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state17) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 17);
		Selected.erase(no);
		SetButtonColor(&m_Mold17, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD17, TEXT("17"));
		Mold_state17 = !Mold_state17;
	}
	else {
		Selected.push_back(17);
		SetButtonColor(&m_Mold17, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD17, TEXT("已选"));
		Mold_state17 = !Mold_state17;
	}
}

void MoldSelectDlg::OnBnClickedButMold18()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state18) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 18);
		Selected.erase(no);
		SetButtonColor(&m_Mold18, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD18, TEXT("18"));
		Mold_state18 = !Mold_state18;
	}
	else {
		Selected.push_back(18);
		SetButtonColor(&m_Mold18, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD18, TEXT("已选"));
		Mold_state18 = !Mold_state18;
	}
}

void MoldSelectDlg::OnBnClickedButMold19()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state19) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 19);
		Selected.erase(no);
		SetButtonColor(&m_Mold19, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD19, TEXT("19"));
		Mold_state19 = !Mold_state19;
	}
	else {
		Selected.push_back(19);
		SetButtonColor(&m_Mold19, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD19, TEXT("已选"));
		Mold_state19 = !Mold_state19;
	}
}

void MoldSelectDlg::OnBnClickedButMold20()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state20) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 20);
		Selected.erase(no);
		SetButtonColor(&m_Mold20, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD20, TEXT("20"));
		Mold_state20 = !Mold_state20;
	}
	else {
		Selected.push_back(20);
		SetButtonColor(&m_Mold20, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD20, TEXT("已选"));
		Mold_state20 = !Mold_state20;
	}
}

void MoldSelectDlg::OnBnClickedButMold21()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state21) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 21);
		Selected.erase(no);
		SetButtonColor(&m_Mold21, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD21, TEXT("21"));
		Mold_state21 = !Mold_state21;
	}
	else {
		Selected.push_back(21);
		SetButtonColor(&m_Mold21, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD21, TEXT("已选"));
		Mold_state21 = !Mold_state21;
	}
}

void MoldSelectDlg::OnBnClickedButMold22()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state22) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 22);
		Selected.erase(no);
		SetButtonColor(&m_Mold22, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD22, TEXT("22"));
		Mold_state22 = !Mold_state22;
	}
	else {
		Selected.push_back(22);
		SetButtonColor(&m_Mold22, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD22, TEXT("已选"));
		Mold_state22 = !Mold_state22;
	}
}

void MoldSelectDlg::OnBnClickedButMold23()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state23) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 23);
		Selected.erase(no);
		SetButtonColor(&m_Mold23, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD23, TEXT("23"));
		Mold_state23 = !Mold_state23;
	}
	else {
		Selected.push_back(23);
		SetButtonColor(&m_Mold23, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD23, TEXT("已选"));
		Mold_state23 = !Mold_state23;
	}
}

void MoldSelectDlg::OnBnClickedButMold24()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state24) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 24);
		Selected.erase(no);
		SetButtonColor(&m_Mold24, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD24, TEXT("24"));
		Mold_state24 = !Mold_state24;
	}
	else {
		Selected.push_back(24);
		SetButtonColor(&m_Mold24, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD24, TEXT("已选"));
		Mold_state24 = !Mold_state24;
	}
}

void MoldSelectDlg::OnBnClickedButMold25()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state25) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 25);
		Selected.erase(no);
		SetButtonColor(&m_Mold25, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD25, TEXT("25"));
		Mold_state25 = !Mold_state25;
	}
	else {
		Selected.push_back(25);
		SetButtonColor(&m_Mold25, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD25, TEXT("已选"));
		Mold_state25 = !Mold_state25;
	}
}

void MoldSelectDlg::OnBnClickedButMold26()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state26) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 26);
		Selected.erase(no);
		SetButtonColor(&m_Mold26, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD26, TEXT("26"));
		Mold_state26 = !Mold_state26;
	}
	else {
		Selected.push_back(26);
		SetButtonColor(&m_Mold26, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD26, TEXT("已选"));
		Mold_state26 = !Mold_state26;
	}
}

void MoldSelectDlg::OnBnClickedButMold27()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state27) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 27);
		Selected.erase(no);
		SetButtonColor(&m_Mold27, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD27, TEXT("27"));
		Mold_state27 = !Mold_state27;
	}
	else {
		Selected.push_back(27);
		SetButtonColor(&m_Mold27, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD27, TEXT("已选"));
		Mold_state27 = !Mold_state27;
	}
}

void MoldSelectDlg::OnBnClickedButMold28()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state28) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 28);
		Selected.erase(no);
		SetButtonColor(&m_Mold28, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD28, TEXT("28"));
		Mold_state28 = !Mold_state28;
	}
	else {
		Selected.push_back(28);
		SetButtonColor(&m_Mold28, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD28, TEXT("已选"));
		Mold_state28 = !Mold_state28;
	}
}

void MoldSelectDlg::OnBnClickedButMold29()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state29) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 29);
		Selected.erase(no);
		SetButtonColor(&m_Mold29, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD29, TEXT("29"));
		Mold_state29 = !Mold_state29;
	}
	else {
		Selected.push_back(29);
		SetButtonColor(&m_Mold29, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD29, TEXT("已选"));
		Mold_state29 = !Mold_state29;
	}
}

void MoldSelectDlg::OnBnClickedButMold30()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state30) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 30);
		Selected.erase(no);
		SetButtonColor(&m_Mold30, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD30, TEXT("30"));
		Mold_state30 = !Mold_state30;
	}
	else {
		Selected.push_back(30);
		SetButtonColor(&m_Mold30, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD30, TEXT("已选"));
		Mold_state30 = !Mold_state30;
	}
}

void MoldSelectDlg::OnBnClickedButMold31()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state31) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 31);
		Selected.erase(no);
		SetButtonColor(&m_Mold31, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD31, TEXT("31"));
		Mold_state31 = !Mold_state31;
	}
	else {
		Selected.push_back(31);
		SetButtonColor(&m_Mold31, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD31, TEXT("已选"));
		Mold_state31 = !Mold_state31;
	}
}

void MoldSelectDlg::OnBnClickedButMold32()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state32) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 32);
		Selected.erase(no);
		SetButtonColor(&m_Mold32, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD32, TEXT("32"));
		Mold_state32 = !Mold_state32;
	}
	else {
		Selected.push_back(32);
		SetButtonColor(&m_Mold32, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD32, TEXT("已选"));
		Mold_state32 = !Mold_state32;
	}
}

void MoldSelectDlg::OnBnClickedButMold33()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state33) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 33);
		Selected.erase(no);
		SetButtonColor(&m_Mold33, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD33, TEXT("33"));
		Mold_state33 = !Mold_state33;
	}
	else {
		Selected.push_back(33);
		SetButtonColor(&m_Mold33, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD33, TEXT("已选"));
		Mold_state33 = !Mold_state33;
	}
}

void MoldSelectDlg::OnBnClickedButMold34()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state34) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 34);
		Selected.erase(no);
		SetButtonColor(&m_Mold34, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD34, TEXT("34"));
		Mold_state34 = !Mold_state34;
	}
	else {
		Selected.push_back(34);
		SetButtonColor(&m_Mold34, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD34, TEXT("已选"));
		Mold_state34 = !Mold_state34;
	}
}

void MoldSelectDlg::OnBnClickedButMold35()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state35) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 35);
		Selected.erase(no);
		SetButtonColor(&m_Mold35, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD35, TEXT("35"));
		Mold_state35 = !Mold_state35;
	}
	else {
		Selected.push_back(35);
		SetButtonColor(&m_Mold35, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD35, TEXT("已选"));
		Mold_state35 = !Mold_state35;
	}
}

void MoldSelectDlg::OnBnClickedButMold36()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state36) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 36);
		Selected.erase(no);
		SetButtonColor(&m_Mold36, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD36, TEXT("36"));
		Mold_state36 = !Mold_state36;
	}
	else {
		Selected.push_back(36);
		SetButtonColor(&m_Mold36, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD36, TEXT("已选"));
		Mold_state36 = !Mold_state36;
	}
}

void MoldSelectDlg::OnBnClickedButMold37()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state37) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 37);
		Selected.erase(no);
		SetButtonColor(&m_Mold37, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD37, TEXT("37"));
		Mold_state37 = !Mold_state37;
	}
	else {
		Selected.push_back(37);
		SetButtonColor(&m_Mold37, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD37, TEXT("已选"));
		Mold_state37 = !Mold_state37;
	}
}

void MoldSelectDlg::OnBnClickedButMold38()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state38) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 38);
		Selected.erase(no);
		SetButtonColor(&m_Mold38, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD38, TEXT("38"));
		Mold_state38 = !Mold_state38;
	}
	else {
		Selected.push_back(38);
		SetButtonColor(&m_Mold38, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD38, TEXT("已选"));
		Mold_state38 = !Mold_state38;
	}
}

void MoldSelectDlg::OnBnClickedButMold39()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state39) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 39);
		Selected.erase(no);
		SetButtonColor(&m_Mold39, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD39, TEXT("39"));
		Mold_state39 = !Mold_state39;
	}
	else {
		Selected.push_back(39);
		SetButtonColor(&m_Mold39, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD39, TEXT("已选"));
		Mold_state39 = !Mold_state39;
	}
}

void MoldSelectDlg::OnBnClickedButMold40()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state40) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 40);
		Selected.erase(no);
		SetButtonColor(&m_Mold40, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD40, TEXT("40"));
		Mold_state40 = !Mold_state40;
	}
	else {
		Selected.push_back(40);
		SetButtonColor(&m_Mold40, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD40, TEXT("已选"));
		Mold_state40 = !Mold_state40;
	}
}

void MoldSelectDlg::OnBnClickedButMold41()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state41) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 41);
		Selected.erase(no);
		SetButtonColor(&m_Mold41, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD41, TEXT("41"));
		Mold_state41 = !Mold_state41;
	}
	else {
		Selected.push_back(41);
		SetButtonColor(&m_Mold41, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD41, TEXT("已选"));
		Mold_state41 = !Mold_state41;
	}
}

void MoldSelectDlg::OnBnClickedButMold42()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state42) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 42);
		Selected.erase(no);
		SetButtonColor(&m_Mold42, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD42, TEXT("42"));
		Mold_state42 = !Mold_state42;
	}
	else {
		Selected.push_back(42);
		SetButtonColor(&m_Mold42, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD42, TEXT("已选"));
		Mold_state42 = !Mold_state42;
	}
}

void MoldSelectDlg::OnBnClickedButMold43()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state43) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 43);
		Selected.erase(no);
		SetButtonColor(&m_Mold43, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD43, TEXT("43"));
		Mold_state43 = !Mold_state43;
	}
	else {
		Selected.push_back(43);
		SetButtonColor(&m_Mold43, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD43, TEXT("已选"));
		Mold_state43 = !Mold_state43;
	}
}

void MoldSelectDlg::OnBnClickedButMold44()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state44) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 44);
		Selected.erase(no);
		SetButtonColor(&m_Mold44, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD44, TEXT("44"));
		Mold_state44 = !Mold_state44;
	}
	else {
		Selected.push_back(44);
		SetButtonColor(&m_Mold44, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD44, TEXT("已选"));
		Mold_state44 = !Mold_state44;
	}
}

void MoldSelectDlg::OnBnClickedButMold45()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state45) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 45);
		Selected.erase(no);
		SetButtonColor(&m_Mold45, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD45, TEXT("45"));
		Mold_state45 = !Mold_state45;
	}
	else {
		Selected.push_back(45);
		SetButtonColor(&m_Mold45, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD45, TEXT("已选"));
		Mold_state45 = !Mold_state45;
	}
}

void MoldSelectDlg::OnBnClickedButMold46()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state46) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 46);
		Selected.erase(no);
		SetButtonColor(&m_Mold46, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD46, TEXT("46"));
		Mold_state46 = !Mold_state46;
	}
	else {
		Selected.push_back(46);
		SetButtonColor(&m_Mold46, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD46, TEXT("已选"));
		Mold_state46 = !Mold_state46;
	}
}

void MoldSelectDlg::OnBnClickedButMold47()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state47) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 47);
		Selected.erase(no);
		SetButtonColor(&m_Mold47, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD47, TEXT("47"));
		Mold_state47 = !Mold_state47;
	}
	else {
		Selected.push_back(47);
		SetButtonColor(&m_Mold47, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD47, TEXT("已选"));
		Mold_state47 = !Mold_state47;
	}
}

void MoldSelectDlg::OnBnClickedButMold48()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state48) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 48);
		Selected.erase(no);
		SetButtonColor(&m_Mold48, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD48, TEXT("48"));
		Mold_state48 = !Mold_state48;
	}
	else {
		Selected.push_back(48);
		SetButtonColor(&m_Mold48, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD48, TEXT("已选"));
		Mold_state48 = !Mold_state48;
	}
}

void MoldSelectDlg::OnBnClickedButMold49()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state49) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 49);
		Selected.erase(no);
		SetButtonColor(&m_Mold49, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD49, TEXT("49"));
		Mold_state49 = !Mold_state49;
	}
	else {
		Selected.push_back(49);
		SetButtonColor(&m_Mold49, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD49, TEXT("已选"));
		Mold_state49 = !Mold_state49;
	}
}

void MoldSelectDlg::OnBnClickedButMold50()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state50) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 50);
		Selected.erase(no);
		SetButtonColor(&m_Mold50, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD50, TEXT("50"));
		Mold_state50 = !Mold_state50;
	}
	else {
		Selected.push_back(50);
		SetButtonColor(&m_Mold50, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD50, TEXT("已选"));
		Mold_state50 = !Mold_state50;
	}
}

void MoldSelectDlg::OnBnClickedButMold51()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state51) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 51);
		Selected.erase(no);
		SetButtonColor(&m_Mold51, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD51, TEXT("51"));
		Mold_state51 = !Mold_state51;
	}
	else {
		Selected.push_back(51);
		SetButtonColor(&m_Mold51, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD51, TEXT("已选"));
		Mold_state51 = !Mold_state51;
	}
}

void MoldSelectDlg::OnBnClickedButMold52()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state52) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 52);
		Selected.erase(no);
		SetButtonColor(&m_Mold52, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD52, TEXT("52"));
		Mold_state52 = !Mold_state52;
	}
	else {
		Selected.push_back(52);
		SetButtonColor(&m_Mold52, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD52, TEXT("已选"));
		Mold_state52 = !Mold_state52;
	}
}

void MoldSelectDlg::OnBnClickedButMold53()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state53) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 53);
		Selected.erase(no);
		SetButtonColor(&m_Mold53, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD53, TEXT("53"));
		Mold_state53 = !Mold_state53;
	}
	else {
		Selected.push_back(53);
		SetButtonColor(&m_Mold53, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD53, TEXT("已选"));
		Mold_state53 = !Mold_state53;
	}
}

void MoldSelectDlg::OnBnClickedButMold54()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state54) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 54);
		Selected.erase(no);
		SetButtonColor(&m_Mold54, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD54, TEXT("54"));
		Mold_state54 = !Mold_state54;
	}
	else {
		Selected.push_back(54);
		SetButtonColor(&m_Mold54, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD54, TEXT("已选"));
		Mold_state54 = !Mold_state54;
	}
}

void MoldSelectDlg::OnBnClickedButMold55()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state55) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 55);
		Selected.erase(no);
		SetButtonColor(&m_Mold55, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD55, TEXT("55"));
		Mold_state55 = !Mold_state55;
	}
	else {
		Selected.push_back(55);
		SetButtonColor(&m_Mold55, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD55, TEXT("已选"));
		Mold_state55 = !Mold_state55;
	}
}

void MoldSelectDlg::OnBnClickedButMold56()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state56) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 56);
		Selected.erase(no);
		SetButtonColor(&m_Mold56, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD56, TEXT("56"));
		Mold_state56 = !Mold_state56;
	}
	else {
		Selected.push_back(56);
		SetButtonColor(&m_Mold56, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD56, TEXT("已选"));
		Mold_state56 = !Mold_state56;
	}
}

void MoldSelectDlg::OnBnClickedButMold57()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state57) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 57);
		Selected.erase(no);
		SetButtonColor(&m_Mold57, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD57, TEXT("57"));
		Mold_state57 = !Mold_state57;
	}
	else {
		Selected.push_back(57);
		SetButtonColor(&m_Mold57, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD57, TEXT("已选"));
		Mold_state57 = !Mold_state57;
	}
}

void MoldSelectDlg::OnBnClickedButMold58()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state58) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 58);
		Selected.erase(no);
		SetButtonColor(&m_Mold58, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD58, TEXT("58"));
		Mold_state58 = !Mold_state58;
	}
	else {
		Selected.push_back(58);
		SetButtonColor(&m_Mold58, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD58, TEXT("已选"));
		Mold_state58 = !Mold_state58;
	}
}

void MoldSelectDlg::OnBnClickedButMold59()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state59) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 59);
		Selected.erase(no);
		SetButtonColor(&m_Mold59, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD59, TEXT("59"));
		Mold_state59 = !Mold_state59;
	}
	else {
		Selected.push_back(59);
		SetButtonColor(&m_Mold59, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD59, TEXT("已选"));
		Mold_state59 = !Mold_state59;
	}
}

void MoldSelectDlg::OnBnClickedButMold60()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state60) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 60);
		Selected.erase(no);
		SetButtonColor(&m_Mold60, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD60, TEXT("60"));
		Mold_state60 = !Mold_state60;
	}
	else {
		Selected.push_back(60);
		SetButtonColor(&m_Mold60, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD60, TEXT("已选"));
		Mold_state60 = !Mold_state60;
	}
}

void MoldSelectDlg::OnBnClickedButMold61()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state61) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 61);
		Selected.erase(no);
		SetButtonColor(&m_Mold61, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD61, TEXT("61"));
		Mold_state61 = !Mold_state61;
	}
	else {
		Selected.push_back(61);
		SetButtonColor(&m_Mold61, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD61, TEXT("已选"));
		Mold_state61 = !Mold_state61;
	}
}

void MoldSelectDlg::OnBnClickedButMold62()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state62) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 62);
		Selected.erase(no);
		SetButtonColor(&m_Mold62, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD62, TEXT("62"));
		Mold_state62 = !Mold_state62;
	}
	else {
		Selected.push_back(62);
		SetButtonColor(&m_Mold62, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD62, TEXT("已选"));
		Mold_state62 = !Mold_state62;
	}
}

void MoldSelectDlg::OnBnClickedButMold63()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state63) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 63);
		Selected.erase(no);
		SetButtonColor(&m_Mold63, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD63, TEXT("63"));
		Mold_state63 = !Mold_state63;
	}
	else {
		Selected.push_back(63);
		SetButtonColor(&m_Mold63, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD63, TEXT("已选"));
		Mold_state63 = !Mold_state63;
	}
}

void MoldSelectDlg::OnBnClickedButMold64()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state64) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 64);
		Selected.erase(no);
		SetButtonColor(&m_Mold64, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD64, TEXT("64"));
		Mold_state64 = !Mold_state64;
	}
	else {
		Selected.push_back(64);
		SetButtonColor(&m_Mold64, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD64, TEXT("已选"));
		Mold_state64 = !Mold_state64;
	}
}

void MoldSelectDlg::OnBnClickedButMold65()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state65) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 65);
		Selected.erase(no);
		SetButtonColor(&m_Mold65, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD65, TEXT("65"));
		Mold_state65 = !Mold_state65;
	}
	else {
		Selected.push_back(65);
		SetButtonColor(&m_Mold65, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD65, TEXT("已选"));
		Mold_state65 = !Mold_state65;
	}
}

void MoldSelectDlg::OnBnClickedButMold66()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state66) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 66);
		Selected.erase(no);
		SetButtonColor(&m_Mold66, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD66, TEXT("66"));
		Mold_state66 = !Mold_state66;
	}
	else {
		Selected.push_back(66);
		SetButtonColor(&m_Mold66, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD66, TEXT("已选"));
		Mold_state66 = !Mold_state66;
	}
}

void MoldSelectDlg::OnBnClickedButMold67()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state67) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 67);
		Selected.erase(no);
		SetButtonColor(&m_Mold67, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD67, TEXT("67"));
		Mold_state67 = !Mold_state67;
	}
	else {
		Selected.push_back(67);
		SetButtonColor(&m_Mold67, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD67, TEXT("已选"));
		Mold_state67 = !Mold_state67;
	}
}

void MoldSelectDlg::OnBnClickedButMold68()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state68) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 68);
		Selected.erase(no);
		SetButtonColor(&m_Mold68, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD68, TEXT("68"));
		Mold_state68 = !Mold_state68;
	}
	else {
		Selected.push_back(68);
		SetButtonColor(&m_Mold68, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD68, TEXT("已选"));
		Mold_state68 = !Mold_state68;
	}
}

void MoldSelectDlg::OnBnClickedButMold69()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state69) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 69);
		Selected.erase(no);
		SetButtonColor(&m_Mold69, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD69, TEXT("69"));
		Mold_state69 = !Mold_state69;
	}
	else {
		Selected.push_back(69);
		SetButtonColor(&m_Mold69, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD69, TEXT("已选"));
		Mold_state69 = !Mold_state69;
	}
}

void MoldSelectDlg::OnBnClickedButMold70()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state70) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 70);
		Selected.erase(no);
		SetButtonColor(&m_Mold70, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD70, TEXT("70"));
		Mold_state70 = !Mold_state70;
	}
	else {
		Selected.push_back(70);
		SetButtonColor(&m_Mold70, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD70, TEXT("已选"));
		Mold_state70 = !Mold_state70;
	}
}

void MoldSelectDlg::OnBnClickedButMold71()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state71) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 71);
		Selected.erase(no);
		SetButtonColor(&m_Mold71, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD71, TEXT("71"));
		Mold_state71 = !Mold_state71;
	}
	else {
		Selected.push_back(71);
		SetButtonColor(&m_Mold71, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD71, TEXT("已选"));
		Mold_state71 = !Mold_state71;
	}
}

void MoldSelectDlg::OnBnClickedButMold72()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state72) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 72);
		Selected.erase(no);
		SetButtonColor(&m_Mold72, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD72, TEXT("72"));
		Mold_state72 = !Mold_state72;
	}
	else {
		Selected.push_back(72);
		SetButtonColor(&m_Mold72, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD72, TEXT("已选"));
		Mold_state72 = !Mold_state72;
	}
}

void MoldSelectDlg::OnBnClickedButMold73()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state73) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 73);
		Selected.erase(no);
		SetButtonColor(&m_Mold73, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD73, TEXT("73"));
		Mold_state73 = !Mold_state73;
	}
	else {
		Selected.push_back(73);
		SetButtonColor(&m_Mold73, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD73, TEXT("已选"));
		Mold_state73 = !Mold_state73;
	}
}

void MoldSelectDlg::OnBnClickedButMold74()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state74) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 74);
		Selected.erase(no);
		SetButtonColor(&m_Mold74, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD74, TEXT("74"));
		Mold_state74 = !Mold_state74;
	}
	else {
		Selected.push_back(74);
		SetButtonColor(&m_Mold74, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD74, TEXT("已选"));
		Mold_state74 = !Mold_state74;
	}
}

void MoldSelectDlg::OnBnClickedButMold75()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state75) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 75);
		Selected.erase(no);
		SetButtonColor(&m_Mold75, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD75, TEXT("75"));
		Mold_state75 = !Mold_state75;
	}
	else {
		Selected.push_back(75);
		SetButtonColor(&m_Mold75, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD75, TEXT("已选"));
		Mold_state75 = !Mold_state75;
	}
}

void MoldSelectDlg::OnBnClickedButMold76()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state76) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 76);
		Selected.erase(no);
		SetButtonColor(&m_Mold76, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD76, TEXT("76"));
		Mold_state76 = !Mold_state76;
	}
	else {
		Selected.push_back(76);
		SetButtonColor(&m_Mold76, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD76, TEXT("已选"));
		Mold_state76 = !Mold_state76;
	}
}

void MoldSelectDlg::OnBnClickedButMold77()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state77) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 77);
		Selected.erase(no);
		SetButtonColor(&m_Mold77, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD77, TEXT("77"));
		Mold_state77 = !Mold_state77;
	}
	else {
		Selected.push_back(77);
		SetButtonColor(&m_Mold77, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD77, TEXT("已选"));
		Mold_state77 = !Mold_state77;
	}
}

void MoldSelectDlg::OnBnClickedButMold78()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state78) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 78);
		Selected.erase(no);
		SetButtonColor(&m_Mold78, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD78, TEXT("78"));
		Mold_state78 = !Mold_state78;
	}
	else {
		Selected.push_back(78);
		SetButtonColor(&m_Mold78, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD78, TEXT("已选"));
		Mold_state78 = !Mold_state78;
	}
}

void MoldSelectDlg::OnBnClickedButMold79()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state79) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 79);
		Selected.erase(no);
		SetButtonColor(&m_Mold79, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD79, TEXT("79"));
		Mold_state79 = !Mold_state79;
	}
	else {
		Selected.push_back(79);
		SetButtonColor(&m_Mold79, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD79, TEXT("已选"));
		Mold_state79 = !Mold_state79;
	}
}

void MoldSelectDlg::OnBnClickedButMold80()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state80) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 80);
		Selected.erase(no);
		SetButtonColor(&m_Mold80, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD80, TEXT("80"));
		Mold_state80 = !Mold_state80;
	}
	else {
		Selected.push_back(80);
		SetButtonColor(&m_Mold80, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD80, TEXT("已选"));
		Mold_state80 = !Mold_state80;
	}
}

void MoldSelectDlg::OnBnClickedButMold81()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state81) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 81);
		Selected.erase(no);
		SetButtonColor(&m_Mold81, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD81, TEXT("81"));
		Mold_state81 = !Mold_state81;
	}
	else {
		Selected.push_back(81);
		SetButtonColor(&m_Mold81, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD81, TEXT("已选"));
		Mold_state81 = !Mold_state81;
	}
}

void MoldSelectDlg::OnBnClickedButMold82()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state82) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 82);
		Selected.erase(no);
		SetButtonColor(&m_Mold82, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD82, TEXT("82"));
		Mold_state82 = !Mold_state82;
	}
	else {
		Selected.push_back(82);
		SetButtonColor(&m_Mold82, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD82, TEXT("已选"));
		Mold_state82 = !Mold_state82;
	}
}

void MoldSelectDlg::OnBnClickedButMold83()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state83) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 83);
		Selected.erase(no);
		SetButtonColor(&m_Mold83, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD83, TEXT("83"));
		Mold_state83 = !Mold_state83;
	}
	else {
		Selected.push_back(83);
		SetButtonColor(&m_Mold83, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD83, TEXT("已选"));
		Mold_state83 = !Mold_state83;
	}
}

void MoldSelectDlg::OnBnClickedButMold84()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state84) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 84);
		Selected.erase(no);
		SetButtonColor(&m_Mold84, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD84, TEXT("84"));
		Mold_state84 = !Mold_state84;
	}
	else {
		Selected.push_back(84);
		SetButtonColor(&m_Mold84, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD84, TEXT("已选"));
		Mold_state84 = !Mold_state84;
	}
}

void MoldSelectDlg::OnBnClickedButMold85()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state85) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 85);
		Selected.erase(no);
		SetButtonColor(&m_Mold85, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD85, TEXT("85"));
		Mold_state85 = !Mold_state85;
	}
	else {
		Selected.push_back(85);
		SetButtonColor(&m_Mold85, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD85, TEXT("已选"));
		Mold_state85 = !Mold_state85;
	}
}

void MoldSelectDlg::OnBnClickedButMold86()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state86) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 86);
		Selected.erase(no);
		SetButtonColor(&m_Mold86, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD86, TEXT("86"));
		Mold_state86 = !Mold_state86;
	}
	else {
		Selected.push_back(86);
		SetButtonColor(&m_Mold86, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD86, TEXT("已选"));
		Mold_state86 = !Mold_state86;
	}
}

void MoldSelectDlg::OnBnClickedButMold87()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state87) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 87);
		Selected.erase(no);
		SetButtonColor(&m_Mold87, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD87, TEXT("87"));
		Mold_state87 = !Mold_state87;
	}
	else {
		Selected.push_back(87);
		SetButtonColor(&m_Mold87, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD87, TEXT("已选"));
		Mold_state87 = !Mold_state87;
	}
}

void MoldSelectDlg::OnBnClickedButMold88()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state88) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 88);
		Selected.erase(no);
		SetButtonColor(&m_Mold88, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD88, TEXT("88"));
		Mold_state88 = !Mold_state88;
	}
	else {
		Selected.push_back(88);
		SetButtonColor(&m_Mold88, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD88, TEXT("已选"));
		Mold_state88 = !Mold_state88;
	}
}

void MoldSelectDlg::OnBnClickedButMold89()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state89) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 89);
		Selected.erase(no);
		SetButtonColor(&m_Mold89, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD89, TEXT("89"));
		Mold_state89 = !Mold_state89;
	}
	else {
		Selected.push_back(89);
		SetButtonColor(&m_Mold88, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD89, TEXT("已选"));
		Mold_state89 = !Mold_state89;
	}
}

void MoldSelectDlg::OnBnClickedButMold90()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state90) {
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 90);
		Selected.erase(no);
		SetButtonColor(&m_Mold90, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD90, TEXT("90"));
		Mold_state90 = !Mold_state90;
	}
	else {
		Selected.push_back(90);
		SetButtonColor(&m_Mold90, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD90, TEXT("已选"));
		Mold_state90 = !Mold_state90;
	}
}


void MoldSelectDlg::OnBnClickedButMold0()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Mold_state0) {
		//Selected.erase(Selected.begin());
		//Selected.assign(Selected.begin() + 1, Selected.end());
		//Selected.pop_back();
		vector<int>::iterator no = find(Selected.begin(), Selected.end(), 0);
		Selected.erase(no);
		SetButtonColor(&m_Mold0, RGB(218, 218, 218));
		SetDlgItemText(IDC_BUT_MOLD0, TEXT("0号"));
		Mold_state0 = !Mold_state0;
	}
	else {
		Selected.push_back(0);
		SetButtonColor(&m_Mold0, RGB(0, 255, 255));
		SetDlgItemText(IDC_BUT_MOLD0, TEXT("0号已选"));
		Mold_state0 = !Mold_state0;
	}

}
