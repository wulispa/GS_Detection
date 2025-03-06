#include "pch.h"
//#include "stdafx.h"
#include "HiKCamera.h"
#include <afxstr.h>
#include <vector>

using namespace std;


HiKCamera::HiKCamera()
{
	InitLib();
	isOpen = false;
}

HiKCamera::~HiKCamera()
{
	if (Handle)
	{
		MV_CC_DestroyHandle(Handle);
		Handle = NULL;
	}
}

void HiKCamera::InitLib()
{
	int nRet = MV_OK;
	void* Handle = NULL;
	//CamConnected = false;
}

//int HiKCamera::EnumDevices(MV_CC_DEVICE_INFO_LIST* pstDevList)
//{
//	int temp = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, pstDevList);
//	if (MV_OK != temp)
//	{
//		return -1;
//	}
//	return 0;
//	//return MV_CC_EnumDevices(pstDevList);
//}

void HiKCamera::OpenCam()
{
	if (Handle)
	{
		MV_CC_DestroyHandle(Handle);
		Handle = NULL;
	}
	MV_CC_DEVICE_INFO stDevInfo = { 0 };
	MV_GIGE_DEVICE_INFO stGigEDev = { 0 };
	char nCurrentIp[128] = "192.168.16.1";
	char nNetExport[128] = "192.168.16.68";
	unsigned int nIp1, nIp2, nIp3, nIp4, nIp;

	sscanf_s(nCurrentIp, "%d.%d.%d.%d", &nIp1, &nIp2, &nIp3, &nIp4);
	nIp = (nIp1 << 24) | (nIp2 << 16) | (nIp3 << 8) | nIp4;
	stGigEDev.nCurrentIp = nIp;

	sscanf_s(nNetExport, "%d.%d.%d.%d", &nIp1, &nIp2, &nIp3, &nIp4);
	nIp = (nIp1 << 24) | (nIp2 << 16) | (nIp3 << 8) | nIp4;
	stGigEDev.nNetExport = nIp;

	stDevInfo.nTLayerType = MV_GIGE_DEVICE;// Only support GigE camera

	stDevInfo.SpecialInfo.stGigEInfo = stGigEDev;
	//[0]GigE:    Hikrobot MV - CE120 - 10GC(00J22969081)  (192.168.16.1)
	MV_CC_CreateHandle(&Handle, &stDevInfo);

	MV_CC_OpenDevice(Handle);
	isOpen = true;
}


int HiKCamera::StartGrabbing()
{
	return MV_CC_StartGrabbing(Handle);
}

int HiKCamera::StopGrabbing()
{
	return MV_CC_StopGrabbing(Handle);
}

void HiKCamera::GetImage()
{
	//images.clear();
	//if (Handle) {
	//	//MV_CC_SetEnumValue(Handle, "TriggerMode", MV_TRIGGER_MODE_OFF);
	//	MV_CC_SetEnumValue(Handle, "TriggerMode", MV_TRIGGER_MODE_ON);

	//	StartGrabbing();
	//	MV_FRAME_OUT stImageInfo = { 0 };
	//	int res=MV_CC_GetImageBuffer(Handle, &stImageInfo, INFINITE);
	//	if (res == MV_OK) {
	//		int W = stImageInfo.stFrameInfo.nWidth;
	//		int H = stImageInfo.stFrameInfo.nHeight;
	//		void*pSrcData = stImageInfo.pBufAddr;
	//		GenImage1(&H_image, "byte", W, H, (Hlong)pSrcData);
	//		images.push_back(H_image);
	//	}
	//	else
	//	{
	//		AfxMessageBox(TEXT("ERROR"));
	//	}

	//	MV_CC_FreeImageBuffer(Handle, &stImageInfo);		
	//}
}

void HiKCamera::CloseCam()
{
	if (Handle) {
		MV_CC_StopGrabbing(Handle);		// Stop grab image
		
		MV_CC_CloseDevice(Handle);		// Close device
		
		MV_CC_DestroyHandle(Handle);	// Destroy handle
	
		Handle = NULL;

	}
}

bool HiKCamera::SaveImage(CString folder_path){
	bool finish = false;
	try {
		/*int i = 0;
		for (std::vector<HObject>::iterator it = images.begin(); it < images.end(); it++) {

			WriteImage(*it, "bmp", 0, (CString2HTuple(folder_path) + (HTuple)i + ".bmp"));
			i++;
		}*/
		finish = true;
		return finish;
	}
	catch (...) {
		return finish;
	}
}
//HTuple HiKCamera::CString2HTuple(CString cString){
//	//CString×ª»»ÎªHTuple
//	USES_CONVERSION;
//	HTuple hv_String = T2A(cString.GetBuffer(0));
//	cString.ReleaseBuffer();
//	return hv_String;
//}

void HiKCamera::SetExposureTime(float ExposureTimeNum)
{
	if (Handle) {
		MV_CC_SetFloatValue(Handle, "ExposureTime", ExposureTimeNum);
	}
}
