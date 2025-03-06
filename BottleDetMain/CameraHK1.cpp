#include "pch.h"
#include "CameraHK1.h"

CameraHK1::CameraHK1()
{
    nRet = MV_OK;
    Handle = NULL;
    pData = NULL;
    Handle = NULL;
    isOpen = false;
    missCamera = false;
    GraphSuccess = false;
    ExposureTimeNum = 100;//初始曝光时间与增益
    GainNum = 2;
}

CameraHK1::CameraHK1(DataManager* pdata):
    m_pData(pdata),
    GraphSuccess(false)
{
    nRet = MV_OK;
    Handle = NULL;
    isOpen = false;
    ExposureTimeNum = 100;//初始曝光时间与增益
    GainNum = 2;
    SelectCamIndex = 0;
}

CameraHK1::CameraHK1(const CameraHK1& obj)
{
    this->m_pData = obj.m_pData;
    nRet = MV_OK;
    Handle = NULL;
    ExposureTimeNum = 100;//初始曝光时间与增益
    GainNum = 2;
    isOpen = false;
}

CameraHK1& CameraHK1::operator=(const CameraHK1& obj)
{
    // TODO: 在此处插入 return 语句
    if (this == &obj) {
        return *this;
    }
    this->m_pData = obj.m_pData;
    int nRet = MV_OK;
    void* Handle = NULL;
    ExposureTimeNum = 1000;//初始曝光时间与增益
    GainNum = 2;
    isOpen = false;
    return *this;
}

CameraHK1::~CameraHK1()
{
    if (Handle)
    {
        CloseCamera();
        MV_CC_DestroyHandle(Handle);
        Handle = NULL;
    }
}

bool CameraHK1::IsOpen()
{
    return isOpen;
}

void CameraHK1::SetCameraParam()
{
}

int CameraHK1::GraphImage()
{
	try {
		Mat img;
		HObject image;
		missCamera = false;
		ProductImages.clear();
		if (MV_OK == nRet) {
			MV_FRAME_OUT stOutFrame = { 0 };
			memset(&stOutFrame, 0, sizeof(MV_FRAME_OUT));
			nRet = MV_CC_SetCommandValue(Handle, "TriggerSoftware");//相机拍照		
			nRet = MV_CC_GetImageBuffer(Handle, &stOutFrame, INFINITE);
			if (MV_OK == nRet) {
				nRet = MV_CC_GetImageBuffer(Handle, &stOutFrame, INFINITE);
				if (MV_OK == nRet) {
					int W = stOutFrame.stFrameInfo.nWidth;
					int H = stOutFrame.stFrameInfo.nHeight;
					void* pSrcData = stOutFrame.pBufAddr;
					GenImage1(&image, "byte", W, H, (Hlong)pSrcData);
					img = HImageToMat(image);
					SingleImage = img.clone();
					ProductImages.push_back(SingleImage);
				}
				nRet = MV_CC_FreeImageBuffer(Handle, &stOutFrame);
				GraphSuccess = true;
			}
			else {
				GraphSuccess = false;
			}
		}
		else
		{
			GraphSuccess = false;
		}
	}
	catch (const std::exception&) {
		missCamera = true;
		return -1;
	}
	return 1;
}

int CameraHK1::StopGraphImage()
{
    return MV_CC_StopGrabbing(Handle);
}

bool CameraHK1::OpenCamera()
{
	try {
		int res;
		if (Handle)
		{
			StopGraphImage();
			MV_CC_CloseDevice(Handle);		//关闭设备
			Sleep(100);
			MV_CC_DestroyHandle(Handle);
			Handle = NULL;
		}
		// ch:枚举设备 | en:Enum device
		//unsigned char ss[16] = "K00915153";
		memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
		nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
		if (MV_OK != nRet)
		{
			AfxMessageBox(TEXT("FIND NO DEVICE"));
		}
		if (stDeviceList.nDeviceNum > 0)
		{
			for (unsigned int i = 0; i < stDeviceList.nDeviceNum; i++)
			{
				MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[i];
				if (NULL == pDeviceInfo)
				{
					break;
				}
				CamId = (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber;

				if (CamId == "K00915145")
				{
					SelectCamIndex = i;
					break;
				}
			}
			res = MV_CC_CreateHandle(&Handle, stDeviceList.pDeviceInfo[SelectCamIndex]);
			isOpen = true;
			res = MV_CC_OpenDevice(Handle);
			if (res != MV_OK) {
				AfxMessageBox(TEXT("相机被占用"));
				isOpen = false;
			}
			nRet = MV_CC_StartGrabbing(Handle);
		}
		else
		{
			//printf("Find No Devices!\n");
			AfxMessageBox(TEXT("相机未连接"));
		}
	}
	catch (const std::exception&)
	{
		return	false;
	}
	return true;
}

bool CameraHK1::RestartCamera()
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

bool CameraHK1::CloseCamera()
{
	try
	{
		if (Handle) {
			int a = MV_CC_StopGrabbing(Handle);		//停止采集
			int b = MV_CC_CloseDevice(Handle);		//关闭设备
			int c = MV_CC_DestroyHandle(Handle);	//销毁相机句柄
			Handle = NULL;
		}
		isOpen = false;
	}
	catch (const std::exception&)
	{
		Sleep(100);
		CloseCamera();
		return	false;
	}
	return	true;
}

Mat CameraHK1::GetImage()
{
	GraphImage();
	if (missCamera) {
		//发送相机离线消息
		return Mat();
	}
	return SingleImage;//单张图片
}

vector<Mat> CameraHK1::GetImages()
{
	vector<Mat>().swap(ProductImages);
	GraphImage();
	if (missCamera) {
		//发送相机离线消息
		return vector<Mat>();
	}
	return ProductImages;
}

bool CameraHK1::isMissCamera()
{
	return missCamera;
}

bool CameraHK1::isSuccessGraph()
{
	return GraphSuccess;
}

bool CameraHK1::UpdateCamera()
{
	ExposureTimeNum = m_pData->GetBottleDetParam()->ExpostTime1;
	GainNum = m_pData->GetBottleDetParam()->GainValue1;
	//ExposureTimeNum = atof(ExposureTime.c_str());
	//GainNum = atof(Gain.c_str());
	MV_CC_SetFloatValue(Handle, "ExposureTime", ExposureTimeNum);
	MV_CC_SetFloatValue(Handle, "Gain", GainNum);
	//MV_CC_SetImageNodeNum(Handle, CamGrabNum);

	//MV_CC_SetIntValue(Handle, "AcquisitionBurstFrameCount", CamGrabNum);
	MV_CC_SetFloatValue(Handle, "AcquisitionFrameRate", 88);

	//帧率控制使能，true表示打开，false标识关闭
	//nRet = MV_CC_SetBoolValue(Handle, "AcquisitionFrameRateEnable", true);

	//SetTriggerModel(false);
	return true;
}

void CameraHK1::OutPutResult()
{	
	//参数初始化
	nRet = MV_CC_SetEnumValue(Handle, "LineSelector", 1);
	//0:Line0 1:Line1 2:Line2 
	nRet = MV_CC_SetEnumValue(Handle, "LineSource", 5);
	//0:ExposureStartActive 5:SoftTriggerActive  6:HardTriggerActive
	int DurationValue = 70000, DelayValue = 0, PreDelayValue = 0;//us
	nRet = MV_CC_SetIntValue(Handle, "StrobeLineDuration", DurationValue);
	//nRet = MV_CC_SetIntValue(Handle, "StrobeLineDelay", DelayValue);//strobe延时，从曝光开始，延时多久输出
	//nRet = MV_CC_SetIntValue(Handle, "StrobeLinePreDelay", PreDelayValue);//strobe提前输出，曝光延后开始
	nRet = MV_CC_SetBoolValue(Handle, "StrobeEnable", TRUE);
	//Strobe输出使能，使能之后，上面配置参数生效，IO输出与LineSource同步
	//输出IO信号命令
	nRet = MV_CC_SetCommandValue(Handle, "LineTriggerSoftware");
}

void CameraHK1::SetTriggerModel(bool Soft)
{
	if (Soft)
	{
		//MV_CC_SetEnumValue(Handle, "TriggerMode", MV_TRIGGER_MODE_ON);

		// ch:设置触发模式为on | en:Set trigger mode as off
		nRet = MV_CC_SetEnumValue(Handle, "TriggerMode", MV_TRIGGER_MODE_ON);
		if (MV_OK != nRet)
		{
			//printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
		}
		// ch:设置触发源为软触发 | en:Set trigger mode as off
		//nRet = MV_CC_SetEnumValue(Handle, "TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
		//nRet = MV_CC_SetEnumValue(Handle, "TriggerSource", 0);//line2也可做输入源，非光耦
		//if (MV_OK != nRet)
		//{
		//	printf("Set Trigger Mode fail! nRet [0x%x]\n", nRet);
		//}
	}
	else {
		MV_CC_SetEnumValue(Handle, "TriggerMode", MV_TRIGGER_MODE_OFF);
	}
}

cv::Mat CameraHK1::HImageToMat(HalconCpp::HObject& H_img)
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
