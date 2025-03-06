#include "pch.h"
#include "DataStatisticXml.h"

DataStatisticXml::DataStatisticXml()
{
	rootName = TEXT("DatDetect");
}

DataStatisticXml::~DataStatisticXml()
{
}

void DataStatisticXml::OpenFile(CString filename)
{
	FileName = filename;
	xml.Load(FileName);
	xml.FindElem(rootName);
}

void DataStatisticXml::CloseFile()
{
}

unordered_map<int, vector<int>> DataStatisticXml::GetMonthData(int Year, int Month)
{
	unordered_map<int, vector<int>> MonthData;
	vector<int> DayData;

	CString year = Year2CStr(Year);
	CString month = Month2CStr(Month);

	for (int id = 0; id < 31; id++) {
		vector<int>().swap(DayData);
		string id1 = "D" + int2str(id + 1);
		CString id2;
		id2.Format(TEXT("%S"), id1.c_str());

		int daydata1 = ReadTypeData(year, month, id2, TEXT("OK"));
		DayData.push_back(daydata1);
		int daydata2 = ReadTypeData(year, month, id2, TEXT("NG"));
		DayData.push_back(daydata2);
		MonthData[id] = DayData;
	}
	return MonthData;
}

void DataStatisticXml::UpdateYear(int YearNow)
{
	int LocalYear = ReadYear();
	if (LocalYear == YearNow)
	{
		DeleteProjNode(YearNow - 2);
	}
	else
	{
		DeleteProjNode(LocalYear - 1);
		AddState(YearNow);
		WriteYear(YearNow);
	}
}

void DataStatisticXml::WriteNodeTxt(CString Year, CString Month, CString Day, CString Type, int Write_Content)
{
	int nn = ReadTypeData(Year, Month, Day, Type);	//读当前值，int
	int sum;
	if (nn < 0) {			//应对初始为空情况
		nn = 0;
		sum = nn + Write_Content;
	}
	else {
		sum = nn + Write_Content;
	}
	//string sum1 = int2str(sum);		
	CString sum2;//转类型
	sum2.Format(TEXT("%S"), int2str(sum).c_str());
	xml.ResetPos();
	xml.FindChildElem(Year);
	xml.IntoElem();
	xml.FindChildElem(Month);
	xml.IntoElem();
	xml.FindChildElem(Day);
	xml.IntoElem();
	xml.FindChildElem(Type);
	//写入四级级节点内容
	xml.SetChildData(sum2);
	xml.Save(FileName);
}

int DataStatisticXml::ReadYear()
{
	xml.ResetPos();
	string str;
	xml.FindChildElem(TEXT("YEARNOW"));
	str = CW2A(xml.GetChildData().GetString());//CString -> string
	int year = str2int(str);
	xml.ResetPos();
	return year;
}

int DataStatisticXml::ReadTypeData(CString Year, CString Month, CString Day, CString Type)
{
	xml.ResetPos();
	string str;
	int n;

	xml.FindChildElem(Year);
	xml.IntoElem();
	xml.FindChildElem(Month);
	xml.IntoElem();
	xml.FindChildElem(Day);
	xml.IntoElem();
	xml.FindChildElem(Type);
	str = CW2A(xml.GetChildData().GetString());
	n = str2int(str);
	//xml.ResetPos();
	if (n < 0)
	{
		n = 0;
	}
	return n;
}

void DataStatisticXml::AddState(int Year)
{
	xml.FindChildElem(TEXT("YEARNOW"));
	CString cstr = xml.GetChildTagName();
	if (cstr.GetLength() == 0)//cstr.GetLength()：求CString类型的长度，所要删除的项目不存在
	{
		xml.AddChildElem(TEXT("YEARNOW"));
	}
	
	CString year = Year2CStr(Year);

	xml.AddChildElem(year);
	xml.IntoElem();
	for (int im = 0; im < 12; im++) {

		CString month=Month2CStr(im+1);

		xml.AddChildElem(month);
		CString cstr = xml.GetChildTagName();
		xml.IntoElem();
		for (int id = 0; id < 31; id++) {
			string id1 = "D" + int2str(id + 1);
			CString id2 = Day2CStr(id+1);
			id2.Format(TEXT("%S"), id1.c_str());
			xml.AddChildElem(id2);
			xml.IntoElem();
			xml.AddChildElem(TEXT("OK"));
			xml.SetChildData(0);
			xml.AddChildElem(TEXT("NG"));
			xml.SetChildData(0);
			xml.OutOfElem();
		}
		xml.OutOfElem();
	}
	xml.OutOfElem();

	xml.Save(FileName);
}

int DataStatisticXml::DeleteProjNode(int Year)
{
	CString year = Year2CStr(Year);

	xml.ResetPos();
	xml.FindChildElem(year);
	CString cstr = xml.GetChildTagName();
	if (cstr.GetLength() == 0)//cstr.GetLength()：求CString类型的长度，所要删除的项目不存在
	{
		return -1;
	}
	else//删除成功
	{
		xml.RemoveChildElem();
		xml.Save(FileName);
		return 0;
	}
}

int DataStatisticXml::DeleteProjNode(int Year, int Month)
{
	CString year = Year2CStr(Year);
	CString month = Month2CStr(Month);

	xml.ResetPos();
	xml.FindChildElem(year);
	xml.IntoElem();
	xml.FindChildElem(month);
	CString cstr = xml.GetChildTagName();
	if (cstr.GetLength() == 0)//cstr.GetLength()：求CString类型的长度，所要删除的项目不存在
	{
		return -1;
	}
	else//删除成功
	{
		xml.RemoveChildElem();
		xml.Save(FileName);
		return 0;
	}
}

int DataStatisticXml::DeleteProjNode(CString Year, CString Month, CString Day)
{
	xml.ResetPos();
	xml.FindChildElem(Year);
	xml.IntoElem();
	xml.FindChildElem(Month);
	xml.IntoElem();
	xml.FindChildElem(Day);
	CString cstr = xml.GetChildTagName();
	if (cstr.GetLength() == 0)//cstr.GetLength()：求CString类型的长度，所要删除的项目不存在
	{
		return -1;
	}
	else//删除成功
	{
		xml.RemoveChildElem();
		xml.Save(FileName);
		return 0;
	}
}

void DataStatisticXml::WriteYear(int YearNow)
{
	xml.ResetPos();
	xml.FindChildElem(TEXT("YEARNOW"));
	//写入一级节点内容
	xml.SetChildData(YearNow);
	xml.Save(FileName);
}



int DataStatisticXml::str2int(string str)
{
	stringstream stream;     //声明一个stringstream变量
	int n;
	//string转int
	stream << str;     //向stream中插入字符串
	stream >> n;
	return n;
}

string DataStatisticXml::int2str(int n)
{
	stringstream stream;     //声明一个stringstream变量
	string str;
	//string转int
	stream << n;     //向stream中插入字符串
	stream >> str;
	return str;
}

CString DataStatisticXml::Year2CStr(int Year)
{
	string yea = "Y" + int2str(Year);
	CString year;
	year.Format(TEXT("%S"), yea.c_str());
	return year;
}

CString DataStatisticXml::Month2CStr(int Month)
{
	string mon = "M" + int2str(Month);
	CString month;
	month.Format(TEXT("%S"), mon.c_str());
	return month;
}

CString DataStatisticXml::Day2CStr(int Day)
{
	string da = "D" + int2str(Day);
	CString day;
	day.Format(TEXT("%S"), da.c_str());
	return day;
}
