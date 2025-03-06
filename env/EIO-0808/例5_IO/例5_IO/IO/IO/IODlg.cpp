
// IODlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IO.h"
#include "IODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CIODlg �Ի���




CIODlg::CIODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIODlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CIODlg ��Ϣ�������

BOOL CIODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    ::SetTimer(this->m_hWnd,0,200,NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CIODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CIODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIODlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		CString string;
	DWORD dvalue = 0;
	int i = 0;
	double position = 0;
	int iret = 0;

	CStatic *Static_IN[32]= {(CStatic *)GetDlgItem(IDC_STATIC_IN0),(CStatic *)GetDlgItem(IDC_STATIC_IN1),(CStatic *)GetDlgItem(IDC_STATIC_IN2),(CStatic *)GetDlgItem(IDC_STATIC_IN3),(CStatic *)GetDlgItem(IDC_STATIC_IN4),
		(CStatic *)GetDlgItem(IDC_STATIC_IN5),(CStatic *)GetDlgItem(IDC_STATIC_IN6),(CStatic *)GetDlgItem(IDC_STATIC_IN7),(CStatic *)GetDlgItem(IDC_STATIC_IN8),(CStatic *)GetDlgItem(IDC_STATIC_IN9),(CStatic *)GetDlgItem(IDC_STATIC_IN10),
		(CStatic *)GetDlgItem(IDC_STATIC_IN11),(CStatic *)GetDlgItem(IDC_STATIC_IN12),(CStatic *)GetDlgItem(IDC_STATIC_IN13),(CStatic *)GetDlgItem(IDC_STATIC_IN14),(CStatic *)GetDlgItem(IDC_STATIC_IN15),
	    (CStatic *)GetDlgItem(IDC_STATIC_IN16),(CStatic *)GetDlgItem(IDC_STATIC_IN17),(CStatic *)GetDlgItem(IDC_STATIC_IN18),(CStatic *)GetDlgItem(IDC_STATIC_IN19),(CStatic *)GetDlgItem(IDC_STATIC_IN20),
	    (CStatic *)GetDlgItem(IDC_STATIC_IN21),(CStatic *)GetDlgItem(IDC_STATIC_IN22),(CStatic *)GetDlgItem(IDC_STATIC_IN23),(CStatic *)GetDlgItem(IDC_STATIC_IN24),(CStatic *)GetDlgItem(IDC_STATIC_IN25),
	    (CStatic *)GetDlgItem(IDC_STATIC_IN26),(CStatic *)GetDlgItem(IDC_STATIC_IN27),(CStatic *)GetDlgItem(IDC_STATIC_IN28),(CStatic *)GetDlgItem(IDC_STATIC_IN29),(CStatic *)GetDlgItem(IDC_STATIC_IN30),(CStatic *)GetDlgItem(IDC_STATIC_IN31)};
   
   /*	CButton *Button_out[32]= {(CButton *)GetDlgItem(IDC_BUTTON_OUT0),(CButton *)GetDlgItem(IDC_BUTTON_OUT1),(CButton *)GetDlgItem(IDC_BUTTON_OUT2),(CButton *)GetDlgItem(IDC_BUTTON_OUT3),(CButton *)GetDlgItem(IDC_BUTTON_OUT4),
		(CButton *)GetDlgItem(IDC_BUTTON_OUT5),(CButton *)GetDlgItem(IDC_BUTTON_OUT6),(CButton *)GetDlgItem(IDC_BUTTON_OUT7),(CButton *)GetDlgItem(IDC_BUTTON_OUT8),(CButton *)GetDlgItem(IDC_BUTTON_OUT9),(CButton *)GetDlgItem(IDC_BUTTON_OUT10),
		(CButton *)GetDlgItem(IDC_BUTTON_OUT11),(CButton *)GetDlgItem(IDC_BUTTON_OUT12),(CButton *)GetDlgItem(IDC_BUTTON_OUT13),(CButton *)GetDlgItem(IDC_BUTTON_OUT14),(CButton *)GetDlgItem(IDC_BUTTON_OUT15),
	    (CButton *)GetDlgItem(IDC_BUTTON_OUT16),(CButton *)GetDlgItem(IDC_BUTTON_OUT17),(CButton *)GetDlgItem(IDC_BUTTON_OUT18),(CButton *)GetDlgItem(IDC_BUTTON_OUT19),(CButton *)GetDlgItem(IDC_BUTTON_OUT20),
	    (CButton *)GetDlgItem(IDC_BUTTON_OUT21),(CButton *)GetDlgItem(IDC_BUTTON_OUT22),(CButton *)GetDlgItem(IDC_BUTTON_OUT23),(CButton *)GetDlgItem(IDC_BUTTON_OUT24),(CButton *)GetDlgItem(IDC_BUTTON_OUT25),
	    (CButton *)GetDlgItem(IDC_BUTTON_OUT26),(CButton *)GetDlgItem(IDC_BUTTON_OUT27),(CButton *)GetDlgItem(IDC_BUTTON_OUT28),(CButton *)GetDlgItem(IDC_BUTTON_OUT29),(CButton *)GetDlgItem(IDC_BUTTON_OUT30),(CButton *)GetDlgItem(IDC_BUTTON_OUT31)};*/
   
	DWORD active_level_1 = 0,active_level_2 = 0;
	//Plt_IoReadAllInput(m_nCard,&active_level_1,&active_level_2); 
	for ( i = 0; i < 32; i++)
    {   
		if ((active_level_1 & 1) == 0)
		{
		   Static_IN[i]->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_RED));       
		}
		else
		{
		   Static_IN[i]->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_GREEN));
		}
        active_level_1 = active_level_1 >> 1;
	}
	/*Plt_IoReadAllOutput(m_nCard,&active_level_1); 	
	for ( i = 0; i < 32; i++)
    {
	
		if ((dvalue & 1) == 0)
        {
           Button_out[i]->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_RED));       
        }
		else
		{
		   Button_out[i]->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_GREEN));
		}
        dvalue = dvalue >> 1;
	}*/
	CDialogEx::OnTimer(nIDEvent);
}
