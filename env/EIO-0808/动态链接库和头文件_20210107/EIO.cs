using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace csEIO 
{
    public class EIO
    {   
        //控制卡级相关函数	
        [DllImport("EIO.dll", EntryPoint = "Plt_CardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen(UInt16 TotalCards, UInt16[] CardNameArray, UInt16[] Section, UInt16[] Host_id); 	//初始化控制卡
        [DllImport("EIO.dll", EntryPoint = "Plt_CardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardClose();	//关闭控制卡
        [DllImport("EIO.dll", EntryPoint = "Plt_IoACardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoACardOpen(UInt16 cardid, UInt16 Section, UInt16 Host_id);
        /*功能描述：打开第cardid号运动控制卡
        输入参数：  cardid 卡号
                    Section IP地址第三段段号
			        Host_id IP地址第四段段号
        输出参数：无
        返回：0或错误码*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoACardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoACardClose(UInt16 cardid);	//关闭控制卡
        /*功能描述：关闭第cardid号运动控制卡
        输入参数：  cardid 卡号
        输出参数：无
        返回：0或错误码*/
        [DllImport("EIO.dll", EntryPoint = "Plt_CardGetVerson", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetVerson(UInt16 cardid,ref UInt32 verson1,ref UInt32 verson2); //verson1 固件版本号  verson2 库版本号
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadInputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level); 	//读取输入口的状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoWriteOutputByBit(UInt16 cardid,UInt16 bitno,UInt16 active_level); 	//设置输出口的状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadOutputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level);  	//读取输出口的状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadAllInput(UInt16 cardid,ref UInt32 active_level_1); 	//读取所有输入IO的值
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadAllOutput(UInt16 cardid,ref UInt32 active_level); 	//读取输出端口的值
        [DllImport("EIO.dll", EntryPoint = "Plt_IoWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoWriteAllOutput(UInt16 cardid,UInt32 active_level);  	//设置输出端口的值
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReverseOutputBit(UInt16 cardid,UInt16 bitno,double hold_time); //翻转当前输出口的状态,并保持设定时间后恢复回翻转前的状态

        //canIO相关函数
         [DllImport("EIO.dll", EntryPoint = "Plt_IoSetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetMasterBaudrate(UInt16 cardid, UInt16 baudrate);
        //*功能描述：设置主站波特率
        //  输入参数：card  卡号  
        //            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
        //  输出参数：无
        //*/
         [DllImport("EIO.dll", EntryPoint = "Plt_IoGetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoGetMasterBaudrate(UInt16 cardid, ref UInt16 baudrate);
        //*功能描述：设置主站波特率
        //  输入参数：card  卡号  
        //           
        //  输出参数： baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
        //*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadInputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level); 	//读取输入口的状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, UInt16 active_level); 	//设置输出口的状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level);  	//读取输出口的状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllInput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level_1); 	//读取所有输入IO的值
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllOutput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level); 	//读取输出端口的值
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);  	//设置输出端口的值
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanGetLinkState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanGetLinkState(UInt16 cardid, UInt16 can_id, ref UInt16 link_state);//读取can连接状态
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReverseOutputBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, double hold_time); //翻转指定can模块当前输出口的状态,并保持设定时间后恢复回翻转前的状态
        ///*功能描述：/翻转指定can模块当前输出口的状态,并保持设定时间后恢复回翻转前的状态
        //  输入参数：card  卡号  
        //            can_id  can id号:有效值为[0,15] 
        //            bitno IO口号 有效值为[0,15]
        //            hold_time：单位是ms 必须是0和1ms的整数倍
        //  输出参数：无
        //*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanInitAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanInitAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);  	
        ///*功能描述：设置指定can模块输出IO初始电平
        //  输入参数：card  卡号  
        //            can_id  can id号:有效值为[0,15]   
        //			active_level  active_level顺序从0到31代表0到31输出IO初始电平
        //  输出参数：无
        //*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanGetNodeType", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanGetNodeType(UInt16 cardid, UInt16 can_id, ref UInt16 type);  	
        ///*功能描述：设置指定can模块输出IO初始电平
        //  输入参数：card  卡号  
        //            can_id  can id号:有效值为[0,15]   
        //  输出参数：type can模块节点类型  1：rcan1616 2:rcan3232
        //*/

        //设置ip和读取IP
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReSetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReSetIP(UInt16 cardid, UInt16 section_3, UInt16 section_4);//重新设置IP
        [DllImport("EIO.dll", EntryPoint = "Plt_IoGetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoGetIP(UInt16 cardid, ref UInt16 section_3, ref UInt16 section_4);//读取IP

        //设置输出IO初始电平
        [DllImport("EIO.dll", EntryPoint = "Plt_IoSetInitIO", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetInitIO(UInt16 cardid, UInt16[] io_init_value);//设置输出IO初始电平
    }
}
