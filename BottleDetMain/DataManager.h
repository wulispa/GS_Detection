#pragma once
#include "publicspace.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

#include "MyXml.h"

using namespace std;
using namespace bodet;


/************************************************
*   功能：参数管理接口
*	日期：2022-11-30
************************************************/

class DataManager
{
public:
	DataManager();
	~DataManager();
	CString xmlPath;
	MyXml myxml;

public:
	/************************************************
	*   功能：string类型的字符串分离
	*	参数：
	*	返回值：
	************************************************/
	vector<string> split(const string& str, const string& pattern);


public:
/*------------------------------瓶子品种参数-------------------------------*/
	vector<string>BottleClasses;//瓶子名称列表
	string SelectBottleName;//选择检测的瓶子名称

	/************************************************
	*   功能：加载瓶子品种参数
	*	参数：
	*	返回值：
	************************************************/
	void LoadBottleParam();

	/************************************************
	*   功能：获取瓶子名称列表
	*	参数：
	*	返回值：
	************************************************/
	void ReadBottleClasses();

	/************************************************
	*   功能：添加名称至列表，并写入配置文件
	*	参数：
	*	返回值：
	************************************************/
	void AddBottleClasses(CString bottleName);

	/************************************************
	*   功能：从列表中删除名称并保存至文件
	*	参数：
	*	返回值：
	************************************************/
	void DeleteBottleClasses(CString bottleName);

	/************************************************
	*   功能：
	*	参数：
	*	返回值：
	************************************************/
	vector<string> GetBottleClasses() {return BottleClasses;}

	/************************************************
	*   功能：获取选择名称
	*	参数：
	*	返回值：
	************************************************/
	string GetSelectBottleName() { return SelectBottleName; }

	/************************************************
	*   功能：读取选择名称
	*	参数：
	*	返回值：
	************************************************/
	void ReadSelectBottleName();

	/************************************************
	*   功能：设置选择名称，并写入配置文件
	*	参数：
	*	返回值：
	************************************************/
	void SetSelectBottleName(CString selectName);

	/************************************************
	*   功能：重命名节点
	*	参数：
	*	返回值：
	************************************************/
	void ReNameBottleName(CString name, CString name2);
	
/*------------------------------系统参数------------------------------*/
	//struct SystemParam
	//{
	//	//系统参数
	//	string ThrowModel;//NORMAL  SUSTAIN  NO
	//	string ShowModel;//SUSTAIN  ONLYBAD
	//	string SaveModel;//NO AUTO AUTOBAD
	//	bool AutoLock;//true false
	//	int AutoLockTime;//
	//};
	SystemParam m_SystemParam;

	/************************************************
	*   功能：加载系统参数
	*	参数：
	*	返回值：
	************************************************/
	void LoadSystemParam();

	/************************************************
	*   功能：获取系统参数
	*	参数：
	*	返回值：
	************************************************/
	SystemParam* GetSystemParam() {return &m_SystemParam;}

	/************************************************
	*   功能：设置剔瓶方式
	*	参数：
	*	返回值：
	************************************************/
	void SetThrowModel(CString throwModel);

	/************************************************
	*   功能：设置显示模式
	*	参数：
	*	返回值：
	************************************************/
	void SetShowModel(CString showModel);

	/************************************************
	*   功能：设置保存模式
	*	参数：
	*	返回值：
	************************************************/
	void SetSaveModel(CString saveModel);

	/************************************************
	*   功能:设置图片类型
	*	参数：
	*	返回值：
	************************************************/
	void SetImageType(CString imageType);

	/************************************************
	*   功能:设置锁定模式
	*	参数：
	*	返回值：
	************************************************/
	void SetAutoLock(CString autoLock);

	/************************************************
	*   功能：设置锁定时间
	*	参数：
	*	返回值：
	************************************************/
	void SetAutoLockTime(CString autoLockTime);

	/************************************************
	*   功能：设置两班三班
	*	参数：
	*	返回值：
	************************************************/
	void SetBanSelect(CString BanSelect);
	/************************************************
	*   功能：设置当前班次
	*	参数：
	*	返回值：
	************************************************/
	void SetBanNumber(CString BanNumber);


/*---------------------------------检测参数-----------------------------*/
	//struct BottleDetParam
	//{
	//	//相机参数
	//	int ExpostTime;
	//	string GainValue;
	//	string AutoSaveImage;
	//	//检测参数
	//	string Model_Path;
	//	string Profile_Path;
	//	string ThreadValue;
	//	string Show_Region;
	//};
	BottleDetParam m_BottleDetParam;
	int GrabNum;//单张采图/连续采图
	vector<Mat> CamImages;
	/************************************************
	*   功能：
	*	参数：
	*	返回值：
	************************************************/
	//int GetNumImage();


	/************************************************
	*   功能：加载检测参数
	*	参数：
	*	返回值：
	************************************************/
	void LoadBottleDetParam();
	/************************************************
	*   功能：使用按钮时候在读就加载检测参数
	*	参数：
	*	返回值：
	************************************************/
	void LoadProductData();


	/************************************************
	*   功能：获取检测参数
	*	参数：
	*	返回值：
	************************************************/
	BottleDetParam* GetBottleDetParam() { return &m_BottleDetParam; }

	

	/************************************************
	*   功能：
	*	参数：
	*	返回值：
	************************************************/
	//***********************瓶底相机**********
	void SetCameraOut(CString CameraOut);
	void SetTrigger(CString TriggerMode);
	void SetNumImage(CString GrabNum);
	void SetExpostTime(CString expostTime);
	void SetGainValue(CString gainValue);
	void SetAutoSaveImage(CString autoSaveImage);
	//***********************模号相机**********
	void SetCameraOut1(CString CameraOut);
	void SetTrigger1(CString TriggerMode);
	void SetExpostTime1(CString expostTime);
	void SetGainValue1(CString gainValue);
	void SetAutoSaveImage1(CString autoSaveImage);
	//*************************检测参数*************
	void SetModel_Path(CString model_Path);
	void SetProfile_Path(CString profile_Path);
	void SetThreadValue(CString threadValue);
	void SetThreadValueLW(CString threadValueLW);
	void SetThreadValueModel(CString threadValueModel);
	void SetChoseModel(CString ChoseModel);
	void SetGrayValue(CString GrayValue);
	void SetGrayThresh(CString GrayModel);
	void SetShow_Region(CString show_Region);
	void SetMoldRecognition(CString moldrecognition);	
	void SetSelectedMold(CString selectedmold);		
	void SetMoldModel_Path(CString moldmodel_path);
	void SetMoldProfile_Path(CString moldprofile_path);
	//GS码项目
	void SetProductDate(CString productdata);  //GS码：生产批次日期
	void SetCullParameters(CString TriggerDistance, CString PhotoelectricDistance);
	void SetPersonUse(CString Person);
	//****************传统算法
	void SetTraditionalPara(CString contra_val, CString area_va, CString gray_val);//传统算法参数

};

