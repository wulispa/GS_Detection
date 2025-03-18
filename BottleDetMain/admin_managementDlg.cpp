// admin_managementDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "admin_managementDlg.h"


// admin_managementDlg 对话框

IMPLEMENT_DYNAMIC(admin_managementDlg, CDialogEx)

admin_managementDlg::admin_managementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_admin_management, pParent)
{

}

admin_managementDlg::~admin_managementDlg()
{
}

void admin_managementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);

}


BOOL admin_managementDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();


	showbutton = 0;//初始化显示密码按钮状态为隐藏状态
	choose_username = _T("");//初始化选择的用户名为空
    Selected_user = -1;//初始化选中行为-1

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        //用户将无法通过点击对话框右上角的关闭按钮来关闭对话框
        pSysMenu->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

    }

    // 设置 ListCtrl 为 Report 模式（表格模式）
    m_list.ModifyStyle(0, LVS_REPORT);

    // 设置ListCtrl为Report模式（带表头）
    m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // 添加列
    m_list.InsertColumn(0, _T("用户名"), LVCFMT_LEFT, 90);
    m_list.InsertColumn(1, _T("密码"), LVCFMT_LEFT, 90);
    m_list.InsertColumn(2, _T("身份"), LVCFMT_LEFT, 90);
    m_list.InsertColumn(3, _T("状态"), LVCFMT_LEFT, 90);
    m_list.InsertColumn(4, _T("日期"), LVCFMT_LEFT, 140);
    m_list.InsertColumn(5, _T("错误次数"), LVCFMT_LEFT, 110);

    SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX);


    mysql_init(&mysql);
    SQL.Connect_MySQL();//连接数据库   
    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据
    string code = "******";
    // 先清空已有数据
    m_list.DeleteAllItems();

	// 添加数据（行号, 列号, 文本内容）i是行 j是列
    for (int i = 0; i < data.size(); i++)
    {
       for (int j = 0; j < data[i].size(); j++)
       {
           if (j == 0) 
               m_list.InsertItem(i, CString(data[i][j].c_str()));//插入第一列
		   else if (j == 1)
               m_list.SetItemText(i, 1, CString(code.c_str()));
		   else if (j == 2)//插入身份
           {
               if(data[i][2]=="0")
                    m_list.SetItemText(i, 2, CString("管理员"));
			   else if (data[i][2] == "1")
                    m_list.SetItemText(i, 2, CString("操作员"));
               else
                    m_list.SetItemText(i, 2, CString("工艺员"));
		   }
		   else if (j == 3)//插入状态
		   {
			   if (data[i][3] == "0")
				   m_list.SetItemText(i, 3, CString("禁用"));
			   else
				   m_list.SetItemText(i, 3, CString("正常"));
		   }
           else
               m_list.SetItemText(i, j, CString(data[i][j].c_str()));//插入其余列
       }
    }

    return TRUE;
}



BEGIN_MESSAGE_MAP(admin_managementDlg, CDialogEx)
	ON_BN_CLICKED(ID_Back, &admin_managementDlg::OnBnClickedBack)
    ON_BN_CLICKED(ID_show, &admin_managementDlg::OnBnClickedshow)
    ON_BN_CLICKED(ID_Confirm, &admin_managementDlg::OnBnClickedConfirm)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, &admin_managementDlg::OnLvnItemchangedList)

    ON_BN_CLICKED(ID_Activate, &admin_managementDlg::OnBnClickedActivate)
    ON_BN_CLICKED(ID_Lock, &admin_managementDlg::OnBnClickedLock)
END_MESSAGE_MAP()


// admin_managementDlg 消息处理程序

void admin_managementDlg::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

void admin_managementDlg::OnBnClickedshow()
{
    //BOOL isEnabled = GetDlgItem(ID_BUTTON1)->IsWindowEnabled();
    //GetDlgItem(ID_BUTTON1)->EnableWindow(FALSE);  // 禁用按钮
	data.clear();
    SQL.getDatafromDB(data, "select * from logintable");//获取数据库数据
	if (!showbutton)
	{
        GetDlgItem(ID_show)->SetWindowText(_T("隐藏密码"));
        showbutton = 1;
        for (int i = 0; i < data.size(); i++)
        {
            m_list.SetItemText(i, 1, CString(data[i][1].c_str()));//插入其余列
        }
	}
	else
	{
        GetDlgItem(ID_show)->SetWindowText(_T("显示密码"));
        showbutton = 0;
        string code = "******";
        for (int i = 0; i < data.size(); i++)
        {
            m_list.SetItemText(i, 1, CString(code.c_str()));//插入其余列
        }
	}
}

void admin_managementDlg::OnBnClickedConfirm()
{
    if (Selected_user == -1)  // -1 表示没有选中行
    {
        MessageBox(_T("请选中用户"), _T("提示"), MB_OK);
        return;
    }
    UpdateData(TRUE);       // 更新控件对应变量的值

    GetDlgItemTextW(IDC_password, change_password);  //新密码
    GetDlgItemTextW(IDC_CONFIRM_PASSWORD, confirmpassword);  //新密码确认
    if (change_password == confirmpassword) //两次密码相同，通过
    {
        if (!SQL.IsValidPassword(change_password))//密码合法性检查
        {
            MessageBox(_T("密码不合法！需保持在六位到十位且只包含字母，数字和字符"), _T("提示"), MB_OK);
            return;
        }
        string datetime = SQL.getFutureDatetime(2);//下次更新时间，当前时间增加2个月,可以根据参数修改

        string query = "UPDATE logintable SET password = '" + string(CT2A(change_password)) + "', datetime = '" + datetime + "' WHERE username = '" + CW2A(choose_username.GetString(), CP_UTF8) + "'";

        SQL.updateDatabase(query);

        {
            GetDlgItem(ID_show)->SetWindowText(_T("显示密码"));
            showbutton = 0;
            string code = "******";
            for (int i = 0; i < data.size(); i++)
            {
                m_list.SetItemText(i, 1, CString(code.c_str()));//插入其余列
            }
        }
        MessageBox(_T("修改密码成功！"), _T("提示"), MB_OK);
    }
    else
    {
        MessageBox(_T("两次密码不一致！"), _T("提示"), MB_OK);
        SetDlgItemText(IDC_password, TEXT(""));
        SetDlgItemText(IDC_CONFIRM_PASSWORD, TEXT(""));
        UpdateData(FALSE); // 更新编辑框控件的显示值
        return;
    }
    Selected_user = -1;//取消选中
}

void admin_managementDlg::OnLvnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
    // 检查是否有选中的行
    int nSelected = m_list.GetNextItem(-1, LVNI_SELECTED);
    if (nSelected != -1)  // -1 表示没有选中行
    {
        choose_username = m_list.GetItemText(nSelected, 0);
        Selected_user = 1;
        message.Format(_T("已选中用户 : %s"),
            choose_username);
        AfxMessageBox(message);
    }
}

void admin_managementDlg::OnBnClickedActivate()
{
    if (Selected_user == -1)  // -1 表示没有选中行
    {
        MessageBox(_T("请选中用户"), _T("提示"), MB_OK);
        return;
    }
    string query = "UPDATE logintable SET state = " + std::to_string(1) + " ,wrongtime = " + std::to_string(0) + " WHERE username = '" + CW2A(choose_username.GetString(), CP_UTF8) + "'";
    SQL.updateDatabase(query);
    message.Format(_T("用户:%s 已激活"), choose_username.GetString());
    AfxMessageBox(message);
    data.clear();
    SQL.getDatafromDB(data, "select * from logintable");//更新数据库数据
    
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][3] == "0")
            m_list.SetItemText(i, 3, CString("禁用"));
        else
            m_list.SetItemText(i, 3, CString("正常"));

        m_list.SetItemText(i, 5, CString(data[i][5].c_str()));//更新错误次数
    }
    Selected_user = -1;//取消选中
}

void admin_managementDlg::OnBnClickedLock()
{
    if (Selected_user == -1)  // -1 表示没有选中行
    {
        MessageBox(_T("请选中用户"), _T("提示"), MB_OK);
        return;
    }
    std::string query = "UPDATE logintable SET state = " + std::to_string(0) + " WHERE username = '" + CW2A(choose_username.GetString(), CP_UTF8) + "'";
    SQL.updateDatabase(query);
    message.Format(_T("用户: %s 已锁定" ), choose_username.GetString());
    AfxMessageBox(message);
	data.clear();
    SQL.getDatafromDB(data, "select * from logintable");//更新数据库数据
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][3] == "0")
            m_list.SetItemText(i, 3, CString("禁用"));
        else
            m_list.SetItemText(i, 3, CString("正常"));

        m_list.SetItemText(i, 5, CString(data[i][5].c_str()));//更新错误次数
    }
    Selected_user = -1;//取消选中
}
