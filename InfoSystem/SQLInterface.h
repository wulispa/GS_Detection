#pragma once

#include"DateInfo.h"

#define SQL_MAX 256		// sql����ַ��������ֵ

class SQLInterface
{
public:

	MYSQL_RES* res;	//result
	MYSQL_ROW row;
	MYSQL mysqlCon;	//Connet
	char sql[SQL_MAX];	// SQL���

	bool Connect_MySQL();	//�������ݿ�
	vector<DateInfo> Get_All_Info();	//��ȡȫ����Ϣ

	vector<DateInfo> Seek_info1(CString RecordTime);//���ҿ�ʼ��Ϣ
	vector<DateInfo> Seek_info2(CString ExpiringDate);//���ҽ�����Ϣ
	vector<DateInfo> Seek_info3(CString ExpiringDate);//��������������Ϣ


};

