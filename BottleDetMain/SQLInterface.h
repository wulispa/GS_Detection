#pragma once

#include"DateInfo.h"
#include <mysql.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <regex>

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
	/*
	功能：获取数据库数据
	参数：data：存储数据的二维数组，queryStr：查询语句
	返回值：成功返回true，失败返回false
	*/
	bool SQLInterface::getDatafromDB(std::vector<std::vector<std::string> >& data, std::string queryStr);	//获取数据库数据
	void SQLInterface::FreeConnect();	//释放连接
	/*
	功能：更新数据库
	参数：sql：更新语句
	*/
	void SQLInterface::updateDatabase(string sql);	//更新数据库

	/*
	功能：插入数据库
	参数：sql：插入语句
	返回值：成功返回true，失败返回false
	*/
	bool SQLInterface::InsertDB(string sql);//插入数据库

	/*
	功能：获取未来时间
	参数：month：增加月数
	返回值：未来更新时间
	*/
	afx_msg string getFutureDatetime(int month);	//获取未来时间

	bool SQLInterface::IsValidPassword(const CString& password);//检查密码是否有效
};

