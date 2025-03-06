#pragma once


// SeekDTimeDlg 对话框

class SeekDTimeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SeekDTimeDlg)

public:
	SeekDTimeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SeekDTimeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SeekDTimeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_ExpiringDate;
	afx_msg void OnBnClickedOk();
};
