#include "pch.h"
#include "SQLInterface.h"
#include <string>
#include <afxwin.h>




bool SQLInterface::Connect_MySQL()
{
	mysql_init(&mysqlCon);

	// localhost:服务器地址，可以直接填入IP；
	// root:账号；
	// PassWord:密码；
	// DialogTest:数据库名；
	// 3306:网络端口
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "root", "xmltest", 3306, NULL, 0))
	{
		AfxMessageBox(_T("数据库连接失败！"));
		return false;
	}
	else // MySQL连接成功则继续访问数据库
	{
		mysql_set_character_set(&mysqlCon, "gb2312"); //设置字节符，防止中文乱码.

	}
	return true;
}
void SQLInterface::FreeConnect()
{
	//释放资源
	//mysql_free_result(res);
	mysql_close(&mysqlCon);
	cout << "数据库已释放！" << endl;
}
bool SQLInterface::Add_Info(DateInfo Info)
{
	// 清空缓冲区
	memset(sql, 0, SQL_MAX);

	// C语言字符串组合
	int len =snprintf(sql, SQL_MAX, "INSERT INTO info VALUES('%s', '%s', '%s', '%s','%s','%s','%s','%s','%s','%s');"
		, Info.m_RecordNumber.c_str(), Info.m_RecordTime.c_str(), Info.m_BatchNumber.c_str()
		, Info.m_ExpiringDate.c_str(), Info.m_U1.c_str(), Info.m_D1.c_str(), Info.m_U2.c_str(), Info.m_D2.c_str()
		, Info.m_Operators.c_str(), Info.m_Notes.c_str());

	//检查 snprintf 生成的 SQL 查询是否正确
	std::cout << "Generated SQL: " << sql << std::endl;

	//检查 snprintf 的返回值以确保缓冲区足够
	if (len>= SQL_MAX) {
		std::cerr << "SQL query is too long!" << std::endl;
	}

	//查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));

	//判断添加结果
	if (ret) {
		//检查MySQL 函数谁否调用错误
		string a;
		a = mysql_error(&mysqlCon);
		//std::cerr << "SQL Error: " << mysql_error(&mysqlCon) << std::endl;
		AfxMessageBox(_T("添加失败！"));
		return false;
	}

	// 关闭数据库
	mysql_close(&mysqlCon);

	return true;
}
void SQLInterface::updateDatabase(string sql) {
	// 确保数据库支持 UTF-8

	std::string query = sql;

	if (mysql_query(&mysqlCon, query.c_str()) != 0) {
		std::cerr << "SQL Update Failed: " << mysql_error(&mysqlCon) << std::endl;
	}
	else {
		std::cout << "Update Successful!" << std::endl;
		mysql_query(&mysqlCon, "COMMIT;"); // 提交事务
	}
}


bool SQLInterface::getDatafromDB(std::vector<std::vector<std::string> >& data, std::string sql)
{
	string queryStr = sql;
	if (0 != mysql_query(&mysqlCon, queryStr.c_str())) {
		std::cerr << "MySQL query error: " << mysql_error(&mysqlCon) << std::endl;
		return false;
	}
	auto result = mysql_store_result(&mysqlCon);//获得数据库结果集  
	int row = mysql_num_rows(result);//获得结果集中的行数  
	int field = mysql_num_fields(result);//获得结果集中的列数  

	MYSQL_ROW line = NULL;
	line = mysql_fetch_row(result);
	std::string temp;
	while (NULL != line) {
		std::vector<std::string> linedata;
		for (int i = 0; i < field; i++) {//获取每一行的内容  
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

	mysql_free_result(result);//释放结果集

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
		mysql_query(&mysqlCon, "COMMIT;"); // 提交事务
	}
	return TRUE;
}

string  SQLInterface::getFutureDatetime(int month) {
	// 获取当前时间
	auto now = std::chrono::system_clock::now();

	// 将时间转换为 `time_t` 类型（秒级时间戳）
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// 转换为 `tm` 结构（本地时间）
	std::tm local_tm;
	localtime_s(&local_tm, &now_c);
	// **增加月数**
	local_tm.tm_mon += month;
	if (local_tm.tm_mon >= 12) {  // 跨年处理
		local_tm.tm_year += local_tm.tm_mon / 12;
		local_tm.tm_mon %= 12;
	}

	// 重新转换为 `time_t`
	std::time_t future_time = std::mktime(&local_tm);

	// 格式化 `YYYY-MM-DD HH:MM:SS`
	std::ostringstream oss;

	std::tm future_tm;
	localtime_s(&future_tm, &future_time);
	oss << std::put_time(&future_tm, "%Y-%m-%d %H:%M:%S");

	return oss.str();
}


bool SQLInterface::IsValidPassword(const CString& password) {
	// 检查密码长度
	int length = password.GetLength();
	if (length < 6 || length > 10) {
		return false;
	}
	// 使用正则表达式检查密码只包含字母、数字和符号，并且不包含空格
	std::wregex pattern(L"^[a-zA-Z0-9!@#$%^&*()_+\\-=[\\]{};':\"\\\\|,.<>/?]+$");
	// 使用正则表达式检查密码是否包含字母、数字和符号，并且不包含空格
	//std::wregex pattern(L"^(?=.*[a-zA-Z])(?=.*\\d)(?=.*[!@#$%^&*()_+\\-=[\\]{};':\"\\\\|,.<>/?]).{6,10}$");
	return std::regex_match((LPCTSTR)password, pattern);
}