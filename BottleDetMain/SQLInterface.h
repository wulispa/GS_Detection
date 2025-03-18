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
	/*
	���ܣ���ȡ���ݿ�����
	������data���洢���ݵĶ�ά���飬queryStr����ѯ���
	����ֵ���ɹ�����true��ʧ�ܷ���false
	*/
	bool SQLInterface::getDatafromDB(std::vector<std::vector<std::string> >& data, std::string queryStr);	//��ȡ���ݿ�����
	void SQLInterface::FreeConnect();	//�ͷ�����
	/*
	���ܣ��������ݿ�
	������sql���������
	*/
	void SQLInterface::updateDatabase(string sql);	//�������ݿ�

	/*
	���ܣ��������ݿ�
	������sql���������
	����ֵ���ɹ�����true��ʧ�ܷ���false
	*/
	bool SQLInterface::InsertDB(string sql);//�������ݿ�

	/*
	���ܣ���ȡδ��ʱ��
	������month����������
	����ֵ��δ������ʱ��
	*/
	afx_msg string getFutureDatetime(int month);	//��ȡδ��ʱ��

	bool SQLInterface::IsValidPassword(const CString& password);//��������Ƿ���Ч
};

