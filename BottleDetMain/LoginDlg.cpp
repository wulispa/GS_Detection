// LoginDlg.cpp: 实现文件
//
#include "pch.h"
#include "BottleDetMain.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "BottleDetMainDlg.h"
#include "ChangePassWordDlg.h"
using namespace tinyxml2;

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
    DDX_Control(pDX, IDC_CHECK_REIGSTSHOW, m_ComBox2);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &LoginDlg::OnBnClickedBtnLogin)
    ON_BN_CLICKED(IDC_BTN_REGIST, &LoginDlg::OnBnClickedBtnReigst)
    ON_WM_CTLCOLOR()
    ON_WM_SIZE()
    ON_EN_CHANGE(IDC_EDIT_PASSWORD, &LoginDlg::OnEnChangeEditPassword)
    ON_BN_CLICKED(IDC_BUT_CHANGE_PASSWORD, &LoginDlg::OnBnClickedButChangePassword)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// LoginDlg 消息处理程序
BOOL LoginDlg::OnInitDialog() {
    // TODO: 在此添加额外的初始化代码
    CDialogEx::OnInitDialog();

    m_ComBox1.AddString(_T("管理员"));
    m_ComBox1.AddString(_T("操作员"));
    m_ComBox2.AddString(_T("管理员"));
    m_ComBox2.AddString(_T("操作员"));

    //ReadConfiger();
    m_brush=CreateSolidBrush(RGB(255, 192, 203));

    CEdit* pmyEdit = (CEdit*)GetDlgItem(IDC_EDIT_PASSWORD); // 密码编辑框控件的指针
    CEdit* pregistEdit = (CEdit*)GetDlgItem(IDC_REGIST_PASSWORD); // 注册密码编辑框控件的指针
    CEdit* pconfirmEdit = (CEdit*)GetDlgItem(IDC_CONFIRM_PASSWORD); // 确认密码编辑框控件的指针
    CEdit* IDEdit = (CEdit*)GetDlgItem(IDC_EDIT_IDCODE); // 权限码编辑框控件的指针
    pmyEdit->SetPasswordChar('*');          // 显示格式为星号
    pregistEdit->SetPasswordChar('*');          // 显示格式为星号
    pconfirmEdit->SetPasswordChar('*');          // 显示格式为星号
    IDEdit->SetPasswordChar('*');          // 显示格式为星号

    //GetDlgItem(IDC_BTN_REGISTER)->ShowWindow(0);
    GetDlgItem(IDC_EDIT_USERNAME)->ShowWindow(0);
    GetDlgItem(IDC_BUT_CHANGE_PASSWORD)->ShowWindow(FALSE);
    GetDlgItem(IDC_STATIC_USERNAME2)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_PASSWORD2)->ShowWindow(FALSE);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        pSysMenu->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    }

    return TRUE;  // return TRUE unless you set the focus to a control
                  // 异常: OCX 属性页应返回 FALSE
}

void LoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
    //CDialogEx::OnOK();      // 关闭登陆界面


}

void LoginDlg::OnBnClickedBtnLogin()
{
	// TODO: 在此添加控件通知处理程序代码
      // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);       // 更新控件对应变量的值
    //GetDlgItemTextW(IDC_EDIT_USERNAME, m_username);
    GetDlgItemTextW(IDC_CHECK_SHOW, m_username);
    GetDlgItemTextW(IDC_EDIT_PASSWORD, m_password);
    CBottleDetMainDlg* pwin = (CBottleDetMainDlg*)parent_win;

    tinyxml2::XMLDocument doc;
    XMLError eResult = doc.LoadFile("users.xml");
    XMLElement* root = doc.FirstChildElement("Users");
    XMLElement* user = root->FirstChildElement("User");

    while (user != nullptr) {
        const char* name = user->Attribute("Name");
        const char* password = user->Attribute("Password");

        if (m_username == name && m_password == password)
        {
            m_pData->SetPersonUse(m_username);
            // 进入主对话框界面
            CDialogEx::OnOK();      // 关闭登陆界面
            pwin->PassLogin = true;
        }
        user = user->NextSiblingElement("User");
    }
    if(!pwin->PassLogin)
    {
        // 弹出窗口提示用户名或密码不正确
        MessageBox(_T("用户名或密码不正确！"), _T("提示"), MB_OK);
        // 清空用户名和密码，便于重新输入
        m_username = "";
        m_password = "";
        SetDlgItemText(IDC_EDIT_PASSWORD, TEXT(""));
        UpdateData(FALSE); // 更新编辑框控件的显示值
     }
    
}


HBRUSH LoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  在此更改 DC 的任何特性
    if (pWnd->GetDlgCtrlID() == IDC_STATIC_COM_PASS
        || pWnd->GetDlgCtrlID() == IDC_CHECK_SHOW
        || pWnd->GetDlgCtrlID() == IDC_EDIT_PASSWORD
        || pWnd->GetDlgCtrlID() == IDC_EDIT_PASSWORD2
        || pWnd->GetDlgCtrlID() == IDC_STATIC_USERNAME
        || pWnd->GetDlgCtrlID() == IDC_STATIC_USERNAME2
        || pWnd->GetDlgCtrlID() == IDC_STATIC_USER_PASS

        || pWnd->GetDlgCtrlID() == IDC_CHECK_REIGSTSHOW
        || pWnd->GetDlgCtrlID() == IDC_REGIST_PASSWORD
        || pWnd->GetDlgCtrlID() == IDC_CONFIRM_PASSWORD
        || pWnd->GetDlgCtrlID() == IDC_EDIT_IDCODE
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


void LoginDlg::OnEnChangeEditPassword()
{
  
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



void LoginDlg::OnBnClickedButChangePassword()
{
    UpdateData(TRUE);       // 更新控件对应变量的值
    GetDlgItemTextW(IDC_CHECK_SHOW, m_username);
    GetDlgItemTextW(IDC_EDIT_PASSWORD, m_password);
    ChangePassWordDlg dlg1(this);
    if (m_username == "管理员" && m_password == passWord[0])
    {
        UserSelectindex = 0;
        dlg1.DoModal();
        WriteConfiger();
        SetDlgItemText(IDC_EDIT_PASSWORD, TEXT(""));
    }
    else if (m_username == "操作员" && m_password == passWord[1]) {
        UserSelectindex = 1;
        dlg1.DoModal();
        WriteConfiger();
        SetDlgItemText(IDC_EDIT_PASSWORD, TEXT(""));
    }
    else
    {
        MessageBox(_T("用户名或密码不正确！"), _T("提示"), MB_OK);
        m_username = "";
        m_password = "";
        SetDlgItemText(IDC_EDIT_PASSWORD, TEXT(""));
        UpdateData(FALSE); // 更新编辑框控件的显示值
    }
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

void LoginDlg::OnBnClickedBtnReigst()
{
    // 加载 XML 文件
    tinyxml2::XMLDocument doc;
    XMLError eResult = doc.LoadFile("users.xml");
    if (eResult != XML_SUCCESS) {
        MessageBox(_T("加载 XML 文件失败！"), _T("错误"), MB_OK);
        return;
    }

    // 获取根节点
    XMLElement* root1 = doc.FirstChildElement("Users");
    XMLElement* root2 = doc.FirstChildElement("Codes");

    if (!root1 || !root2) {
        MessageBox(_T("无法找到根元素！"), _T("错误"), MB_OK);
        return;
    }

    // 遍历用户
    XMLElement* user = root1->FirstChildElement("User");
    XMLElement* code = root2->FirstChildElement("Code");

    if (!code) {
        MessageBox(_T("无法找到权限码元素！"), _T("错误"), MB_OK);
        return;
    }

    const char* permissionCode = code->Attribute("PermissionCode");

    // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE); // 更新控件对应变量的值
    GetDlgItemTextW(IDC_CHECK_REIGSTSHOW, r_username);  //用户名
    GetDlgItemTextW(IDC_REGIST_PASSWORD, r_password);   //注册密码
    GetDlgItemTextW(IDC_CONFIRM_PASSWORD, r_confirm_password);  //注册密码确认
    GetDlgItemTextW(IDC_EDIT_IDCODE, IDcode_password);  //输入权限码

    

    // 输出调试信息，确保获取的值是正确的
 //   TRACE(_T("r_username: %s\n"), r_username);
 //   TRACE(_T("r_password: %s\n"), r_password);
 //   TRACE(_T("r_confirm_password: %s\n"), r_confirm_password);
 //   TRACE(_T("IDcode_password: %s\n"), IDcode_password);

    // 确保密码非空
    if (r_password.IsEmpty() || r_confirm_password.IsEmpty()) {
        MessageBox(_T("密码不能为空！"), _T("错误"), MB_OK);
        return;
    }

    if (r_password == r_confirm_password && permissionCode) //密码二次输入正确且权限码非空
    {
        CString permissionCodeCString(permissionCode);  // 将 const char* 转换为 CString
        if (IDcode_password == permissionCodeCString) //ID码对应正确
        {
            CT2A pszConverted1(r_username);
            const char* r_username = pszConverted1; // 直接获得 const char* 类型
            CT2A pszConverted2(r_password);
            const char* r_password = pszConverted2; // 直接获得 const char* 类型
            MessageBox(_T("添加成功！"), _T("提示"), MB_OK);
            // 添加用户
            XMLElement* user1 = doc.NewElement("User");
            user1->SetAttribute("Name", r_username);
            user1->SetAttribute("Password", r_password);
            root1->InsertEndChild(user1); //插入到Users根里面

            // 保存到文件
            XMLError saveResult = doc.SaveFile("users.xml");
            SetDlgItemText(IDC_REGIST_PASSWORD, TEXT(""));
            SetDlgItemText(IDC_CONFIRM_PASSWORD, TEXT(""));
            SetDlgItemText(IDC_EDIT_IDCODE, TEXT(""));
            UpdateData(FALSE); // 更新编辑框控件的显示值

            if (saveResult != tinyxml2::XML_SUCCESS) {
                MessageBox(_T("保存 XML 文件失败！"), _T("错误"), MB_OK);
                return;
            }
        }
        else
        {
            MessageBox(_T("权限码错误！"), _T("提示"), MB_OK);
            SetDlgItemText(IDC_REGIST_PASSWORD, TEXT(""));
            SetDlgItemText(IDC_CONFIRM_PASSWORD, TEXT(""));
            SetDlgItemText(IDC_EDIT_IDCODE, TEXT(""));
            UpdateData(FALSE); // 更新编辑框控件的显示值
        }
    }
    else
    {
        MessageBox(_T("输入密码不同或权限码错误！"), _T("提示"), MB_OK);
        SetDlgItemText(IDC_REGIST_PASSWORD, TEXT(""));
        SetDlgItemText(IDC_CONFIRM_PASSWORD, TEXT(""));
        SetDlgItemText(IDC_EDIT_IDCODE, TEXT(""));
        UpdateData(FALSE); // 更新编辑框控件的显示值
    }
}




