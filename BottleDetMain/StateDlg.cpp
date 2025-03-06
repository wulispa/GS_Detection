// StateDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "StateDlg.h"
#include "afxdialogex.h"
#include "ChartAxis.h"
#include "ChartAxisLabel.h"
#include "ChartBarSerie.h"



// StateDlg 对话框

IMPLEMENT_DYNAMIC(StateDlg, CDialogEx)

StateDlg::StateDlg(CWnd* pParent, DataStatisticXml* pdatastat /*=nullptr*/)
	: CDialogEx(IDD_STATE_DLG, pParent),
	p_mDatastat(pdatastat)
{

}

StateDlg::StateDlg(CWnd* pParent, DataManager* p_data)
	: CDialogEx(IDD_STATE_DLG, pParent),
	p_Data(p_data)
{

}

StateDlg::~StateDlg()
{
	m_font->DeleteObject();

}

void StateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM_CHART, m_Chart);
	DDX_Control(pDX, IDC_MONTHCALENDAR_TIME, m_mothCtrl);
	DDX_Control(pDX, IDC_COMBO_PART_NUM, m_BanNum);
}


BEGIN_MESSAGE_MAP(StateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_INQUIRE, &StateDlg::OnBnClickedButInquire)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO_PART_NUM, &StateDlg::OnCbnSelchangeComboPartNum)
END_MESSAGE_MAP()


// StateDlg 消息处理程序


BOOL StateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SYSTEMTIME st;
	CString strYear, strMoth, strDay,strHour;
	GetLocalTime(&st);
	m_mothCtrl.SetCurSel(CTime(st.wYear, st.wMonth, st.wDay, 0, 0, 0, 0));//设置默认日期
	m_Year = st.wYear;
	m_Moth = st.wMonth;
	m_Day = st.wDay;
	//m_Hour = st.wHour;
	m_picwin = GetDlgItem(IDC_STAT_PAINT_CONTROL);
	UpDateMothData();
	UpdateDayData();
	//m_mothCtrl.
	m_font = new CFont();
	InitWindowFront();//初始化字体

	m_BanNum.AddString(TEXT("两班"));
	m_BanNum.AddString(TEXT("三班"));

	if (p_Data->GetSystemParam()->BanSelect == "TWO") {
		m_BanNum.SetCurSel(0);
		Num = 12;
	}
	else {
		m_BanNum.SetCurSel(1);
		Num = 8;
	}
	if (p_Data->GetSystemParam()->BanNumber == "FIR") {
		((CButton*)GetDlgItem(IDC_RADIO_ONE))->SetCheck(TRUE);
		if (Num == 8) {
			HourStart = 2;
		}
		else {
			HourStart = 8;
		}
	}
	else if (p_Data->GetSystemParam()->BanNumber == "SEC") {
		((CButton*)GetDlgItem(IDC_RADIO_TWO))->SetCheck(TRUE);
		if (Num == 8) {
			HourStart = 10;
		}
		else {
			HourStart = 20;
		}
	}
	else {
		((CButton*)GetDlgItem(IDC_RADIO_THREE))->SetCheck(TRUE);
		if (Num == 8) {
			HourStart = 18;
		}
		else {
			HourStart = 20;
		}
	}
	BanData = data.GetPartData(m_Year, m_Moth, m_Day, HourStart, Num);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void StateDlg::OnBnClickedButInquire()
{
	//MothData=p_mDatastat->GetMonthData()
	if (((CButton*)GetDlgItem(IDC_RADIO_ONE))->GetCheck()) {
		p_Data->SetBanNumber(TEXT("FIR"));
		if (Num == 8) {
			HourStart = 2;
		}
		else {
			HourStart = 8;
		}
	}
	if (((CButton*)GetDlgItem(IDC_RADIO_TWO))->GetCheck()) {
		p_Data->SetBanNumber(TEXT("SEC"));
		if (Num == 8) {
			HourStart = 10;
		}
		else {
			HourStart = 20;
		}

	}

	if (((CButton*)GetDlgItem(IDC_RADIO_THREE))->GetCheck()) {
		p_Data->SetBanNumber(TEXT("THI"));
		if (Num == 8) {
			HourStart = 18;
		}
		else {
			HourStart = 20;
		}
	}
	CTime mothSelect;
	m_mothCtrl.GetCurSel(mothSelect);
	if ((mothSelect.GetYear() != m_Year) || (mothSelect.GetMonth() != m_Moth))
	{
		m_Year = mothSelect.GetYear();
		m_Moth = mothSelect.GetMonth();
		UpDateMothData();//更新一月数据
	}
	if (mothSelect.GetDay() != m_Day)
	{
		m_Day = mothSelect.GetDay();
		UpdateDayData();
	}

	BanData = data.GetPartData(m_Year, m_Moth, m_Day, HourStart, Num);
	Invalidate();

}

void StateDlg::InitWindowFront()
{
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 2;
	lfCtrl.lfHeight = 16;
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

	GetDlgItem(IDC_GROUP_STAT_PARAM)->SetFont(m_font);
	GetDlgItem(IDC_STATE_PISTURE)->SetFont(m_font);
}

void StateDlg::UpDateMothData()
{
	//读取数据
	int max_num = 0;
	//MothData = data.selectData(m_Year, m_Moth);
	MothData = data.selectData(m_Year, m_Moth, max_num);
	if (data.max > 60000) {
		max_num = data.max + data.max * 0.333;
	}
	else {
		max_num = data.max + 20000;
	}

	//BanData = data.GetPartData(m_Year, m_Moth, m_Day, 8, 12);
	//for (int i = 0; i < MothData.size(); i++) {
	//	MothData[i][]
	//}

	// TODO: 在此添加控件通知处理程序代码
	m_Chart.EnableRefresh(false);
	m_Chart.GetTitle()->RemoveAll();
	m_Chart.RemoveAllSeries();

	//创建x轴
	CChartStandardAxis* pBottomAxis = m_Chart.CreateStandardAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetMinMax(1, 32);
	pBottomAxis->SetDiscrete(true);
	pBottomAxis->SetTickIncrement(false, 1);
	pBottomAxis->GetLabel()->SetText(TEXT("日期"));

	//创建Y轴
	CChartStandardAxis* pLeftAxis = m_Chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	//pLeftAxis->SetMinMax(0, 350000);
	pLeftAxis->SetMinMax(0, max_num);
	pLeftAxis->GetLabel()->SetText(TEXT("数量"));

	//绘制图例
	m_Chart.GetLegend()->SetVisible(true);
	m_Chart.GetLegend()->SetHorizontalMode(true);
	m_Chart.GetLegend()->UndockLegend(80, 50);

	//设置表头
	CString titlr_str;
	titlr_str.Format(TEXT("%d年%d月检测统计图"), m_Year, m_Moth);
	m_Chart.GetTitle()->AddString((const TChartString)titlr_str);
	CChartFont TitleFont;
	TitleFont.SetFont(TEXT("Arial Black"), 120, true, false, true);
	m_Chart.GetTitle()->SetFont(TitleFont);
	m_Chart.GetTitle()->SetColor(RGB(0, 255, 0));

	//设置背景色--渐变
	m_Chart.SetBackGradient(RGB(255, 255, 255), RGB(150, 150, 255), gtVertical);//垂直渐变

	//创建柱状图

	CChartBarSerie* pBarSerieGood = m_Chart.CreateBarSerie();
	CChartBarSerie* pBarSerieBad = m_Chart.CreateBarSerie();
	pBarSerieGood->SetBarWidth(10);
	pBarSerieBad->SetBarWidth(10);

	//模拟数据
	for (int i = 1; i < 32; i++)
	{
		long int value1= MothData[i][0];
		pBarSerieGood->AddPoint(i, value1);
		long int value2 = MothData[i][1];
		pBarSerieBad->AddPoint(i, value2);
	}

	pBarSerieGood->SetColor(RGB(0, 255, 0));
	pBarSerieGood->SetName(TEXT("良品"));

	pBarSerieBad->SetColor(RGB(255, 0, 0));
	pBarSerieBad->SetName(TEXT("次品"));


	m_Chart.SetPanEnabled(false);
	m_Chart.SetZoomEnabled(false);
	m_Chart.EnableRefresh(true);


}
void StateDlg::UpdateDayData()
{
	//IDC_STATE_PISTURE
	CString str;
	str.Format(TEXT("%d年%d月%d日生产统计图"),m_Year, m_Moth, m_Day);
	SetDlgItemText(IDC_STATE_PISTURE, str);

	Invalidate();
	
}
//// TODO: 在此添加控件通知处理程序代码
//m_Chart.EnableRefresh(false);
//m_Chart.GetTitle()->RemoveAll();
//m_Chart.RemoveAllSeries();
//*CChartDateTimeAxis* pBottomAxis = m_Chart.CreateDateTimeAxis(CChartCtrl::BottomAxis);
//pBottomAxis->SetMinMax(1, 31);
//pBottomAxis->SetDiscrete(true);
//pBottomAxis->SetTickIncrement(false, CChartDateTimeAxis::tiDay, 1);
//pBottomAxis->SetTickLabelFormat(false, _T("%b"));*/
//CChartStandardAxis* pBottomAxis = m_Chart.CreateStandardAxis(CChartCtrl::BottomAxis);
//pBottomAxis->SetMinMax(1, 32);
//pBottomAxis->SetDiscrete(true);
//pBottomAxis->SetTickIncrement(false, 1);
////pBottomAxis->SetTickIncrement(false, CChartDateTimeAxis::tiDay, 1);
////pBottomAxis->SetTickLabelFormat(false, _T("%b"));
//
//CChartStandardAxis* pLeftAxis = m_Chart.CreateStandardAxis(CChartCtrl::LeftAxis);
//pLeftAxis->SetMinMax(0, 100);
//pLeftAxis->GetLabel()->SetText(TEXT("Scales"));
////绘制图例
//m_Chart.GetLegend()->SetVisible(true);
//m_Chart.GetLegend()->SetHorizontalMode(true);
//m_Chart.GetLegend()->UndockLegend(80, 50);
//m_Chart.GetTitle()->AddString(TEXT("hello"));
//CChartFont TitleFont;
//TitleFont.SetFont(TEXT("Arial Black"), 120, true, false, true);
//m_Chart.GetTitle()->SetFont(TitleFont);
//m_Chart.GetTitle()->SetColor(RGB(0, 255, 0));
////设置背景色--渐变
//m_Chart.SetBackGradient(RGB(255, 255, 255), RGB(150, 150, 255), gtVertical);//垂直渐变
////创建柱状图
//CChartBarSerie* pBarSerieGood = m_Chart.CreateBarSerie();
//CChartBarSerie* pBarSerieBad = m_Chart.CreateBarSerie();
//pBarSerieGood->SetBarWidth(10);
//pBarSerieBad->SetBarWidth(10);
////模拟数据
//for (int i = 1; i < 32; i++)
//{
//	int value1 = 20 + rand() % (100 - 30);
//	pBarSerieGood->AddPoint(i, value1);
//	int value2 = 20 + rand() % (100 - 30);
//	pBarSerieBad->AddPoint(i, value2);
//}
//pBarSerieGood->SetColor(RGB(0, 255, 0));
//pBarSerieGood->SetName(TEXT("Good"));
//pBarSerieBad->SetColor(RGB(255, 0, 0));
//pBarSerieBad->SetName(TEXT("Bad"));
//m_Chart.SetPanEnabled(false);
//m_Chart.SetZoomEnabled(false);
//m_Chart.EnableRefresh(true);

void StateDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect5;
	GetDlgItem(IDC_STAT_PAINT_CONTROL)->GetWindowRect(rect5);
	ScreenToClient(rect5);
	dc.FillSolidRect(rect5, RGB(0, 255, 255));//绘制背景

	CRect rc;
	CRect m_rect;
	GetDlgItem(IDC_STAT_PAINT_CONTROL)->GetClientRect(m_rect);

	//m_picwin->GetClientRect(m_rect);
	
	CDC* mdc = GetDlgItem(IDC_STAT_PAINT_CONTROL)->GetDC();
	//dc.FillSolidRect(m_rect, RGB(0, 255, 255));

	CRect rect(100, 10, 300, 200);
	CRect rect1(10, 10, 40, 20);//第一类位置
	CRect rect2(10, 30, 40, 40);
	CRect rect3(10, 50, 40, 60);//第三类位置
	CRect rect4(10, 70, 40, 80);

	bingTu.Create(rect);
	//bingTu.Draw(mdc, MothData[m_Day-1][0], MothData[m_Day - 1][1]);
	//bingTu.DrawTextShow(mdc, rect1, rect2, MothData[m_Day - 1][0], MothData[m_Day - 1][1]);
	bingTu.Draw(mdc, BanData[1], BanData[2], BanData[3], BanData[4]);
	bingTu.DrawTextShow(mdc, rect1, rect2, rect3, rect4, BanData[1], BanData[2], BanData[3], BanData[4]);
	CDialogEx::OnPaint();
	GetDlgItem(IDC_STAT_PAINT_CONTROL)->ReleaseDC(mdc);
}


void StateDlg::OnCbnSelchangeComboPartNum()
{
	// TODO: 在此添加控件通知处理程序代码
	int ban = m_BanNum.GetCurSel();
	if (ban == 0) {
		p_Data->SetBanSelect(TEXT("TWO"));
		Num = 12;
	}
	else {
		p_Data->SetBanSelect(TEXT("THREE"));
		Num = 8;
	}
}
