#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Markup.h"
#include <sstream>

using namespace std;

/************************************************
*   功能：读写配置文件，负责数据统计XML文件的所有操作
*	日期：2022/12/12
************************************************/

class DataStatisticXml
{
public:
	DataStatisticXml();
	~DataStatisticXml();
private:
	CMarkup xml;
	CString FileName;

public:
	void OpenFile(CString filename);
	void CloseFile();

	unordered_map<int, vector<int>> GetMonthData(int Year, int Month);
	/*-------------------------读取系统参数---------------------------
	系统参数：DatDetect、 Year、 Month、Day、Data
	-----------------------------------------------------------------*/
public:
	void UpdateYear(int YearNow);
	/************************************************
	*   功能：写四级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteNodeTxt(CString Year, CString Month, CString Day, CString Type, int Write_Content);


	CString rootName ;//根节点名称

	/************************************************
	*   功能：读取当前年份
	*	参数：
	*	返回值：
	************************************************/
	int ReadYear();

	/************************************************
	*   功能：读取四级节点的内容
	*	参数：读OK/NG内容
	*	返回值：
	************************************************/
	int ReadTypeData(CString Year, CString Month, CString Day, CString Type);

	/************************************************
	*   功能：添加工位结点
	*	参数：年
	*	返回值：
	************************************************/
	void AddState(int Year);

	/************************************************
	*   功能：删除项目节点和节点下的所有内容
	*	参数：年
	*	返回值：删除状态 0正常  -1项目不存在
	************************************************/
	int DeleteProjNode(int Year);

	/************************************************
	*   功能：删除项目节点和节点下的所有内容
	*	参数：月
	*	返回值：删除状态 0正常  -1项目不存在
	************************************************/
	int DeleteProjNode(int Year, int Month);

	/************************************************
	*   功能：删除项目节点和节点下的所有内容
	*	参数：日
	*	返回值：删除状态 0正常  -1项目不存在``
	************************************************/
	int DeleteProjNode(CString Year, CString Month, CString Day);

	/************************************************
	*   功能：删除项目节点和节点下的所有内容
	*	参数：OK.NG
	*	返回值：删除状态 0正常  -1项目不存在
	************************************************/
	int DeleteProjNode(CString Year, CString Month, CString Day, CString Type);

	/************************************************
	*   功能：写一级节点内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteYear(int YearNow);



	/************************************************
	*   功能：重写项目节点名称
	*	参数：重命名节点名称
	*	返回值：
	************************************************/
	int RenameBottleName(CString src, CString dst);

	int str2int(string str);

	string int2str(int n);

	CString Year2CStr(int Year);

	CString Month2CStr(int Month);

	CString Day2CStr(int Day);

};

