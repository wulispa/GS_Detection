#include "pch.h"
#include "SQLInterface.h"

bool SQLInterface::Connect_MySQL()
{
	mysql_init(&mysqlCon);

	// localhost:��������ַ������ֱ������IP��
	// root:�˺ţ�
	// PassWord:���룻
	// DialogTest:���ݿ�����
	// 3306:����˿�
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "123456", "dateinfo", 3306, NULL, 0))
	{
		string s = mysql_error(&mysqlCon);
		AfxMessageBox(_T("���ݿ�����ʧ�ܣ�"));

		return false;
	}
	else // MySQL���ӳɹ�������������ݿ�
	{
		mysql_set_character_set(&mysqlCon, "gb2312"); //�����ֽڷ�����ֹ��������.

	}
	return true;
}

vector<DateInfo> SQLInterface::Get_All_Info()
{
	vector<DateInfo> Info;

	// C��������ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM info");

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//�жϲ�ѯ���
	if (ret) {
		printf("���ݲ�ѯʧ�ܣ�ʧ��ԭ��%s\n", mysql_error(&mysqlCon));
		return Info;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);

	// ��ȡ��ѯ����һ������
	// ��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);

		Info.push_back(dateinfo);
	}
	return Info;

	// �ͷŽ����
	mysql_free_result(res);
}


vector<DateInfo> SQLInterface::Seek_info1(CString RecordTime)
{
	vector<DateInfo> result;

	Connect_MySQL();

	// C��������ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM info where RecordTime = '%s';", RecordTime);


	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return result;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);

	// ��ȡ��ѯ����һ������
	// ��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);
		result.push_back(dateinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return result;
}

vector<DateInfo> SQLInterface::Seek_info2(CString ExpiringDate)
{
	vector<DateInfo> result;

	Connect_MySQL();


	// C��������ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM info where ExpiringDate = '%s';", ExpiringDate);


	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//�жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return result;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);

	// ��ȡ��ѯ����һ������
	// ��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);
		result.push_back(dateinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return result;
}

vector<DateInfo> SQLInterface::Seek_info3(CString BatchNumber)
{
	vector<DateInfo> result;

	Connect_MySQL();


	// C��������ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM info where BatchNumber = '%s';", BatchNumber);


	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//�жϲ�ѯ���
	if (ret) {
		//AfxMessageBox(_T("��ѯʧ�ܣ�"));
		return result;
	}
	//��ȡ�����
	res = mysql_store_result(&mysqlCon);

	// ��ȡ��ѯ����һ������
	// ��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res)) {
		DateInfo dateinfo = DateInfo(row[0], row[1], row[2], row[3], row[4], row[5],
			row[6], row[7], row[8], row[9]);
		result.push_back(dateinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return result;
}