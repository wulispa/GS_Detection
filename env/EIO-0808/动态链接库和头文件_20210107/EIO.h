#ifndef _PLT_LIB_H
#define _PLT_LIB_H

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

typedef unsigned char  uint8;                   
typedef signed   char  int8;                   
typedef unsigned short uint16;                 
typedef signed   short int16;                  
typedef unsigned int   uint32;                
typedef signed   int   int32; 
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;

       

#define __PLT_EXPORTS

//定义输入和输出
#ifdef __PLT_EXPORTS
	#define PLT_API __declspec(dllexport)
#else
	#define PLT_API __declspec(dllimport)
#endif

//#define PLT_API

#ifdef __cplusplus
extern "C" {
#endif

//控制卡级相关函数	
PLT_API short __stdcall Plt_CardOpen(uint16 TotalCards,uint16 *CardIdArray,uint16 *Section,uint16* Host_id);//初始化控制卡
PLT_API short __stdcall Plt_CardClose(void);	//关闭控制卡

PLT_API short __stdcall Plt_IoACardOpen(uint16 cardid,uint16 Section,uint16 Host_id);
/*功能描述：打开第cardid号运动控制卡
输入参数：  cardid 卡号
            Section IP地址第三段段号
			Host_id IP地址第四段段号
输出参数：无
返回：0或错误码*/
PLT_API short __stdcall Plt_IoACardClose(uint16 cardid);	//关闭控制卡
/*功能描述：关闭第cardid号运动控制卡
输入参数：  cardid 卡号
输出参数：无
返回：0或错误码*/

PLT_API short __stdcall Plt_CardGetVerson(uint16 cardid,DWORD *verson1,DWORD *verson2); //verson1 固件版本号  verson2 库版本号
/*************************************************************************通用输入输出IO**********************************************************/
PLT_API short __stdcall Plt_IoReadInputByBit(uint16 cardid,uint16 bitno,uint16 *active_level); 	//读取输入口的状态
PLT_API short __stdcall Plt_IoWriteOutputByBit(uint16 cardid,uint16 bitno,uint16 active_level); 	//设置输出口的状态
PLT_API short __stdcall Plt_IoReadOutputByBit(uint16 cardid,uint16 bitno,uint16 *active_level);  	//读取输出口的状态
PLT_API short __stdcall Plt_IoReadAllInput(uint16 cardid,DWORD *active_level_1); 	//读取所有通用输入IO的值
PLT_API short __stdcall Plt_IoReadAllOutput(uint16 cardid,DWORD *active_level); 	//读取通用输出端口的值
PLT_API short __stdcall Plt_IoWriteAllOutput(uint16 cardid,DWORD active_level);  	//设置通用输出端口的值
PLT_API short __stdcall Plt_IoReverseOutputBit(uint16 cardid,uint16 bitno,double hold_time); //翻转当前输出口的状态,并保持设定时间后恢复回翻转前的状态
/*************************************************************************通用输入输出IO**********************************************************

/*************************************************************************CAN输入输出IO**********************************************************/
PLT_API short __stdcall Plt_IoSetMasterBaudrate(uint16 cardid,uint16 baudrate);
//*功能描述：设置主站波特率
//  输入参数：card  卡号  
//            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
//  输出参数：无
//*/
PLT_API short __stdcall Plt_IoGetMasterBaudrate(uint16 cardid,uint16 *baudrate);
//*功能描述：设置主站波特率
//  输入参数：card  卡号  
//           
//  输出参数： baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
//*/
PLT_API short __stdcall Plt_IoCanReadInputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level); 	//读取指定can模块输入口的状态
//*功能描述：读取指定can模块输入口的状态
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            bitno IO口号 有效值为[0,15]
//  输出参数：  *active_level 
//*/
PLT_API short __stdcall Plt_IoCanWriteOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 active_level); 	//设置指定can模块输出口的状态
///*功能描述：设置指定can模块输出口的状态
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            bitno IO口号 有效值为[0,15]
//			active_level 输出电平值  0和1
//  输出参数：无
//*/
PLT_API short __stdcall Plt_IoCanReadOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level);  	//读取指定can模块输出口的状态
///*功能描述：读取指定can模块输出口的状态
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            bitno IO口号 有效值为[0,15]
//  输出参数：  *active_level 输出电平值  0和1
//*/
PLT_API short __stdcall Plt_IoCanReadAllInput(uint16 cardid,uint16 can_id,uint32 *active_level_1); 	//读取指定can模块所有通用输入IO的值
///*功能描述：读取指定can模块所有通用输入IO的值
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            bitno IO口号 有效值为[0,15]
//  输出参数：  *active_level  active_level顺序从0到31代表0到15输入IO电平
//*/
PLT_API short __stdcall Plt_IoCanReadAllOutput(uint16 cardid,uint16 can_id,uint32 *active_level); 	//读取指定can模块所有通用输出口的值
///*功能描述：读取指定can模块所有通用输出口的值
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            bitno IO口号 有效值为[0,31]		
//  输出参数：*active_level  active_level顺序从0到31代表0到15输出IO电平
//*/
PLT_API short __stdcall Plt_IoCanWriteAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	//设置指定can模块所有通用输出口的值
///*功能描述：设置指定can模块所有通用输出口的值
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            bitno IO口号 有效值为[0,31]
//			active_level  active_level顺序从0到31代表0到31输出IO电平
//  输出参数：无
//*/
PLT_API short __stdcall Plt_IoCanGetLinkState(uint16 cardid,uint16 can_id,uint16 *link_state);  	//读取指定can模块连接状态
///*功能描述：读取指定can模块连接状态
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//            
//  输出参数：  *link_state 连接状态 1：连接  0：断开
//*/
PLT_API short __stdcall Plt_IoCanReverseOutputBit(uint16 cardid,uint16 can_id,uint16 bitno,double hold_time); //翻转指定can模块当前输出口的状态,并保持设定时间后恢复回翻转前的状态
///*功能描述：/翻转指定can模块当前输出口的状态,并保持设定时间后恢复回翻转前的状态
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15] 
//            bitno IO口号 有效值为[0,15]
//            hold_time：单位是s 
//  输出参数：无
//*/
PLT_API short __stdcall Plt_IoCanInitAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	
///*功能描述：设置指定can模块输出IO初始电平
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//			active_level  active_level顺序从0到31代表0到31输出IO初始电平
//  输出参数：无
//*/
PLT_API short __stdcall Plt_IoCanGetNodeType(uint16 cardid,uint16 can_id,uint16 *type);  	
///*功能描述：设置指定can模块输出IO初始电平
//  输入参数：card  卡号  
//            can_id  can id号:有效值为[0,15]   
//  输出参数：type can模块节点类型  1：rcan1616 2:rcan3232
//*/
/*************************************************************************CAN输入输出IO**********************************************************/
PLT_API short __stdcall Plt_IoReSetIP(uint16 cardid,uint16 section_3,uint16 section_4);//重置IP地址，卡重新上电后起效
PLT_API short __stdcall Plt_IoGetIP(uint16 cardid,uint16 *section_3,uint16 *section_4);//读取IP地址配置
PLT_API short __stdcall Plt_IoSetInitIO(uint16 cardid,uint16 *io_init_value);//重置输出IO初始电平
#ifdef __cplusplus
}
#endif

#endif
