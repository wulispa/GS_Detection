// CameraParamDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "CameraParamDlg.h"
#include "afxdialogex.h"
#include "myLogger.h"

//CRITICAL_SECTION RESULT_MUTEX1;

// CameraParamDlg 对话框

IMPLEMENT_DYNAMIC(CameraParamDlg, CDialogEx)
DWORD WINAPI CaptureImage(LPVOID pthread);
DWORD WINAPI CamSaveThread(LPVOID pthread);

CameraParamDlg::CameraParamDlg(CWnd* pParent  , DataManager* pdata, CameraBasler* cam/*=nullptr*/)
	: CDialogEx(IDD_CAMERA_PARAM_DIALOG, pParent),
	m_pData(pdata),
	m_Camera(cam),
	m_Camera1(nullptr),
	isAutoSave(false),
	isTrigger(false),
	Capture_flag(1),
	ExitFlag(false),
	Step(0),
	Sustain(false)
{
	m_pData->LoadBottleParam();
	m_pData->LoadBottleDetParam();
	m_param = m_pData->GetBottleDetParam();
	hCaptureImageThread = CreateThread(NULL, 0, CaptureImage, this, 0, NULL);
	//hCSaveImageThread = CreateThread(NULL, 0, CamSaveThread, this, 0, NULL);

	CAPTURE_EVENT=CreateEventW(NULL, FALSE, FALSE, NULL);
	COMPLETE_EVENT= CreateEventW(NULL, FALSE, FALSE, NULL);
}

CameraParamDlg::CameraParamDlg(CWnd* pParent, DataManager* pdata, CameraHK1* cam)
	: CDialogEx(IDD_CAMERA_PARAM_DIALOG, pParent),
	m_pData(pdata),
	m_Camera(nullptr),
	m_Camera1(cam),
	isAutoSave(false),
	isTrigger(false),
	Capture_flag(1),
	ExitFlag(false),
	Step(1),
	Sustain(false)
{
	m_pData->LoadBottleParam();
	m_pData->LoadBottleDetParam();
	m_param = m_pData->GetBottleDetParam();
	hCaptureImageThread = CreateThread(NULL, 0, CaptureImage, this, 0, NULL);
	//hCSaveImageThread = CreateThread(NULL, 0, CamSaveThread, this, 0, NULL);

	CAPTURE_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	COMPLETE_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);

}

CameraParamDlg::~CameraParamDlg()
{
	m_font->DeleteObject();
	ExitFlag = true;
	if (m_Camera!=nullptr && m_Camera->IsOpen())
	{
		m_Camera->CloseCamera();
	}
	if (m_Camera1 != nullptr && m_Camera1->IsOpen())
	{
		m_Camera1->CloseCamera();
	}
	//SetEvent(CAPTURE_EVENT);
	//Capture_flag = 0;
	//WaitForSingleObject(hCaptureImageThread, INFINITE);
	//CloseHandle(hCaptureImageThread);
	////WaitForSingleObject(hCSaveImageThread, INFINITE);
	////CloseHandle(hCSaveImageThread);
	//CloseHandle(CAPTURE_EVENT);
	//CloseHandle(COMPLETE_EVENT);
	m_pData->CamImages = Images;
	ExitFlag = true;
}

void CameraParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CameraParamDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUT_SAVE_CAM_PARAM, &CameraParamDlg::OnBnClickedButSaveCamParam)
	ON_BN_CLICKED(IDC_BUT_EXIT_CAM_PARAM, &CameraParamDlg::OnBnClickedButExitCamParam)
	//ON_BN_CLICKED(IDC_BUT_CONNECTION_TEST, &CameraParamDlg::OnBnClickedButConnectionTest)
	//ON_BN_CLICKED(IDC_BUT_GRAY_SINGLE, &CameraParamDlg::OnBnClickedButGraySingle)
	ON_BN_CLICKED(IDC_BUT_GRAY_STILL, &CameraParamDlg::OnBnClickedButGrayStill)
	//ON_BN_CLICKED(IDC_BUT_DISCONNEXTION, &CameraParamDlg::OnBnClickedButDisconnextion)
	ON_WM_SYSCOMMAND()
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// CameraParamDlg 消息处理程序


BOOL CameraParamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//vector<Mat>().swap(m_pData->CamImages);
	// TODO:  在此添加额外的初始化

	m_win.OpenWindow(GetDlgItem(IDC_CAM_IMAGE_WIN));
	GetDlgItem(IDC_AUTO_SAVE)->ShowWindow(FALSE);

	GetDlgItem(IDC_BUT_CONNECTION_TEST)->ShowWindow(FALSE);//隐藏按钮
	GetDlgItem(IDC_BUT_DISCONNEXTION)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_GRAY_SINGLE)->ShowWindow(FALSE);
	GetDlgItem(IDC_CAMERA_TEST_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_GRABNUM_LABEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_GRABNUM)->ShowWindow(FALSE);
	
	if (Step == 0) {
		CString str_time, str_gain, str_Num;
		str_time.Format(TEXT("%d"), m_param->ExpostTime);
		str_gain.Format(TEXT("%.2lf"), m_param->GainValue);
		str_Num.Format(TEXT("%d"), m_param->GrabNum);

		SetDlgItemText(IDC_EDIT_EXPOSE_TIME, str_time);
		SetDlgItemText(IDC_EDIT_GAIN, str_gain);
		SetDlgItemText(IDC_EDIT_GRABNUM, str_Num);

		GrabNum = m_param->GrabNum;

		if (m_param->AutoSaveImage == "TRUE")
		{
			((CButton*)GetDlgItem(IDC_CHECK_AUTO_SAVE))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_AUTO_SAVE))->SetCheck(FALSE);
		}
		if (m_param->Trigger == "ON")
		{
			((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->SetCheck(FALSE);
		}
		if (m_param->CamOut == "TRUE")
		{
			((CButton*)GetDlgItem(IDC_CHECK_CAMERA_OUT))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_CAMERA_OUT))->SetCheck(FALSE);
		}
	}
	else {
		GetDlgItem(IDC_EDIT_GRABNUM)->ShowWindow(FALSE);
		GetDlgItem(IDC_GRABNUM_LABEL)->ShowWindow(FALSE);
		CString str_time, str_gain;
		str_time.Format(TEXT("%d"), m_param->ExpostTime);
		str_gain.Format(TEXT("%.2lf"), m_param->GainValue);
		SetDlgItemText(IDC_EDIT_EXPOSE_TIME, str_time);
		SetDlgItemText(IDC_EDIT_GAIN, str_gain);
		if (m_param->AutoSaveImage1 == "TRUE")
		{
			((CButton*)GetDlgItem(IDC_CHECK_AUTO_SAVE))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_AUTO_SAVE))->SetCheck(FALSE);
		}
		if (m_param->Trigger1 == "ON")
		{
			((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->SetCheck(FALSE);
		}
		if (m_param->CamOut1 == "TRUE")
		{
			((CButton*)GetDlgItem(IDC_CHECK_CAMERA_OUT))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_CAMERA_OUT))->SetCheck(FALSE);
		}
	}
	//GetDlgItem(IDC_CHECK_TRIGER)->EnableWindow(TRUE);
	//GetDlgItem(IDC_BUT_GRAY_SINGLE)->EnableWindow(FALSE);
	//GetDlgItem(IDC_BUT_GRAY_STILL)->EnableWindow(FALSE);
	m_font = new CFont();
	InitWindowFront();//初始化字体
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CameraParamDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CameraParamDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void CameraParamDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	//dc.FillSolidRect(rect, RGB(157, 172, 253));
	InitControlColor(IDC_CAM_IMAGE_WIN, RGB(0, 0, 0));
}


void CameraParamDlg::ShowImage(Mat& image)
{
	m_win.DispImage(image);
}

void CameraParamDlg::InitWindowFront()
{
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 2;
	lfCtrl.lfHeight = 16;
	lfCtrl.lfItalic = false;
	lfCtrl.lfUnderline = false;
	lfCtrl.lfStrikeOut = false;
	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lfCtrl.lfFaceName, L"宋体");
	lfCtrl.lfWeight = FW_HEAVY;
	m_font->CreateFontIndirectW(&lfCtrl);

	GetDlgItem(IDC_EXPOSR_TIME_LABEL)->SetFont(m_font);
	GetDlgItem(IDC_EDIT_EXPOSE_TIME)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SAVE_CAM_PARAM)->SetFont(m_font);
	GetDlgItem(IDC_GAIN_LABEL)->SetFont(m_font);
	GetDlgItem(IDC_EDIT_GAIN)->SetFont(m_font);
	if (Step == 0) {
		GetDlgItem(IDC_GRABNUM_LABEL)->SetFont(m_font);
		GetDlgItem(IDC_EDIT_GRABNUM)->SetFont(m_font);
	}

	GetDlgItem(IDC_BUT_EXIT_CAM_PARAM)->SetFont(m_font);
	//GetDlgItem(IDC_CHECK_AUTO_SAVE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_CONNECTION_TEST)->SetFont(m_font);
	GetDlgItem(IDC_CAMERA_PARAM_BOX)->SetFont(m_font);
	GetDlgItem(IDC_EXPOSE_L)->SetFont(m_font);
	GetDlgItem(IDC_CAMERA_TEST_BOX)->SetFont(m_font);
	//GetDlgItem(IDC_CHECK_TRIGER)->SetFont(m_font);
	GetDlgItem(IDC_BUT_DISCONNEXTION)->SetFont(m_font);
	GetDlgItem(IDC_BUT_GRAY_SINGLE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_GRAY_STILL)->SetFont(m_font);
}

void CameraParamDlg::ConnectCam()
{
	OnBnClickedButSaveCamParam();
	if (m_Camera->IsOpen())
	{
		m_Camera->CloseCamera();
		Sleep(100);
		m_Camera->OpenCamera();
		m_Camera->UpdateCamera();
		m_Camera->SetTriggerModel(TRUE);
	}
	else
	{
		m_Camera->OpenCamera();
		m_Camera->UpdateCamera();
		m_Camera->SetTriggerModel(TRUE);
	}

}

void CameraParamDlg::OutConnect()
{
	if (m_Camera->IsOpen())
	{
		m_Camera->CloseCamera();
	}
}

void CameraParamDlg::OnBnClickedButSaveCamParam()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Step == 0) {
		CString Gain_str, ExposeTime_str, GrabNum_str;
		GetDlgItemText(IDC_EDIT_GAIN, Gain_str);
		GetDlgItemText(IDC_EDIT_EXPOSE_TIME, ExposeTime_str);
		GetDlgItemText(IDC_EDIT_GRABNUM, GrabNum_str);
		if (((CButton*)GetDlgItem(IDC_CHECK_AUTO_SAVE))->GetCheck()) {
			m_pData->SetAutoSaveImage(TEXT("TRUE"));
		}
		else
		{
			m_pData->SetAutoSaveImage(TEXT("FALSE"));
		}
		if (((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->GetCheck()) {
			//isTrigger = true;
			m_pData->SetTrigger(TEXT("ON"));
		}
		else
		{
			//isTrigger = false;
			m_pData->SetTrigger(TEXT("OFF"));
		}
		if (((CButton*)GetDlgItem(IDC_CHECK_CAMERA_OUT))->GetCheck()) {
			m_pData->SetCameraOut(TEXT("TRUE"));
		}
		else
		{
			m_pData->SetCameraOut(TEXT("FALSE"));
		}
		m_pData->SetGainValue(Gain_str);
		m_pData->SetExpostTime(ExposeTime_str);
		m_pData->SetNumImage(GrabNum_str);
	}
	else {
		CString Gain_str, ExposeTime_str;
		GetDlgItemText(IDC_EDIT_GAIN, Gain_str);
		GetDlgItemText(IDC_EDIT_EXPOSE_TIME, ExposeTime_str);
		if (((CButton*)GetDlgItem(IDC_CHECK_AUTO_SAVE))->GetCheck()) {
			m_pData->SetAutoSaveImage1(TEXT("TRUE"));
		}
		else
		{
			m_pData->SetAutoSaveImage1(TEXT("FALSE"));
		}
		if (((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->GetCheck()) {
			//isTrigger = true;
			m_pData->SetTrigger1(TEXT("ON"));
		}
		else
		{
			//isTrigger = false;
			m_pData->SetTrigger1(TEXT("OFF"));
		}
		if (((CButton*)GetDlgItem(IDC_CHECK_CAMERA_OUT))->GetCheck()) {
			m_pData->SetCameraOut1(TEXT("TRUE"));
		}
		else
		{
			m_pData->SetCameraOut1(TEXT("FALSE"));
		}
		m_pData->SetGainValue1(Gain_str);
		m_pData->SetExpostTime1(ExposeTime_str);
	}
	m_pData->LoadBottleDetParam();

}
void CameraParamDlg::InitControlColor(int ID, COLORREF rgb)
{
	CRect mrect;
	GetDlgItem(ID)->GetClientRect(&mrect);
	FillRect(GetDlgItem(ID)->GetDC()->GetSafeHdc(), &mrect, CBrush(rgb));
}

void CameraParamDlg::OnBnClickedButExitCamParam()
{
	// TODO: 在此添加控件通知处理程序代码
	ExitFlag = true;

	if (m_Camera != nullptr && m_Camera->IsOpen())
	{
		m_Camera->CloseCamera();
	}
	if (m_Camera1 != nullptr && m_Camera1->IsOpen())
	{
		m_Camera1->CloseCamera();
	}

	SetEvent(CAPTURE_EVENT);
	Capture_flag = 0;
	WaitForSingleObject(hCaptureImageThread, INFINITE);
	CloseHandle(hCaptureImageThread);
	//WaitForSingleObject(hCSaveImageThread, INFINITE);
	//CloseHandle(hCSaveImageThread);
	CloseHandle(CAPTURE_EVENT);
	CloseHandle(COMPLETE_EVENT);
	if (m_Camera != nullptr && m_Camera->IsOpen())
	{
		m_Camera->CloseCamera();
	}
	if (m_Camera1 != nullptr && m_Camera1->IsOpen())
	{
		m_Camera1->CloseCamera();
	}
	m_pData->CamImages = Images;

	CDialogEx::OnCancel();
}


//void CameraParamDlg::OnBnClickedButConnectionTest()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	OnBnClickedButSaveCamParam();
//	if (m_Camera->IsOpen())
//	{
//		m_Camera->CloseCamera();
//		Sleep(100);
//		m_Camera->OpenCamera();
//		m_Camera->UpdateCamera();
//		m_Camera->SetTriggerModel(isTrigger);
//	}
//	else
//	{
//		m_Camera->OpenCamera();
//		m_Camera->UpdateCamera();
//		m_Camera->SetTriggerModel(isTrigger);
//	}
//	if (m_Camera->IsOpen()) {
//		AfxMessageBox(TEXT("连接成功"));
//		GetDlgItem(IDC_BUT_GRAY_SINGLE)->EnableWindow(TRUE);
//		GetDlgItem(IDC_BUT_GRAY_STILL)->EnableWindow(TRUE);
//	}
//	else {
//		AfxMessageBox(TEXT("连接错误"));
//	}
//	GetDlgItem(IDC_BUT_CONNECTION_TEST)->EnableWindow(FALSE);
//}

CString CameraParamDlg::SaveImage(Mat& image)
{
	CString name;
	if (m_param->AutoSaveImage == "TRUE")
	{
		SYSTEMTIME st;
		CString TestFolder;
		GetLocalTime(&st);
		TestFolder.Format(TEXT("F:/CameraTest%2d-%2d"), st.wMonth, st.wDay);
		if ((GetFileAttributesA((LPCSTR)TestFolder.GetString())) != FILE_ATTRIBUTE_DIRECTORY) {
			bool flag = CreateDirectory(TestFolder.GetString(), NULL);
			// flag 为 true 说明创建成功
		}
		name.Format(TEXT("/%2d-%2d-%2d.jpg"), st.wHour, st.wMinute, st.wMilliseconds);
		name = TestFolder + name;
		USES_CONVERSION;
		imwrite(W2A(name), image);
	}
	return name;
}

CString CameraParamDlg::SaveImage(vector<Mat>& images)
{
	CString name;
	if (m_param->AutoSaveImage == "TRUE")
	{
		SYSTEMTIME st;
		CString TestFolder;
		GetLocalTime(&st);
		TestFolder.Format(TEXT("F:/CameraTest%2d-%2d"), st.wMonth, st.wDay);
		if ((GetFileAttributesA((LPCSTR)TestFolder.GetString())) != FILE_ATTRIBUTE_DIRECTORY) {
			bool flag = CreateDirectory(TestFolder.GetString(), NULL);
			// flag 为 true 说明创建成功
		}
		for (int i = 0; i < m_param->GrabNum; i++) {
			//name.Format(TEXT("/%2d-%2d-%2d.jpg"), st.wHour, st.wMinute, st.wMilliseconds);
			name.Format(TEXT("/%02d-%02d-%02d-%d.jpg"), st.wHour, st.wMinute, st.wMilliseconds, i);
			name = TestFolder + name;
			//USES_CONVERSION;
			//imwrite(W2A(name), images[i]);
			WriteImage1(images, name, i);
		}
	}
	return name;
}

void CameraParamDlg::WriteImage1(vector<Mat> images, CString name, int i)
{
	USES_CONVERSION;
	imwrite(W2A(name), images[i]);
}

//void CameraParamDlg::OnBnClickedButGraySingle()
//{
//	//m_Camera->UpdateCamera();
//	//m_Camera->SetTriggerModel(isTrigger);
//
//	//// TODO: 在此添加控件通知处理程序代码
//	//if (((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->GetCheck()) {
//	//	Capture_flag = 1;
//	//}
//	//else {
//	//	Capture_flag = 2;
//	//}
//	//SetEvent(CAPTURE_EVENT);
//	//WaitForSingleObject(COMPLETE_EVENT,INFINITE);
//	//ResetEvent(COMPLETE_EVENT);
//}
char* MyW2Ac(const CString& str) {
	int n = str.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, str, n, NULL, 0, NULL, NULL);
	char* strchar = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str, n + 1, strchar, len + 1, NULL, NULL);
	strchar[len] = '\0';
	return strchar;
}

DWORD WINAPI CaptureImage(LPVOID pthread)
{
	CameraParamDlg* pwnd = (CameraParamDlg*)pthread;
	Mat Image;
	vector<Mat> Images;
	while (true)
	{
		//等待主界面消息
		WaitForSingleObject(pwnd->CAPTURE_EVENT, INFINITE);
		SYSTEMTIME st;
		CString strDate, strTime;
		GetLocalTime(&st);
		strTime.Format(TEXT("当前时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		const char* cstr;
		cstr = MyW2Ac(strTime);
		LOG(0, cstr);

		//等到消息后，执行处理
		//1：外部触发，单次多张
		//2：单次多张
		//3：外部触发，连续单次多张
		//4：连续单次多张
		if (pwnd->Capture_flag == 0)
		{
			break;
		}
		//else if (pwnd->Capture_flag == 1)  
		//{
		//	Images = pwnd->m_Camera->GetImages();
		//	pwnd->Images = Images;
		//	//pwnd->CImages.push_back(pwnd->Images);
		//	pwnd->SaveImage(Images);
		//	Image = Images[0];
		//	pwnd->ShowImage(Image);//
		//	ResetEvent(pwnd->CAPTURE_EVENT);
		//	SetEvent(pwnd->COMPLETE_EVENT);
		//}
		//else if (pwnd->Capture_flag == 2)	
		//{
		//	//Image=pwnd->m_Camera->GetImage();
		//	Images = pwnd->m_Camera->GetImages();
		//	Image = Images[0];
		//	pwnd->ShowImage(Image);//
		//	//pwnd->SaveImage(Image);			//保存图像	
		//	pwnd->Images = Images;
		//	//EnterCriticalSection(&RESULT_MUTEX1);//读写上锁
		//	//pwnd->CImages.push_back(pwnd->Images);
		//	//LeaveCriticalSection(&RESULT_MUTEX1);
		//	pwnd->SaveImage(Images);
		//	//GetLocalTime(&st);
		//	//strTime.Format(TEXT("保存时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		//	//cstr = MyW2Ac(strTime);
		//	//LOG(0, cstr);
		//	ResetEvent(pwnd->CAPTURE_EVENT);
		//	SetEvent(pwnd->COMPLETE_EVENT);
		//}
		else if (pwnd->Capture_flag == 3) 
		{
			//Images = pwnd->m_Camera->GetImage(1);			
			Image = pwnd->m_Camera->GetImage(1);			
			if (pwnd->m_Camera->isSuccessGraph() && !Images.empty() && Images.size()==5)
			{
				//Image = Images[0];
				pwnd->ShowImage(Image);
				//pwnd->Images = Images;
				//EnterCriticalSection(&RESULT_MUTEX1);//读写上锁
				//pwnd->CImages.push_back(pwnd->Images);
				//LeaveCriticalSection(&RESULT_MUTEX1);
				pwnd->Images.push_back(Image);
				//保存图像
				pwnd->SaveImage(Images);
			}
			if (pwnd->Sustain)
			{
				Sleep(50);
				SetEvent(pwnd->CAPTURE_EVENT);
			}
			else
			{
				ResetEvent(pwnd->CAPTURE_EVENT);
				SetEvent(pwnd->COMPLETE_EVENT);
			}
		}
		else if (pwnd->Capture_flag == 4 && !Images.empty())
		{
			//Image = pwnd->m_Camera->GetImage();
			Images = pwnd->m_Camera->GetImage(1);
			if (pwnd->m_Camera->isSuccessGraph())
			{
				Image = Images[0];
				pwnd->ShowImage(Image);
				pwnd->Images = Images;

				//pwnd->CImages.push_back(pwnd->Images);

				//保存图像
				//pwnd->SaveImage(Image);
				pwnd->SaveImage(Images);
				//pwnd->Images = Images;
			}
			if (pwnd->Sustain)
			{
				Sleep(50);
				SetEvent(pwnd->CAPTURE_EVENT);
			}
			else
			{
				ResetEvent(pwnd->CAPTURE_EVENT);
				SetEvent(pwnd->COMPLETE_EVENT);
			}

		}
		//pwnd->Images = Images;
		GetLocalTime(&st);
		strTime.Format(TEXT("当前时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		cstr = MyW2Ac(strTime);
		LOG(0, cstr);
		LOG(0, "end");
	}
	return 0;
}

//DWORD __stdcall CamSaveThread(LPVOID pthread)
//{
//	CameraParamDlg* pwnd = (CameraParamDlg*)pthread;
//
//	deque<vector<Mat>>* pImages = &(pwnd->CImages);//图像变量容器
//	Mat Image;
//	vector<Mat> Images;
//	CString name;
//
//	while (true)
//	{
//		if (pImages->size() != 0 && pwnd->Sustain) {
//			EnterCriticalSection(&RESULT_MUTEX1);//读写上锁
//			Images = pImages->front();
//			pImages->pop_front();
//			LeaveCriticalSection(&RESULT_MUTEX1);
//			if (pwnd->m_param->AutoSaveImage == "TRUE") {
//				pwnd->SaveImage(Images);
//			}
//		}
//		else
//		{
//			if (pwnd->ExitFlag)
//			{
//				return 0;//退出系统时终止线程
//			}
//			Sleep(30);
//		}
//
//
//		//if (pwnd->m_param->AutoSaveImage == "TRUE") {
//		//	SYSTEMTIME st;
//		//	CString strDate, strTime;
//		//	const char* cstr;
//		//	GetLocalTime(&st);
//		//	strTime.Format(TEXT("保存时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
//		//	cstr = MyW2Ac(strTime);
//		//	LOG(0, cstr);
//		//	if (pwnd->Images.empty()) {
//		//		//CImages = pwnd->Images;
//		//	}
//		//	else {
//		//		CImages = pwnd->Images;
//		//		//SYSTEMTIME st;
//		//		CString TestFolder;
//		//		GetLocalTime(&st);
//		//		TestFolder.Format(TEXT("CameraTest%2d-%2d"), st.wMonth, st.wDay);
//		//		if ((GetFileAttributesA((LPCSTR)TestFolder.GetString())) != FILE_ATTRIBUTE_DIRECTORY) {
//		//			bool flag = CreateDirectory(TestFolder.GetString(), NULL);
//		//			// flag 为 true 说明创建成功
//		//		}
//		//		for (int i = 0; i < pwnd->m_param->GrabNum; i++) {
//		//			//name.Format(TEXT("/%2d-%2d-%2d.jpg"), st.wHour, st.wMinute, st.wMilliseconds);
//		//			name.Format(TEXT("/%02d-%02d-%02d-%d.jpg"), st.wHour, st.wMinute, st.wMilliseconds, i);
//		//			name = TestFolder + name;
//		//			USES_CONVERSION;
//		//			imwrite(W2A(name), CImages[i]);
//		//			GetLocalTime(&st);
//		//			strTime.Format(TEXT("保存时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
//		//			cstr = MyW2Ac(strTime);
//		//			LOG(0, cstr);
//		//		}
//		//	}
//
//		//}
//	}
//	return 0;
//}

void CameraParamDlg::OnBnClickedButGrayStill()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_Camera->UpdateCamera();
	//m_Camera->SetTriggerModel(TRUE);

	Sustain = !Sustain;
	//if (((CButton*)GetDlgItem(IDC_CHECK_TRIGER))->GetCheck()) {
	//	Capture_flag = 3;
	//}
	//else {
	//	Capture_flag = 4;
	//}

	if (Sustain)
	{
		Capture_flag = 3;
		ConnectCam();
		SetEvent(CAPTURE_EVENT);
		//GetDlgItem(IDC_BUT_GRAY_SINGLE)->EnableWindow(FALSE);
		//GetDlgItem(IDC_BUT_DISCONNEXTION)->EnableWindow(FALSE);
		SetDlgItemText(IDC_BUT_GRAY_STILL, TEXT("停止采集"));
	}
	else
	{
		//m_Camera->StopGraphImage();
		//WaitForSingleObject(COMPLETE_EVENT, 1000);
		//SetEvent(CAPTURE_EVENT);
		ResetEvent(COMPLETE_EVENT);
		//GetDlgItem(IDC_BUT_GRAY_SINGLE)->EnableWindow(TRUE);
		//GetDlgItem(IDC_BUT_DISCONNEXTION)->EnableWindow(TRUE);
		SetDlgItemText(IDC_BUT_GRAY_STILL, TEXT("连续采图"));
		OutConnect();
	}
}


//void CameraParamDlg::OnBnClickedButDisconnextion()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	if (m_Camera->IsOpen())
//	{
//		m_Camera->CloseCamera();
//	}
//	GetDlgItem(IDC_BUT_CONNECTION_TEST)->EnableWindow(TRUE);
//	GetDlgItem(IDC_BUT_GRAY_SINGLE)->EnableWindow(FALSE);
//	GetDlgItem(IDC_BUT_GRAY_STILL)->EnableWindow(FALSE);
//}


void CameraParamDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//if (nID == SC_MOVE || nID == 0xF012) {
	//	return;
	//}
	//else {
		CDialogEx::OnSysCommand(nID, lParam);
	//}
}


void CameraParamDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
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
