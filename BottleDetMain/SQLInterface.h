#pragma once

#include"DateInfo.h"
#include <mysql.h>

#define SQL_MAX 256		// sql����ַ��������ֵ

class SQLInterface
{
public:

	MYSQL_RES* res;	//result
	MYSQL_ROW row;
	MYSQL mysqlCon;	//Connet
	char sql[SQL_MAX];	// SQL���

	bool Connect_MySQL();	//�������ݿ�

	bool Add_Info(DateInfo Info);	//�����Ϣ

};

