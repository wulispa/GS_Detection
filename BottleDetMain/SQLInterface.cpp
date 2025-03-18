#include "pch.h"
#include "SQLInterface.h"
#include <string>
#include <afxwin.h>




bool SQLInterface::Connect_MySQL()
{
	mysql_init(&mysqlCon);

	// localhost:��������ַ������ֱ������IP��
	// root:�˺ţ�
	// PassWord:���룻
	// DialogTest:���ݿ�����
	// 3306:����˿�
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "root", "xmltest", 3306, NULL, 0))
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
void SQLInterface::FreeConnect()
{
	//�ͷ���Դ
	//mysql_free_result(res);
	mysql_close(&mysqlCon);
	cout << "���ݿ����ͷţ�" << endl;
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
void SQLInterface::updateDatabase(string sql) {
	// ȷ�����ݿ�֧�� UTF-8

	std::string query = sql;

	if (mysql_query(&mysqlCon, query.c_str()) != 0) {
		std::cerr << "SQL Update Failed: " << mysql_error(&mysqlCon) << std::endl;
	}
	else {
		std::cout << "Update Successful!" << std::endl;
		mysql_query(&mysqlCon, "COMMIT;"); // �ύ����
	}
}


bool SQLInterface::getDatafromDB(std::vector<std::vector<std::string> >& data, std::string sql)
{
	string queryStr = sql;
	if (0 != mysql_query(&mysqlCon, queryStr.c_str())) {
		std::cerr << "MySQL query error: " << mysql_error(&mysqlCon) << std::endl;
		return false;
	}
	auto result = mysql_store_result(&mysqlCon);//������ݿ�����  
	int row = mysql_num_rows(result);//��ý�����е�����  
	int field = mysql_num_fields(result);//��ý�����е�����  

	MYSQL_ROW line = NULL;
	line = mysql_fetch_row(result);
	std::string temp;
	while (NULL != line) {
		std::vector<std::string> linedata;
		for (int i = 0; i < field; i++) {//��ȡÿһ�е�����  
			if (line[i]) {
				temp = line[i];
				linedata.push_back(temp);
			}
			else {
				temp = "NULL";
				linedata.push_back(temp);
			}
		}
		line = mysql_fetch_row(result);
		data.push_back(linedata);
	}

	mysql_free_result(result);//�ͷŽ����

	return true;
}

bool SQLInterface::InsertDB(string sql)
{
	string queryStr = sql;
	if (mysql_query(&mysqlCon, queryStr.c_str()) != 0) {
		string rel = mysql_error(&mysqlCon);
		std::cerr << "SQL Insert Failed: " << mysql_error(&mysqlCon) << std::endl;
	}
	else {
		std::cout << "Insert Successful!" << std::endl;
		mysql_query(&mysqlCon, "COMMIT;"); // �ύ����
	}
	return TRUE;
}

string  SQLInterface::getFutureDatetime(int month) {
	// ��ȡ��ǰʱ��
	auto now = std::chrono::system_clock::now();

	// ��ʱ��ת��Ϊ `time_t` ���ͣ��뼶ʱ�����
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// ת��Ϊ `tm` �ṹ������ʱ�䣩
	std::tm local_tm;
	localtime_s(&local_tm, &now_c);
	// **��������**
	local_tm.tm_mon += month;
	if (local_tm.tm_mon >= 12) {  // ���괦��
		local_tm.tm_year += local_tm.tm_mon / 12;
		local_tm.tm_mon %= 12;
	}

	// ����ת��Ϊ `time_t`
	std::time_t future_time = std::mktime(&local_tm);

	// ��ʽ�� `YYYY-MM-DD HH:MM:SS`
	std::ostringstream oss;

	std::tm future_tm;
	localtime_s(&future_tm, &future_time);
	oss << std::put_time(&future_tm, "%Y-%m-%d %H:%M:%S");

	return oss.str();
}


bool SQLInterface::IsValidPassword(const CString& password) {
	// ������볤��
	int length = password.GetLength();
	if (length < 6 || length > 10) {
		return false;
	}
	// ʹ��������ʽ�������ֻ������ĸ�����ֺͷ��ţ����Ҳ������ո�
	std::wregex pattern(L"^[a-zA-Z0-9!@#$%^&*()_+\\-=[\\]{};':\"\\\\|,.<>/?]+$");
	// ʹ��������ʽ��������Ƿ������ĸ�����ֺͷ��ţ����Ҳ������ո�
	//std::wregex pattern(L"^(?=.*[a-zA-Z])(?=.*\\d)(?=.*[!@#$%^&*()_+\\-=[\\]{};':\"\\\\|,.<>/?]).{6,10}$");
	return std::regex_match((LPCTSTR)password, pattern);
}