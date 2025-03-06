#pragma once
#include "HalconCpp.h"
using namespace HalconCpp;
#include <vector>
#include <unordered_map>

using namespace std;
class HalconWin
{
public:
	HalconWin();
	~HalconWin();
	//刷新窗口
	void refreshWindow();
	/************************************************
	*   名称：OpenWindow
	*   功能：打开一个Halcon窗口并绑定CWnd
	*	参数：
	pCWnd：窗口句柄数组

	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/
	void openWindow(CWnd * pCWnd);
	void closeWindow();
	/************************************************
	*   名称：DispObj
	*   功能：将拍到的图像或者HObject类型的图案，显示在绑定的窗口上
	*	参数：
	obj：显示的图像或者区域

	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/
	void dispObj(HObject& obj);
	void dispObj(vector<HObject>& objs);
	/************************************************
	*   名称：DispMessage
	*   功能：将字符串的显示在绑定的窗口上
	*	参数：
	cString：显示的字符串
	hv_CoordSystem： 系统，默认"window"
	hv_Row：字符串左上角的行坐标
	hv_Column：字符串左上角的列坐标
	hv_Color： 显示的颜色	"green", "red" ...
	hv_Box：  是否附加框框，  "true" , "false"
	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/

	void dispMessage(HTuple hv_String, HTuple hv_CoordSystem = "window",
		HTuple hv_Row = 10, HTuple hv_Column = 10, HTuple hv_Color = "blue", HTuple hv_Box = "false");


	/************************************************
	*   名称：SetColor
	*   功能：HALCON-》SetColor算子的接口
	*	参数：
	hv_Color： 显示的颜色	"green", "red" ...

	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/
	void setColor(CString cString);

	/************************************************
	*   名称：SetDraw
	*   功能：HALCON-》SetDraw算子的接口,显示区域填充还是边界
	*	参数：
	cString： 显示的颜色	"green", "red" ...

	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/
	void setDraw(CString cString);

	/************************************************
	*   名称：SetLineWidth
	*   功能：HALCON-》SetLineWidth算子的接口，设置线宽
	*	参数：
	hv_Width：  1,2,3...

	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/
	void setLineWidth(HTuple hv_Width);

	/************************************************
	*   名称：CString2HTuple
	*   功能：
	*	参数：
	cString：  输入CString类型字符串

	*	返回值：空
	* 	修改日期：2019年8月3日
	************************************************/

	HTuple CString2HTuple(CString cString);

	/*2023.1.5更新：瓶底检测绘制ROI*/
	//外边缘绘制
	void drawOuterRectangle1();
	void drawOuterCircle(int index);
	void drawOuterPolygon();
	//内边缘绘制
	void drawInnerRectangle1();
	void drawInnerCircle(int index);
	void drawInnerPolygon();
	//刷新窗口
	void refreshROIWindow();
	//删除上一个绘制区域
	void deleteLastRegion(int index);
	//保存绘制结果
	void saveROI();
	void getSourceImage(HObject& obj);
	void displayFinetunnedRegion();
	void displayROI(HObject& obj, int i);

private:
	//窗口句柄
	HTuple hv_WindowHandle;
	//当前图像比率
	//当前窗口所显示的内容（push_back对象是Image的之前会clear）
	vector<HObject> m_objs;
	//显示HObject对象
	void display(HObject& obj);

/***LZY***/
private:
	//保存图片的变量
	HObject ho_Image;

	//相机采图句柄
	HTuple hv_AcqHandle;

/*2023.1.5更新：瓶底检测绘制ROI*/
private:
	//ROI外边缘
	//vector<HObject> outer_region;
	unordered_map<int, vector<HObject>> outer_region;
	//ROI内边缘
	//vector<HObject> inner_region;
	unordered_map<int, vector<HObject>> inner_region;
	//上一次绘制区域类型标志位,外边缘为0，内边缘为1
	unordered_map<int, vector<int>> region_type;
	//区域序号
	vector<int> region_num;
	//调色板
	HTuple colors[10] = { "red", "green", "blue", "cyan", "magenta", "yellow", "medium slate blue", "coral", "slate blue", "spring green"};
};

