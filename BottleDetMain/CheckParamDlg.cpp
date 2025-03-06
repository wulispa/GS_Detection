// CheckParamDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "CheckParamDlg.h"
#include "afxdialogex.h"
#include "BeginDlg.h"


// CheckParamDlg 对话框

IMPLEMENT_DYNAMIC(CheckParamDlg, CDialogEx)
DWORD WINAPI LoadingCheck(LPVOID pthread)
{
	CheckParamDlg* pwnd = (CheckParamDlg*)pthread;
	//pwnd->StartRun();
	//Sleep(5000);
	//if (pwnd->ChoseModel == TEXT("NONE&TRA")) {
	//	pwnd->m_algorithm.UpdateAlgorithm(pwnd->contra_val_vec, pwnd->area_val_vec, pwnd->gray_val_vec);
	//}
	//else {
		//pwnd->m_algorithm.UpdateAImodel(TRUE);
		//pwnd->m_algorithm.UpdateAlgorithm(pwnd->contra_val_vec, pwnd->area_val_vec, pwnd->gray_val_vec);
		pwnd->m_algorithm.UpdateAlgorithm(pwnd->contra_val_vec, pwnd->area_val_vec, pwnd->gray_val_vec, pwnd->ChoseModel);
		//}
	//pwnd->m_AlgorithmIdentify.UpdateAlgorithm();
	HWND Starting = ::FindWindow(NULL, _T("启动中"));
	::SendMessage(Starting, WM_CLOSE, NULL, NULL);
	return 0;
}


double str2double(CString str)
{
	 int intpart = 0;
	 int decpart = 0;
	 double dreturn = 0;
	 USES_CONVERSION;
	 intpart = (double)atof(T2A(str));
	 int leng = str.GetLength();
	 int ipos = str.Find(_T("."));
	 if (-1 == ipos)
	 {
	  return intpart;
	 }
	 int ilen = leng - ipos - 1;
	 CString strdec = str.Right(ilen);
	  decpart = (double)atof(T2A(strdec));
	 double dtemp = decpart*pow(10.0, 0 - ilen);

	 dreturn = intpart + dtemp;

	 return dreturn;
}

//检测主线程
DWORD WINAPI CheckThread(LPVOID pthread)
{
	CheckParamDlg* m_win = (CheckParamDlg*)pthread;
	while (true)
	{
		WaitForSingleObject(m_win->CHECK_EVENT, INFINITE);
		if (m_win->m_Exit) {
			break;
		}
		m_win->CheckByAlgorithm();
		ResetEvent(m_win->CHECK_EVENT);
		Sleep(200);
	}
	return 0;
}
CheckParamDlg::CheckParamDlg(CWnd* pParent, DataManager* pdata)
	: CDialogEx(IDD_CHECK_PARAM_DIALOG, pParent),
	m_pData(pdata),
	Show_region(FALSE),
	m_Exit(false),
	isChecking(false),
	isImage(false),
	m_Cam(CameraBasler(pdata)),
	m_algorithm(AlgorithmBase(pdata))
	//m_AlgorithmIdentify(AlgorithmIdentify(pdata))
{
	m_pData->LoadBottleParam();//
	m_pData->LoadBottleDetParam();

	CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	hTestThreaed = CreateThread(NULL, 0, CheckThread, this, 0, NULL);

}
CheckParamDlg::CheckParamDlg(CWnd* pParent , DataManager* pdata/*=nullptr*/, Mat img)//重载
	: CDialogEx(IDD_CHECK_PARAM_DIALOG, pParent),
	m_pData(pdata),
	Show_region(FALSE),
	m_Exit(false),
	isChecking(false),
	isImage(false),
	m_algorithm(AlgorithmBase(pdata)),
	m_Cam(CameraBasler(pdata)),
	//m_AlgorithmIdentify(AlgorithmIdentify(pdata)),
	Image(img)
{
	m_pData->LoadBottleParam();//
	m_pData->LoadBottleDetParam();
	
	CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	hTestThreaed= CreateThread(NULL, 0, CheckThread, this, 0, NULL);
	
	//Image = img;
}

CheckParamDlg::CheckParamDlg(CWnd* pParent, DataManager* pdata, vector<Mat> imgs)
	: CDialogEx(IDD_CHECK_PARAM_DIALOG, pParent),
	m_pData(pdata),
	Show_region(FALSE),
	m_Exit(false),
	isChecking(false),
	isImage(false),
	m_algorithm(AlgorithmBase(pdata)),
	m_Cam(CameraBasler(pdata)),
	//m_AlgorithmIdentify(AlgorithmIdentify(pdata)),
	Images(imgs),
	number(0)
{
	m_pData->LoadBottleParam();//
	m_pData->LoadBottleDetParam();

	CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	hTestThreaed = CreateThread(NULL, 0, CheckThread, this, 0, NULL);
	//Images = Images[0];
}

CheckParamDlg::CheckParamDlg(CWnd* pParent, DataManager* pdata, vector<Mat> imgs, Detection* m_Detection)
	: CDialogEx(IDD_CHECK_PARAM_DIALOG, pParent),
	m_pData(pdata),
	Show_region(FALSE),
	m_Exit(false),
	isChecking(false),
	isImage(false),
	m_Det(m_Detection),
	m_algorithm(AlgorithmBase(pdata)),
	m_Cam(CameraBasler(pdata)),
	//m_AlgorithmIdentify(AlgorithmIdentify(pdata)),
	Images(imgs),
	number(0)
{
	m_pData->LoadBottleParam();//
	m_pData->LoadBottleDetParam();

	CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	hTestThreaed = CreateThread(NULL, 0, CheckThread, this, 0, NULL);
	//Images = Images[0];

}

CheckParamDlg::CheckParamDlg(CWnd* pParent, DataManager* pdata, vector<Mat> imgs,
	Detection* m_Detection, AlgorithmBase m_algo)
	: CDialogEx(IDD_CHECK_PARAM_DIALOG, pParent),
	m_pData(pdata),
	Show_region(FALSE),
	m_Exit(false),
	isChecking(false),
	isImage(false),
	m_Det(m_Detection),
	m_algorithm(m_algo),
	m_Cam(CameraBasler(pdata)),
	//m_AlgorithmIdentify(AlgorithmIdentify(pdata)),
	Images(imgs),
	number(0)
{
	m_pData->LoadBottleParam();//
	m_pData->LoadBottleDetParam();

	CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	hTestThreaed = CreateThread(NULL, 0, CheckThread, this, 0, NULL);
}

CheckParamDlg::~CheckParamDlg()
{
	CloseHandle(hTestThreaed);
	m_font->DeleteObject();
	if (!m_pData->CamImages.empty()) {
		vector<Mat>().swap(m_pData->CamImages);
	}
}

void CheckParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_SHOW_REGION, m_RadioShowRegion);
	//DDX_Control(pDX, IDC_COMBO_IMAGE_NUM, Image_num_box);

}


BEGIN_MESSAGE_MAP(CheckParamDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUT_LOAD_MODEL, &CheckParamDlg::OnBnClickedButLoadModel)
	ON_BN_CLICKED(IDC_BUT_LOAD_PARAM_FILE, &CheckParamDlg::OnBnClickedButLoadParamFile)
	ON_BN_CLICKED(IDC_BUT_LOAD_IMAGE, &CheckParamDlg::OnBnClickedButLoadImage)
	ON_BN_CLICKED(IDC_BUT_SAVE_PARAM, &CheckParamDlg::OnBnClickedButSaveParam)
	ON_BN_CLICKED(IDC_BUT_EXIT_DET_PARAM, &CheckParamDlg::OnBnClickedButExitDetParam)
	ON_BN_CLICKED(IDC_BUT_RUN_TEST, &CheckParamDlg::OnBnClickedButRunTest)
	ON_BN_CLICKED(IDC_BUT_CHANGE_CLASS_DET, &CheckParamDlg::OnBnClickedButChangeClassDet)
	ON_BN_CLICKED(IDC_BUT_MOLD_SELECT, &CheckParamDlg::OnBnClickedButMoldSelect)
	//ON_BN_CLICKED(IDC_BUT_OUTER_RECTANGLE, &CheckParamDlg::OnBnClickedButOuterRectangle)
	ON_BN_CLICKED(IDC_BUT_OUTER_CYCLE, &CheckParamDlg::OnBnClickedButOuterCycle)
	//ON_BN_CLICKED(IDC_BUT_OUTER_POLYGON, &CheckParamDlg::OnBnClickedButOuterPolygon)
	//ON_BN_CLICKED(IDC_BUT_INNER_RECTANGLE, &CheckParamDlg::OnBnClickedButInnerRectangle)
	ON_BN_CLICKED(IDC_BUT_INNER_CYCLE, &CheckParamDlg::OnBnClickedButInnerCycle)
	//ON_BN_CLICKED(IDC_BUT_INNER_POLYGON, &CheckParamDlg::OnBnClickedButInnerPolygon)
	ON_BN_CLICKED(IDC_BUT_DELETE_REGION, &CheckParamDlg::OnBnClickedButDeleteRegion)
	ON_BN_CLICKED(IDC_BUT_SAVE_REGION, &CheckParamDlg::OnBnClickedButSaveRegion)
	//ON_BN_CLICKED(IDC_BUT_LAST, &CheckParamDlg::OnBnClickedBtnLast)
	//ON_BN_CLICKED(IDC_BUT_NEXT, &CheckParamDlg::OnBnClickedBtnNext)
	ON_BN_CLICKED(IDC_BUT_AITOOL, &CheckParamDlg::OnBnClickedButAitool)
	ON_WM_SYSCOMMAND()
	//ON_CBN_SELCHANGE(IDC_COMBO_IMAGE_NUM, &CheckParamDlg::OnCbnSelchangeComboImageNum)
	ON_BN_CLICKED(IDC_BUT_GRAB_TEST, &CheckParamDlg::OnBnClickedButGrabTest)
	ON_BN_CLICKED(IDC_RADIO_MASK1, &CheckParamDlg::OnBnClickedRadioMask1)
	ON_BN_CLICKED(IDC_RADIO_MASK2, &CheckParamDlg::OnBnClickedRadioMask2)
	ON_BN_CLICKED(IDC_RADIO_MASK3, &CheckParamDlg::OnBnClickedRadioMask3)
	ON_BN_CLICKED(IDC_RADIO_MASK4, &CheckParamDlg::OnBnClickedRadioMask4)

	ON_BN_CLICKED(IDC_RADIO_PIC1, &CheckParamDlg::OnBnClickedRadioPic1)
	ON_BN_CLICKED(IDC_RADIO_PIC2, &CheckParamDlg::OnBnClickedRadioPic2)
	ON_BN_CLICKED(IDC_RADIO_PIC3, &CheckParamDlg::OnBnClickedRadioPic3)
	ON_BN_CLICKED(IDC_RADIO_PIC4, &CheckParamDlg::OnBnClickedRadioPic4)
	ON_BN_CLICKED(IDC_RADIO_PIC5, &CheckParamDlg::OnBnClickedRadioPic5)
	ON_WM_WINDOWPOSCHANGING()
	ON_BN_CLICKED(IDC_BUTTON3, &CheckParamDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_CullingTest, &CheckParamDlg::OnBnClickedButtonCullingtest)
END_MESSAGE_MAP()


// CheckParamDlg 消息处理程序


BOOL CheckParamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_RADIO_SHOW_REGION)->ShowWindow(FALSE); 
	GetDlgItem(IDC_BUT_LOAD_MODEL)->ShowWindow(FALSE);

	GetDlgItem(IDC_MODEL_LABEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_MODEL_BOX)->ShowWindow(FALSE);

	GetDlgItem(IDC_BUT_OUTER_RECTANGLE)->ShowWindow(FALSE);///四个绘制区域按钮的隐藏
	GetDlgItem(IDC_BUT_INNER_RECTANGLE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_OUTER_POLYGON)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_INNER_POLYGON)->ShowWindow(FALSE);
		
	GetDlgItem(IDC_DETTHRE_LABEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_NEXT)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_NUMBER)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_LAST)->ShowWindow(FALSE);
	GetDlgItem(IDC_COMBO_IMAGE_NUM)->ShowWindow(FALSE);
	GetDlgItem(IDC_AREA_DET)->ShowWindow(FALSE);
	GetDlgItem(IDC_CENTER_DET)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_AREA_AI)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_GRAB_TEST)->ShowWindow(FALSE);
	//GetDlgItem(IDC_BUT_MOLD_SELECT)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHOSE_ALGO_BOX)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK_CENTER_AI)->ShowWindow(TRUE);
	GetDlgItem(IDC_CHECK_CENTER_TRADITION)->ShowWindow(TRUE);
	GetDlgItem(IDC_RADIO_PIC1)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_PIC2)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_PIC3)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_PIC4)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_PIC5)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_SHOW)->ShowWindow(FALSE);

	GetDlgItem(IDC_BOTTLE_DET_CLASS)->ShowWindow(FALSE);
	GetDlgItem(IDC_BOTTLE_DET_CLASS_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_CHANGE_CLASS_DET)->ShowWindow(FALSE);
	GetDlgItem(IDC_PARAM_FILE_LABEL)->ShowWindow(FALSE);
	GetDlgItem(IDC_PARAM_FILE_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_LOAD_PARAM_FILE)->ShowWindow(FALSE);
	GetDlgItem(IDC_DET_PARAM_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHOSE_ALGO_BOX)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_CENTER_TRADITION)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_CENTER_AI)->ShowWindow(FALSE);
	GetDlgItem(IDC_BOX_DRAWREGION)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_MASK1)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_MASK2)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_MASK3)->ShowWindow(FALSE);
	GetDlgItem(IDC_RADIO_MASK4)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_AREA_THRESH)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_DET_THRE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_OUTER_CYCLE)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_LBW_THRESH)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_LBW_THRESH)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_INNER_CYCLE)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_GRAY)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_GRAY_VALUE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_DELETE_REGION)->ShowWindow(FALSE);
	GetDlgItem(IDC_CHECK_DUIBI)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_DUIBI_VALUE)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_SAVE_REGION)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_MOLD_SELECT)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_AITOOL)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUT_SAVE_PARAM)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_TEST_Deadline)->ShowWindow(FALSE);
	DownLoadParam();
	m_win.OpenWindow(GetDlgItem(IDC_TEST_IMAGE_WIN));
	CString str(m_pData->GetSelectBottleName().c_str());
	SetDlgItemText(IDC_BOTTLE_DET_CLASS_BOX, str);
	GetDlgItemText(IDC_MODEL_BOX,model_path);
	if (!Images.empty()) {
		Image = Images[0];
		((CButton*)GetDlgItem(IDC_RADIO_PIC1))->SetCheck(TRUE);
	}
	if (!Image.empty()) {
		ShowAndTrans(Image);
		if (!isHalconWinOpen)
		{
			OpenHalconWin();
		}
		//GetDlgItem(IDC_BUT_LAST)->EnableWindow(FALSE);
		//SetDlgItemText(IDC_STATIC_NUMBER, TEXT("第1张图片"));
	}
	else {
		//GetDlgItem(IDC_COMBO_IMAGE_NUM)->EnableWindow(FALSE);

		//GetDlgItem(IDC_BUT_LAST)->EnableWindow(FALSE);
		//GetDlgItem(IDC_BUT_NEXT)->EnableWindow(FALSE);
		//SetDlgItemText(IDC_STATIC_NUMBER, TEXT(""));
	}
	m_font = new CFont();
	InitWindowFront();//初始化字体
	//Image_num_box.AddString(TEXT("请选择图片"));
	//Image_num_box.SetCurSel(number);
	//Image_num_box.AddString(TEXT("第1张"));
	//Image_num_box.AddString(TEXT("第2张"));
	//Image_num_box.AddString(TEXT("第3张"));
	//Image_num_box.AddString(TEXT("第4张"));
	//Image_num_box.AddString(TEXT("第5张"));
	Mask_flag = 0;
	((CButton*)GetDlgItem(IDC_RADIO_MASK1))->SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CheckParamDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CheckParamDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void CheckParamDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	//绘制背景
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	//dc.FillSolidRect(rect, RGB(157, 172, 253));
	InitControlColor(IDC_TEST_IMAGE_WIN, RGB(0, 0, 0));
	//CDialogEx::OnPaint();
}


void CheckParamDlg::OnBnClickedButLoadModel()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("model files(*.pt)|*.jpg|Worksheet Files|*.xls|All Files(*.*)|*.*||"),
		NULL);                            // 构造文件打开对话框  
	dlg.m_ofn.lpstrTitle = _T("添加模型文件");  // 文件打开对话框标题  
	if (IDOK != dlg.DoModal())                 // 判断是否成功选中文件  
		return;
	model_path = dlg.GetPathName();         // 获取文件路径
	SetDlgItemText(IDC_MODEL_BOX, model_path);
	//Profile_path = GetArrayFromCstringBySep(model_path,'\\');
	SetDlgItemText(IDC_PARAM_FILE_BOX, Profile_path);

}
CString CheckParamDlg::GetArrayFromCstringBySep(const CString& str, const TCHAR cSep)
{
	CString CurrStr = str;
	std::vector<CString> DataList;
	int CurrPos;
	CString res;
	while ((CurrPos = CurrStr.Find(cSep)) != -1)
	{
		res = res + CurrStr.Left(CurrPos)+TEXT("\\");
		DataList.push_back(CurrStr.Left(CurrPos));
		CurrStr = CurrStr.Right(CurrStr.GetLength() - CurrPos - 1);
	}
	if (!str.IsEmpty())
	{
		DataList.push_back(str.Left(CurrPos));
	}
	res - DataList[DataList.size() - 1];
	res=res+TEXT("Profile.txt");
	

	return res;
}

void CheckParamDlg::ShowAndTrans(Mat img)
{
	ShowImage(img);

	ho_Image = Mat2HObject(img);
	isImage = true;
	//需求：打开新图片时应当关闭旧窗口，清除内存并打开新窗口，显示画好的mask
	if (isHalconWinOpen)
	{
		m_HalconWin.closeWindow();
	}
	OpenHalconWin();
}

void CheckParamDlg::DownLoadParam()
{
	string ss = m_pData->GetBottleDetParam()->Model_Path;
	model_path = (m_pData->GetBottleDetParam()->Model_Path).c_str();
	Profile_path=(m_pData->GetBottleDetParam()->Profile_Path).c_str();
	ThreadValue=m_pData->GetBottleDetParam()->ThreadValue;
	ThreadValueLW = m_pData->GetBottleDetParam()->ThreadValueLW;
	ThreadModel = (m_pData->GetBottleDetParam()->ThreadModel).c_str();
	GrayValue = m_pData->GetBottleDetParam()->GrayValue;
	GrayModel = (m_pData->GetBottleDetParam()->GrayModel).c_str();
	ChoseModel = (m_pData->GetBottleDetParam()->ChoseModel).c_str();

	/*GS码*/
	TriggerDistance = (m_pData->GetBottleDetParam()->TriggerDistance).c_str();
	PhotoelectricDistance = (m_pData->GetBottleDetParam()->PhotoelectricDistance).c_str();
	SetDlgItemText(IDC_EDIT_TriggerDistance, TriggerDistance);
	SetDlgItemText(IDC_EDIT_PhotoelectricDistance, PhotoelectricDistance);
	DeadLine =m_algorithm.Deadline.c_str();
	UpMold = m_algorithm.UpCode.c_str();
	DownMold = m_algorithm.DownCode.c_str();
	UpNumber = m_algorithm.UpNumber.c_str();
	DownNumber = m_algorithm.DownNumber.c_str();
	UpResult = m_algorithm.UpResult.c_str();
	DownResult = m_algorithm.DownResult.c_str();
	SetDlgItemText(IDC_IMAGE_IDC_EDIT_TESTDEADLINE, DeadLine);
	SetDlgItemText(IDC_TEST_UPREAD_MOLD, UpMold);
	SetDlgItemText(IDC_UPREAD_NUMBER, UpNumber);
	SetDlgItemText(IDC_TEST_UPRESULT, UpResult);
	SetDlgItemText(IDC_TEST_DOWNREAD_MOLD, DownMold);
	SetDlgItemText(IDC_DOWNREAD_NUMBER, DownNumber);
	SetDlgItemText(IDC_TEST_DOWNRESULT, DownResult);
	
	/*string contra_val = m_pData->GetBottleDetParam()->contra_val;
	contra_val_vec = Str2Vec(contra_val);
	if (contra_val_vec[0] > 0) {
		((CButton*)GetDlgItem(IDC_CHECK_DUIBI))->SetCheck(TRUE);
	}
	else {
		((CButton*)GetDlgItem(IDC_CHECK_DUIBI))->SetCheck(FALSE);
	}
	string area_val = m_pData->GetBottleDetParam()->area_val;
	area_val_vec = Str2Vec(area_val);
	if (area_val_vec[0] > 0) {
		((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->SetCheck(TRUE);
	}
	else {
		((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->SetCheck(FALSE);
	}
	string gray_val = m_pData->GetBottleDetParam()->gray_val;
	gray_val_vec = Str2Vec(gray_val);
	if (area_val_vec[0] > 0) {
		((CButton*)GetDlgItem(IDC_CHECK_GRAY))->SetCheck(TRUE);
	}
	else {
		((CButton*)GetDlgItem(IDC_CHECK_GRAY))->SetCheck(FALSE);
	}*/
	//if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON")
	//{
	//	Mold_Recognition = TRUE;
	//}
	//else if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDOFF")
	//{
	//	Mold_Recognition = FALSE;
	//}
	//else {
	//	Mold_Recognition = TRUE;
	//}

	/*if (m_pData->GetBottleDetParam()->Show_Region == "TRUE")
	{
		Show_region = TRUE;
		((CButton*)GetDlgItem(IDC_CHECK_SHOW))->SetCheck(TRUE);
	}
	else
	{
		Show_region = FALSE;
		((CButton*)GetDlgItem(IDC_CHECK_SHOW))->SetCheck(FALSE);
	}*/

	//if (ThreadModel == "AREA")
	//{
	//	((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->SetCheck(TRUE);
	//	((CButton*)GetDlgItem(IDC_CHECK_LBW_THRESH))->SetCheck(FALSE);
	//}
	//else if (ThreadModel == "LW")
	//{
	//	((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->SetCheck(FALSE);
	//	((CButton*)GetDlgItem(IDC_CHECK_LBW_THRESH))->SetCheck(TRUE);
	//}
	//else if (ThreadModel == "BOTH")
	//{
	//	((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->SetCheck(TRUE);
	//	((CButton*)GetDlgItem(IDC_CHECK_LBW_THRESH))->SetCheck(TRUE);
	//}
	//else if (ThreadModel == "NO")
	//{
	//	((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->SetCheck(FALSE);
	//	((CButton*)GetDlgItem(IDC_CHECK_LBW_THRESH))->SetCheck(FALSE);
	//}

	//if (GrayModel == TEXT("TRUE"))
	//{
	//	((CButton*)GetDlgItem(IDC_CHECK_GRAY))->SetCheck(TRUE);
	//}
	//else
	//{
	//	((CButton*)GetDlgItem(IDC_CHECK_GRAY))->SetCheck(FALSE);
	//}

	if (ChoseModel == TEXT("AI&AI"))
	{
		//((CButton*)GetDlgItem(IDC_CHECK_CENTER_AI))->SetCheck(TRUE);
		//((CButton*)GetDlgItem(IDC_CHECK_CENTER_TRADITION))->SetCheck(FALSE);
		//((CButton*)GetDlgItem(IDC_CHECK_AREA_AI))->SetCheck(TRUE);
	}
	else if (ChoseModel == TEXT("AI&TRA"))
	{
		((CButton*)GetDlgItem(IDC_CHECK_CENTER_AI))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_CHECK_CENTER_TRADITION))->SetCheck(TRUE);
		//((CButton*)GetDlgItem(IDC_CHECK_AREA_AI))->SetCheck(TRUE);
	}
	else if (ChoseModel == TEXT("NONE&AI"))
	{
		((CButton*)GetDlgItem(IDC_CHECK_CENTER_AI))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_CHECK_CENTER_TRADITION))->SetCheck(FALSE);
		//((CButton*)GetDlgItem(IDC_CHECK_AREA_AI))->SetCheck(FALSE);
	}
	else if (ChoseModel == TEXT("NONE&TRA"))
	{
		((CButton*)GetDlgItem(IDC_CHECK_CENTER_AI))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_CHECK_CENTER_TRADITION))->SetCheck(TRUE);
		//((CButton*)GetDlgItem(IDC_CHECK_AREA_AI))->SetCheck(FALSE);
	}

	//CString value;
	////value.Format(TEXT("%.2lf"), ThreadValue);
	////SetDlgItemText(IDC_EDIT_DET_THRE, value);
	//value.Format(TEXT("%.2lf"), ThreadValueLW);
	//SetDlgItemText(IDC_EDIT_LBW_THRESH, value);
	////value.Format(TEXT("%.d"), GrayValue);
	////SetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//value.Format(TEXT("%.d"), contra_val_vec[0]);
	//SetDlgItemText(IDC_EDIT_DUIBI_VALUE, value);
	//value.Format(TEXT("%.d"), area_val_vec[0]);
	//SetDlgItemText(IDC_EDIT_DET_THRE, value);
	//value.Format(TEXT("%.d"), gray_val_vec[0]);
	//SetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//SetDlgItemText(IDC_MODEL_BOX, model_path);
	//SetDlgItemText(IDC_PARAM_FILE_BOX, Profile_path);
}

void CheckParamDlg::UpLoadParam()
{

	//m_pData->SetModel_Path(model_path);
	//m_pData->SetProfile_Path(Profile_path);
	CString value;
	//GetDlgItemText(IDC_EDIT_DET_THRE, value);
	//m_pData->SetThreadValue(value);
	//GetDlgItemText(IDC_EDIT_LBW_THRESH, value);
	//m_pData->SetThreadValueLW(value);
	//GetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//m_pData->SetGrayValue(value);
	/*if (((CButton*)GetDlgItem(IDC_RADIO_MASK1))->GetCheck()) {
		SaveLast(0);
	}
	if (((CButton*)GetDlgItem(IDC_RADIO_MASK2))->GetCheck()) {
		SaveLast(1);
	}
	if (((CButton*)GetDlgItem(IDC_RADIO_MASK3))->GetCheck()) {
		SaveLast(2);
	}
	if (((CButton*)GetDlgItem(IDC_RADIO_MASK4))->GetCheck()) {
		SaveLast(3);
	}
	CString ContraVal = Vec2CStr(contra_val_vec);
	CString AreaVal = Vec2CStr(area_val_vec);
	CString GrayVal = Vec2CStr(gray_val_vec);
	m_pData->SetTraditionalPara(ContraVal, AreaVal, GrayVal);
	if (((CButton*)GetDlgItem(IDC_CHECK_GRAY))->GetCheck())
	{
		m_pData->SetGrayThresh(TEXT("TRUE"));
	}
	else
	{
		m_pData->SetGrayThresh(TEXT("FALSE"));
	}

	if (((CButton*)GetDlgItem(IDC_CHECK_SHOW))->GetCheck())
	{
		m_pData->SetShow_Region(TEXT("TRUE"));
	}
	else
	{
		m_pData->SetShow_Region(TEXT("FALSE"));
	}*/

	//if (Mold_Recognition)
	//{
	//	m_pData->SetMoldRecognition(TEXT("MOLDON"));
	//}
	//else {
	//	m_pData->SetMoldRecognition(TEXT("MOLDOFF"));
	//}

	//BOOL AREA_MODEL = ((CButton*)GetDlgItem(IDC_CHECK_AREA_THRESH))->GetCheck();
	//BOOL LW_MODEL = ((CButton*)GetDlgItem(IDC_CHECK_LBW_THRESH))->GetCheck();
	//if (LW_MODEL)
	//{
	//	m_pData->SetThreadValueModel(TEXT("LW"));
	//}

	//if (AREA_MODEL && LW_MODEL)
	//{
	//	m_pData->SetThreadValueModel(TEXT("BOTH"));
	//}
	//else if (AREA_MODEL)
	//{
	//	m_pData->SetThreadValueModel(TEXT("AREA"));
	//}
	//else if (LW_MODEL)
	//{
	//	m_pData->SetThreadValueModel(TEXT("LW"));
	//}
	//else if(!AREA_MODEL && !LW_MODEL)
	//{
	//	m_pData->SetThreadValueModel(TEXT("NO"));
	//}

	BOOL CENTER_AI= ((CButton*)GetDlgItem(IDC_CHECK_CENTER_AI))->GetCheck();
	BOOL CENTER_TRA = ((CButton*)GetDlgItem(IDC_CHECK_CENTER_TRADITION))->GetCheck();
	//BOOL AREA_AI = ((CButton*)GetDlgItem(IDC_CHECK_AREA_AI))->GetCheck();

	//if (CENTER_AI && AREA_AI)
	//{
	//	m_pData->SetChoseModel(TEXT("AI&AI"));
	//}
	if (CENTER_TRA && CENTER_AI)
	{
		m_pData->SetChoseModel(TEXT("AI&TRA"));
	}
	else if (CENTER_AI)
	{
		m_pData->SetChoseModel(TEXT("NONE&AI"));
	}
	else if (CENTER_TRA)
	{
		m_pData->SetChoseModel(TEXT("NONE&TRA"));
	}

	m_pData->LoadBottleParam();//
	m_pData->LoadBottleDetParam();
}



void CheckParamDlg::OnBnClickedButLoadParamFile()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("param files(*.txt)|*.txt|Worksheet Files|*.xls|All Files(*.*)|*.*||"),
		NULL);                            // 构造文件打开对话框  
	dlg.m_ofn.lpstrTitle = _T("添加配置文件");  // 文件打开对话框标题  
	if (IDOK != dlg.DoModal())                 // 判断是否成功选中文件  
		return;
	Profile_path = dlg.GetPathName();         // 获取文件路径
	SetDlgItemText(IDC_PARAM_FILE_BOX, Profile_path);
	model_path = GetArrayFromCstringBySep(Profile_path,'\\');
	SetDlgItemText(IDC_PARAM_FILE_BOX, Profile_path);
}

CString CheckParamDlg::Vec2CStr(vector<int> vals)
{
	string strData;
	CString ress;
	for (int data : vals) {
		strData += std::to_string(data) + ",";
	}
	strData = strData.substr(0, strData.size() - 1);
	int str_leng = sizeof(strData);

	ress = CA2T(strData.c_str());
	return ress;
}

void CheckParamDlg::SaveLast(int MaskFlag)
{
	CString value;
	int temp;
	GetDlgItemText(IDC_EDIT_DUIBI_VALUE, value);
	temp = CStr2int(value);
	contra_val_vec[MaskFlag] = temp;

	GetDlgItemText(IDC_EDIT_DET_THRE, value);
	temp = CStr2int(value);
	area_val_vec[MaskFlag] = temp;

	GetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	temp = CStr2int(value);
	gray_val_vec[MaskFlag] = temp;

}


void CheckParamDlg::OnBnClickedButLoadImage()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("image files(*.jpg)|*.jpg;*.png;*.bmp|Worksheet Files|*.xls|All Files(*.*)|*.*||"),
		NULL);                            // 构造文件打开对话框  
	dlg.m_ofn.lpstrTitle = _T("添加图片");  // 文件打开对话框标题  
	if (IDOK != dlg.DoModal())                 // 判断是否成功选中文件  
		return;
	Image_path = dlg.GetPathName();         // 获取文件路径
	SetDlgItemText(IDC_IMAGE_PATH_BOX, Image_path);
	USES_CONVERSION;
	Image = imread(W2A(Image_path),0);
	ShowAndTrans(Image);
	//ShowImage(Image);
	//ho_Image = Mat2HObject(Image);
	//isImage = true;
}

HObject CheckParamDlg::Mat2HObject(cv::Mat& cv_img)
{
	HalconCpp::HObject H_img;

	if (cv_img.channels() == 1)
	{
		int height = cv_img.rows, width = cv_img.cols;
		int size = height * width;
		uchar* temp = new uchar[size];

		memcpy(temp, cv_img.data, size);
		HalconCpp::GenImage1(&H_img, "byte", width, height, (Hlong)(temp));

		delete[] temp;
	}
	else if (cv_img.channels() == 3)
	{
		int height = cv_img.rows, width = cv_img.cols;
		int size = height * width;
		uchar* B = new uchar[size];
		uchar* G = new uchar[size];
		uchar* R = new uchar[size];

		for (int i = 0; i < height; i++)
		{
			uchar* p = cv_img.ptr<uchar>(i);
			for (int j = 0; j < width; j++)
			{
				B[i * width + j] = p[3 * j];
				G[i * width + j] = p[3 * j + 1];
				R[i * width + j] = p[3 * j + 2];
			}
		}
		HalconCpp::GenImage3(&H_img, "byte", width, height, (Hlong)(R), (Hlong)(G), (Hlong)(B));

		delete[] R;
		delete[] G;
		delete[] B;
	}
	return H_img;
}

vector<int> CheckParamDlg::Str2Vec(string str)
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

int CheckParamDlg::str2int(string str)
{
	stringstream stream;     //声明一个stringstream变量
	int n;
	//string转int
	stream << str;     //向stream中插入字符串
	stream >> n;
	return n;
}

int CheckParamDlg::CStr2int(CString strr)
{
	int ii = 0;
	ii = _ttoi(strr);
	return ii;
}

void CheckParamDlg::OpenHalconWin()
{
	CWnd* pwnd = GetDlgItem(IDC_TEST_IMAGE_WIN);
	m_HalconWin.openWindow(pwnd);
	m_HalconWin.dispObj(ho_Image);
	m_HalconWin.getSourceImage(ho_Image);
	//增加：初始化窗口时读取mask并显示
	//HObject ho_SingleMaskImage, ho_Mask, ho_ROI, ho_EmptyRegion, ho_RegionIntersection;
	//HObject  ho_Background;
	//vector<HObject> ho_MaskImage;
	//ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//for (int i = 0; i < 4; i++)
	//{
	//	Rgb1ToGray(ho_MaskImage[i], &ho_Mask);
	//	Threshold(ho_Mask, &ho_ROI, 128, 255);
	//	GenEmptyRegion(&ho_EmptyRegion);
	//	if (0 != (ho_ROI == ho_EmptyRegion))
	//	{
	//		continue;
	//	}
	//	m_HalconWin.displayROI(ho_ROI, i);
	//}
	m_HalconWin.refreshROIWindow();
	isHalconWinOpen = true;
}

void CheckParamDlg::ShowImage(Mat& image)
{
	
	//Mat dst = m_win.PaintTxt(Trans2RGB(image), "OK");
	
	m_win.DispImage(image);
}

void CheckParamDlg::InitControlColor(int ID, COLORREF rgb)
{
	CRect mrect;
	GetDlgItem(ID)->GetClientRect(&mrect);
	FillRect(GetDlgItem(ID)->GetDC()->GetSafeHdc(), &mrect, CBrush(rgb));
}

void CheckParamDlg::InitWindowFront()
{
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 2;
	lfCtrl.lfHeight = 14;
	lfCtrl.lfItalic = false;
	lfCtrl.lfUnderline = false;
	lfCtrl.lfStrikeOut = false;
	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lfCtrl.lfFaceName, L"新宋体");
	lfCtrl.lfWeight = FW_HEAVY;
	m_font->CreateFontIndirectW(&lfCtrl);

	GetDlgItem(IDC_DET_PARAM_BOX)->SetFont(m_font);
	GetDlgItem(IDC_CHOSE_ALGO_BOX)->SetFont(m_font);
	GetDlgItem(IDC_OPERATE_BOX)->SetFont(m_font);

	GetDlgItem(IDC_BOTTLE_DET_CLASS)->SetFont(m_font);
	//GetDlgItem(IDC_BOTTLE_DET_CLASS_BOX)->SetFont(m_font);
	GetDlgItem(IDC_PARAM_FILE_LABEL)->SetFont(m_font);
	//GetDlgItem(IDC_PARAM_FILE_BOX)->SetFont(m_font);
	GetDlgItem(IDC_DETTHRE_LABEL)->SetFont(m_font);
	//GetDlgItem(IDC_CHECK_AREA_THRESH)->SetFont(m_font);
	//GetDlgItem(IDC_EDIT_DET_THRE)->SetFont(m_font);
	//GetDlgItem(IDC_CHECK_LBW_THRESH)->SetFont(m_font);
	//GetDlgItem(IDC_EDIT_LBW_THRESH)->SetFont(m_font);
	//GetDlgItem(IDC_CHECK_GRAY)->SetFont(m_font);
	//GetDlgItem(IDC_EDIT_GRAY_VALUE)->SetFont(m_font);

	//GetDlgItem(IDC_CENTER_DET)->SetFont(m_font);
	//GetDlgItem(IDC_AREA_DET)->SetFont(m_font);
	GetDlgItem(IDC_OPEN_IMAGE_LABEL)->SetFont(m_font);

	GetDlgItem(IDC_BUT_CHANGE_CLASS_DET)->SetFont(m_font);
	GetDlgItem(IDC_BUT_LOAD_PARAM_FILE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_MOLD_SELECT)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SAVE_PARAM)->SetFont(m_font);
	GetDlgItem(IDC_BUT_EXIT_DET_PARAM)->SetFont(m_font);
	GetDlgItem(IDC_BUT_LOAD_IMAGE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_RUN_TEST)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_OUTER_RECTANGLE)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_INNER_RECTANGLE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_OUTER_CYCLE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_INNER_CYCLE)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_OUTER_POLYGON)->SetFont(m_font);
	//GetDlgItem(IDC_BUT_INNER_POLYGON)->SetFont(m_font);
	GetDlgItem(IDC_BUT_DELETE_REGION)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SAVE_REGION)->SetFont(m_font);
	GetDlgItem(IDC_BUT_AITOOL)->SetFont(m_font);
	//GetDlgItem(IDC_COMBO_IMAGE_NUM)->SetFont(m_font);
	GetDlgItem(IDC_BOX_DRAWREGION)->SetFont(m_font);
	GetDlgItem(IDC_BUT_GRAB_TEST)->SetFont(m_font);

}

void CheckParamDlg::OnBnClickedButSaveParam()
{
	// TODO: 在此添加控件通知处理程序代码
	UpLoadParam();
}


void CheckParamDlg::OnBnClickedButExitDetParam()
{
	// TODO: 在此添加控件通知处理程序代码
	//点击退出按钮，通知线程函数退出
	m_Exit = true;
	if (!m_pData->CamImages.empty()) {
		vector<Mat>().swap(m_pData->CamImages);
	}
	SetEvent(CHECK_EVENT);
	CDialogEx::OnCancel();
}


void CheckParamDlg::OnBnClickedButRunTest()
{
	//UpLoadParam();
	//OnBnClickedButSaveRegion();
	vector<Mat>().swap(GetDetImages);

	SetEvent(CHECK_EVENT);

	//}

}
// 有使用
void CheckParamDlg::CheckByAlgorithm()
{
	isChecking = true;
	//do something;
	//走了elseif
	if (!GetDetImages.empty()) {
		m_algorithm.DoJob(GetDetImages, 5, isChecking);
		//int res = m_algorithm.GetCheckResult(isChecking);
		/*string detect_ID = m_algorithm.test_bottle_type;
		string name = m_algorithm.test_res_name;*/
		//ShowCheckResult(GetDetImages[0], m_algorithm.GetDetRects(), res, detect_ID);
		//ShowCheckResult(GetDetImages[0], m_algorithm.GetDetRects(), res, detect_ID, name);
	}
	else if (!Image.empty()) {
		vector<Mat> Imgs;
		for (int i = 0; i < 5; i++) {
			Imgs.push_back(Image);
		}
		//m_algorithm.DoJob(Image);
		m_algorithm.DoJob(Imgs, 5, isChecking);
		DownLoadParam();
		int res = m_algorithm.GetCheckResult(isChecking);
	/*	string detect_ID = m_algorithm.test_bottle_type;
		string name = m_algorithm.test_res_name;*/
		//ShowCheckResult(Image, m_algorithm.GetDetRects(), res, detect_ID);
		//ShowCheckResult(Image, m_algorithm.GetDetRects(), res, detect_ID, name);
	}
	isChecking = false;
}

void CheckParamDlg::ShowCheckResult(Mat image, vector<cv::Rect> m_points, int result, string detect_ID, string Name) 
{
	Mat show_image;
	if (image.channels() != 3)
	{
		show_image = Trans2RGB(image);
	}
	else
	{
		show_image = image.clone();
	}

	//if (result == 1)
	//{
	//	m_win.PaintTxt(show_image, "OK");
	//	m_win.putTextZH(show_image, "良品", Point(60, 250), Scalar(255, 0, 0), 60);
	//}
	//else
	//{
	//	const char* name1 = nullptr;
	//	name1 = Name.c_str();
	//	m_win.putTextZH(show_image, name1, Point(60, 250), Scalar(255, 0, 0), 60);
	//	m_win.PaintTxt(show_image, "NG");
	//	for (int index = 0; index < m_points.size(); index++)
	//	{
	//		m_win.PaintRectangle(show_image, m_points[index], Scalar(0, 0, 255));

	//	}
	//}
	//if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON") {
	//	//putText(show_image, m_pData->GetSystemParam()->TargetID, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
	//	putText(show_image, m_pData->GetBottleDetParam()->SelectedMold, Point(700, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
	//	vector<int> TargetID = Str2Vec(m_pData->GetBottleDetParam()->SelectedMold);
	//	int detect_id = str2int(detect_ID);
	//	if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end())
	//	{
	//		putText(show_image, detect_ID, Point(700, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 3, 3);
	//	}
	//	else
	//	{
	//		putText(show_image, detect_ID, Point(700, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
	//	}
	//}

	m_win.ClearWindow();
	m_win.DispImage(show_image);

}

void CheckParamDlg::ShowCheckResult(Mat image, vector<cv::Rect> m_points, int result, string detect_ID)
{
	Mat show_image;
	if (image.channels() != 3)
	{
		show_image=Trans2RGB(image);
	}
	else
	{
		show_image = image.clone();
	}

	if (result == 1)
	{
		m_win.PaintTxt(show_image, "OK");
	}
	else
	{
		m_win.PaintTxt(show_image, "NG");
		for (int index = 0; index < m_points.size(); index++)
		{
			m_win.PaintRectangle(show_image, m_points[index], Scalar(0, 0, 255));

		}
	}
	if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON") {
		//putText(show_image, m_pData->GetSystemParam()->TargetID, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
		putText(show_image, m_pData->GetBottleDetParam()->SelectedMold, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
		vector<int> TargetID = Str2Vec(m_pData->GetBottleDetParam()->SelectedMold);
		int detect_id = str2int(detect_ID);
		if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end())
		{
			putText(show_image, detect_ID, Point(700, 120), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 255, 0), 3, 3);
		}
		else
		{
			putText(show_image, detect_ID, Point(700, 120), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
		}
	}
	
	m_win.ClearWindow();
	m_win.DispImage(show_image);
	//imwrite("hemksjks.jpg", image);
}

void CheckParamDlg::ShowCheckResult(Mat image, int result)
{
	Mat dst=m_win.PaintTxt(image, "OK");
	m_win.DispImage(dst);

}


void CheckParamDlg::OnBnClickedButChangeClassDet()
{
	// TODO: 在此添加控件通知处理程序代码
	ChangeClassDlg dlg(this, m_pData);
	dlg.DoModal();
	m_pData->LoadBottleParam();
	
	CString str(m_pData->GetSelectBottleName().c_str());
	SetDlgItemText(IDC_BOTTLE_DET_CLASS_BOX, str);
	m_pData->LoadBottleDetParam();
	DownLoadParam();
}

Mat CheckParamDlg::Trans2RGB(Mat& image)
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


void CheckParamDlg::OnBnClickedButMoldSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	MoldSelectDlg Dlg(this, m_pData);
	Dlg.DoModal();
	//m_pData->LoadBottleParam();
	//m_pData->LoadBottleDetParam();
	//UpLoadParam();

}



//void CheckParamDlg::OnBnClickedButOuterRectangle()
//{
//	if (!isImage)
//	{
//		return;
//	}
//	if (!isHalconWinOpen)
//	{
//		OpenHalconWin();
//	}
//	if (draw_done) {
//		draw_done = false;
//		m_HalconWin.drawOuterRectangle1();
//		draw_done = true;
//	}
//	else {
//		MessageBox(_T("请先完成上次绘制"), _T("提示"), MB_OK);
//	}
//}


void CheckParamDlg::OnBnClickedButOuterCycle()
{
	if (!isImage)
	{
		return;
	}
	if (!isHalconWinOpen)
	{
		OpenHalconWin();
	}
	if (draw_done) {
		draw_done = false;
		m_HalconWin.drawOuterCircle(Mask_flag);
		draw_done = true;
	}
	else {
		MessageBox(_T("请先完成上次绘制"), _T("提示"), MB_OK);
	}
}


//void CheckParamDlg::OnBnClickedButOuterPolygon()
//{
//	if (!isImage)
//	{
//		return;
//	}
//	if (!isHalconWinOpen)
//	{
//		OpenHalconWin();
//	}
//	if (draw_done) {
//		draw_done = false;
//		m_HalconWin.drawOuterPolygon();
//		draw_done = true;
//	}
//	else {
//		MessageBox(_T("请先完成上次绘制"), _T("提示"), MB_OK);
//	}
//}


//void CheckParamDlg::OnBnClickedButInnerRectangle()
//{
//	if (!isImage)
//	{
//		return;
//	}
//	if (!isHalconWinOpen)
//	{
//		OpenHalconWin();
//	}
//	if (draw_done) {
//		draw_done = false;
//		m_HalconWin.drawInnerRectangle1();
//		draw_done = true;
//	}
//	else {
//		MessageBox(_T("请先完成上次绘制"), _T("提示"), MB_OK);
//	}
//}


void CheckParamDlg::OnBnClickedButInnerCycle()
{
	if (!isImage)
	{
		return;
	}
	if (!isHalconWinOpen)
	{
		OpenHalconWin();
	}
	if (draw_done) {
		draw_done = false;
		m_HalconWin.drawInnerCircle(Mask_flag);
		draw_done = true;
	}
	else {
		MessageBox(_T("请先完成上次绘制"), _T("提示"), MB_OK);
	}
}


//void CheckParamDlg::OnBnClickedButInnerPolygon()
//{
//	if (!isImage)
//	{
//		return;
//	}
//	if (!isHalconWinOpen)
//	{
//		OpenHalconWin();
//	}
//	if (draw_done) {
//		draw_done = false;
//		m_HalconWin.drawInnerPolygon();
//		draw_done = true;
//	}
//	else {
//		MessageBox(_T("请先完成上次绘制"), _T("提示"), MB_OK);
//	}
//}


void CheckParamDlg::OnBnClickedButDeleteRegion()
{
	if (!isImage)
	{
		return;
	}
	if (!isHalconWinOpen)
	{
		OpenHalconWin();
	}
	if (draw_done) {
		draw_done = false;
		m_HalconWin.deleteLastRegion(Mask_flag);
		draw_done = true;
	}
	else {
		MessageBox(_T("请先完成上次绘制，再删除"), _T("提示"), MB_OK);
	}
}


void CheckParamDlg::OnBnClickedButSaveRegion()
{
	if (!isImage)
	{
		return;
	}
	if (!isHalconWinOpen)
	{
		return;
	}
	if (draw_done) {
		m_HalconWin.saveROI();
		//m_algorithm.ho_MaskImage
		ReadImage(&m_algorithm.ho_MaskImage[0], ".\\mask0.bmp");
		ReadImage(&m_algorithm.ho_MaskImage[1], ".\\mask1.bmp");
		ReadImage(&m_algorithm.ho_MaskImage[2], ".\\mask2.bmp");
		ReadImage(&m_algorithm.ho_MaskImage[3], ".\\mask3.bmp");
		//m_HalconWin.closeWindow();
		//isHalconWinOpen = false;
		HObject ho_EmptyRegion;
		GenEmptyRegion(&ho_EmptyRegion);
		if (0 != (m_algorithm.ho_MaskImage[0] == ho_EmptyRegion)
			&& 0 != (m_algorithm.ho_MaskImage[1] == ho_EmptyRegion)
			&& 0 != (m_algorithm.ho_MaskImage[2] == ho_EmptyRegion)
			&& 0 != (m_algorithm.ho_MaskImage[3] == ho_EmptyRegion))
		{
			NotEmpty = false;
			MessageBox(_T("未找到检测区域"), _T("提示"), MB_OK);
		}
		else {
			NotEmpty = true;
			m_HalconWin.displayFinetunnedRegion();
		}
		//m_HalconWin.displayFinetunnedRegion();
	}
	else {
		MessageBox(_T("绘制未完成，请单击鼠标右键完成区域绘制"), _T("提示"), MB_OK);
	}
	
}


//void CheckParamDlg::OnBnClickedBtnLast()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	number -= 1;
//	if (number >= 0) {
//		Image = Images[number];
//		ShowAndTrans(Image);
//		CString str;
//		str.Format(TEXT("第%d张图片"), number+1);
//		SetDlgItemText(IDC_STATIC_NUMBER, str);
//
//		if (number == 0) {
//			GetDlgItem(IDC_BUT_LAST)->EnableWindow(FALSE);
//		}
//	}
//	if (!GetDlgItem(IDC_BUT_NEXT)->IsWindowEnabled()) {
//		GetDlgItem(IDC_BUT_NEXT)->EnableWindow(TRUE);
//	}
//}

//void CheckParamDlg::OnBnClickedBtnNext()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	number += 1;
//	if (number <= Images.size() - 1) {
//		Image = Images[number];
//		ShowAndTrans(Image);
//		CString str;
//		str.Format(TEXT("第%d张图片"), number + 1);
//		SetDlgItemText(IDC_STATIC_NUMBER, str);
//
//		if (number == Images.size() - 1) {
//			GetDlgItem(IDC_BUT_NEXT)->EnableWindow(FALSE);
//		}
//	}
//	if (!GetDlgItem(IDC_BUT_LAST)->IsWindowEnabled()) {
//		GetDlgItem(IDC_BUT_LAST)->EnableWindow(TRUE);
//	}
//}


void CheckParamDlg::OnBnClickedButAitool()
{
	// TODO: 在此添加控件通知处理程序代码
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// 指定要运行的可执行文件路径
	//LPCTSTR szExePath = _T("F:/main/main.exe");
	//LPCTSTR szExePath = _T("G:/20230321/main/main.exe");
	LPCTSTR szExePath = _T("main/main.exe");

	// 创建进程
	if (!CreateProcess(szExePath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		// 如果创建进程失败，则显示错误消息
		MessageBox(_T("Failed to create process!"));
	}
	else
	{
		// 如果创建进程成功，则关闭不必要的句柄
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

}
void CheckParamDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//if (nID == SC_MOVE || nID == 0xF012) {
	//	return;
	//}
	//else {
		CDialogEx::OnSysCommand(nID, lParam);
	//}
}
void CheckParamDlg::OnCbnSelchangeComboImageNum()
{
	// TODO: 在此添加控件通知处理程序代码
	number = Image_num_box.GetCurSel();
	int a = number;
	if (number < 5 && !Images.empty()) {
		Image = Images[number];
		ShowAndTrans(Images[number]);
	}
}


void CheckParamDlg::OnBnClickedButGrabTest()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedButSaveRegion();
	vector<Mat>().swap(GetDetImages);
	vector<Mat>().swap(Images);
	if (m_Det != nullptr && m_Det->RunState) {
		AfxMessageBox(TEXT("软件正在运行，无法抓图！"));
	}
	else {
		if (m_Cam.IsOpen())
		{
			m_Cam.CloseCamera();
			Sleep(100);
			m_Cam.OpenCamera();
			m_Cam.UpdateCamera();
			m_Cam.SetTriggerModel(FALSE);
		}
		else
		{
			m_Cam.CloseCamera();
			Sleep(20);
			m_Cam.OpenCamera();
			m_Cam.UpdateCamera();
			m_Cam.SetTriggerModel(FALSE);
		}
		GetDetImages = m_Cam.GetImage(1);
		if (!isChecking && !m_Cam.isMissCamera() && m_Cam.isSuccessGraph() && !GetDetImages.empty()) {
			ShowAndTrans(GetDetImages[0]);
			if (!isHalconWinOpen)
			{
				OpenHalconWin();
			}
			//GetDlgItem(IDC_COMBO_IMAGE_NUM)->EnableWindow(TRUE);

			Images = GetDetImages;
			m_Cam.CloseCamera();
			if (isHalconWinOpen)
			{
				m_HalconWin.closeWindow();
				isHalconWinOpen = false;
			}
			//BeginDlg dlg;
			//HANDLE h_Thread_init = CreateThread(NULL, 0, LoadingCheck, this, 0, NULL);
			//dlg.DoModal();
			//CloseHandle(h_Thread_init);
			m_algorithm.UpdateAlgorithm(contra_val_vec, area_val_vec, gray_val_vec);

			SetEvent(CHECK_EVENT);
		}

	}

}


void CheckParamDlg::OnBnClickedRadioMask1()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveLast(Mask_flag);
	Mask_flag = 0;
	CString value;
	value.Format(TEXT("%.d"), contra_val_vec[0]);
	SetDlgItemText(IDC_EDIT_DUIBI_VALUE, value);
	value.Format(TEXT("%.d"), area_val_vec[0]);
	SetDlgItemText(IDC_EDIT_DET_THRE, value);
	value.Format(TEXT("%.d"), gray_val_vec[0]);
	SetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//if (!isHalconWinOpen && isImage)
	//{
	//	OpenHalconWin();
	//}

}


void CheckParamDlg::OnBnClickedRadioMask2()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveLast(Mask_flag);
	Mask_flag = 1;
	CString value;
	value.Format(TEXT("%.d"), contra_val_vec[1]);
	SetDlgItemText(IDC_EDIT_DUIBI_VALUE, value);
	value.Format(TEXT("%.d"), area_val_vec[1]);
	SetDlgItemText(IDC_EDIT_DET_THRE, value);
	value.Format(TEXT("%.d"), gray_val_vec[1]);
	SetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//if (!isHalconWinOpen && isImage)
	//{
	//	OpenHalconWin();
	//}

}


void CheckParamDlg::OnBnClickedRadioMask3()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveLast(Mask_flag);
	Mask_flag = 2;
	CString value;
	value.Format(TEXT("%.d"), contra_val_vec[2]);
	SetDlgItemText(IDC_EDIT_DUIBI_VALUE, value);
	value.Format(TEXT("%.d"), area_val_vec[2]);
	SetDlgItemText(IDC_EDIT_DET_THRE, value);
	value.Format(TEXT("%.d"), gray_val_vec[2]);
	SetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//if (!isHalconWinOpen && isImage)
	//{
	//	OpenHalconWin();
	//}

}


void CheckParamDlg::OnBnClickedRadioMask4()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveLast(Mask_flag);
	Mask_flag = 3;
	CString value;
	value.Format(TEXT("%.d"), contra_val_vec[3]);
	SetDlgItemText(IDC_EDIT_DUIBI_VALUE, value);
	value.Format(TEXT("%.d"), area_val_vec[3]);
	SetDlgItemText(IDC_EDIT_DET_THRE, value);
	value.Format(TEXT("%.d"), gray_val_vec[3]);
	SetDlgItemText(IDC_EDIT_GRAY_VALUE, value);
	//if (!isHalconWinOpen && isImage)
	//{
	//	OpenHalconWin();
	//}

}


void CheckParamDlg::OnBnClickedRadioPic1()
{
	// TODO: 在此添加控件通知处理程序代码
	number = 0;
	if (number < 5 && !Images.empty()) {
		Image = Images[number];
		ShowAndTrans(Images[number]);
	}

}


void CheckParamDlg::OnBnClickedRadioPic2()
{
	// TODO: 在此添加控件通知处理程序代码
	number = 1;
	if (number < 5 && !Images.empty()) {
		Image = Images[number];
		ShowAndTrans(Images[number]);
	}

}


void CheckParamDlg::OnBnClickedRadioPic3()
{
	// TODO: 在此添加控件通知处理程序代码
	number = 2;
	if (number < 5 && !Images.empty()) {
		Image = Images[number];
		ShowAndTrans(Images[number]);
	}

}


void CheckParamDlg::OnBnClickedRadioPic4()
{
	// TODO: 在此添加控件通知处理程序代码
	number = 3;
	if (number < 5 && !Images.empty()) {
		Image = Images[number];
		ShowAndTrans(Images[number]);
	}

}


void CheckParamDlg::OnBnClickedRadioPic5()
{
	// TODO: 在此添加控件通知处理程序代码
	number = 4;
	if (number < 5 && !Images.empty()) {
		Image = Images[number];
		ShowAndTrans(Images[number]);
	}

}


void CheckParamDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
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


void CheckParamDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//m_detec
}

//剔除测试
void CheckParamDlg::OnBnClickedButtonCullingtest()
{
	CString TriggerDistance;
	CString PhotoelectricDistance;
	GetDlgItemText(IDC_EDIT_TriggerDistance, TriggerDistance);
	GetDlgItemText(IDC_EDIT_PhotoelectricDistance, PhotoelectricDistance);
	m_pData->SetCullParameters(TriggerDistance, PhotoelectricDistance);
	m_pData->LoadBottleDetParam();
	//PLC通讯
	PickBottle = 1;
	FatherSingle father;
	std::vector<int> results = {
		stoi(m_pData->GetBottleDetParam()->TriggerDistance),
		stoi(m_pData->GetBottleDetParam()->PhotoelectricDistance)
		};
	int PLC_result[2];
	for (int i = 0; i < 2; i++) {
		PLC_result[i] = results[i];
	}
	father.ComWithoChild(PLC_result, PickBottle);
	

}
