#include "pch.h"
#include "MyXml.h"

#define M_PI 3.14159265358979323846
//iuwegfukyewg
/*写点中文看是否显示*/

MyXml::MyXml()
{
	rootName = TEXT("BottleDetBase");
}
MyXml::~MyXml()
{

}

vector<string> MyXml::split(const string& str, const string& pattern)
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

void MyXml::OpenFile(CString filename)
{
	FileName = filename;
	xml.Load(FileName);
	xml.FindElem(rootName);
}

string MyXml::ReadNodeTxt(CString First_NodeName)
{
	xml.ResetPos();
	string str;
	xml.FindChildElem(First_NodeName);
	str = CW2A(xml.GetChildData().GetString());//CString -> string
	xml.ResetPos();
	return str;
}

string MyXml::ReadNodeTxt(CString First_NodeName, CString Second_NodeName)
{
	xml.ResetPos();
	string str;
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	//CString str1 = xml.GetChildTagName();
	str = CW2A(xml.GetChildData().GetString());
	xml.OutOfElem();
	xml.ResetPos();
	return str;
}

string MyXml::ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName)
{
	xml.ResetPos();
	string str;
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Third_NodeName);
	str = CW2A(xml.GetChildData().GetString());
	xml.ResetPos();
	return str;
}

string MyXml::ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName)
{
	xml.ResetPos();
	string str;
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Third_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Forth_NodeName);
	str = CW2A(xml.GetChildData().GetString());
	xml.ResetPos();
	return str;
}

string MyXml::ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Five_NodeName)
{
	xml.ResetPos();
	string str;
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Third_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Forth_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Five_NodeName);
	str = CW2A(xml.GetChildData().GetString());
	xml.ResetPos();
	return str;
}

void MyXml::AddProject(CString ProjectName)
{
	xml.ResetPos();
	xml.FindChildElem(TEXT("ProjectParam"));
	xml.IntoElem();
	xml.AddChildElem(ProjectName);
	xml.IntoElem();
	xml.AddChildElem(TEXT("AlgorithmParam"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("ModelPath"));
	xml.SetChildData(TEXT("D:/import_file_5_0320/import_file/Profile.txt"));
	xml.AddChildElem(TEXT("ProfilePath"));
	xml.SetChildData(TEXT("D:/import_file_5_0320/import_file/import_model_cfg.txt"));
	xml.AddChildElem(TEXT("DetThread"));
	xml.SetChildData(TEXT("100"));

	xml.AddChildElem(TEXT("ThreadModel"));
	xml.SetChildData(TEXT("NO"));

	xml.AddChildElem(TEXT("DetThreadLW"));
	xml.SetChildData(TEXT("1"));

	xml.AddChildElem(TEXT("GrayValue"));
	xml.SetChildData(TEXT("100"));

	xml.AddChildElem(TEXT("GrayThresh"));
	xml.SetChildData(TEXT("TRUE"));

	xml.AddChildElem(TEXT("ConfidenceVal1"));
	xml.SetChildData(TEXT("0.5"));

	xml.AddChildElem(TEXT("ConfidenceVal2"));
	xml.SetChildData(TEXT("0.5"));

	xml.AddChildElem(TEXT("NMSThreshVal"));
	xml.SetChildData(TEXT("0.5"));

	xml.AddChildElem(TEXT("ChoseModel"));
	xml.SetChildData(TEXT("NONE&AI"));

	//xml.AddChildElem(TEXT("ShowRegion"));
	//xml.SetChildData(TEXT("TRUE"));

	xml.AddChildElem(TEXT("outer_radius"));
	xml.SetChildData(TEXT("350"));
	xml.AddChildElem(TEXT("inner_radius"));
	xml.SetChildData(TEXT("270"));
	xml.AddChildElem(TEXT("dyn_threshold_val"));
	xml.SetChildData(TEXT("10"));
	xml.AddChildElem(TEXT("area_threshold_val"));
	xml.SetChildData(TEXT("150"));

	xml.AddChildElem(TEXT("Contrast_val"));
	xml.SetChildData(TEXT("10,20,30,40"));
	xml.AddChildElem(TEXT("Area_val"));
	xml.SetChildData(TEXT("400,200,130,140"));
	xml.AddChildElem(TEXT("Gray_val"));
	xml.SetChildData(TEXT("50,60,70,80"));


	xml.AddChildElem(TEXT("MoldRecognition"));
	xml.SetChildData(TEXT("MOLDON"));
	xml.AddChildElem(TEXT("SelectedMold"));
	xml.SetChildData(TEXT("1"));
	xml.AddChildElem(TEXT("MoldModelPath"));
	xml.SetChildData(TEXT("/001/0.pth"));
	xml.AddChildElem(TEXT("MoldProfilePath"));
	xml.SetChildData(TEXT("/001/0.txt"));

	xml.OutOfElem();
	xml.AddChildElem(TEXT("CameraParam"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("ExposeTime"));
	xml.SetChildData(TEXT("120"));
	xml.AddChildElem(TEXT("GainValue"));
	xml.SetChildData(TEXT("2"));
	xml.AddChildElem(TEXT("AutoSaveImage"));
	xml.SetChildData(TEXT("TRUE"));
	xml.AddChildElem(TEXT("GrabNum"));
	xml.SetChildData(TEXT("5"));
	xml.AddChildElem(TEXT("Trigger"));
	xml.SetChildData(TEXT("ON"));
	xml.AddChildElem(TEXT("CameraOut"));
	xml.SetChildData(TEXT("TRUE"));

	xml.ResetPos();
	xml.FindChildElem(TEXT("BottleClassParam"));
	CString cstr_temp = xml.GetChildData();
	cstr_temp.Append(ProjectName);
	cstr_temp.Append(TEXT("||"));
	xml.SetChildData(cstr_temp);
	xml.Save(FileName);
}

void MyXml::AddState(CString ProjectName)
{
	xml.ResetPos();
	xml.FindChildElem(TEXT("ProjectList"));
	xml.IntoElem();
	xml.FindChildElem(ProjectName);
	xml.IntoElem();
	xml.FindChildElem(TEXT("StateNum"));
	CString str = xml.GetChildData();
	int StateNum = _ttoi(str);//CString -> int
	StateNum = StateNum + 1;
	string StateName = "STATE" + to_string(StateNum);//将字符串与数字拼接
	str.Format(TEXT("%d"), StateNum);//int -> CString
	xml.SetChildData(str);
	CString StateName_cstr;
	StateName_cstr.Format(TEXT("%S"), StateName.c_str());//string -> CString
	//开始添加工位节点
	xml.AddChildElem(StateName_cstr);
	xml.IntoElem();
	xml.AddChildElem(TEXT("Camera"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("Class"));
	xml.AddChildElem(TEXT("CameraName"));
	xml.AddChildElem(TEXT("DeviceName"));
	xml.AddChildElem(TEXT("ImageWidth"));
	xml.AddChildElem(TEXT("ImageHeight"));
	xml.OutOfElem();
	xml.AddChildElem(TEXT("OutPutPos"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("ComPos"));
	xml.OutOfElem();
	xml.AddChildElem(TEXT("DetAlgorithm"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("AlgorithmName"));
	xml.OutOfElem();
	xml.AddChildElem(TEXT("PreAlgorithm"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("AlgorithmName"));
	xml.OutOfElem();
	xml.AddChildElem(TEXT("LightControl"));
	xml.IntoElem();
	xml.AddChildElem(TEXT("ComPos"));
	xml.AddChildElem(TEXT("LightValue"));
	xml.AddChildElem(TEXT("CH"));
	xml.OutOfElem();
	xml.Save(FileName);
}

int MyXml::DeleteProjNode(CString ProjectName)
{
	xml.ResetPos();
	xml.FindChildElem(TEXT("ProjectParam"));
	xml.IntoElem();
	xml.FindChildElem(ProjectName);
	CString cstr = xml.GetChildTagName();
	if (cstr.GetLength() == 0)//cstr.GetLength()：求CString类型的长度，所要删除的项目不存在
	{
		return -1;
	}
	else//删除成功
	{
		xml.RemoveChildElem();
		xml.ResetPos();
		xml.FindChildElem(TEXT("BottleClassParam"));
		CString cstr_temp = xml.GetChildData();
		string str_temp;
		string str_temp1;
		CString cstr_temp1;
		CString cstr_ret;
		str_temp = CW2A(cstr_temp.GetString());//CString -> string
		str_temp1 = CW2A(ProjectName.GetString());//CString -> string
		vector<string> Vstr_temp = split(str_temp, "||");
		int len = Vstr_temp.size();
		for (size_t i = 0; i < len; i++)
		{
			if (Vstr_temp[i] != str_temp1)
			{
				cstr_temp1.Format(TEXT("%S"), Vstr_temp[i].c_str());//string -> CString
				cstr_ret.Append(cstr_temp1);
				cstr_ret.Append(TEXT("||"));
			}
			else
			{
				continue;
			}
		}
		xml.SetChildData(cstr_ret);
		xml.ResetPos();
		xml.Save(FileName);
		return 0;
	}
}

void MyXml::WriteNodeTxt(CString First_NodeName, CString Write_Content)
{
	xml.ResetPos();
	xml.FindChildElem(First_NodeName);
	//写入一级节点内容
	xml.SetChildData(Write_Content);
	xml.Save(FileName);
	//CString str = xml.GetChildTagName();
}

void MyXml::WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Write_Content)
{
	xml.ResetPos();
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	//写入二级内容
	xml.SetChildData(Write_Content);
	xml.Save(FileName);
}

void MyXml::WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Write_Content)
{
	xml.ResetPos();
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Third_NodeName);
	//写入三级节点内容
	xml.SetChildData(Write_Content);
	xml.Save(FileName);
}

void MyXml::WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Write_Content)
{
	xml.ResetPos();
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Third_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Forth_NodeName);
	//写入四级级节点内容
	xml.SetChildData(Write_Content);
	xml.Save(FileName);
}

void MyXml::WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Five_NodeName, CString Write_Content)
{
	xml.ResetPos();
	xml.FindChildElem(First_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Second_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Third_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Forth_NodeName);
	xml.IntoElem();
	xml.FindChildElem(Five_NodeName);
	//写入五级级节点内容
	xml.SetChildData(Write_Content);
	xml.Save(FileName);
}
int MyXml::RenameBottleName(CString src, CString dst)
{
	xml.ResetPos();
	xml.FindChildElem(TEXT("ProjectParam"));
	xml.IntoElem();
	xml.FindChildElem(src);
	CString cstr = xml.GetChildTagName();
	if (cstr.GetLength() == 0)//cstr.GetLength()：求CString类型的长度，所要删除的项目不存在
	{
		return -1;
	}
	else//删除成功
	{
		xml.IntoElem();
		CString str;
		str = xml.GetElemContent();
		xml.InsertElem(dst);
		xml.SetElemContent(str);

		xml.ResetPos();
		xml.FindChildElem(TEXT("ProjectParam"));
		xml.IntoElem();
		xml.FindChildElem(src);
		xml.RemoveChildElem();

		xml.ResetPos();
		xml.FindChildElem(TEXT("BottleClassParam"));
		CString cstr_temp = xml.GetChildData();
		string str_temp;
		string str_temp1;
		CString cstr_temp1;
		CString cstr_ret;
		str_temp = CW2A(cstr_temp.GetString());//CString -> string
		str_temp1 = CW2A(src.GetString());//CString -> string
		vector<string> Vstr_temp = split(str_temp, "||");
		int len = Vstr_temp.size();
		for (size_t i = 0; i < len; i++)
		{
			if (Vstr_temp[i] != str_temp1)
			{
				cstr_temp1.Format(TEXT("%S"), Vstr_temp[i].c_str());//string -> CString
				cstr_ret.Append(cstr_temp1);
				cstr_ret.Append(TEXT("||"));
			}
			else
			{
				cstr_ret.Append(dst.GetString());
				cstr_ret.Append(TEXT("||"));

				continue;
			}
		}
		xml.SetChildData(cstr_ret);
		xml.ResetPos();
		xml.Save(FileName);
		return 0;
	}
}

unordered_map<string, string> MyXml::Read_Code(CString xml_path)
{
	unordered_map<string, string> Code_temp;
	unordered_map<string, string> Code_temp_inv;
	CString cstr_temp;
	CString cstr_k;
	CString cstr_v;
	string str_k;
	string str_v;

	xml.Load(xml_path);
	xml.FindElem(TEXT("BOTTLE"));
	for (int i = 1; i <= 90; i++)
	{
		cstr_temp.Format(TEXT("%d"), i);
		xml.FindChildElem(TEXT("S") + cstr_temp);
		cstr_k = xml.GetChildTagName();
		cstr_v = xml.GetChildData();
		str_k = CW2A(cstr_k.GetString());
		str_v = CW2A(cstr_v.GetString());
		Code_temp[str_k] = str_v;
		Code_temp_inv[str_v] = str_k;
	}
	Code_Vec_type2code = Code_temp;
	Code_Vec_code2type = Code_temp_inv;
	return Code_temp;
}

string MyXml::Coordinate2Code(std::vector<pair<int, int>> points, bool codeORtype)
{
	double center_x;
	double center_y;
	double radius;
	int point_temp_x;
	int point_temp_y;
	double angle_temp_last = 0;
	double angle_temp_first = 0;
	double angle_total;
	double angle_ave;
	double angle_code;
	pair<int, int> point_temp_last;
	pair<int, int> point_temp_first;
	int flag_last;
	int flag_first;
	string code = "1000000000001";
	//std::vector<pair<int, int>> points{ {156,144},{141,149},{124,158},{100,178},{78,217},{73,261},{76,277},{87,305},{95,318} };
	//std::vector<pair<int, int>> points{ {141,149},{124,158},{100,178},{156,144},{78,217},{95,318},{73,261},{76,277},{87,305} };
	//std::vector<pair<int, int>> points{ {378,272},{750,236},{403,254},{722,223},{689,214},{462,226},{524,207},{555,202},{655,206} };
	//points.push_back({3,4});
	circleLeastFit(points, center_x, center_y, radius);
	double angle_11 = get_angle(points[0].first, points[0].second, points[1].first, points[1].second, center_x, center_y);


	//找出顺时针的起点和终点
	for (int i = 0; i < 9; i++)
	{
		point_temp_x = points[0].first;
		point_temp_y = points[0].second;
		double angle = get_angle(point_temp_x, point_temp_y, points[i].first, points[i].second, center_x, center_y);
		if (angle >= 0 && angle >= angle_temp_first)
		{
			angle_temp_first = angle;
			point_temp_first = points[i];
			flag_first = i;
		}
		if (angle <= 0 && angle <= angle_temp_last)
		{
			angle_temp_last = angle;
			point_temp_last = points[i];
			flag_last = i;
		}
	}
	points[0].swap(points[flag_first]);
	points[8].swap(points[flag_last]);

	//求总角度
	angle_total = get_angle(points[0].first, points[0].second, points[8].first, points[8].second, center_x, center_y);
	angle_ave = abs(angle_total / 12);

	//根据坐标转编码
	for (int i = 0; i < 7; i++)
	{
		angle_code = abs(get_angle(points[0].first, points[0].second, points[i + 1].first, points[i + 1].second, center_x, center_y));
		if (angle_code >= 0.5 * angle_ave && angle_code < 1.5 * angle_ave)
		{
			code.replace(1, 1, "1");
		}
		if (angle_code >= 1.5 * angle_ave && angle_code < 2.5 * angle_ave)
		{
			code.replace(2, 1, "1");
		}
		if (angle_code >= 2.5 * angle_ave && angle_code < 3.5 * angle_ave)
		{
			code.replace(3, 1, "1");
		}
		if (angle_code >= 3.5 * angle_ave && angle_code < 4.5 * angle_ave)
		{
			code.replace(4, 1, "1");
		}
		if (angle_code >= 4.5 * angle_ave && angle_code < 5.5 * angle_ave)
		{
			code.replace(5, 1, "1");
		}
		if (angle_code >= 5.5 * angle_ave && angle_code < 6.5 * angle_ave)
		{
			code.replace(6, 1, "1");
		}
		if (angle_code >= 6.5 * angle_ave && angle_code < 7.5 * angle_ave)
		{
			code.replace(7, 1, "1");
		}
		if (angle_code >= 7.5 * angle_ave && angle_code < 8.5 * angle_ave)
		{
			code.replace(8, 1, "1");
		}
		if (angle_code >= 8.5 * angle_ave && angle_code < 9.5 * angle_ave)
		{
			code.replace(9, 1, "1");
		}
		if (angle_code >= 9.5 * angle_ave && angle_code < 10.5 * angle_ave)
		{
			code.replace(10, 1, "1");
		}
		if (angle_code >= 10.5 * angle_ave && angle_code < 11.5 * angle_ave)
		{
			code.replace(11, 1, "1");
		}
	}
	//// 设置窗口
	//Mat img = Mat::zeros(Size(800, 600), CV_8UC3);
	//img.setTo(255);              // 设置屏幕为白色
	////Point p1(100, 100);          // 点p1
	////Point p2(758, 50);           // 点p2
	//circle(img, Point(center_x, center_y), radius, Scalar(0, 255, 0), -1);
	//// 画直线函数
	//line(img, Point(center_x, center_y), Point(378, 272), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(750, 236), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(403, 254), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(722, 223), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(689, 214), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(462, 226), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(524, 207), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(555, 202), Scalar(0, 0, 255), 2);   // 红色
	//line(img, Point(center_x, center_y), Point(655, 206), Scalar(0, 0, 255), 2);   // 红色
	//imshow("画板", img);
	//waitKey();
	reverse(code.begin(), code.end());
	Code_Cur = code;
	if (codeORtype) {
		return code;
	}
	else {
		return Code2Type(code);
	}
}

string MyXml::Code2Type(string code)
{
	return Code_Vec_code2type[code];
	//for (int i = 1; i <= 90; i++)
	//{
	//	string str = "S" + to_string(i);
	//	if (Code_Vec_type2code[str] == Code_Cur)
	//	{
	//		return str;
	//	}
	//}
}

bool MyXml::circleLeastFit(const std::vector<pair<int, int>>& points, double& center_x, double& center_y, double& radius)
{
	center_x = 0.0f;
	center_y = 0.0f;
	radius = 0.0f;
	if (points.size() < 3)
	{
		return false;
	}

	double sum_x = 0.0f, sum_y = 0.0f;
	double sum_x2 = 0.0f, sum_y2 = 0.0f;
	double sum_x3 = 0.0f, sum_y3 = 0.0f;
	double sum_xy = 0.0f, sum_x1y2 = 0.0f, sum_x2y1 = 0.0f;

	int N = points.size();
	for (int i = 0; i < N; i++)
	{
		double x = points[i].first;
		double y = points[i].second;
		double x2 = x * x;
		double y2 = y * y;
		sum_x += x;
		sum_y += y;
		sum_x2 += x2;
		sum_y2 += y2;
		sum_x3 += x2 * x;
		sum_y3 += y2 * y;
		sum_xy += x * y;
		sum_x1y2 += x * y2;
		sum_x2y1 += x2 * y;
	}

	double C, D, E, G, H;
	double a, b, c;

	C = N * sum_x2 - sum_x * sum_x;
	D = N * sum_xy - sum_x * sum_y;
	E = N * sum_x3 + N * sum_x1y2 - (sum_x2 + sum_y2) * sum_x;
	G = N * sum_y2 - sum_y * sum_y;
	H = N * sum_x2y1 + N * sum_y3 - (sum_x2 + sum_y2) * sum_y;
	a = (H * D - E * G) / (C * G - D * D);
	b = (H * C - E * D) / (D * D - G * C);
	c = -(a * sum_x + b * sum_y + sum_x2 + sum_y2) / N;

	center_x = a / (-2);
	center_y = b / (-2);
	radius = sqrt(a * a + b * b - 4 * c) / 2;
	return true;
}

double MyXml::get_angle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	//double xie1 = atan2(y1 - y3, x1 - x3);
	//double xie2 = atan2(y2 - y3, x2 - x3);
	//(x3,y3)是相交点,从(x1,y1)->(x2,y2)
	double theta = atan2(y1 - y3, x1 - x3) - atan2(y2 - y3, x2 - x3);
	//double theta_f = atan2(y2 - y3, x2 - x3) - atan2(y1 - y3, x1 - x3);
	if (theta > M_PI)
		theta -= 2 * M_PI;
	if (theta < -M_PI)
		theta += 2 * M_PI;

	theta = theta * 180.0 / M_PI;
	return theta;
}