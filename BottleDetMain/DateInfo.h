#pragma once
#include <iostream>
#include <string>
using namespace std;

class DateInfo
{
public:
	string m_RecordNumber;
	string m_RecordTime;
	string m_BatchNumber;
	string m_ExpiringDate;
	string m_U1;
	string m_D1;
	string m_U2;
	string m_D2;
	string m_Operators;
	string m_Notes;

	DateInfo();
	DateInfo(string RecordNumber, string RecordTime, string BatchNumber, string ExpiringDate
		, string U1, string D1, string U2, string D2, string Operators, string Notes);


};
