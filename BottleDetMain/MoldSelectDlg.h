#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include "publicspace.h"
#include "DataManager.h"
#include "BtnST.h"

using namespace std;
// MoldSelectDlg 对话框

class MoldSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MoldSelectDlg)

public:
	MoldSelectDlg(CWnd* pParent, DataManager* pdata);   // 标准构造函数
	virtual ~MoldSelectDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOLD_SELECT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	bool Mold_state1, Mold_state2, Mold_state3, Mold_state4, Mold_state5, Mold_state6, Mold_state7, Mold_state8, Mold_state9, Mold_state10;
	bool Mold_state11, Mold_state12, Mold_state13, Mold_state14, Mold_state15, Mold_state16, Mold_state17, Mold_state18, Mold_state19, Mold_state20;
	bool Mold_state21, Mold_state22, Mold_state23, Mold_state24, Mold_state25, Mold_state26, Mold_state27, Mold_state28, Mold_state29, Mold_state30;
	bool Mold_state31, Mold_state32, Mold_state33, Mold_state34, Mold_state35, Mold_state36, Mold_state37, Mold_state38, Mold_state39, Mold_state40;
	bool Mold_state41, Mold_state42, Mold_state43, Mold_state44, Mold_state45, Mold_state46, Mold_state47, Mold_state48, Mold_state49, Mold_state50;
	bool Mold_state51, Mold_state52, Mold_state53, Mold_state54, Mold_state55, Mold_state56, Mold_state57, Mold_state58, Mold_state59, Mold_state60;
	bool Mold_state61, Mold_state62, Mold_state63, Mold_state64, Mold_state65, Mold_state66, Mold_state67, Mold_state68, Mold_state69, Mold_state70;
	bool Mold_state71, Mold_state72, Mold_state73, Mold_state74, Mold_state75, Mold_state76, Mold_state77, Mold_state78, Mold_state79, Mold_state80;
	bool Mold_state81, Mold_state82, Mold_state83, Mold_state84, Mold_state85, Mold_state86, Mold_state87, Mold_state88, Mold_state89, Mold_state90;
	bool Mold_state0;
	//public:
//	int T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
//	int T11, T12, T13, T14, T15, T16, T17, T18, T19, T20;
//	int T21, T22, T23, T24, T25, T26, T27, T28, T29, T30;
//	int T31, T32, T33, T34, T35, T36, T37, T38, T39, T40;
//	int T41, T42, T43, T44, T45, T46, T47, T48, T49, T50;
//	int T51, T52, T53, T54, T55, T56, T57, T58, T59, T60;
//	int T61, T62, T63, T64, T65, T66, T67, T68, T69, T70;
//	int T71, T72, T73, T74, T75, T76, T77, T78, T79, T0;
//	int T81, T82, T83, T84, T85, T86, T87, T88, T89, T90;
	CButtonST m_Mold1, m_Mold2, m_Mold3, m_Mold4, m_Mold5, m_Mold6, m_Mold7, m_Mold8, m_Mold9, m_Mold10,
		m_Mold11, m_Mold12, m_Mold13, m_Mold14, m_Mold15, m_Mold16, m_Mold17, m_Mold18, m_Mold19, m_Mold20,
		m_Mold21, m_Mold22, m_Mold23, m_Mold24, m_Mold25, m_Mold26, m_Mold27, m_Mold28, m_Mold29, m_Mold30,
		m_Mold31, m_Mold32, m_Mold33, m_Mold34, m_Mold35, m_Mold36, m_Mold37, m_Mold38, m_Mold39, m_Mold40,
		m_Mold41, m_Mold42, m_Mold43, m_Mold44, m_Mold45, m_Mold46, m_Mold47, m_Mold48, m_Mold49, m_Mold50,
		m_Mold51, m_Mold52, m_Mold53, m_Mold54, m_Mold55, m_Mold56, m_Mold57, m_Mold58, m_Mold59, m_Mold60,
		m_Mold61, m_Mold62, m_Mold63, m_Mold64, m_Mold65, m_Mold66, m_Mold67, m_Mold68, m_Mold69, m_Mold70,
		m_Mold71, m_Mold72, m_Mold73, m_Mold74, m_Mold75, m_Mold76, m_Mold77, m_Mold78, m_Mold79, m_Mold80,
		m_Mold81, m_Mold82, m_Mold83, m_Mold84, m_Mold85, m_Mold86, m_Mold87, m_Mold88, m_Mold89, m_Mold90;
	CButtonST m_Mold0;

public:
	CString Moldmodel_path;//模型路径
	CString MoldProfile_path;//配置文件路径
	BOOL OnMold;
	DataManager* m_pData;//参数管理
	vector<int> Selected;//选择的模号
	CString mold_str;

	CString GetArrayFromCstringBySep(const CString& str, const TCHAR cSep);
	vector<int> Str2Vec(string str);
	void SetButtonColor(CButtonST* butPtr, COLORREF rgbOut, COLORREF rgbFcous, COLORREF rgbIn);
	void SetButtonColor(CButtonST* butPtr, COLORREF color);//重载一次
		/************************************************
	*   功能：初始化字体
	*	参数：
	*	返回值：
	************************************************/
	void InitWindowFront();
	CFont* m_font;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButSelectExit();
	afx_msg void OnBnClickedButSelectSave();
	afx_msg void OnBnClickedButLoadMoldModel();
	void ShowSelectedMold();
	void SetMoldBtnState();
	void InitMoldBtnState();

public:
	afx_msg void OnBnClickedButMold1();
	afx_msg void OnBnClickedButMold2();
	afx_msg void OnBnClickedButMold3();
	afx_msg void OnBnClickedButMold4();
	afx_msg void OnBnClickedButMold5();
	afx_msg void OnBnClickedButMold6();
	afx_msg void OnBnClickedButMold7();
	afx_msg void OnBnClickedButMold8();
	afx_msg void OnBnClickedButMold9();
	afx_msg void OnBnClickedButMold10();
	afx_msg void OnBnClickedButMold11();
	afx_msg void OnBnClickedButMold12();
	afx_msg void OnBnClickedButMold13();
	afx_msg void OnBnClickedButMold14();
	afx_msg void OnBnClickedButMold15();
	afx_msg void OnBnClickedButMold16();
	afx_msg void OnBnClickedButMold17();
	afx_msg void OnBnClickedButMold18();
	afx_msg void OnBnClickedButMold19();
	afx_msg void OnBnClickedButMold20();
	afx_msg void OnBnClickedButMold21();
	afx_msg void OnBnClickedButMold22();
	afx_msg void OnBnClickedButMold23();
	afx_msg void OnBnClickedButMold24();
	afx_msg void OnBnClickedButMold25();
	afx_msg void OnBnClickedButMold26();
	afx_msg void OnBnClickedButMold27();
	afx_msg void OnBnClickedButMold28();
	afx_msg void OnBnClickedButMold29();
	afx_msg void OnBnClickedButMold30();
	afx_msg void OnBnClickedButMold31();
	afx_msg void OnBnClickedButMold32();
	afx_msg void OnBnClickedButMold33();
	afx_msg void OnBnClickedButMold34();
	afx_msg void OnBnClickedButMold35();
	afx_msg void OnBnClickedButMold36();
	afx_msg void OnBnClickedButMold37();
	afx_msg void OnBnClickedButMold38();
	afx_msg void OnBnClickedButMold39();
	afx_msg void OnBnClickedButMold40();
	afx_msg void OnBnClickedButMold41();
	afx_msg void OnBnClickedButMold42();
	afx_msg void OnBnClickedButMold43();
	afx_msg void OnBnClickedButMold44();
	afx_msg void OnBnClickedButMold45();
	afx_msg void OnBnClickedButMold46();
	afx_msg void OnBnClickedButMold47();
	afx_msg void OnBnClickedButMold48();
	afx_msg void OnBnClickedButMold49();
	afx_msg void OnBnClickedButMold50();
	afx_msg void OnBnClickedButMold51();
	afx_msg void OnBnClickedButMold52();
	afx_msg void OnBnClickedButMold53();
	afx_msg void OnBnClickedButMold54();
	afx_msg void OnBnClickedButMold55();
	afx_msg void OnBnClickedButMold56();
	afx_msg void OnBnClickedButMold57();
	afx_msg void OnBnClickedButMold58();
	afx_msg void OnBnClickedButMold59();
	afx_msg void OnBnClickedButMold60();
	afx_msg void OnBnClickedButMold61();
	afx_msg void OnBnClickedButMold62();
	afx_msg void OnBnClickedButMold63();
	afx_msg void OnBnClickedButMold64();
	afx_msg void OnBnClickedButMold65();
	afx_msg void OnBnClickedButMold66();
	afx_msg void OnBnClickedButMold67();
	afx_msg void OnBnClickedButMold68();
	afx_msg void OnBnClickedButMold69();
	afx_msg void OnBnClickedButMold70();
	afx_msg void OnBnClickedButMold71();
	afx_msg void OnBnClickedButMold72();
	afx_msg void OnBnClickedButMold73();
	afx_msg void OnBnClickedButMold74();
	afx_msg void OnBnClickedButMold75();
	afx_msg void OnBnClickedButMold76();
	afx_msg void OnBnClickedButMold77();
	afx_msg void OnBnClickedButMold78();
	afx_msg void OnBnClickedButMold79();
	afx_msg void OnBnClickedButMold80();
	afx_msg void OnBnClickedButMold81();
	afx_msg void OnBnClickedButMold82();
	afx_msg void OnBnClickedButMold83();
	afx_msg void OnBnClickedButMold84();
	afx_msg void OnBnClickedButMold85();
	afx_msg void OnBnClickedButMold86();
	afx_msg void OnBnClickedButMold87();
	afx_msg void OnBnClickedButMold88();
	afx_msg void OnBnClickedButMold89();
	afx_msg void OnBnClickedButMold90();
	afx_msg void OnBnClickedButMold0();
};
