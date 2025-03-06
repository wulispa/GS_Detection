#include "pch.h"
#include"ConnDB.h"
#include<iostream>

using namespace std;

ConnDB::ConnDB() {
}
ConnDB::~ConnDB() {
	
}

bool checkNextMonth(int Year, int Month, int Day);
vector<int> getNextDate(int Year, int Month, int Day);


int ConnDB::connect(const char* host, const char* username, const char* password, const char* dbname, int port) {
	//��ʼ�����ݿ�
	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, host, username,
		password, dbname, port, NULL, 0) == NULL) {
		printf("����ԭ��: %s\n", mysql_error(&mysql));
		printf("����ʧ�ܣ�\n");
		return 0;
	}
	return 1;
}

void ConnDB::disconnect() {
	//�ر����ݿ�
	mysql_close(&mysql);
}


unordered_map<int, vector<int>> ConnDB::selectData(int Year, int Month) {

	unordered_map<int, vector<int>> monthData;
	vector<int> dayData;

	string year = to_string(Year);
	string month = to_string(Month);

	MYSQL_RES* res;//��ѯ�����
	MYSQL_ROW row;//��¼�ṹ��

	//�����ַ�����
	// mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	// ��ʼ��monthData
	for (int i = 0; i <= 31; i++) {
		vector<int>().swap(dayData);
		for (int j = 0; j <= 1; j++) {
			dayData.push_back(0);
		}
		monthData[i] = dayData;
	}

	//�������ݿ�
	int res11 = connect("127.0.0.1", "root", "123456", "mydetect1", 3306);
	if (res11 == 0) {
		return monthData;
	}
	//������Ҫ�����Լ��ı����������룬��ȫΪĬ�ϣ�ֻ�����*��Ϊ�Լ��������Լ���xsgl�����ĳ��Լ����������ݿ⼴��

	//��ѯ����
	string sql1 = "select day(detectdate),sum(ok),sum(ng1),sum(ng2),sum(ng3),sum(ng4),sum(ng5),sum(ng6),sum(ng7),sum(ng8),sum(ng9),sum(ng10) from summary where year(detectdate)='" + year + "' and month(detectdate)='" + month + "' GROUP BY detectdate;";
	int ret = mysql_query(&mysql, sql1.c_str());

	//��ȡ�����
	res = mysql_store_result(&mysql);
	int ng_sum = 0;
	//��ROW��ֵ,�ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res))
	{
		vector<int>().swap(dayData);
		for (int i = 1; i <= 11; i++) {
			if (i == 1) {
				//dayData.push_back(atoi(row[i]));
				dayData.push_back(atoll(row[i]));
			}
			else if (i == 11) {
				//ng_sum += atoi(row[i]);
				ng_sum += atoll(row[i]);
				dayData.push_back(ng_sum);
			}
			else {
				//ng_sum += atoi(row[i]);
				ng_sum += atoll(row[i]);
			}
		}
		monthData[atoi(row[0])] = dayData;
	}
	//�ͷŽ����
	mysql_free_result(res);
	disconnect();
	return monthData;
}

unordered_map<int, vector<int>> ConnDB::selectData(int Year, int Month, int max_num)
{
	unordered_map<int, vector<int>> monthData;
	vector<int> dayData;

	string year = to_string(Year);
	string month = to_string(Month);

	MYSQL_RES* res;//��ѯ�����
	MYSQL_ROW row;//��¼�ṹ��

	//�����ַ�����
	// mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	// ��ʼ��monthData
	for (int i = 0; i <= 31; i++) {
		vector<int>().swap(dayData);
		for (int j = 0; j <= 1; j++) {
			dayData.push_back(0);
		}
		monthData[i] = dayData;
	}

	//�������ݿ�
	int res11 = connect("127.0.0.1", "root", "123456", "mydetect1", 3306);
	if (res11 == 0) {
		return monthData;
	}
	//������Ҫ�����Լ��ı����������룬��ȫΪĬ�ϣ�ֻ�����*��Ϊ�Լ��������Լ���xsgl�����ĳ��Լ����������ݿ⼴��

	//��ѯ����
	string sql1 = "select day(detectdate),sum(ok),sum(ng1),sum(ng2),sum(ng3),sum(ng4),sum(ng5),sum(ng6),sum(ng7),sum(ng8),sum(ng9),sum(ng10) from summary where year(detectdate)='" + year + "' and month(detectdate)='" + month + "' GROUP BY detectdate;";
	int ret = mysql_query(&mysql, sql1.c_str());

	//��ȡ�����
	res = mysql_store_result(&mysql);
	int ng_sum = 0;
	//��ROW��ֵ,�ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	max = 0;
	while (row = mysql_fetch_row(res))
	{
		ng_sum = 0;
		vector<int>().swap(dayData);
		for (int i = 1; i <= 11; i++) {
			if (i == 1) {
				max = max > atoll(row[i]) ? max : atoll(row[i]);
				//dayData.push_back(atoi(row[i]));
				dayData.push_back(atoll(row[i]));
			}
			else if (i == 11) {
				//ng_sum += atoi(row[i]);
				ng_sum += atoll(row[i]);
				max = max > ng_sum ? max : ng_sum;
				dayData.push_back(ng_sum);
			}
			else {
				//ng_sum += atoi(row[i]);
				ng_sum += atoll(row[i]);
			}
		}
		monthData[atoi(row[0])] = dayData;
	}
	max_num = max;
	//�ͷŽ����
	mysql_free_result(res);
	disconnect();
	return monthData;
}

void ConnDB::insertData(string Year, string Month, string Day, string Hour, string Type, int Write_Content) {
	int orign_content = 0;
	int write_content = Write_Content;
	string date = Year + "-" + Month + "-" + Day;
	string sql1, sql2;
	
	MYSQL_RES* res;
	MYSQL_ROW row;
	int res11 = connect("127.0.0.1", "root", "123456", "mydetect1", 3306);
	if (res11 == 0) {
		return ;
	}

	//���ñ��뷽ʽ
	//mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

	sql1 = "select " + Type + " from summary where detectdate='" + date + "' and hour='"+Hour+"';";
	int ret = mysql_query(&mysql, sql1.c_str());
	res = mysql_store_result(&mysql);
	if (row = mysql_fetch_row(res)) {
		//cout << "you" << endl;
		orign_content = atoi(row[0]);
		write_content += orign_content;
		sql2 = "update summary set " + Type + "= '" + to_string(write_content) + "' where detectdate='" + date + "' and hour = '" + Hour + "';";
	}
	else {
		//cout << "wu" << endl;
		sql2 = "insert into summary (detectdate, hour, " + Type + ") values ('" + date + "', '" + Hour + "', '" + to_string(write_content) + "')";
	}
	//sql����ύ
	ret = mysql_query(&mysql, sql2.c_str()); 
	//�ͷŽ����
	mysql_free_result(res);
	disconnect();
}

vector<int> ConnDB::GetPartData(int Year, int Month, int Day, int Hour, int num) {

	MYSQL_RES* res1;
	MYSQL_RES* res2;
	MYSQL_ROW row1;
	MYSQL_ROW row2;

	vector<int> result;
	// ��ʼ������ֵ
	for (int i = 0; i <= 10; i++) {
		result.push_back(0);
	}
	string date = to_string(Year) + '-' + to_string(Month) + '-' + to_string(Day);
	string hour = to_string(Hour);
	string end = to_string(Hour + num - 1);

	int nextEnd;
	int nextYear, nextMonth, nextDay;
	vector<int> nextDate;
	int res11 = connect("127.0.0.1", "root", "123456", "mydetect1", 3306);
	if (res11 == 0) {
		return result;
	}

	if (Hour + num >= 24) {
		nextEnd = Hour + num - 24 - 1;
		vector<int>().swap(nextDate);
		nextDate = getNextDate(Year, Month, Day);
		nextYear = nextDate[0];
		nextMonth = nextDate[1];
		nextDay = nextDate[2];
		string date2 = to_string(nextYear) + '-' + to_string(nextMonth) + '-' + to_string(nextDay);
		// ��װsql
		string sql1 = "select sum(ok), sum(ng1), sum(ng2), sum(ng3), sum(ng4), sum(ng5), sum(ng6), sum(ng7), sum(ng8), sum(ng9), sum(ng10) from summary where detectdate='" + date + "' and hour between " + hour + " and 23;";
		int ret1 = mysql_query(&mysql, sql1.c_str());
		// ��ȡ�����
		res1 = mysql_store_result(&mysql);
		row1 = mysql_fetch_row(res1);
		if (row1[0] != NULL) {
			for (int i = 0; i <= 10; i++) {
				//result[i] = result[i] + atoi(row1[i]);
				result[i] = result[i] + atoll(row1[i]);
			}
		}
		mysql_free_result(res1);
		string sql2 = "select sum(ok), sum(ng1), sum(ng2), sum(ng3), sum(ng4), sum(ng5), sum(ng6), sum(ng7), sum(ng8), sum(ng9), sum(ng10) from summary where detectdate='" + date2 + "' and hour between 0 and " + to_string(nextEnd) + ";";
		int ret2 = mysql_query(&mysql, sql2.c_str());
		// ��ȡ�����
		res2 = mysql_store_result(&mysql);
		// ��ȡ�����
		row2 = mysql_fetch_row(res2);
		if (row2[0] != NULL)
		{
			for (int i = 0; i <= 10; i++) {
				//result[i] = result[i] + atoi(row2[i]);
				result[i] = result[i] + atoll(row2[i]);
			}
		}
		mysql_free_result(res2);
	}
	else {
		string sql1 = "select sum(ok), sum(ng1), sum(ng2), sum(ng3), sum(ng4), sum(ng5), sum(ng6), sum(ng7), sum(ng8), sum(ng9), sum(ng10) from summary where detectdate='" + date + "' and hour between " + hour + " and " + end + ";";
		int ret = mysql_query(&mysql, sql1.c_str());
		res1 = mysql_store_result(&mysql);
		row1 = mysql_fetch_row(res1);
		if (row1[0] != NULL)
		{
			for (int i = 0; i <= 10; i++) {
				//result[i] = atoi(row1[i]);
				result[i] = atoll(row1[i]);
			}
		}
		mysql_free_result(res1);
	}

	disconnect();
	return result;

}

bool checkNextMonth(int Year, int Month, int Day) {
	if (Month == 2) {
		if (Day == 28) {
			if (Year % 400 == 0 || (Year % 100 != 0 && Year % 4 == 0)) {
				return false;
			}
			else {
				return true;
			}
		}
	} 
	else if (Day == 30) {
		if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
			return true;
		}
	}
	else if (Day == 31) {
		return true;
	}
	return false;
}

vector<int> getNextDate(int Year, int Month, int Day) {
	vector<int> result;
	int reDay = Day, reMonth = Month, reYear = Year;
	if (checkNextMonth(Year, Month, Day)) {
		reDay = 1;
		if (Month == 12) {
			reMonth = 1;
			reYear += 1;
		}
		else {
			reMonth += 1;
		}
	}
	else {
		reDay += 1;
	}
	vector<int>().swap(result);
	result.push_back(reYear);
	result.push_back(reMonth);
	result.push_back(reDay);
	return result;
}