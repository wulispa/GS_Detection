#include "pch.h"
#include "DateInfo.h"

DateInfo::DateInfo()
{
}

DateInfo::DateInfo(string RecordNumber, string RecordTime, string BatchNumber, string ExpiringDate,
	string U1, string D1, string U2, string D2, string Operators, string Notes)
{
	m_RecordNumber = RecordNumber;
	m_RecordTime = RecordTime;
	m_BatchNumber = BatchNumber;
	m_ExpiringDate = ExpiringDate;
	m_U1 = U1;
	m_D1 = D1;
	m_U2 = U2;
	m_D2 = D2;
	m_Operators = Operators;
	m_Notes = Notes;
}
