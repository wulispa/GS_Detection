#pragma once
#include<WinSock2.h>
#include<mysql.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string>
#include <unordered_map>
#include <vector>

using namespace std;

class ConnDB {

public:
	ConnDB();
	~ConnDB();
private:
	MYSQL mysql;//数据库句柄
public:
	int max;
	/************************************************
	*   功能：连接数据库
	*	参数：host， username， password， 数据库名, 端口号
	*	返回值：int 1代表连接成功， 0代表连接失败
	************************************************/
	int connect(const char* host, const char* username, const char* password, const char* dbname, int port);
	/************************************************
	*   功能：释放数据库连接
	*	参数：
	*	返回值：
	************************************************/
	void disconnect();
	/************************************************
	*   功能：返回特定月的数据
	*	参数：年，月
	*	返回值：unordered_map<int, vector<int>>
	************************************************/
	unordered_map<int, vector<int>> selectData(int Year, int Month);
	unordered_map<int, vector<int>> selectData(int Year, int Month, int max_num);


	/************************************************
	*   功能：插入特定日期的特定班次的ok或ng1-ng10数据
	*   参数：年，月，日，小时，类型（ok、ng1、ng2、ng3...ng9、ng10），数值
	*   返回值：无
	************************************************/
	void insertData(string Year, string Month, string Day, string Hour, string Type, int Write_Content);


	/************************************************
	*   功能：返回特定num个小时的数据，例：Hour=8,num=12为取8:00-19:59的数据
	*   参数：年，月，日，时
	*   返回值：vector<int> （ok、ng1、ng2、ng3...ng9、ng10）
	************************************************/
	vector<int> GetPartData(int Year, int Month, int Day, int Hour, int num);
};

