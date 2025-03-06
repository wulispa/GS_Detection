#pragma once
#include<vector>

using namespace std;

class ScreenRect
{
public:
	//m:x�᷽��ľ��θ���
	//n:y�᷽��ľ��θ���
	//rect:���ھ���
	//line_offset:�ָ��߿��
	//type��0Ϊ����߿�1Ϊ����߿�2δ�޷ָ���
	ScreenRect(void);		
	void ScreenInit(int m, int n, CRect screenRect, int line_offset = 2, int type = 0);
	~ScreenRect(void);

	//��ȡָ������ (0~m-1, 0~n-1)
	CRect GetCRect(int x, int y);
	CRect GetCRect(int lx, int ly,int rx ,int ry);
private:
	//С���ζ�ά���� vector��Ϊ��
	vector< vector<CRect> > m_rectVector;
};

