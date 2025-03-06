#pragma once

#include"DateInfo.h"

#define SQL_MAX 256		// sql语句字符数组最大值

class SQLInterface
{
public:

	MYSQL_RES* res;	//result
	MYSQL_ROW row;
	MYSQL mysqlCon;	//Connet
	char sql[SQL_MAX];	// SQL语句

	bool Connect_MySQL();	//连接数据库
	vector<DateInfo> Get_All_Info();	//获取全部信息

	vector<DateInfo> Seek_info1(CString RecordTime);//查找开始信息
	vector<DateInfo> Seek_info2(CString ExpiringDate);//查找结束信息
	vector<DateInfo> Seek_info3(CString ExpiringDate);//查找生产批号信息


};

