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
        /*ָ��ܣ���ʼ�����ƿ�
        ���������  TotalCards	�����������򿪿���������
                    CardIdArray	�����������������IP��ַ����λ�������ã����������Ų����ظ�������Ԫ��ȡֵ��Χ[0,11]��
                    Section	    IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£�������������ƿ�����Ĭ��SectionΪ167������Ԫ��ȡֵ��Χ[1,254]��
                    Host_id	    IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã��������,���ƿ�����Ĭ��Host_idΪ120������Ԫ��ȡֵ��Χ[1,254]��
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardOpen_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen_extern(ref UInt16 TotalCards, UInt16[] CardTypeArray, UInt16[] Section, UInt16[] Host_id);
        /*ָ��ܣ���ʼ�����ƿ�
        ���������  Section	      IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£�������������ƿ�����Ĭ��SectionΪ167������Ԫ��ȡֵ��Χ[1,254]��
	                Host_id	      IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã��������,���ƿ�����Ĭ��Host_idΪ120������Ԫ��ȡֵ��Χ[1,254]��       
        ���������	TotalCards	  ��������
                    CardTypeArray �ɹ��򿪵Ŀ�����  0:�Ῠ  1��IO��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardOpen_extern_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardOpen_extern_extern(ref UInt16 TotalCards, UInt16[] CardTypeArray, UInt16[] Section, UInt16[] Host_id, UInt32 time_out);
        /*ָ��ܣ���ʼ�����ƿ�
        ���������  Section	      IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£�������������ƿ�����Ĭ��SectionΪ167������Ԫ��ȡֵ��Χ[1,254]��
	                Host_id	      IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã��������,���ƿ�����Ĭ��Host_idΪ120������Ԫ��ȡֵ��Χ[1,254]�� 
			        time_out      �������ӳ�ʱʱ�� ��λ s
        ���������	TotalCards	  ��������
                    CardTypeArray �ɹ��򿪵Ŀ�����  0:�Ῠ  1��IO��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardClose();	
        /*ָ��ܣ��رտ��ƿ�
        ���������  ��
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardReset", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardReset();
        /*ָ��ܣ���λ���ƿ�
        ���������  ��
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_ACardOpen", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_ACardOpen(UInt16 cardid,UInt16 Section,UInt16 Host_id);
        /*ָ��ܣ���ʼ��һ�����ƿ�
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	                Section	IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£������ƿ�����Ĭ��SectionΪ167��ȡֵ��Χ[1,254]��
	                Host_id	IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã����ƿ�����Ĭ��Host_idΪ120��ȡֵ��Χ[1,254]��
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_ACardOpen_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_ACardOpen_extern(UInt16 cardid,UInt16 Section,UInt16 Host_id,UInt32 time_out);
        /*ָ��ܣ���ʼ��һ�����ƿ�
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	                Section	IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£������ƿ�����Ĭ��SectionΪ167��ȡֵ��Χ[1,254]��
	                Host_id	IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã����ƿ�����Ĭ��Host_idΪ120��ȡֵ��Χ[1,254]��
         *          time_out �������ӳ�ʱʱ�� ��λ s
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_ACardClose", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_ACardClose(UInt16 cardid);	//�رտ��ƿ�
        /*ָ��ܣ��ر�һ�����ƿ�
        ��������� cardid	���ţ�ȡֵ��Χ[0,11]��
        ��������� ��
        ���أ�0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardGetVerson", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetVerson(UInt16 cardid,ref UInt32 verson1,ref UInt32 verson2,ref UInt32 verson3);
        /*ָ��ܣ���ȡ��ذ汾��
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
        ���������	*verson1	FPGA�汾��
                    *verson2	�̼��汾��
                    *verson3	��̬���ӿ�汾��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_GetCardSerialNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_GetCardSerialNum(UInt16 cardid,ref UInt32 SerialNum_0,ref UInt32 SerialNum_1,ref UInt32 SerialNum_2); 
        /*ָ��ܣ���ȡ���ƿ�96λ���к�
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
        ���������	SerialNum_0	���к�0-31λ
	                SerialNum_1	���к�32-63λ
			        SerialNum_2	���к�64-95λ
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardReadCommincationState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardReadCommincationState(UInt16 cardid, ref UInt16 state);	
        /*ָ��ܣ���ȡPC�����˶����ƿ�����״̬
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
        ���������	*state	PC�����˶����ƿ�����״̬ 1������  0���Ͽ�
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardGetCardAxisNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetCardAxisNum(UInt16 cardid, ref UInt16 axisnum);
        /*ָ��ܣ���ȡ��������
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
        ���������  *axisnum	���ƿ�������
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardUpdataFirmare", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardUpdataFirmare(UInt16 cardid, String filename);
        /*ָ��ܣ����ƿ��̼�����
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	                *filename	�¹̼�����·���� ע�⣺·���в����������ַ�
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardParmsFileConfig", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardParmsFileConfig(UInt16 cardid,String ParmsFile);
        /*ָ��ܣ������˶����ƿ�
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	                *ParmsFile	�����ļ� ע�⣺·�������Ǿ���·������·���в��ܳ��������ַ�
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "PLT_GCodeFileProcess", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_GCodeFileProcess(UInt16 cardid,String FileName);//G�����ļ�����

        [DllImport("PLT.dll", EntryPoint = "Plt_CardReSetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardReSetIP(UInt16 cardid, UInt16 section_3, UInt16 section_4);
        /*ָ��ܣ����ÿ��ƿ�IP��ַ
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                section_3	IP��ַ������ֵ����������PC�ĵ�ַһ�£����ƿ�����Ĭ��SectionΪ167��ȡֵ��Χ[1,254]��
			        section_4   IP��ַ���Ķ�ֵ����������PC�ĵ�ַһ�£����ƿ�����Ĭ��SectionΪ120��ȡֵ��Χ[1,254]��
        ���������	��
            ˵����	�����õ�IP��ַ�ڿ��ƿ������ϵ����Ч
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_CardGetIP", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_CardGetIP(UInt16 cardid, ref UInt16 section_3, ref UInt16 section_4);
        /*ָ��ܣ��ض����ƿ����õ�IP��ַ
        ���������  cardid	���ţ�ȡֵ��Χ[0,11]��
        ���������	*section_3	IP��ַ������ֵ�����ƿ�����Ĭ��SectionΪ167
                    *section_4	IP��ַ���Ķ�ֵ�����ƿ�����Ĭ��SectionΪ120
        ���أ�      0�������*/

        //����غ���
        //����ģʽ	
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetPulseOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetPulseOutMode(UInt16 cardid,UInt16 axis,UInt16 mode);	
        /*ָ��ܣ��趨�������ģʽ
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        mode	    �������ģʽ��ȡֵ��Χ��0��2��4��6����������ģʽ�ľ��岨�βο�����ֲᡰ3.4����ģʽ��һ��
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetPulseOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetPulseOutMode(UInt16 cardid,UInt16 axis,ref UInt16 mode);	
        /*ָ��ܣ���ȡ�������ģʽ
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*mode	    �������ģʽ��ȡֵ��Χ��0��2��4��6����������ģʽ�ľ��岨�βο�����ֲᡰ3.4����ģʽ��һ��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEncoderInMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetEncoderInMode(UInt16 cardid,UInt16 axis,UInt16 mode);  
        /*ָ��ܣ��趨�������������ģʽ
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        mode	    �������������ģʽ  ȡֵ��Χ:[0,3]  0������+����   1��1��Ƶ 2:2��Ƶ  3:4��Ƶ
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEncoderInMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetEncoderInMode(UInt16 cardid,UInt16 axis,ref UInt16 mode); 
        /*ָ��ܣ���ȡ�������������ģʽ
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*mode	    �������������ģʽ
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEncoderInNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetEncoderInNegation(UInt16 cardid, UInt16 axis, UInt16 mode);  
        /*ָ��ܣ��趨��������������
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        mode	    ��������������  ȡֵ��Χ:[0,1]  0��EA��ǰEB������   1��EA��ǰEB������
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEncoderInNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetEncoderInNegation(UInt16 cardid, UInt16 axis, ref UInt16 mode); 
        /*ָ��ܣ���ȡ��������������
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*mode	   ��������������
        ���أ�      0�������*/
        //���嵱��
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetPPU", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetPPU(UInt16 cardid,UInt16 axis, double PPU);
        /*ָ��ܣ��趨���嵱��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        PPU	���嵱��ֵ���û���λ��Ӧ����������
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetPPU", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetPPU(UInt16 cardid,UInt16 axis, ref double PPU);
        /*ָ��ܣ���ȡ���嵱��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*PPU	    ���嵱��ֵ���û���λ��Ӧ����������
        ���أ�      0�������*/

        //�����϶
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetBacklash", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetBacklash(UInt16 card,UInt16 axis,double backlash);
        /*ָ��ܣ����÷����϶����
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        backlash	�����϶ֵ����λ�����嵱����λ PPU
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AXGetBacklash", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AXGetBacklash(UInt16 cardid,UInt16 axis,ref double backlash);
        /*ָ��ܣ���ѯ�����϶����
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*backlash	�����϶ֵ
        ���أ�      0�������*/

        //����ֵ���úͻ�ȡ
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetLimitSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetLimitSpeed(UInt16 cardid,UInt16 axis,double speed);
        /*ָ��ܣ�������ļ����ٶ�
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        speed	    ��ļ����ٶ� ����λ��ppu/s
        ���������	��
        ���أ�      0�������*/
       [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLimitSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetLimitSpeed(UInt16 cardid,UInt16 axis,ref double speed);
       /*ָ��ܣ���ȡ��ļ����ٶ�
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                   axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                               EI800ȡֵ��Χ:[0,7];
                               EIC00ȡֵ��Χ:[0,11];
        ���������	*speed	    ��ļ����ٶ� ����λ��ppu/s
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetLimitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetLimitAcc(UInt16 cardid,UInt16 axis,double acc);
        /*ָ��ܣ�������ļ��޼��ٶ�
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        acc	        ��ļ��޼��ٶ�
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLimitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetLimitAcc(UInt16 cardid,UInt16 axis,ref double acc);
        /*ָ��ܣ���ȡ��ļ��޼��ٶ�
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*acc	    ��ļ��޼��ٶ�
        ���أ�      0�������*/

        //��ǰλ��
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetCmmandPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetCmmandPosition(UInt16 cardid, UInt16 axis, double pos);
        /*ָ��ܣ��������ָ��λ��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        pos	        ָ��λ��ֵ
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetCmmandPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetCmmandPosition(UInt16 cardid,UInt16 axis, ref double pos);
        /*ָ��ܣ���ѯ���ָ��λ��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*pos	    ָ��λ��ֵ
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEncoderPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetEncoderPosition(UInt16 cardid,UInt16 axis, double pos);
        /*ָ��ܣ����ñ�����λ��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
			        pos	        �������趨ֵ
        ���������	��
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEncoderPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetEncoderPosition(UInt16 cardid,UInt16 axis, ref double pos);
        /*ָ��ܣ���ȡ������λ��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*pos	    ������λ��
        ���أ�      0�������*/

        [DllImport("PLT.dll", EntryPoint = "Plt_AxSetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxSetBand(UInt16 cardid, UInt16 axis, double band, UInt32 hold_time, UInt32 check_time);
        /*ָ��ܣ������ᵽλ����
         ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                     axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                 EI800ȡֵ��Χ:[0,7];
                                 EIC00ȡֵ��Χ:[0,11];
                     band	    ��������λ��PPU
                     hold_time	������λ�ý���������С����ʱ�� ��λ��ms
                     check_time	�ᵽλ�����ʱ�� ��λ��ms
         ���������	��
         ˵����      1����λ�ж��߼��������������Ŀ��λ�õĲ�ֵС���������ҳ���ʱ�������С����ʱ�䣬���ж϶�λ���
                     2������������ʱ��֮��û�����㡰��λ�ж��߼��������ж϶�λʧ��
         ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetBand(UInt16 cardid, UInt16 axis, ref double band, ref UInt32 hold_time, ref UInt32 check_time);
        /*ָ��ܣ���ѯ�ᵽλ�������
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*band	��������λ��PPU
                    *hold_time	������λ�ý���������С����ʱ�� ��λ��ms
			        *check_time	�ᵽλ�����ʱ�� ��λ��ms
        ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetBandFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetBandFlag(UInt16 cardid, UInt16 axis, ref UInt16 band_flag);
        /*ָ��ܣ���ȡ����������־
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                    axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������	*band_flag	0����λ��
                                1����λ���
                                2����λʧ��
        ���أ�      0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetBandLocationTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetBandLocationTime(UInt16 cardid, UInt16 axis, ref UInt32 location_time);
        /*ָ��ܣ���ȡ������λʱ��
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                    axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������  *location_time  ��ǰ��ʱʱ�䣨�����巢����ɿ�ʼ���㣩                 ��λ��ms
        ���أ�      0�������*/

        [DllImport("PLT.dll", EntryPoint = "Plt_AxCheckEncoderDirResever", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxCheckEncoderDirResever(UInt16 cardid, UInt16 axis, UInt32 hold_time);
        /*ָ��ܣ����������˶������Ƿ������巽���෴
         ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                     axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                 EI800ȡֵ��Χ:[0,7];
                                 EIC00ȡֵ��Χ:[0,11];
                     hold_time	�����෴����ʱ�� ��λ��ms,
                                 ���hold_time����Ϊ0 �����δ˹���
                                 ���hold_time����Ϊ��0������˶�����Hold_timeʱ��󣬱����������巽�����෴�ģ����Զ����м���ֹͣ������������������25
         ���������	��
         ���أ�      0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_AxGetCheckEncoderDirResever", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_AxGetCheckEncoderDirResever(UInt16 cardid, UInt16 axis, ref UInt32 hold_time);
        /*ָ��ܣ����������˶������Ƿ������巽���෴�Ĳ�����ѯ
        ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                    axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];
        ���������  *hold_time	�����෴����ʱ�� ��λ��ms
        ���أ�      0�������*/
        /*************************************************************************��ȫ����***************************************************************/
         public struct struct_el_parms
        {
            public UInt16 pel_enable;//����λʹ�ܣ�0������λ��ֹ��1������λʹ��
            public UInt16 mel_enable;//����λʹ�ܣ�0������λ��ֹ��1������λʹ��
            public UInt16 pel_active_level;//����λ��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
            public UInt16 mel_active_level;//����λ��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
            public UInt16 pel_react;//����λ��Чֹͣ��ʽ��0������ֹͣ��1������ֹͣ
            public UInt16 mel_react;//����λ��Чֹͣ��ʽ��0������ֹͣ��1������ֹͣ
        }; //Ӳ��λ�����ṹ��

        public struct struct_sw_el_parms
        {
            public double melpos;//������λλ�ã���λ:[ppu]
            public double pelpos;//������λλ�ã���λ:[ppu]
            public UInt16 enable;//����λʹ�ܣ�0������λ��ֹ��1������λʹ��
            public UInt16 react;//����λ��Чֹͣ��ʽ��0������ֹͣ��1������ֹͣ
        };//����λ�����ṹ��
     [DllImport("PLT.dll", EntryPoint = "Plt_AxSetEl", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxSetEl(UInt16 cardid,UInt16 axis,struct_el_parms elparms); 
     /*ָ��ܣ�����Ӳ����λ
     ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                 axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                             EI800ȡֵ��Χ:[0,7];
                             EIC00ȡֵ��Χ:[0,11];
                 elparms	    Ӳ��λ����
     ���������	��
     ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEl", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxGetEl(UInt16 cardid,UInt16 axis,ref struct_el_parms elparms);
     /*ָ��ܣ���ȡӲ����λ������
     ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                 axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                             EI800ȡֵ��Χ:[0,7];
                             EIC00ȡֵ��Χ:[0,11];
     ���������	*elparms	Ӳ��λ����
     ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxSetSWEL", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxSetSWEL(UInt16 cardid,UInt16 axis,struct_sw_el_parms swelparms);
     /*ָ��ܣ����������λ
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
             axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                         EI800ȡֵ��Χ:[0,7];
                         EIC00ȡֵ��Χ:[0,11];
             swelparms	�����λ����
    ���������	��
    ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxGetSWEL", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxGetSWEL(UInt16 cardid,UInt16 axis,ref struct_sw_el_parms swelparms);
     /*ָ��ܣ���ȡ�����λ������
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
             axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                         EI800ȡֵ��Χ:[0,7];
                         EIC00ȡֵ��Χ:[0,11];
    ���������	*swelparms	�����λ����
    ���أ�      0�������*/
/*************************************************************************��ȫ����***************************************************************/

/*************************************************************************ר�ýӿ�***************************************************************/
    public struct struct_special_input_parms
    {
        public UInt16 emg_enable;//emgʹ�ܿ��أ�0��ʹ�ܽ�ֹ 1��ʹ����Ч
        public UInt16 emg_level;//emg��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public UInt16 emg_port;//ӳ��ΪEMG������IO��   ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
        public UInt16 alm_enable;//almʹ�ܿ��أ�0��ʹ�ܽ�ֹ 1��ʹ����Ч
        public UInt16 alm_level;//alm��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public double filter_time;//�����ź��˲�ʱ�䣻��λ[ms]
        public UInt16 inp_enable;//inpʹ�ܿ��أ�0��ʹ�ܽ�ֹ 1��ʹ����Ч
        public UInt16 inp_level;//inp��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
    };//

    public struct struct_special_input_status
    {
        public UInt16 alm_status;//alm״̬��0:��Ч��1����Ч
        public UInt16 el_pos_status;//����λ״̬��0:��Ч��1����Ч
        public UInt16 el_neg_status;//����λ״̬��0:��Ч��1����Ч
        public UInt16 swel_pos_status;//������λ״̬��0:��Ч��1����Ч
        public UInt16 swel_neg_status;//������λ״̬��0:��Ч��1����Ч
        public UInt16 emg_status;//emg״̬��0:��Ч��1����Ч
        public UInt16 home_status;//ԭ��״̬��0:��Ч��1����Ч
        public UInt16 inp_status;//inp״̬��0:��Ч��1����Ч
        public UInt16 ez_status;//ez״̬��0:��Ч��1����Ч
        public UInt16 rdy_status;//rdy״̬��0:��Ч��1����Ч
    };//ר������״̬
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigSpecialInputParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigSpecialInputParms(UInt16 cardid,UInt16 axis,struct_special_input_parms specinput);
    /*ָ��ܣ�����EMG\ERC\INP\ALM���źź��˲�ʱ��
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
			    specinput	ר����������
    ���������	��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadSpecialInputParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadSpecialInputParms(UInt16 cardid,UInt16 axis,ref struct_special_input_parms specinput);
    /*ָ��ܣ���ȡEMG\ERC\INP\ALM���źź��˲�ʱ�������
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
    ���������	*specinput	ר����������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadSpecialInputStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadSpecialInputStatus(UInt16 cardid,UInt16 axis,ref struct_special_input_status inputstatus);
    /*ָ��ܣ���ȡ��ר�������ź�״̬
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
    ���������	*inputstatus	ר������״̬
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetsvonPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetsvonPort(UInt16 cardid,UInt16 axis,UInt16 active_level);
    /*ָ��ܣ����SEVON�ź�
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
                active_level	SERV-ON�����ƽֵ 0:�͵�ƽ 1���ߵ�ƽ
    ���������	��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetsvonPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetsvonPort(UInt16 cardid,UInt16 axis,ref UInt16 active_level);
    /*ָ��ܣ���ȡSEVON�ź�
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
    ���������	*active_level	SERV-ON�����ƽֵ 0:�͵�ƽ 1���ߵ�ƽ
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetRdyPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetRdyPort(UInt16 cardid,UInt16 axis,ref UInt16 active_level);
    /*ָ��ܣ���ȡRDY�źţ��˺���������
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
    ���������	*active_level	RDY�ź�����ֵ 0:�͵�ƽ 1���ߵ�ƽ
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetErcPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetErcPort(UInt16 cardid,UInt16 axis,UInt16 active_level);
    /*ָ��ܣ�����ERC�ź������ƽ
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
			    active_level	ERC�ź����ֵ	0:�͵�ƽ 1���ߵ�ƽ
    ���������	��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetErcPort", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetErcPort(UInt16 cardid,UInt16 axis,ref UInt16 active_level);
    /*ָ��ܣ���ȡ����ERC�ź������ƽ
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                            EI800ȡֵ��Χ:[0,7];
                            EIC00ȡֵ��Χ:[0,11];
    ���������	*active_level	ERC�ź����ֵ 0:�͵�ƽ 1���ߵ�ƽ
    ���أ�      0�������*/
/*************************************************************************ר�ýӿ�***************************************************************/

/*************************************************************************����IO���ù���*********************************************************/
    public struct struct_original_type
    {
        public UInt16 type;//0������λ 1������λ 2��ԭ�� 3���ŷ�����  4���ŷ�׼�� 5���ŷ���λ 6:ͨ������IO
        public UInt16 axis;//���.EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];type С��6ʱ�˲�����Ч
        public UInt16 bitno;//ͨ������IO��ţ�EI400\EI400S:[0,31]��EI800\EIC00:[0,15];type����6ʱ�˲�����Ч
        public double Filter;//�˲�ʱ�䣬��λ[ms]
    };//ԭʼ����IO����
    public struct struct_reuse_type
    {
        public UInt16 axis;//���,EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
        public UInt16 type;//0������λ 1������λ 2��ԭ�� 3����ͣ  4������ֹͣ 5���ŷ����� 6:�ŷ�׼�� 7:�ŷ���λ
    };//��������IO����
    [DllImport("PLT.dll", EntryPoint = "PLT_IoSet_input_reuse_to_special_input", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoSet_input_reuse_to_special_input(UInt16 cardid,struct_original_type original_type,struct_reuse_type reuse_type);
    /*ָ��ܣ�ͨ������IO����ר������IO����Ϊר������IO
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                original_type �����õ�ͨ������IO��Ż���ר������IO����
                reuse_type    ���ú��ר������IO����
    �����������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoSet_special_input_reuse_to_input_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoSet_special_input_reuse_to_input_extern(UInt16 cardid,struct_original_type original_type,UInt16 bitno);
    /*����������ר������IO����Ϊͨ������IO
   ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
               original_type ר������IO����
               bitno ���ú�IO���     EI400\EI400Sȡֵ��Χ:[0,23];
                                      EI800ȡֵ��Χ:[0,47];
                                      EIC00ȡֵ��Χ:[0,71];
   �����������
   ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoGet_special_input_reuse", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoGet_special_input_reuse(UInt16 cardid,struct_reuse_type reuse_type,ref struct_original_type original_type);
    /*ָ��ܣ���ȡ��ר������IO��������
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                reuse_type��������IO����
    ���������  original_type  ԭʼ����IO����
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoGet_input_extern_reuse", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoGet_input_extern_reuse(UInt16 cardid,UInt16 bitno,ref struct_original_type original_type);
    /*ָ��ܣ���ȡ��չ����IO��������
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                bitno       EI400\EI400Sȡֵ��Χ:[0,23];
                            EI800ȡֵ��Χ:[0,47];
                            EIC00ȡֵ��Χ:[0,71];
    ���������  *original_type ԭʼ����IO����
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "PLT_IoRead_input_reuse_bybit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short PLT_IoRead_input_reuse_bybit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level);
    /*ָ��ܣ���ȡ��������IO״̬
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                bitno       EI400\EI400Sȡֵ��Χ:[0,23];
                            EI800ȡֵ��Χ:[0,47];
                            EIC00ȡֵ��Χ:[0,71];
    ���������  *active_level ��������IO��ֵ
    ���أ�      0�������*/
/*************************************************************************����IO���ù���*****************************************************/


/*************************************************************************ͨ���������IO**********************************************************/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadInputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level); 	
    /*ָ��ܣ���ȡ����ڵ�״̬
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
    ���������  *active_level �����״̬ 0���͵�ƽ  1���ߵ�ƽ
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoWriteOutputByBit(UInt16 cardid,UInt16 bitno,UInt16 active_level); 	
    /*ָ��ܣ���������ڵ�״̬
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			    active_level ��������״̬ 0���͵�ƽ  1���ߵ�ƽ
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadOutputByBit(UInt16 cardid,UInt16 bitno,ref UInt16 active_level);  
    /*ָ��ܣ���ȡ����ڵ�״̬
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
                bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
    ���������  *active_level �����״̬ 0���͵�ƽ  1���ߵ�ƽ
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadAllInput(UInt16 cardid,ref UInt32 active_level_1,ref UInt32 active_level_2);
    /*ָ��ܣ���ȡ����˿ڵ�ֵ
    ���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
    ���������  *active_level_1	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31
                                EI400\EI400S: bit0-bit31λ����Ч��
                                EI800\EIC00: bit0-bit15λ��Ч��
                *active_level_2	�����32--63��״̬, bit0��ӦIN32��bit31��ӦIN63��������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReadAllOutput(UInt16 cardid,ref UInt32 active_level);
    /*ָ��ܣ���ȡ����˿ڵ�ֵ
    ���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
    ���������  *active_level           ���������0--31��״̬, bit0��ӦOUT0��bit31��ӦOUT31
                                        EI400\EI400S: bit0-bit31λ����Ч��
                                       EI800\EIC00: bit0-bit15λ��Ч��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoWriteAllOutput(UInt16 cardid,UInt32 active_level);
    /*ָ��ܣ���������˿ڵ�ֵ
    ���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
               active_level	            ��������ڵ����״̬, bit0��ӦOUT0��bit31��ӦOUT31
                                        EI400\EI400S: bit0-bit31λ����Ч��
                                        EI800\EIC00: bit0-bit15λ��Ч��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoReverseOutputBit(UInt16 cardid,UInt16 bitno,double hold_time);
    /*ָ��ܣ���ת��ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
    ���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
                bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
                hold_time	��ƽ����ʱ�䣬��λ��ms
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoInitOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoInitOutputBit(UInt16 cardid);
    /*ָ��ܣ��ѵ�ǰ���IO��ʼ��ƽ�����´ο������ϵ�����IO�ĳ�ʼ��ƽ����ͨ�����IO��ʼ��ƽ�ɿ��ƿ���ǰͨ�����IO��ƽ�����������������ÿ��ƿ������ϵ���Ч��
    ���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoInitALLOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoInitALLOutput(UInt16 cardid, UInt32 active_level);
    /*ָ��ܣ��������IO��ʼ��ƽ����ͨ�����IO��ʼ��ƽ�ɴ˺������ã����ƿ������ϵ���Ч��
    ���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
                active_level	���������0--31��״̬, bit0��ӦOUT0��bit31��ӦOUT31
                EI400\EI400S: bit0-bit31λ����Ч��
                EI800\EIC00: bit0-bit15λ��Ч��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoSetOutputMap", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoSetOutputMap(UInt16 cardid, UInt16 logic_output_num, UInt16 physical_out_num);
    /*ָ��ܣ�����ͨ�����IOӳ��
      ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                  logic_output_num �߼����IO�����
                  physical_out_num ʵ������İ忨����IO�����
      ���������  ��
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoGetOutputMap", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoGetOutputMap(UInt16 cardid, UInt16 logic_output_num, ref UInt16 physical_out_num);
    /*ָ��ܣ���ѯͨ�����IOӳ��
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *logic_output_num �߼����IO�����
                *physical_out_num ʵ������İ忨����IO�����
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoSetNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoSetNegation(UInt16 cardid, UInt32 output_negation, UInt32 input_negation);
    /*ָ��ܣ����ñ���IOȡ��
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                output_negation	�����0��31λ�Ƿ�ȡ��,0����ȡ�� 1��ȡ��
                                bit0��ӦIN0��bit31��ӦIN31
                                EI400\EI400S: bit0-bit31λ����Ч��
                                EI800\EIC00: bit0-bit15λ��Ч��
                input_negation	�����0��31λ�Ƿ�ȡ��,0����ȡ�� 1��ȡ��
                                bit0��ӦIN0��bit31��ӦIN31
                                EI400\EI400S: bit0-bit31λ����Ч��
                                EI800\EIC00: bit0-bit15λ��Ч��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoGetNegation", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoGetNegation(UInt16 cardid, ref UInt32 output_negation, ref UInt32 input_negation);
    /*ָ��ܣ��ض�����IOȡ������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *output_negation	�����0��31λ�Ƿ�ȡ��,0����ȡ�� 1��ȡ��
                                bit0��ӦIN0��bit31��ӦIN31
                                EI400\EI400S: bit0-bit31λ����Ч��
                                EI800\EIC00: bit0-bit15λ��Ч��
                *input_negation	�����0��31λ�Ƿ�ȡ��,0����ȡ�� 1��ȡ��
                                bit0��ӦIN0��bit31��ӦIN31
                                EI400\EI400S: bit0-bit31λ����Ч��
                                EI800\EIC00: bit0-bit15λ��Ч��
    ���أ�      0�������*/

   /*ָ��ܣ���������趨��������
    ���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
			    pulse_num      ������������
			    freq           ���Ƶ��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoOutputPulses", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoOutputPulses(UInt16 cardid, UInt32 pulse_num, UInt32 hold_time);
    /*ָ��ܣ�ֹͣ��������趨��������
    ���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_IoOutputPulsesStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoOutputPulsesStop(UInt16 cardid);
    [DllImport("PLT.dll", EntryPoint = "Plt_Io_set_check_input_for_output", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_Io_set_check_input_for_output(UInt16 cardid, UInt16 input_id, UInt16 enable_flag, UInt16 input_logic, UInt16 output_id, UInt16 output_logic);
    /*ָ��ܣ����õȴ���ĳ������IO�趨�������ƽʱ���ض������IO������õĵ�ƽ
    ���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
                input_id: ����IO���[0,7]
			    enable_flag: 1:�����˹���  0���رմ˹���
			    input_logic���ȴ�������IO��ƽ
			    output_id�����IO���[0,7]
			    output_logic�������ƽ
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_Io_get_check_input_for_output", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_Io_get_check_input_for_output(UInt16 cardid, UInt16 input_id, ref UInt16 enable_flag, ref UInt16 input_logic, ref UInt16 output_id, ref UInt16 output_logic);
    /*ָ��ܣ���ȡ�ȴ���ĳ������IO�趨�������ƽʱ���ض������IO������õĵ�ƽ
    ���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
                input_id: ����IO���[0,7]
    ���������  enable_flag: 1:�����˹���  0���رմ˹���
			    input_logic���ȴ�������IO��ƽ
			    output_id�����IO���[0,7]
			    output_logic�������ƽ
    ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_IoSetInputFieterTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_IoSetInputFieterTime(UInt16 cardid, UInt16 bitno, double hold_time); 
        /*ָ��ܣ���������IO�˲�ʱ��,Ŀǰ�˺���ֻ֧��EIO0808
        ���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
                    bitno       ����ڱ��,ȡֵ��Χ��[0,7]
			        hold_time	�˲�ʱ��ʱ�䣬��λ��s
        ���������  ��
        ���أ�      0�������*/ 
/*************************************************************************ͨ���������IO**********************************************************/

/*************************************************************************һάλ�ñȽϹ���*********************************************************/
    public struct struct_axis_compare_parms
    {
        public UInt16 cmp_axis;//�Ƚ���� ,EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
        public UInt16 enable;//�Ƚ�ʹ�ܿ��أ�0���ȽϽ�ֹ��1���Ƚ�����
        public UInt16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
    };//����λ�ñȽ����ò����ṹ��
    public struct struct_axis_compare_datas
    {
        public double cmpposition; //�Ƚ�λ�ã���λ��[pulse]
        public UInt16 cmpmethod; //�ȽϷ�����0�����ڵ��ڣ�1��С�ڵ���
        public UInt16 reaction;//�Ƚ϶���;0���趨io�ŵ�ƽȡ����1���趨io������͵�ƽ��2���趨IO������ߵ�ƽ��3���趨io������趨ʱ���ȵ����壻4���趨�����ֹͣ��5���趨������ֹͣ
        public double pulsewidth;//�����ȣ���λ��[ms]
        public UInt16 react_object;//�趨io�Ż����趨��
    };//����Ƚϻ���������
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareSetParms(UInt16 cardid, UInt16 cmpno, struct_axis_compare_parms axcmpparms);
    /*ָ��ܣ����ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
                axcmpparms	һάλ�ñȽ����ò���
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetParms(UInt16 cardid, UInt16 cmpno, ref struct_axis_compare_parms axcmpparms);
    /*ָ��ܣ���ȡ���ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
    ���������  *axcmpparms	һάλ�ñȽ����ò���
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareClearBuf(UInt16 cardid,UInt16 cmpno);
    /*ָ��ܣ�����Ƚ������бȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareSetData(UInt16 cardid, UInt16 cmpno, struct_axis_compare_datas axcmpdata);
    /*ָ��ܣ���ӱȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
                axcmpdata	�Ƚ�λ�ò���
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetData(UInt16 cardid,UInt16 cmpno,ref double cmpposition);
    /*ָ��ܣ���ȡ��ǰ�Ƚϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
                *cmpposition	������һ���������еıȽϵ�
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetComparedDataNum(UInt16 cardid,UInt16 cmpno,ref Int32 num);
    /*ָ��ܣ���ѯ�Ѿ��ȽϹ��ĵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
                *num	�Ѿ������˱Ƚϵ�λ�ø���
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCompareGetBufRemain(UInt16 cardid,UInt16 cmpno,ref Int32 space);
    /*ָ��ܣ���ѯ���Լ���ıȽϵ�����
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
                *space	ʣ��ȽϿռ�
    ���������  ��
    ���أ�      0�������*/
/*************************************************************************һάλ�ñȽϹ���*********************************************************/
/*************************************************************************��άλ�ñȽϹ���*********************************************************/
    public struct struct_crd_compare_datas
    {
       [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 2)]
       public UInt16[] axis_array;//�Ƚ����б� ȡֵ��Χ��EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7]; EIC00ȡֵ��Χ:[0,11];
       [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 2)]
       public double[] cmpposition_array;//�Ƚ�λ���б�
       [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 2)]
       public UInt16[] cmpmethod_array;//�ȽϷ�����0�����ڵ��ڣ�1��С�ڵ���
       public UInt16 reaction;//�Ƚ϶���;0���趨io�ŵ�ƽȡ����1���趨io������͵�ƽ��2���趨IO������ߵ�ƽ��3���趨io������趨ʱ���ȵ����壻4���趨�����ֹͣ��5���趨������ֹͣ
       public double pulsewidth;//�����ȣ���λ��[ms]
       public UInt16 react_object;//�趨io�Ż����趨��
    };//��ά�Ƚϻ���������
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdcCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdcCompareSetParms(UInt16 cardid, UInt16 enable, UInt16 cmp_source); 	
    /*ָ��ܣ����ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                enable	��ά�Ƚ��Ƿ�ʹ��  1��ʹ�� 0����ֹ
                cmp_source �Ƚ�Դ 0��������� 1������������
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdcCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdcCompareGetParms(UInt16 cardid, ref UInt16 enable, ref UInt16 cmp_source);
    /*ָ��ܣ���ȡ���ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *enable	��ά�Ƚ��Ƿ�ʹ��  1��ʹ�� 0����ֹ
                *cmp_source �Ƚ�Դ 0��������� 1������������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareClearBuf(UInt16 cardid); 
    /*ָ��ܣ�������бȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareSetData(UInt16 cardid, struct_crd_compare_datas crdcmpdata);
    /*ָ��ܣ���ӱȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                crdcmpdata �Ƚϵ�����ṹ��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareGetData(UInt16 cardid, ref UInt16[] axis_array, ref double[] cmpposition_array); 
    /*ָ��ܣ���ȡ��ǰ�Ƚϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *axis_array �Ƚ����б�
                *cmpposition_array �Ƚ�λ���б�
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareGetComparedDataNum(UInt16 cardid, ref long num);
    /*ָ��ܣ�/��ѯ�Ѿ��Ƚϵ�����
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *num �ѱȽϵ�����
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdCompareGetBufRemain(UInt16 cardid, ref long space); 	//��ѯ���Լ���ıȽϵ�����
    /*ָ��ܣ�/��ѯʣ��Ƚϻ�����
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *space ʣ��Ƚϻ�������С
    ���أ�      0�������*/
    /*************************************************************************��άλ�ñȽϹ���*********************************************************/
/*************************************************************************һά��ȷλ�ñȽϹ���*********************************************************/
    public struct struct_axis_accurate_compare_parms
    {
        public UInt16 cmp_axis;//�Ƚ���� EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
        public UInt16 enable;//�Ƚ�ʹ�ܿ��أ�0;�ȽϽ�ֹ��1���Ƚ�����
        public UInt16 cmpmethod;//�ȽϷ�����0�����ڣ�1��С��; 2������ 3:�������ȽϷ���(����λ��ģʽ) 4�����ԱȽϷ� 5��:�������ȽϷ���(���λ��ģʽ)
        public UInt16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
        public UInt16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public double pulsewidth;//�����ȣ���λ����ms��;�˲���ֻ����cmpmethod���ڵ���3�������Ч
        public double liner_distance;//����λ�ñȽ�����ֵ
        public UInt32 liner_num;//����λ�ñȽ���
    };//��ȷλ�ñȽ�
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareSetParms(UInt16 cardid, UInt16 queueno, struct_axis_accurate_compare_parms acccmpparms);
    /*ָ��ܣ����ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                queueno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
                acccmpparms	һά����λ�ñȽ����ò���
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetParms(UInt16 cardid, UInt16 queueno, ref struct_axis_accurate_compare_parms acccmpparms);
    /*ָ��ܣ���ȡ���ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                queueno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
    ���������  *acccmpparms	һά����λ�ñȽ����ò���
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareClearBuf(UInt16 cardid,UInt16 cmpno);
    /*ָ��ܣ�����Ƚ������бȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareSetData(UInt16 cardid,UInt16 cmpno,UInt16 axis,double cmpposition);
    /*ָ��ܣ���ӱȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
                cmpposition	�Ƚ�λ��
			    axis	��������
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetData(UInt16 cardid,UInt16 cmpno,UInt16 axis,ref double cmpposition);
    /*ָ��ܣ���ȡ��ǰ�Ƚϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
			    axis	��������
    ���������  *cmpposition	�Ƚ�λ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetComparedDataNum(UInt16 cardid,UInt16 cmpno,ref Int32 num); 	
    /*ָ��ܣ���ѯ�Ѿ��ȽϹ��ĵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
    ���������  *num	�����Ѿ������˱Ƚϵ�λ������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetBufRemain(UInt16 cardid,UInt16 cmpno,ref Int32 space);
    /*ָ��ܣ���ѯ���Լ���ıȽϵ�����(���ԱȽ�ģʽ��space����ʣ��ıȽϵ���)
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
    ���������  *num	�����Ѿ������˱Ƚϵ�λ������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareGetRemainPoints", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareGetRemainPoints(UInt16 cardid, UInt16 cmpno, ref Int32 remain_points);
    /*ָ��ܣ���ѯ���м����Ƚϵ㻹û�н��бȽ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
    ���������  *remain_points	���м����Ƚϵ㻹û�н��бȽ�
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareOutputMapSet", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareOutputMapSet(UInt16 cardid, UInt16 axis_id, UInt16 enable);
    /*ָ��ܣ���10����11��ӳ��Ϊ���������
    ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
              axis_id      ��ţ�ȡֵ��Χ��10��11
              enable	1:�����������ӳ��Ϊ��������� 0������������ָ�Ϊ���������
    �����������
    ���ز�����������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareOutputMapGet", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareOutputMapGet(UInt16 cardid, UInt16 axis_id,ref UInt16 enable);
    /*ָ��ܣ���ȡ��10����11��ӳ���Ƿ�ӳ��Ϊ���������
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
            axis_id     ��ţ�ȡֵ��Χ��10��11       
  ���������*enable	1:�����������ӳ��Ϊ��������� 0������������ָ�Ϊ���������
  ���ز�����������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxAccurateCompareSetMultiData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxAccurateCompareSetMultiData(UInt16 cardid, UInt16 cmpno, UInt16 data_num, double[] cmpposition);
    /*ָ��ܣ����ٱȽ���Ӷ���Ƚϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
			    data_num	��ӵıȽϵ���� ȡֵ��Χ��[1,127]
                *cmpposition 	�Ƚϵ�λ������  ��λ��ppu
    ���������  ��
    ���أ�      0�������*/
/*************************************************************************����λ�ñȽϹ���*********************************************************/

/*************************************************************************��ά��ȷλ�ñȽϹ���*********************************************************/
    public struct struct_crd_accurate_compare_parms
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
        public UInt16[] axis_array;//�Ƚ����б� ��EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];
        public UInt16 enable;//�Ƚ�ʹ�ܿ��أ�0;�ȽϽ�ֹ��1���Ƚ�����
        public UInt16 cmpmethod;//�ȽϷ�����0��������ȽϷ���1���뿪����ȽϷ�
        public UInt16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
        public UInt16 active_level;//�����Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public double pulsewidth;//�����ȣ���λ����ms��;
        public double cmp_error;//���ȣ���λ[pulse]
    };//��ȷλ�ñȽ�
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareSetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareSetParms(UInt16 cardid,struct_crd_accurate_compare_parms acccmpparms);
    /*ָ��ܣ����ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                acccmpparms ���ٶ�ά�Ƚ����ò����ṹ��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetParms(UInt16 cardid,ref struct_crd_accurate_compare_parms acccmpparms);
    /*ָ��ܣ����ñȽ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *acccmpparms ���ٶ�ά�Ƚ����ò����ṹ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareClearBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareClearBuf(UInt16 cardid);
    /*ָ��ܣ�����Ƚ������бȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareSetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareSetData(UInt16 cardid,double[] cmpposition_array);
    /*ָ��ܣ���ӱȽϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                *cmpposition_array	�Ƚ�λ���б�
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetData", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetData(UInt16 cardid,double[] cmpposition_array);
    /*ָ��ܣ���ȡ��ǰ�Ƚϵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *cmpposition_array	�Ƚ�λ���б�
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetComparedDataNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetComparedDataNum(UInt16 cardid,ref Int32 num); 	
    /*ָ��ܣ���ѯ�Ѿ��ȽϹ��ĵ�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *num	�Ѿ������˱Ƚϵ�λ������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateCompareGetBufRemain", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateCompareGetBufRemain(UInt16 cardid,ref Int32 space);
    /*ָ��ܣ���ѯ���Լ���ıȽϵ�����
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
    ���������  *space	ʣ��ȽϿռ�
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateConfigOutBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateConfigOutBit(UInt16 cardid, UInt32 bitmask); 	
    /*ָ��ܣ�ѡ���ά���ٱȽ������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                bitmask ȡֵ��Χ12��13
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdAccurateReadOutBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdAccurateReadOutBit(UInt16 cardid, ref UInt32 bitmask); 	
    /*ָ��ܣ�ѡ���ά���ٱȽ������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                bitmask ȡֵ��Χ12��13
    ���������  ��
    ���أ�      0�������*/
/*************************************************************************����λ�ñȽϹ���*********************************************************/



/*************************************************************************λ�����湦��*********************************************************/
    public struct struct_axis_latch_parms
    {
        public UInt16 active_level;//��Ч�أ�0������������1���½�������
        public UInt16 latch_method;//���淽ʽ��0���������棻1����������
        public UInt16 latch_source;//����Դ��0����������λ�ã�1�����������λ�ã�
    };//λ����������
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigLatchParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigLatchParms(UInt16 cardid, UInt16 ltc_num, UInt16 axis, struct_axis_latch_parms ltcparms);
    /*ָ��ܣ����ø����������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
                ltcparms	�������
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadLatchParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadLatchParms(UInt16 cardid, UInt16 ltc_num, UInt16 axis, ref struct_axis_latch_parms ltcparms);
    /*ָ��ܣ���ȡ������������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
    ���������  *ltcparms	�������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLatchFlagStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetLatchFlagStatus(UInt16 cardid, UInt16 ltc_num, UInt16 axis, ref UInt16 latchstatus);
    /*ָ��ܣ���ȡ��������־
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
    ���������  *latchstatus	�����־��1:���������� 0��û���������ݣ�
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxClearLatchStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxClearLatchStatus(UInt16 cardid, UInt16 ltc_num, UInt16 axis);
    /*ָ��ܣ���λ��������־
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLacthPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetLacthPosition(UInt16 cardid, UInt16 ltc_num, UInt16 axis, UInt16 startpos_index, UInt16 count,  double[] position);
    /*ָ��ܣ���λ��������־
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetLatchNum", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetLatchNum(UInt16 cardid, UInt16 ltc_num, UInt16 axis, ref Int32 num);
    /*ָ��ܣ���ѯ�Ѿ���������ݸ���
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
                ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
    ���������  *num	����ĸ���
    ���أ�      0�������*/
/*************************************************************************λ�����湦��*********************************************************/



/*************************************************************************���㹦��*********************************************************/
    //����ģ��
    public struct struct_home_config_parms
    {
        public double home_high_vel;//������٣���λ����pulse/s��,ȡֵ��Χ��0,4000000��
        public double home_low_vel;//������٣���λ����pulse/s��,ȡֵ��Χ��0,4000000��
        public double home_acc;//����Ӽ��ٶ�, ��λ����pulse/s2��,ȡֵ��Χ��0,4000000000��
        public UInt16 home_mode;//0:ԭ�㲶�����;1��EZ�������;2:ԭ��+EZ������� 3��������EZ������� 4��һ�λ��� 5�����λ��� 6��һ�λ���ӷ��һ��� 7��ԭ���EZ���� 8��ez���� 9��������EZ����
        public UInt16 org_level;//ԭ����Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public UInt16 org_ltc_source;//ԭ������Դ��0������λ�� 1��������λ��
        public UInt16 ez_level;//ez��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public UInt16 ez_ltc_source;//ez����Դ��0������λ�� 1��������λ��
        public UInt16 org_ltc_level;//0������������ԭ��  1���½�������ԭ��
        public UInt16 ez_ltc_level;//0������������ez 1���½�������ez
    };//����ģ�����ò���
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigHomeParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigHomeParms(UInt16 cardid,UInt16 axis,struct_home_config_parms homeparms);
    /*ָ��ܣ����û������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
			    homeparms	�������
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadHomeParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadHomeParms(UInt16 cardid,UInt16 axis,ref struct_home_config_parms homeparms);
    /*ָ��ܣ���ȡ�������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];			
    ���������  *homeparms	�������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigHomeEncoderFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigHomeEncoderFactor(UInt16 cardid, UInt16 axis, double factor);
    /*ָ��ܣ����ñ���������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
			    factor	����������
    ���������  ��
    ����	1�����������ⲿ���������ŷ������ȣ�ʹÿ���һ�������ܷ���һ����������������ʱֻ��Ҫʹ��Ĭ�ϵı���������1
    2����û�а취ʹ���������������������ʱ����Ҫ���ñ����������������ڻ�����ʹ������ԴΪ������λ��
    3���˲����ڻ�����ʹ�ã���ֻ������ԴΪ������λ��ʱʹ��
    4���˲�����������������Ҳʹ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadHomeEncoderFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadHomeEncoderFactor(UInt16 cardid, UInt16 axis, ref double factor);
    /*ָ��ܣ���ѯ����������
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];			
    ���������  *factor	����������
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxHomeMove", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxHomeMove(UInt16 cardid,UInt16 axis,UInt16 homedir);
    /*ָ��ܣ����������˶�
    ���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
			    homedir	���㷽��0��������1��������
    ���������  ��
    ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxCheckHomeDone", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxCheckHomeDone(UInt16 cardid, UInt16 axis, ref UInt16 done_flag);
    /*ָ��ܣ��������Ƿ����
     ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
               axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                       EI800ȡֵ��Χ:[0,7];
                       EIC00ȡֵ��Χ:[0,11];	
     ���������*done_flag	�����Ƿ���ɱ�־  0������û����� 
                                          1��������� 
										  2��������ֹ��ԭ���Ҳ���ԭ���ź� 
                                          3��������ֹ��ԭ�򣺻��㷽����� 
										  4��������ֹ��ԭ��������λͬʱ��Ч  
										  5��������ֹ��ԭ���Ҳ���EZ�ź�
						                  6��������ֹ��ԭ�򣺳���������������
										  7������ֹͣ��ԭ��������ֹ
     ���ز�����������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHomeSearchDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHomeSearchDistance(UInt16 cardid, UInt16 axis, double home_distance);
    /*ָ��ܣ����û����������룬����������뵽�ﻹû���ҵ�ԭ�㣬���˶�����ֹͣ ֹͣԭ�������24
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
                home_distance �������� ��λ��ppu
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHomeSearchDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHomeSearchDistance(UInt16 cardid, UInt16 axis, ref double home_distance);
    /*ָ��ܣ���ѯ�����������룬����������뵽�ﻹû���ҵ�ԭ�㣬���˶�����ֹͣ ֹͣԭ�������24
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
      ���������*home_distance �������� ��λ��ppu
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHomeStopDelayTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHomeStopDelayTime(UInt16 cardid, UInt16 axis, UInt32 delay_time);
    /*ָ��ܣ����û���������˶�ֹͣ����ʱdelay_time�������������˶���
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
		        delay_time ��ʱʱ�� ����λ ms 
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHomeStopDelayTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHomeStopDelayTime(UInt16 cardid, UInt16 axis, ref UInt32 delay_time);
    /*ָ��ܣ���ȡ����������˶�ֹͣ����ʱʱ�䡣
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
      ���������delay_time ��ʱʱ�� ����λ ms 
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHomeBackDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHomeBackDistance(UInt16 cardid, UInt16 axis, double back_distance);
/*ָ��ܣ����û��㷴��ʱ����ԭ���Ļ��˾���
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
			back_distance �������� ��λ��ppu
  �����������
  ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHomeBackDistance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHomeBackDistance(UInt16 cardid, UInt16 axis, ref double back_distance);
/*ָ��ܣ��ض����㷴��ʱ����ԭ���Ļ��˾���
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
  ���������*back_distance �������� ��λ��ppu
  ���أ�      0�������*/
/*************************************************************************���㹦��*********************************************************/


/*************************************************************************���ֹ���*********************************************************/
    public struct struct_handwheel_config_parms
    {
        public UInt16 handwheelmode;//��������ģʽ��0�������ź�����ģʽ��1������+��������ģʽ��
        public double radio;//���ֱ���;radio <0  ������  radio >0 ������
    };//�������ò���
    [DllImport("PLT.dll", EntryPoint = "Plt_AxConfigHandwheelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxConfigHandwheelParms(UInt16 cardid,UInt16 axis,struct_handwheel_config_parms hwparms);
    /*ָ��ܣ����������˶�����
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
                hwparms	�������ò���
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxReadHandwheelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxReadHandwheelParms(UInt16 cardid,UInt16 axis,ref struct_handwheel_config_parms hwparms);
    /*ָ��ܣ���ȡ��������
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	
      ���������*hwparms	�������ò���
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxHandwheelMove", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxHandwheelMove(UInt16 cardid,UInt16 axis);
    /*ָ��ܣ����������˶�
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHandwheelPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHandwheelPosition(UInt16 cardid, UInt16 axis, double pos);
    /*ָ��ܣ���������λ��
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			    pos	    λ��ֵ
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHandwheelPosition", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHandwheelPosition(UInt16 cardid, UInt16 axis, ref double pos);
    /*ָ��ܣ���ȡ����λ��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
  ���������*pos	    λ��ֵ
  ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetHandwheelChannal", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetHandwheelChannal(UInt16 cardid, UInt16 handwheelchannal);
    /*ָ��ܣ��˺�������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_AxGetHandwheelInputState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetHandwheelInputState(UInt16 cardid, ref UInt16 input_state);
/*ָ��ܣ���ȡ���ֶ��ӿ����ź�����״̬
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
  ���������input_state �� bit0: ��0��ѡ�����ź�״̬ bit1: ��1��ѡ�����ź�״̬ bit2: ��2��ѡ�����ź�״̬ bit3: ��3��ѡ�����ź�״̬
                           bit4: 1�����������ź�״̬ bit5: 10�����������ź�״̬ bit6: 100�����������ź�״̬
						   bit7: ���ּ�ͣ�����ź�״̬
  ���أ�      0�������*/
/*************************************************************************���ֹ���*********************************************************/



/*************************************************************************JOG�͵�λ�˶�����*********************************************************/
    public struct struct_vel_plan_parms
    {
        public double start_vel;     //��ʼ�ٶȣ���λ����ppu/s�� ;ȡֵ��Χ��0,4000000/PPU��
        public double max_vel;       //����ٶȣ���λ����ppu/s��;ȡֵ��Χ(0,4000000/PPU��
        public double end_vel;       //ֹͣ�ٶȣ���λ����ppu/s��;ȡֵ��Χ��0,4000000/PPU��
        public double acc;           //���ٶ�,��λ��[ppu/s2];ȡֵ��Χ(0,4000000000/ppu]
        public double dec;           //���ٶ�,��λ��[ppus/s2];ȡֵ��Χ(0,4000000000/ppu]
    };//�ٶȹ滮����
    //�ٶȲ������ã�
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetSmoothFactor(UInt16 cardid,UInt16 axis,double smooth_factor);
/*ָ��ܣ������ٶ����ߵ�S����ϵ��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
		    smooth_factor	��Plt_AxSetSProfileMode�в���SProfileModeΪ0ʱ����ʾS�α���ϵ����ȡֵ��Χ :[0,1] 
			                ��Plt_AxSetSProfileMode�в���SProfileModeΪ1ʱ����ʾ�˲�ʱ�䣬��λ��s,ȡֵ��Χ[0,1]
  �����������
      ˵����	   ��Plt_AxSetSProfileMode�в���SProfileModeΪ0�� smooth_factorΪ0ʱ���ٶ����߾��������ٶ����ߡ�smooth_factorΪ1ʱ���ٶ����߾�����ƽ����S���ٶ����ߡ�S����ϵ����0��1֮��ʱ���ٶ�����Ҳ�ͽ��������ٶ���������ȫ��S���ٶ�����֮��
                   ��Plt_AxSetSProfileMode�в���SProfileModeΪ1�� smooth_factorΪT���ٶȹ滮�˲�ʱ�䣬�˲�ʱ��Խ���ٶ�����Խƽ��������Ч��Խ�͡�
  ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetSmoothFactor(UInt16 cardid,UInt16 axis,ref double smooth_factor);
    /*ָ��ܣ������ٶ����ߵ�S����ϵ��
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];  
      ���������*smooth_factor	����S�α���ϵ����ȡֵ��Χ :[0,1] 
      ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxSetSProfileMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetSProfileMode(UInt16 cardid, UInt16 axis, UInt16 SProfileMode);
    /*ָ��ܣ�����S���ٶ����߹滮ģʽ(�ú������Զ����˶���Ч)
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
		        SProfileMode	0����ʽ�滮ģʽ   1��T���ٶ�����+�˲�ģʽ
      �����������
          ˵������SProfileModeȡ0ʱ��Plt_AxSetSmoothFactor�����еĲ���smooth_factor��ʾS�����ٶ�ƽ������ϵ����û������λ��
	            ��SProfileModeȡ1ʱ��Plt_AxSetSmoothFactor�����еĲ���smooth_factor��ʾ�˲�ʱ�䣬��λ��s,ȡֵ��Χ[0,1]
      ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_AxGetSProfileMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxGetSProfileMode(UInt16 cardid, UInt16 axis, ref UInt16 SProfileMode);
    /*ָ��ܣ�����S���ٶ����߹滮ģʽ(�ú������Զ����˶���Ч)
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];		    
      ���������SProfileMode	0����ʽ�滮ģʽ   1��T���ٶ�����+�˲�ģʽ
          ˵������SProfileModeȡ0ʱ��Plt_AxSetSmoothFactor�����еĲ���smooth_factor��ʾS�����ٶ�ƽ������ϵ����û������λ��
	            ��SProfileModeȡ1ʱ��Plt_AxSetSmoothFactor�����еĲ���smooth_factor��ʾ�˲�ʱ�䣬��λ��s,ȡֵ��Χ[0,1]
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetvelParms(UInt16 cardid,UInt16 axis,struct_vel_plan_parms axisplanparms);
    /*ָ��ܣ������ٶ����ߵĹ滮����
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
		        axisplanparms	�ٶȹ滮����
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetvelParms(UInt16 cardid,UInt16 axis,ref struct_vel_plan_parms axisplanparms);
    /*ָ��ܣ������ٶ����߹滮����
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];	    
      ���������*axisplanparms	�ٶȹ滮����
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMoveRel(UInt16 cardid,UInt16 axis,double dist);
    /*ָ��ܣ���ʼ��λ�˶����˶�һ��dist���룩
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
                dist	��λ�˶��ľ��룬��λ��PPU distȡֵ��Χ����2147483640/ppu,-2147483640/ppu�� ע�⣺��dist���ϵ�ǰ�Ĵ���ֵ������Χ��2147483640/ppu,-2147483640/ppu�����ᱨ��
      ���������*axisplanparms	�ٶȹ滮����
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMoveAbs(UInt16 cardid,UInt16 axis,double position);
    /*ָ��ܣ���ʼ��λ�˶����˶���positionλ�ã�
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
                position	��λ�˶���Ŀ��λ�ã���λ��PPU positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu��
      ���������*axisplanparms	�ٶȹ滮����
      ���أ�      0�������*/	
     [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeVelMoveRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeVelMoveRel(UInt16 cardid, UInt16 axis, double change_vel, double start_change_vel_dist, double end_change_vel_dist, double dist);
    /*ָ��ܣ���ʼ��λ�˶����˶�һ��dist���룩,�����˶����趨��λ�ý������߱���
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			    change_vel	�м�ƽ�ȶε��ٶ�
                start_change_vel_dist	�м�ο�ʼ���λ��
                end_change_vel_dist	�м�ν������λ��
			    dist �յ�λ����������λ�þ��� positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu��
      �����������
      ���أ�      0�������*/
	 [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeVelMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_AxChangeVelMoveAbs(UInt16 cardid, UInt16 axis, double change_vel, double start_change_vel_pos, double end_change_vel_pos, double position);	
    /*������������ʼ��λ�˶����˶���positionλ�ã�,�����˶����趨��λ�ý������߱���
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			    change_vel	�м�ƽ�ȶε��ٶ�
                start_change_vel_dist	�м�ο�ʼ���λ��
                end_change_vel_dist	�м�ν������λ��
			    position �յ�λ��,positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu��
      �����������
      ���أ�      0�������*/
	[DllImport("PLT.dll", EntryPoint = "Plt_AxMoveVel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMoveVel(UInt16 cardid,UInt16 axis,UInt16 direction);	//ָ�����������˶�
    /*ָ��ܣ�����JOG�˶�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			direction	JOG�˶��ķ���0��������1��������.ָ��λ�����ӵķ���Ϊ�������෴��Ϊ������
  �����������
  ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeTartetPos", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeTartetPos(UInt16 cardid,UInt16 axis,double position);
    /*ָ��ܣ������иı�Ŀ��λ�ã�ԭ����Ŀ��λ���ټ���һ��position���룩
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			position	���߱�λ�˶�����λ�ã���λ��PPU positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu�����ģʽ���߱�λ
  �����������
  ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeTartetPosAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeTartetPosAbs(UInt16 cardid,UInt16 axis,double position);
    /*ָ��ܣ������иı�Ŀ��λ�ã��µ�Ŀ��λ��Ϊposition��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			position	���߱�λ�˶�����λ�ã�����λ�����꣩����λ��PPU positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu������ģʽ���߱�λ
  �����������
  ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeVel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeVel(UInt16 cardid,UInt16 axis,double maxvel);
    /*ָ��ܣ������иı��ٶ�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
            maxvel	���߱��ٺ��µ�����ٶȣ���λ��PPU/s
  �����������
  ���أ�      0�������*/
  [DllImport("PLT.dll", EntryPoint = "Plt_AxChangeTartetPosMaxVelAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxChangeTartetPosMaxVelAcc(UInt16 cardid, UInt16 axis, double position, UInt16 pos_mode, double max_vel, double acc, double dec);
    /*ָ��ܣ�������ͬʱ�ı�ı�Ŀ��λ��
      ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			    axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			            position	���߱�λ�˶�����λ��
					    pos_mode    λ��ģʽ 1������ģʽ  0�����ģʽ 
                        max_vel     ����ٶ� 
					    acc         ���ٶ�
					    dec         ���ٶ�
      �����������
      ���أ�      0�������*/
  [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveRelAndSoftLanding", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
  public static extern short Plt_AxMoveRelAndSoftLanding(UInt16 cardid, UInt16 axis, double soft_landing_vel, double soft_landing_dist, double aim_dist);
/*ָ��ܣ���ʼ������½����Զ����˶�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			soft_landing_vel	����½�ٶ�
            soft_landing_dist	����½λ����������λ�þ���
			aim_dist �յ�λ����������λ�þ��� positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu��
  �����������
  ���أ�      0�������*/	
  [DllImport("PLT.dll", EntryPoint = "Plt_AxMoveAbsAndSoftLanding", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
  public static extern short Plt_AxMoveAbsAndSoftLanding(UInt16 cardid, UInt16 axis, double soft_landing_vel, double soft_landing_pos, double aim_pos);
/*ָ��ܣ���ʼ������½����Զ����˶�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			soft_landing_vel	����½�ٶ�
            soft_landing_pos	����½λ����������λ�þ���
			aim_pos �յ�λ�ã���2147483640/ppu,-2147483640/ppu��
  �����������
  ���أ�      0�������*/	
/*************************************************************************JOG�͵�λ�˶�����*********************************************************/

/*************************************************************************ȡ/�����˶�����*********************************************************/
//ȡ/�����˶�һ����3�ι켣���ֱ��ǣ�ȡ�Ϻ������������ƶ�,���Ϸ��� �漰��5���ᣬ�ֱ�������/�½�Z�ᣬ������תR�ᣬ����ȡ�Ϻ���ƽ�����ƶ���X/Y��,�ȴ�λ���ᡣ
    [DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisSetAxisParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_TakingMaterisSetAxisParms(UInt16 cardid, UInt16 crd, UInt16 wait_input_num, UInt16 wait_input_logic, UInt16[] axis, double ratio_1, double ratio_2);
//ָ��ܣ�����ȡ������ź�ȡ�ϵȴ�����IO��ź͵�ƽ
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//            crd �������
//            wait_input_num ȡ�ϵȴ�����IO���
//		    wait_input_logic ȡ�ϵȴ�����IO��ƽ
//              axis ����б�
//             axis[0]:x���Ӧ�������
//             axis[1]:y���Ӧ�������
//             axis[2]:z���Ӧ�������
//             axis[3]:r���Ӧ�������
//             axis[4]:���ϵȴ�λ�õ�������
//             ratio_1:��һ����ɰٷ�֮ratio_1ʱ�����ڶ���
//             ratio_2:�ڶ�����ɰٷ�֮ratio_2ʱ����������
//  �����������
//  ���ز�����0�������
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisGetAxisParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_TakingMaterisGetAxisParms(UInt16 cardid, UInt16 crd, ref UInt16 wait_input_num, ref UInt16 wait_input_logic, ref UInt16[] axis, ref double ratio_1, ref double ratio_2);
//ָ��ܣ���ȡȡ������ź�ȡ�ϵȴ�����IO��ź͵�ƽ����
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//            crd �������
// ��������� *wait_input_num ȡ�ϵȴ�����IO���
//		      *wait_input_logic ȡ�ϵȴ�����IO��ƽ
//              *axis ����б�
//             *axis[0]:x���Ӧ�������
//             *axis[1]:y���Ӧ�������
//             *axis[2]:z���Ӧ�������
//             *axis[3]:r���Ӧ�������
//             *axis[4]:���ϵȴ�λ�õ�������
//             *ratio_1:��һ����ɰٷ�֮ratio_1ʱ�����ڶ���
//             *ratio_2:�ڶ�����ɰٷ�֮ratio_2ʱ����������
//  ���ز�����0�������
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisSetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisSetvelParms(UInt16 cardid, UInt16 crd, struct_vel_plan_parms[] axisplanparms, double change_vel);
//ָ��ܣ�ȡ�����˶��ٶȲ�������
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//            crd �������
//			axisplanparms[0] ��һ���˶�(����/�½�)�ٶȲ���
//			axisplanparms[1] �ڶ����˶�(XYƽ�ƺ�������ת)���ٶȲ���
//			axisplanparms[2] �������˶�(�½�/����)�ٶȲ���
//			change_vel:���߱����ٶ�
//  �����������
//  ���ز�����������
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisGetvelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisGetvelParms(UInt16 cardid, UInt16 crd, ref struct_vel_plan_parms[] axisplanparms, ref double change_vel);
//ָ��ܣ���ȡȡ�����˶��ٶȲ�������
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//            crd �������
//���������axisplanparms[0] ��һ���˶�(����/�½�)�ٶȲ���
//			axisplanparms[1] �ڶ����˶�(XYƽ�ƺ�������ת)���ٶȲ���
//			axisplanparms[2] �������˶�(�½�/����)�ٶȲ���
//			change_vel:���߱����ٶ�
//  ���ز�����������Plt_TakingMaterisMoveAbs
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisMoveAbs(UInt16 cardid, UInt16 crd, double pos_0, double[] pos_1, double[] pos_2, double[] pos_3, double pos_4, double pos_5, UInt16 motion_mode);
//ָ��ܣ�ȡ���Ͼ����˶�
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//          crd �������
//			  pos_0 ��һ���յ�λ��
//			  pos_1 �ڶ��ε�һ�����ٵ�X/Y/R��λ��
//			  pos_2 �ڶ��εڶ������ٵ�X/Y/R��λ��
//			  pos_3 �ڶ����յ��X/Y/R��λ��
//			  pos_4 �������յ�λ��
//            pos_5�ȴ�λ��
//            motion_mode �˶�ģʽ 0 ��ȡ��  1������,�ҵȴ�pos_5��ʽ�Ǵ��ڵ��� 2������,�ҵȴ�pos_5��ʽ��С�ڵ��� 
//  �����������
//  ���ز�����0�������
[DllImport("PLT.dll", EntryPoint = "Plt_TakingMaterisChangePosAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_TakingMaterisChangePosAbs(UInt16 cardid, UInt16 crd, double[] pos);
//ָ��ܣ�ȡ���Ͼ����˶�
//���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//          crd �������
//			  pos ���߱�λX/Y/R�����λ��
//�����������
//���ز�����0�������
/*************************************************************************ȡ/�����˶�����*********************************************************/

/*************************************************************************ֹͣ����*********************************************************/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxMotionStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxMotionStop(UInt16 cardid, UInt16 axis, UInt16 stop_mode);
    /*ָ��ܣ�ָֹͣ����
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
                stop_mode	ֹͣģʽ  0������ֹͣ 1������ֹͣ
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CardMotionEmgStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CardMotionEmgStop(UInt16 cardid);
    /*ָ��ܣ�ֹͣ������
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetStopAcc(UInt16 cardid, UInt16 axis, double Acc);
    /*ָ��ܣ����ü���ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
                Acc  	����ֹͣ���ٶ�
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetStopAcc(UInt16 cardid, UInt16 axis, ref double Acc);
    /*ָ��ܣ��ض�����ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
      ���������*Acc  	����ֹͣ���ٶ�
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxSetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetUseStopAccFlag(UInt16 cardid, UInt16 axis, UInt16 use_stop_acc_flag);
    /*ָ��ܣ����ü���ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
                use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
      �����������
      ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxGetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetUseStopAccFlag(UInt16 cardid, UInt16 axis, ref UInt16 use_stop_acc_flag);
    /*ָ��ܣ����ü���ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
       ������� *use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
      ���أ�      0�������*/
/*************************************************************************ֹͣ����*********************************************************/

/*************************************************************************�ݾಹ������*********************************************************/
    [DllImport("PLT.dll", EntryPoint = "Plt_AxEnableLeadScrewComp", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxEnableLeadScrewComp(UInt16 cardid,UInt16 axis,UInt16 mode);
    /*ָ��ܣ�ʹ��/��ʹ���ݾಹ������
   ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
             axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
             mode: 1��ʾʹ�ܣ�0��ʾ��ֹ�� 
   �����������
   ���ز�����0�������*/
   [DllImport("PLT.dll", EntryPoint = "Plt_AxGetEnableLeadScrewComp", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxGetEnableLeadScrewComp(UInt16 cardid,UInt16 axis,ref UInt16 mode);
   /*ָ��ܣ���ѯ�ݾಹ����ʹ��״̬
     ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
               axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];	
     ���������*mode: 1��ʾʹ�ܣ�0��ʾ��ֹ�� 
     ���ز�����0�������*/
   [DllImport("PLT.dll", EntryPoint = "Plt_AxSetLeadScrewComp", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_AxSetLeadScrewComp(UInt16 cardid,UInt16 axis,UInt16 n,Int32 startPos,Int32 lenPos,Int32[] pCompPos,Int32[] pCompNeg);
   /*ָ��ܣ������ݾಹ������
   ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
             nΪ��������Χ��1,256��
             startPos Ϊ������ʼ��Ĺ滮λ�ã���λ��pulse���� 
             lenPosΪ�����ε��ܳ�����λ��pulse����  
             pCompPosΪ��ӦΪ�������˶�ʱ������λ����Ҫ�������������� 
             pCompNegΪ��ӦΪ�������˶�ʱ������λ����Ҫ��������������
   �����������
   ����ֵ��0�������*/
/*************************************************************************�ݾಹ������*********************************************************/


/*************************************************************************�岹�˶�����*********************************************************/
    public struct struct_crd_config_parms
    {
        public UInt16 dimension;//����ϵά����EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7]��EIC00ȡֵ��Χ:[0,11];
        public UInt16 intermode;//�����岹ģʽ��0����ͨ�����岹��1��ǰհģʽ�����岹;2������
    };//����ϵ���ò���
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdConfigCrd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdConfigCrd(UInt16 cardid,UInt16 crd,struct_crd_config_parms crdparms,UInt16[] Axismaparray);
    /*ָ��ܣ���������ϵ
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			    crdparms	����ϵ���ò���
			    *Axismaparray	����ϵ����б������ɲ���crdparms�е�����ϵά��������
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetCrd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdGetCrd(UInt16 cardid,UInt16 crd,ref struct_crd_config_parms crdparms,UInt16[] Axismaparray);
    /*ָ��ܣ���ȡ����ϵ���ò���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    ���������	*crdparms	����ϵ���ò���
			    *Axismaparray	����ϵ����б������ɲ���crdparms�е�����ϵά��������
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdResetCrd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdResetCrd(UInt16 cardid,UInt16 crd);
    /*ָ��ܣ�ע������ϵ
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdClearCrdBuf", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdClearCrdBuf(UInt16 cardid, UInt16 crd);
    /*ָ��ܣ��������ϵ������
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveStart", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveStart(UInt16 cardid,UInt16 crd);
    /*ָ��ܣ���������ϵ�˶�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMovePause", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMovePause(UInt16 cardid,UInt16 crd);
    /*ָ��ܣ���ͣ����ϵ�˶�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveStop(UInt16 cardid,UInt16 crd,UInt16 stop_mode);
    /*ָ��ܣ�ֹͣ����ϵ�˶�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    �����������
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetOpenSwitchAdvanceTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdSetOpenSwitchAdvanceTime(UInt16 cardid, UInt16 crd, double time);
    /*ָ��ܣ�������ǰ����ʱ�䣬�˺��������ڽ�������ϵǰ���� 
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			    time ��ǰ����/�ؽ�ʱ�� ��λ��ms
    �����������
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetOpenSwitchAdvanceTime", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdGetOpenSwitchAdvanceTime(UInt16 cardid, UInt16 crd, ref double time);
    /*ָ��ܣ��ض���ǰ����ʱ�䣬�˺��������ڽ�������ϵǰ���� 
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
    ���������time ��ǰ����/�ؽ�ʱ�� ��λ��ms
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdSetStopAcc(UInt16 cardid, UInt16 crd, double Acc);
    /*ָ��ܣ���������ϵ����ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
        ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
                Acc  	����ֹͣ���ٶ�
        �����������
        ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetStopAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdGetStopAcc(UInt16 cardid, UInt16 crd, ref double Acc);
    /*ָ��ܣ��ض�����ϵ����ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
        ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                    crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
        ���������*Acc  	����ֹͣ���ٶ�
        ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdSetUseStopAccFlag(UInt16 cardid, UInt16 crd, UInt16 use_stop_acc_flag);
    /*ָ��ܣ���������ϵ����ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
        ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
                use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
        �����������
        ���أ�      0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetUseStopAccFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdGetUseStopAccFlag(UInt16 cardid, UInt16 crd, ref UInt16 use_stop_acc_flag);
    /*ָ��ܣ��ض�����ϵ����ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
        ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
        ������� *use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
        ���أ�      0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetSpace", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetSpace(UInt16 cardid,UInt16 crd,ref Int32 crdspace);
    /*ָ��ܣ���ѯ�岹������ʣ��ռ�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    ���������*crdspace	������ʣ��ռ�
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetRunningSegment", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetRunningSegment(UInt16 cardid,UInt16 crd,ref Int32 CurSegment);
    /*ָ��ܣ���ѯ��ǰ���жκ�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    ���������*CurSegment	�����˶��Ķκ�
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetRemainVectorLengthRatio", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetRemainVectorLengthRatio(UInt16 cardid, UInt16 crd, ref double ratio);
    /*ָ��ܣ���ȡʣ��岹ʸ�����Ȱٷֱ�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
    ���������  *ratio ʣ��岹ʸ�����Ȱٷֱ�
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufChangeSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufChangeSpeed(UInt16 cardid,UInt16 crd,double ratio);
    /*ָ��ܣ����߸ı��ٶ�
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
                ratio	���ʣ�ȡֵ��Χ:[0,10]��
    ��������� ��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetSmoothFactor(UInt16 cardid,UInt16 crd,double smooth_factor);
    /*ָ��ܣ�����S�α�������
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			    smooth_factor	S�α�������,��Χ��[0,1]
    ��������� ��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetSmoothFactor", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetSmoothFactor(UInt16 cardid,UInt16 crd,ref double smooth_factor);
    /*ָ��ܣ���ȡS�α�������
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
    ��������� *smooth_factor	S�α�������,��Χ��[0,1]
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetVelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetVelParms(UInt16 cardid,UInt16 crd,struct_vel_plan_parms bufvelparms);
    /*ָ��ܣ���������ϵ�ٶȲ���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			    bufvelparms	�ٶȹ滮����
    typedef struct
    {
       double start_vel;     //��ʼ�ٶȣ���λ����ppu/s��
       double max_vel;       //����ٶȣ���λ����ppu/s��
       double end_vel;       //ֹͣ�ٶȣ���λ����ppu/s��
       double acc;           //���ٶ�,��λ��[ppu/s2]
       double dec;           //���ٶ�,��λ��[ppu/s2]
    }struct_vel_plan_parms; 
    ��������� ��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetVelParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetVelParms(UInt16 cardid,UInt16 crd,ref struct_vel_plan_parms bufvelparms);
    /*ָ��ܣ���ȡ����ϵ�ٶȲ���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
    ��������� *bufvelparms	�ٶȹ滮����
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetTrajectoryError", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetTrajectoryError(UInt16 cardid,UInt16 crd,double TrajectoryError);
    /*ָ��ܣ���������Ĺ켣������ǰհģʽ����Ч��
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			    TrajectoryError	����Ĺ켣���ֵ����λ��PPU��
    ��������� ��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetTrajectoryError", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetTrajectoryError(UInt16 cardid,UInt16 crd,ref double TrajectoryError);
    /*ָ��ܣ���ѯ����Ĺ켣������ǰհģʽ����Ч��
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��			
    ��������� *TrajectoryError	����Ĺ켣���ֵ����λ��PPU��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetMaxTransitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetMaxTransitAcc(UInt16 cardid,UInt16 crd,double MaxTransitAcc);
    /*ָ��ܣ�������������Ӽ��ٶȣ�����ǰհģʽ����Ч��
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			    MaxTransitAcc	����������ٶȣ���λ��[ppu/s2]��
    ��������� ��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetMaxTransitAcc", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufGetMaxTransitAcc(UInt16 cardid,UInt16 crd,ref double MaxTransitAcc);
    /*ָ��ܣ���ѯ��������Ӽ��ٶȣ�����ǰհģʽ����Ч��
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
    ��������� *MaxTransitAcc	����������ٶȣ���λ��[ppu/s2]��
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerRel(UInt16 cardid,UInt16 crd,UInt16 axis_num,double[] targetpos_array,UInt32 segnum);
    /*ָ��ܣ�ֱ�߲岹������˶���
      ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                  crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
                 axis_num	����ֱ�߲岹����
                 *targetpos_array	����ֱ�߲岹��������λ�ƣ���λ��PPU��
                 segnum	�κ�
      �����������
      ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerAbs(UInt16 cardid,UInt16 crd,UInt16 axis_num,double[] targetpos_array,UInt32 segnum);
    /*ָ��ܣ�ֱ�߲岹�������˶���
      ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                  crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                  axis_num ����
                  targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
                  segnum �κ�
      �����������
      ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerRelMulti_XYZ", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerRelMulti_XYZ(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] targetpos_array_z, double[] max_vel, double[] acc);
    /*ָ��ܣ�3��ֱ�߲岹��һ����Ӷ���岹�㣬����˶���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
                line_num	һ������ӵ�ֱ��������� ȡֵ��Χ[1,16]
               *targetpos_array_x	����ֱ�߲岹X������λ�ƣ���λ��PPU��
		       *targetpos_array_y	����ֱ�߲岹X������λ�ƣ���λ��PPU��
		       *targetpos_array_z	����ֱ�߲岹X������λ�ƣ���λ��PPU��
		       * max_vel            ����ٶ�
		       * acc                �����ٶ�
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerAbsMulti_XYZ", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerAbsMulti_XYZ(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] targetpos_array_z, double[] max_vel, double[] acc);
    /*ָ��ܣ�3��ֱ�߲岹��һ����Ӷ���岹�㣬�����˶���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
                line_num	һ������ӵ�ֱ��������� ȡֵ��Χ[1,16]
               *targetpos_array_x	����ֱ�߲岹X��ľ���λ�ƣ���λ��PPU��
		       *targetpos_array_y	����ֱ�߲岹X��ľ���λ�ƣ���λ��PPU��
		       *targetpos_array_z	����ֱ�߲岹X��ľ���λ�ƣ���λ��PPU��
		       * max_vel            ����ٶ�
		       * acc                �����ٶ�
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerRelMulti_XY", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerRelMulti_XY(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] max_vel, double[] acc);
    /*ָ��ܣ�2��ֱ�߲岹��һ����Ӷ���岹�㣬����˶���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
                line_num	һ������ӵ�ֱ��������� ȡֵ��Χ[1,16]
               *targetpos_array_x	����ֱ�߲岹X������λ�ƣ���λ��PPU��
		       *targetpos_array_y	����ֱ�߲岹X������λ�ƣ���λ��PPU��
		       * max_vel            ����ٶ�
		       * acc                �����ٶ�
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveLinerAbsMulti_XY", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveLinerAbsMulti_XY(UInt16 cardid, UInt16 crd, UInt16 line_num, double[] targetpos_array_x, double[] targetpos_array_y, double[] max_vel, double[] acc);
    /*ָ��ܣ�2��ֱ�߲岹��һ����Ӷ���岹�㣬�����˶���
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
                line_num	һ������ӵ�ֱ��������� ȡֵ��Χ[1,16]
               *targetpos_array_x	����ֱ�߲岹X��ľ���λ�ƣ���λ��PPU��
		       *targetpos_array_y	����ֱ�߲岹X��ľ���λ�ƣ���λ��PPU��
		       * max_vel            ����ٶ�
		       * acc                �����ٶ�
    �����������
    ����ֵ��0�������*/
    public struct  struct_center_cir_parms
    {
        public UInt16 axis_num;//�岹����
        public UInt16 direction;//Բ������0��˳ʱ�룻1����ʱ�룻
        public UInt16 cirnum;//Բ��Ȧ��
        public UInt16 plane;//Բ�����ĸ�ƽ�棻0��XYƽ�棻1��YZƽ�� 2��XZƽ��
        public UInt16 mode;//λ��ģʽ��0�����λ��ģʽ��1������λ��ģʽ
    };//Բ���յ㷽ʽԲ������
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveCenterCircular", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveCenterCircular(UInt16 cardid,UInt16 crd,struct_center_cir_parms cencirparms,double[] targetpos_array,double[] cenpos_array,UInt32 segnum);
    /*ָ��ܣ�Բ���յ�ģʽԲ���岹 
      ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                  crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                  cencirparms Բ���յ㷽ʽԲ������
                  cenpos_arrayԲ�������б�
                  targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
                  segnum �κ�
      �����������
      ����ֵ��0�������*/

    public struct struct_radius_cir_parms
    {
        public double radius;//Բ���뾶����λ����ppu��
        public UInt16 axis_num;//�岹����
        public UInt16 direction;//Բ������0��˳ʱ�룻1����ʱ�룻
        public UInt16 cirnum;//Բ��Ȧ��
        public UInt16 plane;//Բ�����ĸ�ƽ�棻0��XYƽ�棻1��YZƽ�� 2��XZƽ��
        public UInt16 mode;//λ��ģʽ��0�����λ��ģʽ��1������λ��ģʽ
    };//�յ�뾶Բ������
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMoveRadiusCircular", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMoveRadiusCircular(UInt16 cardid,UInt16 crd,struct_radius_cir_parms radcirparms,double[] targetpos_array,UInt32 segnum);
    /*ָ��ܣ��յ�뾶ģʽԲ���岹 
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                radcirparms �յ�뾶Բ������
                targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
                segnum �κ�
    �����������
    ����ֵ��0�������*/

    public struct struct_3point_cir_parms
    {
        public UInt16 axis_num;//�岹����
        public  UInt16 direction;//Բ������0��˳ʱ�룻1����ʱ�� �˲�����Ч
        public UInt16 cirnum;//Բ��Ȧ��
        public UInt16 plane;//Բ�����ĸ�ƽ�棻0��XYƽ�棻1��YZƽ�� 2��XZƽ�� 3:�ռ�Բ��
        public UInt16 mode;//λ��ģʽ��0�����λ��ģʽ��1������λ��ģʽ
    };//3��Բ������
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufMove3PointCircular", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufMove3PointCircular(UInt16 cardid,UInt16 crd,struct_3point_cir_parms pointscirparms,double[] targetpos_array,double[] midpos_array,UInt32 segnum);
    /*ָ��ܣ�����ģʽԲ���岹 
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                radcirparms pointscirparms
			    midpos_array �м��λ���б�
                targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
                segnum �κ�
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufDelay", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufDelay(UInt16 cardid, UInt16 crd, double time, UInt32 segnum);//�岹��ʱ,��λ��[ms]
    /*ָ��ܣ�������ʱ
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                time	��ʱʱ�䣨��λ��ms��
                segnum �κ�
    �����������
    ����ֵ��0�������*/
    public struct struct_buf_check_input_parms
    {
        public UInt16 input_num;//����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
        public UInt16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public double check_time;//checkʱ��,��λ��[ms]
    };//������ͨ�����IO����
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCheckInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufCheckInput(UInt16 cardid,UInt16 crd,struct_buf_check_input_parms inputparms,UInt32 segnum);
    /*ָ��ܣ��ȴ�����IO
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                inputparms    ����IO����
                segnum �κ�
    �����������
    ����ֵ��0�������*/
    
    public struct struct_buf_check_output_parms
    {
      public UInt16 output_num;//���io�ţ�EI800\EIC00 0-15 EI400S 0-31
      public UInt16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
      public double check_time;//checkʱ��,��λ��[ms]
    };//������ͨ�����IO����
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCheckOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufCheckOutput(UInt16 cardid, UInt16 crd, struct_buf_check_output_parms outputparms, UInt32 segnum);
    /*ָ��ܣ��������ȴ����IO
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                outputparms    ���IO����
                segnum �κ�
    �����������
    ����ֵ��0�������*/


    public struct struct_buf_out_io_parms
    {
        public UInt16 io_mode;//���������ioģʽ��//0���趨io��������趨��ƽ��1���趨io�ͺ��趨��������趨��ƽ��2���趨io�ͺ��趨ʱ������趨��ƽ 3:���趨io��ǰ�趨��������趨��ƽ
        public UInt16 output_num;//���io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
        public UInt16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
        public double actionparm;//ʱ�䣨��λ��S����������(��λ��ppu)
        public double holdtime;//�趨��ƽ����ʱ��,��λ��[ms]
    };//������ͨ�����IO����
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSetOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufSetOutput(UInt16 cardid,UInt16 crd,struct_buf_out_io_parms outputparms,UInt32 segnum);
    /*ָ��ܣ����������IO
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                outputparms    ���IO����
                segnum �κ�
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufBlank", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufBlank(UInt16 cardid, UInt16 crd, UInt16 segnum);
    /*ָ��ܣ����������IO
    ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                outputparms    ���IO����
                segnum �κ�
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufClearIoAction", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufClearIoAction(UInt16 cardid,UInt16 crd,UInt32 io_mask,UInt32 segnum);
    /*ָ��ܣ����IO���� 
      ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                  crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
                  io_mask ��Ҫ��������IO�ţ���0-15BIT��Ӧ0-15�����IO 1����ʾ��� 0����ʾ������
                  segnum �κ�
      �����������
      ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufOpenSwitchAdvance", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufOpenSwitchAdvance(UInt16 cardid, UInt16 crd, double[] pos, UInt16 active_level);
    /*
    ָ��ܣ��������ۿ���/�ؽ�λ��
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		       pos      ���۱Ƚ�λ��(X�������Y������ֵ)
		       active_level  �Ƚ������Ч��ƽ
    �����������
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufOpenSwitchAdvanceMulti", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufOpenSwitchAdvanceMulti(UInt16 cardid, UInt16 crd, UInt32 pos_num, double[] pos_x, double[] pos_y, UInt16 active_level);
    /*
    ָ��ܣ��������ۿ���/�ؽ�λ��
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		       pos_num  ��ӱȽϵ����
		       pos_x    ���۱Ƚ�X��λ��
		       pos_y    ���۱Ƚ�Y��λ��
		       active_level  �Ƚ������Ч��ƽ
    �����������
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSwitchRemainSpace", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufSwitchRemainSpace(UInt16 cardid, UInt16 crd, ref UInt32 space);
    /*
    ָ��ܣ���ȡ����/�ؽ�λ��ʣ�໺��������
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
    ���������space ʣ�໺����
    ����ֵ��0�������*/
     [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufSwitchClear", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufSwitchClear(UInt16 cardid, UInt16 crd);
    /*
    ָ��ܣ���ȡ����/�ؽ�λ��ʣ�໺��������
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
    ���������space ʣ�໺����
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCompareSetStartLength", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
     public static extern short Plt_CrdBufCompareSetStartLength(UInt16 cardid, UInt16 crd, double offset_length, UInt16 active_level);
    /*ָ��ܣ����þ��Ծ���ģʽ����/�ؽ���ʼλ��
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��
		       offset_length ��ǰλ�õ�ƫ�ƹ켣���ȣ�ȡֵ���ڵ�����
		       active_level  ��ʼλ�������ƽ
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufCompareAddLengthMulti", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufCompareAddLengthMulti(UInt16 cardid, UInt16 crd, UInt32 pos_num, double[] length, UInt16 active_level);
    /*
    ָ��ܣ�ͬʱ��Ӷ�����Ծ���ģʽ����/�ؽ�λ��
    ��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		       pos_num  ��ӱȽϵ����,һ�����������42���Ƚϵ� ȡֵ��Χ[1,42]
		       length   ��Կ�ʼ��� ���Ծ��룬ȡֵ���ڵ�����
		       active_level  �Ƚ������Ч��ƽ
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufDistanceOutPut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufDistanceOutPut(UInt16 cardid,UInt16 crd,struct_crd_accurate_compare_parms compare_parms_2d,double start_length_ratio,double end_length_ratio,UInt32 output_num,UInt32 segnum);
    /*
    ָ��ܣ��������Ⱦ����ά�Ƚ������������¶ι켣��Ҫ���¶ι켣������ֱ�߶λ���Բ���Σ��������ִ���
    ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
               crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
              typedef struct
              {
                  uint16 axis_array[2];//�Ƚ����б� 0��X��  1��Y��  EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];
                  uint16 enable;//�Ƚ�ʹ�ܿ��أ�0;�ȽϽ�ֹ��1���Ƚ�����
                  uint16 cmpmethod;//�ȽϷ�����0��������ȽϷ���1���뿪����ȽϷ�
                  uint16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
                  uint16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
                  double pulsewidth;//�����ȣ���λ����ms��
                  double cmp_error;//���ȣ���λ[pulse]
                }struct_crd_accurate_compare_parms;//��ȷλ�ñȽ�
                start_length_ratio ��ʼ��λ��ռ�켣�ܳ��ȵı���
                end_length_ratio �������λ��ռ�켣�ܳ��ȵı���
                output_num���Ⱦ�����������Ŀ��������ʼ��ͽ����㣩
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufDistanceOutPutConti", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufDistanceOutPutConti(UInt16 cardid,UInt16 crd,struct_crd_accurate_compare_parms compare_parms_2d,UInt16 enable_flag,double distance,UInt32 segnum);
    /*
    ָ��ܣ������Ⱦ����ά�Ƚ������������ָ�ʹ�ܴ�ָ��󣬿��ƿ��Զ��ڴ�ָ����ֱ�߲岹�κ�Բ���岹��ǰ��Ӹ��ٶ�ά�Ƚϻ�����ָ�
    ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
              typedef struct
              {
                  uint16 axis_array[2];//�Ƚ����б� 0��X��  1��Y�� EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];
                  uint16 enable;//�Ƚ�ʹ�ܿ��أ�0;�ȽϽ�ֹ��1���Ƚ�����
                  uint16 cmpmethod;//�ȽϷ�����0��������ȽϷ���1���뿪����ȽϷ�
                  uint16 cmp_source_array[2];//�Ƚ�Դ 0������λ�� 1��������λ��
                  uint16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
                  double pulsewidth;//�����ȣ���λ����ms��
                  double cmp_error;//���ȣ���λ[pulse]
                }struct_crd_accurate_compare_parms;//��ȷλ�ñȽ�
                enable_flag �����Ⱦ����ά�Ƚ����ʹ�ܱ�־
                distance �Ⱦ�ȽϾ���ֵ�����嵱����λ��
    �����������
    ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufAxMoveRel", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufAxMoveRel(UInt16 cardid,UInt16 crd,UInt16 axis,double dist,UInt16 mode,UInt32 segnum);
    /*
   ָ��ܣ�����������ϵ������趨�����ģʽ�˶�
   ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
             crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
             axis ��
             mode��0�� ���������趨���˶���ɺ���ܼ����������岹�˶�:1�����������������趨���˶�������������岹�˶�
   �����������
   ����ֵ��0�������*/
    [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufAxMoveAbs", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
    public static extern short Plt_CrdBufAxMoveAbs(UInt16 cardid,UInt16 crd,UInt16 axis,double dist,UInt16 mode,UInt32 segnum);
    /*
    ָ��ܣ�����������ϵ������趨�����ģʽ�˶�
    ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
              axis ��
              mode��0�� ���������趨���˶���ɺ���ܼ����������岹�˶�:1�����������������趨���˶�������������岹�˶�
    �����������
    ����ֵ��0�������*/
    /*************************************************************************�岹�˶�����*********************************************************/

        /*************************************************************************״̬���*********************************************************/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetMotionStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxGetMotionStatus(UInt16 cardid, UInt16 axis, ref UInt16 motionstatus);	//��ȡָ������˶�״̬
         /*ָ��ܣ���ȡָ������˶�״̬
        ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                  axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                              EI800ȡֵ��Χ:[0,7];
                              EIC00ȡֵ��Χ:[0,11];
        ���������*motionstatus	���˶�״̬��0���˶��У�1��ֹͣ��
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxGetStatus(UInt16 cardid, UInt16 axis, ref UInt16 mode, ref UInt16 stopreason);//1����λ 2:JOG 3������ 4������ 5�������岹
         /*ָ��ܣ���ȡ���˶�ģʽ��ֹͣԭ��
         ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                   axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                               EI800ȡֵ��Χ:[0,7];
                               EIC00ȡֵ��Χ:[0,11];
         ���������*status	���˶�ģʽ��0�����У�1����λ�˶���2��JOG�˶���3�������˶���4�������˶���5�������岹�˶���
                   *stopreason ֹͣԭ��
         ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxGetMotionSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxGetMotionSpeed(UInt16 cardid, UInt16 axis, ref double motionspeed);//��ȡ�����ٶ�
         /*ָ��ܣ���ȡָ������˶��ٶ�
         ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                   axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                               EI800ȡֵ��Χ:[0,7];
                               EIC00ȡֵ��Χ:[0,11];
         ���������*motionspeed	�ٶ�ֵ����λ:PPU/s
         ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetMotionSpeed", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdGetMotionSpeed(UInt16 cardid, UInt16 crd, ref double motionspeed);//��ȡ����ϵ���ٶ�
         /*ָ��ܣ���ȡָ������˶��ٶ�
         ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                   crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
         ���������*motionspeed	����ϵ���ٶ�ֵ����λ:PPU/s
         ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_AxClearStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_AxClearStatus(UInt16 cardid, UInt16 axis);//���ֹͣԭ��
         /*ָ��ܣ����ֹͣԭ��
         ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                   axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                               EI800ȡֵ��Χ:[0,7];
                               EIC00ȡֵ��Χ:[0,11];
         �����������
         ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdBufGetStatus", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdBufGetStatus(UInt16 cardid, UInt16 crd, ref UInt16 crdstatus);// 4:�ͷ� 3��������0���˶���1����ͣ 2��ֹͣ��5���쳣
         /*ָ��ܣ���ȡ�岹�˶�������ϵ״̬
         ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                   crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
         ���������*crdstatus	����ϵ״̬��4:�ͷ� 3��������0���˶���1����ͣ 2��ֹͣ��5���쳣��
         ����ֵ��0�������*/
         //��������ϵ��λ���
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdSetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdSetBand(UInt16 cardid, UInt16 crd, double[] band, UInt32[] hold_time, UInt32[] check_time);
        /*ָ��ܣ������ᵽλ���
        ���������  cardid ����
                    crd �岹ϵ��
                    *band ������С���� ��ÿ����������� ��λ�� ppu 
			        *hold_time ���巢����Ϻ���������ͱ���������ƫ�����ֵ������������ʱ��  ÿ������ı���ʱ�����飬��λ��ms
                    check_time  ���巢����Ϻ���������ͱ���������ƫ�����ֵ�����������ʱ�� ÿ������ļ��ʱ�����飬��λ��ms
        �����������
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetBand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdGetBand(UInt16 cardid, UInt16 crd, double[] band, UInt32[] hold_time, UInt32[] check_time);
         /*ָ��ܣ���ѯ����ϵ��λ�������
        ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                    crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
        ���������  *band ������С���� ��ÿ����������� ��λ�� ppu 
			        *hold_time ���巢����Ϻ���������ͱ���������ƫ�����ֵ������������ʱ��  ÿ������ı���ʱ�����飬��λ��ms
                    check_time  ���巢����Ϻ���������ͱ���������ƫ�����ֵ�����������ʱ�� ÿ������ļ��ʱ�����飬��λ��ms
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_CrdGetBandFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_CrdGetBandFlag(UInt16 cardid, UInt16 crd, ref UInt16 band_flag);
         /*ָ��ܣ���ȡ�������
         ���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
                     crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
         ���������band_flag 1������ϵ������������λ�úͱ�����λ��ƫ�����ֵ�����趨������Χ�ڴ��ڵ����趨�ı���ʱ��
                             0������ϵ�������˶��л��������巢���Ѿ���ϵ�������λ�úͱ�����λ��ƫ�����ֵ�����趨������Χ��С���趨�ı���ʱ��
                             2������ϵ��������һ�������巢���Ѿ���ϵ����������ʱ�䵽ʱ������λ�úͱ�����λ��ƫ�����ֵ�����趨������Χ��С���趨�ı���ʱ��
         ����ֵ��0�������*/
        /*************************************************************************����IO����������غ���*********************************************************/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoConfigInputCountMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoConfigInputCountMode(UInt16 cardid, UInt16 bitno, UInt16 count_mode, double filter_time);
        /*ָ��ܣ���������IO����ģʽ
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                    bitno ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			        count_mode ����ģʽ  0����ֹ����IO����  1�������ؼ��� 2���½��ؼ���
			        filter_time ����IO�˲�ʱ�� ��λ��ms 
          �����������
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoReadInputCountMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoReadInputCountMode(UInt16 cardid, UInt16 bitno, ref UInt16 count_mode, ref double filter_time);
        /*ָ��ܣ���ȡIO����ģʽ����
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                    bitno ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
        			
          ���������*count_mode ����ģʽ  0����ֹ����IO����  1�������ؼ��� 2���½��ؼ���
			        *filter_time ����IO�˲�ʱ�� ��λ��ms 
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoSetInputCountValue", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetInputCountValue(UInt16 cardid, UInt16 bitno, UInt32 init_value);
        /*ָ��ܣ���������IO������ʼֵ
           ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                     bitno ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
                     init_value ����io������ʼֵ
           �����������
         ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoGetInputCountValue", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoGetInputCountValue(UInt16 cardid, UInt16 bitno, ref UInt32 count_value);
        /*ָ��ܣ���ȡ����IO����ֵ
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                    bitno   ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
           ���������*count_value  ��ǰ����io����ֵ
        ����ֵ��0�������*/
/*************************************************************************����IO����������غ���*********************************************************/
/*************************************************************************PWM������غ���*********************************************************/
        [DllImport("PLT.dll", EntryPoint = "Plt_PwmSetPwmEnablFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_PwmSetPwmEnablFlag(UInt16 card, UInt16 pwmno, UInt16 pwmflag);
        /*ָ��ܣ���ȡ����IO����ֵ
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                    bitno   ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
           ���������*count_value  ��ǰ����io����ֵ
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_PwmGetPwmEnablFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_PwmGetPwmEnablFlag(UInt16 card, UInt16 pwmno, ref UInt16 pwmflag);
        [DllImport("PLT.dll", EntryPoint = "PLT_SetPwmOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_SetPwmOutMode(UInt16 card, UInt16 pwmno, UInt16 out_mode);
        /*ָ��ܣ�pwm���ģʽ
        ��������� cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                    pwmno  pwmͨ����
			        out_mode pwm���ģʽ  0���Ǹ���ģʽ  1������ģʽ
        ���������  ��
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "PLT_GetPwmOutMode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_GetPwmOutMode(UInt16 card, UInt16 pwmno, ref UInt16 out_mode);
        /*ָ��ܣ���ȡPWM���ģʽ
        ���������  card ����
                     pwmno  pwmͨ����
        ���������  out_mode pwm���ģʽ  0���Ǹ���ģʽ  1������ģʽ
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "PLT_SetPwmOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_SetPwmOut(UInt16 card, UInt16 pwmno, double fDuty, double fFre);
        [DllImport("PLT.dll", EntryPoint = "PLT_GetPwmOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_GetPwmOut(UInt16 card, UInt16 pwmno, ref double fDuty, ref double fFre);
        [DllImport("PLT.dll", EntryPoint = "PLT_CrdBufSetPwmOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_CrdBufSetPwmOut(UInt16 card, UInt16 crd, UInt16 pwmno, double fDuty, double fFre, UInt32 segnum);
        [DllImport("PLT.dll", EntryPoint = "PLT_CrdBufSetPwmFollowParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_CrdBufSetPwmFollowParms(UInt16 card, UInt16 crd, UInt16 pwmno, UInt16 follow_mode, double min_power, double max_power, double ratio, double fix_value);
        /*ָ��ܣ�����pwm�������
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                    pwmno  pwmͨ����
                    follow_mode ����ģʽ  0��ռ�ձ�ģʽ  1��Ƶ��ģʽ
			        min_power   ��С����ֵ  min_power��СֵΪ��
                    max_power   �������ֵ  �� follow_mode=0ʱ��max_power�������ֵΪ1����follow_mode=1ʱ��max_power�������ֵΪ500KHZ
			        ratio       �����������  ʵ�ʸ���PWMֵ x=ratio*vel+minPower
			        fix_value   �̶�ֵ  ��follow_mode=0ʱ �̶�ֵΪƵ��   ��follow_mode=1ʱ �̶�ֵΪռ�ձ�
           �����������
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "PLT_CrdBufGetPwmFollowParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_CrdBufGetPwmFollowParms(UInt16 card, UInt16 crd, UInt16 pwmno, ref UInt16 follow_mode, ref double min_power, ref double max_power, ref double ratio, ref double fix_value);
        /*ָ��ܣ���ȡpwm�������
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                    pwmno  pwmͨ����
                    
           ���������follow_mode ����ģʽ  0��ռ�ձ�ģʽ  1��Ƶ��ģʽ
			        min_power   ��С����ֵ  min_power��СֵΪ��
                    max_power   �������ֵ  �� follow_mode=0ʱ��max_power�������ֵΪ1����follow_mode=1ʱ��max_power�������ֵΪ500KHZ
			        ratio       �����������  ʵ�ʸ���PWMֵ x=ratio*vel+minPower
			        fix_value   �̶�ֵ  ��follow_mode=0ʱ �̶�ֵΪƵ��   ��follow_mode=1ʱ �̶�ֵΪռ�ձ�
        ����ֵ��0�������*/
/*************************************************************************PWM������غ���*********************************************************/
/*************************************************************************״̬���*********************************************************/
/*************************************************************************AD����*********************************************************/
         [DllImport("PLT.dll", EntryPoint = "PLT_AdGetVol", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short PLT_AdGetVol(UInt16 card, UInt16 channal_id, ref float vol);
    /*ָ��ܣ����������ƽ
      ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                channal_id  ͨ����:��ЧֵΪ0��1   
                
      ��������� vol �����ѹֵ ��Χ[0,9.9]
    ����ֵ��0�������*/
    /*************************************************************************AD����*********************************************************/
        /*************************************************************************DA����*********************************************************/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaSetEnableFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaSetEnableFlag(UInt16 card, UInt16 channal_id, UInt16 enable_flag);
        /*ָ��ܣ�����DA���ʹ�ܱ�־
           ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                     channal_id  ͨ����:��ЧֵΪ0��1 
                     enable_flag 1��ʹ�� 0����ֹ
           ��������� ��
         ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaGetEnableFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaGetEnableFlag(UInt16 card, UInt16 channal_id, ref UInt16 enable_flag);
        /*ָ��ܣ�����DA���ʹ�ܱ�־
          ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                    channal_id  ͨ����:��ЧֵΪ0��1   
            
          ���������enable_flag 1��ʹ�� 0����ֹ
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaSetVol", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaSetVol(UInt16 card, UInt16 channal_id, float vol);
        /*ָ��ܣ����������ƽ
           ���������cardid	���ţ�ȡֵ��Χ:[0,11]��  
                     channal_id  ͨ����:��ЧֵΪ0��1 
                     vol �����ѹֵ ��Χ[0,9.9]
           ��������� ��
         ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "PLT_DaGetVol", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short PLT_DaGetVol(UInt16 card, UInt16 channal_id, ref float vol);
        /*ָ��ܣ����������ѹ
           ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
                     channal_id  ͨ����:��ЧֵΪ0��1   
            
           ��������� vol �����ѹֵ ��Χ[0,9.9]
         ����ֵ��0�������*/
        /*************************************************************************DA����*********************************************************/
        /*************************************************************************CAN�������IO**********************************************************/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoSetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoSetMasterBaudrate(UInt16 cardid, UInt16 baudrate);
         /*ָ��ܣ�����EIX00���ƿ�CANͨѶ������
          //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
          //            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
          //  �����������
          ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoGetMasterBaudrate", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoGetMasterBaudrate(UInt16 cardid, ref UInt16 baudrate);
         /*ָ��ܣ���ȡEIX00���ƿ�CANͨѶ������
         //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��  
         //           
         //  ��������� baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
         ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadInputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level); 	//��ȡָ��canģ������ڵ�״̬
        /*ָ��ܣ���ȡָ��canģ��ĳ������ڵ�ƽ
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
                      bitno	����IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
        //  ���������  *active_level 
        ����ֵ��0�������*/

        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, UInt16 active_level); 	//����ָ��canģ������ڵ�״̬
        /*ָ��ܣ�����ָ��canģ��ĳ������ڵ�ƽ
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
                      bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
        //			active_level �����ƽֵ  0��1
        //  �����������
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadOutputByBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, ref UInt16 active_level);  	//��ȡָ��canģ������ڵ�״̬
        /*ָ��ܣ���ȡָ��canģ��ĳ������ڵ�ƽ
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
                      bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
        //  ���������  *active_level
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadAllInput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllInput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level_1); 	//��ȡָ��canģ������ͨ������IO��ֵ
        /*ָ��ܣ���ȡָ��canģ������ͨ������IO��ֵ
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
        //            active_level	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31 RCAN32I32O: bit0-bit31λ����Ч��RCAN16I16O: bit0-bit15λ��Ч��
        //  ���������  *active_level  active_level˳���0��31����0��31����IO��ƽ
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReadAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanReadAllOutput(UInt16 cardid, UInt16 can_id, ref UInt32 active_level); 	//��ȡָ��canģ������ͨ������ڵ�ֵ
        /*ָ��ܣ���ȡָ��canģ������ͨ�����IO��ֵ
        //  �������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
        //            bitno IO�ں� ��ЧֵΪ[0,31]
        //			  active_level	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31 RCAN32I32O: bit0-bit31λ����Ч��RCAN16I16O: bit0-bit15λ��Ч��
        //  �����������
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanWriteAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanWriteAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);  	//����ָ��canģ������ͨ������ڵ�ֵ
        /*ָ��ܣ�����ָ��canģ����������ڵ�ƽ
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
        //           active_level	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31 RCAN32I32O: bit0-bit31λ����Ч��RCAN16I16O: bit0-bit15λ��Ч��
        //  �����������
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanGetLinkState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanGetLinkState(UInt16 cardid, UInt16 can_id, ref UInt16 link_state);  	//��ȡָ��canģ������״̬
        /*ָ��ܣ���ȡָ��canģ������״̬
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��           
        //  ���������  *link_state ����״̬ 1������  0���Ͽ�
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoCanInitAllOutput", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_IoCanInitAllOutput(UInt16 cardid, UInt16 can_id, UInt32 active_level);
         /*ָ��ܣ�����ָ��canģ������ڳ�ʼ��ƽ
         //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                       can_id	canģ�����, ȡֵ��Χ:[0,7]��
         //			active_level  active_level˳���0��31����0��31���IO��ʼ��ƽ
         //  �����������
         ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoCanInitAllOutput_extern", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanInitAllOutput_extern(UInt16 cardid, UInt16 can_id, UInt32 active_level);
        /*ָ��ܣ�����ָ��canģ�������32-63��ʼ��ƽ
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
        //			active_level  active_level˳���0��31����32��63���IO��ʼ��ƽ
        //  �����������
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_IoCanGetNodeType", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanGetNodeType(UInt16 cardid, UInt16 can_id, ref UInt16 type);
        /*ָ��ܣ���ȡָ��canģ��ڵ�����
          //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                        can_id	canģ�����, ȡֵ��Χ:[0,7]��
          //  ���������type canģ��ڵ�����  1��rcan1616 2:rcan3232
          ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanGetNodeVersion", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanGetNodeVersion(UInt16 cardid, UInt16 can_id, ref UInt16 version);  	
        /*ָ��ܣ���ȡָ��canģ��ڵ�����
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
        //  ���������version canģ��ڵ�̼��汾��  
        ����ֵ��0�������*/
        [DllImport("PLT.dll", EntryPoint = "Plt_IoCanReverseOutputBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_IoCanReverseOutputBit(UInt16 cardid, UInt16 can_id, UInt16 bitno, double hold_time);
        /*ָ��ܣ�CANIO��ת
        //  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
                      can_id	canģ�����, ȡֵ��Χ:[0,7]��
			          bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
			          hold_time ���Ի���Ч
        //  �����������
        ����ֵ��0�������*/
        /*************************************************************************CAN�������IO**********************************************************/

        /*************************************************************************����ͬ������**********************************************************/
        [DllImport("PLT.dll", EntryPoint = "Plt_GantrySetEnable", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantrySetEnable(UInt16 cardid, UInt16 master_axis_id, UInt16 slave_axis_id, UInt16 enable_flag);  	
        /*ָ��ܣ���������ʹ�������ͬ����ϵ
        //  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
                      master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                        EI800ȡֵ��Χ:[0,7];
                                        EIC00ȡֵ��Χ:[0,11];	  
			          slave_axis_id	    ������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                        EI800ȡֵ��Χ:[0,7];
                                        EIC00ȡֵ��Χ:[0,11];	
			         enable_flag        ����ʹ����Ƿ�������ͬ����ϵ  1������ 0�����
        //  �����������
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_GantryGetEnable", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern short Plt_GantryGetEnable(UInt16 cardid, UInt16 master_axis_id, ref UInt16 slave_axis_id,ref UInt16 enable_flag);
         /*ָ��ܣ���ѯ����ʹ����Ƿ��������ͬ����ϵ
         //  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
                       master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                         EI800ȡֵ��Χ:[0,7];
                                         EIC00ȡֵ��Χ:[0,11];	  	
         //  ������� *enable_flag       ����ʹ����Ƿ�������ͬ����ϵ  1������ 0�����
                      *slave_axis_id	 ������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                         EI800ȡֵ��Χ:[0,7];
                                         EIC00ȡֵ��Χ:[0,11];	
         ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_GantrySetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantrySetParms(UInt16 cardid, UInt16 master_axis_id, double max_error, double encoder_factor, UInt16 stop_mode);  	
        /*ָ��ܣ���������ͬ���������
        //  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
                      master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                        EI800ȡֵ��Χ:[0,7];
                                        EIC00ȡֵ��Χ:[0,11];	  
			          max_error	        ����ʹ����������������ƫ���λ��[PPU]
			          encoder_factor    ���ͬ�����壬��������������ʹ��������������ֵ
			          stop_mode         ƫ���ֹͣ��ʽ 0������ֹͣ  1������ֹͣ
        //  �����������
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_GantryGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantryGetParms(UInt16 cardid, UInt16 master_axis_id, ref double max_error, ref double encoder_factor, ref UInt16 stop_mode);  	
        /*ָ��ܣ���ȡ����ͬ���������
        //  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
                      master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                        EI800ȡֵ��Χ:[0,7];
                                        EIC00ȡֵ��Χ:[0,11];	  
        //���������  *max_error	    ����ʹ����������������ƫ���λ��[PPU]
			          *encoder_factor   ���ͬ�����壬��������������ʹ��������������ֵ
			          *stop_mode        ƫ���ֹͣ��ʽ 0������ֹͣ  1������ֹͣ
        ����ֵ��0�������*/
         [DllImport("PLT.dll", EntryPoint = "Plt_GantryGetError", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_GantryGetError(UInt16 cardid, UInt16 master_axis_id, ref double cur_error);  	
        /*ָ��ܣ���ȡ����ͬ�����鵱ǰ���������ֵ
        //  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
                      master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                        EI800ȡֵ��Χ:[0,7];
                                        EIC00ȡֵ��Χ:[0,11];	  
        //���������  cur_error	        ����ʹ�������ĵ�ǰ������ƫ���λ��[PPU]
        ����ֵ��0�������*/
/*************************************************************************����ͬ������**********************************************************/
/*************************************************************************�����ģ��**********************************************************/
[DllImport("PLT.dll", EntryPoint = "Plt_SetBlow", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
         public static extern short Plt_SetBlow(UInt16 cardid, UInt16 blow_num, UInt16 blow_flag, UInt32 cur_roll_num);	
/*ָ��ܣ�����/����ָ��
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              blow_num	        ���վվ��   0��CCD1  1��CCD2 2:�հ����ccd
              blow_flag         �� blow_num=0�� 0��OK  1:NG 2:NC �� blow_num=1��0��OK 1������  2��ȱ����  3��Mark��
			  cur_roll_num      ��ǰ����
//���������  ��
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_get_roller_finish_flag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_get_roller_finish_flag(UInt16 cardid, UInt16 blow_num, ref UInt16 flag);
/*������������ȡ��λ��CCD���ռ��������־
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              blow_num	        ���վվ��   0��CCD1  1��CCD2 2:�հ����ccd
//���������  flag              0����Ҫ���  1����Ҫ���
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_clear_roller_finish_flag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_clear_roller_finish_flag(UInt16 cardid, UInt16 blow_num);
/*����������֪ͨ��λ����λ��CCD���ռ��������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              blow_num	        ���վվ��   0��CCD1  1��CCD2 2:�հ����ccd
//���������  ��
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_SetCommand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short  Plt_SetCommand(UInt16 cardid,UInt32 command_id);
/*����������ͨ����̫���·���������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              command_id        
//���������  ��
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_GetTesterFinishFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_GetTesterFinishFlag(UInt16 cardid, UInt16 tester_num, ref UInt16 finish_flag);
/*�������������������Ƿ����һ�β���
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]�� 
              tester_num 0:����վ1  1������վ2
//���������  finish_flag   0:�����ǲ���û�����  1���������
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_SampleTest", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_SampleTest(UInt16 cardid, UInt16 tester_num);
/*������������������Ʒ��������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]�� 
    tester_num 0:����վ1  1������վ2
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_SetTestDataFinisReadFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_SetTestDataFinisReadFlag(UInt16 cardid, UInt16 tester_num);
/*������������λ����ɶ�ȡ�����ǽ������,֪ͨ��λ��
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]�� 
    tester_num 0:����վ1  1������վ2
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_AlineCommand", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_AlineCommand(UInt16 cardid, UInt16 command_id);
/*���������������Զ�У׼����
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              command_id  1:У׼��ʼ   0��У׼����      
//���������  ��
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_GetAlineRdyFlag", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_GetAlineRdyFlag(UInt16 cardid, ref UInt16 flag);
/*������������ȡ�豸�Զ�У׼׼��״̬
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��     
//���������  flag 1���Զ�У׼׼����(�����붥��λ) 0���Զ�У׼û��׼����
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_GetSystemState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_GetSystemState(UInt16 cardid, ref UInt16 state);
/*������������ȡ�豸״̬
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��     
//���������  state 1���Զ�״̬  4���ֶ�״̬  3 ����ͣ״̬
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_WriteRegister", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_WriteRegister(UInt16 cardid, UInt32 address, long value);
/*����������д�Ĵ���
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]�� 
             //5049    CCD1����  value = 1����value= 0��
			 //5050    CCD2����  value = 1����value= 0��
			 //3800    1963     ָ��ȱ�ݵ��ﱨ��     
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_ReadRegister", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_ReadRegister(UInt16 cardid, UInt32 address, ref long value);
/*�������������Ĵ���
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
//���������value
            //5049    CCD1����  value = 1����value= 0��
			//5050    CCD2����  value = 1����value= 0��
����ֵ��0�������*/
/*************************************************************************�����ģ��**********************************************************/
/********************************************�������������غ���**************************************************/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorSetStaticCurrent", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorSetStaticCurrent(UInt16 cardid, UInt16 axis, UInt16 current);
/*ָ��ܣ����ò��������̬����
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			current	    ����ֵ
���������	��
���أ�      0�������*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorSetRunningCurrent", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorSetRunningCurrent(UInt16 cardid, UInt16 axis, UInt16 current);
/*ָ��ܣ����ò��������̬����
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			current	    ����ֵ
���������	��
���أ�      0�������*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorSetSubdivion", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorSetSubdivion(UInt16 cardid, UInt16 axis, UInt16 subdivion);
/*ָ��ܣ����ò������ϸ����
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			subdivion   ϸ����
���������	��
���أ�      0�������*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorGetParms", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorGetParms(UInt16 cardid, UInt16 axis, ref UInt16 subdivion, ref UInt16 static_current, ref UInt16 running_current);
/*ָ��ܣ���ȡ����������ò���
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*subdivion  ϸ����
            *static_current  ��̬����
			*running_current ��̬����
���أ�      0�������*/
 [DllImport("PLT.dll", EntryPoint = "PLT_MotorCurCurrent", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short PLT_MotorCurCurrent(UInt16 cardid, UInt16 axis, ref UInt16 current);
/*ָ��ܣ���ȡ���������ǰ����
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*current    ��ǰ����
���أ�      0�������*/
/********************************************�������������غ���**************************************************/ 
/*************************************************************************RS485��غ���*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485SetBound", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485SetBound(UInt16 cardid, UInt32 bound);
/*
��������������RS485������
���������cardid ����
          bound ������  �����õĲ����� 9600 19200 38400 
�����������
����ֵ��������  0�����óɹ�  2400����Ч�Ĳ�����ֵ*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485GetBound", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485GetBound(UInt16 cardid, ref UInt32 bound);
/*
�����������ض�RS485������
���������cardid ����       
���������bound ������
����ֵ��������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485SetDataReceiveTimeOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485SetDataReceiveTimeOut(UInt16 cardid, UInt16 time_out);
/*
��������������RS485��վ�豸�յ����ƿ����͵�ָ��󣬿��ƿ��ȴ���վ���ݻش���ʱʱ��
���������cardid ����
          time_out����ʱʱ�� ȡֵ��Χ [10,1000] ��λ��ms
�����������
����ֵ��������  0�����óɹ�  2401����Ч�ĳ�ʱʱ��ֵ*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485GetDataReceiveTimeOut", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485GetDataReceiveTimeOut(UInt16 cardid, ref UInt16 time_out);
/*
�����������ض�RS485������
���������cardid ����       
���������time_out����ʱʱ�� 
����ֵ��������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_Rs485DataExchange", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Rs485DataExchange(UInt16 cardid, byte[] data_send_buf, UInt16 data_send_len, byte[] data_receive_buf, ref UInt16 data_receive_len);
/*
����������RS485�������ɸ��ֽ����ݣ�����ȡ��վ���ص�����
���������cardid ����  
          data_send_buf ���͵�RS485��վ������
		  data_send_len ���͵�RS485��վ�����ݳ��ȣ�ȡֵ��Χ[1,100]
���������data_receive_buf����վ���ص�����
          data_receive_len ��վ���ص����ݳ���
����ֵ��������*/
/*************************************************************************RS485��غ���*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchSetBufferDatasEnable", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchSetBufferDatasEnable(UInt16 cardid, UInt16 datas_id, UInt16 enable_flag);
/*����������ʹ��/��ֹ�����Զ��ɼ���������ʹ��ʱ��ͬʱ��ѻ������д洢�������������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	
			  enable_flag       1:ʹ�� 0����ֹ
  ���������  ��
����ֵ��0�������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchConfigBufferParams", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchConfigBufferParams(UInt16 cardid, UInt16 datas_id, double start_pos, double end_pos, UInt32 time_period);
/*������������ȡ���ƿ��ײ��Զ��ɼ�������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	
			  start_pos         �ɼ���ʼλ�ã���λ�����嵱����λ ppu
			  end_pos           �ɼ�����λ�ã���λ�����嵱����λ ppu
			  time_period       �ɼ�Ƶ��      ��λ��time_period ms/��
  ���������  ��
����ֵ��0�������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchReadBufferParams", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchReadBufferParams(UInt16 cardid, UInt16 datas_id, ref double start_pos, ref double end_pos, ref UInt32 time_period);
/*������������ȡ���ƿ��ײ��Զ��ɼ�������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	 
  ���������  start_pos         �ɼ���ʼλ�ã���λ�����嵱����λ ppu
			  end_pos           �ɼ�����λ�ã���λ�����嵱����λ ppu
			  time_period       �ɼ�Ƶ��      ��λ��time_period ms/��
����ֵ��0�������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_WatchGetBufferDatas", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_WatchGetBufferDatas(UInt16 cardid, UInt16 datas_id, UInt32 datas_num, ref UInt32 act_datas_num, double[] datas_buffer);
/*������������ȡ���ƿ��ײ��Զ��洢������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	
			  datas_num         ��Ҫ��ȡ�����ݸ���,һ�������Զ�300����
  ���������  act_datas_num     ʵ�ʶ�ȡ�������ݸ���       
              datas_buffer      ��ȡ��������
����ֵ��0�������*/
/*************************************************************************���Ź�������غ���*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_SetHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_SetHostWatchDog(UInt16 cardid, UInt16 enable, UInt16 watchtime, UInt16 do_total_num, UInt16[] do_num, UInt16[] do_logic);
/*
�������������ÿ��Ź�����
���������cardid ����
          enable ���Ź�ʹ�ܱ�־ 1�����Ź�ʹ��  0�����Ź���ֹ  Ĭ���ǽ�ֹ
          watchtime ��ʱ����ʱ�䣬��λ[ms]
          do_total_num ��ʱ����ʱ��Ҫ���õ����IO������
          *do_num     ��ʱ����ʱ��Ҫ���õ����IO�����
          *do_logic    ��ʱ����ʱ��Ҫ���õ��������IO�ڵ�ƽ
�����������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_GetHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_GetHostWatchDog(UInt16 cardid, ref UInt16 enable, ref UInt16 watchtime, ref UInt16 do_total_num, UInt16[] do_num, UInt16[] do_logic);
/*������������ȡ���Ź�����*/
 [DllImport("PLT.dll", EntryPoint = "Plt_FeedHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_FeedHostWatchDog(UInt16 cardid);
/*�����������ڳ�ʱ����ʱ�䷶Χ�ڲ��ϵ��ô˺������Է�ֹ��ʱ����*/
 [DllImport("PLT.dll", EntryPoint = "Plt_InitHostWatchDog", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_InitHostWatchDog(UInt16 cardid);
/*�������������Ź����ܸ�λ����λ�������Ҫ�ٴ��������Ź����ܣ���Ҫ�������ÿ��Ź�����*/
/*************************************************************************���Ź�������غ���*********************************************************/
/*************************************************************************�Զ����д���ݺ����ӿ�*********************************************************/
 [DllImport("PLT.dll", EntryPoint = "Plt_UserSetDatas", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_UserSetDatas(UInt16 cardid, UInt32 datas_id, UInt32 datas_num, char[] datas_buffer);
/*����������д���ݵ���λ��
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��	
              datas_id          ����ID,�û����Բ���idö���Զ���Ĳ���
			  datas_num         ��Ҫд������ݸ���,һ��������д1200����
			  datas_buffer      д����λ������������
  ���������  ��
����ֵ��0�������*/
 [DllImport("PLT.dll", EntryPoint = "Plt_UserGetDatas", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_UserGetDatas(UInt16 cardid, UInt32 datas_id, ref UInt32 datas_num, char[] datas_buffer);
/*��������������λ��������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��	
              datas_id          ����ID,�û����Բ���idö���Զ���Ĳ���	  
  ���������  datas_buffer      ��ȡ������λ������������
              datas_num         ���ض�ȡ�����ݸ�����	
����ֵ��0�������*/
/*************************************************************************�Զ����д���ݺ����ӿ�*********************************************************/
/*************************************************************************���úͶ�ȡ��λ��ϵͳʱ��*********************************************************/
[DllImport("PLT.dll", EntryPoint = "Plt_Set_System_Time", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
 public static extern short Plt_Set_System_Time(UInt16 cardid, UInt16 year, UInt16 month, UInt16 date, UInt16 hour, UInt16 min, UInt16 sec);
/*����������������λ��ϵͳ ʱ��
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��	
              year  �꣬��Χ[0,99]
			  month ��, ��Χ[1,12]
			  date  ��, ��Χ[1,31]
			  hour  Сʱ, ��Χ[0,23]
			  min   ����, ��Χ[0,59]
			  sec   ��, ��Χ[0,59]
  ���������  ��
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_Get_System_Time", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_Get_System_Time(UInt16 cardid, ref UInt16 year, ref UInt16 month, ref UInt16 date, ref UInt16 hour, ref UInt16 min, ref UInt16 sec);
/*����������������λ��ϵͳ ʱ��
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��	
  ���������  year  �꣬��Χ[0,99]
			  month ��, ��Χ[1,12]
			  date  ��, ��Χ[1,31]
			  hour  Сʱ, ��Χ[0,23]
			  min   ����, ��Χ[0,59]
			  sec   ��, ��Χ[0,59]
����ֵ��0�������*/
/*************************************************************************���úͶ�ȡ��λ��ϵͳʱ��*********************************************************/
/******************************************************************ETHERCAT������غ���*********************************************************/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatDownLoadENIFile", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatDownLoadENIFile(UInt16 cardid, char[] filename);
/*ָ��ܣ�����ethercat��վ���������ļ�
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        *filename	�¹̼�����·���� ע�⣺·���в����������ַ�
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatSetNodeOd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatSetNodeOd(UInt16 cardid,UInt16 slave_id,UInt16 Index,UInt16 SubIndex,UInt16 length,UInt32 Value);
/*ָ��ܣ����ô�վ�����ֵ����ֵ(�޷���)
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        slave_id ��վid��
			Index �����ֵ�����
			SubIndex �����ֵ�������
			length �����ֵ���������(��λ�� byte)
			Value �����ֵ���������ֵ
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetNodeOd", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetNodeOd(UInt16 cardid,UInt16 slave_id,UInt16 Index,UInt16 SubIndex,UInt16 length,ref UInt32 Value);
/*ָ��ܣ����ô�վ�����ֵ����ֵ(�޷���)
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        slave_id ��վid��
			Index �����ֵ�����
			SubIndex �����ֵ�������
			length �����ֵ���������(��λ�� byte)
���������	Value �����ֵ���������ֵ
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatSetNodeOd_INT", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatSetNodeOd_INT(UInt16 cardid, UInt16 slave_id, UInt16 Index, UInt16 SubIndex, UInt16 length, Int32 Value);
/*ָ��ܣ����ô�վ�����ֵ����ֵ(�з���)
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        slave_id ��վid��
			Index �����ֵ�����
			SubIndex �����ֵ�������
			length �����ֵ���������(��λ�� byte)
			Value �����ֵ���������ֵ
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetNodeOd_INT", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetNodeOd_INT(UInt16 cardid, UInt16 slave_id, UInt16 Index, UInt16 SubIndex, UInt16 length, ref Int32 Value);
/*ָ��ܣ����ô�վ�����ֵ����ֵ(�з���)
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        slave_id ��վid��
			Index �����ֵ�����
			SubIndex �����ֵ�������
			length �����ֵ���������(��λ�� byte)
���������	Value �����ֵ���������ֵ
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetSlaveCount", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetSlaveCount(UInt16 cardid,ref UInt16 count);
/*ָ��ܣ���ȡethercat����ϵͳ��վ����
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	count ��վ����
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetSlaveAxisCount", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetSlaveAxisCount(UInt16 cardid,ref UInt16 count);
/*ָ��ܣ���ȡethercat����ϵͳ��վ�����
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	count ��վ�����
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatStart", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatStart(UInt16 cardid);
/*ָ��ܣ�����������ethercatģ��
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatStop", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatStop(UInt16 cardid);
/*ָ��ܣ�ֹͣ������ethercatģ��
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetMasterState", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetMasterState(UInt16 cardid, ref UInt16 state);
/*ָ��ܣ���ȡethercat��վ״̬
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
            slave_id ��վid��
���������	state ��վ״̬  0��δ��ʼ�� 1����ʼ��״̬ 2��Ԥ����״̬  3������״̬  4����ȫ����״̬  8������״̬  16������״̬
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetAxis402State", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetAxis402State(UInt16 cardid,UInt16 slave_id,ref UInt16 state);
/*ָ��ܣ���ȡethercat��վ��402״̬
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
            slave_id ��վid��
���������	state ��վ��402״̬  
			NOT READY TO SWITCH ON 0x00
			SWITCHED ON DISABLED   0x40
			READY TO SWITCH ON     0x21
			SWITCHED ON            0x23
			OPERATION ENABLED      0x27
			QUICK STOP ACTIVE      0x07
			FAULT REACTION ACTIVE  0x0F
			FAULT                  0x08
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatClearAxis402Error", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatClearAxis402Error(UInt16 cardid,UInt16 slave_id);
/*ָ��ܣ�ethercat��վ״̬�������
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
            slave_id ��վid��
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetSlaveInfo", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetSlaveInfo(UInt16 cardid, UInt16 slave_id, UInt16 info_type, byte[] info);
/*ָ��ܣ���ȡethercat��վ��Ϣ
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
            slave_id ��վid��
			info_type ��Ҫ��ȡ�Ĵ�վ��Ϣ����
			 0 : ����ID
			 1:  ���̲�ƷID
			 2:  ��Ʒ�汾��
			 3����Ʒ����
			 4������λ��
			 5��λ�ñ���
���������	��
���أ�      0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatIoReadInputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatIoReadInputByBit(UInt16 cardid,UInt16 slave_id,UInt16 bitno,ref UInt16 active_level); 	
/*ָ��ܣ���ȡָ��ethercat��վģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
              bitno	����IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//  ���������  *active_level 
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatIoWriteOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatIoWriteOutputByBit(UInt16 cardid,UInt16 slave_id,UInt16 bitno,UInt16 active_level); 	
/*ָ��ܣ�����ָ��ethercat��վģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
              bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//			active_level �����ƽֵ  0��1
//  �����������
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatIoReadOutputByBit", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatIoReadOutputByBit(UInt16 cardid,UInt16 slave_id,UInt16 bitno,ref UInt16 active_level);  	
/*ָ��ܣ���ȡָ��ethercat��վģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
              bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//  ���������  *active_level
����ֵ��0�������*/
[DllImport("PLT.dll", EntryPoint = "Plt_EthercatGetAxisErrorCode", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
public static extern short Plt_EthercatGetAxisErrorCode(UInt16 cardid,UInt16 slave_id,ref UInt32 ErrorCode);  	
/*ָ��ܣ���ȡָ��ethercat��վ������
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
//  ���������  *ErrorCode ������
����ֵ��0�������*/
/******************************************************************ETHERCAT������غ���*********************************************************/
     
    }
}
