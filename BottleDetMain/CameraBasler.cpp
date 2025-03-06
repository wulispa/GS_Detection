#include "pch.h"
#include "CameraBasler.h"
#include "myLogger.h"
//#include "ParametrizeCamera_GenericParameterAccess.cpp"
#define CRT_SECURE_NO_WARNINGS
using namespace std;
char* MyW2AB(const CString& str) {
	int n = str.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, str, n, NULL, 0, NULL, NULL);
	char* strchar = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, str, n + 1, strchar, len + 1, NULL, NULL);
	strchar[len] = '\0';
	return strchar;
}

CameraBasler::CameraBasler()
{
	// The exit code of the sample application.
    	int exitCode = 0;
    	// Before using any pylon methods, the pylon runtime must be initialized. 
    	//PylonInitialize();
	pData = NULL;
	isOpen = false;
	missCamera = false;
	GraphSuccess = false;
	ExposureTimeNum = 5000;//初始曝光时间与增益
	GainNum = 2;
}

CameraBasler::CameraBasler(DataManager* pdata) :
	m_pData(pdata),
	GraphSuccess(false)
{
	int exitCode = 0;
    	//PylonInitialize();
	isOpen = false;
	ExposureTimeNum = 5000;//初始曝光时间与增益
	GainNum = 2;
}

CameraBasler::CameraBasler(const CameraBasler& obj)
{
	this->m_pData = obj.m_pData;
	int exitCode = 0;
    	//PylonInitialize();
	ExposureTimeNum = 5000;//初始曝光时间与增益
	GainNum = 2;
	isOpen = false;
}

CameraBasler& CameraBasler::operator=(const CameraBasler& obj)
{
	// TODO: 在此处插入 return 语句
	if (this == &obj) {
		return *this;
	}
	this->m_pData = obj.m_pData;
	//this->camera = obj.camera;

	int exitCode = 0;
    	//PylonInitialize();
	ExposureTimeNum = 5000;//初始曝光时间与增益
	GainNum = 2;
	isOpen = false;
	return *this;
}

CameraBasler::~CameraBasler()
{
	if (isOpen) {
		CloseCamera();
	}
	//PylonTerminate(); 
}

bool CameraBasler::IsOpen()
{
	return isOpen;
}

void CameraBasler::SetCameraParam()//还未写
{
}

int CameraBasler::GraphImage(int choose)
{
	try {
		Mat img;
		HObject image;
		missCamera = false;
		ProductImages.clear();
		// The result data is automatically filled with received chunk data.
		//CGrabResultPtr ptrGrabResult;
		//camera.GetDeviceInfo();
		SYSTEMTIME st;
		CString strDate, strTime;
		GetLocalTime(&st);
		strTime.Format(TEXT("采前时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		const char* cstr;
		cstr = MyW2AB(strTime);
		LOG(0, cstr);

		//static const uint32_t c_countOfImagesToGrab = 1;
		//if (camera.IsOpen()) {
		//	camera.StartGrabbing(c_countOfImagesToGrab);
		//}
		GetLocalTime(&st);
		strTime.Format(TEXT("采11时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		cstr = MyW2AB(strTime);
		LOG(0, cstr);

		//camera.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);
		if(camera.IsGrabbing()){
			GetLocalTime(&st);
			strTime.Format(TEXT("采12时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
			cstr = MyW2AB(strTime);
			LOG(0, cstr);
			CGrabResultPtr ptrGrabResult;	//数据流
			camera.RetrieveResult(INFINITE, ptrGrabResult, TimeoutHandling_ThrowException);
			if (ptrGrabResult == NULL) {
				GraphSuccess = false;
				missCamera = true;
				return -1;
			}
			if(ptrGrabResult->GrabSucceeded())
			{
				GetLocalTime(&st);
				strTime.Format(TEXT("采22时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
				cstr = MyW2AB(strTime);
				LOG(0, cstr);

				int W = ptrGrabResult->GetWidth();
				int H = ptrGrabResult->GetHeight();
				const uint8_t* pImageBuffer = (uint8_t*)ptrGrabResult->GetBuffer();
				GenImage1(&image, "byte", W, H, (Hlong)pImageBuffer);
				sImage = image;
				img = HImage2Mat(image);
				SingleImage = img.clone();
				
				//switch (choose)
				//{
				//case 0:
					//cv::rotate(SingleImage, SingleImage, cv::ROTATE_90_CLOCKWISE);				// 顺时针90
				//	break;
				//case 1:
					cv::rotate(SingleImage, SingleImage, cv::ROTATE_90_COUNTERCLOCKWISE);		// 逆时针90
				//	break;
				//default:
				//	break;
				//}


				if (choose==1)
				{
					cv::rotate(SingleImage, SingleImage, cv::ROTATE_90_CLOCKWISE);				// 顺时针90
				}
				else if(choose==2)
				{
					cv::rotate(SingleImage, SingleImage, cv::ROTATE_90_COUNTERCLOCKWISE);		// 逆时针90
				}
				else
				{}
				GraphSuccess = true;
				GetLocalTime(&st);
				strTime.Format(TEXT("采完时间：%2d:%2d:%2d:%4d"), st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
				cstr = MyW2AB(strTime);
				LOG(0, cstr);

			}
			else {
				GraphSuccess = false;
			}
		}
		else {
			GraphSuccess = false;
		}
	}
	catch (const std::exception&) {
		GraphSuccess = false;
		missCamera = true;
		return -1;
	}
	return 1;
}

void CameraBasler::StopGraphImage()
{
	camera.StopGrabbing();
}

bool CameraBasler::OpenCamera()
{
	PylonInitialize();
	try {
		CTlFactory& tlFactory = CTlFactory::GetInstance();
        DeviceInfoList_t devices;
		int q = tlFactory.EnumerateDevices(devices);
        if ( tlFactory.EnumerateDevices(devices) == 0 )
        {
			AfxMessageBox(TEXT("未能识别到相机，请检查连接"));
			return	false;
        }
		else {
			int n = devices.size();
			for (size_t i = 0; i < devices.size(); ++i)
			{
				string a = devices[i].GetModelName();
				string aa = devices[i].GetSerialNumber();
				if (devices[i].GetSerialNumber() == "23886902") {
					//bool axc = camera.IsGigE();
					//bool axc1 = camera.Is1394();
					//bool axc2 = camera.IsBcon();
					//bool axc3 = camera.IsCameraLink();

					camera.Attach(tlFactory.CreateDevice(devices[i]));
					camera.Open();
					isOpen = camera.IsOpen();
					break;
				}
				//cout << "Using device " << cameras[ i ].GetDeviceInfo().GetModelName() << endl;
			}
			if (!isOpen) {
				AfxMessageBox(TEXT("相机未识别"));
			}
			else {
			}
		}
	}
	catch (...)
	{
		AfxMessageBox(TEXT("相机一占用"));
		return	false;
	}
	return true;
}

bool CameraBasler::OpenCamera(string CamID, int step)
{
	PylonInitialize();
	try {
		CTlFactory& tlFactory = CTlFactory::GetInstance();
		DeviceInfoList_t devices;
		int q = tlFactory.EnumerateDevices(devices);
		if (tlFactory.EnumerateDevices(devices) == 0)
		{
			AfxMessageBox(TEXT("未识别到相机，请检查连接"));
			return	false;
		}
		else {
			int n = devices.size();
			for (size_t i = 0; i < devices.size(); ++i)
			{
				string a = devices[i].GetModelName();
				string aa = devices[i].GetSerialNumber();
				if (devices[i].GetSerialNumber() == CamID) {
					//bool axc = camera.IsGigE();
					//bool axc1 = camera.Is1394();
					//bool axc2 = camera.IsBcon();
					//bool axc3 = camera.IsCameraLink();
					camera.Attach(tlFactory.CreateDevice(devices[i]));
					camera.Open();
					isOpen = camera.IsOpen();
					break;
				}
			}
			if (!isOpen) {
				CString str;
				str.Format(TEXT("未能识别到相机%2d，序列号："), step);
				str = str + CA2T(CamID.c_str()) + TEXT("，请检查连接");
				AfxMessageBox(str);
			}
			else {
				return true;
			}
		}
	}
	catch (...)
	{
		CString str;
		str.Format(TEXT("相机%2d被占用"), step);
		//str = str + CA2T(CamID.c_str()) + TEXT("被占用");
		AfxMessageBox(str);
		return	false;
	}
	return true;
}


bool CameraBasler::RestartCamera()
{
	if (isOpen) {
		CloseCamera();
		Sleep(100);
		OpenCamera();
	}
	else {
		Sleep(100);
		OpenCamera();
	}
	return true;
}

bool CameraBasler::CloseCamera()
{
	try
	{
		if (camera.IsOpen()) {
			camera.StopGrabbing();
			camera.DestroyDevice();
			PylonTerminate();
			isOpen = false;
		}
	}
	catch (const std::exception&)
	{
		Sleep(100);
		CloseCamera();
		return	false;
	}
	return	true;
}


//std::vector<int> CameraBasler::Read_XML()
//{
//	std::vector<int> Cam_GROUP;
//	std::ifstream inputFile("G:\\BottleProject\\BottleFigure\\BottleDetMain\\BottleDet.xml");
//	if (!inputFile.is_open()) {
//		std::cout << "Failed to open XML file." << std::endl;
//	}
//	// 逐行读取文件内容
//	std::string line;
//	while (std::getline(inputFile, line)) {
//		for (int int_i = 1; int_i < 5; int_i++)
//		{
//			string i = to_string(int_i);
//			// 在每一行中查找目标节点
//			size_t startPos = line.find("<GROUP" + i + ">");
//			size_t endPos = line.find("</GROUP" + i + ">");
//			if (startPos != std::string::npos && endPos != std::string::npos)
//			{
//				// 提取节点值
//				std::string value = line.substr(startPos + 8, endPos - startPos - 8);
//				Cam_GROUP.push_back(std::atoi(value.c_str()));
//			}
//		}
//	}
//	// 关闭文件
//	inputFile.close();
//	if (!Cam_GROUP.empty())
//	{
//		//cout << "读取成功" << endl;
//		return Cam_GROUP;
//	}
//	else
//	{
//		std::vector<int> empty;
//		return empty;
//	}
//}

Mat CameraBasler::GetImage(int Choose_Cam)
{
	//std::vector<int> RESULT= Read_XML();
	//int GROUP[4];
	//for (int i = 0; i < 4; i++) {
	//	GROUP[i] = RESULT[i];
	//}
	GraphImage(Choose_Cam);
	//int n1 = m_pData->GetBottleDetParam()->GROUP1;
	//int n2 = m_pData->GetBottleDetParam()->GROUP2;
	//int n3 = m_pData->GetBottleDetParam()->GROUP3;
	//int n4 = m_pData->GetBottleDetParam()->GROUP4;
	//if (Choose_Cam < 2) {
	//	GraphImage(n1);
	//}
	//else if (Choose_Cam < 4) {
	//	GraphImage(n2);
	//}
	//else if (Choose_Cam < 6) {
	//	GraphImage(n3);
	//}
	//else {
	//	GraphImage(n4);
	//}

	if (missCamera) {
		//发送相机离线消息
		return Mat();
	}
	return SingleImage;//单张图片
}

HObject CameraBasler::Get_Image(int n)
{
	//GraphImage();
	if (missCamera) {
		//发送相机离线消息
		return HObject();
	}
	return sImage;//单张图片
}

bool CameraBasler::isMissCamera()
{
	return missCamera;
}

bool CameraBasler::isSuccessGraph()
{
	return GraphSuccess;
}

bool CameraBasler::UpdateCamera()
{
	try {
		ExposureTimeNum = m_pData->GetBottleDetParam()->ExpostTime;
		GainNum = m_pData->GetBottleDetParam()->GainValue;
		double exposuretime = (double)ExposureTimeNum;
		camera.ExposureTime.SetValue(exposuretime);
		double gainraw = (double)GainNum;
		camera.GainSelector.SetValue(GainSelector_All);
		camera.Gain.SetValue(gainraw);
		//CEnumerationPtr pixelFormat(camera.GetNodeMap().GetNode("PixelFormat"));
		//String_t oldPixelFormat = pixelFormat->ToString();
		//if (IsAvailable(pixelFormat->GetEntryByName("Mono8")))
		//{
		//	pixelFormat->FromString("Mono8");
		//}
		//CIntegerPtr ExposureTime(camera.GetNodeMap().GetNode("ExposureTimeRaw"));
		//double ExposureTimeRaw = (double)ExposureTimeNum;
		//ExposureTimeNum = Adjust(ExposureTimeNum, ExposureTime->GetMin(), ExposureTime->GetMax(), ExposureTime->GetInc());
		//ExposureTime->SetValue(ExposureTimeNum);
		//CEnumerationPtr gainAuto(camera.GetNodeMap().GetNode("GainAuto"));
		//if (IsWritable(gainAuto))
		//{
		//	gainAuto->FromString("Off");
		//}
		//if (camera.GetSfncVersion() >= Sfnc_2_0_0)
		//{
		//	CFloatPtr gain(camera.GetNodeMap().GetNode("Gain"));
		//	double newGain = (double)GainNum;
		//	gain->SetValue(newGain);
		//}
		//else
		//{
		//	CIntegerPtr gainRaw(camera.GetNodeMap().GetNode("GainRaw"));
		//	int64_t newGainRaw = (int64_t)GainNum;
		//	newGainRaw = Adjust(newGainRaw, gainRaw->GetMin(), gainRaw->GetMax(), gainRaw->GetInc());
		//	gainRaw->SetValue(newGainRaw);
		//}
		if (camera.IsOpen()) {
			camera.StartGrabbing();
		}
	}
	catch (...) {
		AfxMessageBox(TEXT("相机参数修改失败"));
		if (camera.IsOpen()) {
			CloseCamera();
		}
		return false;
	}
	return true;
}

//bool CameraBasler::UpdateCamera()
//{
//	try {
//		ExposureTimeNum = m_pData->GetBottleDetParam()->ExpostTime;
//		GainNum = m_pData->GetBottleDetParam()->GainValue;
//		double exposuretime = (double)ExposureTimeNum;
//		camera.ExposureTime.SetValue(exposuretime);
//		double gainraw = (double)GainNum;
//		camera.GainSelector.SetValue(GainSelector_All);
//		camera.Gain.SetValue(gainraw);
//
//		if (camera.IsOpen()) {
//			camera.StartGrabbing();
//		}
//	}
//	catch (...) {
//		CString str;
//		str.Format(TEXT("相机%2d参数修改失败"));
//		AfxMessageBox(str);
//		//AfxMessageBox(TEXT("相机%2d参数修改失败"), step);
//		if (camera.IsOpen()) {
//			CloseCamera();
//		}
//		return false;
//	}
//	return true;
//}

void CameraBasler::OutPutResult()
{	
	camera.LineSelector.SetValue(LineSelector_Line2);
	//camera.LineSource.SetValue(LineSource_Off);
	camera.LineInverter.SetValue(false);

	camera.LineSource.SetValue(LineSource_UserOutput1);
	camera.UserOutputValue.SetValue(false);
	camera.UserOutputValue.SetValue(true);
	Sleep(80);
	camera.UserOutputValue.SetValue(false);
	//camera.UserOutputSelector.SetValue(UserOutputSelector_UserOutput1);
	//UserOutputSelectorEnums e = camera.UserOutputSelector.GetValue();
	//Sleep(3000);
	//INodeMap& nodemap = camera.GetNodeMap();
	/*if(ngsignal=="NG")
	{
		


	}*/
	
	//Sleep(3000);
	//camera.LineSelector.SetValue(LineSelector_Line2);

	//camera.LineSource.SetValue(LineSource_UserOutput1);
	//camera.LineInverter.SetValue(true);

	//camera.UserOutputSelector.SetValue(UserOutputSelector_UserOutput1);
	//UserOutputSelectorEnums e = camera.UserOutputSelector.GetValue();

}

void CameraBasler::OutPutResult(int step)
{
}

void CameraBasler::SetTriggerModel(bool Soft)
{
	//INodeMap& nodemap = camera.GetNodeMap();
	if (Soft)
	{
		//camera.TriggerMode.SetValue(TriggerMode_On);
		//camera.TriggerSource.SetValue(TriggerSource_Line1);
		camera.TriggerSelector.SetValue(TriggerSelector_FrameStart);
		camera.TriggerMode.SetValue(TriggerMode_On);
		camera.TriggerSource.SetValue(TriggerSource_Line1);

	}
	else {
		//camera.TriggerMode.SetValue(TriggerMode_Off);
		camera.TriggerMode.SetValue(TriggerMode_Off);

	}
}

void CameraBasler::SetTriggerModel(bool Soft, int step)
{
}

int64_t CameraBasler::Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc)
{
	// Check the input parameters.
	if (inc <= 0)
	{
		// Negative increments are invalid.
		throw LOGICAL_ERROR_EXCEPTION("Unexpected increment %d", inc);
	}
	if (minimum > maximum)
	{
		// Minimum must not be bigger than or equal to the maximum.
		throw LOGICAL_ERROR_EXCEPTION("minimum bigger than maximum.");
	}

	// Check the lower bound.
	if (val < minimum)
	{
		return minimum;
	}

	// Check the upper bound.
	if (val > maximum)
	{
		return maximum;
	}

	// Check the increment.
	if (inc == 1)
	{
		// Special case: all values are valid.
		return val;
	}
	else
	{
		// The value must be min + (n * inc).
		// Due to the integer division, the value will be rounded down.
		return minimum + (((val - minimum) / inc) * inc);
	}
}

cv::Mat CameraBasler::HImage2Mat(HalconCpp::HObject& H_img)
{
	cv::Mat cv_img;
	HalconCpp::HTuple channels, w, h;

	HalconCpp::ConvertImageType(H_img, &H_img, "byte");
	HalconCpp::CountChannels(H_img, &channels);

	if (channels.I() == 1)
	{
		HalconCpp::HTuple pointer;
		GetImagePointer1(H_img, &pointer, nullptr, &w, &h);
		int width = w.I(), height = h.I();
		int size = width * height;
		cv_img = cv::Mat::zeros(height, width, CV_8UC1);
		memcpy(cv_img.data, (void*)(pointer.L()), size);
	}

	else if (channels.I() == 3)
	{
		HalconCpp::HTuple pointerR, pointerG, pointerB;
		HalconCpp::GetImagePointer3(H_img, &pointerR, &pointerG, &pointerB, nullptr, &w, &h);
		int width = w.I(), height = h.I();
		int size = width * height;
		cv_img = cv::Mat::zeros(height, width, CV_8UC3);
		uchar* R = (uchar*)(pointerR.L());
		uchar* G = (uchar*)(pointerG.L());
		uchar* B = (uchar*)(pointerB.L());
		for (int i = 0; i < height; ++i)
		{
			uchar* p = cv_img.ptr<uchar>(i);
			for (int j = 0; j < width; ++j)
			{
				p[3 * j] = B[i * width + j];
				p[3 * j + 1] = G[i * width + j];
				p[3 * j + 2] = R[i * width + j];
			}
		}
	}
	return cv_img;
}
