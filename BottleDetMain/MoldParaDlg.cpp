// MoldParaDlg.cpp: 实现文件
//

#include "pch.h"
#include "BottleDetMain.h"
#include "MoldParaDlg.h"
#include "afxdialogex.h"

//************************************不用***********************************//
// MoldParaDlg 对话框

IMPLEMENT_DYNAMIC(MoldParaDlg, CDialogEx)

//DWORD WINAPI CheckThreadMold(LPVOID pthread)
//{
//	MoldParaDlg* m_win = (MoldParaDlg*)pthread;
//	while (true)
//	{
//		WaitForSingleObject(m_win->CHECK_EVENT, INFINITE);
//		if (m_win->m_Exit) {
//			break;
//		}
//		m_win->CheckByAlgorithm();
//		ResetEvent(m_win->CHECK_EVENT);
//		Sleep(200);
//	}
//	return 0;
//}

MoldParaDlg::MoldParaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MOLD_PARAM_DIALOG, pParent)
{

}

MoldParaDlg::MoldParaDlg(CWnd* pParent, DataManager* pdata)
	: CDialogEx(IDD_MOLD_PARAM_DIALOG, pParent),
	m_pData(pdata)
{
	//CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	//hTestThreaedmold = CreateThread(NULL, 0, CheckThreadMold, this, 0, NULL);

}

MoldParaDlg::MoldParaDlg(CWnd* pParent, DataManager* pdata, Mat img)
	: CDialogEx(IDD_MOLD_PARAM_DIALOG, pParent),
	m_pData(pdata),
	Image(img)
{
	//CHECK_EVENT = CreateEventW(NULL, FALSE, FALSE, NULL);
	//hTestThreaedmold = CreateThread(NULL, 0, CheckThreadMold, this, 0, NULL);

}

MoldParaDlg::~MoldParaDlg()
{
	m_font->DeleteObject();

}

void MoldParaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MoldParaDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_MOLD_EXIT, &MoldParaDlg::OnBnClickedButMoldExit)
	ON_BN_CLICKED(IDC_BUT_SELECT, &MoldParaDlg::OnBnClickedButSelect)
	ON_BN_CLICKED(IDC_BUT_READ_MOLD_IMAGE, &MoldParaDlg::OnBnClickedButReadMoldImage)
	ON_BN_CLICKED(IDC_BUT_MOLD_RUN_TEST, &MoldParaDlg::OnBnClickedButMoldRunTest)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_BUT_MOLD_SAVE, &MoldParaDlg::OnBnClickedButMoldSave)
END_MESSAGE_MAP()


// MoldParaDlg 消息处理程序


void MoldParaDlg::InitControlColor(int ID, COLORREF rgb)
{
	CRect mrect;
	GetDlgItem(ID)->GetClientRect(&mrect);
	FillRect(GetDlgItem(ID)->GetDC()->GetSafeHdc(), &mrect, CBrush(rgb));
}

void MoldParaDlg::ShowAndTrans(Mat img)
{
	ShowImage(img);
	ho_Image = Mat2HObject(img);
	isImage = true;
	//需求：打开新图片时应当关闭旧窗口，清除内存并打开新窗口，显示画好的mask
	if (isHalconWinOpen)
	{
		m_HalconWin.closeWindow();
	}
	OpenHalconWin();
}

void MoldParaDlg::ShowImage(Mat& image)
{
	m_win.DispImage(image);
}

void MoldParaDlg::OpenHalconWin()
{
	CWnd* pwnd = GetDlgItem(IDC_MOLD_IMAGE);
	m_HalconWin.openWindow(pwnd);
	m_HalconWin.dispObj(ho_Image);
	m_HalconWin.getSourceImage(ho_Image);
	//增加：初始化窗口时读取mask并显示
	//HObject ho_SingleMaskImage, ho_Mask, ho_ROI, ho_EmptyRegion, ho_RegionIntersection;
	//HObject  ho_Background;
	//vector<HObject> ho_MaskImage;
	//ReadImage(&ho_SingleMaskImage, ".\\mask0.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask1.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask2.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//ReadImage(&ho_SingleMaskImage, ".\\mask3.bmp");
	//ho_MaskImage.push_back(ho_SingleMaskImage);
	//for (int i = 0; i < 4; i++)
	//{
	//	Rgb1ToGray(ho_MaskImage[i], &ho_Mask);
	//	Threshold(ho_Mask, &ho_ROI, 128, 255);
	//	GenEmptyRegion(&ho_EmptyRegion);
	//	if (0 != (ho_ROI == ho_EmptyRegion))
	//	{
	//		continue;
	//	}
	//	m_HalconWin.displayROI(ho_ROI, i);
	//}
	m_HalconWin.refreshROIWindow();
	isHalconWinOpen = true;

}

HObject MoldParaDlg::Mat2HObject(cv::Mat& cv_img)
{
	HalconCpp::HObject H_img;

	if (cv_img.channels() == 1)
	{
		int height = cv_img.rows, width = cv_img.cols;
		int size = height * width;
		uchar* temp = new uchar[size];

		memcpy(temp, cv_img.data, size);
		HalconCpp::GenImage1(&H_img, "byte", width, height, (Hlong)(temp));

		delete[] temp;
	}
	else if (cv_img.channels() == 3)
	{
		int height = cv_img.rows, width = cv_img.cols;
		int size = height * width;
		uchar* B = new uchar[size];
		uchar* G = new uchar[size];
		uchar* R = new uchar[size];

		for (int i = 0; i < height; i++)
		{
			uchar* p = cv_img.ptr<uchar>(i);
			for (int j = 0; j < width; j++)
			{
				B[i * width + j] = p[3 * j];
				G[i * width + j] = p[3 * j + 1];
				R[i * width + j] = p[3 * j + 2];
			}
		}
		HalconCpp::GenImage3(&H_img, "byte", width, height, (Hlong)(R), (Hlong)(G), (Hlong)(B));

		delete[] R;
		delete[] G;
		delete[] B;
	}
	return H_img;
}

void MoldParaDlg::ShowCheckResult(Mat image, string detect_ID)
{
	Mat show_image;
	if (image.channels() != 3)
	{
		show_image = Trans2RGB(image);
	}
	else
	{
		show_image = image.clone();
	}
	if (m_pData->GetBottleDetParam()->MoldRecognition == "MOLDON") {
		//putText(show_image, m_pData->GetSystemParam()->TargetID, Point(700, 50), FONT_HERSHEY_SIMPLEX, 2, Scalar(0, 0, 255), 3, 3);
		putText(show_image, m_pData->GetBottleDetParam()->SelectedMold, Point(700, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
		vector<int> TargetID = Str2Vec(m_pData->GetBottleDetParam()->SelectedMold);
		int detect_id = str2int(detect_ID);
		if (find(TargetID.begin(), TargetID.end(), detect_id) != TargetID.end())
		{
			putText(show_image, detect_ID, Point(700, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 3, 3);
		}
		else
		{
			putText(show_image, detect_ID, Point(700, 120), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 3, 3);
		}
	}

	m_win.ClearWindow();
	m_win.DispImage(show_image);

}

Mat MoldParaDlg::Trans2RGB(Mat& image)
{
	cv::Mat three_channel = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);
	vector<cv::Mat> channels;
	for (int i = 0; i < 3; i++)
	{
		channels.push_back(image);
	}
	merge(channels, three_channel);
	return three_channel;
}

vector<int> MoldParaDlg::Str2Vec(string str)
{
	int start = 0;
	int num = 0;
	vector<int> nums;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			string temp = str.substr(start, i - start);
			nums.push_back(atoi(temp.c_str()));
			num++;
			start = i + 1;
		}
	}
	string temp = str.substr(start, str.size() - start + 1);
	nums.push_back(atoi(temp.c_str()));
	return nums;
}

int MoldParaDlg::str2int(string str)
{
	stringstream stream;     //声明一个stringstream变量
	int n;
	//string转int
	stream << str;     //向stream中插入字符串
	stream >> n;
	return n;
}

void MoldParaDlg::DownLoadParam()
{
}

void MoldParaDlg::UpLoadParam()
{
}

void MoldParaDlg::InitWindowFront()
{
	LOGFONT lfCtrl = { 0 };
	lfCtrl.lfOrientation = 0;
	lfCtrl.lfEscapement = 2;
	lfCtrl.lfHeight = 14;
	lfCtrl.lfItalic = false;
	lfCtrl.lfUnderline = false;
	lfCtrl.lfStrikeOut = false;
	lfCtrl.lfCharSet = DEFAULT_CHARSET;
	lfCtrl.lfQuality = DEFAULT_QUALITY;
	lfCtrl.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lfCtrl.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lfCtrl.lfFaceName, L"新宋体");
	lfCtrl.lfWeight = FW_HEAVY;
	m_font->CreateFontIndirectW(&lfCtrl);

	GetDlgItem(IDC_LEFT_VAL)->SetFont(m_font);
	GetDlgItem(IDC_RIGHT_VAL)->SetFont(m_font);
	GetDlgItem(IDC_BUT_SELECT)->SetFont(m_font);
	GetDlgItem(IDC_BUT_MOLD_SAVE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_READ_MOLD_IMAGE)->SetFont(m_font);
	GetDlgItem(IDC_BUT_MOLD_RUN_TEST)->SetFont(m_font);
	GetDlgItem(IDC_BUT_MOLD_EXIT)->SetFont(m_font);

}

void MoldParaDlg::CheckByAlgorithm()
{
	isChecking = true;
	string bottle_type = "0";
	vector<cv::Rect> mrect;
	if (mrect.size() == 9) {
		vector<pair<int, int>> points;
		for (cv::Rect& i : mrect) {
			points.push_back(pair<int, int>(i.x, i.y));
		}
		string bottle_type_temp = bottle_xml.Coordinate2Code(points, false);
		bottle_type_temp.erase(bottle_type_temp.begin());
		bottle_type = bottle_type_temp;
		//bottle_type = sub(bottle_type_temp, "S");
	}

	string detect_ID;
	ShowCheckResult(Image, detect_ID);
	isChecking = false;

}

void MoldParaDlg::OnBnClickedButMoldExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void MoldParaDlg::OnBnClickedButSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	MoldSelectDlg Dlg(this, m_pData);
	Dlg.DoModal();
}


void MoldParaDlg::OnBnClickedButReadMoldImage()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("image files(*.jpg)|*.jpg;*.png;*.bmp|Worksheet Files|*.xls|All Files(*.*)|*.*||"),
		NULL);                            // 构造文件打开对话框  
	dlg.m_ofn.lpstrTitle = _T("添加图片");  // 文件打开对话框标题  
	if (IDOK != dlg.DoModal())                 // 判断是否成功选中文件  
		return;
	Image_path = dlg.GetPathName();         // 获取文件路径
	SetDlgItemText(IDC_IMAGE_PATH_BOX, Image_path);
	USES_CONVERSION;
	Image = imread(W2A(Image_path), 0);
	ShowAndTrans(Image);

}


void MoldParaDlg::OnBnClickedButMoldRunTest()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!isChecking && isImage) {
		if (isHalconWinOpen)
		{
			m_HalconWin.closeWindow();
			isHalconWinOpen = false;
		}
		//SetEvent(CHECK_EVENT);
		CheckByAlgorithm();
	}

}


BOOL MoldParaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_win.OpenWindow(GetDlgItem(IDC_MOLD_IMAGE));
	DownLoadParam();

	m_font = new CFont();
	InitWindowFront();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH MoldParaDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void MoldParaDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	//				   // TODO: 在此处添加消息处理程序代码
	//				   // 不为绘图消息调用 CDialogEx::OnPaint()
	//	//绘制背景
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	//dc.FillSolidRect(rect, RGB(157, 172, 253));
	InitControlColor(IDC_MOLD_IMAGE, RGB(0, 0, 0));

}


void MoldParaDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void MoldParaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nID == SC_MOVE || nID == 0xF012) {
		return;
	}
	else {
		CDialogEx::OnSysCommand(nID, lParam);
	}

	//CDialogEx::OnSysCommand(nID, lParam);
}


void MoldParaDlg::OnBnClickedButMoldSave()
{
	// TODO: 在此添加控件通知处理程序代码
	UpLoadParam();
}
