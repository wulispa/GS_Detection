#include "pch.h"
#include "DataManager.h"

DataManager::DataManager()
{
	xmlPath = TEXT("BottleDet.xml");
	myxml.OpenFile(xmlPath);
	//Num_Image = 1;
}

DataManager::~DataManager()
{
}

vector<string> DataManager::split(const string& str, const string& pattern)
{
	vector<string> ret;
	if (pattern.empty()) return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);
	while (index != str.npos) {
		if (start != index)
			ret.push_back(str.substr(start, index - start));
		start = index + 1;
		index = str.find_first_of(pattern, start);
	}
	if (!str.substr(start).empty())
		ret.push_back(str.substr(start));
	return ret;
}

void DataManager::LoadBottleParam()
{
	ReadBottleClasses();
	ReadSelectBottleName();
}

void DataManager::ReadBottleClasses()
{
	string str = myxml.ReadNodeTxt(TEXT("BottleClassParam"));
	BottleClasses = split(str, "||");
}

void DataManager::AddBottleClasses(CString bottleName)
{
	myxml.AddProject(bottleName);
}

void DataManager::DeleteBottleClasses(CString bottleName)
{
	myxml.DeleteProjNode(bottleName);
}

void DataManager::ReadSelectBottleName()
{
	string str = myxml.ReadNodeTxt(TEXT("BottleSelect"));
	SelectBottleName = str;
}

void DataManager::SetSelectBottleName(CString selectName)
{
	myxml.WriteNodeTxt(TEXT("BottleSelect"), selectName);
}

void DataManager::ReNameBottleName(CString name, CString name2)
{
	myxml.RenameBottleName(name, name2);
}

void DataManager::LoadSystemParam()
{
	m_SystemParam.ThrowModel = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("ThrowModel"));
	m_SystemParam.ShowModel = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("ShowModel"));
	m_SystemParam.SaveModel = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("SaveModel"));
	m_SystemParam.ImageType = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("ImageType"));
	m_SystemParam.AutoLock = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("AutoLock"));
	string AutoLockTime_temp = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("AutoLockTime"));
	m_SystemParam.AutoLockTime = atoi(AutoLockTime_temp.c_str());
	m_SystemParam.BanSelect = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("BanSelect"));
	m_SystemParam.BanNumber = myxml.ReadNodeTxt(TEXT("SystemParam"), TEXT("BanNumber"));

	//m_SystemParam.TargetID = "1111010101011";
}

void DataManager::SetThrowModel(CString throwModel)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("ThrowModel"), throwModel);
}

void DataManager::SetShowModel(CString showModel)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("ShowModel"), showModel);
}

void DataManager::SetSaveModel(CString saveModel)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("SaveModel"), saveModel);
}

void DataManager::SetImageType(CString imageType)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("ImageType"), imageType);
}

void DataManager::SetAutoLock(CString autoLock)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("AutoLock"), autoLock);
}

void DataManager::SetAutoLockTime(CString autoLockTime)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("AutoLockTime"), autoLockTime);
}

void DataManager::SetBanSelect(CString BanSelect)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("BanSelect"), BanSelect);
}

void DataManager::SetBanNumber(CString BanNumber)
{
	myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("BanNumber"), BanNumber);
}



//int DataManager::GetNumImage()
//{
//	LoadBottleDetParam();
//	GrabNum = m_BottleDetParam.GrabNum;
//	return GrabNum;
//}

void DataManager::SetCameraOut(CString CameraOut)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("CameraOut"), CameraOut);

}

void DataManager::SetTrigger(CString TriggerMode)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("Trigger"), TriggerMode);

}

void DataManager::SetNumImage(CString GrabNum)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("GrabNum"), GrabNum);
}

void DataManager::LoadBottleDetParam()
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	//加载检测参数
	m_BottleDetParam.Model_Path = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ModelPath"));
	m_BottleDetParam.Profile_Path = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ProfilePath"));
	string DetThread_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("DetThread"));
	m_BottleDetParam.ThreadValue = stod(DetThread_temp);
	/*string DetThreadLW_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("DetThreadLW"));
	m_BottleDetParam.ThreadValueLW = stod(DetThreadLW_temp);*/
	m_BottleDetParam.ThreadModel = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ThreadModel"));
	string GrayValue_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("GrayValue"));
	m_BottleDetParam.GrayValue = atoi(GrayValue_temp.c_str());
	m_BottleDetParam.GrayModel = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("GrayThresh"));
	m_BottleDetParam.MoldRecognition = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("MoldRecognition"));
	m_BottleDetParam.SelectedMold = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("SelectedMold"));
	m_BottleDetParam.MoldModel_Path = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("MoldModelPath"));
	m_BottleDetParam.MoldProfile_Path = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("MoldProfilePath"));
	

	string ConfidenceValue1_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ConfidenceVal1"));
	m_BottleDetParam.ConfidenceVal1 = stod(ConfidenceValue1_temp.c_str());

	string ConfidenceValue2_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ConfidenceVal2"));
	m_BottleDetParam.ConfidenceVal2 = stod(ConfidenceValue1_temp.c_str());

	string NMSThreshVal_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("NMSThreshVal"));
	m_BottleDetParam.NMSThreshVal = stod(ConfidenceValue1_temp.c_str());

	m_BottleDetParam.ChoseModel=myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ChoseModel"));

	m_BottleDetParam.Show_Region = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ShowRegion"));
	//加载相机参数
	//*************************瓶底相机*****************
	string ExposeTime_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("ExposeTime"));
	m_BottleDetParam.ExpostTime = atoi(ExposeTime_temp.c_str());
	string GainValue_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("GainValue"));
	m_BottleDetParam.GainValue = stod(GainValue_temp);
	m_BottleDetParam.AutoSaveImage = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("AutoSaveImage"));
	m_BottleDetParam.CamOut = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("CameraOut"));
	string GrabNum_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("GrabNum"));
	m_BottleDetParam.GrabNum = atoi(GrabNum_temp.c_str());
	m_BottleDetParam.Trigger = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("Trigger"));
	//*************************模号相机*****************
	string ExposeTime_temp1 = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("ExposeTime1"));
	m_BottleDetParam.ExpostTime1 = atoi(ExposeTime_temp.c_str());
	string GainValue_temp1 = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("GainValue1"));
	m_BottleDetParam.GainValue1 = stod(GainValue_temp);
	m_BottleDetParam.AutoSaveImage1 = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("AutoSaveImage1"));
	m_BottleDetParam.CamOut1 = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("CameraOut1"));
	m_BottleDetParam.Trigger1 = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("Trigger1"));

	//加载传统检测算法参数
	string  inner_radius_temp= myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("inner_radius"));
	m_BottleDetParam.inner_radius = atoi(inner_radius_temp.c_str());

	string  outer_radius_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("outer_radius"));
	m_BottleDetParam.outer_radius = atoi(outer_radius_temp.c_str());

	string  dyn_threshold_val_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("dyn_threshold_val"));
	m_BottleDetParam.dyn_threshold_val = atoi(dyn_threshold_val_temp.c_str());

	string  area_threshold_val_temp = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("area_threshold_val"));
	m_BottleDetParam.area_threshold_val = atoi(area_threshold_val_temp.c_str());

	m_BottleDetParam.contra_val = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("Contrast_val"));
	m_BottleDetParam.area_val = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("Area_val"));
	m_BottleDetParam.gray_val = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("Gray_val"));

	//GS码
	m_BottleDetParam.PhotoelectricDistance= myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("PhotoelectricDistance"));
	m_BottleDetParam.TriggerDistance = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("TriggerDistance"));
	m_BottleDetParam.PersonUse = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("PersonUse"));
}

void DataManager::LoadProductData()
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	m_BottleDetParam.ProductData = myxml.ReadNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ProductData"));
}

void DataManager::SetExpostTime(CString expostTime)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("ExposeTime"), expostTime);
}

void DataManager::SetGainValue(CString gainValue)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("GainValue"), gainValue);
}

void DataManager::SetAutoSaveImage(CString autoSaveImage)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("AutoSaveImage"), autoSaveImage);
}

void DataManager::SetCameraOut1(CString CameraOut)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("CameraOut1"), CameraOut);
}

void DataManager::SetTrigger1(CString TriggerMode)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("Trigger1"), TriggerMode);
}

void DataManager::SetExpostTime1(CString expostTime)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("ExposeTime1"), expostTime);
}

void DataManager::SetGainValue1(CString gainValue)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("GainValue1"), gainValue);
}

void DataManager::SetAutoSaveImage1(CString autoSaveImage)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("CameraParam"), TEXT("AutoSaveImage1"), autoSaveImage);
}

void DataManager::SetModel_Path(CString model_Path)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ModelPath"), model_Path);
}

void DataManager::SetProfile_Path(CString profile_Path)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ProfilePath"), profile_Path);
}

void DataManager::SetThreadValue(CString threadValue)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("DetThread"), threadValue);
}

void DataManager::SetThreadValueLW(CString threadValueLW)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("DetThreadLW"), threadValueLW);
}

void DataManager::SetThreadValueModel(CString threadValueModel)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ThreadModel"), threadValueModel);
}

void DataManager::SetChoseModel(CString ChoseModel)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ChoseModel"), ChoseModel);
}

void DataManager::SetGrayValue(CString GrayValue)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("GrayValue"), GrayValue);
}

void DataManager::SetGrayThresh(CString GrayModel)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("GrayThresh"), GrayModel);
}

void DataManager::SetShow_Region(CString show_Region)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ShowRegion"), show_Region);
}

void DataManager::SetMoldRecognition(CString moldrecognition)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("MoldRecognition"), moldrecognition);
	//myxml.WriteNodeTxt(TEXT("SystemParam"), TEXT("MoldRecognition"), moldrecognition);
}

void DataManager::SetSelectedMold(CString selectedmold)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("SelectedMold"), selectedmold);
}

void DataManager::SetMoldModel_Path(CString moldmodel_path)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("MoldModelPath"), moldmodel_path);
}

void DataManager::SetMoldProfile_Path(CString moldprofile_path)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("MoldProfilePath"), moldprofile_path);
}

void DataManager::SetProductDate(CString productdata)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("ProductData"), productdata);

}

void DataManager::SetCullParameters(CString TriggerDistance, CString PhotoelectricDistance)
{	
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("TriggerDistance"), TriggerDistance);
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("PhotoelectricDistance"), PhotoelectricDistance);
}

void DataManager::SetPersonUse(CString Person)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("PersonUse"), Person);
}

void DataManager::SetTraditionalPara(CString contra_val, CString area_va, CString gray_val)
{
	CString cstr;
	cstr.Format(TEXT("%S"), SelectBottleName.c_str());
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("Contrast_val"), contra_val);
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("Area_val"), area_va);
	myxml.WriteNodeTxt(TEXT("ProjectParam"), cstr, TEXT("AlgorithmParam"), TEXT("Gray_val"), gray_val);
}
