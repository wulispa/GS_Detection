
// InfoSystemDlg.h: 头文件
//

#pragma once
#include"SQLInterface.h"

// CInfoSystemDlg 对话框
class CInfoSystemDlg : public CDialogEx
{
// 构造
public:
	CInfoSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数
	virtual ~CInfoSystemDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFOSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	SQLInterface SQL;
	vector<DateInfo>Info;
	CListCtrl m_list;
	CFont* m_font;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
	// 创建字体对象
	CFont font;
	afx_msg void OnBnClickedButton3();
	void ShowPage(int nPage);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();

	int m_nItemsPerPage = 8; // 每页显示的项数
	int m_nCurrentPage = 0;   // 当前页码
	bool m_bIsFirstPage;
	bool m_bIsLastPage;

	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
