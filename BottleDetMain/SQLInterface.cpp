#include "pch.h"
#include "SQLInterface.h"

bool SQLInterface::Connect_MySQL()
{
	mysql_init(&mysqlCon);

	// localhost:服务器地址，可以直接填入IP；
	// root:账号；
	// PassWord:密码；
	// DialogTest:数据库名；
	// 3306:网络端口
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "123456", "dateinfo", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败！"));
		return false;
	}
	else // MySQL连接成功则继续访问数据库
	{
		mysql_set_character_set(&mysqlCon, "gb2312"); //设置字节符，防止中文乱码.

	}
	return true;
}

bool SQLInterface::Add_Info(DateInfo Info)
{
	// 清空缓冲区
	memset(sql, 0, SQL_MAX);

	// C语言字符串组合
	int len =snprintf(sql, SQL_MAX, "INSERT INTO info VALUES('%s', '%s', '%s', '%s','%s','%s','%s','%s','%s','%s');"
		, Info.m_RecordNumber.c_str(), Info.m_RecordTime.c_str(), Info.m_BatchNumber.c_str()
		, Info.m_ExpiringDate.c_str(), Info.m_U1.c_str(), Info.m_D1.c_str(), Info.m_U2.c_str(), Info.m_D2.c_str()
		, Info.m_Operators.c_str(), Info.m_Notes.c_str());

	//检查 snprintf 生成的 SQL 查询是否正确
	std::cout << "Generated SQL: " << sql << std::endl;

	//检查 snprintf 的返回值以确保缓冲区足够
	if (len>= SQL_MAX) {
		std::cerr << "SQL query is too long!" << std::endl;
	}

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//判断添加结果
	if (ret) {
		//检查MySQL 函数谁否调用错误
		string a;
		a = mysql_error(&mysqlCon);
		//std::cerr << "SQL Error: " << mysql_error(&mysqlCon) << std::endl;
		AfxMessageBox(_T("添加失败！"));
		return false;
	}

	// 关闭数据库
	mysql_close(&mysqlCon);

	return true;
}