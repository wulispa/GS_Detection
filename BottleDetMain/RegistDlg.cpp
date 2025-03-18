// RegistDlg.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "afxdialogex.h"
#include "RegistDlg.h"
#include "resource.h"


using namespace std;

// RegistDlg 对话框

IMPLEMENT_DYNAMIC(RegistDlg, CDialogEx)

RegistDlg::RegistDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REGIST_DLG, pParent)
{

}

RegistDlg::~RegistDlg()
{
}

void RegistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_Regist_SHOW, m_ComBox1);
}


BEGIN_MESSAGE_MAP(RegistDlg, CDialogEx)

	ON_BN_CLICKED(IDC_BTN_Regist, &RegistDlg::OnBnClickedBtnRegist)

END_MESSAGE_MAP()

// RegistDlg 消息处理程序
BOOL RegistDlg::OnInitDialog() {
    // TODO: 在此添加额外的初始化代码
    CDialogEx::OnInitDialog();
    mysql_init(&mysql);
    SQL.Connect_MySQL();//连接数据库   
    
    //将数据添加到m_ComBox1控件中

    m_ComBox1.AddString(_T("操作员"));
    m_ComBox1.AddString(_T("工艺员"));
    m_ComBox1.AddString(_T("管理员"));

    //ReadConfiger();
    m_brush = CreateSolidBrush(RGB(255, 192, 203));

    CEdit* pmyEdit_PASSWORD = (CEdit*)GetDlgItem(IDC_REGIST_PASSWORD); // 密码编辑框控件的指针
    CEdit* pmyEdit_CONFIRM_PASSWORD = (CEdit*)GetDlgItem(IDC_CONFIRM_PASSWORD); // 密码编辑框控件的指针
    CEdit* pmyEdit_IDCODE = (CEdit*)GetDlgItem(IDC_EDIT_IDCODE); // 密码编辑框控件的指针
    
    pmyEdit_PASSWORD->SetPasswordChar('*');          // 显示格式为星号
    pmyEdit_CONFIRM_PASSWORD->SetPasswordChar('*');  // 显示格式为星号
    pmyEdit_IDCODE->SetPasswordChar('*');            // 显示格式为星号


    return TRUE;  // return TRUE unless you set the focus to a control
}
// RegistDlg 消息处理程序


void RegistDlg::OnBnClickedBtnRegist()
{
    UpdateData(TRUE);       // 更新控件对应变量的值

    GetDlgItemTextW(IDC_Username, registname);  //用户名
    GetDlgItemTextW(IDC_REGIST_PASSWORD, password);   //注册密码
    GetDlgItemTextW(IDC_Regist_SHOW, ID);  //注册身份
    GetDlgItemTextW(IDC_CONFIRM_PASSWORD, confirmpassword);  //注册密码确认
    GetDlgItemTextW(IDC_EDIT_IDCODE, IDcode);  //输入权限码

    
    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据

    int state = 1; //状态
    int wrongtime = 0; //错误次数
    if (ID.IsEmpty() || registname.IsEmpty() || password.IsEmpty() || confirmpassword.IsEmpty() || IDcode.IsEmpty()) {
        MessageBox(_T("请填写完整信息！"), _T("错误"), MB_OK);
        return;
    }
    if (IDcode == permissionCode) //权限码正确
    {
		for (int i = 0; i < data.size(); i++)
		{
			if (registname == CA2T(data[i][0].c_str()))//用户名已存在
			{
				MessageBox(_T("用户名已存在！请更换"), _T("提示"), MB_OK);
				return;
			}
        }
		if (password == confirmpassword)  //两次密码一致
        {
            if (!SQL.IsValidPassword(password))//密码合法性检查
                    {
						MessageBox(_T("密码不合法！需保持在六位到十位且只包含字母，数字和字符"), _T("提示"), MB_OK);
						return;
                    }
            string datetime = SQL.getFutureDatetime(2);//下次更新时间，当前时间增加2个月,可以根据参数修改

            IDindex = getIDindex(ID); //获取身份索引

            // 构造 INSERT 语句
            string sql = "INSERT INTO logintable (username, password, ID, state, datetime, wrongtime) VALUES ('"
                + string(CT2A(registname)) + "', '"
                + string(CT2A(password)) + "', '"
                + std::to_string(IDindex) + "', "
                + std::to_string(state) + ", '"
                + datetime + "', "
                + std::to_string(wrongtime) + ");";
			SQL.InsertDB(sql); // 插入数据库
            CDialogEx::OnOK();      // 关闭注册界面
            MessageBox(_T("注册成功！"), _T("提示"), MB_OK);

            LoginDlg dlg;//登录对话框
            dlg.DoModal();
        }
        else
        {
            MessageBox(_T("两次密码不一致！"), _T("提示"), MB_OK);
            SetDlgItemText(IDC_REGIST_PASSWORD, TEXT(""));
            SetDlgItemText(IDC_CONFIRM_PASSWORD, TEXT(""));
            SetDlgItemText(IDC_EDIT_IDCODE, TEXT(""));
            UpdateData(FALSE); // 更新编辑框控件的显示值
         }
    }
    else
    {
        MessageBox(_T("权限码错误！"), _T("提示"), MB_OK);
        SetDlgItemText(IDC_EDIT_IDCODE, TEXT(""));
        UpdateData(FALSE); // 更新编辑框控件的显示值
    }
}

int RegistDlg::getIDindex(CString ID)
{
	int IDindex = -1;
	if (ID == _T("管理员"))
	{
		IDindex = 0;
	}
	else if (ID == _T("操作员"))
	{
		IDindex = 1;
	}
	else if (ID == _T("工艺员"))
	{
		IDindex = 2;
	}
	return IDindex;
}

