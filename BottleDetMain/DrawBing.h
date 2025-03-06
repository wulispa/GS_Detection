#pragma once
#include <math.h>
#include <string>

using namespace std;

class DrawBing
{
public:
	DrawBing();
	~DrawBing();
	void Create(CRect& rt);
	void Destory();
	void Draw(CDC* pDC, INT Data1, INT Data2);
	void Draw(CDC* pDC, int Data1, int Data2, int Data3, int Data4);//Àƒ¿‡»±œ›

	void DrawPrecent(CDC* pDC, int nIndex, INT nCount);
	void DrawTextShow(CDC* pDC, CRect D1, CRect D2, INT Data1, INT Data2);
	void DrawTextShow(CDC* pDC, CRect D1, CRect D2, CRect D3, CRect D4, int Data1, int Data2, int Data3, int Data4);

private:

	void Create(int x, int y, int cx, int cy);
	void CountPoint(int nAngle, CPoint& pt, BOOL bPercent);

private:
	int m_x;
	int m_y;
	int m_cx;
	int m_cy;
	CRect m_rt;

	HBRUSH m_hBrushData1;
	HBRUSH m_hBrushData2;
	HBRUSH m_hBrushData3;
	HBRUSH m_hBrushData4;
	//HBRUSH m_hBrushData5;
	//HBRUSH m_hBrushData6;

};


//void DrawBingTu(CDC* pDC,
//	CRect& rc,
//	INT nLRDaDan,
//	INT nLRZhongDan,
//	INT nLRXiaoDan,
//	INT nLCDaDan,
//	INT nLCZhongDan,
//	INT nLCXiaoDan)
//{
//	DrawBing bingTu;
//	bingTu.Create(rc);
//	bingTu.Draw(pDC, nLRDaDan, nLRZhongDan, nLRXiaoDan, nLCDaDan, nLCZhongDan, nLCXiaoDan);
//}