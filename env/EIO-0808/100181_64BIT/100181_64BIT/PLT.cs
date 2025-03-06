using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace csPLT 
{
    public class PLT
    {   	
        [DllImport("PLT.dll", EntryPoint = "Plt_CardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen(UInt16 TotalCards, UInt16[] CardNameArray, UInt16[] Section, UInt16[] Host_id);
        /*指令功能：初始化控制卡
        输入参数：  TotalCards	卡的数量（打开卡的数量）
                    CardIdArray	卡号数组参数（根据IP地址第四位进行设置），各卡卡号不能重复，数组元素取值范围[0,11]。
                    Section	    IP地址第三段的号码（需与主机PC的地址一致）数组参数，控制卡出厂默认Section为167，数组元素取值范围[1,254]。
                    Host_id	    IP地址第四段的号码（由串口或指令设置）数组参数,控制卡出厂默认Host_id为120。数组元素取值范围[1,254]。
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardOpen_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen_extern(ref UInt16 TotalCards, UInt16[] CardTypeArray, UInt16[] Section, UInt16[] Host_id);
        /*指令功能：初始化控制卡
        输入参数：  Section	      IP地址第三段的号码（需与主机PC的地址一致）数组参数，控制卡出厂默认Section为167，数组元素取值范围[1,254]。
	                Host_id	      IP地址第四段的号码（由串口或指令设置）数组参数,控制卡出厂默认Host_id为120。数组元素取值范围[1,254]。       
        输出参数：	TotalCards	  卡的数量
                    CardTypeArray 成功打开的卡类型  0:轴卡  1：IO卡
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardOpen_extern_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen_extern_extern(ref UInt16 TotalCards, UInt16[] CardTypeArray, UInt16[] Section, UInt16[] Host_id, UInt32 time_out);
        /*指令功能：初始化控制卡
        输入参数：  Section	      IP地址第三段的号码（需与主机PC的地址一致）数组参数，控制卡出厂默认Section为167，数组元素取值范围[1,254]。
	                Host_id	      IP地址第四段的号码（由串口或指令设置）数组参数,控制卡出厂默认Host_id为120。数组元素取值范围[1,254]。 
			        time_out      网络连接超时时间 单位 s
        输出参数：	TotalCards	  卡的数量
                    CardTypeArray 成功打开的卡类型  0:轴卡  1：IO卡
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardClose();	
        /*指令功能：关闭控制卡
        输入参数：  无
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardReset", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardReset();
        /*指令功能：复位控制卡
        输入参数：  无
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_ACardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_ACardOpen(UInt16 cardid,UInt16 Section,UInt16 Host_id);
        /*指令功能：初始化一个控制卡
        输入参数：  cardid	卡号，取值范围[0,11]。
	                Section	IP地址第三段的号码（需与主机PC的地址一致），控制卡出厂默认Section为167，取值范围[1,254]。
	                Host_id	IP地址第四段的号码（由串口或指令设置）控制卡出厂默认Host_id为120，取值范围[1,254]。
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_ACardOpen_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_ACardOpen_extern(UInt16 cardid,UInt16 Section,UInt16 Host_id,UInt32 time_out);
        /*指令功能：初始化一个控制卡
        输入参数：  cardid	卡号，取值范围[0,11]。
	                Section	IP地址第三段的号码（需与主机PC的地址一致），控制卡出厂默认Section为167，取值范围[1,254]。
	                Host_id	IP地址第四段的号码（由串口或指令设置）控制卡出厂默认Host_id为120，取值范围[1,254]。
         *          time_out 网络连接超时时间 单位 s
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_ACardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_ACardClose(UInt16 cardid);	//关闭控制卡
        /*指令功能：关闭一个控制卡
        输入参数： cardid	卡号，取值范围[0,11]。
        输出参数： 无
        返回：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardGetVerson", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetVerson(UInt16 cardid,ref UInt32 verson1,ref UInt32 verson2,ref UInt32 verson3);
        /*指令功能：读取相关版本号
        输入参数：  cardid	卡号，取值范围[0,11]。
        输出参数：	*verson1	FPGA版本号
                    *verson2	固件版本号
                    *verson3	动态链接库版本号
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_GetCardSerialNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_GetCardSerialNum(UInt16 cardid,ref UInt32 SerialNum_0,ref UInt32 SerialNum_1,ref UInt32 SerialNum_2); 
        /*指令功能：读取控制卡96位序列号
        输入参数：  cardid	卡号，取值范围[0,11]。
        输出参数：	SerialNum_0	序列号0-31位
	                SerialNum_1	序列号32-63位
			        SerialNum_2	序列号64-95位
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardReadCommincationState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardReadCommincationState(UInt16 cardid, ref UInt16 state);	
        /*指令功能：读取PC机和运动控制卡连接状态
        输入参数：  cardid	卡号，取值范围[0,11]。
        输出参数：	*state	PC机和运动控制卡连接状态 1：连接  0：断开
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardGetCardAxisNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetCardAxisNum(UInt16 cardid, ref UInt16 axisnum);
        /*指令功能：读取卡的轴数
        输入参数：  cardid	卡号，取值范围[0,11]。
        输出参数：  *axisnum	控制卡的轴数
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardUpdataFirmare", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardUpdataFirmare(UInt16 cardid, String filename);
        /*指令功能：控制卡固件更新
        输入参数：  cardid	卡号，取值范围[0,11]。
	                *filename	新固件绝对路径。 注意：路径中不能有中文字符
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardParmsFileConfig", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardParmsFileConfig(UInt16 cardid,String ParmsFile);
        /*指令功能：配置运动控制卡
        输入参数：  cardid	卡号，取值范围[0,11]。
	                *ParmsFile	配置文件 注意：路径必须是绝对路径，且路径中不能出现中文字符
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "PLT_GCodeFileProcess", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_GCodeFileProcess(UInt16 cardid,String FileName);//G代码文件解释

        [DllImport("PLT.dll", EntryPoint = "Plt_CardReSetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardReSetIP(UInt16 cardid, UInt16 section_3, UInt16 section_4);
        /*指令功能：设置控制卡IP地址
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                section_3	IP地址第三段值（需与主机PC的地址一致）控制卡出厂默认Section为167，取值范围[1,254]。
			        section_4   IP地址第四段值（需与主机PC的地址一致）控制卡出厂默认Section为120，取值范围[1,254]。
        输出参数：	无
            说明：	新设置的IP地址在控制卡重新上电后起效
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardGetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetIP(UInt16 cardid, ref UInt16 section_3, ref UInt16 section_4);
        /*指令功能：回读控制卡设置的IP地址
        输入参数：  cardid	卡号，取值范围[0,11]。
        输出参数：	*section_3	IP地址第三段值，控制卡出厂默认Section为167
                    *section_4	IP地址第四段值，控制卡出厂默认Section为120
        返回：      0或错误码*/

        //轴相关函数
        //脉冲模式	
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetPulseOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetPulseOutMode(UInt16 cardid,UInt16 axis,UInt16 mode);	
        /*指令功能：设定脉冲输出模式
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        mode	    脉冲输出模式，取值范围：0、2、4、6。各种脉冲模式的具体波形参考编程手册“3.4脉冲模式”一节
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetPulseOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetPulseOutMode(UInt16 cardid,UInt16 axis,ref UInt16 mode);	
        /*指令功能：读取脉冲输出模式
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*mode	    脉冲输出模式，取值范围：0、2、4、6。各种脉冲模式的具体波形参考编程手册“3.4脉冲模式”一节
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEncoderInMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetEncoderInMode(UInt16 cardid,UInt16 axis,UInt16 mode);  
        /*指令功能：设定编码器输入计数模式
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        mode	    编码器输入计数模式  取值范围:[0,3]  0：脉冲+方向   1：1倍频 2:2倍频  3:4倍频
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEncoderInMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetEncoderInMode(UInt16 cardid,UInt16 axis,ref UInt16 mode); 
        /*指令功能：读取编码器输入计数模式
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*mode	    编码器输入计数模式
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEncoderInNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetEncoderInNegation(UInt16 cardid, UInt16 axis, UInt16 mode);  
        /*指令功能：设定编码器计数方向
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        mode	    编码器计数方向  取值范围:[0,1]  0：EA超前EB正计数   1：EA超前EB负计数
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEncoderInNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetEncoderInNegation(UInt16 cardid, UInt16 axis, ref UInt16 mode); 
        /*指令功能：读取编码器计数方向
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*mode	   编码器计数方向
        返回：      0或错误码*/
        //脉冲当量
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetPPU", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetPPU(UInt16 cardid,UInt16 axis, double PPU);
        /*指令功能：设定脉冲当量
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        PPU	脉冲当量值（用户单位对应的脉冲数）
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetPPU", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetPPU(UInt16 cardid,UInt16 axis, ref double PPU);
        /*指令功能：读取脉冲当量
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*PPU	    脉冲当量值（用户单位对应的脉冲数）
        返回：      0或错误码*/

        //反向间隙
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetBacklash", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetBacklash(UInt16 card,UInt16 axis,double backlash);
        /*指令功能：设置反向间隙参数
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        backlash	反向间隙值，单位：脉冲当量单位 PPU
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AXGetBacklash", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AXGetBacklash(UInt16 cardid,UInt16 axis,ref double backlash);
        /*指令功能：查询反向间隙参数
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*backlash	反向间隙值
        返回：      0或错误码*/

        //极限值设置和获取
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetLimitSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetLimitSpeed(UInt16 cardid,UInt16 axis,double speed);
        /*指令功能：设置轴的极限速度
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        speed	    轴的极限速度 ，单位：ppu/s
        输出参数：	无
        返回：      0或错误码*/
       [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLimitSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetLimitSpeed(UInt16 cardid,UInt16 axis,ref double speed);
       /*指令功能：读取轴的极限速度
        输入参数：  cardid	    卡号，取值范围[0,11]。
                   axis	    轴号，EI400\EI400S取值范围:[0,3];
                               EI800取值范围:[0,7];
                               EIC00取值范围:[0,11];
        输出参数：	*speed	    轴的极限速度 ，单位：ppu/s
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetLimitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetLimitAcc(UInt16 cardid,UInt16 axis,double acc);
        /*指令功能：设置轴的极限加速度
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        acc	        轴的极限加速度
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLimitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetLimitAcc(UInt16 cardid,UInt16 axis,ref double acc);
        /*指令功能：读取轴的极限加速度
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*acc	    轴的极限加速度
        返回：      0或错误码*/

        //当前位置
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetCmmandPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetCmmandPosition(UInt16 cardid, UInt16 axis, double pos);
        /*指令功能：设置轴的指令位置
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        pos	        指令位置值
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetCmmandPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetCmmandPosition(UInt16 cardid,UInt16 axis, ref double pos);
        /*指令功能：查询轴的指令位置
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*pos	    指令位置值
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEncoderPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetEncoderPosition(UInt16 cardid,UInt16 axis, double pos);
        /*指令功能：设置编码器位置
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
			        pos	        编码器设定值
        输出参数：	无
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEncoderPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetEncoderPosition(UInt16 cardid,UInt16 axis, ref double pos);
        /*指令功能：读取编码器位置
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*pos	    编码器位置
        返回：      0或错误码*/

        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetBand(UInt16 cardid, UInt16 axis, double band, UInt32 hold_time, UInt32 check_time);
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
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetBand(UInt16 cardid, UInt16 axis, ref double band, ref UInt32 hold_time, ref UInt32 check_time);
        /*指令功能：查询轴到位误差配置
        输入参数：  cardid	    卡号，取值范围[0,11]。
	                axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*band	误差带，单位：PPU
                    *hold_time	编码器位置进入误差带最小保持时间 单位：ms
			        *check_time	轴到位最大检测时间 单位：ms
        返回：      0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetBandFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetBandFlag(UInt16 cardid, UInt16 axis, ref UInt16 band_flag);
        /*指令功能：读取单轴误差带标志
        输入参数：  cardid	    卡号，取值范围[0,11]。
                    axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：	*band_flag	0：定位中
                                1：定位完成
                                2：定位失败
        返回：      0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetBandLocationTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetBandLocationTime(UInt16 cardid, UInt16 axis, ref UInt32 location_time);
        /*指令功能：读取误差带定位时间
        输入参数：  cardid	    卡号，取值范围[0,11]。
                    axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：  *location_time  当前延时时间（从脉冲发送完成开始计算）                 单位：ms
        返回：      0或错误码*/

        [DllImport("PLT.dll", EntryPoint = "Plt_AxCheckEncoderDirResever", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxCheckEncoderDirResever(UInt16 cardid, UInt16 axis, UInt32 hold_time);
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
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetCheckEncoderDirResever", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetCheckEncoderDirResever(UInt16 cardid, UInt16 axis, ref UInt32 hold_time);
        /*指令功能：检查编码器运动方向是否与脉冲方向相反的参数查询
        输入参数：  cardid	    卡号，取值范围[0,11]。
                    axis	    轴号，EI400\EI400S取值范围:[0,3];
                                EI800取值范围:[0,7];
                                EIC00取值范围:[0,11];
        输出参数：  *hold_time	方向相反保持时间 单位：ms
        返回：      0或错误码*/
        /*************************************************************************安全保护***************************************************************/
         public struct struct_el_parms
        {
            public UInt16 pel_enable;//正限位使能；0：正限位禁止；1：正限位使能
            public UInt16 mel_enable;//负限位使能；0：负限位禁止；1：负限位使能
            public UInt16 pel_active_level;//正限位有效电平；0：低电平有效；1：高电平有效
            public UInt16 mel_active_level;//负限位有效电平；0：低电平有效；1：高电平有效
            public UInt16 pel_react;//正限位有效停止方式；0：立即停止；1：减速停止
            public UInt16 mel_react;//正限位有效停止方式；0：立即停止；1：减速停止
        }; //硬限位参数结构体

        public struct struct_sw_el_parms
        {
            public double melpos;//负软限位位置，单位:[ppu]
            public double pelpos;//正软限位位置，单位:[ppu]
            public UInt16 enable;//软限位使能；0：软限位禁止；1：负限位使能
            public UInt16 react;//软限位有效停止方式；0：立即停止；1：减速停止
        };//软限位参数结构体
     [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEl", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxSetEl(UInt16 cardid,UInt16 axis,struct_el_parms elparms); 
     /*指令功能：设置硬件限位
     输入参数：  cardid	    卡号，取值范围[0,11]。
                 axis	    轴号，EI400\EI400S取值范围:[0,3];
                             EI800取值范围:[0,7];
                             EIC00取值范围:[0,11];
                 elparms	    硬限位参数
     输出参数：	无
     返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEl", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxGetEl(UInt16 cardid,UInt16 axis,ref struct_el_parms elparms);
     /*指令功能：读取硬件限位的设置
     输入参数：  cardid	    卡号，取值范围[0,11]。
                 axis	    轴号，EI400\EI400S取值范围:[0,3];
                             EI800取值范围:[0,7];
                             EIC00取值范围:[0,11];
     输出参数：	*elparms	硬限位参数
     返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxSetSWEL", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxSetSWEL(UInt16 cardid,UInt16 axis,struct_sw_el_parms swelparms);
     /*指令功能：设置软件限位
    输入参数：  cardid	    卡号，取值范围[0,11]。
             axis	    轴号，EI400\EI400S取值范围:[0,3];
                         EI800取值范围:[0,7];
                         EIC00取值范围:[0,11];
             swelparms	软件限位参数
    输出参数：	无
    返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxGetSWEL", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxGetSWEL(UInt16 cardid,UInt16 axis,ref struct_sw_el_parms swelparms);
     /*指令功能：读取软件限位的设置
    输入参数：  cardid	    卡号，取值范围[0,11]。
             axis	    轴号，EI400\EI400S取值范围:[0,3];
                         EI800取值范围:[0,7];
                         EIC00取值范围:[0,11];
    输出参数：	*swelparms	软件限位参数
    返回：      0或错误码*/
/*************************************************************************安全保护***************************************************************/

/*************************************************************************专用接口***************************************************************/
    public struct struct_special_input_parms
    {
        public UInt16 emg_enable;//emg使能开关；0：使能禁止 1：使能有效
        public UInt16 emg_level;//emg有效电平；0：低电平有效；1：高电平有效
        public UInt16 emg_port;//映射为EMG的输入IO口   取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
        public UInt16 alm_enable;//alm使能开关；0：使能禁止 1：使能有效
        public UInt16 alm_level;//alm有效电平；0：低电平有效；1：高电平有效
        public double filter_time;//输入信号滤波时间；单位[ms]
        public UInt16 inp_enable;//inp使能开关；0：使能禁止 1：使能有效
        public UInt16 inp_level;//inp有效电平；0：低电平有效；1：高电平有效
    };//

    public struct struct_special_input_status
    {
        public UInt16 alm_status;//alm状态；0:无效；1：有效
        public UInt16 el_pos_status;//正限位状态；0:无效；1：有效
        public UInt16 el_neg_status;//负限位状态；0:无效；1：有效
        public UInt16 swel_pos_status;//正软限位状态；0:无效；1：有效
        public UInt16 swel_neg_status;//负软限位状态；0:无效；1：有效
        public UInt16 emg_status;//emg状态；0:无效；1：有效
        public UInt16 home_status;//原点状态；0:无效；1：有效
        public UInt16 inp_status;//inp状态；0:无效；1：有效
        public UInt16 ez_status;//ez状态；0:无效；1：有效
        public UInt16 rdy_status;//rdy状态；0:无效；1：有效
    };//专用输入状态
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigSpecialInputParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigSpecialInputParms(UInt16 cardid,UInt16 axis,struct_special_input_parms specinput);
    /*指令功能：配置EMG\ERC\INP\ALM等信号和滤波时间
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
			    specinput	专用输入配置
    输出参数：	无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadSpecialInputParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadSpecialInputParms(UInt16 cardid,UInt16 axis,ref struct_special_input_parms specinput);
    /*指令功能：读取EMG\ERC\INP\ALM等信号和滤波时间的配置
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
    输出参数：	*specinput	专用输入配置
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadSpecialInputStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadSpecialInputStatus(UInt16 cardid,UInt16 axis,ref struct_special_input_status inputstatus);
    /*指令功能：读取轴专用输入信号状态
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
    输出参数：	*inputstatus	专用输入状态
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetsvonPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetsvonPort(UInt16 cardid,UInt16 axis,UInt16 active_level);
    /*指令功能：输出SEVON信号
    输入参数：  cardid	    卡号，取值范围[0,11]。
                axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
                active_level	SERV-ON输出电平值 0:低电平 1：高电平
    输出参数：	无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetsvonPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetsvonPort(UInt16 cardid,UInt16 axis,ref UInt16 active_level);
    /*指令功能：获取SEVON信号
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
    输出参数：	*active_level	SERV-ON输出电平值 0:低电平 1：高电平
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetRdyPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetRdyPort(UInt16 cardid,UInt16 axis,ref UInt16 active_level);
    /*指令功能：获取RDY信号（此函数保留）
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
    输出参数：	*active_level	RDY信号输入值 0:低电平 1：高电平
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetErcPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetErcPort(UInt16 cardid,UInt16 axis,UInt16 active_level);
    /*指令功能：控制ERC信号输出电平
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
			    active_level	ERC信号输出值	0:低电平 1：高电平
    输出参数：	无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetErcPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetErcPort(UInt16 cardid,UInt16 axis,ref UInt16 active_level);
    /*指令功能：获取控制ERC信号输出电平
    输入参数：  cardid	    卡号，取值范围[0,11]。
	            axis	    轴号，EI400\EI400S取值范围:[0,3];
                            EI800取值范围:[0,7];
                            EIC00取值范围:[0,11];
    输出参数：	*active_level	ERC信号输出值 0:低电平 1：高电平
    返回：      0或错误码*/
/*************************************************************************专用接口***************************************************************/

/*************************************************************************输入IO复用功能*********************************************************/
    public struct struct_original_type
    {
        public UInt16 type;//0：正限位 1：负限位 2：原点 3：伺服报警  4：伺服准备 5：伺服到位 6:通用输入IO
        public UInt16 axis;//轴号.EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];type 小于6时此参数有效
        public UInt16 bitno;//通用输入IO序号，EI400\EI400S:[0,31]，EI800\EIC00:[0,15];type等于6时此参数有效
        public double Filter;//滤波时间，单位[ms]
    };//原始输入IO类型
    public struct struct_reuse_type
    {
        public UInt16 axis;//轴号,EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
        public UInt16 type;//0：正限位 1：负限位 2：原点 3：急停  4：减速停止 5：伺服报警 6:伺服准备 7:伺服到位
    };//复用输入IO类型
    [DllImport("PLT.dll", EntryPoint = "PLT_IoSet_input_reuse_to_special_input", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoSet_input_reuse_to_special_input(UInt16 cardid,struct_original_type original_type,struct_reuse_type reuse_type);
    /*指令功能：通用输入IO或者专用输入IO复用为专用输入IO
    输入参数：  cardid	    卡号，取值范围[0,11]。
                original_type 被复用的通用输入IO序号或者专用输入IO参数
                reuse_type    复用后的专用输入IO参数
    输出参数：无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoSet_special_input_reuse_to_input_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoSet_special_input_reuse_to_input_extern(UInt16 cardid,struct_original_type original_type,UInt16 bitno);
    /*功能描述：专用输入IO复用为通用输入IO
   输入参数：  cardid	    卡号，取值范围[0,11]。
               original_type 专用输入IO类型
               bitno 复用后IO编号     EI400\EI400S取值范围:[0,23];
                                      EI800取值范围:[0,47];
                                      EIC00取值范围:[0,71];
   输出参数：无
   返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoGet_special_input_reuse", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoGet_special_input_reuse(UInt16 cardid,struct_reuse_type reuse_type,ref struct_original_type original_type);
    /*指令功能：读取轴专用输入IO复用配置
    输入参数：  cardid	    卡号，取值范围[0,11]。
                reuse_type复用输入IO类型
    输出参数：  original_type  原始输入IO类型
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoGet_input_extern_reuse", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoGet_input_extern_reuse(UInt16 cardid,UInt16 bitno,ref struct_original_type original_type);
    /*指令功能：读取扩展输入IO复用配置
    输入参数：  cardid	    卡号，取值范围[0,11]。
                bitno       EI400\EI400S取值范围:[0,23];
                            EI800取值范围:[0,47];
                            EIC00取值范围:[0,71];
    输出参数：  *original_type 原始输入IO类型
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoRead_input_reuse_bybit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoRead_input_reuse_bybit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level);
    /*指令功能：读取复用输入IO状态
    输入参数：  cardid	    卡号，取值范围[0,11]。
                bitno       EI400\EI400S取值范围:[0,23];
                            EI800取值范围:[0,47];
                            EIC00取值范围:[0,71];
    输出参数：  *active_level 复用输入IO的值
    返回：      0或错误码*/
/*************************************************************************输入IO复用功能*****************************************************/


/*************************************************************************通用输入输出IO**********************************************************/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadInputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level); 	
    /*指令功能：读取输入口的状态
    输入参数：  cardid	    卡号，取值范围[0,11]。
                bitno       输入口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
    输出参数：  *active_level 输入口状态 0：低电平  1：高电平
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoWriteOutputByBit(UInt16 cardid,UInt16 bitno,UInt16 active_level); 	
    /*指令功能：设置输出口的状态
    输入参数：  cardid	    卡号，取值范围[0,11]。
                bitno       输出口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			    active_level 输出口输出状态 0：低电平  1：高电平
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadOutputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level);  
    /*指令功能：读取输出口的状态
    输入参数：  cardid	    卡号，取值范围[0,11]。
                bitno       输出口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
    输出参数：  *active_level 输出口状态 0：低电平  1：高电平
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadAllInput(UInt16 cardid,ref UInt32 active_level_1,ref UInt32 active_level_2);
    /*指令功能：读取输入端口的值
    输入参数：  cardid	    卡号，取值范围[0,11]。
    输出参数：  *active_level_1	输入口0--31的状态, bit0对应IN0，bit31对应IN31
                                EI400\EI400S: bit0-bit31位都有效；
                                EI800\EIC00: bit0-bit15位有效；
                *active_level_2	输入口32--63的状态, bit0对应IN32，bit31对应IN63（保留）
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadAllOutput(UInt16 cardid,ref UInt32 active_level);
    /*指令功能：读取输出端口的值
    输入参数：  cardid	                卡号，取值范围[0,11]。
    输出参数：  *active_level           所有输出口0--31的状态, bit0对应OUT0，bit31对应OUT31
                                        EI400\EI400S: bit0-bit31位都有效；
                                       EI800\EIC00: bit0-bit15位有效；
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoWriteAllOutput(UInt16 cardid,UInt32 active_level);
    /*指令功能：设置输出端口的值
    输入参数：  cardid	                卡号，取值范围[0,11]。
               active_level	            所有输出口的输出状态, bit0对应OUT0，bit31对应OUT31
                                        EI400\EI400S: bit0-bit31位都有效；
                                        EI800\EIC00: bit0-bit15位有效；
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReverseOutputBit(UInt16 cardid,UInt16 bitno,double hold_time);
    /*指令功能：翻转当前输出口的状态,并保持设定时间后恢复回翻转前的状态
    输入参数：  cardid	                卡号，取值范围[0,11]。
                bitno       输出口编号,取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
                hold_time	电平保持时间，单位：ms
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoInitOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoInitOutputBit(UInt16 cardid);
    /*指令功能：把当前输出IO初始电平设置下次控制器上电后输出IO的初始电平（各通用输出IO初始电平由控制卡当前通用输出IO电平决定，函数不用设置控制卡重新上电生效）
    输入参数：  cardid	                卡号，取值范围[0,11]。
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoInitALLOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoInitALLOutput(UInt16 cardid, UInt32 active_level);
    /*指令功能：设置输出IO初始电平（各通用输出IO初始电平由此函数设置，控制卡重新上电生效）
    输入参数：  cardid	                卡号，取值范围[0,11]。
                active_level	所有输出口0--31的状态, bit0对应OUT0，bit31对应OUT31
                EI400\EI400S: bit0-bit31位都有效；
                EI800\EIC00: bit0-bit15位有效；
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoSetOutputMap", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoSetOutputMap(UInt16 cardid, UInt16 logic_output_num, UInt16 physical_out_num);
    /*指令功能：设置通用输出IO映射
      输入参数：  cardid 卡号，取值范围:[0,11]。
                  logic_output_num 逻辑输出IO口序号
                  physical_out_num 实际输出的板卡物理IO口序号
      输出参数：  无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoGetOutputMap", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoGetOutputMap(UInt16 cardid, UInt16 logic_output_num, ref UInt16 physical_out_num);
    /*指令功能：查询通用输出IO映射
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *logic_output_num 逻辑输出IO口序号
                *physical_out_num 实际输出的板卡物理IO口序号
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoSetNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoSetNegation(UInt16 cardid, UInt32 output_negation, UInt32 input_negation);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_IoGetNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoGetNegation(UInt16 cardid, ref UInt32 output_negation, ref UInt32 input_negation);
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
			    freq           输出频率
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoOutputPulses", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoOutputPulses(UInt16 cardid, UInt32 pulse_num, UInt32 hold_time);
    /*指令功能：停止连续输出设定个数脉冲
    输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoOutputPulsesStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoOutputPulsesStop(UInt16 cardid);
    [DllImport("PLT.dll", EntryPoint = "Plt_Io_set_check_input_for_output", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_Io_set_check_input_for_output(UInt16 cardid, UInt16 input_id, UInt16 enable_flag, UInt16 input_logic, UInt16 output_id, UInt16 output_logic);
    /*指令功能：设置等待到某个输入IO设定的输入电平时，特定的输出IO输出设置的电平
    输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
                input_id: 输入IO序号[0,7]
			    enable_flag: 1:开启此功能  0：关闭此功能
			    input_logic：等待的输入IO电平
			    output_id：输出IO序号[0,7]
			    output_logic：输出电平
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_Io_get_check_input_for_output", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_Io_get_check_input_for_output(UInt16 cardid, UInt16 input_id, ref UInt16 enable_flag, ref UInt16 input_logic, ref UInt16 output_id, ref UInt16 output_logic);
    /*指令功能：读取等待到某个输入IO设定的输入电平时，特定的输出IO输出设置的电平
    输入参数：  cardid 卡号，  取值范围:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
                input_id: 输入IO序号[0,7]
    输出参数：  enable_flag: 1:开启此功能  0：关闭此功能
			    input_logic：等待的输入IO电平
			    output_id：输出IO序号[0,7]
			    output_logic：输出电平
    返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_IoSetInputFieterTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoSetInputFieterTime(UInt16 cardid, UInt16 bitno, double hold_time); 
        /*指令功能：设置输入IO滤波时间,目前此函数只支持EIO0808
        输入参数：  cardid	                卡号，取值范围[0,11]。
                    bitno       输入口编号,取值范围：[0,7]
			        hold_time	滤波时间时间，单位：s
        输出参数：  无
        返回：      0或错误码*/ 
/*************************************************************************通用输入输出IO**********************************************************/

/*************************************************************************一维位置比较功能*********************************************************/
    public struct struct_axis_compare_parms
    {
        public UInt16 cmp_axis;//比较轴号 ,EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
        public UInt16 enable;//比较使能开关；0：比较禁止；1：比较允许
        public UInt16 cmp_source;//比较源 0：理论位置 1：编码器位置
    };//单轴位置比较配置参数结构体
    public struct struct_axis_compare_datas
    {
        public double cmpposition; //比较位置，单位：[pulse]
        public UInt16 cmpmethod; //比较方法：0：大于等于；1：小于等于
        public UInt16 reaction;//比较动作;0：设定io号电平取反；1：设定io号输出低电平；2：设定IO号输出高电平；3：设定io号输出设定时间宽度的脉冲；4：设定轴减速停止；5：设定轴立即停止
        public double pulsewidth;//脉冲宽度；单位：[ms]
        public UInt16 react_object;//设定io号或者设定轴
    };//单轴比较缓冲区数据
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareSetParms(UInt16 cardid, UInt16 cmpno, struct_axis_compare_parms axcmpparms);
    /*指令功能：配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
                axcmpparms	一维位置比较配置参数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetParms(UInt16 cardid, UInt16 cmpno, ref struct_axis_compare_parms axcmpparms);
    /*指令功能：读取配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
    输出参数：  *axcmpparms	一维位置比较配置参数
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareClearBuf(UInt16 cardid,UInt16 cmpno);
    /*指令功能：清除比较器所有比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareSetData(UInt16 cardid, UInt16 cmpno, struct_axis_compare_datas axcmpdata);
    /*指令功能：添加比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
                axcmpdata	比较位置参数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetData(UInt16 cardid,UInt16 cmpno,ref double cmpposition);
    /*指令功能：读取当前比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
                *cmpposition	返回下一个即将进行的比较点
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetComparedDataNum(UInt16 cardid,UInt16 cmpno,ref Int32 num);
    /*指令功能：查询已经比较过的点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
                *num	已经进行了比较的位置个数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetBufRemain(UInt16 cardid,UInt16 cmpno,ref Int32 space);
    /*指令功能：查询可以加入的比较点数量
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号 取值范围：[0,11]
                *space	剩余比较空间
    输出参数：  无
    返回：      0或错误码*/
/*************************************************************************一维位置比较功能*********************************************************/
/*************************************************************************二维位置比较功能*********************************************************/
    public struct struct_crd_compare_datas
    {
       [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 2)]
       public UInt16[] axis_array;//比较轴列表 取值范围：EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7]; EIC00取值范围:[0,11];
       [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 2)]
       public double[] cmpposition_array;//比较位置列表
       [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 2)]
       public UInt16[] cmpmethod_array;//比较方法：0：大于等于；1：小于等于
       public UInt16 reaction;//比较动作;0：设定io号电平取反；1：设定io号输出低电平；2：设定IO号输出高电平；3：设定io号输出设定时间宽度的脉冲；4：设定轴减速停止；5：设定轴立即停止
       public double pulsewidth;//脉冲宽度；单位：[ms]
       public UInt16 react_object;//设定io号或者设定轴
    };//二维比较缓冲区数据
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdcCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdcCompareSetParms(UInt16 cardid, UInt16 enable, UInt16 cmp_source); 	
    /*指令功能：配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
                enable	二维比较是否使能  1：使能 0：禁止
                cmp_source 比较源 0：脉冲计数 1：编码器计数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdcCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdcCompareGetParms(UInt16 cardid, ref UInt16 enable, ref UInt16 cmp_source);
    /*指令功能：读取配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *enable	二维比较是否使能  1：使能 0：禁止
                *cmp_source 比较源 0：脉冲计数 1：编码器计数
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareClearBuf(UInt16 cardid); 
    /*指令功能：清除所有比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareSetData(UInt16 cardid, struct_crd_compare_datas crdcmpdata);
    /*指令功能：添加比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                crdcmpdata 比较点参数结构体
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareGetData(UInt16 cardid, ref UInt16[] axis_array, ref double[] cmpposition_array); 
    /*指令功能：读取当前比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *axis_array 比较轴列表
                *cmpposition_array 比较位置列表
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareGetComparedDataNum(UInt16 cardid, ref long num);
    /*指令功能：/查询已经比较点数量
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *num 已比较点数量
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareGetBufRemain(UInt16 cardid, ref long space); 	//查询可以加入的比较点数量
    /*指令功能：/查询剩余比较缓冲区
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *space 剩余比较缓冲区大小
    返回：      0或错误码*/
    /*************************************************************************二维位置比较功能*********************************************************/
/*************************************************************************一维精确位置比较功能*********************************************************/
    public struct struct_axis_accurate_compare_parms
    {
        public UInt16 cmp_axis;//比较轴号 EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
        public UInt16 enable;//比较使能开关；0;比较禁止；1：比较允许；
        public UInt16 cmpmethod;//比较方法：0：等于；1：小于; 2：大于 3:缓冲区比较方法(绝对位置模式) 4：线性比较法 5：:缓冲区比较方法(相对位置模式)
        public UInt16 cmp_source;//比较源 0：理论位置 1：编码器位置
        public UInt16 active_level;//有效电平；0：低电平有效；1：高电平有效
        public double pulsewidth;//脉冲宽度；单位：【ms】;此参数只有在cmpmethod大于等于3情况下有效
        public double liner_distance;//线性位置比较增量值
        public UInt32 liner_num;//线性位置比较数
    };//精确位置比较
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareSetParms(UInt16 cardid, UInt16 queueno, struct_axis_accurate_compare_parms acccmpparms);
    /*指令功能：配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
                queueno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
                acccmpparms	一维高速位置比较配置参数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetParms(UInt16 cardid, UInt16 queueno, ref struct_axis_accurate_compare_parms acccmpparms);
    /*指令功能：读取配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
                queueno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
    输出参数：  *acccmpparms	一维高速位置比较配置参数
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareClearBuf(UInt16 cardid,UInt16 cmpno);
    /*指令功能：清除比较器所有比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareSetData(UInt16 cardid,UInt16 cmpno,UInt16 axis,double cmpposition);
    /*指令功能：添加比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
                cmpposition	比较位置
			    axis	保留参数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetData(UInt16 cardid,UInt16 cmpno,UInt16 axis,ref double cmpposition);
    /*指令功能：读取当前比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
			    axis	保留参数
    输出参数：  *cmpposition	比较位置
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetComparedDataNum(UInt16 cardid,UInt16 cmpno,ref Int32 num); 	
    /*指令功能：查询已经比较过的点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
    输出参数：  *num	返回已经进行了比较的位置数量
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetBufRemain(UInt16 cardid,UInt16 cmpno,ref Int32 space);
    /*指令功能：查询可以加入的比较点数量(线性比较模式下space返回剩余的比较点数)
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
    输出参数：  *num	返回已经进行了比较的位置数量
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetRemainPoints", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetRemainPoints(UInt16 cardid, UInt16 cmpno, ref Int32 remain_points);
    /*指令功能：查询还有几个比较点还没有进行比较
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1]; 
    输出参数：  *remain_points	还有几个比较点还没有进行比较
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareOutputMapSet", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareOutputMapSet(UInt16 cardid, UInt16 axis_id, UInt16 enable);
    /*指令功能：第10轴或第11轴映射为高速输出口
    输入参数：cardid 卡号，取值范围:[0,11]。
              axis_id      轴号，取值范围：10或11
              enable	1:轴脉冲输出口映射为高速输出口 0：轴脉冲输出恢复为脉冲输出口
    输出参数：无
    返回参数：错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareOutputMapGet", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareOutputMapGet(UInt16 cardid, UInt16 axis_id,ref UInt16 enable);
    /*指令功能：读取第10轴或第11轴映射是否映射为高速输出口
  输入参数：cardid 卡号，取值范围:[0,11]。
            axis_id     轴号，取值范围：10或11       
  输出参数：*enable	1:轴脉冲输出口映射为高速输出口 0：轴脉冲输出恢复为脉冲输出口
  返回参数：错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareSetMultiData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareSetMultiData(UInt16 cardid, UInt16 cmpno, UInt16 data_num, double[] cmpposition);
    /*指令功能：高速比较添加多个比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                cmpno	比较器号, EI400\EI400S\ EI800取值范围:[0,3];EIC00取值范围:[0,1];
			    data_num	添加的比较点个数 取值范围：[1,127]
                *cmpposition 	比较点位置数组  单位：ppu
    输出参数：  无
    返回：      0或错误码*/
/*************************************************************************高速位置比较功能*********************************************************/

/*************************************************************************二维精确位置比较功能*********************************************************/
    public struct struct_crd_accurate_compare_parms
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
        public UInt16[] axis_array;//比较轴列表 。EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];
        public UInt16 enable;//比较使能开关；0;比较禁止；1：比较允许；
        public UInt16 cmpmethod;//比较方法：0：开区间比较法；1：半开区间比较法
        public UInt16 cmp_source;//比较源 0：理论位置 1：编码器位置
        public UInt16 active_level;//输出有效电平；0：低电平有效；1：高电平有效
        public double pulsewidth;//脉冲宽度；单位：【ms】;
        public double cmp_error;//精度；单位[pulse]
    };//精确位置比较
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareSetParms(UInt16 cardid,struct_crd_accurate_compare_parms acccmpparms);
    /*指令功能：配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
                acccmpparms 高速二维比较配置参数结构体
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetParms(UInt16 cardid,ref struct_crd_accurate_compare_parms acccmpparms);
    /*指令功能：配置比较器
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *acccmpparms 高速二维比较配置参数结构体
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareClearBuf(UInt16 cardid);
    /*指令功能：清除比较器所有比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareSetData(UInt16 cardid,double[] cmpposition_array);
    /*指令功能：添加比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
                *cmpposition_array	比较位置列表
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetData(UInt16 cardid,double[] cmpposition_array);
    /*指令功能：读取当前比较点
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *cmpposition_array	比较位置列表
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetComparedDataNum(UInt16 cardid,ref Int32 num); 	
    /*指令功能：查询已经比较过的点
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *num	已经进行了比较的位置数量
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetBufRemain(UInt16 cardid,ref Int32 space);
    /*指令功能：查询可以加入的比较点数量
    输入参数：  cardid 卡号，取值范围:[0,11]。
    输出参数：  *space	剩余比较空间
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateConfigOutBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateConfigOutBit(UInt16 cardid, UInt32 bitmask); 	
    /*指令功能：选择二维高速比较输出口
    输入参数：  cardid 卡号，取值范围:[0,11]。
                bitmask 取值范围12或13
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateReadOutBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateReadOutBit(UInt16 cardid, ref UInt32 bitmask); 	
    /*指令功能：选择二维高速比较输出口
    输入参数：  cardid 卡号，取值范围:[0,11]。
                bitmask 取值范围12或13
    输出参数：  无
    返回：      0或错误码*/
/*************************************************************************高速位置比较功能*********************************************************/



/*************************************************************************位置锁存功能*********************************************************/
    public struct struct_axis_latch_parms
    {
        public UInt16 active_level;//有效沿；0；上升沿锁存1：下降沿锁存
        public UInt16 latch_method;//锁存方式；0：单次锁存；1：连续锁存
        public UInt16 latch_source;//锁存源；0：锁存理论位置；1：锁存编码器位置；
    };//位置锁存配置
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigLatchParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigLatchParms(UInt16 cardid, UInt16 ltc_num, UInt16 axis, struct_axis_latch_parms ltcparms);
    /*指令功能：配置高速锁存参数
    输入参数：  cardid 卡号，取值范围:[0,11]。
                ltc_num	锁存器通道号，取值范围[0,1]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
                ltcparms	锁存参数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadLatchParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadLatchParms(UInt16 cardid, UInt16 ltc_num, UInt16 axis, ref struct_axis_latch_parms ltcparms);
    /*指令功能：读取高速锁存配置
    输入参数：  cardid 卡号，取值范围:[0,11]。
                ltc_num	锁存器通道号，取值范围[0,1]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
    输出参数：  *ltcparms	锁存参数
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLatchFlagStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetLatchFlagStatus(UInt16 cardid, UInt16 ltc_num, UInt16 axis, ref UInt16 latchstatus);
    /*指令功能：读取锁存器标志
    输入参数：  cardid 卡号，取值范围:[0,11]。
                ltc_num	锁存器通道号，取值范围[0,1]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
    输出参数：  *latchstatus	锁存标志（1:有锁存数据 0：没有锁存数据）
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxClearLatchStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxClearLatchStatus(UInt16 cardid, UInt16 ltc_num, UInt16 axis);
    /*指令功能：复位锁存器标志
    输入参数：  cardid 卡号，取值范围:[0,11]。
                ltc_num	锁存器通道号，取值范围[0,1]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLacthPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetLacthPosition(UInt16 cardid, UInt16 ltc_num, UInt16 axis, UInt16 startpos_index, UInt16 count,  double[] position);
    /*指令功能：复位锁存器标志
    输入参数：  cardid 卡号，取值范围:[0,11]。
                ltc_num	锁存器通道号，取值范围[0,1]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLatchNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetLatchNum(UInt16 cardid, UInt16 ltc_num, UInt16 axis, ref Int32 num);
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
    public struct struct_home_config_parms
    {
        public double home_high_vel;//回零高速，单位：【pulse/s】,取值范围（0,4000000】
        public double home_low_vel;//回零高速，单位：【pulse/s】,取值范围（0,4000000】
        public double home_acc;//回零加减速度, 单位：【pulse/s2】,取值范围（0,4000000000】
        public UInt16 home_mode;//0:原点捕获回零;1：EZ锁存回零;2:原点+EZ锁存回零 3：反向找EZ锁存回零 4：一次回零 5：二次回零 6：一次回零加反找回零 7：原点加EZ回零 8：ez回零 9：反向找EZ回零
        public UInt16 org_level;//原点有效电平，0：低电平有效；1：高电平有效
        public UInt16 org_ltc_source;//原点锁存源，0：理论位置 1：编码器位置
        public UInt16 ez_level;//ez有效电平，0：低电平有效；1：高电平有效
        public UInt16 ez_ltc_source;//ez锁存源，0：理论位置 1：编码器位置
        public UInt16 org_ltc_level;//0：上升沿锁存原点  1：下降沿锁存原点
        public UInt16 ez_ltc_level;//0：上升沿锁存ez 1：下降沿锁存ez
    };//回零模块配置参数
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigHomeParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigHomeParms(UInt16 cardid,UInt16 axis,struct_home_config_parms homeparms);
    /*指令功能：设置回零参数
    输入参数：  cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
			    homeparms	回零参数
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadHomeParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadHomeParms(UInt16 cardid,UInt16 axis,ref struct_home_config_parms homeparms);
    /*指令功能：读取回零参数
    输入参数：  cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];			
    输出参数：  *homeparms	回零参数
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigHomeEncoderFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigHomeEncoderFactor(UInt16 cardid, UInt16 axis, double factor);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadHomeEncoderFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadHomeEncoderFactor(UInt16 cardid, UInt16 axis, ref double factor);
    /*指令功能：查询编码器比例
    输入参数：  cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];			
    输出参数：  *factor	编码器比例
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxHomeMove", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxHomeMove(UInt16 cardid,UInt16 axis,UInt16 homedir);
    /*指令功能：启动回零运动
    输入参数：  cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
			    homedir	回零方向（0：负方向，1：正方向）
    输出参数：  无
    返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCheckHomeDone", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCheckHomeDone(UInt16 cardid, UInt16 axis, ref UInt16 done_flag);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHomeSearchDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHomeSearchDistance(UInt16 cardid, UInt16 axis, double home_distance);
    /*指令功能：设置回零搜索距离，如果搜索距离到达还没有找到原点，则运动减速停止 停止原因代码是24
      输入参数：cardid 卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
                home_distance 搜索距离 单位：ppu
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHomeSearchDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHomeSearchDistance(UInt16 cardid, UInt16 axis, ref double home_distance);
    /*指令功能：查询回零搜索距离，如果搜索距离到达还没有找到原点，则运动减速停止 停止原因代码是24
      输入参数：cardid 卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
      输出参数：*home_distance 搜索距离 单位：ppu
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHomeStopDelayTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHomeStopDelayTime(UInt16 cardid, UInt16 axis, UInt32 delay_time);
    /*指令功能：设置回零过程中运动停止后延时delay_time后再启动反向运动。
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
		        delay_time 延时时间 ，单位 ms 
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHomeStopDelayTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHomeStopDelayTime(UInt16 cardid, UInt16 axis, ref UInt32 delay_time);
    /*指令功能：读取回零过程中运动停止后延时时间。
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
      输出参数：delay_time 延时时间 ，单位 ms 
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHomeBackDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHomeBackDistance(UInt16 cardid, UInt16 axis, double back_distance);
/*指令功能：设置回零反找时碰到原点后的回退距离
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
			back_distance 搜索距离 单位：ppu
  输出参数：无
  返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHomeBackDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHomeBackDistance(UInt16 cardid, UInt16 axis, ref double back_distance);
/*指令功能：回读回零反找时碰到原点后的回退距离
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*back_distance 搜索距离 单位：ppu
  返回：      0或错误码*/
/*************************************************************************回零功能*********************************************************/


/*************************************************************************手轮功能*********************************************************/
    public struct struct_handwheel_config_parms
    {
        public UInt16 handwheelmode;//手轮输入模式：0：正交信号输入模式；1：脉冲+方向输入模式；
        public double radio;//手轮倍率;radio <0  负方向  radio >0 正方向
    };//手轮配置参数
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigHandwheelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigHandwheelParms(UInt16 cardid,UInt16 axis,struct_handwheel_config_parms hwparms);
    /*指令功能：配置手轮运动参数
      输入参数：cardid 卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
                hwparms	手轮配置参数
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadHandwheelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadHandwheelParms(UInt16 cardid,UInt16 axis,ref struct_handwheel_config_parms hwparms);
    /*指令功能：读取手轮配置
      输入参数：cardid 卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	
      输出参数：*hwparms	手轮配置参数
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxHandwheelMove", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxHandwheelMove(UInt16 cardid,UInt16 axis);
    /*指令功能：启动手轮运动
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHandwheelPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHandwheelPosition(UInt16 cardid, UInt16 axis, double pos);
    /*指令功能：设置手轮位置
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			    pos	    位置值
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHandwheelPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHandwheelPosition(UInt16 cardid, UInt16 axis, ref double pos);
    /*指令功能：读取手轮位置
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];	
  输出参数：*pos	    位置值
  返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHandwheelChannal", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHandwheelChannal(UInt16 cardid, UInt16 handwheelchannal);
    /*指令功能：此函数保留*/
 [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHandwheelInputState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHandwheelInputState(UInt16 cardid, ref UInt16 input_state);
/*指令功能：读取手轮端子控制信号输入状态
  输入参数：cardid 卡号，取值范围:[0,11]。
  输出参数：input_state ： bit0: 轴0轴选输入信号状态 bit1: 轴1轴选输入信号状态 bit2: 轴2轴选输入信号状态 bit3: 轴3轴选输入信号状态
                           bit4: 1倍倍率输入信号状态 bit5: 10倍倍率输入信号状态 bit6: 100倍倍率输入信号状态
						   bit7: 手轮急停输入信号状态
  返回：      0或错误码*/
/*************************************************************************手轮功能*********************************************************/



/*************************************************************************JOG和点位运动功能*********************************************************/
    public struct struct_vel_plan_parms
    {
        public double start_vel;     //起始速度，单位：【ppu/s】 ;取值范围【0,4000000/PPU】
        public double max_vel;       //最大速度，单位：【ppu/s】;取值范围(0,4000000/PPU】
        public double end_vel;       //停止速度，单位：【ppu/s】;取值范围【0,4000000/PPU】
        public double acc;           //加速度,单位：[ppu/s2];取值范围(0,4000000000/ppu]
        public double dec;           //减速度,单位：[ppus/s2];取值范围(0,4000000000/ppu]
    };//速度规划参数
    //速度参数设置：
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetSmoothFactor(UInt16 cardid,UInt16 axis,double smooth_factor);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetSmoothFactor(UInt16 cardid,UInt16 axis,ref double smooth_factor);
    /*指令功能：设置速度曲线的S比例系数
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];  
      输出参数：*smooth_factor	设置S段比例系数，取值范围 :[0,1] 
      返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxSetSProfileMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetSProfileMode(UInt16 cardid, UInt16 axis, UInt16 SProfileMode);
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
     [DllImport("PLT.dll", EntryPoint = "Plt_AxGetSProfileMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxGetSProfileMode(UInt16 cardid, UInt16 axis, ref UInt16 SProfileMode);
    /*指令功能：设置S型速度曲线规划模式(该函数仅对定长运动有效)
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];		    
      输出参数：SProfileMode	0：公式规划模式   1：T型速度曲线+滤波模式
          说明：当SProfileMode取0时，Plt_AxSetSmoothFactor函数中的参数smooth_factor表示S曲线速度平滑比例系数，没有物理单位。
	            当SProfileMode取1时，Plt_AxSetSmoothFactor函数中的参数smooth_factor表示滤波时间，单位是s,取值范围[0,1]
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetvelParms(UInt16 cardid,UInt16 axis,struct_vel_plan_parms axisplanparms);
    /*指令功能：设置速度曲线的规划参数
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
		        axisplanparms	速度规划参数
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetvelParms(UInt16 cardid,UInt16 axis,ref struct_vel_plan_parms axisplanparms);
    /*指令功能：设置速度曲线规划参数
      输入参数：cardid 卡号，取值范围:[0,11]。
			    axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];	    
      输出参数：*axisplanparms	速度规划参数
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMoveRel(UInt16 cardid,UInt16 axis,double dist);
    /*指令功能：开始点位运动（运动一段dist距离）
      输入参数：cardid 卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
                dist	点位运动的距离，单位：PPU dist取值范围：【2147483640/ppu,-2147483640/ppu】 注意：当dist加上当前寄存器值超出范围【2147483640/ppu,-2147483640/ppu】，会报错
      输出参数：*axisplanparms	速度规划参数
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMoveAbs(UInt16 cardid,UInt16 axis,double position);
    /*指令功能：开始点位运动（运动到position位置）
      输入参数：cardid 卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
                position	点位运动的目标位置，单位：PPU position取值范围：【2147483640/ppu,-2147483640/ppu】
      输出参数：*axisplanparms	速度规划参数
      返回：      0或错误码*/	
     [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeVelMoveRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeVelMoveRel(UInt16 cardid, UInt16 axis, double change_vel, double start_change_vel_dist, double end_change_vel_dist, double dist);
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
	 [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeVelMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxChangeVelMoveAbs(UInt16 cardid, UInt16 axis, double change_vel, double start_change_vel_pos, double end_change_vel_pos, double position);	
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
	[DllImport("PLT.dll", EntryPoint = "Plt_AxMoveVel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMoveVel(UInt16 cardid,UInt16 axis,UInt16 direction);	//指定轴做连续运动
    /*指令功能：启动JOG运动
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			direction	JOG运动的方向，0：负方向，1：正方向.指令位置增加的方向为正方向，相反的为负方向。
  输出参数：无
  返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeTartetPos", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeTartetPos(UInt16 cardid,UInt16 axis,double position);
    /*指令功能：运行中改变目标位置（原来的目标位置再加上一段position距离）
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			position	在线变位运动的新位置，单位：PPU position取值范围：【2147483640/ppu,-2147483640/ppu】相对模式在线变位
  输出参数：无
  返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeTartetPosAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeTartetPosAbs(UInt16 cardid,UInt16 axis,double position);
    /*指令功能：运行中改变目标位置（新的目标位置为position）
  输入参数：cardid 卡号，取值范围:[0,11]。
			axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
			position	在线变位运动的新位置（绝对位置坐标），单位：PPU position取值范围：【2147483640/ppu,-2147483640/ppu】绝对模式在线变位
  输出参数：无
  返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeVel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeVel(UInt16 cardid,UInt16 axis,double maxvel);
    /*指令功能：运行中改变速度
  输入参数：cardid 卡号，取值范围:[0,11]。
            axis	轴号，EI400\EI400S取值范围:[0,3];
                    EI800取值范围:[0,7];
                    EIC00取值范围:[0,11];
            maxvel	在线变速后新的最大速度，单位：PPU/s
  输出参数：无
  返回：      0或错误码*/
  [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeTartetPosMaxVelAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeTartetPosMaxVelAcc(UInt16 cardid, UInt16 axis, double position, UInt16 pos_mode, double max_vel, double acc, double dec);
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
  [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveRelAndSoftLanding", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
  public static extern short Plt_AxMoveRelAndSoftLanding(UInt16 cardid, UInt16 axis, double soft_landing_vel, double soft_landing_dist, double aim_dist);
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
  [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveAbsAndSoftLanding", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
  public static extern short Plt_AxMoveAbsAndSoftLanding(UInt16 cardid, UInt16 axis, double soft_landing_vel, double soft_landing_pos, double aim_pos);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisSetAxisParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_TakingMaterisSetAxisParms(UInt16 cardid, UInt16 crd, UInt16 wait_input_num, UInt16 wait_input_logic, UInt16[] axis, double ratio_1, double ratio_2);
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
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisGetAxisParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_TakingMaterisGetAxisParms(UInt16 cardid, UInt16 crd, ref UInt16 wait_input_num, ref UInt16 wait_input_logic, ref UInt16[] axis, ref double ratio_1, ref double ratio_2);
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
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisSetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisSetvelParms(UInt16 cardid, UInt16 crd, struct_vel_plan_parms[] axisplanparms, double change_vel);
//指令功能：取放料运动速度参数配置
//  输入参数：cardid 卡号，取值范围:[0,11]。
//            crd 动作序号
//			axisplanparms[0] 第一段运动(上升/下降)速度参数
//			axisplanparms[1] 第二段运动(XY平移和物料旋转)合速度参数
//			axisplanparms[2] 第三段运动(下降/上升)速度参数
//			change_vel:在线变速速度
//  输出参数：无
//  返回参数：错误码
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisGetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisGetvelParms(UInt16 cardid, UInt16 crd, ref struct_vel_plan_parms[] axisplanparms, ref double change_vel);
//指令功能：读取取放料运动速度参数配置
//  输入参数：cardid 卡号，取值范围:[0,11]。
//            crd 动作序号
//输出参数：axisplanparms[0] 第一段运动(上升/下降)速度参数
//			axisplanparms[1] 第二段运动(XY平移和物料旋转)合速度参数
//			axisplanparms[2] 第三段运动(下降/上升)速度参数
//			change_vel:在线变速速度
//  返回参数：错误码Plt_TakingMaterisMoveAbs
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisMoveAbs(UInt16 cardid, UInt16 crd, double pos_0, double[] pos_1, double[] pos_2, double[] pos_3, double pos_4, double pos_5, UInt16 motion_mode);
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
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisChangePosAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisChangePosAbs(UInt16 cardid, UInt16 crd, double[] pos);
//指令功能：取放料绝对运动
//输入参数：cardid 卡号，取值范围:[0,11]。
//          crd 动作序号
//			  pos 在线变位X/Y/R轴绝对位置
//输出参数：无
//返回参数：0或错误码
/*************************************************************************取/放料运动功能*********************************************************/

/*************************************************************************停止函数*********************************************************/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxMotionStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMotionStop(UInt16 cardid, UInt16 axis, UInt16 stop_mode);
    /*指令功能：停止指定轴
      输入参数：cardid	卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
                stop_mode	停止模式  0：减速停止 1：立即停止
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CardMotionEmgStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CardMotionEmgStop(UInt16 cardid);
    /*指令功能：停止所有轴
      输入参数：cardid	卡号，取值范围:[0,11]。
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetStopAcc(UInt16 cardid, UInt16 axis, double Acc);
    /*指令功能：设置减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
      输入参数：cardid	卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
                Acc  	减速停止加速度
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetStopAcc(UInt16 cardid, UInt16 axis, ref double Acc);
    /*指令功能：回读减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
      输入参数：cardid	卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
      输出参数：*Acc  	减速停止加速度
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetUseStopAccFlag(UInt16 cardid, UInt16 axis, UInt16 use_stop_acc_flag);
    /*指令功能：设置减速停止时是否使用减速停止专用加速度标志
      输入参数：cardid	卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
                use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
      输出参数：无
      返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetUseStopAccFlag(UInt16 cardid, UInt16 axis, ref UInt16 use_stop_acc_flag);
    /*指令功能：设置减速停止时是否使用减速停止专用加速度标志
      输入参数：cardid	卡号，取值范围:[0,11]。
                axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
       输出参数 *use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
      返回：      0或错误码*/
/*************************************************************************停止函数*********************************************************/

/*************************************************************************螺距补偿功能*********************************************************/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxEnableLeadScrewComp", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxEnableLeadScrewComp(UInt16 cardid,UInt16 axis,UInt16 mode);
    /*指令功能：使能/关使能螺距补偿功能
   输入参数：cardid	卡号，取值范围:[0,11]。
             axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];
             mode: 1表示使能，0表示禁止。 
   输出参数：无
   返回参数：0或错误码*/
   [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEnableLeadScrewComp", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetEnableLeadScrewComp(UInt16 cardid,UInt16 axis,ref UInt16 mode);
   /*指令功能：查询螺距补偿的使能状态
     输入参数：cardid	卡号，取值范围:[0,11]。
               axis	轴号，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7];EIC00取值范围:[0,11];	
     输出参数：*mode: 1表示使能，0表示禁止。 
     返回参数：0或错误码*/
   [DllImport("PLT.dll", EntryPoint = "Plt_AxSetLeadScrewComp", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetLeadScrewComp(UInt16 cardid,UInt16 axis,UInt16 n,Int32 startPos,Int32 lenPos,Int32[] pCompPos,Int32[] pCompNeg);
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
    public struct struct_crd_config_parms
    {
        public UInt16 dimension;//坐标系维数，EI400\EI400S取值范围:[0,3];EI800取值范围:[0,7]，EIC00取值范围:[0,11];
        public UInt16 intermode;//连续插补模式；0：普通连续插补；1：前瞻模式连续插补;2：保留
    };//坐标系配置参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdConfigCrd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdConfigCrd(UInt16 cardid,UInt16 crd,struct_crd_config_parms crdparms,UInt16[] Axismaparray);
    /*指令功能：配置坐标系
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
			    crdparms	坐标系配置参数
			    *Axismaparray	坐标系轴号列表（数量由参数crdparms中的坐标系维数决定）
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetCrd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdGetCrd(UInt16 cardid,UInt16 crd,ref struct_crd_config_parms crdparms,UInt16[] Axismaparray);
    /*指令功能：读取坐标系配置参数
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：	*crdparms	坐标系配置参数
			    *Axismaparray	坐标系轴号列表（数量由参数crdparms中的坐标系维数决定）
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdResetCrd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdResetCrd(UInt16 cardid,UInt16 crd);
    /*指令功能：注销坐标系
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdClearCrdBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdClearCrdBuf(UInt16 cardid, UInt16 crd);
    /*指令功能：清除坐标系缓冲区
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveStart", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveStart(UInt16 cardid,UInt16 crd);
    /*指令功能：启动坐标系运动
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMovePause", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMovePause(UInt16 cardid,UInt16 crd);
    /*指令功能：暂停坐标系运动
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveStop(UInt16 cardid,UInt16 crd,UInt16 stop_mode);
    /*指令功能：停止坐标系运动
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：无
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetOpenSwitchAdvanceTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdSetOpenSwitchAdvanceTime(UInt16 cardid, UInt16 crd, double time);
    /*指令功能：设置提前开胶时间，此函数必须在建立坐标系前调用 
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
			    time 提前开胶/关胶时间 单位：ms
    输出参数：无
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetOpenSwitchAdvanceTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdGetOpenSwitchAdvanceTime(UInt16 cardid, UInt16 crd, ref double time);
    /*指令功能：回读提前开胶时间，此函数必须在建立坐标系前调用 
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。		
    输出参数：time 提前开胶/关胶时间 单位：ms
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdSetStopAcc(UInt16 cardid, UInt16 crd, double Acc);
    /*指令功能：设置坐标系减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
        输入参数：cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
                Acc  	减速停止加速度
        输出参数：无
        返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdGetStopAcc(UInt16 cardid, UInt16 crd, ref double Acc);
    /*指令功能：回读坐标系减速停止专用加速度(适用于包括命令减速停止和限位等其他异常情况减速停止)
        输入参数：cardid	卡号，取值范围:[0,11]。
                    crd	坐标系号，取值范围:[0,1]。
        输出参数：*Acc  	减速停止加速度
        返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdSetUseStopAccFlag(UInt16 cardid, UInt16 crd, UInt16 use_stop_acc_flag);
    /*指令功能：设置坐标系减速停止时是否使用减速停止专用加速度标志
        输入参数：cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
                use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
        输出参数：无
        返回：      0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdGetUseStopAccFlag(UInt16 cardid, UInt16 crd, ref UInt16 use_stop_acc_flag);
    /*指令功能：回读坐标系减速停止时是否使用减速停止专用加速度标志
        输入参数：cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
        输出参数 *use_stop_acc_flag  	1：使用减速停止专用加速度 0：使用Plt_AxSetvelParms函数设置的减速度。默认为0
        返回：      0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetSpace", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetSpace(UInt16 cardid,UInt16 crd,ref Int32 crdspace);
    /*指令功能：查询插补缓冲区剩余空间
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：*crdspace	缓冲器剩余空间
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetRunningSegment", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetRunningSegment(UInt16 cardid,UInt16 crd,ref Int32 CurSegment);
    /*指令功能：查询当前运行段号
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：*CurSegment	正在运动的段号
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetRemainVectorLengthRatio", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetRemainVectorLengthRatio(UInt16 cardid, UInt16 crd, ref double ratio);
    /*指令功能：读取剩余插补矢量长度百分比
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
    输出参数：  *ratio 剩余插补矢量长度百分比
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufChangeSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufChangeSpeed(UInt16 cardid,UInt16 crd,double ratio);
    /*指令功能：在线改变速度
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
                ratio	倍率，取值范围:[0,10]。
    输出参数： 无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetSmoothFactor(UInt16 cardid,UInt16 crd,double smooth_factor);
    /*指令功能：设置S段比例参数
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
			    smooth_factor	S段比例参数,范围：[0,1]
    输出参数： 无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetSmoothFactor(UInt16 cardid,UInt16 crd,ref double smooth_factor);
    /*指令功能：读取S段比例参数
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。		
    输出参数： *smooth_factor	S段比例参数,范围：[0,1]
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetVelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetVelParms(UInt16 cardid,UInt16 crd,struct_vel_plan_parms bufvelparms);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetVelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetVelParms(UInt16 cardid,UInt16 crd,ref struct_vel_plan_parms bufvelparms);
    /*指令功能：获取坐标系速度参数
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。		
    输出参数： *bufvelparms	速度规划参数
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetTrajectoryError", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetTrajectoryError(UInt16 cardid,UInt16 crd,double TrajectoryError);
    /*指令功能：设置允许的轨迹误差（仅在前瞻模式下有效）
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
			    TrajectoryError	允许的轨迹误差值（单位：PPU）
    输出参数： 无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetTrajectoryError", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetTrajectoryError(UInt16 cardid,UInt16 crd,ref double TrajectoryError);
    /*指令功能：查询允许的轨迹误差（仅在前瞻模式下有效）
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。			
    输出参数： *TrajectoryError	允许的轨迹误差值（单位：PPU）
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetMaxTransitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetMaxTransitAcc(UInt16 cardid,UInt16 crd,double MaxTransitAcc);
    /*指令功能：设置允许的最大加加速度（仅在前瞻模式下有效）
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。
			    MaxTransitAcc	允许的最大加速度（单位：[ppu/s2]）
    输出参数： 无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetMaxTransitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetMaxTransitAcc(UInt16 cardid,UInt16 crd,ref double MaxTransitAcc);
    /*指令功能：查询允许的最大加加速度（仅在前瞻模式下有效）
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。		
    输出参数： *MaxTransitAcc	允许的最大加速度（单位：[ppu/s2]）
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerRel(UInt16 cardid,UInt16 crd,UInt16 axis_num,double[] targetpos_array,UInt32 segnum);
    /*指令功能：直线插补（相对运动）
      输入参数：  cardid	卡号，取值范围:[0,11]。
                  crd	坐标系号，取值范围:[0,1]。		
                 axis_num	参与直线插补轴数
                 *targetpos_array	参与直线插补各轴的相对位移（单位：PPU）
                 segnum	段号
      输出参数：无
      返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerAbs(UInt16 cardid,UInt16 crd,UInt16 axis_num,double[] targetpos_array,UInt32 segnum);
    /*指令功能：直线插补（绝对运动）
      输入参数：  cardid	卡号，取值范围:[0,11]。
                  crd	坐标系号，取值范围:[0,1]。	
                  axis_num 轴数
                  targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
                  segnum 段号
      输出参数：无
      返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerRelMulti_XYZ", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerRelMulti_XYZ(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] targetpos_array_z, double[] max_vel, double[] acc);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerAbsMulti_XYZ", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerAbsMulti_XYZ(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] targetpos_array_z, double[] max_vel, double[] acc);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerRelMulti_XY", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerRelMulti_XY(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] max_vel, double[] acc);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerAbsMulti_XY", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerAbsMulti_XY(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] max_vel, double[] acc);
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
    public struct  struct_center_cir_parms
    {
        public UInt16 axis_num;//插补轴数
        public UInt16 direction;//圆弧方向，0：顺时针；1：逆时针；
        public UInt16 cirnum;//圆弧圈数
        public UInt16 plane;//圆弧在哪个平面；0：XY平面；1：YZ平面 2：XZ平面
        public UInt16 mode;//位置模式。0：相对位置模式；1：绝对位置模式
    };//圆心终点方式圆弧参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveCenterCircular", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveCenterCircular(UInt16 cardid,UInt16 crd,struct_center_cir_parms cencirparms,double[] targetpos_array,double[] cenpos_array,UInt32 segnum);
    /*指令功能：圆心终点模式圆弧插补 
      输入参数：  cardid	卡号，取值范围:[0,11]。
                  crd	坐标系号，取值范围:[0,1]。	
                  cencirparms 圆心终点方式圆弧参数
                  cenpos_array圆心坐标列表
                  targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
                  segnum 段号
      输出参数：无
      返回值：0或错误码*/

    public struct struct_radius_cir_parms
    {
        public double radius;//圆弧半径，单位：【ppu】
        public UInt16 axis_num;//插补轴数
        public UInt16 direction;//圆弧方向，0：顺时针；1：逆时针；
        public UInt16 cirnum;//圆弧圈数
        public UInt16 plane;//圆弧在哪个平面；0：XY平面；1：YZ平面 2：XZ平面
        public UInt16 mode;//位置模式。0：相对位置模式；1：绝对位置模式
    };//终点半径圆弧参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveRadiusCircular", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveRadiusCircular(UInt16 cardid,UInt16 crd,struct_radius_cir_parms radcirparms,double[] targetpos_array,UInt32 segnum);
    /*指令功能：终点半径模式圆弧插补 
    输入参数： cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                radcirparms 终点半径圆弧参数
                targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
                segnum 段号
    输出参数：无
    返回值：0或错误码*/

    public struct struct_3point_cir_parms
    {
        public UInt16 axis_num;//插补轴数
        public  UInt16 direction;//圆弧方向，0：顺时针；1：逆时针 此参数无效
        public UInt16 cirnum;//圆弧圈数
        public UInt16 plane;//圆弧在哪个平面；0：XY平面；1：YZ平面 2：XZ平面 3:空间圆弧
        public UInt16 mode;//位置模式。0：相对位置模式；1：绝对位置模式
    };//3点圆弧参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMove3PointCircular", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMove3PointCircular(UInt16 cardid,UInt16 crd,struct_3point_cir_parms pointscirparms,double[] targetpos_array,double[] midpos_array,UInt32 segnum);
    /*指令功能：三点模式圆弧插补 
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                radcirparms pointscirparms
			    midpos_array 中间点位置列表
                targetpos_array 目标位置列表，此目标位置是映射后的坐标系轴目标位置
                segnum 段号
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufDelay", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufDelay(UInt16 cardid, UInt16 crd, double time, UInt32 segnum);//插补延时,单位：[ms]
    /*指令功能：缓冲延时
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                time	延时时间（单位：ms）
                segnum 段号
    输出参数：无
    返回值：0或错误码*/
    public struct struct_buf_check_input_parms
    {
        public UInt16 input_num;//输入io号：取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
        public UInt16 active_level;//有效电平，0：低电平有效；1：高电平有效
        public double check_time;//check时间,单位：[ms]
    };//缓冲区通用输出IO参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCheckInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufCheckInput(UInt16 cardid,UInt16 crd,struct_buf_check_input_parms inputparms,UInt32 segnum);
    /*指令功能：等待输入IO
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                inputparms    输入IO参数
                segnum 段号
    输出参数：无
    返回值：0或错误码*/
    
    public struct struct_buf_check_output_parms
    {
      public UInt16 output_num;//输出io号：EI800\EIC00 0-15 EI400S 0-31
      public UInt16 active_level;//有效电平，0：低电平有效；1：高电平有效
      public double check_time;//check时间,单位：[ms]
    };//缓冲区通用输出IO参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCheckOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufCheckOutput(UInt16 cardid, UInt16 crd, struct_buf_check_output_parms outputparms, UInt32 segnum);
    /*指令功能：缓冲区等待输出IO
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                outputparms    输出IO参数
                segnum 段号
    输出参数：无
    返回值：0或错误码*/


    public struct struct_buf_out_io_parms
    {
        public UInt16 io_mode;//缓冲区输出io模式；//0：设定io立即输出设定电平；1：设定io滞后设定距离输出设定电平；2：设定io滞后设定时间输出设定电平 3:：设定io提前设定距离输出设定电平
        public UInt16 output_num;//输出io号：取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
        public UInt16 active_level;//有效电平，0：低电平有效；1：高电平有效
        public double actionparm;//时间（单位是S）或距离参数(单位是ppu)
        public double holdtime;//设定电平保持时间,单位：[ms]
    };//缓冲区通用输出IO参数
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetOutput(UInt16 cardid,UInt16 crd,struct_buf_out_io_parms outputparms,UInt32 segnum);
    /*指令功能：缓冲区输出IO
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                outputparms    输出IO参数
                segnum 段号
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufBlank", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufBlank(UInt16 cardid, UInt16 crd, UInt16 segnum);
    /*指令功能：缓冲区输出IO
    输入参数：  cardid	卡号，取值范围:[0,11]。
                crd	坐标系号，取值范围:[0,1]。	
                outputparms    输出IO参数
                segnum 段号
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufClearIoAction", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufClearIoAction(UInt16 cardid,UInt16 crd,UInt32 io_mask,UInt32 segnum);
    /*指令功能：清除IO操作 
      输入参数：  cardid	卡号，取值范围:[0,11]。
                  crd	坐标系号，取值范围:[0,1]。	
                  io_mask 需要清除的输出IO号，第0-15BIT对应0-15个输出IO 1：表示清楚 0：表示不操作
                  segnum 段号
      输出参数：无
      返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufOpenSwitchAdvance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufOpenSwitchAdvance(UInt16 cardid, UInt16 crd, double[] pos, UInt16 active_level);
    /*
    指令功能：设置理论开胶/关胶位置
    输入参数： cardid	卡号，取值范围:[0,11]。
               crd	    坐标系号，取值范围:[0,1]。	
		       pos      理论比较位置(X轴坐标和Y轴坐标值)
		       active_level  比较输出有效电平
    输出参数：无
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufOpenSwitchAdvanceMulti", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufOpenSwitchAdvanceMulti(UInt16 cardid, UInt16 crd, UInt32 pos_num, double[] pos_x, double[] pos_y, UInt16 active_level);
    /*
    指令功能：设置理论开胶/关胶位置
    输入参数： cardid	卡号，取值范围:[0,11]。
               crd	    坐标系号，取值范围:[0,1]。	
		       pos_num  添加比较点个数
		       pos_x    理论比较X轴位置
		       pos_y    理论比较Y轴位置
		       active_level  比较输出有效电平
    输出参数：无
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSwitchRemainSpace", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufSwitchRemainSpace(UInt16 cardid, UInt16 crd, ref UInt32 space);
    /*
    指令功能：读取开胶/关胶位置剩余缓冲区数量
    输入参数： cardid	卡号，取值范围:[0,11]。
               crd	    坐标系号，取值范围:[0,1]。	
    输出参数：space 剩余缓冲区
    返回值：0或错误码*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSwitchClear", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufSwitchClear(UInt16 cardid, UInt16 crd);
    /*
    指令功能：读取开胶/关胶位置剩余缓冲区数量
    输入参数： cardid	卡号，取值范围:[0,11]。
               crd	    坐标系号，取值范围:[0,1]。	
    输出参数：space 剩余缓冲区
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCompareSetStartLength", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufCompareSetStartLength(UInt16 cardid, UInt16 crd, double offset_length, UInt16 active_level);
    /*指令功能：设置绝对距离模式开胶/关胶开始位置
    输入参数： cardid	卡号，取值范围:[0,11]。
               crd	    坐标系号，取值范围:[0,1]。
		       offset_length 当前位置的偏移轨迹长度，取值大于等于零
		       active_level  开始位置输出电平
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCompareAddLengthMulti", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufCompareAddLengthMulti(UInt16 cardid, UInt16 crd, UInt32 pos_num, double[] length, UInt16 active_level);
    /*
    指令功能：同时添加多个绝对距离模式开胶/关胶位置
    输入参数： cardid	卡号，取值范围:[0,11]。
               crd	    坐标系号，取值范围:[0,1]。	
		       pos_num  添加比较点个数,一次最多可以添加42个比较点 取值范围[1,42]
		       length   相对开始点的 绝对距离，取值大于等于零
		       active_level  比较输出有效电平
    输出参数：无
    返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufDistanceOutPut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufDistanceOutPut(UInt16 cardid,UInt16 crd,struct_crd_accurate_compare_parms compare_parms_2d,double start_length_ratio,double end_length_ratio,UInt32 output_num,UInt32 segnum);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufDistanceOutPutConti", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufDistanceOutPutConti(UInt16 cardid,UInt16 crd,struct_crd_accurate_compare_parms compare_parms_2d,UInt16 enable_flag,double distance,UInt32 segnum);
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
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufAxMoveRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufAxMoveRel(UInt16 cardid,UInt16 crd,UInt16 axis,double dist,UInt16 mode,UInt32 segnum);
    /*
   指令功能：缓冲区坐标系外的轴设定点相对模式运动
   输入参数：cardid	卡号，取值范围:[0,11]。
             crd	坐标系号，取值范围:[0,1]。	
             axis 轴
             mode，0： 缓冲区外设定点运动完成后才能继续缓冲区插补运动:1：启动缓冲区外轴设定点运动后继续缓冲区插补运动
   输出参数：无
   返回值：0或错误码*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufAxMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufAxMoveAbs(UInt16 cardid,UInt16 crd,UInt16 axis,double dist,UInt16 mode,UInt32 segnum);
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
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetMotionStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxGetMotionStatus(UInt16 cardid, UInt16 axis, ref UInt16 motionstatus);	//读取指定轴的运动状态
         /*指令功能：读取指定轴的运动状态
        输入参数：cardid	卡号，取值范围:[0,11]。
                  axis	轴号，EI400\EI400S取值范围:[0,3];
                              EI800取值范围:[0,7];
                              EIC00取值范围:[0,11];
        输出参数：*motionstatus	轴运动状态（0：运动中，1：停止）
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxGetStatus(UInt16 cardid, UInt16 axis, ref UInt16 mode, ref UInt16 stopreason);//1：点位 2:JOG 3：回零 4：手轮 5：连续插补
         /*指令功能：获取轴运动模式及停止原因
         输入参数：cardid	卡号，取值范围:[0,11]。
                   axis	轴号，EI400\EI400S取值范围:[0,3];
                               EI800取值范围:[0,7];
                               EIC00取值范围:[0,11];
         输出参数：*status	轴运动模式（0：空闲，1：点位运动，2：JOG运动，3：回零运动，4：手轮运动，5：连续插补运动）
                   *stopreason 停止原因
         返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetMotionSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxGetMotionSpeed(UInt16 cardid, UInt16 axis, ref double motionspeed);//读取各轴速度
         /*指令功能：读取指定轴的运动速度
         输入参数：cardid	卡号，取值范围:[0,11]。
                   axis	轴号，EI400\EI400S取值范围:[0,3];
                               EI800取值范围:[0,7];
                               EIC00取值范围:[0,11];
         输出参数：*motionspeed	速度值，单位:PPU/s
         返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetMotionSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdGetMotionSpeed(UInt16 cardid, UInt16 crd, ref double motionspeed);//读取坐标系合速度
         /*指令功能：读取指定轴的运动速度
         输入参数：cardid	卡号，取值范围:[0,11]。
                   crd	坐标系号，取值范围:[0,1]。	
         输出参数：*motionspeed	坐标系合速度值，单位:PPU/s
         返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxClearStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxClearStatus(UInt16 cardid, UInt16 axis);//清除停止原因
         /*指令功能：清除停止原因
         输入参数：cardid	卡号，取值范围:[0,11]。
                   axis	轴号，EI400\EI400S取值范围:[0,3];
                               EI800取值范围:[0,7];
                               EIC00取值范围:[0,11];
         输出参数：无
         返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdBufGetStatus(UInt16 cardid, UInt16 crd, ref UInt16 crdstatus);// 4:释放 3：建立；0：运动；1：暂停 2：停止；5：异常
         /*指令功能：获取插补运动的坐标系状态
         输入参数：cardid	卡号，取值范围:[0,11]。
                   crd	坐标系号，取值范围:[0,1]。	
         输出参数：*crdstatus	坐标系状态（4:释放 3：建立；0：运动；1：暂停 2：停止；5：异常）
         返回值：0或错误码*/
         //设置坐标系到位误差
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdSetBand(UInt16 cardid, UInt16 crd, double[] band, UInt32[] hold_time, UInt32[] check_time);
        /*指令功能：设置轴到位误差
        输入参数：  cardid 卡号
                    crd 插补系号
                    *band 误差带大小数组 即每轴允许的误差带 单位： ppu 
			        *hold_time 脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带保持时间  每轴允许的保持时间数组，单位：ms
                    check_time  脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带监测时间 每轴允许的检测时间数组，单位：ms
        输出参数：无
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdGetBand(UInt16 cardid, UInt16 crd, double[] band, UInt32[] hold_time, UInt32[] check_time);
         /*指令功能：查询坐标系到位误差配置
        输入参数：  cardid	卡号，取值范围:[0,11]。
                    crd	坐标系号，取值范围:[0,1]。	
        输出参数：  *band 误差带大小数组 即每轴允许的误差带 单位： ppu 
			        *hold_time 脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带保持时间  每轴允许的保持时间数组，单位：ms
                    check_time  脉冲发送完毕后脉冲计数和编码器计数偏差绝对值进入误差带监测时间 每轴允许的检测时间数组，单位：ms
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetBandFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdGetBandFlag(UInt16 cardid, UInt16 crd, ref UInt16 band_flag);
         /*指令功能：读取误差带标记
         输入参数：  cardid	卡号，取值范围:[0,11]。
                     crd	坐标系号，取值范围:[0,1]。	
         输出参数：band_flag 1：坐标系中所有轴脉冲位置和编码器位置偏差绝对值落在设定误差带范围内大于等于设定的保持时间
                             0：坐标系轴正在运动中或者轴脉冲发送已经完毕但是脉冲位置和编码器位置偏差绝对值落在设定误差带范围内小于设定的保持时间
                             2：坐标系中至少有一个轴脉冲发送已经完毕但是误差带检查时间到时，脉冲位置和编码器位置偏差绝对值落在设定误差带范围内小于设定的保持时间
         返回值：0或错误码*/
        /*************************************************************************输入IO计数功能相关函数*********************************************************/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoConfigInputCountMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoConfigInputCountMode(UInt16 cardid, UInt16 bitno, UInt16 count_mode, double filter_time);
        /*指令功能：设置输入IO计数模式
          输入参数：cardid	卡号，取值范围:[0,11]。
                    bitno 输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
			        count_mode 计数模式  0：禁止输入IO计数  1：上升沿计数 2：下降沿计数
			        filter_time 输入IO滤波时间 单位：ms 
          输出参数：无
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoReadInputCountMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadInputCountMode(UInt16 cardid, UInt16 bitno, ref UInt16 count_mode, ref double filter_time);
        /*指令功能：读取IO计数模式设置
          输入参数：cardid	卡号，取值范围:[0,11]。
                    bitno 输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
        			
          输出参数：*count_mode 计数模式  0：禁止输入IO计数  1：上升沿计数 2：下降沿计数
			        *filter_time 输入IO滤波时间 单位：ms 
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoSetInputCountValue", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetInputCountValue(UInt16 cardid, UInt16 bitno, UInt32 init_value);
        /*指令功能：设置输入IO计数初始值
           输入参数：cardid	卡号，取值范围:[0,11]。
                     bitno 输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
                     init_value 输入io计数初始值
           输出参数：无
         返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoGetInputCountValue", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoGetInputCountValue(UInt16 cardid, UInt16 bitno, ref UInt32 count_value);
        /*指令功能：读取输入IO计数值
          输入参数：cardid	卡号，取值范围:[0,11]。
                    bitno   输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
           输出参数：*count_value  当前输入io计数值
        返回值：0或错误码*/
/*************************************************************************输入IO计数功能相关函数*********************************************************/
/*************************************************************************PWM功能相关函数*********************************************************/
        [DllImport("PLT.dll", EntryPoint = "Plt_PwmSetPwmEnablFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_PwmSetPwmEnablFlag(UInt16 card, UInt16 pwmno, UInt16 pwmflag);
        /*指令功能：读取输入IO计数值
          输入参数：cardid	卡号，取值范围:[0,11]。
                    bitno   输入io号，取值范围：EI400\EI400S:[0,31]，EI800\EIC00:[0,15];
           输出参数：*count_value  当前输入io计数值
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_PwmGetPwmEnablFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_PwmGetPwmEnablFlag(UInt16 card, UInt16 pwmno, ref UInt16 pwmflag);
        [DllImport("PLT.dll", EntryPoint = "PLT_SetPwmOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_SetPwmOutMode(UInt16 card, UInt16 pwmno, UInt16 out_mode);
        /*指令功能：pwm输出模式
        输入参数： cardid	卡号，取值范围:[0,11]。 
                    pwmno  pwm通道号
			        out_mode pwm输出模式  0：非跟随模式  1：跟随模式
        输出参数：  无
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "PLT_GetPwmOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_GetPwmOutMode(UInt16 card, UInt16 pwmno, ref UInt16 out_mode);
        /*指令功能：读取PWM输出模式
        输入参数：  card 卡号
                     pwmno  pwm通道号
        输出参数：  out_mode pwm输出模式  0：非跟随模式  1：跟随模式
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "PLT_SetPwmOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_SetPwmOut(UInt16 card, UInt16 pwmno, double fDuty, double fFre);
        [DllImport("PLT.dll", EntryPoint = "PLT_GetPwmOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_GetPwmOut(UInt16 card, UInt16 pwmno, ref double fDuty, ref double fFre);
        [DllImport("PLT.dll", EntryPoint = "PLT_CrdBufSetPwmOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_CrdBufSetPwmOut(UInt16 card, UInt16 crd, UInt16 pwmno, double fDuty, double fFre, UInt32 segnum);
        [DllImport("PLT.dll", EntryPoint = "PLT_CrdBufSetPwmFollowParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_CrdBufSetPwmFollowParms(UInt16 card, UInt16 crd, UInt16 pwmno, UInt16 follow_mode, double min_power, double max_power, double ratio, double fix_value);
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
         [DllImport("PLT.dll", EntryPoint = "PLT_CrdBufGetPwmFollowParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_CrdBufGetPwmFollowParms(UInt16 card, UInt16 crd, UInt16 pwmno, ref UInt16 follow_mode, ref double min_power, ref double max_power, ref double ratio, ref double fix_value);
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
/*************************************************************************状态监测*********************************************************/
/*************************************************************************AD功能*********************************************************/
         [DllImport("PLT.dll", EntryPoint = "PLT_AdGetVol", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short PLT_AdGetVol(UInt16 card, UInt16 channal_id, ref float vol);
    /*指令功能：设置输出电平
      输入参数：cardid	卡号，取值范围:[0,11]。 
                channal_id  通道号:有效值为0和1   
                
      输出参数： vol 输出电压值 范围[0,9.9]
    返回值：0或错误码*/
    /*************************************************************************AD功能*********************************************************/
        /*************************************************************************DA功能*********************************************************/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaSetEnableFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaSetEnableFlag(UInt16 card, UInt16 channal_id, UInt16 enable_flag);
        /*指令功能：设置DA输出使能标志
           输入参数：cardid	卡号，取值范围:[0,11]。 
                     channal_id  通道号:有效值为0和1 
                     enable_flag 1：使能 0：禁止
           输出参数： 无
         返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaGetEnableFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaGetEnableFlag(UInt16 card, UInt16 channal_id, ref UInt16 enable_flag);
        /*指令功能：设置DA输出使能标志
          输入参数：cardid	卡号，取值范围:[0,11]。 
                    channal_id  通道号:有效值为0和1   
            
          输出参数：enable_flag 1：使能 0：禁止
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaSetVol", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaSetVol(UInt16 card, UInt16 channal_id, float vol);
        /*指令功能：设置输出电平
           输入参数：cardid	卡号，取值范围:[0,11]。  
                     channal_id  通道号:有效值为0和1 
                     vol 输出电压值 范围[0,9.9]
           输出参数： 无
         返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaGetVol", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaGetVol(UInt16 card, UInt16 channal_id, ref float vol);
        /*指令功能：设置输出电压
           输入参数：cardid	卡号，取值范围:[0,11]。 
                     channal_id  通道号:有效值为0和1   
            
           输出参数： vol 输出电压值 范围[0,9.9]
         返回值：0或错误码*/
        /*************************************************************************DA功能*********************************************************/
        /*************************************************************************CAN输入输出IO**********************************************************/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoSetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetMasterBaudrate(UInt16 cardid, UInt16 baudrate);
         /*指令功能：设置EIX00控制卡CAN通讯波特率
          //  输入参数：cardid	卡号，取值范围:[0,11]。 
          //            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
          //  输出参数：无
          返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoGetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoGetMasterBaudrate(UInt16 cardid, ref UInt16 baudrate);
         /*指令功能：读取EIX00控制卡CAN通讯波特率
         //  输入参数：cardid	卡号，取值范围:[0,11]。  
         //           
         //  输出参数： baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
         返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadInputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level); 	//读取指定can模块输入口的状态
        /*指令功能：读取指定can模块某个输入口电平
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
                      bitno	输入IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
        //  输出参数：  *active_level 
        返回值：0或错误码*/

        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, UInt16 active_level); 	//设置指定can模块输出口的状态
        /*指令功能：设置指定can模块某个输出口电平
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
                      bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
        //			active_level 输出电平值  0和1
        //  输出参数：无
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level);  	//读取指定can模块输出口的状态
        /*指令功能：读取指定can模块某个输出口电平
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
                      bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
        //  输出参数：  *active_level
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllInput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level_1); 	//读取指定can模块所有通用输入IO的值
        /*指令功能：读取指定can模块所有通用输入IO的值
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
        //            active_level	输入口0--31的状态, bit0对应IN0，bit31对应IN31 RCAN32I32O: bit0-bit31位都有效；RCAN16I16O: bit0-bit15位有效；
        //  输出参数：  *active_level  active_level顺序从0到31代表0到31输入IO电平
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllOutput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level); 	//读取指定can模块所有通用输出口的值
        /*指令功能：读取指定can模块所有通用输出IO的值
        //  输入参数cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
        //            bitno IO口号 有效值为[0,31]
        //			  active_level	输出口0--31的状态, bit0对应IN0，bit31对应IN31 RCAN32I32O: bit0-bit31位都有效；RCAN16I16O: bit0-bit15位有效；
        //  输出参数：无
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);  	//设置指定can模块所有通用输出口的值
        /*指令功能：设置指定can模块所有输出口电平
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
        //           active_level	输出口0--31的状态, bit0对应IN0，bit31对应IN31 RCAN32I32O: bit0-bit31位都有效；RCAN16I16O: bit0-bit15位有效；
        //  输出参数：无
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanGetLinkState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanGetLinkState(UInt16 cardid, UInt16 can_id, ref UInt16 link_state);  	//读取指定can模块连接状态
        /*指令功能：读取指定can模块连接状态
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。           
        //  输出参数：  *link_state 连接状态 1：连接  0：断开
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoCanInitAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanInitAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);
         /*指令功能：设置指定can模块输出口初始电平
         //  输入参数：cardid	卡号，取值范围:[0,11]。
                       can_id	can模块序号, 取值范围:[0,7]。
         //			active_level  active_level顺序从0到31代表0到31输出IO初始电平
         //  输出参数：无
         返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoCanInitAllOutput_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanInitAllOutput_extern(UInt16 cardid, UInt16 can_id, UInt32 active_level);
        /*指令功能：设置指定can模块输出口32-63初始电平
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
        //			active_level  active_level顺序从0到31代表32到63输出IO初始电平
        //  输出参数：无
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoCanGetNodeType", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanGetNodeType(UInt16 cardid, UInt16 can_id, ref UInt16 type);
        /*指令功能：读取指定can模块节点类型
          //  输入参数：cardid	卡号，取值范围:[0,11]。
                        can_id	can模块序号, 取值范围:[0,7]。
          //  输出参数：type can模块节点类型  1：rcan1616 2:rcan3232
          返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanGetNodeVersion", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanGetNodeVersion(UInt16 cardid, UInt16 can_id, ref UInt16 version);  	
        /*指令功能：读取指定can模块节点类型
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
        //  输出参数：version can模块节点固件版本号  
        返回值：0或错误码*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanReverseOutputBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, double hold_time);
        /*指令功能：CANIO翻转
        //  输入参数：cardid	卡号，取值范围:[0,11]。
                      can_id	can模块序号, 取值范围:[0,7]。
			          bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
			          hold_time 测试机无效
        //  输出参数：无
        返回值：0或错误码*/
        /*************************************************************************CAN输入输出IO**********************************************************/

        /*************************************************************************龙门同步控制**********************************************************/
        [DllImport("PLT.dll", EntryPoint = "Plt_GantrySetEnable", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantrySetEnable(UInt16 cardid, UInt16 master_axis_id, UInt16 slave_axis_id, UInt16 enable_flag);  	
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
         [DllImport("PLT.dll", EntryPoint = "Plt_GantryGetEnable", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_GantryGetEnable(UInt16 cardid, UInt16 master_axis_id, ref UInt16 slave_axis_id,ref UInt16 enable_flag);
         /*指令功能：查询主轴和从轴是否存在龙门同步关系
         //  输入参数：cardid	        卡号，取值范围:[0,11]。
                       master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                         EI800取值范围:[0,7];
                                         EIC00取值范围:[0,11];	  	
         //  输出参数 *enable_flag       主轴和从轴是否建立龙门同步关系  1：建立 0：解除
                      *slave_axis_id	 从轴轴号，EI400\EI400S取值范围:[0,3];
                                         EI800取值范围:[0,7];
                                         EIC00取值范围:[0,11];	
         返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_GantrySetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantrySetParms(UInt16 cardid, UInt16 master_axis_id, double max_error, double encoder_factor, UInt16 stop_mode);  	
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
         [DllImport("PLT.dll", EntryPoint = "Plt_GantryGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantryGetParms(UInt16 cardid, UInt16 master_axis_id, ref double max_error, ref double encoder_factor, ref UInt16 stop_mode);  	
        /*指令功能：获取龙门同步轴组参数
        //  输入参数：cardid	        卡号，取值范围:[0,11]。
                      master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                        EI800取值范围:[0,7];
                                        EIC00取值范围:[0,11];	  
        //输出参数：  *max_error	    主轴和从轴允许的最大编码器偏差，单位：[PPU]
			          *encoder_factor   输出同样脉冲，主轴编码器计数和从轴编码器计数比值
			          *stop_mode        偏差超限停止方式 0：减速停止  1：立即停止
        返回值：0或错误码*/
         [DllImport("PLT.dll", EntryPoint = "Plt_GantryGetError", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantryGetError(UInt16 cardid, UInt16 master_axis_id, ref double cur_error);  	
        /*指令功能：获取龙门同步轴组当前编码器误差值
        //  输入参数：cardid	        卡号，取值范围:[0,11]。
                      master_axis_id	主轴轴号，EI400\EI400S取值范围:[0,3];
                                        EI800取值范围:[0,7];
                                        EIC00取值范围:[0,11];	  
        //输出参数：  cur_error	        主轴和从轴允许的当前编码器偏差，单位：[PPU]
        返回值：0或错误码*/
/*************************************************************************龙门同步控制**********************************************************/
/*************************************************************************测包机模块**********************************************************/
[DllImport("PLT.dll", EntryPoint = "Plt_SetBlow", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_SetBlow(UInt16 cardid, UInt16 blow_num, UInt16 blow_flag, UInt32 cur_roll_num);	
/*指令功能：吹气/补料指令
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              blow_num	        检测站站号   0：CCD1  1：CCD2 2:空包检测ccd
              blow_flag         当 blow_num=0： 0：OK  1:NG 2:NC 当 blow_num=1：0：OK 1：补料  2：缺陷料  3：Mark料
			  cur_roll_num      当前个数
//输出参数：  无
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_get_roller_finish_flag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_get_roller_finish_flag(UInt16 cardid, UInt16 blow_num, ref UInt16 flag);
/*功能描述：读取下位机CCD拍照计数清除标志
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              blow_num	        检测站站号   0：CCD1  1：CCD2 2:空包检测ccd
//输出参数：  flag              0：不要清除  1：需要清除
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_clear_roller_finish_flag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_clear_roller_finish_flag(UInt16 cardid, UInt16 blow_num);
/*功能描述：通知下位机上位机CCD拍照计数已清除
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              blow_num	        检测站站号   0：CCD1  1：CCD2 2:空包检测ccd
//输出参数：  无
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_SetCommand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short  Plt_SetCommand(UInt16 cardid,UInt32 command_id);
/*功能描述：通过以太网下发控制命令
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              command_id        
//输出参数：  无
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_GetTesterFinishFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_GetTesterFinishFlag(UInt16 cardid, UInt16 tester_num, ref UInt16 finish_flag);
/*功能描述：检测测试仪是否完成一次测试
//  输入参数：cardid	        卡号，取值范围:[0,11]。 
              tester_num 0:测试站1  1：测试站2
//输出参数：  finish_flag   0:测试仪测试没有完成  1：测试完成
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_SampleTest", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_SampleTest(UInt16 cardid, UInt16 tester_num);
/*功能描述：测试仪样品测试命令
//  输入参数：cardid	        卡号，取值范围:[0,11]。 
    tester_num 0:测试站1  1：测试站2
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_SetTestDataFinisReadFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_SetTestDataFinisReadFlag(UInt16 cardid, UInt16 tester_num);
/*功能描述：上位机完成读取测试仪结果数据,通知下位机
//  输入参数：cardid	        卡号，取值范围:[0,11]。 
    tester_num 0:测试站1  1：测试站2
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_AlineCommand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_AlineCommand(UInt16 cardid, UInt16 command_id);
/*功能描述：设置自动校准命令
//  输入参数：cardid	        卡号，取值范围:[0,11]。
              command_id  1:校准开始   0：校准结束      
//输出参数：  无
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_GetAlineRdyFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_GetAlineRdyFlag(UInt16 cardid, ref UInt16 flag);
/*功能描述：读取设备自动校准准备状态
//  输入参数：cardid	        卡号，取值范围:[0,11]。     
//输出参数：  flag 1：自动校准准备好(测试针顶到位) 0：自动校准没有准备好
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_GetSystemState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_GetSystemState(UInt16 cardid, ref UInt16 state);
/*功能描述：读取设备状态
//  输入参数：cardid	        卡号，取值范围:[0,11]。     
//输出参数：  state 1：自动状态  4：手动状态  3 ：暂停状态
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_WriteRegister", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_WriteRegister(UInt16 cardid, UInt32 address, long value);
/*功能描述：写寄存器
//  输入参数：cardid	        卡号，取值范围:[0,11]。 
             //5049    CCD1开关  value = 1开；value= 0关
			 //5050    CCD2开关  value = 1开；value= 0关
			 //3800    1963     指定缺陷到达报警     
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_ReadRegister", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_ReadRegister(UInt16 cardid, UInt32 address, ref long value);
/*功能描述：读寄存器
//  输入参数：cardid	        卡号，取值范围:[0,11]。
//输出参数：value
            //5049    CCD1开关  value = 1开；value= 0关
			//5050    CCD2开关  value = 1开；value= 0关
返回值：0或错误码*/
/*************************************************************************测包机模块**********************************************************/
/********************************************步进电机驱动相关函数**************************************************/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorSetStaticCurrent", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorSetStaticCurrent(UInt16 cardid, UInt16 axis, UInt16 current);
/*指令功能：设置步进电机静态电流
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			current	    电流值
输出参数：	无
返回：      0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorSetRunningCurrent", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorSetRunningCurrent(UInt16 cardid, UInt16 axis, UInt16 current);
/*指令功能：设置步进电机动态电流
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			current	    电流值
输出参数：	无
返回：      0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorSetSubdivion", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorSetSubdivion(UInt16 cardid, UInt16 axis, UInt16 subdivion);
/*指令功能：设置步进电机细分数
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
			subdivion   细分数
输出参数：	无
返回：      0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorGetParms(UInt16 cardid, UInt16 axis, ref UInt16 subdivion, ref UInt16 static_current, ref UInt16 running_current);
/*指令功能：读取步进电机配置参数
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*subdivion  细分数
            *static_current  静态电流
			*running_current 动态电流
返回：      0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorCurCurrent", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorCurCurrent(UInt16 cardid, UInt16 axis, ref UInt16 current);
/*指令功能：读取步进电机当前电流
输入参数：  cardid	    卡号，取值范围[0,11]。
	        axis	    轴号，EI400\EI400S取值范围:[0,3];
                        EI800取值范围:[0,7];
                        EIC00取值范围:[0,11];
输出参数：	*current    当前电流
返回：      0或错误码*/
/********************************************步进电机驱动相关函数**************************************************/ 
/*************************************************************************RS485相关函数*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485SetBound", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485SetBound(UInt16 cardid, UInt32 bound);
/*
功能描述：设置RS485波特率
输入参数：cardid 卡号
          bound 波特率  可设置的波特率 9600 19200 38400 
输出参数：无
返回值：错误码  0：设置成功  2400：无效的波特率值*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485GetBound", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485GetBound(UInt16 cardid, ref UInt32 bound);
/*
功能描述：回读RS485波特率
输入参数：cardid 卡号       
输出参数：bound 波特率
返回值：错误码*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485SetDataReceiveTimeOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485SetDataReceiveTimeOut(UInt16 cardid, UInt16 time_out);
/*
功能描述：设置RS485从站设备收到控制卡发送的指令后，控制卡等待从站数据回传超时时间
输入参数：cardid 卡号
          time_out：超时时间 取值范围 [10,1000] 单位：ms
输出参数：无
返回值：错误码  0：设置成功  2401：无效的超时时间值*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485GetDataReceiveTimeOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485GetDataReceiveTimeOut(UInt16 cardid, ref UInt16 time_out);
/*
功能描述：回读RS485波特率
输入参数：cardid 卡号       
输出参数：time_out：超时时间 
返回值：错误码*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485DataExchange", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485DataExchange(UInt16 cardid, byte[] data_send_buf, UInt16 data_send_len, byte[] data_receive_buf, ref UInt16 data_receive_len);
/*
功能描述：RS485发送若干个字节数据，并读取从站返回的数据
输入参数：cardid 卡号  
          data_send_buf 发送到RS485从站的数据
		  data_send_len 发送到RS485从站的数据长度，取值范围[1,100]
输出参数：data_receive_buf：从站返回的数据
          data_receive_len 从站返回的数据长度
返回值：错误码*/
/*************************************************************************RS485相关函数*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchSetBufferDatasEnable", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchSetBufferDatasEnable(UInt16 cardid, UInt16 datas_id, UInt16 enable_flag);
/*功能描述：使能/禁止数据自动采集，当设置使能时，同时会把缓冲区中存储的数据清除掉。
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	
			  enable_flag       1:使能 0：禁止
  输出参数：  无
返回值：0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchConfigBufferParams", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchConfigBufferParams(UInt16 cardid, UInt16 datas_id, double start_pos, double end_pos, UInt32 time_period);
/*功能描述：读取控制卡底层自动采集的数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	
			  start_pos         采集开始位置，单位：脉冲当量单位 ppu
			  end_pos           采集结束位置，单位：脉冲当量单位 ppu
			  time_period       采集频率      单位：time_period ms/个
  输出参数：  无
返回值：0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchReadBufferParams", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchReadBufferParams(UInt16 cardid, UInt16 datas_id, ref double start_pos, ref double end_pos, ref UInt32 time_period);
/*功能描述：读取控制卡底层自动采集的数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	 
  输出参数：  start_pos         采集开始位置，单位：脉冲当量单位 ppu
			  end_pos           采集结束位置，单位：脉冲当量单位 ppu
			  time_period       采集频率      单位：time_period ms/个
返回值：0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchGetBufferDatas", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchGetBufferDatas(UInt16 cardid, UInt16 datas_id, UInt32 datas_num, ref UInt32 act_datas_num, double[] datas_buffer);
/*功能描述：读取控制卡底层自动存储的数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。
              datas_id          需要读取的数据id,0-11 对应0-11轴脉冲计数  12-23 对应0-11轴编码器计数	
			  datas_num         需要读取的数据个数,一次最多可以读300个。
  输出参数：  act_datas_num     实际读取到的数据个数       
              datas_buffer      读取到的数据
返回值：0或错误码*/
/*************************************************************************看门狗功能相关函数*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_SetHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_SetHostWatchDog(UInt16 cardid, UInt16 enable, UInt16 watchtime, UInt16 do_total_num, UInt16[] do_num, UInt16[] do_logic);
/*
功能描述：设置看门狗参数
输入参数：cardid 卡号
          enable 看门狗使能标志 1：看门狗使能  0：看门狗禁止  默认是禁止
          watchtime 超时报警时间，单位[ms]
          do_total_num 超时报警时需要设置的输出IO口总数
          *do_num     超时报警时需要设置的输出IO口序号
          *do_logic    超时报警时需要设置的输出各个IO口电平
输出参数：无*/
 [DllImport("PLT.dll", EntryPoint = "Plt_GetHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_GetHostWatchDog(UInt16 cardid, ref UInt16 enable, ref UInt16 watchtime, ref UInt16 do_total_num, UInt16[] do_num, UInt16[] do_logic);
/*功能描述：读取看门狗参数*/
 [DllImport("PLT.dll", EntryPoint = "Plt_FeedHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_FeedHostWatchDog(UInt16 cardid);
/*功能描述：在超时报警时间范围内不断调用此函数，以防止超时报警*/
 [DllImport("PLT.dll", EntryPoint = "Plt_InitHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_InitHostWatchDog(UInt16 cardid);
/*功能描述：看门狗功能复位，复位后如果需要再次启动看门狗功能，需要重新配置看门狗函数*/
/*************************************************************************看门狗功能相关函数*********************************************************/
/*************************************************************************自定义读写数据函数接口*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_UserSetDatas", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_UserSetDatas(UInt16 cardid, UInt32 datas_id, UInt32 datas_num, char[] datas_buffer);
/*功能描述：写数据到下位机
  输入参数：  cardid	        卡号，取值范围:[0,11]。	
              datas_id          参数ID,用户可以参数id枚举自定义的参数
			  datas_num         需要写入的数据个数,一次最多可以写1200个。
			  datas_buffer      写到下位机的数据数组
  输出参数：  无
返回值：0或错误码*/
 [DllImport("PLT.dll", EntryPoint = "Plt_UserGetDatas", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_UserGetDatas(UInt16 cardid, UInt32 datas_id, ref UInt32 datas_num, char[] datas_buffer);
/*功能描述：从下位机读数据
  输入参数：  cardid	        卡号，取值范围:[0,11]。	
              datas_id          参数ID,用户可以参数id枚举自定义的参数	  
  输出参数：  datas_buffer      读取到的下位机的数据数组
              datas_num         返回读取的数据个数。	
返回值：0或错误码*/
/*************************************************************************自定义读写数据函数接口*********************************************************/
/*************************************************************************设置和读取下位机系统时间*********************************************************/
[DllImport("PLT.dll", EntryPoint = "Plt_Set_System_Time", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Set_System_Time(UInt16 cardid, UInt16 year, UInt16 month, UInt16 date, UInt16 hour, UInt16 min, UInt16 sec);
/*功能描述：设置下位机系统 时间
  输入参数：  cardid	        卡号，取值范围:[0,11]。	
              year  年，范围[0,99]
			  month 月, 范围[1,12]
			  date  日, 范围[1,31]
			  hour  小时, 范围[0,23]
			  min   分钟, 范围[0,59]
			  sec   秒, 范围[0,59]
  输出参数：  无
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_Get_System_Time", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_Get_System_Time(UInt16 cardid, ref UInt16 year, ref UInt16 month, ref UInt16 date, ref UInt16 hour, ref UInt16 min, ref UInt16 sec);
/*功能描述：设置下位机系统 时间
  输入参数：  cardid	        卡号，取值范围:[0,11]。	
  输出参数：  year  年，范围[0,99]
			  month 月, 范围[1,12]
			  date  日, 范围[1,31]
			  hour  小时, 范围[0,23]
			  min   分钟, 范围[0,59]
			  sec   秒, 范围[0,59]
返回值：0或错误码*/
/*************************************************************************设置和读取下位机系统时间*********************************************************/
/******************************************************************ETHERCAT总线相关函数*********************************************************/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatDownLoadENIFile", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatDownLoadENIFile(UInt16 cardid, char[] filename);
/*指令功能：下载ethercat从站网络配置文件
输入参数：  cardid	卡号，取值范围[0,11]。
	        *filename	新固件绝对路径。 注意：路径中不能有中文字符
输出参数：	无
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatSetNodeOd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatSetNodeOd(UInt16 cardid,UInt16 slave_id,UInt16 Index,UInt16 SubIndex,UInt16 length,UInt32 Value);
/*指令功能：配置从站对象字典参数值(无符号)
输入参数：  cardid	卡号，取值范围[0,11]。
	        slave_id 从站id号
			Index 对象字典索引
			SubIndex 对象字典子索引
			length 对象字典索引长度(单位： byte)
			Value 对象字典索引参数值
输出参数：	无
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetNodeOd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetNodeOd(UInt16 cardid,UInt16 slave_id,UInt16 Index,UInt16 SubIndex,UInt16 length,ref UInt32 Value);
/*指令功能：配置从站对象字典参数值(无符号)
输入参数：  cardid	卡号，取值范围[0,11]。
	        slave_id 从站id号
			Index 对象字典索引
			SubIndex 对象字典子索引
			length 对象字典索引长度(单位： byte)
输出参数：	Value 对象字典索引参数值
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatSetNodeOd_INT", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatSetNodeOd_INT(UInt16 cardid, UInt16 slave_id, UInt16 Index, UInt16 SubIndex, UInt16 length, Int32 Value);
/*指令功能：配置从站对象字典参数值(有符号)
输入参数：  cardid	卡号，取值范围[0,11]。
	        slave_id 从站id号
			Index 对象字典索引
			SubIndex 对象字典子索引
			length 对象字典索引长度(单位： byte)
			Value 对象字典索引参数值
输出参数：	无
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetNodeOd_INT", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetNodeOd_INT(UInt16 cardid, UInt16 slave_id, UInt16 Index, UInt16 SubIndex, UInt16 length, ref Int32 Value);
/*指令功能：配置从站对象字典参数值(有符号)
输入参数：  cardid	卡号，取值范围[0,11]。
	        slave_id 从站id号
			Index 对象字典索引
			SubIndex 对象字典子索引
			length 对象字典索引长度(单位： byte)
输出参数：	Value 对象字典索引参数值
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetSlaveCount", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetSlaveCount(UInt16 cardid,ref UInt16 count);
/*指令功能：读取ethercat网络系统从站个数
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	count 从站个数
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetSlaveAxisCount", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetSlaveAxisCount(UInt16 cardid,ref UInt16 count);
/*指令功能：读取ethercat网络系统从站轴个数
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	count 从站轴个数
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatStart", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatStart(UInt16 cardid);
/*指令功能：启动控制器ethercat模块
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	无
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatStop(UInt16 cardid);
/*指令功能：停止控制器ethercat模块
输入参数：  cardid	卡号，取值范围[0,11]。
输出参数：	无
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetMasterState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetMasterState(UInt16 cardid, ref UInt16 state);
/*指令功能：读取ethercat主站状态
输入参数：  cardid	卡号，取值范围[0,11]。
            slave_id 从站id号
输出参数：	state 主站状态  0：未初始化 1：初始化状态 2：预操作状态  3：启动状态  4：安全操作状态  8：操作状态  16：错误状态
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetAxis402State", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetAxis402State(UInt16 cardid,UInt16 slave_id,ref UInt16 state);
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
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatClearAxis402Error", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatClearAxis402Error(UInt16 cardid,UInt16 slave_id);
/*指令功能：ethercat轴站状态错误清除
输入参数：  cardid	卡号，取值范围[0,11]。
            slave_id 从站id号
输出参数：	无
返回：      0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetSlaveInfo", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetSlaveInfo(UInt16 cardid, UInt16 slave_id, UInt16 info_type, byte[] info);
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
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatIoReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatIoReadInputByBit(UInt16 cardid,UInt16 slave_id,UInt16 bitno,ref UInt16 active_level); 	
/*指令功能：读取指定ethercat从站模块某个输入口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
              bitno	输入IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//  输出参数：  *active_level 
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatIoWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatIoWriteOutputByBit(UInt16 cardid,UInt16 slave_id,UInt16 bitno,UInt16 active_level); 	
/*指令功能：设置指定ethercat从站模块某个输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
              bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//			active_level 输出电平值  0和1
//  输出参数：无
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatIoReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatIoReadOutputByBit(UInt16 cardid,UInt16 slave_id,UInt16 bitno,ref UInt16 active_level);  	
/*指令功能：读取指定ethercat从站模块某个输出口电平
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
              bitno	输出IO口序号，RCAN16I16O取值范围：[0,15]RCAN32I32O取值范围：[0,31]
//  输出参数：  *active_level
返回值：0或错误码*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetAxisErrorCode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetAxisErrorCode(UInt16 cardid,UInt16 slave_id,ref UInt32 ErrorCode);  	
/*指令功能：读取指定ethercat从站错误码
//  输入参数：cardid	卡号，取值范围:[0,11]。
              slave_id	ethercat从站模块序号, 取值范围:[0,7]。
//  输出参数：  *ErrorCode 错误码
返回值：0或错误码*/
/******************************************************************ETHERCAT总线相关函数*********************************************************/
     
    }
}
