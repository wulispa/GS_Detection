#include "pch.h"
#include "OmronPLC.h"

OmronPLC::OmronPLC()
{
	m_COM = "COM2";//ͨѶ�˿ں� COM2
	baud_Rete = 38400;//ͨѶ������ 38400
	m_Position = "D120";
}

OmronPLC::~OmronPLC()
{
	if (OpenFlag)
	{
		DisConnectPLC();
	}
}

bool OmronPLC::ConnectPLC()
{
	m_omron.SerialPortInni(m_COM, baud_Rete);
	if (OpenFlag || m_omron.IsOpen()) {
		return true;
	}
	else
	{
		m_omron.Open();
		OpenFlag == true;
	}
	return true;
}

bool OmronPLC::isOpen()
{
	return OpenFlag;
}

bool OmronPLC::SendResult(int send_num)
{
	OperateResult^ res = m_omron.Write(m_Position, send_num);
	if (res->IsSuccess) {
		return true;
	}
	else
	{
		return false;
	}
}

int OmronPLC::ReadIntData()
{
	OperateResult<short>^ r = m_omron.ReadInt16(m_Position);
	if (r->IsSuccess)
	{
		return r->Content;
	}
	else
	{
		return -1;
	}
}

void OmronPLC::DisConnectPLC()
{
	m_omron.Close();
}

void OmronPLC::InitPlcParam(System::String^ m_com, System::String^ Position, int rate)
{
	System::String^ m_COM= m_com;//ͨѶ�˿ں� COM2
	int baud_Rete= rate;//ͨѶ������ 34800
	m_Position = Position;
}
