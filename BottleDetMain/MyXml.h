#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Markup.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;

using namespace std;

/************************************************
*   功能：读写配置文件，此类实负责XML文件的所有操作
*	日期：2022/10/21
************************************************/

class MyXml
{
public:
	MyXml();
	~MyXml();
	CMarkup xml;
	CString FileName;
	unordered_map<string, string> Code_Vec_type2code;
	unordered_map<string, string> Code_Vec_code2type;
	string Code_Cur;
public:
	/************************************************
	*   功能：string类型的字符串分离
	*	参数：
	*	返回值：
	************************************************/
	vector<string> split(const string& str, const string& pattern);

public:
	void OpenFile(CString filename);
	void CloseFile();

	/*-------------------------读取系统参数---------------------------
	系统参数：ProjectNums、 CameraList、 LightControlList、PreAlgList、
	DetAlgList、 OutPutList
	-----------------------------------------------------------------*/
public:
	CString rootName ;//根节点名称
	/************************************************
	*   功能：枚举所有子节点名称
	*	参数：父节点名称
	*	返回值：
	************************************************/
	vector<string> GetAllNodeName(string Father_name);



	/************************************************
	*   功能：读取一级节点内容
	*	参数：
	*	返回值：
	************************************************/
	string ReadNodeTxt(CString First_NodeName);

	/************************************************
	*   功能：读取二级节点内容
	*	参数：
	*	返回值：
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName);

	/************************************************
	*   功能：读取三级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName);

	/************************************************
	*   功能：读取四级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName);

	/************************************************
	*   功能：读取五级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	string ReadNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Five_NodeName);

	/************************************************
	*   功能：添加项目节点
	*	参数：项目名称
	*	返回值：
	************************************************/
	void AddProject(CString ProjectName);

	/************************************************
	*   功能：添加工位结点
	*	参数：项目父节点名称
	*	返回值：
	************************************************/
	void AddState(CString ProjectName);

	/************************************************
	*   功能：删除项目节点和节点下的所有内容
	*	参数：项目名称
	*	返回值：删除状态 0正常  -1项目不存在
	************************************************/
	int DeleteProjNode(CString ProjectName);

	/************************************************
	*   功能：写一级节点内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Write_Content);

	/************************************************
	*   功能：写二级节点内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Write_Content);

	/************************************************
	*   功能：写三级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Write_Content);

	/************************************************
	*   功能：写四级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Write_Content);

	/************************************************
	*   功能：写四级节点的内容
	*	参数：
	*	返回值：
	************************************************/
	void WriteNodeTxt(CString First_NodeName, CString Second_NodeName, CString Third_NodeName, CString Forth_NodeName, CString Five_NodeName, CString Write_Content);

	/************************************************
	*   功能：重写项目节点名称
	*	参数：重命名瓶子名称和相对应的检测参数节点名称
	*	返回值：
	************************************************/
	int RenameBottleName(CString src, CString dst);

	/************************************************
	*   功能：读取型号编码
	*	参数：
	*	返回值：
	************************************************/
	unordered_map<string, string> Read_Code(CString xml_path);

	/************************************************
	*   功能：坐标转编码
	*	参数：输入9个坐标
	*	返回值：
	************************************************/
	string Coordinate2Code(std::vector<pair<int, int>> points, bool codeORtype);

	/************************************************
	*   功能：编码转型号
	*	参数：
	*	返回值：
	************************************************/
	string Code2Type(string code);

	/************************************************
	*   功能：多点拟合圆
	*	参数：
	*	返回值：
	************************************************/
	bool circleLeastFit(const std::vector<pair<int, int>>& points, double& center_x, double& center_y, double& radius);

	/************************************************
	*   功能：求三点之间的夹角
	*	参数：
	*	返回值：
	************************************************/
	double get_angle(double x1, double y1, double x2, double y2, double x3, double y3);
};

