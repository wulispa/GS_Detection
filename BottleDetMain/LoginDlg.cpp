// LoginDlg.cpp: 实现文件
//
#include "pch.h"
#include "BottleDetMain.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "BottleDetMainDlg.h"
#include "ChangePassWordDlg.h"

// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent),
    parent_win(pParent),
    UserSelectindex(0)
{

}

LoginDlg::LoginDlg(CWnd* pParent, DataManager* pdata)
    : CDialogEx(IDD_LOGIN_DIALOG, pParent),
    parent_win(pParent),
    UserSelectindex(0),
    m_pData(pdata)
{
}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_SHOW, m_ComBox1);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &LoginDlg::OnBnClickedBtnLogin)

    ON_WM_CTLCOLOR()
    ON_WM_SIZE()
    ON_WM_PAINT()

    ON_BN_CLICKED(IDC_BTN_Regist, &LoginDlg::OnBnClickedBtnRegist)
    ON_BN_CLICKED(IDC_BTN_Changepassword, &LoginDlg::OnBnClickedBtnChangepassword)
END_MESSAGE_MAP()


// LoginDlg 消息处理程序
BOOL LoginDlg::OnInitDialog() {
    // TODO: 在此添加额外的初始化代码
    CDialogEx::OnInitDialog();
    mysql_init(&mysql);
    SQL.Connect_MySQL();//连接数据库   
    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据
	//将data第一列数据添加到m_ComBox1控件中

	for (int i = 0; i < data.size(); i++)
	{
		m_ComBox1.AddString(CA2T(data[i][0].c_str()));
	}

    //ReadConfiger();
    m_brush=CreateSolidBrush(RGB(255, 192, 203));

    CEdit* pmyEdit = (CEdit*)GetDlgItem(IDC_Login_PASSWORD); // 密码编辑框控件的指针

    pmyEdit->SetPasswordChar('*');          // 显示格式为星号


    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        //用户将无法通过点击对话框右上角的关闭按钮来关闭对话框
        pSysMenu->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

    }
    
    return TRUE;  // return TRUE unless you set the focus to a control
                  // 异常: OCX 属性页应返回 FALSE
}
CTime CStringToCTime(const CString& datetime)
{
    int year, month, day, hour, minute, second;
    if (_stscanf_s(datetime, _T("%d-%d-%d %d:%d:%d"), &year, &month, &day, &hour, &minute, &second) == 6)
    {
        return CTime(year, month, day, hour, minute, second);
    }
    return CTime(); // 解析失败，返回无效时间
}

bool CompareDateTime(CString datetime)
{

    CTime t = CStringToCTime(datetime); // 转换为 CTime
    if (CTime::GetCurrentTime() > t)
        return FALSE;
    return true;
}

void LoginDlg::OnBnClickedBtnLogin()
{
    // TODO: 在此添加控件通知处理程序代码

    UpdateData(TRUE);       // 更新控件对应变量的值
    //GetDlgItemTextW(IDC_EDIT_USERNAME, m_username);
    GetDlgItemTextW(IDC_CHECK_SHOW, m_username);
    GetDlgItemTextW(IDC_EDIT_PASSWORD, m_password);
    CBottleDetMainDlg* pwin = (CBottleDetMainDlg*)parent_win;
    //data初始化为空
	data.clear();
    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据

    int i = 0;
    while (i < data.size()) {
        name = CA2T(data[i][0].c_str());
        if (m_username == name)
        {
            password = CA2T(data[i][1].c_str());
            //Sting ID = CA2T(data[i][2].c_str());
            wrongtimes = std::stoi(data[i][5]);
            if (data[i][3] == "1")
                state = 1;
            else
                state = 0;
            datetime = CA2T(data[i][4].c_str());
            //std::string query = "UPDATE logintable SET 密码错误次数 = " + std::to_string(wrongtimes) + " WHERE 用户 = '" + CT2A(m_username.GetString()) + "'";

			if (wrongtimes >= 3)
			{
				MessageBox(_T("该用户已被锁定！请联系管理员解锁"), _T("提示"), MB_OK);
				return;
			}
            if (!state)
            {
                MessageBox(_T("该用户已被禁用！"), _T("提示"), MB_OK);
                return;
            }
            if (!CompareDateTime(datetime))//1是未过期
            {
                MessageBox(_T("该用户已过期！请重新修改密码以更新有效期"), _T("提示"), MB_OK);
                return;
            }
            if (m_password == password)
            {
                m_pData->SetPersonUse(m_username);
				//登录成功将次数清零
                std::string query = "UPDATE logintable SET wrongtime = " + std::to_string(0) + " WHERE username = '" + CW2A(m_username.GetString(), CP_UTF8) + "'";
                SQL.updateDatabase(query);
                // 进入主对话框界面
                CDialogEx::OnOK();      // 关闭登陆界面
                data.clear();
                pwin->PassLogin = true;
            }
            else
            {
                wrongtimes++;
                string query = "UPDATE logintable SET wrongtime = " + std::to_string(wrongtimes) + " WHERE username = '" + CW2A(m_username.GetString(), CP_UTF8) + "'";
				SQL.updateDatabase(query);
                //SQL.getDatafromDB(data, query);
                CString message;
                message.Format(_T("密码错误！剩余 %d 次"), 3 - wrongtimes);
                MessageBox(message, _T("提示"), MB_OK);
                return;
            }
        }
        i++;
    }
    if(i = data.size())
    {
        MessageBox(_T("用户名不存在！"), _T("提示"), MB_OK);
        return;
    }
    if (!pwin->PassLogin)
    {
        // 清空用户名和密码，便于重新输入
        m_username = _T("");
        m_password = _T("");
        SetDlgItemText(IDC_EDIT_PASSWORD, TEXT(""));
        UpdateData(FALSE); // 更新编辑框控件的显示值
    }
}


HBRUSH LoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  在此更改 DC 的任何特性
    if (pWnd->GetDlgCtrlID() == IDC_CHECK_SHOW
		|| pWnd->GetDlgCtrlID() == IDC_STATIC_COM_PASS
		|| pWnd->GetDlgCtrlID() == IDC_CHECK_SHOW
        || pWnd->GetDlgCtrlID() == IDC_STATIC_USERNAME
        || pWnd->GetDlgCtrlID() == IDC_STATIC_USER_PASS
        )
    { 
        pDC->SetTextColor(RGB(40, 2, 247));
        pDC->SetBkColor(RGB(255, 192, 203));//设置文本背景颜色
        hbr = HBRUSH(m_brush);
    }

    return hbr;
}


void LoginDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogEx::OnSize(nType, cx, cy);

    // TODO: 在此处添加消息处理程序代码
}



void LoginDlg::ReadConfiger()
{
    fstream ifile;
    ifile.open("pass.txt");
    string str1;
    ifile >> str1;
    CString dst1 = CA2T(str1.c_str());
    string str2;
    ifile >> str2;
    CString dst2 = CA2T(str2.c_str());
    passWord.push_back(dst1);
    passWord.push_back(dst2);
    ifile.close();//关闭是个好习惯
}
void LoginDlg::WriteConfiger()
{
    fstream ifile;
    ifile.open("pass.txt", ios::out | ios::trunc);
    ifile.close();
    ifile.open("pass.txt");
    string str1 = CT2A(passWord[0].GetString());
    ifile<<str1;
    ifile << endl;
    string str2 = CT2A(passWord[1].GetString());
    ifile << str2;
    ifile.close();//关闭是个好习惯
}

void LoginDlg::OnPaint()
{
    //绘制背景
    CRect rect;
    CPaintDC dc(this);
    GetClientRect(rect);
    dc.FillSolidRect(rect, RGB(255, 192, 203));
    CDialogEx::OnPaint();
}

void LoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    // 禁用关闭按钮
    if ((nID & 0xFFF0) == SC_CLOSE)
    {
        // 这里可以添加你希望执行的代码，例如显示一个提示对话框
        AfxMessageBox(_T("关闭按钮已禁用。"));
        return;
    }

    CDialogEx::OnSysCommand(nID, lParam);
}




void LoginDlg::OnBnClickedBtnRegist()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnOK();      // 关闭登录界面
    RegistDlg dlg;//注册对话框
	dlg.DoModal();

}

void LoginDlg::OnBnClickedBtnChangepassword()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnOK();
	ChangePasswordDlg dlg;//修改密码对话框
    dlg.DoModal();
}

