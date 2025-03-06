#pragma once


// SeekSTimeDlg 对话框

class SeekSTimeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SeekSTimeDlg)

public:
	SeekSTimeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SeekSTimeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SeekSTimeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_RecordTime;
	afx_msg void OnBnClickedOk();
};
