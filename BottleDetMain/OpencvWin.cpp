#include "pch.h"
#include "OpencvWin.h"


OpencvWin::OpencvWin()
{
}

OpencvWin::~OpencvWin()
{

}

void OpencvWin::OpenWindow(CWnd* win)
{
	m_Win = win;

}

void OpencvWin::DispImage(Mat image)
{
	CRect m_rect;
	double ratio;
	CDC* pDC = m_Win->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	IplImage img = image;
	int w = image.cols;
	int h = image.rows;
	CvvImage cimg;
	cimg.CopyOf(&img);
	m_Win->GetClientRect(&rect);
	CPoint center = rect.CenterPoint();
	
	if (h > w)
	{
		m_rect.top = rect.top;
		m_rect.bottom = rect.bottom;
		ratio = (double)h / (double)rect.Height();
		m_rect.left = center.x - (int)((w /ratio) / 2);
		m_rect.right = center.x + (int)((w / ratio) / 2);
	}
	else {
		m_rect.left = rect.left;
		m_rect.right = rect.right;
		ratio = (double)w / (double)rect.Width();
		m_rect.top = center.y - (int)((h / ratio) / 2);
		m_rect.bottom = center.y + (int)((h / ratio) / 2);
	}
	cimg.DrawToHDC(hDC, &m_rect);
	m_Win->ReleaseDC(pDC);
}

void OpencvWin::ClearWindow()
{
	CDC* pDC = m_Win->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	m_Win->GetClientRect(&rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));
	m_Win->ReleaseDC(pDC);
}

Mat OpencvWin::PaintTxt(Mat& Image, string txt)
{
	putText(Image, txt, Point(60, 130), FONT_HERSHEY_SIMPLEX, 4, Scalar(0, 0, 255), 6, 8);

	return Image;

}

Mat OpencvWin::PaintTxt(Mat& Image, string txt, Point pos, Scalar clor)
{
	putText(Image, txt, pos, FONT_HERSHEY_SIMPLEX, 6, clor, 6, 8);

	return Image;
}

Mat OpencvWin::PaintRectangle(Mat& Image, Rect& rect, cv::Scalar clor)
{
	cv::rectangle(Image, rect, clor, 3, LINE_8, 0);
	return Image;
}

Mat OpencvWin::putTextZH(Mat& Image, const char* str, Point org, Scalar color, int fontsize, const char* fn, bool italic, bool underline)
{
	put11.putTextZH(Image, str, org,color, fontsize, "Î¢ÈíÑÅºÚ");
	return Image;
}

