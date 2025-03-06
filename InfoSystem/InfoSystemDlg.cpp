
// InfoSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "InfoSystem.h"
#include "InfoSystemDlg.h"
#include "afxdialogex.h"
#include "wchar.h"
#include "SeekSTimeDlg.h"
#include "SeekDTimeDlg.h"
#include "SeekBNumberDlg.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CInfoSystemDlg 对话框



CInfoSystemDlg::CInfoSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INFOSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_font = nullptr;
}

CInfoSystemDlg::~CInfoSystemDlg()
{
	// 在析构函数中删除 CFont 对象
	if (m_font != nullptr)
	{
		m_font->DeleteObject();
		delete m_font;
	}
}

void CInfoSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);
}

BEGIN_MESSAGE_MAP(CInfoSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CInfoSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CInfoSystemDlg::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &CInfoSystemDlg::OnLvnItemchangedList3)
	ON_BN_CLICKED(IDC_BUTTON3, &CInfoSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CInfoSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CInfoSystemDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CInfoSystemDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CInfoSystemDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON4, &CInfoSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CInfoSystemDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CInfoSystemDlg 消息处理程序

BOOL CInfoSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	//设置背景颜色
	m_list.SetBkColor(RGB(40, 2, 247)); 
	m_list.SetTextBkColor(RGB(157, 172, 253)); 

	VERIFY(font.CreateFont(
		42,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_HEAVY,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		FALSE,                         // cStrikeOut
		DEFAULT_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("黑体")));            // lpszFacename

	// 将字体设置到列表控件
	m_list.SetFont(&font);
	font.DeleteObject(); // 记得删除字体对象

	// 设置列表控件风格，例如LVS_REPORT
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);	// 整行选择、网格线
	// 添加列
	m_list.InsertColumn(0, _T("记录编号"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(1, _T("记录时间"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(2, _T("生产批号"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(3, _T("失效年月"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(4, _T("上层明码"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(5, _T("下层明码"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(6, _T("上层条码"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(7, _T("下层条码"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(8, _T("操作人"), LVCFMT_LEFT, 110);
	m_list.InsertColumn(9, _T("备注"), LVCFMT_LEFT, 110);


	SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);


	// 创建字体对象
	CFont Cfont;
	BOOL bFontCreated = Cfont.CreatePointFont(120, _T("黑体")); // 120表示12点大小
	if (bFontCreated)
	{
		// 获取按钮控件并设置字体
		CButton* pBtns[] = {
			(CButton*)GetDlgItem(IDC_BUTTON1), // IDC_BUTTON1是第一个按钮的ID
			(CButton*)GetDlgItem(IDC_BUTTON2), // IDC_BUTTON2是第二个按钮的ID
			(CButton*)GetDlgItem(IDC_BUTTON3),
			(CButton*)GetDlgItem(IDC_BUTTON4),
			(CButton*)GetDlgItem(IDC_BUTTON5),
			(CButton*)GetDlgItem(IDC_BUTTON6),
			(CButton*)GetDlgItem(IDC_BUTTON7),
			(CButton*)GetDlgItem(IDC_BUTTON8),
			(CButton*)GetDlgItem(IDC_BUTTON9),
			// ... 添加更多按钮控件ID
		};
		for (CButton* pBtn : pBtns)
		{
			if (pBtn != NULL)
			{
				pBtn->SetFont(&Cfont);
			}
		}
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CInfoSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInfoSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CInfoSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInfoSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (SQL.Connect_MySQL())
	{
		Info = SQL.Get_All_Info();
		//MessageBox(TEXT("123"));
		for (int i = 0; i < Info.size(); i++)
		{
			m_list.InsertItem(i, _T(""));			// 插入行
			m_list.SetItemText(i, 0, Info[i].m_RecordNumber.c_str());
			m_list.SetItemText(i, 1, Info[i].m_RecordTime.c_str());
			m_list.SetItemText(i, 2, Info[i].m_BatchNumber.c_str());
			m_list.SetItemText(i, 3, Info[i].m_ExpiringDate.c_str());
			m_list.SetItemText(i, 4, Info[i].m_U1.c_str());
			m_list.SetItemText(i, 5, Info[i].m_D1.c_str());
			m_list.SetItemText(i, 6, Info[i].m_U2.c_str());
			m_list.SetItemText(i, 7, Info[i].m_D2.c_str());
			m_list.SetItemText(i, 8, Info[i].m_Operators.c_str());
			m_list.SetItemText(i, 9, Info[i].m_Notes.c_str());
		}
	}
	else
	{
		return;
	}

	// 显示第一页
	ShowPage(m_nCurrentPage);
}


void CInfoSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CTime m_time;
	m_time = CTime::GetCurrentTime();//获取系统当前时间
	CString m_strDateTime;//系统时间
	m_strDateTime = m_time.Format("%Y.%m.%d");//系统时间格式化，以年月日方式
	if (m_list.GetItemCount() <= 0)
	{
		AfxMessageBox(_T("列表中没有数据，无法导出"));
		return;
	}
	char szFilters[] = _T("xlsx文件(*.xlsx)|*.xlsx|txt文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog dlg(FALSE, _T("xlsx"), m_strDateTime, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilters, this);
	if (dlg.DoModal() != IDOK)
		return;
	CString strFilePath;
	strFilePath = dlg.GetPathName();//获得文件路径名
	DWORD dwRe = GetFileAttributes(strFilePath);
	if (dwRe != (DWORD)-1)
	{
		DeleteFile(strFilePath);
	}
	//保存文件数据
	FILE* fp;
	fopen_s(&fp, strFilePath, "w");
	//	char str[1024];
	if (fp == NULL)
	{
		printf("save file error\n");
		return;
	}
	//得到listctrl的所有列的header字符串内容
	int nHeadNum = m_list.GetHeaderCtrl()->GetItemCount();
	LVCOLUMN lvcol;
	char str_out[256];
	int nColNum;
	nColNum = 0;
	lvcol.mask = LVCF_TEXT;
	lvcol.pszText = str_out;
	lvcol.cchTextMax = 256;
	while (m_list.GetColumn(nColNum, &lvcol))
	{
		nColNum++;
		fprintf_s(fp, "%s\t", lvcol.pszText);
	}
	fprintf_s(fp, "\n", lvcol.pszText);

	//读取listctrl数据

	int nRow = m_list.GetItemCount();
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nColNum; j++)

		{
			CString str_data = m_list.GetItemText(i, j);//获取指定列
			fprintf_s(fp, "%s\t", str_data);  // \t为水平制表符
		}
		fprintf_s(fp, "\n");
	}
	fclose(fp);
	AfxMessageBox("文件已生成！");
}


void CInfoSystemDlg::OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



void CInfoSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	SeekSTimeDlg dlg;
	if (dlg.DoModal()==IDOK)
	{
		vector<DateInfo> result = SQL.Seek_info1(dlg.m_RecordTime);
		if (result.empty())
		{
			MessageBox(TEXT("查无数据"), TEXT("提示"));
			return;
		}

		m_list.DeleteAllItems();
		CString str;
		for (int i = 0; i < result.size(); i++)
		{
			m_list.InsertItem(i, _T(""));			// 插入行
			m_list.SetItemText(i, 0, result[i].m_RecordNumber.c_str());
			m_list.SetItemText(i, 1, result[i].m_RecordTime.c_str());
			m_list.SetItemText(i, 2, result[i].m_BatchNumber.c_str());
			m_list.SetItemText(i, 3, result[i].m_ExpiringDate.c_str());
			m_list.SetItemText(i, 4, result[i].m_U1.c_str());
			m_list.SetItemText(i, 5, result[i].m_D1.c_str());
			m_list.SetItemText(i, 6, result[i].m_U2.c_str());
			m_list.SetItemText(i, 7, result[i].m_D2.c_str());
			m_list.SetItemText(i, 8, result[i].m_Operators.c_str());
			m_list.SetItemText(i, 9, result[i].m_Notes.c_str());
		}
	}


}


void CInfoSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	
	SeekDTimeDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		vector<DateInfo> result = SQL.Seek_info2(dlg.m_ExpiringDate);
		if (result.empty())
		{
			MessageBox(TEXT("查无数据"), TEXT("提示"));
			return;
		}

		m_list.DeleteAllItems();
		CString str;
		for (int i = 0; i < result.size(); i++)
		{
			m_list.InsertItem(i, _T(""));			// 插入行
			m_list.SetItemText(i, 0, result[i].m_RecordNumber.c_str());
			m_list.SetItemText(i, 1, result[i].m_RecordTime.c_str());
			m_list.SetItemText(i, 2, result[i].m_BatchNumber.c_str());
			m_list.SetItemText(i, 3, result[i].m_ExpiringDate.c_str());
			m_list.SetItemText(i, 4, result[i].m_U1.c_str());
			m_list.SetItemText(i, 5, result[i].m_D1.c_str());
			m_list.SetItemText(i, 6, result[i].m_U2.c_str());
			m_list.SetItemText(i, 7, result[i].m_D2.c_str());
			m_list.SetItemText(i, 8, result[i].m_Operators.c_str());
			m_list.SetItemText(i, 9, result[i].m_Notes.c_str());
		}
	}

}


void CInfoSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	SeekBNumberDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		vector<DateInfo> result = SQL.Seek_info3(dlg.m_BatchNumber);
		if (result.empty())
		{
			MessageBox(TEXT("查无数据"), TEXT("提示"));
			return;
		}

		m_list.DeleteAllItems();
		CString str;
		for (int i = 0; i < result.size(); i++)
		{
			m_list.InsertItem(i, _T(""));			// 插入行
			m_list.SetItemText(i, 0, result[i].m_RecordNumber.c_str());
			m_list.SetItemText(i, 1, result[i].m_RecordTime.c_str());
			m_list.SetItemText(i, 2, result[i].m_BatchNumber.c_str());
			m_list.SetItemText(i, 3, result[i].m_ExpiringDate.c_str());
			m_list.SetItemText(i, 4, result[i].m_U1.c_str());
			m_list.SetItemText(i, 5, result[i].m_D1.c_str());
			m_list.SetItemText(i, 6, result[i].m_U2.c_str());
			m_list.SetItemText(i, 7, result[i].m_D2.c_str());
			m_list.SetItemText(i, 8, result[i].m_Operators.c_str());
			m_list.SetItemText(i, 9, result[i].m_Notes.c_str());
		}
	}
}



void CInfoSystemDlg::ShowPage(int nPage) {
	int nStartIndex = nPage * m_nItemsPerPage;
	int nEndIndex = min((nPage + 1) * m_nItemsPerPage - 1, (int)Info.size() - 1);

	// 清除当前显示的项
	m_list.DeleteAllItems();

	// 显示新页的项
	for (int i = nStartIndex; i <= nEndIndex; ++i) {

		//存储数据转换类型
		CString strText1 = (Info[i].m_RecordNumber.c_str()); 
		CString strText2 = (Info[i].m_RecordTime.c_str());
		CString strText3 = (Info[i].m_BatchNumber.c_str());
		CString strText4 = (Info[i].m_ExpiringDate.c_str());
		CString strText5 = (Info[i].m_U1.c_str());
		CString strText6 = (Info[i].m_D1.c_str());
		CString strText7 = (Info[i].m_U2.c_str());
		CString strText8 = (Info[i].m_D2.c_str());
		CString strText9 = (Info[i].m_Operators.c_str());
		CString strText10 = (Info[i].m_Notes.c_str());

		int nIndex = m_list.InsertItem(i - nStartIndex, strText1);
		// 可以设置其他列的值
		m_list.SetItemText(nIndex, 1, strText2);
		m_list.SetItemText(nIndex, 2, strText3);
		m_list.SetItemText(nIndex, 3, strText4);
		m_list.SetItemText(nIndex, 4, strText5);
		m_list.SetItemText(nIndex, 5, strText6);
		m_list.SetItemText(nIndex, 6, strText7);
		m_list.SetItemText(nIndex, 7, strText8);
		m_list.SetItemText(nIndex, 8, strText9);
		m_list.SetItemText(nIndex, 9, strText10);
	}
}



void CInfoSystemDlg::OnBnClickedButton6()		//首页
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_bIsFirstPage) {
		m_nCurrentPage = 0;
		ShowPage(m_nCurrentPage);
		m_bIsFirstPage = true;
		m_bIsLastPage = false;
	}
}


void CInfoSystemDlg::OnBnClickedButton7()	//上一页
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_nCurrentPage > 0) {
		m_nCurrentPage--;
		ShowPage(m_nCurrentPage);
	}

}


void CInfoSystemDlg::OnBnClickedButton8()	//下一页
{
	// TODO: 在此添加控件通知处理程序代码
	int nMaxPage = (int)(Info.size() + m_nItemsPerPage - 1) / m_nItemsPerPage - 1;
	if (m_nCurrentPage < nMaxPage) {
		m_nCurrentPage++;
		ShowPage(m_nCurrentPage);
	}

}


void CInfoSystemDlg::OnBnClickedButton9()	//尾页
{
	// TODO: 在此添加控件通知处理程序代码
	int nMaxPage = (int)(Info.size() + m_nItemsPerPage - 1) / m_nItemsPerPage - 1;
	if (!m_bIsLastPage) {
		m_nCurrentPage = nMaxPage;
		ShowPage(m_nCurrentPage);
		m_bIsLastPage = true;
		m_bIsFirstPage = false;
	}
}



