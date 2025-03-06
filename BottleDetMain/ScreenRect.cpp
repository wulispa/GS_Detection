#include "pch.h"
#include "ScreenRect.h"

ScreenRect::ScreenRect()
{
}

void ScreenRect::ScreenInit(int m, int n, CRect screenRect,int line_offset, int type)
{
	CRect r(0,0,0,0);
	vector<vector <CRect> > ivec(m ,vector<CRect>(n, r));    //m*n的二维vector，所有元素为0
	m_rectVector = ivec;

	vector<vector<CRect>>().swap(ivec);

	switch(type){
		//0为有外边框
	case 0:
		{
			//小矩形总和
			int rect_sum_w = screenRect.Width()-line_offset*(n+1);
			int rect_sum_h = screenRect.Height()-line_offset*(m+1);

			//小矩形宽长
			int rect_w = rect_sum_w/n;
			int rect_h = rect_sum_h/m;

			//宽长余数
			int line_w = rect_sum_w%n;
			int line_h = rect_sum_h%m;

			int col = 0 ,row = 0;                //加到间隔中置1
			for(int i=0; i<m; i++)
			{
				if(col != line_h) col++;
				row = 1;
				for(int j=0; j<n; j++)
				{
					CRect r(
						line_offset*(j+1)+j*rect_w +row,
						line_offset*(i+1)+i*rect_h + col,
						line_offset*(j+1)+(j+1)*rect_w +row,
						line_offset*(i+1)+(i+1)*rect_h + col);
					if(row != line_w) row++;
					m_rectVector[i][j] = r;
					/*m_rectVector[i][j] = new CRect(
						line_offset*(j+1)+j*rect_w +row,
						line_offset*(i+1)+i*rect_h + col,
						line_offset*(j+1)+(j+1)*rect_w +row,
						line_offset*(i+1)+(i+1)*rect_h + col);*/
				}
			}
		}
		break;
		//1为无外边框
	case 1:
		{
			//小矩形总和
			int rect_sum_w = screenRect.Width()-line_offset*(n-1);
			int rect_sum_h = screenRect.Height()-line_offset*(m-1);

			//小矩形宽长
			int rect_w = rect_sum_w/n;
			int rect_h = rect_sum_h/m;

			//宽长余数
			int line_w = rect_sum_w%n;
			int line_h = rect_sum_h%m;

			int line = 0 ,row = 0;                //加到间隔中置1
			for(int i=0; i<m; i++)
			{
				if(line != line_h+1) line++;
				row = 1;
				for(int j=0; j<n; j++)
				{
					CRect r(
						line_offset*(j)+j*rect_w +row-1,
						line_offset*(i)+i*rect_h + line-1,
						line_offset*(j)+(j+1)*rect_w + row-1,
						line_offset*(i)+(i+1)*rect_h + line-1);
					if(row != line_w+1) row++;
					m_rectVector[i][j] = r;
					/*m_rectVector[i][j] = new CRect(
						line_offset*(j)+j*rect_w +row-1,
						line_offset*(i)+i*rect_h + line-1,
						line_offset*(j)+(j+1)*rect_w + row-1,
						line_offset*(i)+(i+1)*rect_h + line-1);*/
				}
			}
		}
		break;
		//2未无分割线
	case 2:
		{
			//小矩形总和
			int rect_sum_w = screenRect.Width();
			int rect_sum_h = screenRect.Height();

			//小矩形宽长
			int rect_w = rect_sum_w/n;
			int rect_h = rect_sum_h/m;

			//宽长余数
			int line_w = rect_sum_w%n;
			int line_h = rect_sum_h%m;

			int col = 0 ,row = 0;                //加到间隔中置1
			for(int i=0; i<m; i++)
			{
				for(int j=0; j<n; j++)
				{	
					CRect r(
						j*rect_w + row,
						i*rect_h + col,
						(j+1)*rect_w + 1 + row,
						(i+1)*rect_h + 1 + col);
					m_rectVector[i][j] = r;
					/*m_rectVector[i][j] = new CRect(
						j*rect_w + row,
						i*rect_h + col,
						(j+1)*rect_w + 1 + row,
						(i+1)*rect_h + 1 + col);*/
					if(row != line_w) row++;
				}
				if(col != line_h) col++;
				row = 0;
			}
		}
		break;
	}
}


ScreenRect::~ScreenRect(void)
{
	vector< vector<CRect> >().swap(m_rectVector);;
	
}

//获取指定矩形
CRect ScreenRect::GetCRect(int x, int y)
{	
	return m_rectVector[x][y];
}

//获取指定矩形
CRect ScreenRect::GetCRect(int lx, int ly,int rx ,int ry)
{	
	CRect rect(GetCRect(lx, ly).TopLeft(), GetCRect(rx, ry).BottomRight());

	return rect;
}

