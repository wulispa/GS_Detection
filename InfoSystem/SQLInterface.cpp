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
		string s = mysql_error(&mysqlCon);
		AfxMessageBox(_T("数据库连接失败！"));

		return false;
	}
	else // MySQL连接成功则继续访问数据库
	{
		mysql_set_character_set(&mysqlCon, "gb2312"); //设置字节符，防止中文乱码.

	}
	return true;
}

vector<DateInfo> SQLInterface::Get_All_Info()
{
	vector<DateInfo> Info;

	// C语言组合字符串
	snprintf(sql, SQL_MAX, "SELECT * FROM info");

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//判断查询结果
	if (ret) {
		printf("数据查询失败！失败原因：%s\n", mysql_error(&mysqlCon));
		return Info;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);

	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);

		Info.push_back(dateinfo);
	}
	return Info;

	// 释放结果集
	mysql_free_result(res);
}


vector<DateInfo> SQLInterface::Seek_info1(CString RecordTime)
{
	vector<DateInfo> result;

	Connect_MySQL();

	// C语言组合字符串
	snprintf(sql, SQL_MAX, "SELECT * FROM info where RecordTime = '%s';", RecordTime);


	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("查询失败！"));
		return result;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);

	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);
		result.push_back(dateinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return result;
}

vector<DateInfo> SQLInterface::Seek_info2(CString ExpiringDate)
{
	vector<DateInfo> result;

	Connect_MySQL();


	// C语言组合字符串
	snprintf(sql, SQL_MAX, "SELECT * FROM info where ExpiringDate = '%s';", ExpiringDate);


	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//判断查询结果
	if (ret) {
		AfxMessageBox(_T("查询失败！"));
		return result;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);

	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);
		result.push_back(dateinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return result;
}

vector<DateInfo> SQLInterface::Seek_info3(CString BatchNumber)
{
	vector<DateInfo> result;

	Connect_MySQL();


	// C语言组合字符串
	snprintf(sql, SQL_MAX, "SELECT * FROM info where BatchNumber = '%s';", BatchNumber);


	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//判断查询结果
	if (ret) {
		//AfxMessageBox(_T("查询失败！"));
		return result;
	}
	//获取结果集
	res = mysql_store_result(&mysqlCon);

	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);
		result.push_back(dateinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return result;
}