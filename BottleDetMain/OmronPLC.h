#pragma once

#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include <string>
#include <vector>


using namespace msclr::interop;

using namespace HslCommunication;
using namespace HslCommunication::Core::Net;
using namespace HslCommunication::ModBus;
using namespace HslCommunication::Serial;
using namespace HslCommunication::Profinet::Omron;

using namespace std;

/************************************************
*   ���ܣ�ŷķ��PLC�ӿ�
*	���ڣ�2023-2-23
************************************************/

ref class OmronPLC
{
public  :
    OmronPLC();
    ~OmronPLC();

public:
    System::String^ m_COM;//ͨѶ�˿ں� COM2
    int baud_Rete;//ͨѶ������ 34800
    System::String^ m_Position; //��д�Ĵ�����ַD120
   //int dataBits;   //����λ8
   // int StopBits;   //ֹͣλ1
   // int send_Num;


public:
    //ŷķ��PLC����
    OmronHostLink m_omron;

    bool OpenFlag;

    //����PLC
    bool ConnectPLC();

    //�����Ƿ񷢿���־
    bool isOpen();

    //��������
    bool SendResult(int send_num);

    //��ȡint ������
    int ReadIntData();

    //�رմ���
    void DisConnectPLC();

    //��ʼ�����ڲ���
    void InitPlcParam(System::String^ m_com, System::String^ Position, int rate);

};
//��������ת������
//System::String^ Trans2String(string str)
//{
//    System::String^ res = marshal_as<System::String^>(str);
//    return res;
//}
