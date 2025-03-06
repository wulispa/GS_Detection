#include "pch.h"
#include "HalconWin.h"


HalconWin::HalconWin()
{
}


HalconWin::~HalconWin()
{
}
void HalconWin::openWindow(CWnd * pCWnd)
{	//定义显示的起点和长宽高      
	HTuple HWindowRow, HWindowColumn, HWindowWidth, HWindowHeight;
	//定义窗口ID     
	HTuple HWindowID;
	CRect rect;
	pCWnd->GetClientRect(&rect);
	HWindowRow = rect.top;
	HWindowColumn = rect.left;
	HWindowWidth = rect.Width();
	HWindowHeight = rect.Height();
	HWindowID = (Hlong)pCWnd->m_hWnd;
	//SetWindowAttr("background_color", "white");
	SetCheck("~father");
	HalconCpp::OpenWindow(HWindowRow, HWindowColumn, HWindowWidth, HWindowHeight, HWindowID, "visible", "", &hv_WindowHandle);
	SetCheck("father");
	setDraw(L"margin");
}

void HalconWin::closeWindow()
{
	ClearWindow(hv_WindowHandle);
	m_objs.clear();
	region_num.clear();
	//瓶底检测清空ROI
	unordered_map<int, vector<HObject>>().swap(outer_region);
	unordered_map<int, vector<HObject>>().swap(inner_region);
	unordered_map<int, vector<int>>().swap(region_type);
	//outer_region.clear();
	//inner_region.clear();
	//region_type.clear();
	CloseWindow(hv_WindowHandle);
}

void HalconWin::dispObj(HObject& obj)
{
	
	HTuple hv_cls;
	GetObjClass(obj, &hv_cls);
	CString cstr(L"image");
	//如果obj是image类型，清空m_objs
	if (hv_cls.S().operator==(cstr))
	{
		m_objs.clear();
	}

	display(obj);
	m_objs.push_back(obj);
}


void HalconWin::dispObj(vector<HObject>& objs)
{

	int len = (int)objs.size();
	for (int i = 0; i < len; i++)
	{

		HTuple hv_cls;
		GetObjClass(objs.at(i), &hv_cls);
		CString cstr(L"image");
		//如果obj是image类型，清空m_objs
		if (hv_cls.S().operator==(cstr))
		{
			m_objs.clear();
		}
		display(objs.at(i));
		m_objs.push_back(objs.at(i));

	}
}

HTuple HalconWin::CString2HTuple(CString cString)
{
	//CString转换为HTuple
	USES_CONVERSION;
	HTuple hv_String = T2A(cString.GetBuffer(0));
	cString.ReleaseBuffer();
	return hv_String;
}


void  HalconWin::dispMessage(HTuple hv_String, HTuple hv_CoordSystem,
	HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box)
{



	// Local control variables
	HTuple  hv_Red, hv_Green, hv_Blue, hv_Row1Part;
	HTuple  hv_Column1Part, hv_Row2Part, hv_Column2Part, hv_RowWin;
	HTuple  hv_ColumnWin, hv_WidthWin, hv_HeightWin, hv_MaxAscent;
	HTuple  hv_MaxDescent, hv_MaxWidth, hv_MaxHeight, hv_R1;
	HTuple  hv_C1, hv_FactorRow, hv_FactorColumn, hv_UseShadow;
	HTuple  hv_ShadowColor, hv_Exception, hv_Width, hv_Index;
	HTuple  hv_Ascent, hv_Descent, hv_W, hv_H, hv_FrameHeight;
	HTuple  hv_FrameWidth, hv_R2, hv_C2, hv_DrawMode, hv_CurrentColor;

	//This procedure displays text in a graphics window.
	//
	//Input parameters:
	//WindowHandle: The WindowHandle of the graphics window, where
	//   the message should be displayed
	//String: A tuple of strings containing the text message to be displayed
	//CoordSystem: If set to 'window', the text position is given
	//   with respect to the window coordinate system.
	//   If set to 'image', image coordinates are used.
	//   (This may be useful in zoomed images.)
	//Row: The row coordinate of the desired text position
	//   If set to -1, a default value of 12 is used.
	//Column: The column coordinate of the desired text position
	//   If set to -1, a default value of 12 is used.
	//Color: defines the color of the text as string.
	//   If set to [], '' or 'auto' the currently set color is used.
	//   If a tuple of strings is passed, the colors are used cyclically
	//   for each new textline.
	//Box: If Box[0] is set to 'true', the text is written within an orange box.
	//     If set to' false', no box is displayed.
	//     If set to a color string (e.g. 'white', '#FF00CC', etc.),
	//       the text is written in a box of that color.
	//     An optional second value for Box (Box[1]) controls if a shadow is displayed:
	//       'true' -> display a shadow in a default color
	//       'false' -> display no shadow (same as if no second value is given)
	//       otherwise -> use given string as color string for the shadow color
	//
	//Prepare window
	GetRgb(hv_WindowHandle, &hv_Red, &hv_Green, &hv_Blue);
	GetPart(hv_WindowHandle, &hv_Row1Part, &hv_Column1Part, &hv_Row2Part, &hv_Column2Part);
	GetWindowExtents(hv_WindowHandle, &hv_RowWin, &hv_ColumnWin, &hv_WidthWin, &hv_HeightWin);
	SetPart(hv_WindowHandle, 0, 0, hv_HeightWin - 1, hv_WidthWin - 1);
	//
	//default settings
	if (0 != (hv_Row == -1))
	{
		hv_Row = 12;
	}
	if (0 != (hv_Column == -1))
	{
		hv_Column = 12;
	}
	if (0 != (hv_Color == HTuple()))
	{
		hv_Color = "";
	}
	//
	hv_String = (("" + hv_String) + "").TupleSplit("\n");
	//
	//Estimate extentions of text depending on font size.
	GetFontExtents(hv_WindowHandle, &hv_MaxAscent, &hv_MaxDescent, &hv_MaxWidth, &hv_MaxHeight);
	if (0 != (hv_CoordSystem == HTuple("window")))
	{
		hv_R1 = hv_Row;
		hv_C1 = hv_Column;
	}
	else
	{
		//Transform image to window coordinates
		hv_FactorRow = (1.*hv_HeightWin) / ((hv_Row2Part - hv_Row1Part) + 1);
		hv_FactorColumn = (1.*hv_WidthWin) / ((hv_Column2Part - hv_Column1Part) + 1);
		hv_R1 = ((hv_Row - hv_Row1Part) + 0.5)*hv_FactorRow;
		hv_C1 = ((hv_Column - hv_Column1Part) + 0.5)*hv_FactorColumn;
	}
	//
	//Display text box depending on text size
	hv_UseShadow = 1;
	hv_ShadowColor = "gray";
	if (0 != (HTuple(hv_Box[0]) == HTuple("true")))
	{
		hv_Box[0] = "#fce9d4";
		hv_ShadowColor = "#f28d26";
	}
	if (0 != ((hv_Box.TupleLength())>1))
	{
		if (0 != (HTuple(hv_Box[1]) == HTuple("true")))
		{
			//Use default ShadowColor set above
		}
		else if (0 != (HTuple(hv_Box[1]) == HTuple("false")))
		{
			hv_UseShadow = 0;
		}
		else
		{
			hv_ShadowColor = ((const HTuple&)hv_Box)[1];
			//Valid color?
			try
			{
				SetColor(hv_WindowHandle, HTuple(hv_Box[1]));
			}
			// catch (Exception) 
			catch (HalconCpp::HException &HDevExpDefaultException)
			{
				HDevExpDefaultException.ToHTuple(&hv_Exception);
				hv_Exception = "Wrong value of control parameter Box[1] (must be a 'true', 'false', or a valid color string)";
				throw HalconCpp::HException(hv_Exception);
			}
		}
	}
	if (0 != (HTuple(hv_Box[0]) != HTuple("false")))
	{
		//Valid color?
		try
		{
			SetColor(hv_WindowHandle, HTuple(hv_Box[0]));
		}
		// catch (Exception) 
		catch (HalconCpp::HException &HDevExpDefaultException)
		{
			HDevExpDefaultException.ToHTuple(&hv_Exception);
			hv_Exception = "Wrong value of control parameter Box[0] (must be a 'true', 'false', or a valid color string)";
			throw HalconCpp::HException(hv_Exception);
		}
		//Calculate box extents
		hv_String = (" " + hv_String) + " ";
		hv_Width = HTuple();
		{
			HTuple end_val93 = (hv_String.TupleLength()) - 1;
			HTuple step_val93 = 1;
			for (hv_Index = 0; hv_Index.Continue(end_val93, step_val93); hv_Index += step_val93)
			{
				GetStringExtents(hv_WindowHandle, HTuple(hv_String[hv_Index]), &hv_Ascent,
					&hv_Descent, &hv_W, &hv_H);
				hv_Width = hv_Width.TupleConcat(hv_W);
			}
		}
		hv_FrameHeight = hv_MaxHeight*(hv_String.TupleLength());
		hv_FrameWidth = (HTuple(0).TupleConcat(hv_Width)).TupleMax();
		hv_R2 = hv_R1 + hv_FrameHeight;
		hv_C2 = hv_C1 + hv_FrameWidth;
		//Display rectangles
		GetDraw(hv_WindowHandle, &hv_DrawMode);
		SetDraw(hv_WindowHandle, "fill");
		//Set shadow color
		SetColor(hv_WindowHandle, hv_ShadowColor);
		if (0 != hv_UseShadow)
		{
			DispRectangle1(hv_WindowHandle, hv_R1 + 1, hv_C1 + 1, hv_R2 + 1, hv_C2 + 1);
		}
		//Set box color
		SetColor(hv_WindowHandle, HTuple(hv_Box[0]));
		DispRectangle1(hv_WindowHandle, hv_R1, hv_C1, hv_R2, hv_C2);
		SetDraw(hv_WindowHandle, hv_DrawMode);
	}
	//Write text.
	{
		HTuple end_val115 = (hv_String.TupleLength()) - 1;
		HTuple step_val115 = 1;
		for (hv_Index = 0; hv_Index.Continue(end_val115, step_val115); hv_Index += step_val115)
		{
			hv_CurrentColor = ((const HTuple&)hv_Color)[hv_Index % (hv_Color.TupleLength())];
			if (0 != (HTuple(hv_CurrentColor != HTuple("")).TupleAnd(hv_CurrentColor != HTuple("auto"))))
			{
				SetColor(hv_WindowHandle, hv_CurrentColor);
			}
			else
			{
				SetRgb(hv_WindowHandle, hv_Red, hv_Green, hv_Blue);
			}
			hv_Row = hv_R1 + (hv_MaxHeight*hv_Index);
			SetTposition(hv_WindowHandle, hv_Row, hv_C1);
			WriteString(hv_WindowHandle, HTuple(hv_String[hv_Index]));
		}
	}
	//Reset changed window settings
	SetRgb(hv_WindowHandle, hv_Red, hv_Green, hv_Blue);
	SetPart(hv_WindowHandle, hv_Row1Part, hv_Column1Part, hv_Row2Part, hv_Column2Part);
	return;
}





void HalconWin::setColor(CString cString)
{
	//CString转换为HTuple
	HTuple hv_String = CString2HTuple(cString);
	HalconCpp::SetColor(hv_WindowHandle, hv_String);
}

void HalconWin::setDraw(CString cString)
{
	//CString转换为HTuple
	HTuple hv_String = CString2HTuple(cString);
	HalconCpp::SetDraw(hv_WindowHandle, hv_String);
}


void HalconWin::setLineWidth(HTuple hv_Width)
{
	HalconCpp::SetLineWidth(hv_WindowHandle, hv_Width);
}


void HalconWin::refreshWindow()
{
	HalconCpp::ClearWindow(hv_WindowHandle);
	int len = (int)m_objs.size();
	for (int i = 0; i < len; i++)
	{
		display(m_objs.at(i));
	}
}

//private:
void HalconWin::display(HObject& obj)
{


	try {
		HTuple hv_cls;
		HTuple  hv_Row, hv_Column, hv_Width1;
		HTuple  hv_Height1, hv_Width, hv_Height, hv_win_rate, hv_img_rate;
		HTuple  hv_imgPart_Width, hv_imgPart_Height;
		GetObjClass(obj, &hv_cls);
		CString cstr(L"image");
		if (hv_cls.S().operator==(cstr))
		{
			HTuple width, height;
			GetImageSize(obj, &width, &height);
			//旋转180度
			//RotateImage(ho_Image, &ho_Image, 0, "constant");
			//镜像
			//MirrorImage(ho_Image, &ho_Image, "row");
			//自适应图片大小显示
			GetWindowExtents(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Width1, &hv_Height1);
			GetImageSize(obj, &hv_Width, &hv_Height);
			hv_win_rate = (hv_Width1.TupleReal()) / (hv_Height1.TupleReal());
			hv_img_rate = (hv_Width.TupleReal()) / (hv_Height.TupleReal());
			if (0 != (hv_win_rate < hv_img_rate))
			{
				hv_imgPart_Width = hv_Width;
				hv_imgPart_Height = (hv_Width * hv_Height1) / hv_Width1;
			}
			else
			{
				hv_imgPart_Width = (hv_Height * hv_Width1) / hv_Height1;
				hv_imgPart_Height = hv_Height;
			}
			SetPart(hv_WindowHandle, 0, 0, hv_imgPart_Height, hv_imgPart_Width);
			//SetPart(hv_WindowHandle, 0, 0, height - 1, width - 1);
			HalconCpp::DispObj(obj, hv_WindowHandle);
		}
		else {
			HalconCpp::DispObj(obj, hv_WindowHandle);
		}
	}
	catch (...)
	{
	}


}

/*2023.1.5更新：瓶底检测绘制ROI*/
void HalconWin::drawOuterRectangle1()
{
	//HTuple  hv_Row1, hv_Column1, hv_Row2, hv_Column2, hv_Area;
	//HObject  ho_Rectangle;
	//SetColor(hv_WindowHandle, "red");
	//DrawRectangle1(hv_WindowHandle, &hv_Row1, &hv_Column1, &hv_Row2, &hv_Column2);
	//GenRectangle1(&ho_Rectangle, hv_Row1, hv_Column1, hv_Row2, hv_Column2);
	//dispObj(ho_Rectangle);
	//outer_region.push_back(ho_Rectangle);
	//region_type.push_back(0);
}

void HalconWin::drawOuterCircle(int index)
{
	HTuple  hv_Column, hv_Row3, hv_Column3, hv_Radius;
	HObject  ho_Circle;
	SetColor(hv_WindowHandle, colors[index]);
	DrawCircle(hv_WindowHandle, &hv_Row3, &hv_Column3, &hv_Radius);
	GenCircle(&ho_Circle, hv_Row3, hv_Column3, hv_Radius);
	dispObj(ho_Circle);
	outer_region[index].push_back(ho_Circle);
	region_type[index].push_back(0);
	region_num.push_back(index);
}

void HalconWin::drawOuterPolygon()
{
	//HObject  ho_PolygonRegion, ho_RegionFillUp;
	//SetColor(hv_WindowHandle, "red");
	//DrawPolygon(&ho_PolygonRegion, hv_WindowHandle);
	//FillUp(ho_PolygonRegion, &ho_RegionFillUp);
	//dispObj(ho_RegionFillUp);
	//outer_region.push_back(ho_RegionFillUp);
	//region_type.push_back(0);
}

void HalconWin::drawInnerRectangle1()
{
	//HTuple  hv_Row1, hv_Column1, hv_Row2, hv_Column2, hv_Area;
	//HObject  ho_Rectangle;
	//SetColor(hv_WindowHandle, "blue");
	//DrawRectangle1(hv_WindowHandle, &hv_Row1, &hv_Column1, &hv_Row2, &hv_Column2);
	//GenRectangle1(&ho_Rectangle, hv_Row1, hv_Column1, hv_Row2, hv_Column2);
	//dispObj(ho_Rectangle);
	//inner_region.push_back(ho_Rectangle);
	//region_type.push_back(1);
}

void HalconWin::drawInnerCircle(int index)
{
	HTuple  hv_Column, hv_Row3, hv_Column3, hv_Radius;
	HObject  ho_Circle;
	SetColor(hv_WindowHandle, colors[index]);
	DrawCircle(hv_WindowHandle, &hv_Row3, &hv_Column3, &hv_Radius);
	GenCircle(&ho_Circle, hv_Row3, hv_Column3, hv_Radius);
	dispObj(ho_Circle);
	inner_region[index].push_back(ho_Circle);
	region_type[index].push_back(1);
	region_num.push_back(index);
}

void HalconWin::drawInnerPolygon()
{
	//HObject  ho_PolygonRegion, ho_RegionFillUp;
	//SetColor(hv_WindowHandle, "blue");
	//DrawPolygon(&ho_PolygonRegion, hv_WindowHandle);
	//FillUp(ho_PolygonRegion, &ho_RegionFillUp);
	//dispObj(ho_RegionFillUp);
	//inner_region.push_back(ho_RegionFillUp);
	//region_type.push_back(1);
}

void HalconWin::refreshROIWindow()
{
	HalconCpp::ClearWindow(hv_WindowHandle);
	int len = (int)m_objs.size();
	for (int i = 0; i < len; i++)
	{
		HTuple hv_cls;
		GetObjClass(m_objs.at(i), &hv_cls);
		CString cstr(L"image");
		if (hv_cls.S().operator==(cstr))
		{
			display(m_objs.at(i));
		}
		else
		{
			SetColor(hv_WindowHandle, colors[region_num[i-1]]);
			display(m_objs.at(i));
		}
	}
}

void HalconWin::deleteLastRegion(int index)
{
	//if (region_type.size() > 0)
	//{
	//	while (region_type.size() > 0)
	//	{
	//		if (region_type.back() == 0)
	//		{
	//			outer_region.pop_back();
	//			region_type.pop_back();
	//			break;
	//		}
	//		if (region_type.back() == 1)
	//		{
	//			inner_region.pop_back();
	//			region_type.pop_back();
	//			break;
	//		}
	//	}
	//	HTuple hv_cls;
	//	GetObjClass(m_objs.back(), &hv_cls);
	//	CString cstr(L"image");
	//	if (hv_cls.S() != cstr)
	//	{
	//		m_objs.pop_back();
	//		region_num.pop_back();
	//	}
	//	refreshROIWindow();
	//}
	//else
	//{
	//待补充：删除单个mask可视化
	outer_region[index].clear();
	inner_region[index].clear();
	region_type[index].clear();
	int flag = 1;
	while (flag == 1)
	{
		flag = 0;
		int len = (int)m_objs.size();
		for (int i = 1; i < len; i++)
		{
			if (region_num[i - 1] == index)
			{
				m_objs.erase(m_objs.begin() + i);
				region_num.erase(region_num.begin() + i - 1);
				flag = 1;
				break;
			}
		}
	}
	refreshROIWindow();
	HObject  ho_Blank_Image, ho_MultiChannelImage;
	GenImageConst(&ho_Blank_Image, "byte", 768, 768);
	Compose3(ho_Blank_Image, ho_Blank_Image, ho_Blank_Image, &ho_MultiChannelImage);
	if (index == 0) {
		WriteImage(ho_MultiChannelImage, "bmp", 0, ".\\mask0");
	}
	if (index == 1) {
		WriteImage(ho_MultiChannelImage, "bmp", 0, ".\\mask1");
	}
	if (index == 2) {
		WriteImage(ho_MultiChannelImage, "bmp", 0, ".\\mask2");
	}
	if (index == 3) {
		WriteImage(ho_MultiChannelImage, "bmp", 0, ".\\mask3");
	}
	//}
}

void HalconWin::saveROI()
{
	for (int index = 0; index < 4; index++) 
	{
		if (region_type[index].size() == 0)
		{
			continue;
		}
		HTuple  hv_Width, hv_Height;
		HTuple  hv_Rows, hv_Columns, hv_Newtuple;
		HObject  ho_ObjectsConcatOuter, ho_RegionUnionOuter, ho_ObjectsConcatInner, ho_RegionUnionInner, ho_RegionDifference;
		HObject  ho_Mask;
		GetImageSize(m_objs.at(0), &hv_Width, &hv_Height);
		GenEmptyObj(&ho_ObjectsConcatOuter);
		int len = (int)outer_region[index].size();
		int len1 = (int)inner_region[index].size();
		if (len == 0 && len1 > 0)
		{
			continue;
		}
		if (len > 0)
		{
			for (int i = 0; i < len; i++)
			{
				ConcatObj(ho_ObjectsConcatOuter, outer_region[index].at(i), &ho_ObjectsConcatOuter);
			}
		}
		Union1(ho_ObjectsConcatOuter, &ho_RegionUnionOuter);
		GenEmptyObj(&ho_ObjectsConcatInner);
		if (len1 > 0)
		{
			for (int i = 0; i < len1; i++)
			{
				ConcatObj(ho_ObjectsConcatInner, inner_region[index].at(i), &ho_ObjectsConcatInner);
			}
		}
		Union1(ho_ObjectsConcatInner, &ho_RegionUnionInner);

		Difference(ho_RegionUnionOuter, ho_RegionUnionInner, &ho_RegionDifference);
		HTuple  hv_Area, hv_Row, hv_Column;

		AreaCenter(ho_RegionDifference, &hv_Area, &hv_Row, &hv_Column);
		if (0 != (hv_Area > 0)) {
			GetRegionPoints(ho_RegionDifference, &hv_Rows, &hv_Columns);
			GenImageConst(&ho_Mask, "byte", hv_Width + 200, hv_Height + 500);
			Rgb1ToGray(ho_Mask, &ho_Mask);
			TupleGenConst(hv_Rows.TupleLength(), 255, &hv_Newtuple);
			SetGrayval(ho_Mask, hv_Rows, hv_Columns, hv_Newtuple);
		}
		else {
			GenImageConst(&ho_Mask, "byte", hv_Width + 200, hv_Height + 500);
			Rgb1ToGray(ho_Mask, &ho_Mask);
		}
		if (index == 0) {
			WriteImage(ho_Mask, "bmp", 0, ".\\mask0");
		}
		if (index == 1) {
			WriteImage(ho_Mask, "bmp", 0, ".\\mask1");
		}
		if (index == 2) {
			WriteImage(ho_Mask, "bmp", 0, ".\\mask2");
		}
		if (index == 3) {
			WriteImage(ho_Mask, "bmp", 0, ".\\mask3");
		}
	}
	//region_type.clear();
	//outer_region.clear();
	//inner_region.clear();
}

void HalconWin::getSourceImage(HObject& obj)
{
	ho_Image = obj;
}

void HalconWin::displayFinetunnedRegion()
{
	HObject  ho_Region, ho_RegionFillUp, ho_RegionClosing, ho_RegionTrans;
	HObject ho_SingleMaskImage, ho_Mask, ho_ROI, ho_EmptyRegion, ho_RegionIntersection;
	HObject  ho_Background;
	vector<HObject> ho_MaskImage;
	HTuple  hv_UsedThreshold;
	HTuple  hv_Rows, hv_Columns, hv_Newtuple;
	HTuple  hv_Width, hv_Height;

	GetImageSize(ho_Image, &hv_Width, &hv_Height);
	ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	ho_MaskImage.push_back(ho_SingleMaskImage);
	BinaryThreshold(ho_Image, &ho_Region, "max_separability", "light", &hv_UsedThreshold);
	//FillUp(ho_Region, &ho_RegionFillUp);
	//ClosingCircle(ho_RegionFillUp, &ho_RegionClosing, 100);
	FillUpShape(ho_Region, &ho_RegionFillUp, "area", 1, 1000);
	ClosingCircle(ho_RegionFillUp, &ho_RegionClosing, 50);
	ErosionCircle(ho_RegionClosing, &ho_RegionClosing, 15);
	//ShapeTrans(ho_RegionClosing, &ho_RegionTrans, "rectangle1");
	for (int i = 0; i < 4; i++)
	{
		Rgb1ToGray(ho_MaskImage[i], &ho_Mask);
		Threshold(ho_Mask, &ho_ROI, 128, 255);
		GenEmptyRegion(&ho_EmptyRegion);
		if (0 != (ho_RegionClosing == ho_EmptyRegion))
		{
			continue;
		}
		if (0 != (ho_ROI == ho_EmptyRegion))
		{
			continue;
		}
		Intersection(ho_ROI, ho_RegionClosing, &ho_RegionIntersection);
		outer_region[i].clear();
		inner_region[i].clear();
		region_type[i].clear();
		int flag = 1;
		while (flag == 1)
		{
			flag = 0;
			int len = (int)m_objs.size();
			for (int j = 1; j < len; j++)
			{
				if (region_num[j - 1] == i)
				{
					m_objs.erase(m_objs.begin() + j);
					region_num.erase(region_num.begin() + j - 1);
					flag = 1;
					break;
				}
			}
		}
		m_objs.push_back(ho_RegionIntersection);
		region_num.push_back(i);

		GetRegionPoints(ho_RegionIntersection, &hv_Rows, &hv_Columns);
		GenImageConst(&ho_Background, "byte", hv_Width, hv_Height);
		Rgb1ToGray(ho_Background, &ho_Background);
		TupleGenConst(hv_Rows.TupleLength(), 255, &hv_Newtuple);
		SetGrayval(ho_Background, hv_Rows, hv_Columns, hv_Newtuple);
		if (i == 0) {
			WriteImage(ho_Background, "bmp", 0, ".\\mask0");
		}
		if (i == 1) {
			WriteImage(ho_Background, "bmp", 0, ".\\mask1");
		}
		if (i == 2) {
			WriteImage(ho_Background, "bmp", 0, ".\\mask2");
		}
		if (i == 3) {
			WriteImage(ho_Background, "bmp", 0, ".\\mask3");
		}
	}
	refreshROIWindow();
}

void HalconWin::displayROI(HObject& obj, int i)
{
	m_objs.push_back(obj);
	region_num.push_back(i);
}
