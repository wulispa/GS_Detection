#pragma once


// SeekBNumberDlg 对话框

class SeekBNumberDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SeekBNumberDlg)

public:
	SeekBNumberDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SeekBNumberDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SeekBNumberDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_BatchNumber;
	afx_msg void OnBnClickedOk();
};
