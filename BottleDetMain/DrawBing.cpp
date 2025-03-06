#include "pch.h"
#include "DrawBing.h"

DrawBing::DrawBing()
{
	m_hBrushData1 = NULL;
	m_hBrushData2 = NULL;
	m_hBrushData3 = NULL;
	m_hBrushData4 = NULL;
}

DrawBing::~DrawBing()
{
	Destory();
}

void DrawBing::Create(CRect& rt)
{
	m_rt = rt;
	Create(m_rt.left, m_rt.top, m_rt.Width(), m_rt.Height());
}

void DrawBing::Destory()
{
	if (m_hBrushData1)
	{
		::DeleteObject(m_hBrushData1);
	}
	m_hBrushData1 = NULL;
	if (m_hBrushData2)
	{
		::DeleteObject(m_hBrushData2);
	}
	m_hBrushData2 = NULL;
	if (m_hBrushData3)
	{
		::DeleteObject(m_hBrushData3);
	}
	m_hBrushData3 = NULL;
	if (m_hBrushData4)
	{
		::DeleteObject(m_hBrushData4);
	}
	m_hBrushData4 = NULL;

}

void DrawBing::Draw(CDC* pDC, INT Data1, INT Data2)
{
	pDC->SelectStockObject(NULL_PEN);
	//		pDC->SelectObject();

	double total = (Data1 + Data2);
	if (total == 0) {
		pDC->SelectObject(m_hBrushData1);
		DrawPrecent(pDC, 0, 180);
		pDC->SelectObject(m_hBrushData2);
		DrawPrecent(pDC, 180, 180);
	}
	else {
		double oneCellPrecent = 360 / total;
		int nIndex = 0;
		INT nLcDa = Data1 * oneCellPrecent;
		if (nLcDa == 360) {
			nLcDa = 359;
			pDC->SelectObject(m_hBrushData1);
			DrawPrecent(pDC, nIndex, nLcDa);
			nIndex += nLcDa;
			DrawPrecent(pDC, 359, 1);
		}
		else if (nLcDa == 0) {}
		else {
			pDC->SelectObject(m_hBrushData1);
			DrawPrecent(pDC, nIndex, nLcDa);
			nIndex += nLcDa;
		}
		INT nLcZhong = Data2 * oneCellPrecent;
		if (nLcZhong == 0) {}
		else if (nLcZhong == 360) {
			nLcZhong = 359;
			pDC->SelectObject(m_hBrushData2);
			DrawPrecent(pDC, nIndex, nLcZhong);
			nIndex += nLcZhong;
			DrawPrecent(pDC, 359, 1);
		}
		else {
			pDC->SelectObject(m_hBrushData2);
			//DrawPrecent(pDC, nIndex, nLcZhong);
			DrawPrecent(pDC, nIndex, (360 - nLcDa));
			nIndex += nLcZhong;
		}
	}
}

void DrawBing::Draw(CDC* pDC, int Data1, int Data2, int Data3, int Data4)
{
	pDC->SelectStockObject(NULL_PEN);
	//		pDC->SelectObject();

	double total = (Data1 + Data2 + Data3 + Data4);
	if (total == 0) {
		pDC->SelectObject(m_hBrushData1);
		DrawPrecent(pDC, 0, 90);
		pDC->SelectObject(m_hBrushData2);
		DrawPrecent(pDC, 90, 90);
		pDC->SelectObject(m_hBrushData3);
		DrawPrecent(pDC, 180, 90);
		pDC->SelectObject(m_hBrushData4);
		DrawPrecent(pDC, 270, 90);
	}
	else {
		double oneCellPrecent = 360 / total;
		int nIndex = 0;
		INT nLcDa = Data1 * oneCellPrecent;
		if (nLcDa == 360) {
			nLcDa = 359;
			pDC->SelectObject(m_hBrushData1);
			DrawPrecent(pDC, nIndex, nLcDa);
			nIndex += nLcDa;
			DrawPrecent(pDC, 359, 1);
		}
		else if (nLcDa == 0 && Data1 != 0) {
			pDC->SelectObject(m_hBrushData1);
			DrawPrecent(pDC, nIndex, 2);
			nIndex += 2;
		}
		else if (Data1 == 0) {
		}
		else {
			pDC->SelectObject(m_hBrushData1);
			DrawPrecent(pDC, nIndex, nLcDa);
			nIndex += nLcDa;
		}
		INT nLcZhong = Data2 * oneCellPrecent;
		if (nLcZhong == 0 && Data2 != 0) {
			pDC->SelectObject(m_hBrushData2);
			DrawPrecent(pDC, nIndex, 2);
			nIndex += 2;
		}
		else if (Data2 == 0) {
		}
		else if (nLcZhong == 360) {
			nLcZhong = 359;
			pDC->SelectObject(m_hBrushData2);
			DrawPrecent(pDC, nIndex, nLcZhong);
			nIndex += nLcZhong;
			DrawPrecent(pDC, 359, 1);
		}
		else {
			pDC->SelectObject(m_hBrushData2);
			//DrawPrecent(pDC, nIndex, nLcZhong);
			DrawPrecent(pDC, nIndex, nLcZhong);
			nIndex += nLcZhong;
		}
		INT nLcThree = Data3 * oneCellPrecent;
		if (nLcThree == 0 && Data3 != 0) {
			pDC->SelectObject(m_hBrushData3);
			DrawPrecent(pDC, nIndex, 2);
			nIndex += 2;
		}
		else if (Data3 == 0) {
		}
		else if (nLcThree == 360) {
			nLcThree = 359;
			pDC->SelectObject(m_hBrushData3);
			DrawPrecent(pDC, nIndex, nLcThree);
			nIndex += nLcThree;
			DrawPrecent(pDC, 359, 1);
		}
		else {
			pDC->SelectObject(m_hBrushData3);
			//DrawPrecent(pDC, nIndex, nLcZhong);
			DrawPrecent(pDC, nIndex, nLcThree);
			nIndex += nLcThree;
		}
		INT nLcFour = Data4 * oneCellPrecent;
		if (nLcFour == 0 && Data4 != 0) {
			//DrawPrecent(pDC, nIndex, 1);
			//nIndex += 1;
			DrawPrecent(pDC, 359, 1);
		}
		else if (Data4 == 0) {
		}
		else if (nLcFour == 360) {
			nLcFour = 359;
			pDC->SelectObject(m_hBrushData4);
			DrawPrecent(pDC, nIndex, nLcFour);
			nIndex += nLcFour;
			DrawPrecent(pDC, 359, 1);
		}
		else {
			pDC->SelectObject(m_hBrushData4);
			//DrawPrecent(pDC, nIndex, nLcZhong);
			DrawPrecent(pDC, nIndex, 360-nIndex);
			nIndex += nLcFour;
		}

	}
}

void DrawBing::DrawPrecent(CDC* pDC, int nIndex, INT nCount)
{
	CPoint ptStart;
	CPoint ptEnd;
	CountPoint(nIndex, ptEnd, FALSE);
	CountPoint(nIndex + nCount, ptStart, FALSE);
	pDC->Pie(&m_rt, ptStart, ptEnd);
}

void DrawBing::DrawTextShow(CDC* pDC, CRect D1, CRect D2, INT Data1, INT Data2)
{
	CString data1;//转类型
	data1.Format(TEXT("OK:%d"), Data1);
	pDC->SelectObject(m_hBrushData1);
	CBrush br1(RGB(30, 217, 114));
	pDC->FillRect(D1, &br1);
	pDC->TextOutW(50, 10, data1);///////////////////////////////////位置相对的话需改

	CString data2;//转类型
	data2.Format(TEXT("NG:%d"), Data2);
	CBrush br2(RGB(234, 34, 23));
	pDC->SelectObject(m_hBrushData2);
	pDC->FillRect(D2, &br2);
	pDC->TextOutW(50, 30, data2);/////////////////////////////////同上
}

void DrawBing::DrawTextShow(CDC* pDC, CRect D1, CRect D2, CRect D3, CRect D4, int Data1, int Data2, int Data3, int Data4)
{
	CString data1;//转类型
	data1.Format(TEXT("点状:%d"), Data1);
	pDC->SelectObject(m_hBrushData1);
	CBrush br1(RGB(154, 10, 43));
	pDC->FillRect(D1, &br1);
	pDC->TextOutW(D1.right+10, D1.top-5, data1);///////////////////////////////////位置相对的话需改

	CString data2;//转类型
	data2.Format(TEXT("污渍:%d"), Data2);
	CBrush br2(RGB(28, 41, 136));
	pDC->SelectObject(m_hBrushData2);
	pDC->FillRect(D2, &br2);
	pDC->TextOutW(D2.right + 10, D2.top-5, data2);/////////////////////////////////同上

	CString data3;//转类型
	data3.Format(TEXT("划痕:%d"), Data3);
	CBrush br3(RGB(63, 106, 57));
	pDC->SelectObject(m_hBrushData3);
	pDC->FillRect(D3, &br3);
	pDC->TextOutW(D3.right + 10, D3.top-5, data3);/////////////////////////////////同上

	CString data4;//转类型
	data4.Format(TEXT("混合:%d"), Data4);
	CBrush br4(RGB(130, 78, 34));
	pDC->SelectObject(m_hBrushData4);
	pDC->FillRect(D4, &br4);
	pDC->TextOutW(D4.right + 10, D4.top-5, data4);/////////////////////////////////同上

}

void DrawBing::Create(int x, int y, int cx, int cy)
{
	m_x = x;
	m_y = y;
	m_cx = cx;
	m_cy = cy;

	//m_hBrushData1 = CreateSolidBrush(RGB(30, 217, 114));
	//m_hBrushData2 = CreateSolidBrush(RGB(234, 34, 23));
	m_hBrushData1 = CreateSolidBrush(RGB(154, 10, 43));
	m_hBrushData2 = CreateSolidBrush(RGB(28, 41, 136));
	m_hBrushData3 = CreateSolidBrush(RGB(63, 106, 57));
	m_hBrushData4 = CreateSolidBrush(RGB(130, 78, 34));

}

void DrawBing::CountPoint(int nAngle, CPoint& pt, BOOL bPercent)
{
	double pi = 3.1415926535;
	int nLeft = m_x;
	int nTop = m_y;
	int nRight = m_x + m_cx;
	int nBottom = m_y + m_cy;

	while (nAngle < 0)
		nAngle += 360;

	while (nAngle > 359)
		nAngle -= 359;

	double dAngle = ((double)nAngle) * pi / (double)180;

	double r;
	r = ((double)nBottom - nTop) / 2.0;
	if (bPercent)
		r = r * 3.0 / 5.0;

	double dOffX = (r * sin(dAngle));
	double dOffY = 0.0 - (r * cos(dAngle));

	double dX = ((double)(nRight + nLeft)) / 2.0;
	double dY = ((double)(nTop + nBottom)) / 2.0;

	pt.x = (int)(dX + dOffX);
	pt.y = (int)(dY + dOffY);
}



//void DrawBingTu(CDC* pDC, CRect& rc, INT OKData, INT NGData);
//
//void CMFC1Dlg::DrawBingTu(CDC* pDC, CRect& rc, INT OKData, INT NGData)
//{
//	DrawBing bingTu;
//	bingTu.Create(rc);
//	bingTu.Draw(pDC, OKData, NGData);
//}
//
//void CMFC1Dlg::OnBnClickedButton1()
//{
//	CRect rect(100, 100, 400, 400);
//	CRect rect1(10, 10, 40, 20);//OK的
//	CRect rect2(10, 50, 40, 60);
//	DrawBingTu(GetDlgItem(IDC_IMAGE1)->GetDC(), rect, OKData, NGData);
//	DrawBing xx;
//	xx.DrawTextShow(GetDlgItem(IDC_IMAGE1)->GetDC(), rect1, rect2, OKData, NGData);
//}
