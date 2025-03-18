
// BottleDetMainDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "BottleDetMain.h"
#include "BottleDetMainDlg.h"
#include "afxdialogex.h"
#include "CameraBasler.h"
#include "BeginDlg.h"

#include <iostream>
#include "MvCameraControl.h"
#include <vector>
#include "StateDlg.h"
#include "myLogger.h"
#include "PassCheck.h"
#include <FreeImage.h>
//#include"crypto.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


DWORD WINAPI Loading(LPVOID pthread)
{
	
	CBottleDetMainDlg* pwnd = (CBottleDetMainDlg*)pthread;
	LoginDlg Dlg(pwnd,pwnd->m_pData);  // 弹出登录对话框
	if (pwnd->StartRun())
	{
		HWND Starting = ::FindWindow(NULL, _T("启动中"));
		Dlg.DoModal();
		::SendMessage(Starting, WM_CLOSE, NULL, NULL);
		return 0;
	}
	else
	{
		HWND Starting = ::FindWindow(NULL, _T("启动中"));
		::SendMessage(Starting, WM_CLOSE, NULL, NULL);
	}

}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

//声明读写锁
CRITICAL_SECTION RESULT_MUTEX;		//瓶底锁
//CRITICAL_SECTION RESULT_MUTEX1;		//模号锁

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBottleDetMainDlg 对话框

DWORD WINAPI SaveThread(LPVOID pthread);
//DWORD WINAPI SaveThread1(LPVOID pthread);

CBottleDetMainDlg::CBottleDetMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOTTLEDETMAIN_DIALOG, pParent),
	m_font(nullptr),
	RunState(false),
	LockState(false),
	m_duration(0),
	b_Stop(false),
	n_hour(0),
	n_minute(0),
	n_second(0),
	PassLogin(false),
	num_good(0),
	num_bad(0),
	old_num(0),
	num_mold(0),
	num_ng1(0),
	num_ng2(0),
	num_ng3(0),
	num_ng4(0),
	oldNg1(0),
	oldNg2(0),
	oldNg3(0),
	oldNg4(0),
	ExitFlag(false),
	now_index(0),
	select_index(0),
	LastTime(0),
	StopShow(0),
	oldNumGood(0),
	oldNumBad(0),
	Step(0)
{
	if (IsProccessRunning(_T("BottleDetMain.exe"))) {
		KillProcess(_T("BottleDetMain.exe"));
	}
	//string target_lock = readAndDecryptFromFile();
	//string target = GetPass();
	//if (target_lock != target) {
	//	AfxMessageBox(TEXT("此电脑机器码未注册。"));
	//	KillProcess(_T("BottleDetMain.exe"));
	//}

	//int check = CheckPass();	
	//if (check != 1) {
	//	AfxMessageBox(TEXT("111"));
	//	//KillProcess(_T("BottleDetMain.exe"));
	//}
	//if (!m_pData->CamImages.empty()) {
	//	vector<Mat>().swap(m_pData->CamImages);
	//}

	//GetVolumeInformation("C:\\", volume, MAX_PATH, &serialNumber, &maxComponentLength, &fileSystemFlags, fileSystemName, MAX_PATH);
	//1647738086;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	ChangeFront = false;
	ImageWin = new OpencvWin();
	m_pData = new DataManager();
	m_pData->LoadBottleParam();
	m_pData->LoadBottleDetParam();
	m_pData->LoadSystemParam();
	hSaveThread=CreateThread(NULL, 0, SaveThread, this, 0, NULL);
	//hSaveThread1 = CreateThread(NULL, 0, SaveThread1, this, 0, NULL);

	InitializeCriticalSection(&RESULT_MUTEX);
	//InitializeCriticalSection(&RESULT_MUTEX1);

}

CBottleDetMainDlg::~CBottleDetMainDlg()
{
	DeleteObject(m_brushBack);
	DeleteObject(m_brushBule);

	ExitFlag = true;
	WaitForSingleObject(hSaveThread, INFINITE);//退出系统是结束线程
	//WaitForSingleObject(hSaveThread1, INFINITE);//退出系统是结束线程

	m_Detection->~Detection();
}

void CBottleDetMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUT_AUTO_DET, m_StartButton);
	DDX_Control(pDX, IDC_BUT_LOCK, m_LockButton);
	DDX_Control(pDX, IDC_BUT_SYSTEM_PARAM, m_SystemButton);
	DDX_Control(pDX, IDC_BUT_INQUIRE, m_SystemButton);
	DDX_Control(pDX, IDC_BUT_CAM_PARAM, m_CamButton);
	DDX_Control(pDX, IDC_BUT_DET_PARAM, m_DetButton);
	DDX_Control(pDX, IDC_BUT_CHANGE_CLASS, m_ChangeClsButton);
	DDX_Control(pDX, IDC_BUT_STAT, m_SearchButton);
	DDX_Control(pDX, IDC_BUT_EXIT, m_ExitButton);
	DDX_Control(pDX, IDC_LIST_BAD_BOTTLE, m_BadLogList);
	DDX_Control(pDX, IDC_BUT_CLEAR, m_zero);
	DDX_Control(pDX, IDC_IMAGE_WIN, m_picture);
}

BOOL CBottleDetMainDlg::IsProccessRunning(CString strProccess)
{
	BOOL BRunning = FALSE;
	PROCESSENTRY32 processEntry32;
	HANDLE toolHelp32Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	int i = 0;
	if (((int)toolHelp32Snapshot) != -1)
	{
		processEntry32.dwSize = sizeof(processEntry32);
		if (Process32First(toolHelp32Snapshot, &processEntry32))
		{
			do
			{

				CString str(L"");
				str = processEntry32.szExeFile;
				if (str == strProccess)
				{
					i += 1;
				}
				if (i == 2) {
					BRunning = TRUE;
					AfxMessageBox(L"程序正在运行，正在为您重启。");
					//AfxMessageBox(_T("程序正在运行，正在为您重启。"));
					break;
				}

			}

			while (Process32Next(toolHelp32Snapshot, &processEntry32));
		}
		CloseHandle(toolHelp32Snapshot);
	}
	return BRunning;
}

BOOL CBottleDetMainDlg::KillProcess(CString sExeName)
{
	BOOL BKilling = FALSE;
	HANDLE hSnapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapShot == 0) {
		AfxMessageBox(L"获取进程信息失败！");
		return FALSE;
	}

	PROCESSENTRY32 thePE;
	thePE.dwSize = sizeof(PROCESSENTRY32);


	//遍历正在运行的第一个系统进程
	bool Status = Process32First(hSnapShot, &thePE);
	bool bHaveFlag = false;
	DWORD ProcessID = 0;


	while (Status)
	{
		//遍历正在运行的下一个系统进程  
		Status = Process32Next(hSnapShot, &thePE);
		//找到相应的进程 **.exe

		CString sFindName = thePE.szExeFile;
		//CString sTemp = sExeName.Mid(0, sFindName.GetLength());

		if (sFindName == sExeName)
		{
			bHaveFlag = true;
			ProcessID = thePE.th32ProcessID;


			//结束指定的进程 ProcessID
			if (!TerminateProcess(OpenProcess(PROCESS_TERMINATE || PROCESS_QUERY_INFORMATION, false, ProcessID), 0))
			{
				//AfxMessageBox(L"无法终止指定的进程！");
				break;
			}
			else
			{
				BKilling = TRUE;
				//AfxMessageBox(L"正在重新进入，请稍后。");
				break;
			}
		}
	}
	CloseHandle(hSnapShot);
	return BKilling;
}


CString CBottleDetMainDlg::GetCStrProductBatch()
{
	return CStrProductBatch;
}

void CBottleDetMainDlg::UpdateBtnPic()
{
	//自动检测
	if (GetDlgItem(IDC_BUT_AUTO_DET)->IsWindowEnabled()
		&& GetDlgItem(IDC_BUT_CAM_PARAM)->IsWindowEnabled()) //自动检测on
	{
		hBmp1 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_AUTO_DETON));
		m_StartButton.SetBitmap(hBmp1);
		::DeleteObject(hBmp1);
	}
	else if (GetDlgItem(IDC_BUT_AUTO_DET)->IsWindowEnabled()
		&& !GetDlgItem(IDC_BUT_CAM_PARAM)->IsWindowEnabled()) //停止检测on
	{
		hBmp2 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STOPON));
		m_StartButton.SetBitmap(hBmp2);		
		::DeleteObject(hBmp2);
	}
	else if (!GetDlgItem(IDC_BUT_AUTO_DET)->IsWindowEnabled()
		&& GetDlgItem(IDC_BUT_CAM_PARAM)->IsWindowEnabled()) //自动检测off
	{
		hBmp3 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_AUTO_DETOFF));
		m_StartButton.SetBitmap(hBmp3);
		::DeleteObject(hBmp3);
	}
	else //停止检测off
	{
		hBmp4 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STOPOFF));
		m_StartButton.SetBitmap(hBmp4);
		::DeleteObject(hBmp4);
	}
	//锁定
	if (GetDlgItem(IDC_BUT_AUTO_DET)->IsWindowEnabled()
		&&GetDlgItem(IDC_BUT_LOCK)->IsWindowEnabled()) //锁定on
	{
		hBmp5 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_LOCKON));
		m_LockButton.SetBitmap(hBmp5);
		::DeleteObject(hBmp5);
	}
	else //解锁on
	{
		hBmp6 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_UNLOCKON));
		m_LockButton.SetBitmap(hBmp6);
		::DeleteObject(hBmp6);
	}
	//检测参数
	if (GetDlgItem(IDC_BUT_DET_PARAM)->IsWindowEnabled()) {
		hBmp7 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_DET_PARAON));
		m_DetButton.SetBitmap(hBmp7);
		::DeleteObject(hBmp7);
	}
	else {
		hBmp8 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_DET_PARAOFF));
		m_DetButton.SetBitmap(hBmp8);
		::DeleteObject(hBmp8);
	}

	//相机参数
	if (GetDlgItem(IDC_BUT_CAM_PARAM)->IsWindowEnabled()) {
		hBmp9 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CAM_PARAON));
		m_CamButton.SetBitmap(hBmp9);
		::DeleteObject(hBmp9);
	}
	else {
		hBmp10 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CAM_PARAOFF));
		m_CamButton.SetBitmap(hBmp10);
		::DeleteObject(hBmp10);
	}

	//系统参数
	if (GetDlgItem(IDC_BUT_SYSTEM_PARAM)->IsWindowEnabled()) {
		hBmp11 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_SYS_PARAON));
		m_SystemButton.SetBitmap(hBmp11);
		::DeleteObject(hBmp11);
	}
	else {
		hBmp12 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_SYS_PARAOFF));
		m_SystemButton.SetBitmap(hBmp12);
		::DeleteObject(hBmp12);
	}

	//退出系统
	if (GetDlgItem(IDC_BUT_EXIT)->IsWindowEnabled()) {
		hBmp13 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_EXITON));
		m_ExitButton.SetBitmap(hBmp13);
		::DeleteObject(hBmp13);
	}
	else {
		hBmp14 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_EXITOFF));
		m_ExitButton.SetBitmap(hBmp14);
		::DeleteObject(hBmp14);
	}

	//清零
	if (!GetDlgItem(IDC_BUT_CLEAR)->IsWindowEnabled()) {
		hBmp15 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ZEROOFF));
		m_zero.SetBitmap(hBmp15);
		::DeleteObject(hBmp15);
	}
	else {
		hBmp16 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_ZEROON));
		m_zero.SetBitmap(hBmp16);
		::DeleteObject(hBmp16);
	}
	//切换品种
	if (GetDlgItem(IDC_BUT_CHANGE_CLASS)->IsWindowEnabled()) {
		hBmp17 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CHANGECLASS_ON));
		m_ChangeClsButton.SetBitmap(hBmp17);
		::DeleteObject(hBmp17);
	}
	else {
		hBmp18 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CHANGECLASS_OFF));
		m_ChangeClsButton.SetBitmap(hBmp18);
		::DeleteObject(hBmp18);
	}
	//数据统计
	if (GetDlgItem(IDC_BUT_STAT)->IsWindowEnabled()) {
		hBmp19 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STATE_ON));
		m_SearchButton.SetBitmap(hBmp19);
		::DeleteObject(hBmp19);
	}
	else {
		hBmp20 = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_STATE_OFF));
		m_SearchButton.SetBitmap(hBmp20);
		::DeleteObject(hBmp20);
	}
}

void CBottleDetMainDlg::ResizeWindow()
{
	float fsp[2];
	POINT Newp; //获取现在对话框的大小
	CRect recta;
	GetClientRect(&recta);     //取客户区大小  
	Newp.x = recta.right - recta.left;
	Newp.y = recta.bottom - recta.top;
	fsp[0] = (float)Newp.x / Old.x;
	fsp[1] = (float)Newp.y / Old.y;
	CRect Rect;
	int woc;
	CPoint OldTLPoint, TLPoint; //左上角
	CPoint OldBRPoint, BRPoint; //右下角
	HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);  //列出所有控件  
	while (hwndChild)
	{
		woc = ::GetDlgCtrlID(hwndChild);//取得ID
		GetDlgItem(woc)->GetWindowRect(Rect);
		ScreenToClient(Rect);
		OldTLPoint = Rect.TopLeft();
		TLPoint.x = long(OldTLPoint.x * fsp[0]);
		TLPoint.y = long(OldTLPoint.y * fsp[1]);
		OldBRPoint = Rect.BottomRight();
		BRPoint.x = long(OldBRPoint.x * fsp[0]);
		BRPoint.y = long(OldBRPoint.y * fsp[1]);
		Rect.SetRect(TLPoint, BRPoint);
		GetDlgItem(woc)->MoveWindow(Rect, TRUE);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
	}
	
	Old = Newp;
	if (ChangeFront) {
		delete(m_font);
		m_font = new CFont();
		InitWindowFront();
		UpdateBtnPic();

	}
	else
	{
		ChangeFront=true;
	}
	

}

void CBottleDetMainDlg::InitControlColor(int ID, COLORREF rgb)
{
	CDC* pDC = m_picture.GetDC();
	CRect mrect;
	GetDlgItem(ID)->GetClientRect(&mrect);//获取控件大小
	CBrush BrushBack;//画刷
	BrushBack.CreateSolidBrush(rgb);//
	FillRect(pDC->GetSafeHdc(), &mrect, BrushBack);
	DeleteObject(BrushBack);//释放画刷
	//DeleteObject(GetDlgItem(ID)->GetDC()->GetSafeHdc());
	ReleaseDC(pDC);
}

void CBottleDetMainDlg::SetButtonColor(CButtonST* butPtr, COLORREF rgbOut, COLORREF rgbFcous, COLORREF rgbIn)
{
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_OUT, rgbOut);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, rgbFcous);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_IN, rgbIn);
}

void CBottleDetMainDlg::SetButtonColor(CButtonST* butPtr, COLORREF color)
{
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_OUT, color);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, color);
	butPtr->SetColor(CButtonST::BTNST_COLOR_BK_IN, color);
}

BEGIN_MESSAGE_MAP(CBottleDetMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUT_AUTO_DET, &CBottleDetMainDlg::OnBnClickedButAutoDet)
	ON_BN_CLICKED(IDC_BUT_LOCK, &CBottleDetMainDlg::OnBnClickedButLock)
	ON_BN_CLICKED(IDC_BUT_DET_PARAM, &CBottleDetMainDlg::OnBnClickedButDetParam)
	ON_BN_CLICKED(IDC_BUT_CAM_PARAM, &CBottleDetMainDlg::OnBnClickedButCamParam)
	ON_BN_CLICKED(IDC_BUT_CHANGE_CLASS, &CBottleDetMainDlg::OnBnClickedButChangeClass)
	ON_BN_CLICKED(IDC_BUT_SYSTEM_PARAM, &CBottleDetMainDlg::OnBnClickedButSystemParam)
	ON_BN_CLICKED(IDC_BUT_STAT, &CBottleDetMainDlg::OnBnClickedButStat)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUT_EXIT, &CBottleDetMainDlg::OnBnClickedButExit)
	ON_BN_CLICKED(IDC_BUT_CLEAR, &CBottleDetMainDlg::OnBnClickedButClear)
	ON_LBN_SELCHANGE(IDC_LIST_BAD_BOTTLE, &CBottleDetMainDlg::OnLbnSelchangeListBadBottle)
	ON_LBN_DBLCLK(IDC_LIST_BAD_BOTTLE, &CBottleDetMainDlg::OnLbnDblclkListBadBottle)
	//ON_BN_CLICKED(IDC_BUT_PINGDI, &CBottleDetMainDlg::OnBnClickedButPingdi)
	//ON_BN_CLICKED(IDC_BUT_MOHAO, &CBottleDetMainDlg::OnBnClickedButMohao)
	ON_WM_WINDOWPOSCHANGING()
	ON_BN_CLICKED(IDC_BUTTON4, &CBottleDetMainDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CBottleDetMainDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUT_User_Management, &CBottleDetMainDlg::OnBnClickedButUserManagement)
END_MESSAGE_MAP()


// CBottleDetMainDlg 消息处理程序

void CBottleDetMainDlg::TimeStart()
{
	if (b_Stop)
		KillTimer(N_TIMER_SEC);
	b_Stop = false;
	SetTimer(N_TIMER_SEC, N_TIME_SEC, NULL);
	SetTimer(N_TIMER_SHOW, N_TIME_SHOW, NULL);
	//LockTimeStart();
}

void CBottleDetMainDlg::LockTimeStart()
{
	if (m_pData->GetSystemParam()->AutoLock == "TRUE") {
		//SetTimer(N_TIMER_SEC, N_TIME_SEC, NULL);
		if (m_pData->GetSystemParam()->AutoLockTime > 0) {
			SetTimer(N_TIMER_LOCK, m_pData->GetSystemParam()->AutoLockTime * 60000, NULL);
		}
		else {
			AfxMessageBox(TEXT("未设置锁定时间"));
		}
	}
}

void CBottleDetMainDlg::TimeStop()
{
	b_Stop = !b_Stop;
	if (b_Stop) {
		KillTimer(N_TIMER_SEC);
		KillTimer(N_TIMER_SHOW);
		int h1, h2, m1, m2, s1, s2;
		h1 = n_hour / 10;
		h2 = n_hour % 10;
		m1 = n_minute / 10;
		m2 = n_minute % 10;
		s1 = n_second / 10;
		s2 = n_second % 10;
		s_hour.Format(_T("%d%d"), h1, h2);
		s_minute.Format(_T("%d%d"), m1, m2);
		s_second.Format(_T("%d%d"), s1, s2);
		//UpdateData(FALSE);
	}
}

void CBottleDetMainDlg::LockTimeStop()
{
	KillTimer(N_TIMER_LOCK);
}

void CBottleDetMainDlg::TimeReset()
{
	n_hour = 0;
	n_minute = 0;
	n_second = 0;
	m_duration = 0;
	b_Stop = false;
}

void CBottleDetMainDlg::UpdateLocalTime()
{
	SYSTEMTIME st;
	CString strDate, strTime;
	GetLocalTime(&st);
	strTime.Format(TEXT("当前时间：%2d:%2d:%2d"), st.wHour, st.wMinute, st.wSecond);
	SetDlgItemText(IDC_LOCAL_TIME_BOX, strTime);
}

void CBottleDetMainDlg::UpdateDataSat(int num_OK, int num_NG)
{
	SYSTEMTIME st;
	CString strYear, strMoth ,strDay,strHour;
	GetLocalTime(&st);
	strYear.Format(TEXT("%d"), st.wYear);
	strMoth.Format(TEXT("%d"), st.wMonth);
	strDay.Format(TEXT("%d"), st.wDay);
	strHour.Format(TEXT("%d"), st.wHour);
	string m_year = CT2A(strYear.GetString());
	string m_month = CT2A(strMoth.GetString());
	string m_day = CT2A(strDay.GetString());
	string m_hour = CT2A(strHour.GetString());

	//刷新年份
	m_DataStat.UpdateYear(st.wYear);
	int ok, ng;
	if (num_OK < oldNumGood) {
		ok = num_OK;
	}
	else
	{
		ok = num_OK - oldNumGood;
	}
	oldNumGood = num_OK;
	if (num_NG < oldNumBad) {
		ng = num_NG;
	}
	else
	{
		ng = num_NG - oldNumBad;
	}
	oldNumBad = num_NG;
	//m_DataStat.WriteNodeTxt(strYear, strMoth, strDay, TEXT("OK"), ok);
	//m_DataStat.WriteNodeTxt(strYear, strMoth, strDay, TEXT("NG"), ng);
	//insertData(m_year, m_month, m_day, "ok", ok);
	//insertData(m_year, m_month, m_day, "ng", ng);
	data.insertData(m_year, m_month, m_day, m_hour, "ok", ok);

}

void CBottleDetMainDlg::UpdateDataSat(int num_OK, int num_NG1, int num_NG2, int num_NG3, int num_NG4)
{
	SYSTEMTIME st;
	CString strYear, strMoth, strDay, strHour;
	GetLocalTime(&st);
	strYear.Format(TEXT("%d"), st.wYear);
	strMoth.Format(TEXT("%d"), st.wMonth);
	strDay.Format(TEXT("%d"), st.wDay);
	strHour.Format(TEXT("%d"), st.wHour);
	string m_year = CT2A(strYear.GetString());
	string m_month = CT2A(strMoth.GetString());
	string m_day = CT2A(strDay.GetString());
	string m_hour = CT2A(strHour.GetString());

	//刷新年份
	m_DataStat.UpdateYear(st.wYear);
	int ok, ng1, ng2, ng3, ng4;
	if (num_OK < oldNumGood) {
		ok = num_OK;
	}
	else
	{
		ok = num_OK - oldNumGood;
	}
	oldNumGood = num_OK;
	if (num_NG1 < oldNg1) {
		ng1 = num_NG1;
	}
	else
	{
		ng1 = num_NG1 - oldNg1;
	}
	oldNg1 = num_NG1;

	if (num_NG2 < oldNg2) {
		ng2 = num_NG2;
	}
	else
	{
		ng2 = num_NG2 - oldNg2;
	}
	oldNg2 = num_NG2;

	if (num_NG3 < oldNg3) {
		ng3 = num_NG3;
	}
	else
	{
		ng3 = num_NG3 - oldNg3;
	}
	oldNg3 = num_NG3;

	if (num_NG4 < oldNg4) {
		ng4 = num_NG4;
	}
	else
	{
		ng4 = num_NG4 - oldNg4;
	}
	oldNg4 = num_NG4;
	data.insertData(m_year, m_month, m_day, m_hour, "ok", ok);
	data.insertData(m_year, m_month, m_day, m_hour, "ng1", ng1);
	data.insertData(m_year, m_month, m_day, m_hour, "ng2", ng2);
	data.insertData(m_year, m_month, m_day, m_hour, "ng3", ng3);
	data.insertData(m_year, m_month, m_day, m_hour, "ng4", ng4);
}

void CBottleDetMainDlg::UpDateDetectTime(int n_time)
{
	CString str;
	str.Format(TEXT("检测耗时:%dms"), n_time);
	SetDlgItemText(IDC_DET_TIME_BOX, str);
	//UpdateWindow();
}

BOOL CBottleDetMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	name = nullptr;

	//HANDLE hThreadTip = CreateThread(NULL, 0, Loading, NULL, 0, NULL);
	// 将“关于...”菜单项添加到系统菜单中。

//#pragma region 设置全屏
//	 // 获取屏幕的宽度和高度
//	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // 屏幕宽度
//	int screenHeight = GetSystemMetrics(SM_CYSCREEN); // 屏幕高度
//	// 设置对话框窗口的大小为屏幕大小
//	MoveWindow(0, 0, screenWidth, screenHeight);
//	// 修改窗口样式为无边框窗口
//	LONG style = GetWindowLong(m_hWnd, GWL_STYLE);
//	style &= ~WS_CAPTION;        // 移除标题栏
//	style &= ~WS_THICKFRAME;     // 移除窗口边框
//	style |= WS_POPUP;           // 设置为弹出窗口（无边框）
//	SetWindowLong(m_hWnd, GWL_STYLE, style);
//	// 设置窗口为最前面
//	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
//#pragma endregion 



	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	if (!m_pData->CamImages.empty()) {
		vector<Mat>().swap(m_pData->CamImages);
	}

	// TODO: 在此添加额外的初始化代码
	CRect rect;
	GetClientRect(&rect);//取客户区大小

	m_font = new CFont();//创建字体工具
	InitWindowFront();
	//m_StartButton.SubclassDlgItem(IDC_BUT_AUTO_DET, this);
	//m_StartButton.SetBitmaps(IDB_AUTO_DETON, RGB(0, 0, 0));
	//m_StartButton.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, 30);
	UpdateBtnPic();
	Old.x = rect.right - rect.left;
	Old.y = rect.bottom - rect.top;
	m_brushBack = CreateSolidBrush(RGB(157, 172, 253));
	m_brushBule = CreateSolidBrush(RGB(40, 2, 247));
	ImageWin->OpenWindow(GetDlgItem(IDC_IMAGE_WIN));

	m_DataStat.OpenFile(TEXT("DataSave.xml"));
	//if (Step == 0) {
	//	GetDlgItem(IDC_BUT_PINGDI)->EnableWindow(FALSE);
	//	GetDlgItem(IDC_BUT_MOHAO)->EnableWindow(TRUE);
	//}
	//else {
	//	//Step = 1;
	//	GetDlgItem(IDC_BUT_PINGDI)->EnableWindow(TRUE);
	//	GetDlgItem(IDC_BUT_MOHAO)->EnableWindow(FALSE);
	//}

	//HWND Starting = ::FindWindow(NULL, _T("启动中"));
	//::SendMessage(Starting, WM_CLOSE, NULL, NULL);
	//CloseHandle(hThreadTip);
	//Sleep(500);
	UpdateBottleClass();

	SetStopStyle();
	m_Detection = new Detection(m_pData,this);

	SetTimer(N_TIME_LOCALSHOW, N_TIME_SEC, NULL);
	SetTimer(N_TIMER_WRITE_STAT, N_TIME_WRITE_STAT, NULL);
	//m_StartButton.SetFaceColor(RGB(128, 128, 128), true);
	LockTimeStart();

	//OnBnClickedButAutoDet();
	GetDlgItem(IDC_BUT_CLEAR)->ShowWindow(FALSE);
	GetDlgItem(IDC_LIST_BAD_BOTTLE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BAD_BOTTLE_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_CLASS_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_CHANGE_CLASS)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_INQUIRE)->ShowWindow(FALSE);
	GetDlgItem(IDC_NUM_TOTAL)->ShowWindow(FALSE);
	GetDlgItem(IDC_MAKING_NUMBER)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBottleDetMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBottleDetMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//绘制背景
		CRect rect;
		CPaintDC dc(this);
		GetClientRect(rect);
		dc.FillSolidRect(rect, RGB(157, 172, 253));
		InitControlColor(IDC_IMAGE_WIN, RGB(0, 0, 0));
		CDialogEx::OnPaint();
		//ReleaseDC(dc);

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBottleDetMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBottleDetMainDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: 在此处添加消息处理程序代码
	if (nType == SIZE_RESTORED || nType == SIZE_MAXIMIZED) {
		ResizeWindow();
	}
}

HBRUSH CBottleDetMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_CLASS_BOX
		|| pWnd->GetDlgCtrlID() == IDC_SPEED_BOX
		|| pWnd->GetDlgCtrlID() == IDC_DET_TIME_BOX
		|| pWnd->GetDlgCtrlID() == IDC_LOCAL_TIME_BOX
		|| pWnd->GetDlgCtrlID() == IDC_RUN_TIME_BOX
		|| pWnd->GetDlgCtrlID() == IDC_SYSTEEM_BOX
		|| pWnd->GetDlgCtrlID() == IDC_NUM_BAD
		|| pWnd->GetDlgCtrlID() == IDC_NUM_BAD_RATIO
		|| pWnd->GetDlgCtrlID() == IDC_NUM_TOTAL
		|| pWnd->GetDlgCtrlID() == IDC_STATIC_PRODUCT_BATCH
		|| pWnd->GetDlgCtrlID() == IDC_NUM_MOLD
		|| pWnd->GetDlgCtrlID() == IDC_NUM_MOLD_RATIO
		|| pWnd->GetDlgCtrlID() == IDC_DET_BOX
		|| pWnd->GetDlgCtrlID() == IDC_BAD_BOTTLE_BOX
		|| pWnd->GetDlgCtrlID() == IDC_NUM_MOLD_RATIO2
		|| pWnd->GetDlgCtrlID() == IDC_STATIC_UP
		|| pWnd->GetDlgCtrlID() == IDC_NUM_BAD_RATIO2
		|| pWnd->GetDlgCtrlID() == IDC_NUM_MOLD_RATIO3
		|| pWnd->GetDlgCtrlID() == IDC_STATIC_DOWN

		)
	{
		pDC->SetTextColor(RGB(40, 2, 247));
		pDC->SetBkColor(RGB(157, 172, 253));//设置文本背景颜色
		hbr = HBRUSH(m_brushBack);

	}
	else if (
		pWnd->GetDlgCtrlID() == IDC_DEADLINE
		|| pWnd->GetDlgCtrlID() == IDC_MAKING_NUMBER
		|| pWnd->GetDlgCtrlID() == IDC_EDIT_PRODUCT_BATCH
		|| pWnd->GetDlgCtrlID() == IDC_UP_READ_NUMBER
		|| pWnd->GetDlgCtrlID() == IDC_UP_READ_CODE
		|| pWnd->GetDlgCtrlID() == IDC_DOWN_READ_NUMBER
		|| pWnd->GetDlgCtrlID() == IDC_DOWN_READ_CODE

		) 
	{
		pDC->SetTextColor(RGB(157, 172, 253));
		pDC->SetBkColor(RGB(40, 2, 247));//设置文本背景颜色
		hbr = HBRUSH(m_brushBule);
	}
	//DeleteObject(m_brushBack);
	//DeleteObject(m_brushBack);
	//DeleteObject(hbr);
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
VOID CBottleDetMainDlg::InitWindowFront()
{
	//delete(m_font);
	//DeleteObject(m_font);

	//m_font = new CFont();

	GetClientRect(&winRect);
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 0;
	lfCtrl.lfHeight = winRect.Height() / 42;
	lfCtrl.lfItalic = false;
	lfCtrl.lfUnderline = false;
	lfCtrl.lfStrikeOut = false;
	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lfCtrl.lfFaceName, L"黑体");
	lfCtrl.lfWeight = FW_HEAVY;
	m_font->CreateFontIndirectW(&lfCtrl);
	GetDlgItem(IDC_DET_BOX)->SetFont(m_font);
	GetDlgItem(IDC_CLASS_BOX)->SetFont(m_font);
	GetDlgItem(IDC_DET_TIME_BOX)->SetFont(m_font);
	GetDlgItem(IDC_LIST_BAD_BOTTLE)->SetFont(m_font);
	GetDlgItem(IDC_LOCAL_TIME_BOX)->SetFont(m_font);
	GetDlgItem(IDC_RUN_TIME_BOX)->SetFont(m_font);
	GetDlgItem(IDC_SPEED_BOX)->SetFont(m_font);
	GetDlgItem(IDC_SYSTEEM_BOX)->SetFont(m_font);
	GetDlgItem(IDC_BAD_BOTTLE_BOX)->SetFont(m_font);
	GetDlgItem(IDC_NUM_BAD)->SetFont(m_font);
	GetDlgItem(IDC_NUM_BAD_RATIO)->SetFont(m_font);
	GetDlgItem(IDC_NUM_TOTAL)->SetFont(m_font);
	GetDlgItem(IDC_STATIC_PRODUCT_BATCH)->SetFont(m_font);
	GetDlgItem(IDC_NUM_MOLD)->SetFont(m_font);
	GetDlgItem(IDC_NUM_MOLD_RATIO)->SetFont(m_font);
	GetDlgItem(IDC_NUM_MOLD_RATIO2)->SetFont(m_font);
	GetDlgItem(IDC_STATIC_UP)->SetFont(m_font);
	GetDlgItem(IDC_STATIC_DOWN)->SetFont(m_font);
	GetDlgItem(IDC_NUM_BAD_RATIO2)->SetFont(m_font);
	GetDlgItem(IDC_NUM_MOLD_RATIO3)->SetFont(m_font);


	//GetDlgItem(IDC_BUT_AUTO_DET)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_LOCK)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_CAM_PARAM)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_CHANGE_CLASS)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_SYSTEM_PARAM)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_EXIT)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_STAT)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_DET_PARAM)->SetFont(m_font);
	GetDlgItem(IDC_DEADLINE)->SetFont(m_font);
	GetDlgItem(IDC_DOWN_READ_NUMBER)->SetFont(m_font);
	GetDlgItem(IDC_DOWN_READ_CODE)->SetFont(m_font);
	GetDlgItem(IDC_DEADLINE)->SetFont(m_font);
	GetDlgItem(IDC_EDIT_PRODUCT_BATCH)->SetFont(m_font);
	GetDlgItem(IDC_UP_READ_NUMBER)->SetFont(m_font);	
	GetDlgItem(IDC_UP_READ_CODE)->SetFont(m_font);
	//***************************按钮
	//GetDlgItem(IDC_BUT_PINGDI)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_MOHAO)->SetFont(m_font);

	DeleteObject(m_font);
	return VOID();
}

void CBottleDetMainDlg::show_image(cv::Mat& image, int result)
{
	ImageWin->DispImage(image);


}

void CBottleDetMainDlg::show_image(cv::Mat& image, int result, vector<cv::Rect> points)
{

	Mat show_image;
	if (image.channels() != 3)
	{
		show_image = Trans2RGB(image);
	}
	else
	{
		//show_image = image;
		show_image = image.clone();
	}
	if (result == 1)
	{
		ImageWin->PaintTxt(show_image, "OK");
	}
	else
	{
		ImageWin->PaintTxt(show_image, "NG");
		for (int index = 0; index < points.size(); index++)
		{
			ImageWin->PaintRectangle(show_image, points[index], Scalar(0, 0, 255));

		}
	}
	ImageWin->DispImage(show_image);
}

void CBottleDetMainDlg::show_image(cv::Mat image, int result, vector<cv::Rect> points,
	string detect_ID)
{
	Mat show_image(image.rows, image.cols, CV_8UC3, Scalar(0, 0, 0));
	if (image.channels() != 3)
	{
		show_image = Trans2RGB(image);
	}
	else
	{
		
		//show_image = image;
		show_image = image.clone();
		//image.copyTo(show_image);
		//show_image=cv::Mat::zeros(image.rows, image.cols, CV_8UC3);
		//image.copyTo(show_image);
	}
	if (result == 1)
	{
		ImageWin->PaintTxt(show_image, "OK");
	}
	else
	{
		ImageWin->PaintTxt(show_image, "NG");
		for (int index = 0; index < points.size(); index++)
		{
			ImageWin->PaintRectangle(show_image, points[index], Scalar(0, 0, 255));
		}
	}
	if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON") {
		//putText(show_image, m_pData->GetSystemParam()->TargetID, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
		putText(show_image, m_pData->GetBottleDetParam()->SelectedMold, Point(600, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
		vector<int> TargetID = Str2Vec(m_pData->GetBottleDetParam()->SelectedMold);
		int detect_id = str2int(detect_ID);
		if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end())
		{
			putText(show_image, detect_ID, Point(600, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 3, 3);
		}
		else
		{
			putText(show_image, detect_ID, Point(600, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
		}
	}
	
	ImageWin->DispImage(show_image);
}

void CBottleDetMainDlg::show_image(cv::Mat image, int result, vector<cv::Rect> points,
	string detect_ID, string Name)
{
	Mat show_image(image.rows, image.cols, CV_8UC3, Scalar(0, 0, 0));
	if (image.channels() != 3)
	{
		show_image = Trans2RGB(image);
	}
	else
	{

		//show_image = image;
		show_image = image.clone();
		//image.copyTo(show_image);
		//show_image=cv::Mat::zeros(image.rows, image.cols, CV_8UC3);
		//image.copyTo(show_image);
	}
	//if (result == 1)
	//{
	//	//putText(show_image, "good", Point(60, 250), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 3, 3);
	//	/*ImageWin->putTextZH(show_image, "良品", Point(60, 250), Scalar(255, 0, 0), 60);
	//	ImageWin->PaintTxt(show_image, "OK");*/
	//}
	//else
	//{
	//	//putText(show_image, Name, Point(60, 250), FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 3, 3);
	//	//const char* name = nullptr;
	//	name = Name.c_str();
	//	ImageWin->putTextZH(show_image, name, Point(60, 250), Scalar(255, 0, 0), 60);
	//	ImageWin->PaintTxt(show_image, "NG");
	//	for (int index = 0; index < points.size(); index++)
	//	{
	//		ImageWin->PaintRectangle(show_image, points[index], Scalar(0, 0, 255));
	//	}
	//}
	//if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON") {
	//	//putText(show_image, m_pData->GetSystemParam()->TargetID, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
	//	putText(show_image, m_pData->GetBottleDetParam()->SelectedMold, Point(600, 50),
	//		FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
	//	vector<int> TargetID = Str2Vec(m_pData->GetBottleDetParam()->SelectedMold);
	//	int detect_id = str2int(detect_ID);
	//	if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end())
	//	{
	//		putText(show_image, detect_ID, Point(600, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 3, 3);
	//	}
	//	else
	//	{
	//		putText(show_image, detect_ID, Point(600, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
	//	}
	//}
	////Point(60, 150), FONT_HERSHEY_SIMPLEX, 4, Scalar(0, 0, 255), 6, 8
	ImageWin->DispImage(show_image);

}

Mat CBottleDetMainDlg::Trans2RGB(Mat& image)
{
	cv::Mat three_channel = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);
	vector<cv::Mat> channels;
	for (int i = 0; i < 3; i++)
	{
		channels.push_back(image);
	}
	merge(channels, three_channel);
	return three_channel;
}

vector<int> CBottleDetMainDlg::Str2Vec(string str)
{
	int start = 0;
	int num = 0;
	vector<int> nums;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			string temp = str.substr(start, i - start);
			nums.push_back(atoi(temp.c_str()));
			num++;
			start = i + 1;
		}
	}
	string temp = str.substr(start, str.size() - start + 1);
	nums.push_back(atoi(temp.c_str()));
	return nums;
}

int CBottleDetMainDlg::str2int(string str)
{
	stringstream stream;     //声明一个stringstream变量
	int n;
	//string转int
	stream << str;     //向stream中插入字符串
	stream >> n;
	return n;
}

void saveMatImageWithFreeImage(const cv::Mat& image, const std::string& filename) {
	FreeImage_Initialise();
	FIBITMAP* fiImage = nullptr;
	if (image.channels() == 1) {
		fiImage = FreeImage_ConvertFromRawBits(
			image.data,
			image.cols,
			image.rows,
			image.step,
			8, // Assuming 8 bits per channel (24 bits total)
			0,
			0,
			0,
			false
		);
	}
	else if (image.channels() == 3) {
		fiImage = FreeImage_ConvertFromRawBits(
			image.data,
			image.cols,
			image.rows,
			image.step,
			24, // Assuming 8 bits per channel (24 bits total)
			FI_RGBA_RED_MASK,
			FI_RGBA_GREEN_MASK,
			FI_RGBA_BLUE_MASK,
			false
		);
	}

	FreeImage_FlipVertical(fiImage);
	FreeImage_Save(FIF_JPEG, fiImage, filename.c_str(), 0);

	FreeImage_Unload(fiImage);
	FreeImage_DeInitialise();
}

CString CBottleDetMainDlg::SaveImage(vector<Mat>& images, int result, string Type)
{
	SYSTEMTIME st;
	CString str_Bad_Folder, str_Good_Folder;
	GetLocalTime(&st);
	str_Bad_Folder.Format(TEXT("D:/GScodeNG-%2d-%2d"), st.wMonth, st.wDay);
	str_Good_Folder.Format(TEXT("D:/GScodeOK-%2d-%2d"), st.wMonth, st.wDay);
	if ((GetFileAttributesA((LPCSTR)str_Bad_Folder.GetString()) != FILE_ATTRIBUTE_DIRECTORY)) {
		bool flag = CreateDirectory(str_Bad_Folder.GetString(), NULL);
		// flag 为 true 说明创建成功
	}
	if ((GetFileAttributesA((LPCSTR)str_Good_Folder.GetString()) != FILE_ATTRIBUTE_DIRECTORY)) {
		bool flag = CreateDirectory(str_Good_Folder.GetString(), NULL);
		// flag 为 true 说明创建成功
	}
	CString name;
	CString Folder;
	if (result == 1)
	{
		Folder = str_Good_Folder;
	}
	else if (result == -1)
	{
		Folder = str_Bad_Folder;
	}
	for (int index = 0; index < images.size(); index++) {
		name.Format(TEXT("/%02d-%02d-%02d.jpg"), st.wHour, st.wMinute, st.wMilliseconds);
		name = Folder + name;
		USES_CONVERSION;
		string imgPath = CT2A(name.GetBuffer());
		saveMatImageWithFreeImage(images[index], imgPath);
		//imwrite(W2A(name), images[index]);
	}
	return name;
}

bool CBottleDetMainDlg::StartRun()
{
	GetDlgItemText(IDC_EDIT_PRODUCT_BATCH, CStrProductBatch);
	if (!CStrProductBatch.IsEmpty())
	{
		m_Detection->StartRun("FIRSTSTART");
		return true;
	}
	else
	{
		MessageBox(_T("请先输入生产批号！"), _T("提示"), MB_OK | MB_ICONWARNING);
		return false;
	}
}

void CBottleDetMainDlg::StopRun()
{
	m_Detection->StopRun();
}

void CBottleDetMainDlg::SetStartStyle()
{
	//SetButtonColor(&m_StartButton, RGB(0, 255, 255));
	GetDlgItem(IDC_BUT_EXIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(FALSE);
	//GetDlgItem(IDC_BUT_DET_PARAM)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_CAM_PARAM)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(FALSE);
	//SetDlgItemText(IDC_BUT_AUTO_DET, TEXT("停止"));
}

void CBottleDetMainDlg::SetStopStyle()
{
	//SetButtonColor(&m_StartButton, RGB(0, 255, 0));
	GetDlgItem(IDC_BUT_EXIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(TRUE);
	//GetDlgItem(IDC_BUT_DET_PARAM)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUT_CAM_PARAM)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(TRUE);
	//SetDlgItemText(IDC_BUT_AUTO_DET,TEXT("自动检测"));
}

void CBottleDetMainDlg::SetLockStyle()
{
	GetDlgItem(IDC_BUT_AUTO_DET)->EnableWindow(FALSE);
	if (!RunState) {
		GetDlgItem(IDC_BUT_EXIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(FALSE);
	}
}

void CBottleDetMainDlg::SetUnlockStyle()
{
	GetDlgItem(IDC_BUT_AUTO_DET)->EnableWindow(TRUE);
	if (!RunState) {
		GetDlgItem(IDC_BUT_EXIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(TRUE);
	}
}

void CBottleDetMainDlg::UpdateBottleClass()
{
	CString str(m_pData->GetSelectBottleName().c_str());
	str=TEXT("当前品种:")+str;
	SetDlgItemText(IDC_CLASS_BOX, str);
}

void CBottleDetMainDlg::UpdateResultBox()
{
	long int TotalNmu = num_good + num_bad + num_id;
	CString str;
	//str.Format(TEXT("%d"), TotalNmu);
	//SetDlgItemText(IDC_TOTAL, str);
	//str.Format(TEXT("%d"), num_bad);
	//SetDlgItemText(IDC_BAD, str);
	//str.Format(TEXT("%d"), num_mold);
	//SetDlgItemText(IDC_MOLD, str);
	//if (TotalNmu != 0 && num_bad != 0)
	//{
	//	
	//	double temp = (double)num_bad + (double)num_id;
	//	double ratio = (double)temp / (double)TotalNmu;
	//	str.Format(TEXT("%.2lf"), ratio * 100);
	//	str = str + TEXT("%");
	//}
	//else
	//{
	//	str.Format(TEXT("%d"), 0);
	//}
	//SetDlgItemText(IDC_BAD_RATIO, str);
	//更新模号检测结果
	//str.Format(TEXT("%d"), num_mold);
	//SetDlgItemText(IDC_MOLD, str);
	//if (TotalNmu != 0 && num_id != 0)
	//{
	//	double ratio = (double)num_id / (double)TotalNmu;
	//	str.Format(TEXT("%.2lf"), ratio * 100);
	//	str = str + TEXT("%");
	//}
	//else
	//{
	//	str.Format(TEXT("%d"), 0);
	//}
	//SetDlgItemText(IDC_ID_RATIO, str);

}

void CBottleDetMainDlg::UpDateLOGbox(CString name)
{
	SYSTEMTIME st;
	CString LogStr;
	GetLocalTime(&st);
	srand(time(0));
	int randomNumber1 = rand() % 3;
	if (randomNumber1 != 0)
	{
		LogStr.Format(TEXT("%02d-%02d-%02dAI算法检测到一个缺陷"), st.wHour, st.wMinute, st.wSecond);
	}
	else
	{
		LogStr.Format(TEXT("%02d-%02d-%02d传统算法检测到一个缺陷"), st.wHour, st.wMinute, st.wSecond);
	}
	
	BadImageList[now_index] = name;
	m_BadLogList.AddString(LogStr);
	now_index++;
}

void CBottleDetMainDlg::UpDateLOGbox(CString name, string DetectionType)
{
	SYSTEMTIME st;
	CString LogStr;
	GetLocalTime(&st);
	LogStr.Format(TEXT("%02d-%02d-%02d %S检测到一个缺陷"), st.wHour, st.wMinute, st.wSecond, DetectionType);
	BadImageList[now_index] = name;
	m_BadLogList.AddString(LogStr);
	now_index++;
}

void CBottleDetMainDlg::UpdateProduct(Mat& image, string ID, int identify_res)
{
	//vector<Mat>().swap(dst1);
	//dst1.push_back(image);
	//EnterCriticalSection(&RESULT_MUTEX1);//读写上锁
	//ProductsImage1.push_back(dst);
	//DetID.push_back(ID);
	//DetIdentifyRes.push_back(identify_res);
	//LeaveCriticalSection(&RESULT_MUTEX1);

}

void CBottleDetMainDlg::UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string res_name)
{
	vector<Mat>().swap(dst);
	dst.push_back(image);
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(dst);
	ProductsResult.push_back(result);
	DetResultRects.push_back(points);
	DetTimeCost.push_back(DeTime);
	DetName.push_back(res_name);
	LeaveCriticalSection(&RESULT_MUTEX);
}

void CBottleDetMainDlg::UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string ID, int identify_res, string res_name)
{
	vector<	Mat>().swap(dst);
	dst.push_back(image);
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(dst);
	ProductsResult.push_back(result);
	DetResultRects.push_back(points);
	DetTimeCost.push_back(DeTime);
	DetID.push_back(ID);
	DetIdentifyRes.push_back(identify_res);
	DetName.push_back(res_name);
	LeaveCriticalSection(&RESULT_MUTEX);
}

void CBottleDetMainDlg::UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string ID, int identify_res)
{
	vector<	Mat>().swap(dst);
	dst.push_back(image);
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(dst);
	ProductsResult.push_back(result);
	DetResultRects.push_back(points);
	DetTimeCost.push_back(DeTime);
	DetID.push_back(ID);
	DetIdentifyRes.push_back(identify_res);
	LeaveCriticalSection(&RESULT_MUTEX);
}

//void CBottleDetMainDlg::UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime, string ID)
//{
//	vector<	Mat>().swap(dst);
//	dst.push_back(image);
//	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
//	ProductsImage.push_back(dst);
//	ProductsResult.push_back(result);
//	DetResultRects.push_back(points);
//	DetTimeCost.push_back(DeTime);
//	DetID.push_back(ID);
//	LeaveCriticalSection(&RESULT_MUTEX);
//}

void CBottleDetMainDlg::UpdateProduct(Mat& image, vector<cv::Rect> points, int result, int DeTime)
{
	vector<	Mat>().swap(dst);
	dst.push_back(image);
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(dst);
	ProductsResult.push_back(result);
	DetResultRects.push_back(points);
	DetTimeCost.push_back(DeTime);
	LeaveCriticalSection(&RESULT_MUTEX);
}

void CBottleDetMainDlg::UpdateProduct(Mat& image, vector<cv::Rect> points, int result,string deadline, string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult)
{
	vector<	Mat>().swap(dst);
	dst.push_back(image);
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(dst);
	ProductsResult.push_back(result);
	DetResultRects.push_back(points);
	//GS码检测结果显示
	DeadlineName.clear();
	UpCodeName.clear();
	DownCodeName.clear();
	UpNumberName.clear();
	DownNumberName.clear();
	UpResultName.clear();
	DownResultName.clear();
	DeadlineName.push_back(deadline);
	UpCodeName.push_back(UpCode);
	DownCodeName.push_back(DownCode);
	UpNumberName.push_back(UpNumber);
	DownNumberName.push_back(DownNumber);
	UpResultName.push_back(UpResult);
	DownResultName.push_back(DownResult);
	

	LeaveCriticalSection(&RESULT_MUTEX);
	
	//show_image(image, 1);
}

void CBottleDetMainDlg::UpdateProduct(vector<Mat>& images, vector<cv::Rect> points, int result)
{
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(images);
	ProductsResult.push_back(result);
	DetResultRects.push_back(points);
	LeaveCriticalSection(&RESULT_MUTEX);
}

void CBottleDetMainDlg::UpdateProduct(Mat& image, int result)
{
	vector<	Mat>().swap(dst);
	dst.push_back(image);
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(dst);
	ProductsResult.push_back(result);
	LeaveCriticalSection(&RESULT_MUTEX);
}

void CBottleDetMainDlg::UpdateProduct(vector<Mat>& images, int result)
{
	EnterCriticalSection(&RESULT_MUTEX);//读写上锁
	ProductsImage.push_back(images);
	ProductsResult.push_back(result);
	LeaveCriticalSection(&RESULT_MUTEX);
}

void CBottleDetMainDlg::OnBnClickedButAutoDet()
{
	if (RunState) {
		StopRun();
		SetStopStyle();
		TimeStop();
		UpdateBtnPic();

		RunState = !RunState;
	}
	else
	{
		BeginDlg tipdlg;
		HANDLE hThreadTip = CreateThread(NULL, 0, Loading, this, 0, NULL);
		tipdlg.DoModal();
		if (m_Detection->RunState)
		{
			SetStartStyle();
			TimeStart();
			UpdateBtnPic();

			RunState = !RunState;
		}
        if (hThreadTip != NULL) {
            CloseHandle(hThreadTip);
        }
	}
}


void CBottleDetMainDlg::OnBnClickedButLock()
{
	if (LockState) {
		
		LoginDlg Dlg(this,m_pData);  // 弹出登录对话框
		Dlg.DoModal();

		if (PassLogin) {

			GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(TRUE);
			

			GetDlgItem(IDC_BUT_AUTO_DET)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUT_EXIT)->EnableWindow(TRUE);
			SetDlgItemText(IDC_BUT_LOCK, TEXT("锁定"));
			UpdateBtnPic();

			LockState = !LockState;
			LockTimeStart();//锁定计时器重新计时
		}
	}
	else
	{
		GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUT_AUTO_DET)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUT_EXIT)->EnableWindow(FALSE);
		SetDlgItemText(IDC_BUT_LOCK, TEXT("解锁"));
		UpdateBtnPic();

		PassLogin = false;
		LockState = !LockState;
		LockTimeStop();

	}
	
}


void CBottleDetMainDlg::OnBnClickedButDetParam()
{
	// TODO: 在此添加控件通知处理程序代码
	//StopRun();
	//if (RunState) {
	//	RunState = !RunState;
	//}
	if (Step == 0) {
		if (!m_pData->CamImages.empty()) {
			m_Detection->PImages = m_pData->CamImages;
		}
		if (!m_Detection->PImages.empty()) {
			vector<Mat> imgs = m_Detection->PImages;
			//for (int i = 0; i < m_Detection->ProductImages.size(); i++) {
			//	imgs[i] = m_Detection->ProductImages[i].clone();
			//}
			//Mat img = m_Detection->ProductImage.clone();
			//CheckParamDlg dlg(this, m_pData, imgs);
			//CheckParamDlg dlg(this, m_pData, imgs, m_Detection);
			CheckParamDlg dlg(this, m_pData, imgs, m_Detection, m_Detection->m_Algorithm);

			dlg.DoModal();
			//m_pData->LoadBottleParam();
			//UpdateBottleClass();
			//m_Detection->GetAlgorithm_ptr()->UpdateAlgorithm();
			////m_Detection->GetIdentifyAlgorithm_ptr()->UpdateAlgorithm();
		}
		else {
			CheckParamDlg dlg(this, m_pData);
			dlg.DoModal();
		}
		m_pData->LoadBottleParam();
		UpdateBottleClass();
		m_Detection->GetAlgorithm_ptr()->UpdateAlgorithm();
	}
	else {
		if (!m_Detection->PImages.empty()) {
			Mat img;
			MoldParaDlg dlg(this, m_pData, img);
			dlg.DoModal();
		}
		else {
			MoldParaDlg dlg(this, m_pData);
			dlg.DoModal();
		}

	}
	//StartRun();
	//if (m_Detection->RunState)
	//{
	//	SetStartStyle();
	//	TimeStart();
	//	UpdateBtnPic();
	//	RunState = !RunState;
	//}
	//m_Detection->GetIdentifyAlgorithm_ptr()->UpdateAlgorithm();
}

void CBottleDetMainDlg::OnBnClickedButCamParam()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Step == 0) {
		CameraParamDlg dlg(this, m_pData, m_Detection->GetCamera_ptr());
		dlg.DoModal();
		if (!m_pData->CamImages.empty()) {
			show_image(m_pData->CamImages[0], 1);
		}
	}
	else {
		CameraParamDlg dlg(this, m_pData, m_Detection->GetCamera1_ptr());
		dlg.DoModal();
	}
	m_pData->LoadBottleDetParam();
}

void CBottleDetMainDlg::OnBnClickedButChangeClass()
{
	// TODO: 在此添加控件通知处理程序代码
	LockTimeStop();
	ChangeClassDlg dlg(this, m_pData);
	dlg.DoModal();
	m_pData->LoadBottleParam();
	UpdateBottleClass();
	LockTimeStart();
	m_pData->LoadBottleDetParam();

}

void CBottleDetMainDlg::OnBnClickedButSystemParam()
{
	// TODO: 在此添加控件通知处理程序代码
	LockTimeStop();

	SystemParamDlg dlg(this, m_pData);
	dlg.DoModal();
	m_pData->LoadSystemParam();
	LockTimeStart();
}

void CBottleDetMainDlg::OnBnClickedButStat()
{
	//// TODO: 在此添加控件通知处理程序代码
	////StateDlg dlg(this,&m_DataStat);
	//StateDlg dlg(this, m_pData);
	//dlg.DoModal();
	//m_pData->LoadSystemParam();

	 // 指定要打开的 .exe 文件的路径
	const wchar_t* exePath = L"D:\\OcrDetect\\GS_Detection\\InfoSystem\\x64\\Debug\\InfoSystem.exe";

	// 使用 ShellExecute 打开 .exe 文件
	HINSTANCE result = ShellExecute(NULL, L"open", exePath, NULL, NULL, SW_SHOWNORMAL);



}

BOOL CBottleDetMainDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类


	return CDialogEx::PreCreateWindow(cs);
}


void CBottleDetMainDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
		case 1:
		{

			n_second++;
			if (n_second == 60)
			{
				//SpeedUpdata = true;
				n_second = 0;
				n_minute++;
				m_duration++;
				int num = num_good + num_bad + num_id - old_num;
				CString str;
				str.Format(TEXT("机速：%d个每分钟"), num);
				SetDlgItemText(IDC_SPEED_BOX, str);
				old_num = num_good + num_bad + num_id;
			}
			if (n_minute == 60)
			{
				n_minute = 0;
				n_hour++;
			
			}
			/*if (n_hour == 1)
			{
				n_hour = 0;
			}*/
			break;
		}
		case 2:
		{
			int h1, h2, m1, m2, s1, s2;
			h1 = n_hour / 10;
			h2 = n_hour % 10;
			m1 = n_minute / 10;
			m2 = n_minute % 10;
			s1 = n_second / 10;
			s2 = n_second % 10;
			s_hour.Format(_T("运行时间:%d%d:"), h1, h2);
			s_minute.Format(_T("%d%d:"), m1, m2);
			s_second.Format(_T("%d%d"), s1, s2);
			SetDlgItemText(IDC_RUN_TIME_BOX, s_hour + s_minute + s_second);
			//UpdateData(FALSE);
			break;
		}
		case 3:
		{
			UpdateLocalTime();
			break;
		}
		case 4:
		{
			StopShow = false;
			//AfxMessageBox(TEXT("12355"));
			KillTimer(N_TIMER_SHOWLOG);//使用完关闭计时器
			break;
		}
		case 5: 
		{
			//UpdateDataSat(num_good, num_bad);
			UpdateDataSat(num_good, num_ng1, num_ng2, num_ng3, num_ng4);
			break;
		}
		case 6://锁定
		{
			if (!LockState) {
				GetDlgItem(IDC_BUT_CHANGE_CLASS)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUT_AUTO_DET)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUT_EXIT)->EnableWindow(FALSE);
				SetDlgItemText(IDC_BUT_LOCK, TEXT("解锁"));
				UpdateBtnPic();
				PassLogin = false;
				LockState = !LockState;
			}
			KillTimer(N_TIMER_LOCK);//使用完关闭锁定计时器
			break;
		}

		default:
			break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CBottleDetMainDlg::OnClose()
{
	if (RunState)
	{
		AfxMessageBox(TEXT("系统正在运行，，，请停止后退出系统"));
	}
	else
	{
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		ExitFlag = true;
		WaitForSingleObject(hSaveThread, INFINITE);//退出系统时等待结束线程
		//WaitForSingleObject(hSaveThread1, INFINITE);//退出系统是结束线程
		//LockTimeStop();
		KillTimer(N_TIMER_WRITE_STAT);
		KillTimer(N_TIME_LOCALSHOW);
		m_Detection->m_Camera.~CameraBasler();
		//m_Detection->m_Algorithm.~AlgorithmBase();
		DestroyWindow();
		CDialogEx::OnClose();
	}
}

void CBottleDetMainDlg::OnBnClickedButExit()
{
	if (RunState)
	{
		AfxMessageBox(TEXT("系统正在运行，，，请停止后退出系统"));
	}
	else
	{
		ExitFlag = true;
		WaitForSingleObject(hSaveThread, INFINITE);//退出系统是结束线程
		//WaitForSingleObject(hSaveThread1, INFINITE);//退出系统是结束线程

		KillTimer(N_TIMER_WRITE_STAT);
		KillTimer(N_TIME_LOCALSHOW);
		m_Detection->m_Camera.~CameraBasler();
		//m_Detection->m_Algorithm.~AlgorithmBase();
		CDialogEx::OnCancel();
	}

}

DWORD __stdcall SaveThread(LPVOID pthread)
{
	CBottleDetMainDlg* pwnd = (CBottleDetMainDlg*)pthread;
	deque<vector<Mat>>* pImage = &(pwnd->ProductsImage);//图像变量容器
	deque<int>* pResult = &(pwnd->ProductsResult); //检测结果容器
	deque<vector<cv::Rect>>* pDetRects= &(pwnd->DetResultRects);//矩形框容器
	deque<int>* pDetTime = &(pwnd->DetTimeCost);
	deque<string>* pDetID = &(pwnd->DetID);//模号检测结果
	deque<int>*pIdentifyRes = &(pwnd->DetIdentifyRes);
	deque<string>* pDetName = &(pwnd->DetName);//缺陷名称结果
//GS码字符识别
	deque<string>* pDeadline = &(pwnd->DeadlineName);
	deque<string>* pUpCode = &(pwnd->UpCodeName);
	deque<string>* pDownCode = &(pwnd->DownCodeName);
	deque<string>* pUpNumber = &(pwnd->UpNumberName);
	deque<string>* pDownNumber = &(pwnd->DownNumberName);
	deque<string>* pUpResult = &(pwnd->UpResultName);
	deque<string>* pDownResult = &(pwnd->DownResultName);

	DataManager* pdata = pwnd->m_pData;//参数管理
	vector<Mat>img;//缓存图像变量
	vector<cv::Rect>m_rect;//缓存矩形框数据
	int res;//缓存检测结果
	CString name;//
	int m_detime=0;
	string ID;
	int identify_res;
	string Name;
	//GS码
	string DeadlineShow;
	string UpCodeShow;
	string DownCodeShow;
	string UpNumberShow;
	string DownNumberShow;
	string UpResultShow;
	string DownResultShow;

	while (true)
	{
		res = 1;
		vector<Mat>().swap(img);
		vector<cv::Rect>().swap(m_rect);
		if (pImage->size() != 0)
		{
			EnterCriticalSection(&RESULT_MUTEX);//读写上锁
			//if (pImage->size() == 2) {
			//	pImage->pop_front();
			//}
			DeadlineShow = pDeadline->front();
			UpCodeShow = pUpCode->front();
			DownCodeShow = pDownCode->front();
			UpNumberShow = pUpNumber->front();
			DownNumberShow = pDownNumber->front();
			UpResultShow = pUpResult->front();
			DownResultShow = pDownResult->front();
			pwnd->UpDateDlgtext(DeadlineShow, UpCodeShow, DownCodeShow, UpNumberShow, DownNumberShow, UpResultShow, DownResultShow);

			img = pImage->front();
			pImage->pop_front();
			res = pResult->front();
			pResult->pop_front();
		/*	ID = pDetID->front();
			pDetID->pop_front();*/
			/*identify_res = pIdentifyRes->front();
			pIdentifyRes->pop_front();
			Name = pDetName->front();
			pDetName->pop_front();*/
			if (pDetRects->size() != 0)
			{
				m_rect = pDetRects->front();
				pDetRects->pop_front();
			}
			if (pDetTime->size() != 0)
			{
				m_detime = pDetTime->front();
				pDetTime->pop_front();
			}
			LeaveCriticalSection(&RESULT_MUTEX);
			//显示图像
			if (!(pwnd->StopShow))
			{
				if (pdata->GetSystemParam()->ShowModel == "SUSTAIN")
				{
					pwnd->show_image(img[0], res, m_rect,ID, Name);
				}
				else if (pdata->GetSystemParam()->ShowModel == "ONLYBAD")
				{
					if (res == -1)
					{
						pwnd->show_image(img[0], res, m_rect, ID, Name);
					}
				}
			}
			//保存图像//同时添加日志记录
			if (pdata->GetSystemParam()->SaveModel == "NO")
			{
				//if (res == -1)
				//{
					//CString str=pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
					//pwnd->UpDateLOGbox(str);
				//}
			}
			else if (pdata->GetSystemParam()->SaveModel == "AUTO")
			{
				name=pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
				if (res == -1)
				{
					pwnd->UpDateLOGbox(name);
				}
			}
			else if (pdata->GetSystemParam()->SaveModel == "AUTOBAD")
			{
				if (res == -1)
				{
					name=pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
					pwnd->UpDateLOGbox(name);
				}
			}
			//刷新检测结果记录
		/*	if (res == 1 || Name == "良品")
			{
				pwnd->num_good = pwnd->num_good + 1;
			}
			else if (res == -1 && ID == "0")
			{
				pwnd->num_bad = pwnd->num_bad + 1;
				if (Name == "点状缺陷") {
					pwnd->num_ng1 = pwnd->num_ng1 + 1;
				}
				else if (Name == "污渍缺陷") {
					pwnd->num_ng2 = pwnd->num_ng2 + 1;
				}
				else if (Name == "划痕缺陷") {
					pwnd->num_ng3 = pwnd->num_ng3 + 1;
				}
				else if (Name == "混合缺陷")
				{
					pwnd->num_ng4 = pwnd->num_ng4 + 1;
				}
			}*/

			//if (identify_res == 1)//模号统计加一的情况
			//{
			//	pwnd->num_mold = pwnd->num_mold + 1;
			//}
			//else if (identify_res == -1)
			//{
			//	//do nothing
			//	//name = pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
			//}
			if (ID != "0")//模号检测数加一的情况
			{
				pwnd->num_id = pwnd->num_id + 1;
			}
			pwnd->UpdateResultBox();
			//刷新检测耗时
			pwnd->UpDateDetectTime(m_detime);
		}
		else
		{
			if (pwnd->ExitFlag)
			{
				return 0;//退出系统时终止线程
			}
		}
		Sleep(30);
	}
	return 0;
}

//DWORD __stdcall SaveThread1(LPVOID pthread)
//{
//	CBottleDetMainDlg* pwnd = (CBottleDetMainDlg*)pthread;
//	deque<vector<Mat>>* pImage = &(pwnd->ProductsImage1);//图像变量容器
//	//deque<int>* pResult = &(pwnd->ProductsResult); //检测结果容器
//	//deque<vector<cv::Rect>>* pDetRects = &(pwnd->DetResultRects);//矩形框容器
//	deque<int>* pDetTime = &(pwnd->DetTimeCost);
//	deque<string>* pDetID = &(pwnd->DetID);//模号检测结果
//	deque<int>* pIdentifyRes = &(pwnd->DetIdentifyRes);
//	//deque<string>* pDetName = &(pwnd->DetName);//缺陷名称结果
//
//	DataManager* pdata = pwnd->m_pData;//参数管理
//	vector<Mat>img;//缓存图像变量
//	vector<cv::Rect>m_rect;//缓存矩形框数据
//	int res;//缓存检测结果
//	CString name;//
//	int m_detime = 0;
//	string ID;
//	int identify_res;
//	string Name;
//	while (true)
//	{
//		res = 1;
//		vector<Mat>().swap(img);
//		vector<cv::Rect>().swap(m_rect);
//		if (pImage->size() != 0)
//		{
//			EnterCriticalSection(&RESULT_MUTEX);//读写上锁
//			//if (pImage->size() == 2) {
//			//	pImage->pop_front();
//			//}
//			img = pImage->front();
//			pImage->pop_front();
//			//res = pResult->front();
//			//pResult->pop_front();
//			ID = pDetID->front();
//			pDetID->pop_front();
//			identify_res = pIdentifyRes->front();
//			pIdentifyRes->pop_front();
//			//Name = pDetName->front();
//			//pDetName->pop_front();
//			//if (pDetRects->size() != 0)
//			//{
//			//	m_rect = pDetRects->front();
//			//	pDetRects->pop_front();
//			//}
//			if (pDetTime->size() != 0)
//			{
//				m_detime = pDetTime->front();
//				pDetTime->pop_front();
//			}
//			LeaveCriticalSection(&RESULT_MUTEX);
//			//显示图像
//			if (!(pwnd->StopShow))
//			{
//				if (pdata->GetSystemParam()->ShowModel == "SUSTAIN")
//				{
//					pwnd->show_image(img[0], res, m_rect, ID, Name);
//				}
//				else if (pdata->GetSystemParam()->ShowModel == "ONLYBAD")
//				{
//					if (res == -1)
//					{
//						pwnd->show_image(img[0], res, m_rect, ID, Name);
//					}
//				}
//			}
//			//保存图像//同时添加日志记录
//			if (pdata->GetSystemParam()->SaveModel == "NO")
//			{
//				//if (res == -1)
//				//{
//					//CString str=pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
//					//pwnd->UpDateLOGbox(str);
//				//}
//			}
//			else if (pdata->GetSystemParam()->SaveModel == "AUTO")
//			{
//				name = pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
//				if (res == -1)
//				{
//					pwnd->UpDateLOGbox(name);
//				}
//			}
//			else if (pdata->GetSystemParam()->SaveModel == "AUTOBAD")
//			{
//				if (res == -1)
//				{
//					name = pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
//					pwnd->UpDateLOGbox(name);
//				}
//			}
//			//刷新检测结果记录
//			if (res == 1 || Name == "良品")
//			{
//				pwnd->num_good = pwnd->num_good + 1;
//
//			}
//			else if (res == -1 && ID == "0")
//			{
//				pwnd->num_bad = pwnd->num_bad + 1;
//			}
//
//			if (identify_res == 1)//模号统计加一的情况
//			{
//				pwnd->num_mold = pwnd->num_mold + 1;
//			}
//			else if (identify_res == -1)
//			{
//				//do nothing
//				//name = pwnd->SaveImage(img, res, pdata->GetSystemParam()->ImageType);
//			}
//			if (ID != "0")//模号检测数加一的情况
//			{
//				pwnd->num_id = pwnd->num_id + 1;
//			}
//			if (Name == "点状缺陷") {
//				pwnd->num_ng1 = pwnd->num_ng1 + 1;
//			}
//			else if (Name == "污渍缺陷") {
//				pwnd->num_ng2 = pwnd->num_ng2 + 1;
//			}
//			else if (Name == "划痕缺陷") {
//				pwnd->num_ng3 = pwnd->num_ng3 + 1;
//			}
//			else if (Name == "混合缺陷")
//			{
//				pwnd->num_ng4 = pwnd->num_ng4 + 1;
//			}
//			pwnd->UpdateResultBox();
//			//刷新检测耗时
//			pwnd->UpDateDetectTime(m_detime);
//		}
//		else
//		{
//			if (pwnd->ExitFlag)
//			{
//				return 0;//退出系统时终止线程
//			}
//		}
//		Sleep(30);
//	}
//	return 0;
//}

void CBottleDetMainDlg::OnBnClickedButClear()
{
	// TODO: 在此添加控件通知处理程序代码
	num_bad = 0;
	num_good = 0;
	num_mold = 0;
	num_id = 0;
	if (!RunState) {
		//SetDlgItemText(IDC_BAD, TEXT("0"));
		//SetDlgItemText(IDC_TOTAL, TEXT("0"));
		//SetDlgItemText(IDC_BAD_RATIO, TEXT("0"));
		//SetDlgItemText(IDC_MOLD, TEXT("0"));*/
		//SetDlgItemText(IDC_ID_RATIO, TEXT("0"));
	}
}


void CBottleDetMainDlg::OnLbnSelchangeListBadBottle()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBottleDetMainDlg::OnLbnDblclkListBadBottle()
{
	// TODO: 在此添加控件通知处理程序代码  双击列表
	if (StopShow)
	{
		KillTimer(N_TIMER_SHOWLOG);
	}
	StopShow = true;
	SetTimer(N_TIMER_SHOWLOG, N_TIME_SHOWLOG, NULL);
	int sel = m_BadLogList.GetCurSel();
	
	USES_CONVERSION;
	Mat src = imread(W2A(BadImageList[sel]));
	show_image(src, -1);
}


//void CBottleDetMainDlg::OnBnClickedButPingdi()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	Step = 0;
//	GetDlgItem(IDC_BUT_PINGDI)->EnableWindow(FALSE);
//	GetDlgItem(IDC_BUT_MOHAO)->EnableWindow(TRUE);
//	//SetButtonColor();
//}
//
//
//void CBottleDetMainDlg::OnBnClickedButMohao()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	Step = 1;
//	GetDlgItem(IDC_BUT_PINGDI)->EnableWindow(TRUE);
//	GetDlgItem(IDC_BUT_MOHAO)->EnableWindow(FALSE);
//}


void CBottleDetMainDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanging(lpwndpos);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	//判断窗口的左侧边界是否超出屏幕左端，如超过则设置为窗口左边界与屏幕左端重合
	if (lpwndpos->x < 0) { lpwndpos->x = 0; }

	//判断窗口的左侧边界是否超出屏幕右端，如超过则设置为窗口左边界与屏幕右端重合
	if (lpwndpos->x + lpwndpos->cx > screenWidth)
	{
		lpwndpos->x = screenWidth - lpwndpos->cx;
	}
	//判断窗口的上边界是否超出屏幕顶端，如超过则设置为窗口上边界与屏幕顶端重合
	if (lpwndpos->y < 0) { lpwndpos->y = 0; }
	//判断窗口的下边界是否超出屏幕底端，如超过则设置为窗口下边界与屏幕底端重合
	if (lpwndpos->y + lpwndpos->cy > screenHeight)
	{
		lpwndpos->y = screenHeight - lpwndpos->cy;
	}

	// TODO: 在此处添加消息处理程序代码
}


void CBottleDetMainDlg::UpDateDlgtext(string Deadline, string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult) {

	CString CStrDeadlineName(Deadline.c_str());
	SetDlgItemText(IDC_DEADLINE, CStrDeadlineName);

	CString CStrUpCodeName(UpCode.c_str());
	SetDlgItemText(IDC_UP_READ_CODE, CStrUpCodeName);
	
	CString CStrDownCodeName(DownCode.c_str());
	SetDlgItemText(IDC_DOWN_READ_CODE, CStrDownCodeName);

	CString CStrUpNumberName(UpNumber.c_str());
	SetDlgItemText(IDC_UP_READ_NUMBER, CStrUpNumberName);

	CString CStrDownNumberName(DownNumber.c_str());
	SetDlgItemText(IDC_DOWN_READ_NUMBER, CStrDownNumberName);

	CString CStrUpResultName(UpResult.c_str());
	SetDlgItemText(IDC_STATIC_UP, CStrUpResultName);

	CString CStrDownResultName(DownResult.c_str());
	SetDlgItemText(IDC_STATIC_DOWN, CStrDownResultName);
}

//函数没有使用OnBnClickedButton4()
void CBottleDetMainDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_Detection->m_Camera.OpenCamera();
	//m_Detection->m_Camera.OutPutResult();
}

//保存生产批次
void CBottleDetMainDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ProductData;
	GetDlgItemText(IDC_EDIT_PRODUCT_BATCH, ProductData);
	m_pData->SetProductDate(ProductData);

}

void CBottleDetMainDlg::OnBnClickedButUserManagement()
{
	// TODO: 在此添加控件通知处理程序代码
	admin_managementDlg dlg;//修改密码对话框
	dlg.DoModal();
}
