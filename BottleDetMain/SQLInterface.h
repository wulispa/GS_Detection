#pragma once

#include"DateInfo.h"
#include <mysql.h>

#define SQL_MAX 256		// sql语句字符数组最大值

class SQLInterface
{
public:

	MYSQL_RES* res;	//result
	MYSQL_ROW row;
	MYSQL mysqlCon;	//Connet
	char sql[SQL_MAX];	// SQL语句

	bool Connect_MySQL();	//连接数据库

	bool Add_Info(DateInfo Info);	//添加信息

};

