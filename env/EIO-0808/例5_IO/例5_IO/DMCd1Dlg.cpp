// DMCd1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "DMCd1.h"
#include "DMCd1Dlg.h"
#include "PLT.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDMCd1Dlg dialog

CDMCd1Dlg::CDMCd1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDMCd1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDMCd1Dlg)
	m_nAxis = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDMCd1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDMCd1Dlg)
	DDX_Control(pDX, IDC_COMBO_NODENUM, m_combox_nodenum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDMCd1Dlg, CDialog)
	//{{AFX_MSG_MAP(CDMCd1Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_COMMAND_RANGE(IDC_BUTTON_OUT0, IDC_BUTTON_OUT0+31, OnOutputSignal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDMCd1Dlg message handlers

BOOL CDMCd1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
   
	// TODO: Add extra initialization here
	uint16 TotalCards;
	uint16 CardTypeArray[12];
	uint16 Section[12];
	uint16 Host_id[12];
	Section[0] = 167;
	Host_id[0] = 120;
	short iret;
	CString str;
	iret = Plt_CardOpen_extern(&TotalCards,&CardTypeArray[0],Section,Host_id);
	if(iret != 0)
	{
	     MessageBox(L"打开PLT控制卡失败",L"R-CONTROL",NULL);	
	}
	else
	{    
		 str.Format( L"找到控制卡个数:%d",TotalCards);
	     MessageBox(str,L"R-CONTROL",NULL);	
	}
	m_nCard = 0; 
		UpdateControl();
	    SetTimer( IDC_TIMER, 100, NULL );

	m_combox_nodenum.SetCurSel(1);

	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDMCd1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDMCd1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDMCd1Dlg::UpdateControl()
{
//	GetDlgItem( IDC_CHECK_LOGIC )->SetWindowText( m_bLogic?"逻辑方向：正":"逻辑方向：反");
}

void CDMCd1Dlg::OnTimer(UINT_PTR nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
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
   
   	CButton *Button_out[32]= {(CButton *)GetDlgItem(IDC_BUTTON_OUT0),(CButton *)GetDlgItem(IDC_BUTTON_OUT1),(CButton *)GetDlgItem(IDC_BUTTON_OUT2),(CButton *)GetDlgItem(IDC_BUTTON_OUT3),(CButton *)GetDlgItem(IDC_BUTTON_OUT4),
		(CButton *)GetDlgItem(IDC_BUTTON_OUT5),(CButton *)GetDlgItem(IDC_BUTTON_OUT6),(CButton *)GetDlgItem(IDC_BUTTON_OUT7),(CButton *)GetDlgItem(IDC_BUTTON_OUT8),(CButton *)GetDlgItem(IDC_BUTTON_OUT9),(CButton *)GetDlgItem(IDC_BUTTON_OUT10),
		(CButton *)GetDlgItem(IDC_BUTTON_OUT11),(CButton *)GetDlgItem(IDC_BUTTON_OUT12),(CButton *)GetDlgItem(IDC_BUTTON_OUT13),(CButton *)GetDlgItem(IDC_BUTTON_OUT14),(CButton *)GetDlgItem(IDC_BUTTON_OUT15),
	    (CButton *)GetDlgItem(IDC_BUTTON_OUT16),(CButton *)GetDlgItem(IDC_BUTTON_OUT17),(CButton *)GetDlgItem(IDC_BUTTON_OUT18),(CButton *)GetDlgItem(IDC_BUTTON_OUT19),(CButton *)GetDlgItem(IDC_BUTTON_OUT20),
	    (CButton *)GetDlgItem(IDC_BUTTON_OUT21),(CButton *)GetDlgItem(IDC_BUTTON_OUT22),(CButton *)GetDlgItem(IDC_BUTTON_OUT23),(CButton *)GetDlgItem(IDC_BUTTON_OUT24),(CButton *)GetDlgItem(IDC_BUTTON_OUT25),
	    (CButton *)GetDlgItem(IDC_BUTTON_OUT26),(CButton *)GetDlgItem(IDC_BUTTON_OUT27),(CButton *)GetDlgItem(IDC_BUTTON_OUT28),(CButton *)GetDlgItem(IDC_BUTTON_OUT29),(CButton *)GetDlgItem(IDC_BUTTON_OUT30),(CButton *)GetDlgItem(IDC_BUTTON_OUT31)};
   
	DWORD active_level_1,active_level_2;
	Plt_IoReadAllInput(m_nCard,&active_level_1,&active_level_2); 
	for ( i = 0; i < 32; i++)
    {   
		if ((dvalue & 1) == 0)
		{
		   Static_IN[i]->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_RED));       
		}
		else
		{
		   Static_IN[i]->SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_GREEN));
		}
        dvalue = dvalue >> 1;
	}
	Plt_IoReadAllOutput(m_nCard,&active_level_1); 	
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
	}
	CDialog::OnTimer(nIDEvent);
}







void CDMCd1Dlg::OnDestroy() 
{
	// TODO: Add your message handler code here
	Plt_CardClose();	//非常之重要，释放其占用的系统资源
	KillTimer( IDC_TIMER );
	CDialog::OnDestroy();
	
}
void CDMCd1Dlg::OnOutputSignal(UINT id) 
{
	// TODO: Add your control notification handler code here
	unsigned short OutputBit = 0,iret;
	Plt_IoReadOutputByBit(m_nCard,(id-IDC_BUTTON_OUT0),&OutputBit);//读取输出信号
	if( OutputBit == 0 )
		iret = Plt_IoWriteOutputByBit(m_nCard,(id-IDC_BUTTON_OUT0),1); 	//设置输出口的状态
	else
		iret = Plt_IoWriteOutputByBit(m_nCard,(id-IDC_BUTTON_OUT0),0); 	//设置输出口的状态
}

