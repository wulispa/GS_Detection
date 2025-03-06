#pragma once


// BeginDlg 对话框

#define TIME_TIP 200
#define TIMER_TIP 1
class BeginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BeginDlg)

public:
	BeginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BeginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BEGIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	CFont m_font;
	CStatic m_static;
	HBRUSH m_brushBack;


public:
	BOOL OnInitDialog();
	//virtual void OnTimer();
	int round = 3;
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
};
