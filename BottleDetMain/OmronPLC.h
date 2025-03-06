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
*   功能：欧姆龙PLC接口
*	日期：2023-2-23
************************************************/

ref class OmronPLC
{
public  :
    OmronPLC();
    ~OmronPLC();

public:
    System::String^ m_COM;//通讯端口号 COM2
    int baud_Rete;//通讯波特率 34800
    System::String^ m_Position; //读写寄存器地址D120
   //int dataBits;   //数据位8
   // int StopBits;   //停止位1
   // int send_Num;


public:
    //欧姆龙PLC对象
    OmronHostLink m_omron;

    bool OpenFlag;

    //链接PLC
    bool ConnectPLC();

    //串口是否发开标志
    bool isOpen();

    //发送数据
    bool SendResult(int send_num);

    //读取int 型数据
    int ReadIntData();

    //关闭串口
    void DisConnectPLC();

    //初始化串口参数
    void InitPlcParam(System::String^ m_com, System::String^ Position, int rate);

};
//定义数据转换函数
//System::String^ Trans2String(string str)
//{
//    System::String^ res = marshal_as<System::String^>(str);
//    return res;
//}
