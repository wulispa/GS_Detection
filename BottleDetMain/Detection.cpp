#include "pch.h"
#include "Detection.h"
#include "BottleDetMainDlg.h"
#include "myLogger.h"

//using namespace cv;


VOID CallBackDetection(WPARAM wparam, LPARAM lparam);


char* MyW2A(const CString& str) {
	int n = str.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, str, n, NULL, 0, NULL, NULL);
	char* strchar = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str, n + 1, strchar, len + 1, NULL, NULL);
	strchar[len] = '\0';
	return strchar;
}

//异常检测线程
DWORD WINAPI ErrorChecktThread(LPVOID pthread)
{
	return 0;
}
//模号识别
//DWORD WINAPI IdentifyThread(LPVOID pthread)
//{
//	//Detection* m_det = (Detection*)pthread;
//	//while (true)
//	//{
//	//	if (m_det->RunState)
//	//	{
//	//		m_det->IdentifyByAlgorithm();
//	//	}
//	//	else
//	//	{
//	//		Sleep(100);
//	//	}
//	//}
//	return 0;
//}

// 检测主线程
DWORD WINAPI DetectionThread(LPVOID pthread)
{
	Detection* m_det = (Detection*)pthread;
	while (true)
	{
		if (m_det->RunState)
		{
			m_det->CheckByAlgorithm();
		}
		else
		{
			Sleep(100);
		}
	}
	return 0;
}
//模号线程
//DWORD WINAPI DetectionThread1(LPVOID pthread)
//{
//	Detection* m_det = (Detection*)pthread;
//	while (true)
//	{
//		if (m_det->RunState)
//		{
//			m_det->CheckByAlgorithmMode();
//		}
//		else
//		{
//			Sleep(100);
//		}
//	}
//	return 0;
//}

VOID CallBackDetection(WPARAM wparam, LPARAM lparam)
{
	/*DvDetection* m_detection = (DvDetection*)wparam;
	int STEPNOW = (int)lparam;
	m_detection->CheckByAlgorithm(STEPNOW);*/
}

Detection::Detection(DataManager* pdata, CWnd* pwin) :
	m_Camera(CameraBasler(pdata)),
	m_Algorithm(AlgorithmBase(pdata)),
	//m_AlgorithmIdentify(AlgorithmIdentify(pdata)),
	RunState(false),
	m_pWin(pwin),
	m_pData(pdata),
	DetectTime(0),
	IdentifyResult(0)
{
	InitThread();
	CHECK_EVENT = CreateEventW(NULL, TRUE, TRUE, NULL);
	//CHECK_EVENT1 = CreateEventW(NULL, TRUE, TRUE, NULL);

	GRAPH_EVENT = CreateEventW(NULL, TRUE, TRUE, NULL);
	//GRAPH_EVENT1 = CreateEventW(NULL, TRUE, TRUE, NULL);

	IDENTIFY_EVENT = CreateEventW(NULL, TRUE, TRUE, NULL);
	//if (m_pData->GetBottleDetParam()->Trigger == "ON")
	//{
	//	isTrigger = true;
	//}
	//else
	//{
	//	isTrigger = false;
	//}
}

Detection::Detection(DataManager* pdata, BottleDetParam* m_param, CWnd* pwin)
{

}

Detection::~Detection()
{
	CloseThreadHandle();
	m_Camera.~CameraBasler();
	//m_Algorithm.~AlgorithmBase();
	//m_AlgorithmIdentify.~AlgorithmIdentify();
}
void Detection::StartRun(string model)
{
	if (model == "FIRSTSTART")
	{
		if (FirstStartCheck()) {
			RunState = true;
		}
	}
	else if (model == "RESTART")
	{
		if (RestartCheck()) {
			RunState = true;
		}
	}
	else if (model == "CONTINUE")
	{
		if (ContinueCheck()) {
			RunState = true;
		}
	}
}

void Detection::StopRun()
{
	SignalTotal = 0;
	RunState = false;
	DWORD res=WaitForSingleObject(GRAPH_EVENT, 500);///等待2秒钟//1000//500
	if (res == WAIT_TIMEOUT) {
		m_Camera.StopGraphImage();
	}
	//DWORD res1 = WaitForSingleObject(GRAPH_EVENT1, 500);///等待2秒钟//1000//500
	//if (res1 == WAIT_TIMEOUT) {
	//	m_Camera1.StopGraphImage();
	//}

	WaitForSingleObject(CHECK_EVENT, 500);//等待检测完成后停止//INFINITE->1000//500
	//WaitForSingleObject(CHECK_EVENT1, 500);

	//m_Camera.~CameraHK();
	if (m_Camera.IsOpen()) {
		m_Camera.CloseCamera();
	}
}

bool Detection::FirstStartCheck()
{
	if (m_pData->GetBottleDetParam()->Trigger == "ON")
	{
		isTrigger = true;
	}
	else
	{
		isTrigger = false;
	}

	try {
		//m_Algorithm.UpdateAlgorithm();//刷新检测参数模型参数
		if (m_Camera.IsOpen()) {
			m_Camera.CloseCamera();
			//FirstStartCheck();
			m_Camera.OpenCamera();
			m_Camera.UpdateCamera();
			m_Camera.SetTriggerModel(isTrigger);

			return true;
		}
		else {
			
			m_Camera.OpenCamera();
			m_Camera.UpdateCamera();
			m_Camera.SetTriggerModel(isTrigger);

		}
		if (!m_Camera.IsOpen())
		{
			return false;
		}
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Detection::RestartCheck()
{
	try {
		if (m_Camera.IsOpen()) {
			m_Camera.CloseCamera();
			m_Camera.OpenCamera();
			m_Camera.UpdateCamera();
			return true;
		}
		else {
			//m_Camera.UpdateCamera();
			m_Camera.OpenCamera();
		}
		if (!m_Camera.IsOpen())
		{
			return false;
		}
		m_Algorithm.UpdateAlgorithm();//刷新模型参数
		//m_AlgorithmIdentify.UpdateAlgorithm();
		return true;
	}
	catch (...) {
		return false;
	}
}

bool Detection::ContinueCheck()
{
	return true;
}

BOOL Detection::InitThread()
{
	hThreadDetection = CreateThread(NULL, 0, DetectionThread, this, 0, NULL);
	//hThreadDetection1 = CreateThread(NULL, 0, DetectionThread1, this, 0, NULL);

	hThreadErrorCheck = CreateThread(NULL, 0, ErrorChecktThread, this, 0, NULL);

	//hThreadIdentify= CreateThread(NULL, 0, IdentifyThread, this, 0, NULL);
	return 0;
}

void Detection::CloseThreadHandle()
{
	if (hThreadDetection) {
		CloseHandle(hThreadDetection);
	}
	//if (hThreadDetection1) {
	//	CloseHandle(hThreadDetection1);
	//}

	if (hThreadErrorCheck) {
		CloseHandle(hThreadErrorCheck);
	}
	if (hThreadIdentify)
	{
		CloseHandle(hThreadIdentify);
	}
}
// 使用
int Detection::CheckByAlgorithm()
{

	ResetEvent(CHECK_EVENT);
	ResetEvent(GRAPH_EVENT);
	ResetEvent(IDENTIFY_EVENT);
	int num_image = m_pData->GetBottleDetParam()->GrabNum;
	string Throw_model = m_pData->GetSystemParam()->ThrowModel;
	string CamOut = m_pData->GetBottleDetParam()->CamOut;	//模号由相机输出true/false
	int result = 1;
	int Identify_result = 1;
	vector<Mat>().swap(ProductImages);
	string Signal="OK";
	
	if (num_image == 1)
	{
		ProductImage = m_Camera.GetImage(1);
		if (!ProductImage.empty())
		{
			SignalTotal += 1;
		}
		SetEvent(GRAPH_EVENT);
		if (!m_Camera.isMissCamera() && m_Camera.isSuccessGraph()) {
			if (SignalTotal > 1) {
				m_Algorithm.DoJob(ProductImage);
				DetectionDeadline = m_Algorithm.Deadline;
				DetectionUpCode = m_Algorithm.UpCode;
				DetectionDownCode = m_Algorithm.DownCode;
				DetectionUpNumber = m_Algorithm.UpNumber;
				DetectionDownNumber = m_Algorithm.DownNumber;
				DetectionUpResult = m_Algorithm.UpResult;
				DetectionDownResult = m_Algorithm.DownResult;

				
				//SQL.Add_Info(DateInfo(DetectionDeadline, DetectionUpCode, DetectionDownCode, DetectionUpNumber, DetectionDownNumber, DetectionUpResult, DetectionDownResult,"0","0","0"));//插入数据库

				if (DetectionUpResult == "上层条码比对成功！" && DetectionDownResult == "下层条码比对成功！")
				{
					Signal = "OK";
				}
				else 
				{
					Signal = "NG";
				}
			}
			
			if (Signal == "NG")
			{
				m_Camera.OutPutResult();
			}



			result = m_Algorithm.GetCheckResult();
			//Identify_result = m_Algorithm.GetIDResult();
			//if (CamOut == "TRUE") {
			//	if (Throw_model == "NORMAL")
			//	{
			//		if (result == -1 || Identify_result == 1)
			//		{
			//			m_Camera.OutPutResult();
			//		}
			//	}
			//	else if (Throw_model == "SUSTAIN")
			//	{
			//		m_Camera.OutPutResult();
			//	}
			//	else
			//	{
			//		///Do Nothing
			//	}
			//}
			//else {
			//	if (Throw_model == "NORMAL")
			//	{
			//		if (result == -1)
			//		{
			//			m_Camera.OutPutResult();
			//		}
			//	}
			//	else if (Throw_model == "SUSTAIN")
			//	{
			//		m_Camera.OutPutResult();
			//	}
			//	else
			//	{
			//		///Do Nothing
			//	}
			//	if (m_Algorithm.bottle_type != "0") {
			//		int idd = str2intd(m_Algorithm.bottle_type);
			//		if (idd < 0) {
			//			idd = 0;
			//		}
			//		father.ComWithoChild(idd);
			//	}
			//	else {
			//		father.ComWithoChild(0);
			//	}
			//}
			UpdateProductImageShow(ProductImage, m_Algorithm.GetDetRects(), result,DetectionDeadline, DetectionUpCode, DetectionDownCode, DetectionUpNumber, DetectionDownNumber, DetectionUpResult, DetectionDownResult);
		}
		else
		{
			AfxMessageBox(L"拍照失败1");
		}
	}
	//else
	//{
	//	ProductImages = m_Camera.GetImage(1);
	//	vector<Mat> PRImages;
	//	SetEvent(GRAPH_EVENT);
	//	if (!m_Camera.isMissCamera() && m_Camera.isSuccessGraph() 
	//		&& !ProductImages.empty() && ProductImages.size() == 5)
	//	{
	//		PImages.assign(ProductImages.begin(), ProductImages.end());
	//		if (ProductImages[0].channels() != 3) {
	//			for (int i = 0; i < ProductImages.size(); i++) {
	//				cv::cvtColor(ProductImages[i], ProductImages[i], cv::COLOR_GRAY2BGR);
	//				//ProductImages[i] = ProductImages[i](Rect(150, 280, 896, 716));
	//				PRImages.push_back(ProductImages[i](Rect(150, 280, 896, 716)));
	//			}
	//		}
	//		int number = m_Algorithm.DoJob(ProductImages, num_image);
	//		result = m_Algorithm.GetCheckResult();
	//		Identify_result = m_Algorithm.GetIDResult();
	//		if (CamOut == "TRUE") {
	//			if (Throw_model == "NORMAL")
	//			{
	//				if (result == -1 || Identify_result == 1)
	//				{
	//					m_Camera.OutPutResult();
	//				}
	//			}
	//			else if (Throw_model == "SUSTAIN")
	//			{
	//				m_Camera.OutPutResult();
	//			}
	//			else
	//			{
	//				///Do Nothing
	//			}
	//		}
	//		else {
	//			if (Throw_model == "NORMAL")
	//			{
	//				if (result == -1)
	//				{
	//					m_Camera.OutPutResult();
	//				}
	//			}
	//			else if (Throw_model == "SUSTAIN")
	//			{
	//				m_Camera.OutPutResult();
	//			}
	//			else
	//			{
	//				///Do Nothing
	//			}
	//			if (m_Algorithm.bottle_type != "0") {
	//				int idd = str2intd(m_Algorithm.bottle_type);
	//				if (idd < 0) {
	//					idd = 0;
	//				}
	//				father.ComWithoChild(idd);
	//			}
	//			else {
	//				father.ComWithoChild(0);
	//			}
	//		}
	//		ProductImage = ProductImages[number];
	//		UpdateProductImageShow(ProductImage, m_Algorithm.GetDetRects(), result,
	//			m_Algorithm.GetDetCostTime(), 
	//			m_Algorithm.bottle_type, Identify_result, m_Algorithm.res_name);
	//	}
	//	else{}
	//}
	SetEvent(CHECK_EVENT);
		return 0;
}

//int Detection::CheckByAlgorithmMode()
//{
//	ResetEvent(CHECK_EVENT1);
//	ResetEvent(GRAPH_EVENT1);
//	string Throw_model = m_pData->GetSystemParam()->ThrowModel;
//	string CamOut = m_pData->GetBottleDetParam()->CamOut;	//模号由相机输出true/false
//	int Identify_result = 1;
//	vector<Mat>().swap(ProductImages);
//	ProductImage = m_Camera1.GetImage();
//	SetEvent(GRAPH_EVENT1);
//	if (!m_Camera.isMissCamera() && m_Camera.isSuccessGraph())
//	{
//		PImages.assign(ProductImages.begin(), ProductImages.end());
//		if (ProductImages[0].channels() != 3) {
//			for (int i = 0; i < ProductImages.size(); i++) {
//				cv::cvtColor(ProductImages[i], ProductImages[i], cv::COLOR_GRAY2BGR);
//				//ProductImages[i] = ProductImages[i](Rect(150, 280, 896, 716));
//			}
//
//		}
//		//int number = m_Algorithm.DoJob(ProductImages, 1);
//		m_Algorithm.CheckByModeAlgorithm(ProductImage);
//		//bottle_type = "0";
//		Identify_result = m_Algorithm.GetIDResult();
//		if (CamOut == "TRUE") {
//			if (Throw_model == "NORMAL")
//			{
//				if (Identify_result == 1)
//				{
//					m_Camera1.OutPutResult();
//				}
//			}
//			else if (Throw_model == "SUSTAIN")
//			{
//				m_Camera1.OutPutResult();
//			}
//			else
//			{
//				///Do Nothing
//			}
//
//		}
//		else {
//			if (Throw_model == "NORMAL")
//			{
//				if (Identify_result == -1)
//				{
//					m_Camera1.OutPutResult();
//
//				}
//			}
//			else if (Throw_model == "SUSTAIN")
//			{
//				m_Camera1.OutPutResult();
//			}
//			else
//			{
//				///Do Nothing
//			}
//			if (m_Algorithm.bottle_type != "0") {
//				int idd = str2intd(m_Algorithm.bottle_type);
//				if (idd < 0) {
//					idd = 0;
//				}
//				father.ComWithoChild(idd);
//			}
//			else {
//				father.ComWithoChild(0);
//			}
//		}
//		UpdateProductImageShow(ProductImage, m_Algorithm.bottle_type, Identify_result);
//	}
//	else
//	{
//		//ResetEvent(GRAPH_EVENT);
//		//SetEvent(GRAPH_EVENT);
//		//AfxMessageBox(L"拍照失败1");
//	}
//	SetEvent(CHECK_EVENT1);
//
//	return 0;
//}

int Detection::IdentifyByAlgorithm()
{
	//ResetEvent(IDENTIFY_EVENT);
	//int num_image = m_pData->GetBottleDetParam()->GrabNum;
	////WaitForSingleObject(GRAPH_EVENT, INFINITE);//等待拍照完成
	//if (!m_Camera.isMissCamera() && m_Camera.isSuccessGraph()) 
	//{			
	//	//m_AlgorithmIdentify.UpdateAlgorithm();
	//	if (num_image == 1) {
	//		m_AlgorithmIdentify.DoJob(ProductImage);
	//	}
	//	else {
	//		//ProductImages = m_Camera.GetImages();
	//		//m_AlgorithmIdentify.DoJob(ProductImages, num_image);
	//	}
	//	//IdentifyResult = m_AlgorithmIdentify.GetCheckResult();//模号匹配为1，否为-1
	//	
	//}
	//SetEvent(IDENTIFY_EVENT);

	return 0;
}

VOID Detection::UpdateProductImageShow(Mat Image,int result)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	//m_win->UpDateDetectTime(DetectTime);///更新检测耗时———更改日期：2022/12/3-QJJ
	m_win->UpdateProduct(Image, result);
	return VOID();
}

VOID Detection::UpdateProductImageShow(vector<Mat> Images, int result)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	//m_win->UpDateDetectTime(DetectTime);///更新检测耗时———更改日期：2022/12/3-QJJ
	m_win->UpdateProduct(Images, result);
	return VOID();
}

VOID Detection::UpdateProductImageShow(Mat Image, vector<cv::Rect> points, int result, string deadline,string UpCode, string DownCode, string UpNumber, string DownNumber, string UpResult, string DownResult)
{
	//SystemParamDlg* m_win = (SystemParamDlg*)m_pWin;
	 CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	//m_win->UpDateDetectTime(DetectTime);///更新检测耗时———更改日期：2024/7/31-罗盟波
	
	m_win->UpdateProduct(Image, points, result,deadline,UpCode,DownCode,UpNumber,DownNumber,UpResult,DownResult);
	return VOID();
}

VOID Detection::UpdateProductImageShow(vector<Mat> Images, vector<cv::Rect> points, int result)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	//m_win->UpDateDetectTime(DetectTime);///更新检测耗时———更改日期：2022/12/3-QJJ
	m_win->UpdateProduct(Images, points, result);
	return VOID();
}

VOID Detection::UpdateProductImageShow(vector<Mat> Images, vector<cv::Rect> points, int result, int DeTime)
{
	return VOID();
}

VOID Detection::UpdateProductImageShow(Mat Image, vector<cv::Rect> points, int result, int DeTime)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	m_win->UpdateProduct(Image, points, result,DeTime);
	return VOID();

}

VOID Detection::UpdateProductImageShow(Mat Image, vector<cv::Rect> points, int result, int DeTime, string detect_ID)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	m_win->UpdateProduct(Image, points, result, DeTime, detect_ID);
	return VOID();
}

VOID Detection::UpdateProductImageShow(Mat Image, string detect_ID, int detect_Result)
{
	return VOID();
}

VOID Detection::UpdateProductImageShow(Mat Image, vector<cv::Rect> points, int result, int DeTime, string detect_ID, int detect_Result)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	m_win->UpdateProduct(Image, points, result, DeTime, detect_ID, detect_Result);
	return VOID();
}

VOID Detection::UpdateProductImageShow(Mat Image, vector<cv::Rect> points, int result, int DeTime, string detect_ID, int detect_Result, string res_name)
{
	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
	m_win->UpdateProduct(Image, points, result, DeTime, detect_ID, detect_Result, res_name);
	return VOID();
}

//VOID Detection::UpdateProductImageShow(Mat Image, vector<cv::Rect> points, int result, int DeTime, string res_name)
//{
//	CBottleDetMainDlg* m_win = (CBottleDetMainDlg*)m_pWin;
//	m_win->UpdateProduct(Image, points, result, DeTime, res_name);
//	return VOID();
//}

VOID Detection::UpdateProductResult(int result)
{
	return VOID();
}

CameraBasler* Detection::GetCamera_ptr()
{
	return &m_Camera;
	
}

CameraHK1* Detection::GetCamera1_ptr()
{
	return &m_Camera1;
}

AlgorithmBase* Detection::GetAlgorithm_ptr()
{
	return &m_Algorithm;
}

//AlgorithmIdentify* Detection::GetIdentifyAlgorithm_ptr()
//{
//	return &m_AlgorithmIdentify;
//}

int Detection::str2intd(string str)
{
	stringstream stream;     //声明一个stringstream变量
	int n;
	//string转int
	stream << str;     //向stream中插入字符串
	stream >> n;
	return n;
}

CString Detection::SaveImaged(vector<Mat>& images)
{
	CString name;
		SYSTEMTIME st;
		CString TestFolder;
		GetLocalTime(&st);
		for (int i = 0; i < images.size(); i++) {
			TestFolder.Format(TEXT("Test%2d-%2d"), st.wMonth, st.wDay);
			if ((GetFileAttributesA((LPCSTR)TestFolder.GetString())) != FILE_ATTRIBUTE_DIRECTORY) {
				bool flag = CreateDirectory(TestFolder.GetString(), NULL);
				// flag 为 true 说明创建成功
			}
			//name.Format(TEXT("/%2d-%2d-%2d.jpg"), st.wHour, st.wMinute, st.wMilliseconds);
			name.Format(TEXT("/%02d-%02d-%02d-%d.jpg"), st.wHour, st.wMinute, st.wMilliseconds, i);
			name = TestFolder + name;
			USES_CONVERSION;
			imwrite(W2A(name), images[i]);

		}
	return name;
}
