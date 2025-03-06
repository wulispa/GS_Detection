#pragma once


// ChangePassWordDlg 对话框

class ChangePassWordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePassWordDlg)

public:
	ChangePassWordDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangePassWordDlg();
	CWnd* pwin;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT_PASS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPassworld();
	afx_msg void OnBnClickedPassword();
};
