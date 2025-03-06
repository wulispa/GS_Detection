using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace csEIO 
{
    public class EIO
    {   
        //���ƿ�����غ���	
        [DllImport("EIO.dll", EntryPoint = "Plt_CardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen(UInt16 TotalCards, UInt16[] CardNameArray, UInt16[] Section, UInt16[] Host_id); 	//��ʼ�����ƿ�
        [DllImport("EIO.dll", EntryPoint = "Plt_CardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardClose();	//�رտ��ƿ�
        [DllImport("EIO.dll", EntryPoint = "Plt_IoACardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoACardOpen(UInt16 cardid, UInt16 Section, UInt16 Host_id);
        /*�����������򿪵�cardid���˶����ƿ�
        ���������  cardid ����
                    Section IP��ַ�����ζκ�
			        Host_id IP��ַ���Ķζκ�
        �����������
        ���أ�0�������*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoACardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoACardClose(UInt16 cardid);	//�رտ��ƿ�
        /*�����������رյ�cardid���˶����ƿ�
        ���������  cardid ����
        �����������
        ���أ�0�������*/
        [DllImport("EIO.dll", EntryPoint = "Plt_CardGetVerson", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetVerson(UInt16 cardid,ref UInt32 verson1,ref UInt32 verson2); //verson1 �̼��汾��  verson2 ��汾��
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadInputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level); 	//��ȡ����ڵ�״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoWriteOutputByBit(UInt16 cardid,UInt16 bitno,UInt16 active_level); 	//��������ڵ�״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadOutputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level);  	//��ȡ����ڵ�״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadAllInput(UInt16 cardid,ref UInt32 active_level_1); 	//��ȡ��������IO��ֵ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadAllOutput(UInt16 cardid,ref UInt32 active_level); 	//��ȡ����˿ڵ�ֵ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoWriteAllOutput(UInt16 cardid,UInt32 active_level);  	//��������˿ڵ�ֵ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReverseOutputBit(UInt16 cardid,UInt16 bitno,double hold_time); //��ת��ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬

        //canIO��غ���
         [DllImport("EIO.dll", EntryPoint = "Plt_IoSetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetMasterBaudrate(UInt16 cardid, UInt16 baudrate);
        //*����������������վ������
        //  ���������card  ����  
        //            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
        //  �����������
        //*/
         [DllImport("EIO.dll", EntryPoint = "Plt_IoGetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoGetMasterBaudrate(UInt16 cardid, ref UInt16 baudrate);
        //*����������������վ������
        //  ���������card  ����  
        //           
        //  ��������� baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
        //*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadInputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level); 	//��ȡ����ڵ�״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, UInt16 active_level); 	//��������ڵ�״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level);  	//��ȡ����ڵ�״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllInput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level_1); 	//��ȡ��������IO��ֵ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllOutput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level); 	//��ȡ����˿ڵ�ֵ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);  	//��������˿ڵ�ֵ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanGetLinkState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanGetLinkState(UInt16 cardid, UInt16 can_id, ref UInt16 link_state);//��ȡcan����״̬
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReverseOutputBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, double hold_time); //��תָ��canģ�鵱ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
        ///*����������/��תָ��canģ�鵱ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
        //  ���������card  ����  
        //            can_id  can id��:��ЧֵΪ[0,15] 
        //            bitno IO�ں� ��ЧֵΪ[0,15]
        //            hold_time����λ��ms ������0��1ms��������
        //  �����������
        //*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanInitAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanInitAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);  	
        ///*��������������ָ��canģ�����IO��ʼ��ƽ
        //  ���������card  ����  
        //            can_id  can id��:��ЧֵΪ[0,15]   
        //			active_level  active_level˳���0��31����0��31���IO��ʼ��ƽ
        //  �����������
        //*/
        [DllImport("EIO.dll", EntryPoint = "Plt_IoCanGetNodeType", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanGetNodeType(UInt16 cardid, UInt16 can_id, ref UInt16 type);  	
        ///*��������������ָ��canģ�����IO��ʼ��ƽ
        //  ���������card  ����  
        //            can_id  can id��:��ЧֵΪ[0,15]   
        //  ���������type canģ��ڵ�����  1��rcan1616 2:rcan3232
        //*/

        //����ip�Ͷ�ȡIP
        [DllImport("EIO.dll", EntryPoint = "Plt_IoReSetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReSetIP(UInt16 cardid, UInt16 section_3, UInt16 section_4);//��������IP
        [DllImport("EIO.dll", EntryPoint = "Plt_IoGetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoGetIP(UInt16 cardid, ref UInt16 section_3, ref UInt16 section_4);//��ȡIP

        //�������IO��ʼ��ƽ
        [DllImport("EIO.dll", EntryPoint = "Plt_IoSetInitIO", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetInitIO(UInt16 cardid, UInt16[] io_init_value);//�������IO��ʼ��ƽ
    }
}
