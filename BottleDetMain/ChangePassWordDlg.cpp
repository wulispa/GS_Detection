// ChangePasswordDlg.cpp: 实现文件
//

#include "pch.h"

#include "afxdialogex.h"
#include "ChangePasswordDlg.h"


// ChangePasswordDlg 对话框

IMPLEMENT_DYNAMIC(ChangePasswordDlg, CDialogEx)

ChangePasswordDlg::ChangePasswordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Change_DIALOG, pParent)
{
}

ChangePasswordDlg::~ChangePasswordDlg()
{
}
// RegistDlg 消息处理程序
BOOL ChangePasswordDlg::OnInitDialog() {
    // TODO: 在此添加额外的初始化代码
    CDialogEx::OnInitDialog();
    mysql_init(&mysql);
    SQL.Connect_MySQL();//连接数据库   
    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据

    //将data数据添加到m_ComBox1控件中

    for (int i = 0; i < data.size(); i++)
    {
        m_ComBox1.AddString(CA2T(data[i][0].c_str()));
    }

    //ReadConfiger();
    m_brush = CreateSolidBrush(RGB(255, 192, 203));

    CEdit* pmyEdit_Used_PASSWORD = (CEdit*)GetDlgItem(IDC_Used_PASSWORD); // 原始密码编辑框控件的指针
    CEdit* pmyEdit_Change_PASSWORD_PASSWORD = (CEdit*)GetDlgItem(IDC_Change_PASSWORD); // 新密码编辑框控件的指针
    CEdit* pmyEdit_Change_PASSWORD_Confirm = (CEdit*)GetDlgItem(IDC_Change_PASSWORD_Confirm); // 确认密码编辑框控件的指针

    pmyEdit_Used_PASSWORD->SetPasswordChar('*');          // 显示格式为星号
    pmyEdit_Change_PASSWORD_PASSWORD->SetPasswordChar('*');  // 显示格式为星号
    pmyEdit_Change_PASSWORD_Confirm->SetPasswordChar('*');            // 显示格式为星号


    return TRUE;  // return TRUE unless you set the focus to a control
}
// RegistDlg 消息处理程序

void ChangePasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CHECK_SHOW, m_ComBox1);
}


BEGIN_MESSAGE_MAP(ChangePasswordDlg, CDialogEx)
    ON_BN_CLICKED(IDC_OK, &ChangePasswordDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ChangePasswordDlg 消息处理程序

void ChangePasswordDlg::OnBnClickedOk()
{
    UpdateData(TRUE);       // 更新控件对应变量的值

    GetDlgItemTextW(IDC_CHECK_SHOW, name);  //用户名
    GetDlgItemTextW(IDC_Used_PASSWORD, used_password);   //原始密码
    GetDlgItemTextW(IDC_Change_PASSWORD, change_password);  //新密码
    GetDlgItemTextW(IDC_Change_PASSWORD_Confirm, confirmpassword);  //新密码确认

    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据

    if (name.IsEmpty() || used_password.IsEmpty() || change_password.IsEmpty() || confirmpassword.IsEmpty()) {
        MessageBox(_T("请填写完整信息！"), _T("错误"), MB_OK);
        return;
    }
    int i = 0;
    while (i < data.size()) {
        sys_name = CA2T(data[i][0].c_str());
		if (name == sys_name)//用户名正确
        {
			sys_password = CA2T(data[i][1].c_str());
			if (used_password == sys_password)//原始密码正确
            {
                if (change_password == confirmpassword) //两次密码相同，通过
                {
                    if (!SQL.IsValidPassword(change_password))//密码合法性检查
                    {
						MessageBox(_T("密码不合法！需保持在六位到十位且只包含字母，数字和字符"), _T("提示"), MB_OK);
						return;
                    }
                    string datetime = SQL.getFutureDatetime(2);//下次更新时间，当前时间增加2个月,可以根据参数修改

                    string query = "UPDATE logintable SET password = '" + string(CT2A(change_password)) + "', datetime = '" + datetime + "' WHERE username = '" + string(CT2A(name)) + "'";

                    SQL.updateDatabase(query);

                    CDialogEx::OnOK();      // 关闭注册界面
                    MessageBox(_T("修改密码成功！"), _T("提示"), MB_OK);

                    LoginDlg dlg;//登录对话框
                    dlg.DoModal();
                }
                else
                {
                    MessageBox(_T("两次密码不一致！"), _T("提示"), MB_OK);
                    SetDlgItemText(IDC_Change_PASSWORD, TEXT(""));
                    SetDlgItemText(IDC_Change_PASSWORD_Confirm, TEXT(""));
                    UpdateData(FALSE); // 更新编辑框控件的显示值
                    return;
                }
            }
			else
			{
				MessageBox(_T("原始密码错误！"), _T("提示"), MB_OK);
				return;
			}
        }
		i++;
    }
    if (i = data.size())
    {
        MessageBox(_T("用户名不存在！"), _T("提示"), MB_OK);
        return;
    }
}
