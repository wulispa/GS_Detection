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

#ifdef __cplusplus
extern "C" {
#endif

PLT_API short __stdcall Plt_CardOpen(uint16 TotalCards,uint16 *CardIdArray,uint16 *Section,uint16* Host_id);
/*指令功能：初始化控制卡
输入参数：  TotalCards	卡的数量（打开卡的数量）
	        CardIdArray	卡号数组参数（根据IP地址第四位进行设置），各卡卡号不能重复，数组元素取值范围[0,11]。
	        Section	    IP地址第三段的号码（需与主机PC的地址一致）数组参数，控制卡出厂默认Section为167，数组元素取值范围[1,254]。
	        Host_id	    IP地址第四段的号码（由串口或指令设置）数组参数,控制卡出厂默认Host_id为120。数组元素取值范围[1,254]。
输出参数：	无
返回：      0或错误码*/

PLT_API short __stdcall Plt_CardOpen_extern(uint16 *TotalCards,uint16 *CardTypeArray,uint16 *Section,uint16* Host_id);
/*指令功能：初始化控制卡
输入参数：  Section	      IP地址第三段的号码（需与主机PC的地址一致）数组参数，控制卡出厂默认Section为167，数组元素取值范围[1,254]。
	        Host_id	      IP地址第四段的号码（由串口或指令设置）数组参数,控制卡出厂默认Host_id为120。数组元素取值范围[1,254]。       
输出参数：	TotalCards	  卡的数量
            CardTypeArray 成功打开的卡类型  0:轴卡  1：IO卡
返回：      0或错误码*/

PLT_API short __stdcall Plt_CardOpen_extern_extern(uint16 *TotalCards,uint16 *CardTypeArray,uint16 *Section,uint16* Host_id,uint32 time_out);
/*指令功能：初始化控制卡
输入参数：  Section	      IP地址第三段的号码（需与主机PC的地址一致）数组参数，控制卡出厂默认Section为167，数组元素取值范围[1,254]。
	        Host_id	      IP地址第四段的号码（由串口或指令设置）数组参数,控制卡出厂默认Host_id为120。数组元素取值范围[1,254]。 
			time_out      网络连接超时时间 单位 s
输出参数：	TotalCards	  卡的数量
            CardTypeArray 成功打开的卡类型  0:轴卡  1：IO卡
返回：      0或错误码*/

PLT_API short __stdcall Plt_CardClose(void);	//关闭控制卡
/*指令功能：关闭控制卡
输入参数：  无
输出参数：	无
返回：      0或错误码*/

PLT_API short __stdcall Plt_CardReset(void);
/*指令功能：复位控制卡
输入参数：  无
输出参数：	无
返回：      0或错误码*/

PLT_API short __stdcall Plt_ACardOpen(uint16 cardid,uint16 Section,uint16 Host_id);
/*指令功能：初始化一个控制卡
输入参数：  cardid	卡号，取值范围[0,11]。
	        Section	IP地址第三段的号码（需与主机PC的地址一致），控制卡出厂默认Section为167，取值范围[1,254]。
	        Host_id	IP地址第四段的号码（由串口或指令设置）控制卡出厂默认Host_id为120，取值范围[1,254]。
输出参数：	无
返回：      0或错误码*/

PLT_API short __stdcall Plt_ACardOpen_extern(uint16 cardid,uint16 Section,uint16 Host_id,uint32 time_out);
/*指令功能：初始化一个控制卡
输入参数：  cardid	卡号，取值范围[0,11]。
	        Section	IP地址第三段的号码（需与主机PC的地址一致），控制卡出厂默认Section为167，取值范围[1,254]。
	        Host_id	IP地址第四段的号码（由串口或指令设置）控制卡出厂默认Host_id为120，取值范围[1,254]。
			time_out 网络连接超时时间 单位 ms
输出参数：	无
返回：      0或错误码*/

PLT_API short __stdcall Plt_ACardClose(uint16 cardid);	//关闭控制卡
/*指令功能：关闭一个控制卡
输入参数： cardid	卡号，取值范围[0,11]。
输出参数： 无
返回：0或错误码*/
PLT_API short __stdcall Plt_CardGetVerson(uint16 cardid,DWORD *verson1,DWORD *verson2,DWORD *verson3); 
/*指令功能：读取相关版本号
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	*verson1	FPGA版本号
	        *verson2	固件版本号
			*verson3	动态链接库版本号
返回：      0或错误码*/
PLT_API short __stdcall Plt_GetCardSerialNum(uint16 cardid,DWORD *SerialNum_0,DWORD *SerialNum_1,DWORD *SerialNum_2); 
/*指令功能：读取控制卡96位序列号
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	SerialNum_0	序列号0-31位
	        SerialNum_1	序列号32-63位
			SerialNum_2	序列号64-95位
返回：      0或错误码*/
PLT_API short __stdcall Plt_CardUpdataFirmare(uint16 cardid,const char *filename);
/*指令功能：控制卡固件更新
输入参数：  cardid	卡号，取值范围[0,11]。
	        *filename	新固件绝对路径。 注意：路径中不能有中文字符
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CardReadCommincationState(uint16 cardid,uint16 *state);	
/*指令功能：读取PC机和运动控制卡连接状态
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	*state	PC机和运动控制卡连接状态 1：连接  0：断开
返回：      0或错误码*/
PLT_API short __stdcall Plt_CardGetCardAxisNum(uint16 cardid,uint16 *axisnum);
/*指令功能：读取卡的轴数
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：  *axisnum	控制卡的轴数
返回：      0或错误码*/
PLT_API short __stdcall Plt_CardParmsFileConfig(uint16 cardid,const char *ParmsFile);
/*指令功能：配置运动控制卡
输入参数：  cardid	卡号，取值范围[0,11]。
	        *ParmsFile	配置文件 注意：路径必须是绝对路径，且路径中不能出现中文字符
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall PLT_GCodeFileProcess(uint16 cardid,const char* FileName);

PLT_API short __stdcall Plt_CardReSetIP(uint16 cardid,uint16 section_3,uint16 section_4);
/*指令功能：设置控制卡IP地址
输入参数：  cardid	    卡号，取值范围[0,11]。
	        section_3	IP地址第三段值（需与主机PC的地址一致）控制卡出厂默认Section为167，取值范围[1,254]。
			section_4   IP地址第四段值（需与主机PC的地址一致）控制卡出厂默认Section为120，取值范围[1,254]。
输出参数：	无
    说明：	新设置的IP地址在控制卡重新上电后起效
返回：      0或错误码*/
PLT_API short __stdcall Plt_CardGetIP(uint16 cardid,uint16 *section_3,uint16 *section_4);//读取IP地址配置
/*指令功能：回读控制卡设置的IP地址
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	*section_3	IP地址第三段值，控制卡出厂默认Section为167
            *section_4	IP地址第四段值，控制卡出厂默认Section为120
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetPulseOutMode(uint16 cardid,uint16 axis,uint16 mode);	
/*指令功能：设定脉冲输出模式
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			mode	    脉冲输出模式，取值范围：0、2、4、6。各种脉冲模式的具体波形参考编程手册“3.4脉冲模式”一节
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetPulseOutMode(uint16 cardid,uint16 axis,uint16 *mode);	//读取脉冲输出模式
/*指令功能：读取脉冲输出模式
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*mode	    脉冲输出模式，取值范围：0、2、4、6。各种脉冲模式的具体波形参考编程手册“3.4脉冲模式”一节
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetEncoderInMode(uint16 cardid,uint16 axis,uint16 mode);  
/*指令功能：设定编码器输入计数模式
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			mode	    编码器输入计数模式  取值范围:[0,3]  0：脉冲+方向   1：1倍频 2:2倍频  3:4倍频
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetEncoderInMode(uint16 cardid,uint16 axis,uint16 *mode); 
/*指令功能：读取编码器输入计数模式
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*mode	    编码器输入计数模式
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetEncoderInNegation(uint16 cardid,uint16 axis,uint16 mode);  
/*指令功能：设定编码器计数方向
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			mode	    编码器计数方向  取值范围:[0,1]  0：EA超前EB正计数   1：EA超前EB负计数
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetEncoderInNegation(uint16 cardid,uint16 axis,uint16 *mode); 
/*指令功能：读取编码器计数方向
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*mode	   编码器计数方向
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetPPU(uint16 cardid,uint16 axis, double PPU);
/*指令功能：设定脉冲当量
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			PPU	脉冲当量值（用户单位对应的脉冲数）
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetPPU(uint16 cardid,uint16 axis, double *PPU);
/*指令功能：读取脉冲当量
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*PPU	    脉冲当量值（用户单位对应的脉冲数）
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetBacklash(uint16 card,uint16 axis,double backlash);
/*指令功能：设置反向间隙参数
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			backlash	反向间隙值，单位：脉冲当量单位 PPU
输出参数：	无
返回：      0或错误码*/

PLT_API short __stdcall Plt_AXGetBacklash(uint16 cardid,uint16 axis,double *backlash);
/*指令功能：查询反向间隙参数
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*backlash	反向间隙值
返回：      0或错误码*/

PLT_API short __stdcall Plt_AxSetLimitSpeed(uint16 cardid,uint16 axis,double speed);
/*指令功能：设置轴的极限速度
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			speed	    轴的极限速度 ，单位：ppu/s
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetLimitSpeed(uint16 cardid,uint16 axis,double *speed);
/*指令功能：读取轴的极限速度
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*speed	    轴的极限速度 ，单位：ppu/s
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetLimitAcc(uint16 cardid,uint16 axis,double acc);
/*指令功能：设置轴的极限加速度
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			acc	        轴的极限加速度
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetLimitAcc(uint16 cardid,uint16 axis,double *acc);
/*指令功能：读取轴的极限加速度
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*acc	    轴的极限加速度
返回：      0或错误码*/

PLT_API short __stdcall Plt_AxSetCmmandPosition(uint16 cardid, uint16 axis, double pos);
/*指令功能：设置轴的指令位置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			pos	        指令位置值
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetCmmandPosition(uint16 cardid,uint16 axis, double * pos);
/*指令功能：查询轴的指令位置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*pos	    指令位置值
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetEncoderPosition(uint16 cardid,uint16 axis, double pos);
/*指令功能：设置编码器位置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			pos	        编码器设定值
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetEncoderPosition(uint16 cardid,uint16 axis, double * pos);
/*指令功能：读取编码器位置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*pos	    编码器位置
返回：      0或错误码*/

PLT_API short __stdcall Plt_AxSetBand(uint16 cardid,uint16 axis,double band,uint32 hold_time,uint32 check_time);
/*指令功能：设置轴到位误差带
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			band	    误差带，单位：PPU
			hold_time	编码器位置进入误差带最小保持时间 单位：ms
			check_time	轴到位最大检测时间 单位：ms
输出参数：	无
说明：      1、到位判断逻辑，如果编码器与目标位置的差值小于误差带，且持续时间大于最小保持时间，则判断定位完成
            2、如果在最大检测时间之内没有满足“到位判断逻辑”，则判断定位失败
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetBand(uint16 cardid,uint16 axis,double *band,uint32 *hold_time,uint32 *check_time);
/*指令功能：查询轴到位误差配置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*band	误差带，单位：PPU
            *hold_time	编码器位置进入误差带最小保持时间 单位：ms
			*check_time	轴到位最大检测时间 单位：ms
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetBandFlag(uint16 cardid,uint16 axis,uint16 *band_flag);
/*指令功能：读取单轴误差带标志
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*band_flag	0：定位中
                        1：定位完成
                        2：定位失败
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetBandLocationTime(uint16 cardid,uint16 axis,uint32 *location_time);
/*指令功能：读取误差带定位时间
输入参数：  cardid	    卡号，取值范围[0,11]。
            axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：  *location_time  当前延时时间（从脉冲发送完成开始计算）                 单位：ms
返回：      0或错误码*/

PLT_API short __stdcall Plt_AxCheckEncoderDirResever(uint16 cardid,uint16 axis,uint32 hold_time);
/*指令功能：检查编码器运动方向是否与脉冲方向相反
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			hold_time	方向相反保持时间 单位：ms,
                        如果hold_time设置为0 则屏蔽此功能
                        如果hold_time设置为非0，如果运动持续Hold_time时间后，编码器与脉冲方向还是相反的，则自动进行减速停止，并报警，报警代码25
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetCheckEncoderDirResever(uint16 cardid,uint16 axis,uint32 *hold_time);
/*指令功能：检查编码器运动方向是否与脉冲方向相反的参数查询
输入参数：  cardid	    卡号，取值范围[0,11]。
            axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：  *hold_time	方向相反保持时间 单位：ms
返回：      0或错误码*/
/*************************************************************************安全保护***************************************************************/
typedef struct
{
  uint16 pel_enable;//正限位使能；0：正限位禁止；1：正限位使能
  uint16 mel_enable;//负限位使能；0：负限位禁止；1：负限位使能
  uint16 pel_active_level;//正限位有效电平；0：低电平有效；1：高电平有效
  uint16 mel_active_level;//负限位有效电平；0：低电平有效；1：高电平有效
  uint16 pel_react;//正限位有效停止方式；0：立即停止；1：减速停止
  uint16 mel_react;//正限位有效停止方式；0：立即停止；1：减速停止
}struct_el_parms; //硬限位参数结构体

typedef struct
{ 
  double melpos;//负软限位位置，单位:[ppu]
  double pelpos;//正软限位位置，单位:[ppu]
  uint16 enable;//软限位使能；0：软限位禁止；1：负限位使能
  uint16 react;//软限位有效停止方式；0：立即停止；1：减速停止
}struct_sw_el_parms;//软限位参数结构体

PLT_API short __stdcall Plt_AxSetEl(uint16 cardid,uint16 axis,struct_el_parms elparms); 
/*指令功能：设置硬件限位
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			elparms	    硬限位参数
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetEl(uint16 cardid,uint16 axis,struct_el_parms *elparms); 
/*指令功能：读取硬件限位的设置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*elparms	硬限位参数
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetSWEL(uint16 cardid,uint16 axis,struct_sw_el_parms swelparms);
/*指令功能：设置软件限位
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			swelparms	软件限位参数
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetSWEL(uint16 cardid,uint16 axis,struct_sw_el_parms *swelparms);
/*指令功能：读取软件限位的设置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*swelparms	软件限位参数
返回：      0或错误码*/
/*************************************************************************安全保护***************************************************************/

/*************************************************************************专用接口***************************************************************/
typedef struct
{
  uint16 emg_enable;//emg使能开关；0：使能禁止 1：使能有效
  uint16 emg_level;//emg有效电平；0：低电平有效；1：高电平有效
  uint16 emg_port;//映射为EMG的输入IO口 取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
  uint16 alm_enable;//alm使能开关；0：使能禁止 1：使能有效
  uint16 alm_level;//alm有效电平；0：低电平有效；1：高电平有效
  double filter_time;//输入信号滤波时间；单位[ms]
  uint16 inp_enable;//inp使能开关；0：使能禁止 1：使能有效
  uint16 inp_level;//inp有效电平；0：低电平有效；1：高电平有效
}struct_special_input_parms;//

typedef struct
{
  uint16 alm_status;//alm状态；0:无效；1：有效
  uint16 el_pos_status;//正限位状态；0:无效；1：有效
  uint16 el_neg_status;//负限位状态；0:无效；1：有效
  uint16 swel_pos_status;//正软限位状态；0:无效；1：有效
  uint16 swel_neg_status;//负软限位状态；0:无效；1：有效
  uint16 emg_status;//emg状态；0:无效；1：有效
  uint16 home_status;//原点状态；0:无效；1：有效
  uint16 inp_status;//inp状态；0:无效；1：有效
  uint16 ez_status;//ez状态；0:无效；1：有效
  uint16 rdy_status;//rdy状态；0:无效；1：有效
}struct_special_input_status;//专用输入状态
PLT_API short __stdcall Plt_AxConfigSpecialInputParms(uint16 cardid,uint16 axis,struct_special_input_parms specinput);
/*指令功能：配置EMG\ERC\INP\ALM等信号和滤波时间
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			specinput	专用输入配置
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxReadSpecialInputParms(uint16 cardid,uint16 axis,struct_special_input_parms *specinput);
/*指令功能：读取EMG\ERC\INP\ALM等信号和滤波时间的配置
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*specinput	专用输入配置
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxReadSpecialInputStatus(uint16 cardid,uint16 axis,struct_special_input_status *inputstatus);
/*指令功能：读取轴专用输入信号状态
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*inputstatus	专用输入状态
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetsvonPort(uint16 cardid,uint16 axis,uint16 active_level); 	
/*指令功能：输出SEVON信号
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			active_level	SERV-ON输出电平值 0:低电平 1：高电平
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetsvonPort(uint16 cardid,uint16 axis,uint16 *active_level);
/*指令功能：获取SEVON信号
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*active_level	SERV-ON输出电平值 0:低电平 1：高电平
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetRdyPort(uint16 cardid,uint16 axis,uint16 *active_level);
/*指令功能：获取RDY信号（此函数保留）
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*active_level	RDY信号输入值 0:低电平 1：高电平
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetErcPort(uint16 cardid,uint16 axis,uint16 active_level);
/*指令功能：控制ERC信号输出电平
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			active_level	ERC信号输出值	0:低电平 1：高电平
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetErcPort(uint16 cardid,uint16 axis,uint16 *active_level);
/*指令功能：获取控制ERC信号输出电平
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*active_level	ERC信号输出值 0:低电平 1：高电平
返回：      0或错误码*/
/*************************************************************************专用接口***************************************************************/

/*************************************************************************输入IO复用功能*********************************************************/
typedef struct
{ 
  uint16 type;//0：正限位 1：负限位 2：原点 3：伺服报警  4：伺服准备 5：伺服到位 6:通用输入IO
  uint16 axis;//轴号.EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];type 小于6时此参数有效
  uint16 bitno;//通用输入IO序号，EI400\EI400S:[0,31]，EI800\EIC00:[0,15];type等于6时此参数有效
  double Filter;//滤波时间，单位[ms]
}struct_original_type;//原始输入IO类型
typedef struct
{
   uint16 axis;//轴号,EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
   uint16 type;//0：正限位 1：负限位 2：原点 3：急停  4：减速停止 5：伺服报警 6:伺服准备 7:伺服到位
}struct_reuse_type;//复用输入IO类型
PLT_API short __stdcall PLT_IoSet_input_reuse_to_special_input(uint16 cardid,struct_original_type original_type,struct_reuse_type reuse_type);
/*指令功能：通用输入IO或者专用输入IO复用为专用输入IO
输入参数：  cardid	    卡号，取值范围[0,11]。
            original_type 被复用的通用输入IO序号或者专用输入IO参数
            reuse_type    复用后的专用输入IO参数
输出参数：无
返回：      0或错误码*/
PLT_API short __stdcall PLT_IoSet_special_input_reuse_to_input_extern(uint16 cardid,struct_original_type original_type,uint16 bitno);
/*功能描述：专用输入IO复用为通用输入IO
输入参数：  cardid	    卡号，取值范围[0,11]。
            original_type 专用输入IO类型
			bitno 复用后IO编号     EI400\EI400S取值范围:[0,23];
                                   EI800取值范围:[0,47];
                                   EIC00取值范围:[0,71];
输出参数：无
返回：      0或错误码*/
PLT_API short __stdcall PLT_IoGet_special_input_reuse(uint16 cardid,struct_reuse_type reuse_type,struct_original_type *original_type);
/*指令功能：读取轴专用输入IO复用配置
输入参数：  cardid	    卡号，取值范围[0,11]。
            reuse_type复用输入IO类型
输出参数：  original_type  原始输入IO类型
返回：      0或错误码*/
PLT_API short __stdcall PLT_IoGet_input_extern_reuse(uint16 cardid,uint16 bitno,struct_original_type *original_type);
/*指令功能：读取扩展输入IO复用配置
输入参数：  cardid	    卡号，取值范围[0,11]。
            bitno       EI400\EI400S取值范围:[0,23];
                        EI800取值范围:[0,47];
                        EIC00取值范围:[0,71];
输出参数：  *original_type 原始输入IO类型
返回：      0或错误码*/
PLT_API short __stdcall PLT_IoRead_input_reuse_bybit(uint16 cardid,uint16 bitno,uint16 *active_level);
/*指令功能：读取复用输入IO状态
输入参数：  cardid	    卡号，取值范围[0,11]。
            bitno       EI400\EI400S取值范围:[0,23];
                        EI800取值范围:[0,47];
                        EIC00取值范围:[0,71];
输出参数：  *active_level 复用输入IO的值
返回：      0或错误码*/
/*************************************************************************输入IO复用功能*****************************************************/


/*************************************************************************通用输入输出IO**********************************************************/
PLT_API short __stdcall Plt_IoReadInputByBit(uint16 cardid,uint16 bitno,uint16 *active_level); 	
/*指令功能：读取输入口的状态
输入参数：  cardid	    卡号，取值范围[0,11]。
            bitno       输入口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
输出参数：  *active_level 输入口状态 0：低电平  1：高电平
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoWriteOutputByBit(uint16 cardid,uint16 bitno,uint16 active_level); 	
/*指令功能：设置输出口的状态
输入参数：  cardid	    卡号，取值范围[0,11]。
            bitno       输出口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			active_level 输出口输出状态 0：低电平  1：高电平
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoReadOutputByBit(uint16 cardid,uint16 bitno,uint16 *active_level);  	
/*指令功能：读取输出口的状态
输入参数：  cardid	    卡号，取值范围[0,11]。
            bitno       输出口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
输出参数：  *active_level 输出口状态 0：低电平  1：高电平
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoReadAllInput(uint16 cardid,DWORD *active_level_1,DWORD *active_level_2); 
/*指令功能：读取输入端口的值
输入参数：  cardid	    卡号，取值范围[0,11]。
输出参数：  *active_level_1	输入口0--31的状态, bit0对应IN0，bit31对应IN31
                            EI400\EI400S: bit0-bit31位都有效；
                            EI800\EIC00: bit0-bit15位有效；
			*active_level_2	输入口32--63的状态, bit0对应IN32，bit31对应IN63（保留）
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoReadAllOutput(uint16 cardid,DWORD *active_level); 	
/*指令功能：读取输出端口的值
输入参数：  cardid	                卡号，取值范围[0,11]。
输出参数：  *active_level           所有输出口0--31的状态, bit0对应OUT0，bit31对应OUT31
                                    EI400\EI400S: bit0-bit31位都有效；
                                   EI800\EIC00: bit0-bit15位有效；
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoWriteAllOutput(uint16 cardid,DWORD active_level);  	//设置通用输出端口的值
/*指令功能：设置输出端口的值
输入参数：  cardid	                卡号，取值范围[0,11]。
           active_level	            所有输出口的输出状态, bit0对应OUT0，bit31对应OUT31
                                    EI400\EI400S: bit0-bit31位都有效；
                                    EI800\EIC00: bit0-bit15位有效；
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoReverseOutputBit(uint16 cardid,uint16 bitno,double hold_time); 
/*指令功能：翻转当前输出口的状态,并保持设定时间后恢复回翻转前的状态
输入参数：  cardid	                卡号，取值范围[0,11]。
            bitno       输出口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			hold_time	电平保持时间，单位：ms
输出参数：  无
返回：      0或错误码*/ 
PLT_API short __stdcall Plt_IoInitOutputBit(uint16 cardid);
/*指令功能：把当前输出IO初始电平设置下次控制器上电后输出IO的初始电平（各通用输出IO初始电平由控制卡当前通用输出IO电平决定，函数不用设置控制卡重新上电生效）
输入参数：  cardid	                卡号，取值范围[0,11]。
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoInitALLOutput(uint16 cardid,DWORD active_level); 
/*指令功能：设置输出IO初始电平（各通用输出IO初始电平由此函数设置，控制卡重新上电生效）
输入参数：  cardid	                卡号，取值范围[0,11]。
            active_level	所有输出口0--31的状态, bit0对应OUT0，bit31对应OUT31
            EI400\EI400S: bit0-bit31位都有效；
            EI800\EIC00: bit0-bit15位有效；
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoSetOutputMap(uint16 cardid,uint16 logic_output_num,uint16 physical_out_num); 
/*指令功能：设置通用输出IO映射
输入参数：  cardid 卡号，取值范围:[0,11]。
            logic_output_num 逻辑输出IO口序号
            physical_out_num 实际输出的板卡物理IO口序号
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoGetOutputMap(uint16 cardid,uint16 logic_output_num,uint16 *physical_out_num); 
/*指令功能：查询通用输出IO映射
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *logic_output_num 逻辑输出IO口序号
            *physical_out_num 实际输出的板卡物理IO口序号
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoSetNegation(uint16 cardid,uint32 output_negation,uint32 input_negation); 
/*指令功能：设置本地IO取反
输入参数：  cardid 卡号，取值范围:[0,11]。
            output_negation	输出口0—31位是否取反,0：不取反 1：取反
                            bit0对应IN0，bit31对应IN31
                            EI400\EI400S: bit0-bit31位都有效；
                            EI800\EIC00: bit0-bit15位有效；
            input_negation	输入口0—31位是否取反,0：不取反 1：取反
                            bit0对应IN0，bit31对应IN31
                            EI400\EI400S: bit0-bit31位都有效；
                            EI800\EIC00: bit0-bit15位有效；
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_IoGetNegation(uint16 cardid,uint32 *output_negation,uint32 *input_negation); 
/*指令功能：回读本地IO取反设置
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *output_negation	输出口0—31位是否取反,0：不取反 1：取反
                            bit0对应IN0，bit31对应IN31
                            EI400\EI400S: bit0-bit31位都有效；
                            EI800\EIC00: bit0-bit15位有效；
            *input_negation	输入口0—31位是否取反,0：不取反 1：取反
                            bit0对应IN0，bit31对应IN31
                            EI400\EI400S: bit0-bit31位都有效；
                            EI800\EIC00: bit0-bit15位有效；
返回：      0或错误码*/

/*指令功能：连续输出设定个数脉冲
输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
			pulse_num      输出脉冲个数：
			hold_time      输出脉冲低电平/高电平时间 单位 us
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall  Plt_IoOutputPulses(uint16 cardid,uint32 pulse_num,uint32 hold_time);
/*指令功能：停止连续输出设定个数脉冲
输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall  Plt_IoOutputPulsesStop(uint16 cardid);

PLT_API short __stdcall  Plt_Io_set_check_input_for_output(uint16 cardid,uint16 input_id,uint16 enable_flag,uint16 input_logic,uint16 output_id,uint16 output_logic);
/*指令功能：设置等待到某个输入IO设定的输入电平时，特定的输出IO输出设置的电平
输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
            input_id: 输入IO序号[0,7]
			enable_flag: 1:开启此功能  0：关闭此功能
			input_logic：等待的输入IO电平
			output_id：输出IO序号[0,7]
			output_logic：输出电平
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall  Plt_Io_get_check_input_for_output(uint16 cardid,uint16 input_id,uint16 *enable_flag,uint16 *input_logic,uint16 *output_id,uint16 *output_logic);
/*指令功能：读取等待到某个输入IO设定的输入电平时，特定的输出IO输出设置的电平
输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
            input_id: 输入IO序号[0,7]
输出参数：  enable_flag: 1:开启此功能  0：关闭此功能
			input_logic：等待的输入IO电平
			output_id：输出IO序号[0,7]
			output_logic：输出电平
返回：      0或错误码*/
/***********************************************连续输出设定个数脉冲*****************************************/
/*************************************************************************通用输入输出IO**********************************************************/

/*************************************************************************一维位置比较功能*********************************************************/
typedef struct
{
  uint16 cmp_axis;//比较轴号,EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
  uint16 enable;//比较使能开关；0：比较禁止；1：比较允许
  uint16 cmp_source;//比较源 0：理论位置 1：编码器位置
}struct_axis_compare_parms;//单轴位置比较配置参数结构体

typedef struct
{
  double cmpposition; //比较位置，单位：[pulse]
  uint16 cmpmethod; //比较方法：0：大于等于；1：小于等于
  uint16 reaction;//比较动作;0：设定io号电平取反；1：设定io号输出低电平；2：设定IO号输出高电平；3：设定io号输出设定时间宽度的脉冲；4：设定轴减速停止；5：设定轴立即停止
  double pulsewidth;//脉冲宽度；单位：[ms]
  uint16 react_object;//设定io号或者设定轴
}struct_axis_compare_datas;//单轴比较缓冲区数据

PLT_API short __stdcall Plt_AxCompareSetParms(uint16 cardid,uint16 cmpno,struct_axis_compare_parms axcmpparms);
/*指令功能：配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
            axcmpparms	一维位置比较配置参数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCompareGetParms(uint16 cardid,uint16 cmpno,struct_axis_compare_parms *axcmpparms);	
/*指令功能：读取配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
输出参数：  *axcmpparms	一维位置比较配置参数
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCompareClearBuf(uint16 cardid,uint16 cmpno); 	
/*指令功能：清除比较器所有比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCompareSetData(uint16 cardid,uint16 cmpno,struct_axis_compare_datas axcmpdata);
/*指令功能：添加比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
            axcmpdata	比较位置参数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCompareGetData(uint16 cardid,uint16 cmpno,double *cmpposition); 	//读取当前比较点
/*指令功能：读取当前比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
            *cmpposition	返回下一个即将进行的比较点
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCompareGetComparedDataNum(uint16 cardid,uint16 cmpno,long *num); 
/*指令功能：查询已经比较过的点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
            *num	已经进行了比较的位置个数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCompareGetBufRemain(uint16 cardid,uint16 cmpno,long *space); 
/*指令功能：查询可以加入的比较点数量
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号 取值范围：[0,11]
            *space	剩余比较空间
输出参数：  无
返回：      0或错误码*/
/*************************************************************************一维位置比较功能*********************************************************/

/*************************************************************************二维位置比较功能*********************************************************/
typedef struct
{
  uint16 axis_array[2];//比较轴列表 取值范围：EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7]; EIC00取值范围:[0,11];
  double cmpposition_array[2];//比较位置列表
  uint16 cmpmethod_array[2];//比较方法：0：大于等于；1：小于等于
  uint16 reaction;//比较动作;0：设定io号电平取反；1：设定io号输出低电平；2：设定IO号输出高电平；3：设定io号输出设定时间宽度的脉冲；4：设定轴减速停止；5：设定轴立即停止
  double pulsewidth;//脉冲宽度；单位：[ms]
  uint16 react_object;//设定io号或者设定轴
}struct_crd_compare_datas;//二维比较缓冲区数据
PLT_API short __stdcall Plt_CrdcCompareSetParms(uint16 cardid,uint16 enable, uint16 cmp_source); 	
/*指令功能：配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
            enable	二维比较是否使能  1：使能 0：禁止
            cmp_source 比较源 0：脉冲计数 1：编码器计数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdcCompareGetParms(uint16 cardid,uint16 *enable, uint16 *cmp_source);
/*指令功能：读取配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *enable	二维比较是否使能  1：使能 0：禁止
            *cmp_source 比较源 0：脉冲计数 1：编码器计数
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdCompareClearBuf(uint16 cardid); 
/*指令功能：清除所有比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdCompareSetData(uint16 cardid,struct_crd_compare_datas crdcmpdata);
/*指令功能：添加比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            crdcmpdata 比较点参数结构体
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdCompareGetData(uint16 cardid,uint16* axis_array,double *cmpposition_array); 
/*指令功能：读取当前比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *axis_array 比较轴列表
            *cmpposition_array 比较位置列表
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdCompareGetComparedDataNum(uint16 cardid,long *num);
/*指令功能：/查询已经比较点数量
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *num 已比较点数量
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdCompareGetBufRemain(uint16 cardid,long *space); 	//查询可以加入的比较点数量
/*指令功能：/查询剩余比较缓冲区
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *space 剩余比较缓冲区大小
返回：      0或错误码*/
/*************************************************************************二维位置比较功能*********************************************************/

/*************************************************************************一维精确位置比较功能*********************************************************/
typedef struct
{
  uint16 cmp_axis;//比较轴号 EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
  uint16 enable;//比较使能开关；0;比较禁止；1：比较允许；
  uint16 cmpmethod;//比较方法：0：等于；1：小于; 2：大于 3:缓冲区比较方法(绝对位置模式) 4：线性比较法 5：:缓冲区比较方法(相对位置模式)
  uint16 cmp_source;//比较源 0：理论位置 1：编码器位置
  uint16 active_level;//有效电平；0：低电平有效；1：高电平有效
  double pulsewidth;//脉冲宽度；单位：【ms】;此参数只有在cmpmethod大于等于3情况下有效
  double liner_distance;//线性位置比较增量值 单位：PPU
  uint32 liner_num;//线性位置比较数
}struct_axis_accurate_compare_parms;//精确位置比较
PLT_API short __stdcall Plt_AxAccurateCompareSetParms(uint16 cardid,uint16 queueno,struct_axis_accurate_compare_parms acccmpparms);
/*指令功能：配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
            queueno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
            acccmpparms	一维高速位置比较配置参数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareGetParms(uint16 cardid,uint16 queueno,struct_axis_accurate_compare_parms *acccmpparms);
/*指令功能：读取配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
            queueno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
输出参数：  *acccmpparms	一维高速位置比较配置参数
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareClearBuf(uint16 cardid,uint16 cmpno);
/*指令功能：清除比较器所有比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareSetData(uint16 cardid,uint16 cmpno,uint16 axis,double cmpposition);
/*指令功能：添加比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
            cmpposition	比较位置
			axis	保留参数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareGetData(uint16 cardid,uint16 cmpno,uint16 axis,double *cmpposition);
/*指令功能：读取当前比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
			axis	保留参数
输出参数：  *cmpposition	比较位置
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareGetComparedDataNum(uint16 cardid,uint16 cmpno,long *num); 	
/*指令功能：查询已经比较过的点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
输出参数：  *num	返回已经进行了比较的位置数量
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareGetBufRemain(uint16 cardid,uint16 cmpno,long *space); 
/*指令功能：查询可以加入的比较点数量(线性比较模式下space返回剩余的比较点数)
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
输出参数：  *num	返回已经进行了比较的位置数量
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareGetRemainPoints(uint16 cardid,uint16 cmpno,long *remain_points); 
/*指令功能：查询还有几个比较点还没有进行比较
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
输出参数：  *remain_points	还有几个比较点还没有进行比较
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareOutputMapSet(uint16 cardid,uint16 axis_id,uint16 enable);
/*指令功能：第10轴或第11轴映射为高速输出口
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis_id      轴号，取值范围：10或11
            enable	1:轴脉冲输出口映射为高速输出口 0：轴脉冲输出恢复为脉冲输出口
  输出参数：无
  返回参数：错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareOutputMapGet(uint16 cardid,uint16 axis_id,uint16 *enable); 
/*指令功能：读取第10轴或第11轴映射是否映射为高速输出口
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis_id     轴号，取值范围：10或11       
  输出参数：*enable	1:轴脉冲输出口映射为高速输出口 0：轴脉冲输出恢复为脉冲输出口
  返回参数：错误码*/
PLT_API short __stdcall Plt_AxAccurateCompareSetMultiData(uint16 cardid,uint16 cmpno,uint16 data_num,double *cmpposition);
/*指令功能：高速比较添加多个比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
			data_num	添加的比较点个数 取值范围：[1,127]
            *cmpposition 	比较点位置数组  单位：ppu
输出参数：  无
返回：      0或错误码*/
/*************************************************************************高速位置比较功能*********************************************************/

/*************************************************************************二维精确位置比较功能*********************************************************/
typedef struct
{
  uint16 axis_array[2];//比较轴列。EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7]; EIC00取值范围:[0,11];
  uint16 enable;//比较使能开关；0;比较禁止；1：比较允许；
  uint16 cmpmethod;//保留值
  uint16 cmp_source;//比较源 0：理论位置 1：编码器位置
  uint16 active_level;//输出有效电平；0：低电平有效；1：高电平有效
  double pulsewidth;//脉冲宽度；单位：【ms】;
  double cmp_error;//精度；单位[pulse]
}struct_crd_accurate_compare_parms;//精确位置比较
PLT_API short __stdcall Plt_CrdAccurateCompareSetParms(uint16 cardid,struct_crd_accurate_compare_parms acccmpparms);
/*指令功能：配置比较器
输入参数：  cardid 卡号，取值范围:[0,11]。
            acccmpparms 高速二维比较配置参数结构体
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetParms(uint16 cardid,struct_crd_accurate_compare_parms *acccmpparms);
/*指令功能：读取比较器配置
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *acccmpparms 高速二维比较配置参数结构体
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateCompareClearBuf(uint16 cardid);
/*指令功能：清除比较器所有比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateCompareSetData(uint16 cardid,double *cmpposition_array);
/*指令功能：添加比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
            *cmpposition_array	比较位置列表
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetData(uint16 cardid,double *cmpposition_array);
/*指令功能：读取当前比较点
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *cmpposition_array	比较位置列表
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetComparedDataNum(uint16 cardid,long *num); 
/*指令功能：查询已经比较过的点
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *num	已经进行了比较的位置数量
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetBufRemain(uint16 cardid,long *space); 	
/*指令功能：查询可以加入的比较点数量
输入参数：  cardid 卡号，取值范围:[0,11]。
输出参数：  *space	剩余比较空间
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateConfigOutBit(uint16 cardid,uint32 bitmask); 	
/*指令功能：选择二维高速比较输出口
输入参数：  cardid 卡号，取值范围:[0,11]。
            bitmask 取值范围12或13
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_CrdAccurateReadOutBit(uint16 cardid,uint32 *bitmask); 	
/*指令功能：选择二维高速比较输出口
输入参数：  cardid 卡号，取值范围:[0,11]。
            bitmask 取值范围12或13
输出参数：  无
返回：      0或错误码*/
/*************************************************************************高速位置比较功能*********************************************************/



/*************************************************************************位置锁存功能*********************************************************/
typedef struct
{
  uint16 active_level;//有效沿；0；上升沿锁存1：下降沿锁存
  uint16 latch_method;//锁存方式；0：单次锁存；1：连续锁存
  uint16 latch_source;//锁存源；0：锁存理论位置；1：锁存编码器位置；
}struct_axis_latch_parms;//位置锁存配置
PLT_API short __stdcall Plt_AxConfigLatchParms(uint16 cardid,uint16 ltc_num,uint16 axis,struct_axis_latch_parms ltcparms); 	
/*指令功能：配置高速锁存参数
输入参数：  cardid 卡号，取值范围:[0,11]。
            ltc_num	锁存器通道号，取值范围[0,1]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			ltcparms	锁存参数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxReadLatchParms(uint16 cardid,uint16 ltc_num,uint16 axis,struct_axis_latch_parms *ltcparms);	
/*指令功能：读取高速锁存配置
输入参数：  cardid 卡号，取值范围:[0,11]。
            ltc_num	锁存器通道号，取值范围[0,1]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
输出参数：  *ltcparms	锁存参数
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetLatchFlagStatus(uint16 cardid,uint16 ltc_num,uint16 axis,uint16 *latchstatus); 	
/*指令功能：读取锁存器标志
输入参数：  cardid 卡号，取值范围:[0,11]。
            ltc_num	锁存器通道号，取值范围[0,1]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
输出参数：  *latchstatus	锁存标志（1:有锁存数据 0：没有锁存数据）
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxClearLatchStatus(uint16 cardid,uint16 ltc_num,uint16 axis);  
/*指令功能：复位锁存器标志
输入参数：  cardid 卡号，取值范围:[0,11]。
            ltc_num	锁存器通道号，取值范围[0,1]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetLacthPosition(uint16 cardid,uint16 ltc_num,uint16 axis,uint16 startpos_index,uint16 count,double *position);
/*指令功能：读取锁存位置
输入参数：  cardid 卡号，取值范围:[0,11]。
            ltc_num	锁存器通道号，取值范围[0,1]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			startpos_index	需要读取的开始位置索引号，取值范围:[0,255]  单次锁存模式下 此参数无效                                            
	        count	需要读取的个数，取值范围:[0,255]  单次锁存模式下 此参数无效
输出参数：  *position	读取的锁存位置列表
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetLatchNum(uint16 cardid,uint16 ltc_num,uint16 axis,uint16 *num);  
/*指令功能：查询已经锁存的数据个数
输入参数：  cardid 卡号，取值范围:[0,11]。
            ltc_num	锁存器通道号，取值范围[0,1]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
输出参数：  *num	锁存的个数
返回：      0或错误码*/
/*************************************************************************位置锁存功能*********************************************************/



/*************************************************************************回零功能*********************************************************/
//回零模块
typedef struct
{ 
  double home_high_vel;//回零高速，单位：【pulse/s】,取值范围（0,4000000】
  double home_low_vel;//回零低速， 单位：【pulse/s】,取值范围（0,4000000】
  double home_acc;//回零加减速度,  单位：【pulse/s2】,取值范围（0,4000000000】
  uint16 home_mode;//0:原点捕获回零;1：EZ锁存回零;2:原点+EZ锁存回零 3：反向找EZ锁存回零 4：一次回零 5：二次回零 6：一次回零加反找回零 7：原点加EZ回零 8：ez回零 9：反向找EZ回零
  uint16 org_level;//原点有效电平，0：低电平有效；1：高电平有效
  uint16 org_ltc_source;//原点锁存源，0：理论位置 1：编码器位置
  uint16 ez_level;//ez有效电平，0：低电平有效；1：高电平有效
  uint16 ez_ltc_source;//ez锁存源，0：理论位置 1：编码器位置
  uint16 org_ltc_level;//0：上升沿锁存原点  1：下降沿锁存原点
  uint16 ez_ltc_level;//0：上升沿锁存ez 1：下降沿锁存ez
}struct_home_config_parms;//回零模块配置参数
PLT_API short __stdcall Plt_AxConfigHomeParms(uint16 cardid,uint16 axis,struct_home_config_parms homeparms);
/*指令功能：设置回零参数
输入参数：  cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			homeparms	回零参数
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxReadHomeParms(uint16 cardid,uint16 axis,struct_home_config_parms *homeparms);
/*指令功能：读取回零参数
输入参数：  cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];			
输出参数：  *homeparms	回零参数
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxConfigHomeEncoderFactor(uint16 cardid,uint16 axis,double factor);
/*指令功能：配置编码器比例
输入参数：  cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			factor	编码器比例
输出参数：  无
建议	1、建议设置外部编码器或伺服参数等，使每输出一个脉冲能返回一个编码器计数，此时只需要使用默认的编码器比例1
2、当没有办法使脉冲计数与编码器计数相等时，需要设置编码器比例，才能在回零中使用锁存源为编码器位置
3、此参数在回零中使用，但只在锁存源为编码器位置时使用
4、此参数在轴误差带功能中也使用
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxReadHomeEncoderFactor(uint16 cardid,uint16 axis,double *factor);
/*指令功能：查询编码器比例
输入参数：  cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];			
输出参数：  *factor	编码器比例
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxHomeMove(uint16 cardid,uint16 axis,uint16 homedir);
/*指令功能：启动回零运动
输入参数：  cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			homedir	回零方向（0：负方向，1：正方向）
输出参数：  无
返回：      0或错误码*/
PLT_API short __stdcall Plt_AxCheckHomeDone(uint16 cardid,uint16 axis,uint16 *done_flag);
/*指令功能：检查回零是否完成
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*done_flag	回零是否完成标志  0：回零没有完成 
                                          1：回零完成 
										  2：回零终止，原因：找不到原点信号 
                                          3：回零终止，原因：回零方向错误 
										  4：回零终止，原因：正负限位同时有效  
										  5：回零终止，原因：找不到EZ信号
						                  6：回零终止，原因：超出回零搜索距离
										  7：回零停止，原因：命令终止
  返回参数：错误码*/
PLT_API short __stdcall Plt_AxSetHomeSearchDistance(uint16 cardid,uint16 axis,double home_distance);
/*指令功能：设置回零搜索距离，如果搜索距离到达还没有找到原点，则运动减速停止 停止原因代码是24
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			home_distance 搜索距离 单位：ppu
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetHomeSearchDistance(uint16 cardid,uint16 axis,double *home_distance);
/*指令功能：查询回零搜索距离，如果搜索距离到达还没有找到原点，则运动减速停止 停止原因代码是24
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*home_distance 搜索距离 单位：ppu
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetHomeStopDelayTime(uint16 cardid,uint16 axis,uint32 delay_time);
/*指令功能：设置回零过程中运动停止后延时delay_time后再启动反向运动。
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
		    delay_time 延时时间 ，单位 ms 
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetHomeStopDelayTime(uint16 cardid,uint16 axis,uint32 *delay_time);
/*指令功能：读取回零过程中运动停止后延时时间。
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
  输出参数：delay_time 延时时间 ，单位 ms 
  返回：      0或错误码*/

PLT_API short __stdcall Plt_AxSetHomeBackDistance(uint16 cardid,uint16 axis,double back_distance);
/*指令功能：设置回零反找时碰到原点后的回退距离
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			back_distance 搜索距离 单位：ppu
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetHomeBackDistance(uint16 cardid,uint16 axis,double *back_distance);
/*指令功能：回读回零反找时碰到原点后的回退距离
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*back_distance 搜索距离 单位：ppu
  返回：      0或错误码*/
/*************************************************************************回零功能*********************************************************/


/*************************************************************************手轮功能*********************************************************/
typedef struct
{ 
  uint16 handwheelmode;//手轮输入模式：0：正交信号输入模式；1：脉冲+方向输入模式；
  double radio;//手轮倍率;radio <0  负方向  radio >0 正方向
}struct_handwheel_config_parms;//手轮配置参数
PLT_API short __stdcall Plt_AxConfigHandwheelParms(uint16 cardid,uint16 axis,struct_handwheel_config_parms hwparms);	
/*指令功能：配置手轮运动参数
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			hwparms	手轮配置参数
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxReadHandwheelParms(uint16 cardid,uint16 axis,struct_handwheel_config_parms *hwparms);	//读取输入手轮脉冲信号的工作方式
/*指令功能：读取手轮配置
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*hwparms	手轮配置参数
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetHandwheelPosition(uint16 cardid,uint16 axis,double pos);//设置手轮当前位置
/*指令功能：设置手轮位置
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			pos	    位置值
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetHandwheelPosition(uint16 cardid,uint16 axis,double *pos);
/*指令功能：读取手轮位置
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*pos	    位置值
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxHandwheelMove(uint16 card,uint16 axis);
/*指令功能：启动手轮运动
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetHandwheelChannal(uint16 cardid,uint16 handwheelchannal);

PLT_API short __stdcall Plt_AxGetHandwheelInputState(uint16 cardid,uint16 *input_state);
/*指令功能：读取手轮端子控制信号输入状态
  输入参数：cardid 卡号，取值范围:[0,11]。
  输出参数：input_state ： bit0: 轴0轴选输入信号状态 bit1: 轴1轴选输入信号状态 bit2: 轴2轴选输入信号状态 bit3: 轴3轴选输入信号状态
                           bit4: 1倍倍率输入信号状态 bit5: 10倍倍率输入信号状态 bit6: 100倍倍率输入信号状态
						   bit7: 手轮急停输入信号状态
  返回：      0或错误码*/
/*************************************************************************手轮功能*********************************************************/



/*************************************************************************JOG和点位运动功能*********************************************************/
typedef struct
{
   double start_vel;     //起始速度，单位：【ppu/s】 ;取值范围【0,4000000/PPU】
   double max_vel;       //最大速度，单位：【ppu/s】;取值范围(0,4000000/PPU】
   double end_vel;       //停止速度，单位：【ppu/s】;取值范围【0,4000000/PPU】
   double acc;           //加速度,单位：[ppu/s2];取值范围(0,4000000000/ppu]
   double dec;           //减速度,单位：[ppus/s2];取值范围(0,4000000000/ppu]
}struct_vel_plan_parms;//速度规划参数
//速度参数设置：
PLT_API short __stdcall Plt_AxSetSmoothFactor(uint16 cardid,uint16 axis,double smooth_factor);
/*指令功能：设置速度曲线的S比例系数
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
		    smooth_factor	当Plt_AxSetSProfileMode中参数SProfileMode为0时，表示S段比例系数，取值范围 :[0,1] 
			                当Plt_AxSetSProfileMode中参数SProfileMode为1时，表示滤波时间，单位是s,取值范围[0,1]
  输出参数：无
      说明：	   当Plt_AxSetSProfileMode中参数SProfileMode为0： smooth_factor为0时，速度曲线就是梯形速度曲线。smooth_factor为1时，速度曲线就是最平滑的S形速度曲线。S比例系数在0和1之间时，速度曲线也就介于梯形速度曲线与完全的S形速度曲线之间
                   当Plt_AxSetSProfileMode中参数SProfileMode为1： smooth_factor为T型速度规划滤波时间，滤波时间越大，速度曲线越平滑，但是效率越低。
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetSmoothFactor(uint16 cardid,uint16 axis,double *smooth_factor);
/*指令功能：设置速度曲线的S比例系数
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];  
  输出参数：*smooth_factor	设置S段比例系数，取值范围 :[0,1] 
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetSProfileMode(uint16 cardid,uint16 axis,uint16 SProfileMode);
/*指令功能：设置S型速度曲线规划模式(该函数仅对定长运动有效)
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
		    SProfileMode	0：公式规划模式   1：T型速度曲线+滤波模式
  输出参数：无
      说明：当SProfileMode取0时，Plt_AxSetSmoothFactor函数中的参数smooth_factor表示S曲线速度平滑比例系数，没有物理单位。
	        当SProfileMode取1时，Plt_AxSetSmoothFactor函数中的参数smooth_factor表示滤波时间，单位是s,取值范围[0,1]
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetSProfileMode(uint16 cardid,uint16 axis,uint16 *SProfileMode);
/*指令功能：设置S型速度曲线规划模式(该函数仅对定长运动有效)
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];		    
  输出参数：SProfileMode	0：公式规划模式   1：T型速度曲线+滤波模式
      说明：当SProfileMode取0时，Plt_AxSetSmoothFactor函数中的参数smooth_factor表示S曲线速度平滑比例系数，没有物理单位。
	        当SProfileMode取1时，Plt_AxSetSmoothFactor函数中的参数smooth_factor表示滤波时间，单位是s,取值范围[0,1]
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetvelParms(uint16 cardid,uint16 axis,struct_vel_plan_parms axisplanparms);
/*指令功能：设置速度曲线的规划参数
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
		    axisplanparms	速度规划参数
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxGetvelParms(uint16 cardid,uint16 axis,struct_vel_plan_parms *axisplanparms);
/*指令功能：设置速度曲线规划参数
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	    
  输出参数：*axisplanparms	速度规划参数
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxMoveRel(uint16 cardid,uint16 axis,double dist);	
/*指令功能：开始点位运动（运动一段dist距离）
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			dist	点位运动的距离，单位：PPU dist取值范围：【2147483640/ppu,-2147483640/ppu】 注意：当dist加上当前寄存器值超出范围【2147483640/ppu,-2147483640/ppu】，会报错
  输出参数：*axisplanparms	速度规划参数
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxMoveAbs(uint16 cardid,uint16 axis,double position);	
/*指令功能：开始点位运动（运动到position位置）
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			position	点位运动的目标位置，单位：PPU position取值范围：【2147483640/ppu,-2147483640/ppu】
  输出参数：*axisplanparms	速度规划参数
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxChangeVelMoveRel(uint16 cardid,uint16 axis,double change_vel,double start_change_vel_dist,double end_change_vel_dist,double dist);
/*指令功能：开始点位运动（运动一段dist距离）,并在运动中设定的位置进行在线变速
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			change_vel	中间平稳段的速度
            start_change_vel_dist	中间段开始相对位置
            end_change_vel_dist	中间段结束相对位置
			dist 终点位置相对于起点位置距离 position取值范围：【2147483640/ppu,-2147483640/ppu】
  输出参数：无
  返回：      0或错误码*/	
PLT_API short __stdcall Plt_AxChangeVelMoveAbs(uint16 cardid,uint16 axis,double change_vel,double start_change_vel_pos,double end_change_vel_pos,double position);	// 
/*功能描述：开始点位运动（运动到position位置）,并在运动中设定的位置进行在线变速
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			change_vel	中间平稳段的速度
            start_change_vel_dist	中间段开始相对位置
            end_change_vel_dist	中间段结束相对位置
			position 终点位置,position取值范围：【2147483640/ppu,-2147483640/ppu】
  输出参数：无
  返回：      0或错误码*/			
PLT_API short __stdcall Plt_AxMoveVel(uint16 cardid,uint16 axis,uint16 direction);	//指定轴做连续运动
/*指令功能：启动JOG运动
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			direction	JOG运动的方向，0：负方向，1：正方向.指令位置增加的方向为正方向，相反的为负方向。
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxChangeTartetPos(uint16 cardid,uint16 axis,double position);
/*指令功能：运行中改变目标位置（原来的目标位置再加上一段position距离）
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			position	在线变位运动的新位置，单位：PPU position取值范围：【2147483640/ppu,-2147483640/ppu】相对模式在线变位
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxChangeTartetPosAbs(uint16 cardid,uint16 axis,double position);
/*指令功能：运行中改变目标位置（新的目标位置为position）
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			position	在线变位运动的新位置（绝对位置坐标），单位：PPU position取值范围：【2147483640/ppu,-2147483640/ppu】绝对模式在线变位
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxChangeVel(uint16 cardid,uint16 axis,double maxvel); //maxvel取值范围：[-4000000/PPU,4000000/PPU]
/*指令功能：运行中改变速度
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			maxvel	在线变速后新的最大速度，单位：PPU/s
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxChangeTartetPosMaxVelAcc(uint16 cardid,uint16 axis,double position,uint16 pos_mode,double max_vel,double acc,double dec);
/*指令功能：运行中同时改变改变目标位置
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			        position	在线变位运动的新位置
					pos_mode    位置模式 1：绝对模式  0：相对模式 
                    max_vel     最大速度 
					acc         加速度
					dec         减速度
  输出参数：无
  返回：      0或错误码*/

PLT_API short __stdcall Plt_AxMoveRelAndSoftLanding(uint16 cardid,uint16 axis,double soft_landing_vel,double soft_landing_dist,double aim_dist);
/*指令功能：开始有软着陆的相对定长运动
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			soft_landing_vel	软着陆速度
            soft_landing_dist	软着陆位置相对于起点位置距离
			aim_dist 终点位置相对于起点位置距离 position取值范围：【2147483640/ppu,-2147483640/ppu】
  输出参数：无
  返回：      0或错误码*/	
PLT_API short __stdcall Plt_AxMoveAbsAndSoftLanding(uint16 cardid,uint16 axis,double soft_landing_vel,double soft_landing_pos,double aim_pos);
/*指令功能：开始有软着陆的相对定长运动
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			soft_landing_vel	软着陆速度
            soft_landing_pos	软着陆位置相对于起点位置距离
			aim_pos 终点位置：【2147483640/ppu,-2147483640/ppu】
  输出参数：无
  返回：      0或错误码*/	
/*************************************************************************JOG和点位运动功能*********************************************************/

/*************************************************************************取/放料运动功能*********************************************************/
//取/放料运动一共有3段轨迹，分别是，取料后上升，物料移动,物料放料 涉及到5个轴，分别是上升/下降Z轴，物料旋转R轴，物料取料后在平面内移动的X/Y轴,等待位置轴。
PLT_API short __stdcall Plt_TakingMaterisSetAxisParms(uint16 cardid,uint16 crd,uint16 wait_input_num,uint16 wait_input_logic,uint16 *axis,double ratio_1,double ratio_2);
//指令功能：配置取放料轴号和取料等待输入IO序号和电平
//  输入参数：cardid 卡号，取值范围:[0,11]。
//            crd 动作序号
//            wait_input_num 取料等待输入IO序号
//		    wait_input_logic 取料等待输入IO电平
//              axis 轴号列表：
//             axis[0]:x轴对应物理轴号
//             axis[1]:y轴对应物理轴号
//             axis[2]:z轴对应物理轴号
//             axis[3]:r轴对应物理轴号
//             axis[4]:放料等待位置到达的轴号
//             ratio_1:第一段完成百分之ratio_1时启动第二段
//             ratio_2:第二段完成百分之ratio_2时启动第三段
//  输出参数：无
//  返回参数：0或错误码
PLT_API short __stdcall Plt_TakingMaterisGetAxisParms(uint16 cardid,uint16 crd,uint16 *wait_input_num,uint16 *wait_input_logic,uint16 *axis,double *ratio_1,double *ratio_2);
//指令功能：读取取放料轴号和取料等待输入IO序号和电平配置
//  输入参数：cardid 卡号，取值范围:[0,11]。
//            crd 动作序号
// 输出参数： *wait_input_num 取料等待输入IO序号
//		      *wait_input_logic 取料等待输入IO电平
//              *axis 轴号列表：
//             *axis[0]:x轴对应物理轴号
//             *axis[1]:y轴对应物理轴号
//             *axis[2]:z轴对应物理轴号
//             *axis[3]:r轴对应物理轴号
//             *axis[4]:放料等待位置到达的轴号
//             *ratio_1:第一段完成百分之ratio_1时启动第二段
//             *ratio_2:第二段完成百分之ratio_2时启动第三段
//  返回参数：0或错误码
PLT_API short __stdcall Plt_TakingMaterisSetvelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms *axisplanparms,double change_vel);
//指令功能：取放料运动速度参数配置
//  输入参数：cardid 卡号，取值范围:[0,11]。
//            crd 动作序号
//			axisplanparms[0] 第一段运动(上升/下降)速度参数
//			axisplanparms[1] 第二段运动(XY平移和物料旋转)合速度参数
//			axisplanparms[2] 第三段运动(下降/上升)速度参数
//			change_vel:在线变速速度
//  输出参数：无
//  返回参数：错误码
PLT_API short __stdcall Plt_TakingMaterisGetvelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms *axisplanparms,double *change_vel);
//指令功能：读取取放料运动速度参数配置
//  输入参数：cardid 卡号，取值范围:[0,11]。
//            crd 动作序号
//输出参数：axisplanparms[0] 第一段运动(上升/下降)速度参数
//			axisplanparms[1] 第二段运动(XY平移和物料旋转)合速度参数
//			axisplanparms[2] 第三段运动(下降/上升)速度参数
//			change_vel:在线变速速度
//  返回参数：错误码
PLT_API short __stdcall Plt_TakingMaterisMoveAbs(uint16 cardid,uint16 crd,double pos_0,double *pos_1,double *pos_2,double *pos_3,double pos_4,double pos_5,uint16 motion_mode);
//指令功能：取放料绝对运动
//  输入参数：cardid 卡号，取值范围:[0,11]。
//          crd 动作序号
//			  pos_0 第一段终点位置
//			  pos_1 第二段第一个变速点X/Y/R轴位置
//			  pos_2 第二段第二个变速点X/Y/R轴位置
//			  pos_3 第二段终点点X/Y/R轴位置
//			  pos_4 第三段终点位置
//            pos_5等待位置
//            motion_mode 运动模式 0 ：取料  1：放料,且等待pos_5方式是大于等于 2：放料,且等待pos_5方式是小于等于 
//  输出参数：无
//  返回参数：0或错误码
PLT_API short __stdcall Plt_TakingMaterisChangePosAbs(uint16 cardid,uint16 crd,double *pos);
//指令功能：取放料绝对运动
//输入参数：cardid 卡号，取值范围:[0,11]。
//          crd 动作序号
//			  pos 在线变位X/Y/R轴绝对位置
//输出参数：无
//返回参数：0或错误码
/*************************************************************************取/放料运动功能*********************************************************/

/*************************************************************************停止函数*********************************************************/

PLT_API short __stdcall Plt_AxMotionStop(uint16 cardid,uint16 axis,uint16 stop_mode); //指定运动轴停止 0：减速停止 1：立即停止
/*指令功能：停止指定轴
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
            stop_mode	停止模式  0：减速停止 1：立即停止
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_CardMotionEmgStop(uint16 cardid);	
/*指令功能：停止所有轴
  输入参数：cardid	卡号，取值范围:[0,11]。
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall Plt_AxSetStopAcc(uint16 cardid,uint16 axis,double Acc);
/*指令功能：设置减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
            Acc  	减速停止加速度
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall  Plt_AxGetStopAcc(uint16 cardid,uint16 axis,double *Acc);
/*指令功能：回读减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
  输出参数：*Acc  	减速停止加速度
  返回：      0或错误码*/
  PLT_API short __stdcall Plt_AxSetUseStopAccFlag(uint16 cardid,uint16 axis,uint16 use_stop_acc_flag);
/*指令功能：设置减速停止时是否使用减速停止专用加速度标志
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
            use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall  Plt_AxGetUseStopAccFlag(uint16 cardid,uint16 axis,uint16 *use_stop_acc_flag);
/*指令功能：回读减速停止时是否使用减速停止专用加速度标志
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
   输出参数 *use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
  返回：      0或错误码*/
/*************************************************************************停止函数*********************************************************/

/*************************************************************************螺距补偿功能*********************************************************/
PLT_API short __stdcall Plt_AxEnableLeadScrewComp(uint16 cardid,uint16 axis,uint16 mode);  
/*指令功能：使能/关使能螺距补偿功能
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
			mode: 1表示使能，0表示禁止。 
  输出参数：无
  返回参数：0或错误码*/
PLT_API short __stdcall Plt_AxGetEnableLeadScrewComp(uint16 cardid,uint16 axis,uint16 *mode); 
/*指令功能：查询螺距补偿的使能状态
  输入参数：cardid	卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];	
  输出参数：*mode: 1表示使能，0表示禁止。 
  返回参数：0或错误码*/
PLT_API short __stdcall Plt_AxSetLeadScrewComp(uint16 cardid,uint16 axis,uint16 n,int32 startPos,int32 lenPos,int32 *pCompPos,int32 *pCompNeg);  
/*指令功能：设置螺距补偿参数
输入参数：cardid	卡号，取值范围:[0,11]。
           axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
		  n为点数，范围【1,256】
		  startPos 为补偿起始点的规划位置（单位：pulse）； 
		  lenPos为测量段的总长（单位：pulse）；  
		  pCompPos为对应为正方向运动时，各点位置需要补偿的脉冲数； 
		  pCompNeg为对应为负方向运动时，各点位置需要补偿的脉冲数；
输出参数：无
返回值：0或错误码*/
/*************************************************************************螺距补偿功能*********************************************************/


/*************************************************************************插补运动功能*********************************************************/
typedef struct
{ 
  uint16 dimension;//坐标系维数，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7]，EIC00取值范围:[0,11];
  uint16 intermode;//连续插补模式；0：普通连续插补；1：前瞻模式连续插补;2：保留
}struct_crd_config_parms;//坐标系配置参数
PLT_API short __stdcall Plt_CrdConfigCrd(uint16 cardid,uint16 crd,struct_crd_config_parms crdparms,uint16 *Axismaparray);
/*指令功能：配置坐标系
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			crdparms	坐标系配置参数
			*Axismaparray	坐标系轴号列表（数量由参数crdparms中的坐标系维数决定）
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdGetCrd(uint16 cardid,uint16 crd,struct_crd_config_parms *crdparms,uint16 *Axismaparray);
/*指令功能：读取坐标系配置参数
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：	*crdparms	坐标系配置参数
			*Axismaparray	坐标系轴号列表（数量由参数crdparms中的坐标系维数决定）
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdResetCrd(uint16 cardid,uint16 crd);
/*指令功能：注销坐标系
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdClearCrdBuf(uint16 cardid,uint16 crd);
/*指令功能：清除坐标系缓冲区
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufMoveStart(uint16 cardid,uint16 crd);
/*指令功能：启动坐标系运动
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufMovePause(uint16 cardid,uint16 crd);
/*指令功能：暂停坐标系运动
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufMoveStop(uint16 cardid,uint16 crd,uint16 stop_mode);
/*指令功能：停止坐标系运动
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：无
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdSetOpenSwitchAdvanceTime(uint16 cardid,uint16 crd,double time);
/*指令功能：设置提前开胶时间，此函数必须在建立坐标系前调用 
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			time 提前开胶/关胶时间 单位：ms
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdGetOpenSwitchAdvanceTime(uint16 cardid,uint16 crd,double *time);
/*指令功能：回读提前开胶时间，此函数必须在建立坐标系前调用 
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
输出参数：time 提前开胶/关胶时间 单位：ms
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdSetStopAcc(uint16 cardid,uint16 crd,double Acc);
/*指令功能：设置坐标系减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
  输入参数：cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
            Acc  	减速停止加速度
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall  Plt_CrdGetStopAcc(uint16 cardid,uint16 crd,double *Acc);
/*指令功能：回读坐标系减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
  输入参数：cardid	卡号，取值范围:[0,11]。
             crd	坐标系号，取值范围:[0,1]。
  输出参数：*Acc  	减速停止加速度
  返回：      0或错误码*/
  PLT_API short __stdcall Plt_CrdSetUseStopAccFlag(uint16 cardid,uint16 crd,uint16 use_stop_acc_flag);
/*指令功能：设置坐标系减速停止时是否使用减速停止专用加速度标志
  输入参数：cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
            use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
  输出参数：无
  返回：      0或错误码*/
PLT_API short __stdcall  Plt_CrdGetUseStopAccFlag(uint16 cardid,uint16 crd,uint16 *use_stop_acc_flag);
/*指令功能：回读坐标系减速停止时是否使用减速停止专用加速度标志
  输入参数：cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
   输出参数 *use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
  返回：      0或错误码*/

PLT_API short __stdcall  Plt_CrdBufGetSpace(uint16 cardid,uint16 crd,long *crdspace);
/*指令功能：查询插补缓冲区剩余空间
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：*crdspace	缓冲器剩余空间
返回值：0或错误码*/
PLT_API short __stdcall  Plt_CrdBufGetRunningSegment(uint16 cardid,uint16 crd,long *CurSegment);
/*指令功能：查询当前运行段号
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：*CurSegment	正在运动的段号
返回值：0或错误码*/
PLT_API short __stdcall  Plt_CrdBufGetRemainVectorLengthRatio(uint16 cardid,uint16 crd,double *ratio);
/*指令功能：读取剩余插补矢量长度百分比
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：  *ratio 剩余插补矢量长度百分比
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufChangeSpeed(uint16 cardid,uint16 crd,double ratio);
/*指令功能：在线改变速度
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			ratio	倍率，取值范围:[0,10]。
输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufSetSmoothFactor(uint16 cardid,uint16 crd,double smooth_factor);
/*指令功能：设置S段比例参数
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			smooth_factor	S段比例参数,范围：[0,1]
输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufGetSmoothFactor(uint16 cardid,uint16 crd,double *smooth_factor);
/*指令功能：读取S段比例参数
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
输出参数： *smooth_factor	S段比例参数,范围：[0,1]
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufSetVelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms bufvelparms);
/*指令功能：设置坐标系速度参数
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			bufvelparms	速度规划参数
typedef struct
{
   double start_vel;     //起始速度，单位：【ppu/s】
   double max_vel;       //最大速度，单位：【ppu/s】
   double end_vel;       //停止速度，单位：【ppu/s】
   double acc;           //加速度,单位：[ppu/s2]
   double dec;           //减速度,单位：[ppu/s2]
}struct_vel_plan_parms; 
输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufGetVelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms *bufvelparms);
/*指令功能：获取坐标系速度参数
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
输出参数： *bufvelparms	速度规划参数
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufSetTrajectoryError(uint16 cardid,uint16 crd,double TrajectoryError);
/*指令功能：设置允许的轨迹误差（仅在前瞻模式下有效）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			TrajectoryError	允许的轨迹误差值（单位：PPU）
输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufGetTrajectoryError(uint16 cardid,uint16 crd,double *TrajectoryError);
/*指令功能：查询允许的轨迹误差（仅在前瞻模式下有效）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。			
输出参数： *TrajectoryError	允许的轨迹误差值（单位：PPU）
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufSetMaxTransitAcc(uint16 cardid,uint16 crd,double MaxTransitAcc);
/*指令功能：设置允许的最大加加速度（仅在前瞻模式下有效）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			MaxTransitAcc	允许的最大加速度（单位：[ppu/s2]）
输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufGetMaxTransitAcc(uint16 cardid,uint16 crd,double *MaxTransitAcc);
/*指令功能：查询允许的最大加加速度（仅在前瞻模式下有效）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
输出参数： *MaxTransitAcc	允许的最大加速度（单位：[ppu/s2]）
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdBufSetFollowAxis(uint16 cardid,uint16 crd,uint16 follow_axis_num,uint16 *axis_list);
/*指令功能：设置坐标系跟随轴
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
			follow_axis_num	跟随轴个数
			axis_list 坐标系中跟随轴轴号 取值： 0:表示坐标系X轴 1：表示坐标系Y轴 2：表示坐标系Z轴 3：表示坐标系U轴 4：表示坐标系V轴 5：表示坐标系W轴
输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufGetFollowAxis(uint16 cardid,uint16 crd,uint16 *follow_axis_num,uint16 *axis_list);
/*指令功能：读取坐标系跟随轴配置
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。
输出参数：  follow_axis_num	跟随轴个数
		    axis_list 坐标系中跟随轴轴号 取值： 0:表示坐标系X轴 1：表示坐标系Y轴 2：表示坐标系Z轴 3：表示坐标系U轴 4：表示坐标系V轴 5：表示坐标系W轴
返回值：    0或错误码*/

PLT_API short __stdcall Plt_CrdBufMoveLinerRel(uint16 cardid,uint16 crd,uint16 axis_num,double* targetpos_array,uint32 segnum);
/*指令功能：直线插补（相对运动）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
           axis_num	参与直线插补轴数
           *targetpos_array	参与直线插补各轴的相对位移（单位：PPU）
           segnum	段号
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufMoveLinerAbs(uint16 cardid,uint16 crd,uint16 axis_num,double* targetpos_array,uint32 segnum);
/*指令功能：直线插补（绝对运动）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            axis_num 轴数
            targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
            segnum 段号
输出参数：无
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdBufMoveLinerRelMulti_XYZ(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* targetpos_array_z,double* max_vel,double* acc);
/*指令功能：3轴直线插补（一次添加多个插补点，相对运动）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
            line_num	一次性添加的直线坐标点数 取值范围[1,16]
           *targetpos_array_x	参与直线插补X轴的相对位移（单位：PPU）
		   *targetpos_array_y	参与直线插补X轴的相对位移（单位：PPU）
		   *targetpos_array_z	参与直线插补X轴的相对位移（单位：PPU）
		   * max_vel            最大速度
		   * acc                最大加速度
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufMoveLinerAbsMulti_XYZ(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* targetpos_array_z,double* max_vel,double* acc);
/*指令功能：3轴直线插补（一次添加多个插补点，绝对运动）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
            line_num	一次性添加的直线坐标点数 取值范围[1,16]
           *targetpos_array_x	参与直线插补X轴的绝对位移（单位：PPU）
		   *targetpos_array_y	参与直线插补X轴的绝对位移（单位：PPU）
		   *targetpos_array_z	参与直线插补X轴的绝对位移（单位：PPU）
		   * max_vel            最大速度
		   * acc                最大加速度
输出参数：无
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdBufMoveLinerRelMulti_XY(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* max_vel,double* acc);
/*指令功能：2轴直线插补（一次添加多个插补点，相对运动）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
            line_num	一次性添加的直线坐标点数 取值范围[1,16]
           *targetpos_array_x	参与直线插补X轴的相对位移（单位：PPU）
		   *targetpos_array_y	参与直线插补X轴的相对位移（单位：PPU）
		   * max_vel            最大速度
		   * acc                最大加速度
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufMoveLinerAbsMulti_XY(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* max_vel,double* acc);
/*指令功能：2轴直线插补（一次添加多个插补点，绝对运动）
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。		
            line_num	一次性添加的直线坐标点数 取值范围[1,16]
           *targetpos_array_x	参与直线插补X轴的绝对位移（单位：PPU）
		   *targetpos_array_y	参与直线插补X轴的绝对位移（单位：PPU）
		   * max_vel            最大速度
		   * acc                最大加速度
输出参数：无
返回值：0或错误码*/

typedef struct
{
  uint16 axis_num;//插补轴数
  uint16 direction;//圆弧方向，0：顺时针；1：逆时针；
  uint16 cirnum;//圆弧圈数
  uint16 plane;//圆弧在哪个平面；0：XY平面；1：YZ平面 2：XZ平面
  uint16 mode;//位置模式。0：相对位置模式；1：绝对位置模式
}struct_center_cir_parms;//圆心终点方式圆弧参数

PLT_API short __stdcall Plt_CrdBufMoveCenterCircular(uint16 cardid,uint16 crd,struct_center_cir_parms cencirparms,double *targetpos_array,double *cenpos_array,uint32 segnum);
/*指令功能：圆心终点模式圆弧插补 
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            cencirparms 圆心终点方式圆弧参数
			cenpos_array圆心坐标列表
            targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
            segnum 段号
输出参数：无
返回值：0或错误码*/
typedef struct
{
  double radius;//圆弧半径，单位：【ppu】
  uint16 axis_num;//插补轴数
  uint16 direction;//圆弧方向，0：顺时针；1：逆时针；
  uint16 cirnum;//圆弧圈数
  uint16 plane;//圆弧在哪个平面；0：XY平面；1：YZ平面 2：XZ平面
  uint16 mode;//位置模式。0：相对位置模式；1：绝对位置模式
}struct_radius_cir_parms;//终点半径圆弧参数

PLT_API short __stdcall Plt_CrdBufMoveRadiusCircular(uint16 cardid,uint16 crd,struct_radius_cir_parms radcirparms,double *targetpos_array,uint32 segnum);
/*指令功能：终点半径模式圆弧插补 
输入参数： cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            radcirparms 终点半径圆弧参数
            targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
            segnum 段号
输出参数：无
返回值：0或错误码*/
typedef struct
{
  uint16 axis_num;//插补轴数
  uint16 direction;//圆弧方向，0：顺时针；1：逆时针；此参数无效
  uint16 cirnum;//圆弧圈数
  uint16 plane;//圆弧在哪个平面；0：XY平面；1：YZ平面 2：XZ平面 3:空间圆弧
  uint16 mode;//位置模式。0：相对位置模式；1：绝对位置模式
}struct_3point_cir_parms;//3点圆弧参数

PLT_API short __stdcall Plt_CrdBufMove3PointCircular(uint16 cardid,uint16 crd,struct_3point_cir_parms pointscirparms,double *targetpos_array,double *midpos_array,uint32 segnum);
/*指令功能：三点模式圆弧插补 
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            radcirparms pointscirparms
			midpos_array 中间点位置列表
            targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
            segnum 段号
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufDelay(uint16 cardid,uint16 crd,double time,uint32 segnum);//插补延时,单位：[ms]
/*指令功能：缓冲延时
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            time	延时时间（单位：ms）
            segnum 段号
输出参数：无
返回值：0或错误码*/

typedef struct
{
  uint16 input_num;//输入io号：取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
  uint16 active_level;//有效电平，0：低电平有效；1：高电平有效
  double check_time;//check时间,单位：[ms]
}struct_buf_check_input_parms;
PLT_API short __stdcall Plt_CrdBufCheckInput(uint16 cardid,uint16 crd,struct_buf_check_input_parms inputparms,uint32 segnum);
/*指令功能：等待输入IO
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            inputparms    输入IO参数
            segnum 段号
输出参数：无
返回值：0或错误码*/

typedef struct
{
  uint16 output_num;//输出io号：EI800\EIC00 0-15 EI400S 0-31
  uint16 active_level;//有效电平，0：低电平有效；1：高电平有效
  double check_time;//check时间,单位：[ms]
}struct_buf_check_output_parms;//缓冲区通用输出IO参数
PLT_API short __stdcall Plt_CrdBufCheckOutput(uint16 cardid,uint16 crd,struct_buf_check_output_parms outputparms,uint32 segnum);
/*指令功能：缓冲区等待输出IO
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            outputparms    输出IO参数
            segnum 段号
输出参数：无
返回值：0或错误码*/

typedef struct
{
  uint16 io_mode;//缓冲区输出io模式；//0：设定io立即输出设定电平；1：设定io滞后设定距离输出设定电平；2：设定io滞后设定时间输出设定电平 3:：设定io提前设定距离输出设定电平
  uint16 output_num;//输出io号：取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
  uint16 active_level;//有效电平，0：低电平有效；1：高电平有效
  double actionparm;//时间（单位是ms）或距离参数(单位是ppu)
  double holdtime;//设定电平保持时间,单位：[ms]
}struct_buf_out_io_parms;//缓冲区通用输出IO参数
PLT_API short __stdcall Plt_CrdBufSetOutput(uint16 cardid,uint16 crd,struct_buf_out_io_parms outputparms,uint32 segnum);
/*指令功能：缓冲区输出IO
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            outputparms    输出IO参数
            segnum 段号
输出参数：无
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdBufBlank(uint16 cardid,uint16 crd,uint32 segnum);
/*指令功能：缓冲区空指令
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            segnum 段号
输出参数：无
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdBufClearIoAction(uint16 cardid,uint16 crd,uint32 io_mask,uint32 segnum);
/*指令功能：清除IO操作 
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
            io_mask 需要清除的输出IO号，第0-15BIT对应0-15个输出IO 1：表示清楚 0：表示不操作
            segnum 段号
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufOpenSwitchAdvance(uint16 cardid,uint16 crd,double* pos,uint16 active_level);
/*
指令功能：设置理论开胶/关胶位置
输入参数： cardid	卡号，取值范围:[0,11]。
           crd	    坐标系号，取值范围:[0,1]。	
		   pos      理论比较位置(X轴坐标和Y轴坐标值)
		   active_level  比较输出有效电平
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufOpenSwitchAdvanceMulti(uint16 cardid,uint16 crd,uint32 pos_num,double* pos_x,double* pos_y,uint16 active_level);
/*
指令功能：设置理论开胶/关胶位置
输入参数： cardid	卡号，取值范围:[0,11]。
           crd	    坐标系号，取值范围:[0,1]。	
		   pos_num  添加比较点个数,一次最多可以添加42个比较点 取值范围[1,42]
		   pos_x    理论比较X轴位置
		   pos_y    理论比较Y轴位置
		   active_level  比较输出有效电平
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufSwitchRemainSpace(uint16 cardid,uint16 crd,uint32 *space);
/*
指令功能：读取开胶/关胶位置剩余缓冲区数量
输入参数： cardid	卡号，取值范围:[0,11]。
           crd	    坐标系号，取值范围:[0,1]。	
输出参数：space 剩余缓冲区
返回值：0或错误码*/

PLT_API short __stdcall Plt_CrdBufSwitchClear(uint16 cardid,uint16 crd);
/*
指令功能：读取开胶/关胶位置剩余缓冲区数量
输入参数： cardid	卡号，取值范围:[0,11]。
           crd	    坐标系号，取值范围:[0,1]。	
输出参数：space 剩余缓冲区
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufCompareSetStartLength(uint16 cardid,uint16 crd,double offset_length,uint16 active_level);
/*指令功能：设置绝对距离模式开胶/关胶开始位置
输入参数： cardid	卡号，取值范围:[0,11]。
           crd	    坐标系号，取值范围:[0,1]。
		   offset_length 当前位置的偏移轨迹长度，取值大于等于零
		   active_level  开始位置输出电平
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufCompareAddLengthMulti(uint16 cardid,uint16 crd,uint32 pos_num,double* length,uint16 active_level);
/*
指令功能：同时添加多个绝对距离模式开胶/关胶位置
输入参数： cardid	卡号，取值范围:[0,11]。
           crd	    坐标系号，取值范围:[0,1]。	
		   pos_num  添加比较点个数,一次最多可以添加42个比较点 取值范围[1,42]
		   length   相对开始点的 绝对距离，取值大于等于零
		   active_level  比较输出有效电平
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufDistanceOutPut(uint16 cardid,uint16 crd,struct_crd_accurate_compare_parms compare_parms_2d,double start_length_ratio,double end_length_ratio,uint32 output_num,uint32 segnum);
/*
指令功能：缓冲区等距离二维比较输出（相对于下段轨迹。要求：下段轨迹必须是直线段或者圆弧段，否则会出现错误）
输入参数：cardid	卡号，取值范围:[0,11]。
           crd	坐标系号，取值范围:[0,1]。	
		  typedef struct
		  {
			  uint16 axis_array[2];//比较轴列表 0：X轴  1：Y轴  EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];
			  uint16 enable;//比较使能开关；0;比较禁止；1：比较允许；
			  uint16 cmpmethod;//比较方法：0：开区间比较法；1：半开区间比较法
			  uint16 cmp_source;//比较源 0：理论位置 1：编码器位置
			  uint16 active_level;//有效电平；0：低电平有效；1：高电平有效
			  double pulsewidth;//脉冲宽度；单位：【ms】
			  double cmp_error;//精度；单位[pulse]
			}struct_crd_accurate_compare_parms;//精确位置比较
			start_length_ratio 开始点位置占轨迹总长度的比例
			end_length_ratio 结束点的位置占轨迹总长度的比例
			output_num：等距离输出点的数目（包括开始点和结束点）
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufDistanceOutPutConti(uint16 cardid,uint16 crd,struct_crd_accurate_compare_parms compare_parms_2d,uint16 enable_flag,double distance,uint32 segnum);
/*
指令功能：连续等距离二维比较输出（缓冲区指令，使能此指令后，控制卡自动在此指令后的直线插补段和圆弧插补段前添加高速二维比较缓冲区指令）
输入参数：cardid	卡号，取值范围:[0,11]。
          crd	坐标系号，取值范围:[0,1]。	
		  typedef struct
		  {
			  uint16 axis_array[2];//比较轴列表 0：X轴  1：Y轴 EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];
			  uint16 enable;//比较使能开关；0;比较禁止；1：比较允许；
			  uint16 cmpmethod;//比较方法：0：开区间比较法；1：半开区间比较法
			  uint16 cmp_source_array[2];//比较源 0：理论位置 1：编码器位置
			  uint16 active_level;//有效电平；0：低电平有效；1：高电平有效
			  double pulsewidth;//脉冲宽度；单位：【ms】
			  double cmp_error;//精度；单位[pulse]
			}struct_crd_accurate_compare_parms;//精确位置比较
			enable_flag 连续等距离二维比较输出使能标志
			distance 等距比较距离值（脉冲当量单位）
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufAxMoveRel(uint16 cardid,uint16 crd,uint16 axis,double dist,uint16 mode,uint32 segnum);
/*
指令功能：缓冲区坐标系外的轴设定点相对模式运动
输入参数：cardid	卡号，取值范围:[0,11]。
          crd	坐标系号，取值范围:[0,1]。	
		  axis 轴
		  mode，0： 缓冲区外设定点运动完成后才能继续缓冲区插补运动:1：启动缓冲区外轴设定点运动后继续缓冲区插补运动
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufAxMoveAbs(uint16 cardid,uint16 crd,uint16 axis,double dist,uint16 mode,uint32 segnum);
/*
指令功能：缓冲区坐标系外的轴设定点相对模式运动
输入参数：cardid	卡号，取值范围:[0,11]。
          crd	坐标系号，取值范围:[0,1]。	
		  axis 轴
		  mode，0： 缓冲区外设定点运动完成后才能继续缓冲区插补运动:1：启动缓冲区外轴设定点运动后继续缓冲区插补运动
输出参数：无
返回值：0或错误码*/
/*************************************************************************插补运动功能*********************************************************/


/*************************************************************************状态监测*********************************************************/
PLT_API short __stdcall Plt_AxGetMotionStatus(uint16 cardid,uint16 axis,uint16 *motionstatus);	
/*指令功能：读取指定轴的运动状态
输入参数：cardid	卡号，取值范围:[0,11]。
          axis	轴号，EI400\EI400S取值范围:[0,3];
                      EI800取值范围:[0,7];
                      EIC00取值范围:[0,11];
输出参数：*motionstatus	轴运动状态（0：运动中，1：停止）
返回值：0或错误码*/
PLT_API short __stdcall Plt_AxGetStatus(uint16 cardid,uint16 axis,uint16* mode,uint16 *stopreason);
/*指令功能：获取轴运动模式及停止原因
输入参数：cardid	卡号，取值范围:[0,11]。
          axis	轴号，EI400\EI400S取值范围:[0,3];
                      EI800取值范围:[0,7];
                      EIC00取值范围:[0,11];
输出参数：*status	轴运动模式（0：空闲，1：点位运动，2：JOG运动，3：回零运动，4：手轮运动，5：连续插补运动）
          *stopreason 停止原因
返回值：0或错误码*/
PLT_API short __stdcall Plt_AxGetMotionSpeed(uint16 cardid,uint16 axis,double *motionspeed);//读取各轴速度
/*指令功能：读取指定轴的运动速度
输入参数：cardid	卡号，取值范围:[0,11]。
          axis	轴号，EI400\EI400S取值范围:[0,3];
                      EI800取值范围:[0,7];
                      EIC00取值范围:[0,11];
输出参数：*motionspeed	速度值，单位:PPU/s
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdGetMotionSpeed(uint16 cardid,uint16 crd,double *motionspeed);
/*指令功能：读取指定轴的运动速度
输入参数：cardid	卡号，取值范围:[0,11]。
          crd	坐标系号，取值范围:[0,1]。	
输出参数：*motionspeed	坐标系合速度值，单位:PPU/s
返回值：0或错误码*/
PLT_API short __stdcall Plt_AxClearStatus(uint16 cardid,uint16 axis);
/*指令功能：清除停止原因
输入参数：cardid	卡号，取值范围:[0,11]。
          axis	轴号，EI400\EI400S取值范围:[0,3];
                      EI800取值范围:[0,7];
                      EIC00取值范围:[0,11];
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdBufGetStatus(uint16 cardid,uint16 crd,uint16 *crdstatus);
/*指令功能：获取插补运动的坐标系状态
输入参数：cardid	卡号，取值范围:[0,11]。
          crd	坐标系号，取值范围:[0,1]。	
输出参数：*crdstatus	坐标系状态（4:释放 3：建立；0：运动；1：暂停 2：停止；5：异常）
返回值：0或错误码*/
//设置坐标系到位误差
PLT_API short __stdcall Plt_CrdSetBand(uint16 cardid,uint16 crd,double *band,uint32 *hold_time,uint32 *check_time);
/*指令功能：设置坐标系轴到位误差
输入参数：  cardid 卡号
            crd 插补系号
            *band 误差带大小数组 即每轴允许的误差带 单位： ppu 
			*hold_time 脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带保持时间  每轴允许的保持时间数组，单位：ms
            check_time  脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带监测时间 每轴允许的检测时间数组，单位：ms
输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdGetBand(uint16 cardid,uint16 crd,double *band,uint32 *hold_time,uint32 *check_time);
/*指令功能：查询坐标系轴到位误差配置
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
输出参数：  *band 误差带大小数组 即每轴允许的误差带 单位： ppu 
			*hold_time 脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带保持时间  每轴允许的保持时间数组，单位：ms
            check_time  脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带监测时间 每轴允许的检测时间数组，单位：ms
返回值：0或错误码*/
PLT_API short __stdcall Plt_CrdGetBandFlag(uint16 cardid,uint16 crd,uint16 *band_flag);
/*指令功能：读取误差带标记
输入参数：  cardid	卡号，取值范围:[0,11]。
            crd	坐标系号，取值范围:[0,1]。	
输出参数：band_flag 1：坐标系中所有轴脉冲位置和编码器位置偏差绝对值落在设定误差带范围内大于等于设定的保持时间
	                0：坐标系轴正在运动中或者轴脉冲发送已经完毕但是脉冲位置和编码器位置偏差绝对值落在设定误差带范围内小于设定的保持时间
	                2：坐标系中至少有一个轴脉冲发送已经完毕但是误差带检查时间到时，脉冲位置和编码器位置偏差绝对值落在设定误差带范围内小于设定的保持时间
返回值：0或错误码*/
/*************************************************************************状态监测*********************************************************/
/*************************************************************************输入IO计数功能相关函数*********************************************************/
PLT_API short __stdcall  Plt_IoConfigInputCountMode(uint16 cardid,uint16 bitno,uint16 count_mode,double filter_time);
/*指令功能：设置输入IO计数模式
  输入参数：cardid	卡号，取值范围:[0,11]。
            bitno 输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			count_mode 计数模式  0：禁止输入IO计数  1：上升沿计数 2：下降沿计数
			filter_time 输入IO滤波时间 单位：ms 
  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_IoReadInputCountMode(uint16 cardid,uint16 bitno,uint16 *count_mode,double *filter_time);
/*指令功能：读取IO计数模式设置
  输入参数：cardid	卡号，取值范围:[0,11]。
            bitno 输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			
  输出参数：*count_mode 计数模式  0：禁止输入IO计数  1：上升沿计数 2：下降沿计数
			*filter_time 输入IO滤波时间 单位：ms 
返回值：0或错误码*/
PLT_API short __stdcall  Plt_IoSetInputCountValue(uint16 cardid,uint16 bitno,uint32 init_value);
/*指令功能：设置输入IO计数初始值
  输入参数：cardid	卡号，取值范围:[0,11]。
            bitno 输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			init_value 输入io计数初始值
  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_IoGetInputCountValue(uint16 cardid,uint16 bitno,uint32 *count_value);
/*指令功能：读取输入IO计数值
  输入参数：cardid	卡号，取值范围:[0,11]。
            bitno   输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
   输出参数：*count_value  当前输入io计数值
返回值：0或错误码*/
/*************************************************************************输入IO计数功能相关函数*********************************************************/
/*************************************************************************PWM功能相关函数*********************************************************/
PLT_API short __stdcall Plt_PwmSetPwmEnablFlag(uint16 card,uint16 pwmno,uint16 pwmflag);
/*指令功能：读取输入IO计数值
  输入参数：cardid	卡号，取值范围:[0,11]。
            bitno   输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
   输出参数：*count_value  当前输入io计数值
返回值：0或错误码*/
PLT_API short __stdcall Plt_PwmGetPwmEnablFlag(uint16 card,uint16 pwmno,uint16 *pwmflag);
PLT_API short __stdcall PLT_SetPwmOutMode(uint16 card, uint16 pwmno,uint16 out_mode);
/*指令功能：pwm输出模式
输入参数： cardid	卡号，取值范围:[0,11]。 
            pwmno  pwm通道号
			out_mode pwm输出模式  0：非跟随模式  1：跟随模式
输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall PLT_GetPwmOutMode(uint16 card, uint16 pwmno,uint16 *out_mode);
/*指令功能：读取PWM输出模式
输入参数：  card 卡号
             pwmno  pwm通道号
输出参数：  out_mode pwm输出模式  0：非跟随模式  1：跟随模式
返回值：0或错误码*/
PLT_API short __stdcall PLT_SetPwmOut(uint16 card, uint16 pwmno,double fDuty, double fFre);
PLT_API short __stdcall PLT_GetPwmOut(WORD card,WORD pwmno,double* fDuty, double* fFre);
PLT_API short __stdcall PLT_CrdBufSetPwmOut(uint16 card,uint16 crd,uint16 pwmno,double fDuty, double fFre,uint32 segnum);
PLT_API short __stdcall PLT_CrdBufSetPwmFollowParms(uint16 card,uint16 crd,uint16 pwmno,uint16 follow_mode,double min_power,double max_power,double ratio,double fix_value);
/*指令功能：设置pwm跟随参数
  输入参数：cardid	卡号，取值范围:[0,11]。 
            pwmno  pwm通道号
            follow_mode 跟随模式  0：占空比模式  1：频率模式
			min_power   最小能量值  min_power最小值为零
            max_power   最大能量值  当 follow_mode=0时，max_power可设最大值为1，当follow_mode=1时，max_power可设最大值为500KHZ
			ratio       能量跟随比率  实际跟随PWM值 x=ratio*vel+minPower
			fix_value   固定值  当follow_mode=0时 固定值为频率   当follow_mode=1时 固定值为占空比
   输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall PLT_CrdBufGetPwmFollowParms(uint16 card,uint16 crd,uint16 pwmno,uint16 *follow_mode,double *min_power,double *max_power,double *ratio,double *fix_value);
/*指令功能：读取pwm跟随参数
  输入参数：cardid	卡号，取值范围:[0,11]。 
            pwmno  pwm通道号
            
   输出参数：follow_mode 跟随模式  0：占空比模式  1：频率模式
			min_power   最小能量值  min_power最小值为零
            max_power   最大能量值  当 follow_mode=0时，max_power可设最大值为1，当follow_mode=1时，max_power可设最大值为500KHZ
			ratio       能量跟随比率  实际跟随PWM值 x=ratio*vel+minPower
			fix_value   固定值  当follow_mode=0时 固定值为频率   当follow_mode=1时 固定值为占空比
返回值：0或错误码*/
/*************************************************************************PWM功能相关函数*********************************************************/
/*************************************************************************AD功能*********************************************************/
PLT_API short __stdcall PLT_AdGetVol(uint16 card,uint16 channal_id,float *vol);
/*指令功能：设置输出电平
  输入参数：cardid	卡号，取值范围:[0,11]。 
            channal_id  通道号:有效值为0和1   
            
  输出参数： vol 输出电压值 范围[0,9.9]
返回值：0或错误码*/
/*************************************************************************AD功能*********************************************************/
/*************************************************************************DA功能*********************************************************/
PLT_API short __stdcall PLT_DaSetEnableFlag(uint16 card,uint16 channal_id,uint16 enable_flag);
/*指令功能：设置DA输出使能标志
  输入参数：cardid	卡号，取值范围:[0,11]。 
            channal_id  通道号:有效值为0和1 
            enable_flag 1：使能 0：禁止
  输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall PLT_DaGetEnableFlag(uint16 card,uint16 channal_id,uint16 *enable_flag);
/*指令功能：设置DA输出使能标志
  输入参数：cardid	卡号，取值范围:[0,11]。 
            channal_id  通道号:有效值为0和1   
            
  输出参数：enable_flag 1：使能 0：禁止
返回值：0或错误码*/
PLT_API short __stdcall PLT_DaSetVol(uint16 card,uint16 channal_id,float vol);
/*指令功能：设置输出电平
  输入参数：cardid	卡号，取值范围:[0,11]。  
            channal_id  通道号:有效值为0和1 
            vol 输出电压值 范围[0,9.9]
  输出参数： 无
返回值：0或错误码*/
PLT_API short __stdcall PLT_DaGetVol(uint16 card,uint16 channal_id,float *vol);
/*指令功能：设置输出电平
  输入参数：cardid	卡号，取值范围:[0,11]。 
            channal_id  通道号:有效值为0和1   
            
  输出参数： vol 输出电压值 范围[0,9.9]
返回值：0或错误码*/
/*************************************************************************DA功能*********************************************************/
/*************************************************************************CAN输入输出IO**********************************************************/
PLT_API short __stdcall Plt_IoSetMasterBaudrate(uint16 cardid,uint16 baudrate);
/*指令功能：设置EIX00控制卡CAN通讯波特率
//  输入参数：cardid	卡号，取值范围:[0,11]。 
//            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoGetMasterBaudrate(uint16 cardid,uint16 *baudrate);
/*指令功能：读取EIX00控制卡CAN通讯波特率
//  输入参数：cardid	卡号，取值范围:[0,11]。  
//           
//  输出参数： baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanReadInputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level); 	//读取指定can模块输入口的状态
/*指令功能：读取指定can模块某个输入口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
              bitno	输入IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//  输出参数：  *active_level 
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanWriteOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 active_level); 	//设置指定can模块输出口的状态
/*指令功能：设置指定can模块某个输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
              bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//			active_level 输出电平值  0和1
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanReadOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level);  	//读取指定can模块输出口的状态
/*指令功能：读取指定can模块某个输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
              bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//  输出参数：  *active_level
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanReadAllInput(uint16 cardid,uint16 can_id,uint32 *active_level_1); 	//读取指定can模块所有通用输入IO的值
/*指令功能：读取指定can模块所有通用输入IO的值
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
//            active_level	输入口0--31的状态, bit0对应IN0，bit31对应IN31 RCAN32I32O: bit0-bit31位都有效；RCAN16I16O: bit0-bit15位有效；
//  输出参数：  *active_level  active_level顺序从0到31代表0到31输入IO电平
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanReadAllOutput(uint16 cardid,uint16 can_id,uint32 *active_level); 	//读取指定can模块所有通用输出口的值
/*指令功能：读取指定can模块所有通用输出IO的值
//  输入参数cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
//            bitno IO口号 有效值为[0,31]
//			  active_level	输出口0--31的状态, bit0对应IN0，bit31对应IN31 RCAN32I32O: bit0-bit31位都有效；RCAN16I16O: bit0-bit15位有效；
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanWriteAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	//设置指定can模块所有通用输出口的值
/*指令功能：设置指定can模块所有输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
//           active_level	输出口0--31的状态, bit0对应IN0，bit31对应IN31 RCAN32I32O: bit0-bit31位都有效；RCAN16I16O: bit0-bit15位有效；
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanGetLinkState(uint16 cardid,uint16 can_id,uint16 *link_state);  	//读取指定can模块连接状态
/*指令功能：读取指定can模块连接状态
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。           
//  输出参数：  *link_state 连接状态 1：连接  0：断开
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanInitAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	
/*指令功能：设置指定can模块输出口初始电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
//			active_level  active_level顺序从0到31代表0到31输出IO初始电平
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanGetNodeType(uint16 cardid,uint16 can_id,uint16 *type);  	
/*指令功能：读取指定can模块节点类型
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
//  输出参数：type can模块节点类型  1：rcan1616 2:rcan3232
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanGetNodeVersion(uint16 cardid,uint16 can_id,uint16 *version);  	
/*指令功能：读取指定can模块节点类型
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
//  输出参数：version can模块节点固件版本号  
返回值：0或错误码*/
PLT_API short __stdcall Plt_IoCanReverseOutputBit(uint16 cardid,uint16 can_id,uint16 bitno,double hold_time);
/*指令功能：CANIO翻转
//  输入参数：cardid	卡号，取值范围:[0,11]。
              can_id	can模块序号, 取值范围:[0,7]。
			  bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
			  hold_time 翻转电平保持时间 单位：s
//  输出参数：无
返回值：0或错误码*/
/*************************************************************************CAN输入输出IO**********************************************************/

/*************************************************************************龙门同步控制**********************************************************/
PLT_API short __stdcall Plt_GantrySetEnable(uint16 cardid,uint16 master_axis_id,uint16 slave_axis_id,uint16 enable_flag);  	
/*指令功能：配置主轴和从轴龙门同步关系
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	  
			  slave_axis_id	    从轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	
			 enable_flag        主轴和从轴是否建立龙门同步关系  1：建立 0：解除
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_GantryGetEnable(uint16 cardid,uint16 master_axis_id,uint16 *slave_axis_id,uint16 *enable_flag);  	
/*指令功能：查询主轴和从轴是否存在龙门同步关系
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	  	
//  输出参数 *enable_flag       主轴和从轴是否建立龙门同步关系  1：建立 0：解除
             *slave_axis_id	    从轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	
返回值：0或错误码*/

PLT_API short __stdcall Plt_GantrySetParms(uint16 cardid,uint16 master_axis_id,double max_error,double encoder_factor,uint16 stop_mode);  	
/*指令功能：配置龙门同步轴组参数
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	  
			  max_error	        主轴和从轴允许的最大编码器偏差，单位：[PPU]
			  encoder_factor    输出同样脉冲，主轴编码器计数和从轴编码器计数比值
			  stop_mode         偏差超限停止方式 0：减速停止  1：立即停止
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_GantryGetParms(uint16 cardid,uint16 master_axis_id,double *max_error,double *encoder_factor,uint16 *stop_mode);  	
/*指令功能：获取龙门同步轴组参数
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	  
//输出参数：  *max_error	    主轴和从轴允许的最大编码器偏差，单位：[PPU]
			  *encoder_factor   输出同样脉冲，主轴编码器计数和从轴编码器计数比值
			  *stop_mode        偏差超限停止方式 0：减速停止  1：立即停止
返回值：0或错误码*/
PLT_API short __stdcall Plt_GantryGetError(uint16 cardid,uint16 master_axis_id,double *cur_error);  	
/*指令功能：获取龙门同步轴组当前编码器误差值
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];	  
//输出参数：  cur_error	        主轴和从轴允许的当前编码器偏差，单位：[PPU]
返回值：0或错误码*/
/*************************************************************************龙门同步控制**********************************************************/
/*************************************************************************测包机模块**********************************************************/
PLT_API short __stdcall  Plt_SetBlow(uint16 cardid,uint16 blow_num,uint16 blow_flag,uint32 cur_roll_num);	
/*指令功能：吹气/补料指令
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              blow_num	        检测站站号   0：CCD1  1：CCD2 2:空包检测ccd
              blow_flag         当 blow_num=0： 0：OK  1:NG 2:NC 当 blow_num=1：0：OK 1：补料  2：缺陷料  3：Mark料
			  cur_roll_num      当前个数
//输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_get_roller_finish_flag(uint16 cardid,uint16 blow_num,uint16 *flag);
/*功能描述：读取下位机CCD拍照计数清除标志
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              blow_num	        检测站站号   0：CCD1  1：CCD2 2:空包检测ccd
//输出参数：  flag              0：不要清除  1：需要清除
返回值：0或错误码*/
PLT_API short __stdcall  Plt_clear_roller_finish_flag(uint16 cardid,uint16 blow_num);
/*功能描述：通知下位机上位机CCD拍照计数已清除
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              blow_num	        检测站站号   0：CCD1  1：CCD2 2:空包检测ccd
//输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_SetInternetHeartBeat(uint16 cardid,uint32 beat_time);
/*功能描述：设置以太网通信监控心跳时间
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              beat_time         心跳时间  单位：[s]  最小值大于5s，如果设置的时间大于0之后，就意味着开启了以太网断线监控功能，如果在心跳时间内收不到上位机
			                    下发的数据，控制卡以太网模块会重新初始化，方便上位机可以重新打开卡。
//输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_SetCommand(uint16 cardid,uint32 command_id);
/*功能描述：通过以太网下发控制命令
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              command_id        
//输出参数：  无
返回值：0或错误码*/

PLT_API short __stdcall  Plt_GetTesterFinishFlag(uint16 cardid,uint16 *finish_flag);
/*功能描述：检测测试仪是否完成一次测试
//  输入参数：cardid	        卡号，取值范围:[0,11]。          
//输出参数：  finish_flag   0:测试仪测试没有完成  1：测试完成
返回值：0或错误码*/
PLT_API short __stdcall  Plt_SampleTest(uint16 cardid);
/*功能描述：测试仪样品测试命令
//  输入参数：cardid	        卡号，取值范围:[0,11]。          
返回值：0或错误码*/
PLT_API short __stdcall  Plt_SetTestDataFinisReadFlag(uint16 cardid);
/*功能描述：上位机完成读取测试仪结果数据,通知下位机
//  输入参数：cardid	        卡号，取值范围:[0,11]。          
返回值：0或错误码*/

PLT_API short __stdcall  Plt_AlineCommand(uint16 cardid,uint16 command_id);
/*功能描述：设置自动校准命令
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              command_id  1:校准开始   0：校准结束      
//输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_GetAlineRdyFlag(uint16 cardid,uint16 *flag);
/*功能描述：读取设备自动校准准备状态
//  输入参数：cardid	        卡号，取值范围:[0,11]。     
//输出参数：  flag 1：自动校准准备好(测试针顶到位) 0：自动校准没有准备好
返回值：0或错误码*/

PLT_API short __stdcall  Plt_GetSystemState(uint16 cardid,uint16 *state);
/*功能描述：读取设备状态
//  输入参数：cardid	        卡号，取值范围:[0,11]。     
//输出参数：  state 1：自动状态  4：手动状态  3 ：暂停状态
返回值：0或错误码*/
PLT_API short __stdcall  Plt_WriteRegister(uint16 cardid,uint32 address,long value);
/*功能描述：写寄存器
//  输入参数：cardid	        卡号，取值范围:[0,11]。 
             //5049    CCD1开关  value = 1开；value= 0关
			 //5050    CCD2开关  value = 1开；value= 0关
			 //3800    1963     指定缺陷到达报警     
返回值：0或错误码*/
PLT_API short __stdcall  Plt_ReadRegister(uint16 cardid,uint32 address,long *value);
/*功能描述：读寄存器
//  输入参数：cardid	        卡号，取值范围:[0,11]。
//输出参数：value
            //5049    CCD1开关  value = 1开；value= 0关
			//5050    CCD2开关  value = 1开；value= 0关
返回值：0或错误码*/
/*************************************************************************测包机模块**********************************************************/
/*************************************************************************RS485相关函数*********************************************************/
PLT_API short __stdcall  Plt_Rs485SetBound(uint16 cardid,uint32 bound);
/*
功能描述：设置RS485波特率
输入参数：cardid 卡号
          bound 波特率  可设置的波特率 9600 19200 38400 
输出参数：无
返回值：错误码  0：设置成功  2400：无效的波特率值*/
PLT_API short __stdcall  Plt_Rs485GetBound(uint16 cardid,uint32 *bound);
/*
功能描述：回读RS485波特率
输入参数：cardid 卡号       
输出参数：bound 波特率
返回值：错误码*/
PLT_API short __stdcall  Plt_Rs485SetDataReceiveTimeOut(uint16 cardid,uint16 time_out);
/*
功能描述：设置RS485从站设备收到控制卡发送的指令后，控制卡等待从站数据回传超时时间
输入参数：cardid 卡号
          time_out：超时时间 取值范围 [10,1000] 单位：ms
输出参数：无
返回值：错误码  0：设置成功  2401：无效的超时时间值*/
PLT_API short __stdcall  Plt_Rs485GetDataReceiveTimeOut(uint16 cardid,uint16 *time_out);
/*
功能描述：回读RS485波特率
输入参数：cardid 卡号       
输出参数：time_out：超时时间 
返回值：错误码*/

PLT_API short __stdcall  Plt_Rs485DataExchange(uint16 cardid,uint8 *data_send_buf,uint16 data_send_len,uint8 *data_receive_buf,uint16 *data_receive_len);
/*
功能描述：RS485发送若干个字节数据，并读取从站返回的数据
输入参数：cardid 卡号  
          data_send_buf 发送到RS485从站的数据
		  data_send_len 发送到RS485从站的数据长度，取值范围[1,100]
输出参数：data_receive_buf：从站返回的数据
          data_receive_len 从站返回的数据长度
返回值：错误码*/
/*************************************************************************RS485相关函数*********************************************************/
/******************************************************************ETHERCAT总线相关函数*********************************************************/
PLT_API short __stdcall Plt_EthercatDownLoadENIFile(uint16 cardid,const char *filename);
/*指令功能：下载ethercat从站网络配置文件
输入参数：  cardid	卡号，取值范围[0,11]。
	        *filename	新固件绝对路径。 注意：路径中不能有中文字符
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatSetNodeOd(uint16 cardid,uint16 slave_id,uint16 Index,uint16 SubIndex,uint16 length,uint32 Value);
/*指令功能：配置从站对象字典参数值
输入参数：  cardid	卡号，取值范围[0,11]。
	        slave_id 从站id号
			Index 对象字典索引
			SubIndex 对象字典子索引
			length 对象字典索引长度(单位： byte)
			Value 对象字典索引参数值
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatGetNodeOd(uint16 cardid,uint16 slave_id,uint16 Index,uint16 SubIndex,uint16 length,uint32 *Value);
/*指令功能：配置从站对象字典参数值
输入参数：  cardid	卡号，取值范围[0,11]。
	        slave_id 从站id号
			Index 对象字典索引
			SubIndex 对象字典子索引
			length 对象字典索引长度(单位： byte)
输出参数：	Value 对象字典索引参数值
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatGetSlaveCount(uint16 cardid,uint16 *count);
/*指令功能：读取ethercat网络系统从站个数
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	count 从站个数
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatGetSlaveAxisCount(uint16 cardid,uint16 *count);
/*指令功能：读取ethercat网络系统从站轴个数
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	count 从站轴个数
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatStart(uint16 cardid);
/*指令功能：启动控制器ethercat模块
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatStop(uint16 cardid);
/*指令功能：停止控制器ethercat模块
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatGetSlaveState(uint16 cardid,uint16 slave_id,uint16 *state);
/*指令功能：读取ethercat主站状态
输入参数：  cardid	卡号，取值范围[0,11]。
            slave_id 从站id号
输出参数：	state 主站状态  0：未初始化 1：初始化状态 2：预操作状态  3：启动状态  4：安全操作状态  8：操作状态  16：错误状态
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatGetAxis402State(uint16 cardid,uint16 slave_id,uint16 *state);
/*指令功能：读取ethercat从站轴402状态
输入参数：  cardid	卡号，取值范围[0,11]。
            slave_id 从站id号
输出参数：	state 从站轴402状态  
			NOT READY TO SWITCH ON 0x00
			SWITCHED ON DISABLED   0x40
			READY TO SWITCH ON     0x21
			SWITCHED ON            0x23
			OPERATION ENABLED      0x27
			QUICK STOP ACTIVE      0x07
			FAULT REACTION ACTIVE  0x0F
			FAULT                  0x08
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatClearAxis402Error(uint16 cardid,uint16 slave_id);
/*指令功能：ethercat轴站状态错误清除
输入参数：  cardid	卡号，取值范围[0,11]。
            slave_id 从站id号
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatGetSlaveInfo(uint16 cardid,uint16 slave_id,uint16 info_type,int8 *info);
/*指令功能：读取ethercat从站信息
输入参数：  cardid	卡号，取值范围[0,11]。
            slave_id 从站id号
			info_type 需要读取的从站信息类型
			 0 : 厂商ID
			 1:  厂商产品ID
			 2:  产品版本号
			 3：产品名称
			 4：配置位置
			 5：位置别名
输出参数：	无
返回：      0或错误码*/
PLT_API short __stdcall Plt_EthercatIoReadInputByBit(uint16 cardid,uint16 slave_id,uint16 bitno,uint16 *active_level); 	
/*指令功能：读取指定ethercat从站模块某个输入口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
              bitno	输入IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//  输出参数：  *active_level 
返回值：0或错误码*/
PLT_API short __stdcall Plt_EthercatIoWriteOutputByBit(uint16 cardid,uint16 slave_id,uint16 bitno,uint16 active_level); 	
/*指令功能：设置指定ethercat从站模块某个输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
              bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//			active_level 输出电平值  0和1
//  输出参数：无
返回值：0或错误码*/
PLT_API short __stdcall Plt_EthercatIoReadOutputByBit(uint16 cardid,uint16 slave_id,uint16 bitno,uint16 *active_level);  	
/*指令功能：读取指定ethercat从站模块某个输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
              bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//  输出参数：  *active_level
返回值：0或错误码*/
/******************************************************************ETHERCAT总线相关函数*********************************************************/
/*************************************************************************测试机相关函数**********************************************************/
PLT_API short __stdcall  Plt_TesterSetParam(uint16 cardid,uint16 param_id,uint32 param_value);	
/*指令功能：
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              param_id	        
              param_value       
  输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_TesterGetParam(uint16 cardid,uint16 param_id,uint32 *param_value);
/*功能描述：
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              param_id	        
  输出参数：  param_value       
返回值：0或错误码*/
PLT_API short __stdcall  Plt_TesterGetCdTextDataSingle(uint16 cardid,uint16 num,uint32 *bin);
PLT_API short __stdcall  Plt_TesterGetCdOkNgSum(uint16 cardid,uint32 *value);
PLT_API short __stdcall  Plt_TesterGetIrTextDataSum(uint16 cardid,uint16 num,uint32 *value);
PLT_API short __stdcall  Plt_TesterGetIrOkNgSum(uint16 cardid,uint16 num,uint32 *value);
PLT_API short __stdcall  Plt_TesterGetBlowBinNum(uint16 cardid,uint16 num,uint32 *value);
PLT_API short __stdcall  Plt_TesterSetBlowBinChoose(uint16 cardid,uint16 bin_id,uint16 data);
/*************************************************************************测试机相关函数**********************************************************/
PLT_API short __stdcall  Plt_WatchSetBufferDatasEnable(uint16 cardid,uint16 datas_id,uint16 enable_flag);
/*功能描述：使能/禁止数据自动采集，当设置使能时，同时会把缓冲区中存储的数据清除掉。
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	
			  enable_flag       1:使能 0：禁止
  输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_WatchConfigBufferParams(uint16 cardid,uint16 datas_id,double start_pos,double end_pos,uint32 time_period);
/*功能描述：读取控制卡底层自动采集的数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	
			  start_pos         采集开始位置，单位：脉冲当量单位 ppu
			  end_pos           采集结束位置，单位：脉冲当量单位 ppu
			  time_period       采集频率      单位：time_period ms/个
  输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_WatchReadBufferParams(uint16 cardid,uint16 datas_id,double *start_pos,double *end_pos,uint32 *time_period);
/*功能描述：读取控制卡底层自动采集的数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	 
  输出参数：  start_pos         采集开始位置，单位：脉冲当量单位 ppu
			  end_pos           采集结束位置，单位：脉冲当量单位 ppu
			  time_period       采集频率      单位：time_period ms/个
返回值：0或错误码*/
PLT_API short __stdcall  Plt_WatchGetBufferDatas(uint16 cardid,uint16 datas_id,uint32 datas_num,uint32 *act_datas_num,double *datas_buffer);
/*功能描述：读取控制卡底层自动采集的数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	
			  datas_num         需要读取的数据个数,一次最多可以读300个。
  输出参数：  act_datas_num     实际读取到的数据个数       
              datas_buffer      读取到的数据
返回值：0或错误码*/

/*************************************************************************看门狗功能相关函数*********************************************************/
PLT_API short __stdcall  Plt_SetHostWatchDog(uint16 cardid,uint16 enable,uint16 watchtime,uint16 do_total_num,uint16 *do_num,uint16 *do_logic);
/*
功能描述：设置看门狗参数
输入参数：cardid 卡号
          enable 看门狗使能标志 1：看门狗使能  0：看门狗禁止  默认是禁止
          watchtime 超时报警时间，单位[ms]
          do_total_num 超时报警时需要设置的输出IO口总数
          *do_num     超时报警时需要设置的输出IO口序号
          *do_logic    超时报警时需要设置的输出各个IO口电平
输出参数：无*/
PLT_API short __stdcall  Plt_GetHostWatchDog(uint16 cardid,uint16 *enable,uint16 *watchtime,uint16 *do_total_num,uint16 *do_num,uint16 *do_logic);
/*功能描述：读取看门狗参数*/
PLT_API short __stdcall  Plt_FeedHostWatchDog(uint16 cardid);
/*功能描述：在超时报警时间范围内不断调用此函数，以防止超时报警*/
PLT_API short __stdcall  Plt_InitHostWatchDog(uint16 cardid);
/*功能描述：看门狗功能复位，复位后如果需要再次启动看门狗功能，需要重新配置看门狗函数*/
/*************************************************************************看门狗功能相关函数*********************************************************/
/*************************************************************************自定义读写数据函数接口*********************************************************/
PLT_API short __stdcall  Plt_UserSetDatas(uint16 cardid,uint32 datas_id,uint32 datas_num,char *datas_buffer);
/*功能描述：写数据到下位机
  输入参数：  cardid	        卡号，取值范围:[0,11]。	
              datas_id          参数ID,用户可以参数id枚举自定义的参数
			  datas_num         需要写入的数据个数,一次最多可以写1200个。
			  datas_buffer      写到下位机的数据数组
  输出参数：  无
返回值：0或错误码*/
PLT_API short __stdcall  Plt_UserGetDatas(uint16 cardid,uint32 datas_id,uint32 *datas_num,char *datas_buffer);
/*功能描述：从下位机读数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。	
              datas_id          参数ID,用户可以参数id枚举自定义的参数	  
  输出参数：  datas_buffer      读取到的下位机的数据数组
              datas_num         返回读取的数据个数。	
返回值：0或错误码*/
/*************************************************************************自定义读写数据函数接口*********************************************************/
#ifdef __cplusplus
}
#endif

#endif
