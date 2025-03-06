// StatShowDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "StatShowDlg.h"
#include "afxdialogex.h"


// StatShowDlg 对话框

IMPLEMENT_DYNAMIC(StatShowDlg, CDialogEx)

StatShowDlg::StatShowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STATE_DLG, pParent)
{

}

StatShowDlg::~StatShowDlg()
{
}

void StatShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StatShowDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// StatShowDlg 消息处理程序


HBRUSH StatShowDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


BOOL StatShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//初始化统计窗口颜色
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void StatShowDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	//CRect rect;
	//GetDlgItem(IDC_STAT_PAINT_CONTROL)->GetWindowRect(rect);
	//ScreenToClient(rect);
	//dc.FillSolidRect(rect, RGB(0, 255, 255));//绘制背景
	////获得窗口坐标
	//int left = rect.left;
	//int top = rect.top;
	//int right = rect.right;
	//int bottom = rect.bottom;
	////x坐标轴起始坐标
	//int LintStart_x, LineStart_y, LintStop_x, LineStop_y;
	//LintStart_x = left ;
	//LineStart_y = bottom -30;
	//LintStop_x = right - 10;
	//LineStop_y = bottom - 30;
	//dc.MoveTo(LintStart_x, LineStart_y);
	//dc.LineTo(LintStop_x, LineStop_y);
	//
	//LintStart_x = left + 10;
	//LineStart_y = bottom-5 ;
	//LintStop_x = left + 10;
	//LineStop_y = top +10;
	//dc.MoveTo(LintStart_x, LineStart_y);
	//dc.LineTo(LintStop_x, LineStop_y);
	//dc.MoveTo(0, 0);
	//
	////生成统计数据,按30天计算，统计近30天的检测情况
	//int lenth = right - left - 20;//774--   750/30=24
	////left+10+20------------------------->right-10-34
	/////left+30-----left+53
	////bottom -30   bottom -315
	//CRect ract_child;
	//SYSTEMTIME st;
	////CString LogStr;
	//GetLocalTime(&st);
	////LogStr.Format(TEXT("%2d-%2d-%2d检测到一个缺陷"), st.wHour, st.wMinute, st.wSecond);
	//int t_day, t_moth;
	//t_day = st.wDay;
	//t_moth = st.wMonth;
	//
	//for (int index = 0; index < 30; index++)
	//{



	//}



	//CString str = TEXT("12345");
	//dc.SetTextColor(RGB(0, 0, 0));
	//dc.DrawText(str, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	//InitControlColor(IDC_STAT_PAINT_CONTROL, RGB(0, 255, 255));
}
void StatShowDlg::InitControlColor(int ID, COLORREF rgb)
{
	CRect mrect;
	GetDlgItem(ID)->GetClientRect(&mrect);
	FillRect(GetDlgItem(ID)->GetDC()->GetSafeHdc(), &mrect, CBrush(rgb));
}