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
	MYSQL mysql;//���ݿ���
public:
	int max;
	/************************************************
	*   ���ܣ��������ݿ�
	*	������host�� username�� password�� ���ݿ���, �˿ں�
	*	����ֵ��int 1�������ӳɹ��� 0��������ʧ��
	************************************************/
	int connect(const char* host, const char* username, const char* password, const char* dbname, int port);
	/************************************************
	*   ���ܣ��ͷ����ݿ�����
	*	������
	*	����ֵ��
	************************************************/
	void disconnect();
	/************************************************
	*   ���ܣ������ض��µ�����
	*	�������꣬��
	*	����ֵ��unordered_map<int, vector<int>>
	************************************************/
	unordered_map<int, vector<int>> selectData(int Year, int Month);
	unordered_map<int, vector<int>> selectData(int Year, int Month, int max_num);


	/************************************************
	*   ���ܣ������ض����ڵ��ض���ε�ok��ng1-ng10����
	*   �������꣬�£��գ�Сʱ�����ͣ�ok��ng1��ng2��ng3...ng9��ng10������ֵ
	*   ����ֵ����
	************************************************/
	void insertData(string Year, string Month, string Day, string Hour, string Type, int Write_Content);


	/************************************************
	*   ���ܣ������ض�num��Сʱ�����ݣ�����Hour=8,num=12Ϊȡ8:00-19:59������
	*   �������꣬�£��գ�ʱ
	*   ����ֵ��vector<int> ��ok��ng1��ng2��ng3...ng9��ng10��
	************************************************/
	vector<int> GetPartData(int Year, int Month, int Day, int Hour, int num);
};

