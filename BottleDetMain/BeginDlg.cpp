// BeginDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "BeginDlg.h"
#include "afxdialogex.h"


// BeginDlg 对话框

IMPLEMENT_DYNAMIC(BeginDlg, CDialogEx)

BeginDlg::BeginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BEGIN_DIALOG, pParent)
{

}

BeginDlg::~BeginDlg()
{
	DeleteObject(m_brushBack);
}

void BeginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BeginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// BeginDlg 消息处理程序
BOOL BeginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(_T("启动中"));
	m_brushBack = CreateSolidBrush(RGB(136, 139, 186));
	m_static.SubclassDlgItem(IDC_TIP, this);
	m_font.CreatePointFont(500, _T("楷体"));
	m_static.SetFont(&m_font);
	//SetDlgItemText(IDC_TIP1, _T("\n\n\n\n启动中   "));
	//OnTimer();
	SetTimer(TIMER_TIP, TIME_TIP, NULL);
	SetDlgItemText(IDC_TIME_COSTS, TEXT("预计耗时3分钟"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void BeginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


void BeginDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{
		switch ((++round) % 4) {
			case 0:
				SetDlgItemText(IDC_TIP, _T("\n\n\n\n启动中   "));
				break;
			case 1:
				SetDlgItemText(IDC_TIP, _T("\n\n\n\n启动中.  "));
				break;
			case 2:
				SetDlgItemText(IDC_TIP, _T("\n\n\n\n启动中.. "));
				break;
			case 3:
				SetDlgItemText(IDC_TIP, _T("\n\n\n\n启动中..."));
				break;
			default:
				break;
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


HBRUSH BeginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_TIP ||
		pWnd->GetDlgCtrlID()== IDC_TIME_COSTS) {
		pDC->SetTextColor(RGB(40, 2, 247));
		//pDC->SetBkColor(RGB(136, 139, 186));//设置文本背景颜色
		pDC->SetBkMode(TRANSPARENT);		//设置文本背景透明
		GetStockObject(HOLLOW_BRUSH);
		//return HBRUSH(GetStockObject(HOLLOW_BRUSH));
		hbr = HBRUSH(m_brushBack);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void BeginDlg::OnPaint()
{
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(136, 139, 186));
	//InitControlColor(IDC_IMAGE_WIN, RGB(0, 0, 0));
	//CPaintDC dc(this); // device context for painting
	//				   // TODO: 在此处添加消息处理程序代码
	//				   // 不为绘图消息调用 CDialogEx::OnPaint()
}
