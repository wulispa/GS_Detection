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
		AfxMessageBox(_T("���ݿ�����ʧ�ܣ�"));
		return false;
	}
	else // MySQL���ӳɹ�������������ݿ�
	{
		mysql_set_character_set(&mysqlCon, "gb2312"); //�����ֽڷ�����ֹ��������.

	}
	return true;
}

bool SQLInterface::Add_Info(DateInfo Info)
{
	// ��ջ�����
	memset(sql, 0, SQL_MAX);

	// C�����ַ������
	int len =snprintf(sql, SQL_MAX, "INSERT INTO info VALUES('%s', '%s', '%s', '%s','%s','%s','%s','%s','%s','%s');"
		, Info.m_RecordNumber.c_str(), Info.m_RecordTime.c_str(), Info.m_BatchNumber.c_str()
		, Info.m_ExpiringDate.c_str(), Info.m_U1.c_str(), Info.m_D1.c_str(), Info.m_U2.c_str(), Info.m_D2.c_str()
		, Info.m_Operators.c_str(), Info.m_Notes.c_str());

	//��� snprintf ���ɵ� SQL ��ѯ�Ƿ���ȷ
	std::cout << "Generated SQL: " << sql << std::endl;

	//��� snprintf �ķ���ֵ��ȷ���������㹻
	if (len>= SQL_MAX) {
		std::cerr << "SQL query is too long!" << std::endl;
	}

	//��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//�ж���ӽ��
	if (ret) {
		//���MySQL ����˭����ô���
		string a;
		a = mysql_error(&mysqlCon);
		//std::cerr << "SQL Error: " << mysql_error(&mysqlCon) << std::endl;
		AfxMessageBox(_T("���ʧ�ܣ�"));
		return false;
	}

	// �ر����ݿ�
	mysql_close(&mysqlCon);

	return true;
}