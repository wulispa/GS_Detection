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

//������������
#ifdef __PLT_EXPORTS
	#define PLT_API __declspec(dllexport)
#else
	#define PLT_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

PLT_API short __stdcall Plt_CardOpen(uint16 TotalCards,uint16 *CardIdArray,uint16 *Section,uint16* Host_id);
/*ָ��ܣ���ʼ�����ƿ�
���������  TotalCards	�����������򿪿���������
	        CardIdArray	�����������������IP��ַ����λ�������ã����������Ų����ظ�������Ԫ��ȡֵ��Χ[0,11]��
	        Section	    IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£�������������ƿ�����Ĭ��SectionΪ167������Ԫ��ȡֵ��Χ[1,254]��
	        Host_id	    IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã��������,���ƿ�����Ĭ��Host_idΪ120������Ԫ��ȡֵ��Χ[1,254]��
���������	��
���أ�      0�������*/

PLT_API short __stdcall Plt_CardOpen_extern(uint16 *TotalCards,uint16 *CardTypeArray,uint16 *Section,uint16* Host_id);
/*ָ��ܣ���ʼ�����ƿ�
���������  Section	      IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£�������������ƿ�����Ĭ��SectionΪ167������Ԫ��ȡֵ��Χ[1,254]��
	        Host_id	      IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã��������,���ƿ�����Ĭ��Host_idΪ120������Ԫ��ȡֵ��Χ[1,254]��       
���������	TotalCards	  ��������
            CardTypeArray �ɹ��򿪵Ŀ�����  0:�Ῠ  1��IO��
���أ�      0�������*/

PLT_API short __stdcall Plt_CardOpen_extern_extern(uint16 *TotalCards,uint16 *CardTypeArray,uint16 *Section,uint16* Host_id,uint32 time_out);
/*ָ��ܣ���ʼ�����ƿ�
���������  Section	      IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£�������������ƿ�����Ĭ��SectionΪ167������Ԫ��ȡֵ��Χ[1,254]��
	        Host_id	      IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã��������,���ƿ�����Ĭ��Host_idΪ120������Ԫ��ȡֵ��Χ[1,254]�� 
			time_out      �������ӳ�ʱʱ�� ��λ s
���������	TotalCards	  ��������
            CardTypeArray �ɹ��򿪵Ŀ�����  0:�Ῠ  1��IO��
���أ�      0�������*/

PLT_API short __stdcall Plt_CardClose(void);	//�رտ��ƿ�
/*ָ��ܣ��رտ��ƿ�
���������  ��
���������	��
���أ�      0�������*/

PLT_API short __stdcall Plt_CardReset(void);
/*ָ��ܣ���λ���ƿ�
���������  ��
���������	��
���أ�      0�������*/

PLT_API short __stdcall Plt_ACardOpen(uint16 cardid,uint16 Section,uint16 Host_id);
/*ָ��ܣ���ʼ��һ�����ƿ�
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        Section	IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£������ƿ�����Ĭ��SectionΪ167��ȡֵ��Χ[1,254]��
	        Host_id	IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã����ƿ�����Ĭ��Host_idΪ120��ȡֵ��Χ[1,254]��
���������	��
���أ�      0�������*/

PLT_API short __stdcall Plt_ACardOpen_extern(uint16 cardid,uint16 Section,uint16 Host_id,uint32 time_out);
/*ָ��ܣ���ʼ��һ�����ƿ�
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        Section	IP��ַ�����εĺ��루��������PC�ĵ�ַһ�£������ƿ�����Ĭ��SectionΪ167��ȡֵ��Χ[1,254]��
	        Host_id	IP��ַ���Ķεĺ��루�ɴ��ڻ�ָ�����ã����ƿ�����Ĭ��Host_idΪ120��ȡֵ��Χ[1,254]��
			time_out �������ӳ�ʱʱ�� ��λ ms
���������	��
���أ�      0�������*/

PLT_API short __stdcall Plt_ACardClose(uint16 cardid);	//�رտ��ƿ�
/*ָ��ܣ��ر�һ�����ƿ�
��������� cardid	���ţ�ȡֵ��Χ[0,11]��
��������� ��
���أ�0�������*/
PLT_API short __stdcall Plt_CardGetVerson(uint16 cardid,DWORD *verson1,DWORD *verson2,DWORD *verson3); 
/*ָ��ܣ���ȡ��ذ汾��
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	*verson1	FPGA�汾��
	        *verson2	�̼��汾��
			*verson3	��̬���ӿ�汾��
���أ�      0�������*/
PLT_API short __stdcall Plt_GetCardSerialNum(uint16 cardid,DWORD *SerialNum_0,DWORD *SerialNum_1,DWORD *SerialNum_2); 
/*ָ��ܣ���ȡ���ƿ�96λ���к�
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	SerialNum_0	���к�0-31λ
	        SerialNum_1	���к�32-63λ
			SerialNum_2	���к�64-95λ
���أ�      0�������*/
PLT_API short __stdcall Plt_CardUpdataFirmare(uint16 cardid,const char *filename);
/*ָ��ܣ����ƿ��̼�����
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        *filename	�¹̼�����·���� ע�⣺·���в����������ַ�
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_CardReadCommincationState(uint16 cardid,uint16 *state);	
/*ָ��ܣ���ȡPC�����˶����ƿ�����״̬
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	*state	PC�����˶����ƿ�����״̬ 1������  0���Ͽ�
���أ�      0�������*/
PLT_API short __stdcall Plt_CardGetCardAxisNum(uint16 cardid,uint16 *axisnum);
/*ָ��ܣ���ȡ��������
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������  *axisnum	���ƿ�������
���أ�      0�������*/
PLT_API short __stdcall Plt_CardParmsFileConfig(uint16 cardid,const char *ParmsFile);
/*ָ��ܣ������˶����ƿ�
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        *ParmsFile	�����ļ� ע�⣺·�������Ǿ���·������·���в��ܳ��������ַ�
���������	��
���أ�      0�������*/
PLT_API short __stdcall PLT_GCodeFileProcess(uint16 cardid,const char* FileName);

PLT_API short __stdcall Plt_CardReSetIP(uint16 cardid,uint16 section_3,uint16 section_4);
/*ָ��ܣ����ÿ��ƿ�IP��ַ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        section_3	IP��ַ������ֵ����������PC�ĵ�ַһ�£����ƿ�����Ĭ��SectionΪ167��ȡֵ��Χ[1,254]��
			section_4   IP��ַ���Ķ�ֵ����������PC�ĵ�ַһ�£����ƿ�����Ĭ��SectionΪ120��ȡֵ��Χ[1,254]��
���������	��
    ˵����	�����õ�IP��ַ�ڿ��ƿ������ϵ����Ч
���أ�      0�������*/
PLT_API short __stdcall Plt_CardGetIP(uint16 cardid,uint16 *section_3,uint16 *section_4);//��ȡIP��ַ����
/*ָ��ܣ��ض����ƿ����õ�IP��ַ
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	*section_3	IP��ַ������ֵ�����ƿ�����Ĭ��SectionΪ167
            *section_4	IP��ַ���Ķ�ֵ�����ƿ�����Ĭ��SectionΪ120
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetPulseOutMode(uint16 cardid,uint16 axis,uint16 mode);	
/*ָ��ܣ��趨�������ģʽ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			mode	    �������ģʽ��ȡֵ��Χ��0��2��4��6����������ģʽ�ľ��岨�βο�����ֲᡰ3.4����ģʽ��һ��
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetPulseOutMode(uint16 cardid,uint16 axis,uint16 *mode);	//��ȡ�������ģʽ
/*ָ��ܣ���ȡ�������ģʽ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*mode	    �������ģʽ��ȡֵ��Χ��0��2��4��6����������ģʽ�ľ��岨�βο�����ֲᡰ3.4����ģʽ��һ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetEncoderInMode(uint16 cardid,uint16 axis,uint16 mode);  
/*ָ��ܣ��趨�������������ģʽ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			mode	    �������������ģʽ  ȡֵ��Χ:[0,3]  0������+����   1��1��Ƶ 2:2��Ƶ  3:4��Ƶ
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetEncoderInMode(uint16 cardid,uint16 axis,uint16 *mode); 
/*ָ��ܣ���ȡ�������������ģʽ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*mode	    �������������ģʽ
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetEncoderInNegation(uint16 cardid,uint16 axis,uint16 mode);  
/*ָ��ܣ��趨��������������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			mode	    ��������������  ȡֵ��Χ:[0,1]  0��EA��ǰEB������   1��EA��ǰEB������
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetEncoderInNegation(uint16 cardid,uint16 axis,uint16 *mode); 
/*ָ��ܣ���ȡ��������������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*mode	   ��������������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetPPU(uint16 cardid,uint16 axis, double PPU);
/*ָ��ܣ��趨���嵱��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			PPU	���嵱��ֵ���û���λ��Ӧ����������
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetPPU(uint16 cardid,uint16 axis, double *PPU);
/*ָ��ܣ���ȡ���嵱��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*PPU	    ���嵱��ֵ���û���λ��Ӧ����������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetBacklash(uint16 card,uint16 axis,double backlash);
/*ָ��ܣ����÷����϶����
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			backlash	�����϶ֵ����λ�����嵱����λ PPU
���������	��
���أ�      0�������*/

PLT_API short __stdcall Plt_AXGetBacklash(uint16 cardid,uint16 axis,double *backlash);
/*ָ��ܣ���ѯ�����϶����
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*backlash	�����϶ֵ
���أ�      0�������*/

PLT_API short __stdcall Plt_AxSetLimitSpeed(uint16 cardid,uint16 axis,double speed);
/*ָ��ܣ�������ļ����ٶ�
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			speed	    ��ļ����ٶ� ����λ��ppu/s
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetLimitSpeed(uint16 cardid,uint16 axis,double *speed);
/*ָ��ܣ���ȡ��ļ����ٶ�
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*speed	    ��ļ����ٶ� ����λ��ppu/s
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetLimitAcc(uint16 cardid,uint16 axis,double acc);
/*ָ��ܣ�������ļ��޼��ٶ�
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			acc	        ��ļ��޼��ٶ�
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetLimitAcc(uint16 cardid,uint16 axis,double *acc);
/*ָ��ܣ���ȡ��ļ��޼��ٶ�
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*acc	    ��ļ��޼��ٶ�
���أ�      0�������*/

PLT_API short __stdcall Plt_AxSetCmmandPosition(uint16 cardid, uint16 axis, double pos);
/*ָ��ܣ��������ָ��λ��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			pos	        ָ��λ��ֵ
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetCmmandPosition(uint16 cardid,uint16 axis, double * pos);
/*ָ��ܣ���ѯ���ָ��λ��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*pos	    ָ��λ��ֵ
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetEncoderPosition(uint16 cardid,uint16 axis, double pos);
/*ָ��ܣ����ñ�����λ��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			pos	        �������趨ֵ
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetEncoderPosition(uint16 cardid,uint16 axis, double * pos);
/*ָ��ܣ���ȡ������λ��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*pos	    ������λ��
���أ�      0�������*/

PLT_API short __stdcall Plt_AxSetBand(uint16 cardid,uint16 axis,double band,uint32 hold_time,uint32 check_time);
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
PLT_API short __stdcall Plt_AxGetBand(uint16 cardid,uint16 axis,double *band,uint32 *hold_time,uint32 *check_time);
/*ָ��ܣ���ѯ�ᵽλ�������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*band	��������λ��PPU
            *hold_time	������λ�ý���������С����ʱ�� ��λ��ms
			*check_time	�ᵽλ�����ʱ�� ��λ��ms
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetBandFlag(uint16 cardid,uint16 axis,uint16 *band_flag);
/*ָ��ܣ���ȡ����������־
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*band_flag	0����λ��
                        1����λ���
                        2����λʧ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetBandLocationTime(uint16 cardid,uint16 axis,uint32 *location_time);
/*ָ��ܣ���ȡ������λʱ��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������  *location_time  ��ǰ��ʱʱ�䣨�����巢����ɿ�ʼ���㣩                 ��λ��ms
���أ�      0�������*/

PLT_API short __stdcall Plt_AxCheckEncoderDirResever(uint16 cardid,uint16 axis,uint32 hold_time);
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
PLT_API short __stdcall Plt_AxGetCheckEncoderDirResever(uint16 cardid,uint16 axis,uint32 *hold_time);
/*ָ��ܣ����������˶������Ƿ������巽���෴�Ĳ�����ѯ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������  *hold_time	�����෴����ʱ�� ��λ��ms
���أ�      0�������*/
/*************************************************************************��ȫ����***************************************************************/
typedef struct
{
  uint16 pel_enable;//����λʹ�ܣ�0������λ��ֹ��1������λʹ��
  uint16 mel_enable;//����λʹ�ܣ�0������λ��ֹ��1������λʹ��
  uint16 pel_active_level;//����λ��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  uint16 mel_active_level;//����λ��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  uint16 pel_react;//����λ��Чֹͣ��ʽ��0������ֹͣ��1������ֹͣ
  uint16 mel_react;//����λ��Чֹͣ��ʽ��0������ֹͣ��1������ֹͣ
}struct_el_parms; //Ӳ��λ�����ṹ��

typedef struct
{ 
  double melpos;//������λλ�ã���λ:[ppu]
  double pelpos;//������λλ�ã���λ:[ppu]
  uint16 enable;//����λʹ�ܣ�0������λ��ֹ��1������λʹ��
  uint16 react;//����λ��Чֹͣ��ʽ��0������ֹͣ��1������ֹͣ
}struct_sw_el_parms;//����λ�����ṹ��

PLT_API short __stdcall Plt_AxSetEl(uint16 cardid,uint16 axis,struct_el_parms elparms); 
/*ָ��ܣ�����Ӳ����λ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			elparms	    Ӳ��λ����
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetEl(uint16 cardid,uint16 axis,struct_el_parms *elparms); 
/*ָ��ܣ���ȡӲ����λ������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*elparms	Ӳ��λ����
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetSWEL(uint16 cardid,uint16 axis,struct_sw_el_parms swelparms);
/*ָ��ܣ����������λ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			swelparms	�����λ����
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetSWEL(uint16 cardid,uint16 axis,struct_sw_el_parms *swelparms);
/*ָ��ܣ���ȡ�����λ������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*swelparms	�����λ����
���أ�      0�������*/
/*************************************************************************��ȫ����***************************************************************/

/*************************************************************************ר�ýӿ�***************************************************************/
typedef struct
{
  uint16 emg_enable;//emgʹ�ܿ��أ�0��ʹ�ܽ�ֹ 1��ʹ����Ч
  uint16 emg_level;//emg��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  uint16 emg_port;//ӳ��ΪEMG������IO�� ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
  uint16 alm_enable;//almʹ�ܿ��أ�0��ʹ�ܽ�ֹ 1��ʹ����Ч
  uint16 alm_level;//alm��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  double filter_time;//�����ź��˲�ʱ�䣻��λ[ms]
  uint16 inp_enable;//inpʹ�ܿ��أ�0��ʹ�ܽ�ֹ 1��ʹ����Ч
  uint16 inp_level;//inp��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
}struct_special_input_parms;//

typedef struct
{
  uint16 alm_status;//alm״̬��0:��Ч��1����Ч
  uint16 el_pos_status;//����λ״̬��0:��Ч��1����Ч
  uint16 el_neg_status;//����λ״̬��0:��Ч��1����Ч
  uint16 swel_pos_status;//������λ״̬��0:��Ч��1����Ч
  uint16 swel_neg_status;//������λ״̬��0:��Ч��1����Ч
  uint16 emg_status;//emg״̬��0:��Ч��1����Ч
  uint16 home_status;//ԭ��״̬��0:��Ч��1����Ч
  uint16 inp_status;//inp״̬��0:��Ч��1����Ч
  uint16 ez_status;//ez״̬��0:��Ч��1����Ч
  uint16 rdy_status;//rdy״̬��0:��Ч��1����Ч
}struct_special_input_status;//ר������״̬
PLT_API short __stdcall Plt_AxConfigSpecialInputParms(uint16 cardid,uint16 axis,struct_special_input_parms specinput);
/*ָ��ܣ�����EMG\ERC\INP\ALM���źź��˲�ʱ��
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			specinput	ר����������
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxReadSpecialInputParms(uint16 cardid,uint16 axis,struct_special_input_parms *specinput);
/*ָ��ܣ���ȡEMG\ERC\INP\ALM���źź��˲�ʱ�������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*specinput	ר����������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxReadSpecialInputStatus(uint16 cardid,uint16 axis,struct_special_input_status *inputstatus);
/*ָ��ܣ���ȡ��ר�������ź�״̬
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*inputstatus	ר������״̬
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetsvonPort(uint16 cardid,uint16 axis,uint16 active_level); 	
/*ָ��ܣ����SEVON�ź�
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			active_level	SERV-ON�����ƽֵ 0:�͵�ƽ 1���ߵ�ƽ
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetsvonPort(uint16 cardid,uint16 axis,uint16 *active_level);
/*ָ��ܣ���ȡSEVON�ź�
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*active_level	SERV-ON�����ƽֵ 0:�͵�ƽ 1���ߵ�ƽ
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetRdyPort(uint16 cardid,uint16 axis,uint16 *active_level);
/*ָ��ܣ���ȡRDY�źţ��˺���������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*active_level	RDY�ź�����ֵ 0:�͵�ƽ 1���ߵ�ƽ
���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetErcPort(uint16 cardid,uint16 axis,uint16 active_level);
/*ָ��ܣ�����ERC�ź������ƽ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
			active_level	ERC�ź����ֵ	0:�͵�ƽ 1���ߵ�ƽ
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetErcPort(uint16 cardid,uint16 axis,uint16 *active_level);
/*ָ��ܣ���ȡ����ERC�ź������ƽ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
	        axis	    ��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                        EI800ȡֵ��Χ:[0,7];
                        EIC00ȡֵ��Χ:[0,11];
���������	*active_level	ERC�ź����ֵ 0:�͵�ƽ 1���ߵ�ƽ
���أ�      0�������*/
/*************************************************************************ר�ýӿ�***************************************************************/

/*************************************************************************����IO���ù���*********************************************************/
typedef struct
{ 
  uint16 type;//0������λ 1������λ 2��ԭ�� 3���ŷ�����  4���ŷ�׼�� 5���ŷ���λ 6:ͨ������IO
  uint16 axis;//���.EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];type С��6ʱ�˲�����Ч
  uint16 bitno;//ͨ������IO��ţ�EI400\EI400S:[0,31]��EI800\EIC00:[0,15];type����6ʱ�˲�����Ч
  double Filter;//�˲�ʱ�䣬��λ[ms]
}struct_original_type;//ԭʼ����IO����
typedef struct
{
   uint16 axis;//���,EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
   uint16 type;//0������λ 1������λ 2��ԭ�� 3����ͣ  4������ֹͣ 5���ŷ����� 6:�ŷ�׼�� 7:�ŷ���λ
}struct_reuse_type;//��������IO����
PLT_API short __stdcall PLT_IoSet_input_reuse_to_special_input(uint16 cardid,struct_original_type original_type,struct_reuse_type reuse_type);
/*ָ��ܣ�ͨ������IO����ר������IO����Ϊר������IO
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            original_type �����õ�ͨ������IO��Ż���ר������IO����
            reuse_type    ���ú��ר������IO����
�����������
���أ�      0�������*/
PLT_API short __stdcall PLT_IoSet_special_input_reuse_to_input_extern(uint16 cardid,struct_original_type original_type,uint16 bitno);
/*����������ר������IO����Ϊͨ������IO
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            original_type ר������IO����
			bitno ���ú�IO���     EI400\EI400Sȡֵ��Χ:[0,23];
                                   EI800ȡֵ��Χ:[0,47];
                                   EIC00ȡֵ��Χ:[0,71];
�����������
���أ�      0�������*/
PLT_API short __stdcall PLT_IoGet_special_input_reuse(uint16 cardid,struct_reuse_type reuse_type,struct_original_type *original_type);
/*ָ��ܣ���ȡ��ר������IO��������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            reuse_type��������IO����
���������  original_type  ԭʼ����IO����
���أ�      0�������*/
PLT_API short __stdcall PLT_IoGet_input_extern_reuse(uint16 cardid,uint16 bitno,struct_original_type *original_type);
/*ָ��ܣ���ȡ��չ����IO��������
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            bitno       EI400\EI400Sȡֵ��Χ:[0,23];
                        EI800ȡֵ��Χ:[0,47];
                        EIC00ȡֵ��Χ:[0,71];
���������  *original_type ԭʼ����IO����
���أ�      0�������*/
PLT_API short __stdcall PLT_IoRead_input_reuse_bybit(uint16 cardid,uint16 bitno,uint16 *active_level);
/*ָ��ܣ���ȡ��������IO״̬
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            bitno       EI400\EI400Sȡֵ��Χ:[0,23];
                        EI800ȡֵ��Χ:[0,47];
                        EIC00ȡֵ��Χ:[0,71];
���������  *active_level ��������IO��ֵ
���أ�      0�������*/
/*************************************************************************����IO���ù���*****************************************************/


/*************************************************************************ͨ���������IO**********************************************************/
PLT_API short __stdcall Plt_IoReadInputByBit(uint16 cardid,uint16 bitno,uint16 *active_level); 	
/*ָ��ܣ���ȡ����ڵ�״̬
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
���������  *active_level �����״̬ 0���͵�ƽ  1���ߵ�ƽ
���أ�      0�������*/
PLT_API short __stdcall Plt_IoWriteOutputByBit(uint16 cardid,uint16 bitno,uint16 active_level); 	
/*ָ��ܣ���������ڵ�״̬
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			active_level ��������״̬ 0���͵�ƽ  1���ߵ�ƽ
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_IoReadOutputByBit(uint16 cardid,uint16 bitno,uint16 *active_level);  	
/*ָ��ܣ���ȡ����ڵ�״̬
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
            bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
���������  *active_level �����״̬ 0���͵�ƽ  1���ߵ�ƽ
���أ�      0�������*/
PLT_API short __stdcall Plt_IoReadAllInput(uint16 cardid,DWORD *active_level_1,DWORD *active_level_2); 
/*ָ��ܣ���ȡ����˿ڵ�ֵ
���������  cardid	    ���ţ�ȡֵ��Χ[0,11]��
���������  *active_level_1	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31
                            EI400\EI400S: bit0-bit31λ����Ч��
                            EI800\EIC00: bit0-bit15λ��Ч��
			*active_level_2	�����32--63��״̬, bit0��ӦIN32��bit31��ӦIN63��������
���أ�      0�������*/
PLT_API short __stdcall Plt_IoReadAllOutput(uint16 cardid,DWORD *active_level); 	
/*ָ��ܣ���ȡ����˿ڵ�ֵ
���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
���������  *active_level           ���������0--31��״̬, bit0��ӦOUT0��bit31��ӦOUT31
                                    EI400\EI400S: bit0-bit31λ����Ч��
                                   EI800\EIC00: bit0-bit15λ��Ч��
���أ�      0�������*/
PLT_API short __stdcall Plt_IoWriteAllOutput(uint16 cardid,DWORD active_level);  	//����ͨ������˿ڵ�ֵ
/*ָ��ܣ���������˿ڵ�ֵ
���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
           active_level	            ��������ڵ����״̬, bit0��ӦOUT0��bit31��ӦOUT31
                                    EI400\EI400S: bit0-bit31λ����Ч��
                                    EI800\EIC00: bit0-bit15λ��Ч��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_IoReverseOutputBit(uint16 cardid,uint16 bitno,double hold_time); 
/*ָ��ܣ���ת��ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
            bitno       ����ڱ��,ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			hold_time	��ƽ����ʱ�䣬��λ��ms
���������  ��
���أ�      0�������*/ 
PLT_API short __stdcall Plt_IoInitOutputBit(uint16 cardid);
/*ָ��ܣ��ѵ�ǰ���IO��ʼ��ƽ�����´ο������ϵ�����IO�ĳ�ʼ��ƽ����ͨ�����IO��ʼ��ƽ�ɿ��ƿ���ǰͨ�����IO��ƽ�����������������ÿ��ƿ������ϵ���Ч��
���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_IoInitALLOutput(uint16 cardid,DWORD active_level); 
/*ָ��ܣ��������IO��ʼ��ƽ����ͨ�����IO��ʼ��ƽ�ɴ˺������ã����ƿ������ϵ���Ч��
���������  cardid	                ���ţ�ȡֵ��Χ[0,11]��
            active_level	���������0--31��״̬, bit0��ӦOUT0��bit31��ӦOUT31
            EI400\EI400S: bit0-bit31λ����Ч��
            EI800\EIC00: bit0-bit15λ��Ч��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_IoSetOutputMap(uint16 cardid,uint16 logic_output_num,uint16 physical_out_num); 
/*ָ��ܣ�����ͨ�����IOӳ��
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            logic_output_num �߼����IO�����
            physical_out_num ʵ������İ忨����IO�����
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_IoGetOutputMap(uint16 cardid,uint16 logic_output_num,uint16 *physical_out_num); 
/*ָ��ܣ���ѯͨ�����IOӳ��
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *logic_output_num �߼����IO�����
            *physical_out_num ʵ������İ忨����IO�����
���أ�      0�������*/
PLT_API short __stdcall Plt_IoSetNegation(uint16 cardid,uint32 output_negation,uint32 input_negation); 
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
PLT_API short __stdcall Plt_IoGetNegation(uint16 cardid,uint32 *output_negation,uint32 *input_negation); 
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
			hold_time      �������͵�ƽ/�ߵ�ƽʱ�� ��λ us
���������  ��
���أ�      0�������*/
PLT_API short __stdcall  Plt_IoOutputPulses(uint16 cardid,uint32 pulse_num,uint32 hold_time);
/*ָ��ܣ�ֹͣ��������趨��������
���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
���������  ��
���أ�      0�������*/
PLT_API short __stdcall  Plt_IoOutputPulsesStop(uint16 cardid);

PLT_API short __stdcall  Plt_Io_set_check_input_for_output(uint16 cardid,uint16 input_id,uint16 enable_flag,uint16 input_logic,uint16 output_id,uint16 output_logic);
/*ָ��ܣ����õȴ���ĳ������IO�趨�������ƽʱ���ض������IO������õĵ�ƽ
���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
            input_id: ����IO���[0,7]
			enable_flag: 1:�����˹���  0���رմ˹���
			input_logic���ȴ�������IO��ƽ
			output_id�����IO���[0,7]
			output_logic�������ƽ
���������  ��
���أ�      0�������*/
PLT_API short __stdcall  Plt_Io_get_check_input_for_output(uint16 cardid,uint16 input_id,uint16 *enable_flag,uint16 *input_logic,uint16 *output_id,uint16 *output_logic);
/*ָ��ܣ���ȡ�ȴ���ĳ������IO�趨�������ƽʱ���ض������IO������õĵ�ƽ
���������  cardid ���ţ�  ȡֵ��Χ:EI400S:[0,3] EI800[0,7] EIC00/EIC04 [0,11]
            input_id: ����IO���[0,7]
���������  enable_flag: 1:�����˹���  0���رմ˹���
			input_logic���ȴ�������IO��ƽ
			output_id�����IO���[0,7]
			output_logic�������ƽ
���أ�      0�������*/
/***********************************************��������趨��������*****************************************/
/*************************************************************************ͨ���������IO**********************************************************/

/*************************************************************************һάλ�ñȽϹ���*********************************************************/
typedef struct
{
  uint16 cmp_axis;//�Ƚ����,EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
  uint16 enable;//�Ƚ�ʹ�ܿ��أ�0���ȽϽ�ֹ��1���Ƚ�����
  uint16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
}struct_axis_compare_parms;//����λ�ñȽ����ò����ṹ��

typedef struct
{
  double cmpposition; //�Ƚ�λ�ã���λ��[pulse]
  uint16 cmpmethod; //�ȽϷ�����0�����ڵ��ڣ�1��С�ڵ���
  uint16 reaction;//�Ƚ϶���;0���趨io�ŵ�ƽȡ����1���趨io������͵�ƽ��2���趨IO������ߵ�ƽ��3���趨io������趨ʱ���ȵ����壻4���趨�����ֹͣ��5���趨������ֹͣ
  double pulsewidth;//�����ȣ���λ��[ms]
  uint16 react_object;//�趨io�Ż����趨��
}struct_axis_compare_datas;//����Ƚϻ���������

PLT_API short __stdcall Plt_AxCompareSetParms(uint16 cardid,uint16 cmpno,struct_axis_compare_parms axcmpparms);
/*ָ��ܣ����ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
            axcmpparms	һάλ�ñȽ����ò���
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCompareGetParms(uint16 cardid,uint16 cmpno,struct_axis_compare_parms *axcmpparms);	
/*ָ��ܣ���ȡ���ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
���������  *axcmpparms	һάλ�ñȽ����ò���
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCompareClearBuf(uint16 cardid,uint16 cmpno); 	
/*ָ��ܣ�����Ƚ������бȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCompareSetData(uint16 cardid,uint16 cmpno,struct_axis_compare_datas axcmpdata);
/*ָ��ܣ���ӱȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
            axcmpdata	�Ƚ�λ�ò���
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCompareGetData(uint16 cardid,uint16 cmpno,double *cmpposition); 	//��ȡ��ǰ�Ƚϵ�
/*ָ��ܣ���ȡ��ǰ�Ƚϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
            *cmpposition	������һ���������еıȽϵ�
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCompareGetComparedDataNum(uint16 cardid,uint16 cmpno,long *num); 
/*ָ��ܣ���ѯ�Ѿ��ȽϹ��ĵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
            *num	�Ѿ������˱Ƚϵ�λ�ø���
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCompareGetBufRemain(uint16 cardid,uint16 cmpno,long *space); 
/*ָ��ܣ���ѯ���Լ���ıȽϵ�����
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ����� ȡֵ��Χ��[0,11]
            *space	ʣ��ȽϿռ�
���������  ��
���أ�      0�������*/
/*************************************************************************һάλ�ñȽϹ���*********************************************************/

/*************************************************************************��άλ�ñȽϹ���*********************************************************/
typedef struct
{
  uint16 axis_array[2];//�Ƚ����б� ȡֵ��Χ��EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7]; EIC00ȡֵ��Χ:[0,11];
  double cmpposition_array[2];//�Ƚ�λ���б�
  uint16 cmpmethod_array[2];//�ȽϷ�����0�����ڵ��ڣ�1��С�ڵ���
  uint16 reaction;//�Ƚ϶���;0���趨io�ŵ�ƽȡ����1���趨io������͵�ƽ��2���趨IO������ߵ�ƽ��3���趨io������趨ʱ���ȵ����壻4���趨�����ֹͣ��5���趨������ֹͣ
  double pulsewidth;//�����ȣ���λ��[ms]
  uint16 react_object;//�趨io�Ż����趨��
}struct_crd_compare_datas;//��ά�Ƚϻ���������
PLT_API short __stdcall Plt_CrdcCompareSetParms(uint16 cardid,uint16 enable, uint16 cmp_source); 	
/*ָ��ܣ����ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            enable	��ά�Ƚ��Ƿ�ʹ��  1��ʹ�� 0����ֹ
            cmp_source �Ƚ�Դ 0��������� 1������������
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdcCompareGetParms(uint16 cardid,uint16 *enable, uint16 *cmp_source);
/*ָ��ܣ���ȡ���ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *enable	��ά�Ƚ��Ƿ�ʹ��  1��ʹ�� 0����ֹ
            *cmp_source �Ƚ�Դ 0��������� 1������������
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdCompareClearBuf(uint16 cardid); 
/*ָ��ܣ�������бȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdCompareSetData(uint16 cardid,struct_crd_compare_datas crdcmpdata);
/*ָ��ܣ���ӱȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            crdcmpdata �Ƚϵ�����ṹ��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdCompareGetData(uint16 cardid,uint16* axis_array,double *cmpposition_array); 
/*ָ��ܣ���ȡ��ǰ�Ƚϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *axis_array �Ƚ����б�
            *cmpposition_array �Ƚ�λ���б�
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdCompareGetComparedDataNum(uint16 cardid,long *num);
/*ָ��ܣ�/��ѯ�Ѿ��Ƚϵ�����
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *num �ѱȽϵ�����
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdCompareGetBufRemain(uint16 cardid,long *space); 	//��ѯ���Լ���ıȽϵ�����
/*ָ��ܣ�/��ѯʣ��Ƚϻ�����
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *space ʣ��Ƚϻ�������С
���أ�      0�������*/
/*************************************************************************��άλ�ñȽϹ���*********************************************************/

/*************************************************************************һά��ȷλ�ñȽϹ���*********************************************************/
typedef struct
{
  uint16 cmp_axis;//�Ƚ���� EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
  uint16 enable;//�Ƚ�ʹ�ܿ��أ�0;�ȽϽ�ֹ��1���Ƚ�����
  uint16 cmpmethod;//�ȽϷ�����0�����ڣ�1��С��; 2������ 3:�������ȽϷ���(����λ��ģʽ) 4�����ԱȽϷ� 5��:�������ȽϷ���(���λ��ģʽ)
  uint16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
  uint16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  double pulsewidth;//�����ȣ���λ����ms��;�˲���ֻ����cmpmethod���ڵ���3�������Ч
  double liner_distance;//����λ�ñȽ�����ֵ ��λ��PPU
  uint32 liner_num;//����λ�ñȽ���
}struct_axis_accurate_compare_parms;//��ȷλ�ñȽ�
PLT_API short __stdcall Plt_AxAccurateCompareSetParms(uint16 cardid,uint16 queueno,struct_axis_accurate_compare_parms acccmpparms);
/*ָ��ܣ����ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            queueno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
            acccmpparms	һά����λ�ñȽ����ò���
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareGetParms(uint16 cardid,uint16 queueno,struct_axis_accurate_compare_parms *acccmpparms);
/*ָ��ܣ���ȡ���ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            queueno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
���������  *acccmpparms	һά����λ�ñȽ����ò���
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareClearBuf(uint16 cardid,uint16 cmpno);
/*ָ��ܣ�����Ƚ������бȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareSetData(uint16 cardid,uint16 cmpno,uint16 axis,double cmpposition);
/*ָ��ܣ���ӱȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
            cmpposition	�Ƚ�λ��
			axis	��������
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareGetData(uint16 cardid,uint16 cmpno,uint16 axis,double *cmpposition);
/*ָ��ܣ���ȡ��ǰ�Ƚϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
			axis	��������
���������  *cmpposition	�Ƚ�λ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareGetComparedDataNum(uint16 cardid,uint16 cmpno,long *num); 	
/*ָ��ܣ���ѯ�Ѿ��ȽϹ��ĵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
���������  *num	�����Ѿ������˱Ƚϵ�λ������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareGetBufRemain(uint16 cardid,uint16 cmpno,long *space); 
/*ָ��ܣ���ѯ���Լ���ıȽϵ�����(���ԱȽ�ģʽ��space����ʣ��ıȽϵ���)
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
���������  *num	�����Ѿ������˱Ƚϵ�λ������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareGetRemainPoints(uint16 cardid,uint16 cmpno,long *remain_points); 
/*ָ��ܣ���ѯ���м����Ƚϵ㻹û�н��бȽ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1]; 
���������  *remain_points	���м����Ƚϵ㻹û�н��бȽ�
���أ�      0�������*/
PLT_API short __stdcall Plt_AxAccurateCompareOutputMapSet(uint16 cardid,uint16 axis_id,uint16 enable);
/*ָ��ܣ���10����11��ӳ��Ϊ���������
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis_id      ��ţ�ȡֵ��Χ��10��11
            enable	1:�����������ӳ��Ϊ��������� 0������������ָ�Ϊ���������
  �����������
  ���ز�����������*/
PLT_API short __stdcall Plt_AxAccurateCompareOutputMapGet(uint16 cardid,uint16 axis_id,uint16 *enable); 
/*ָ��ܣ���ȡ��10����11��ӳ���Ƿ�ӳ��Ϊ���������
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis_id     ��ţ�ȡֵ��Χ��10��11       
  ���������*enable	1:�����������ӳ��Ϊ��������� 0������������ָ�Ϊ���������
  ���ز�����������*/
PLT_API short __stdcall Plt_AxAccurateCompareSetMultiData(uint16 cardid,uint16 cmpno,uint16 data_num,double *cmpposition);
/*ָ��ܣ����ٱȽ���Ӷ���Ƚϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            cmpno	�Ƚ�����, EI400\EI400S\ EI800ȡֵ��Χ:[0,3];EIC00ȡֵ��Χ:[0,1];
			data_num	��ӵıȽϵ���� ȡֵ��Χ��[1,127]
            *cmpposition 	�Ƚϵ�λ������  ��λ��ppu
���������  ��
���أ�      0�������*/
/*************************************************************************����λ�ñȽϹ���*********************************************************/

/*************************************************************************��ά��ȷλ�ñȽϹ���*********************************************************/
typedef struct
{
  uint16 axis_array[2];//�Ƚ����С�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7]; EIC00ȡֵ��Χ:[0,11];
  uint16 enable;//�Ƚ�ʹ�ܿ��أ�0;�ȽϽ�ֹ��1���Ƚ�����
  uint16 cmpmethod;//����ֵ
  uint16 cmp_source;//�Ƚ�Դ 0������λ�� 1��������λ��
  uint16 active_level;//�����Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  double pulsewidth;//�����ȣ���λ����ms��;
  double cmp_error;//���ȣ���λ[pulse]
}struct_crd_accurate_compare_parms;//��ȷλ�ñȽ�
PLT_API short __stdcall Plt_CrdAccurateCompareSetParms(uint16 cardid,struct_crd_accurate_compare_parms acccmpparms);
/*ָ��ܣ����ñȽ���
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            acccmpparms ���ٶ�ά�Ƚ����ò����ṹ��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetParms(uint16 cardid,struct_crd_accurate_compare_parms *acccmpparms);
/*ָ��ܣ���ȡ�Ƚ�������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *acccmpparms ���ٶ�ά�Ƚ����ò����ṹ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateCompareClearBuf(uint16 cardid);
/*ָ��ܣ�����Ƚ������бȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateCompareSetData(uint16 cardid,double *cmpposition_array);
/*ָ��ܣ���ӱȽϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            *cmpposition_array	�Ƚ�λ���б�
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetData(uint16 cardid,double *cmpposition_array);
/*ָ��ܣ���ȡ��ǰ�Ƚϵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *cmpposition_array	�Ƚ�λ���б�
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetComparedDataNum(uint16 cardid,long *num); 
/*ָ��ܣ���ѯ�Ѿ��ȽϹ��ĵ�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *num	�Ѿ������˱Ƚϵ�λ������
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateCompareGetBufRemain(uint16 cardid,long *space); 	
/*ָ��ܣ���ѯ���Լ���ıȽϵ�����
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
���������  *space	ʣ��ȽϿռ�
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateConfigOutBit(uint16 cardid,uint32 bitmask); 	
/*ָ��ܣ�ѡ���ά���ٱȽ������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            bitmask ȡֵ��Χ12��13
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_CrdAccurateReadOutBit(uint16 cardid,uint32 *bitmask); 	
/*ָ��ܣ�ѡ���ά���ٱȽ������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            bitmask ȡֵ��Χ12��13
���������  ��
���أ�      0�������*/
/*************************************************************************����λ�ñȽϹ���*********************************************************/



/*************************************************************************λ�����湦��*********************************************************/
typedef struct
{
  uint16 active_level;//��Ч�أ�0������������1���½�������
  uint16 latch_method;//���淽ʽ��0���������棻1����������
  uint16 latch_source;//����Դ��0����������λ�ã�1�����������λ�ã�
}struct_axis_latch_parms;//λ����������
PLT_API short __stdcall Plt_AxConfigLatchParms(uint16 cardid,uint16 ltc_num,uint16 axis,struct_axis_latch_parms ltcparms); 	
/*ָ��ܣ����ø����������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			ltcparms	�������
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxReadLatchParms(uint16 cardid,uint16 ltc_num,uint16 axis,struct_axis_latch_parms *ltcparms);	
/*ָ��ܣ���ȡ������������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
���������  *ltcparms	�������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetLatchFlagStatus(uint16 cardid,uint16 ltc_num,uint16 axis,uint16 *latchstatus); 	
/*ָ��ܣ���ȡ��������־
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
���������  *latchstatus	�����־��1:���������� 0��û���������ݣ�
���أ�      0�������*/
PLT_API short __stdcall Plt_AxClearLatchStatus(uint16 cardid,uint16 ltc_num,uint16 axis);  
/*ָ��ܣ���λ��������־
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetLacthPosition(uint16 cardid,uint16 ltc_num,uint16 axis,uint16 startpos_index,uint16 count,double *position);
/*ָ��ܣ���ȡ����λ��
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
            ltc_num	������ͨ���ţ�ȡֵ��Χ[0,1]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
			startpos_index	��Ҫ��ȡ�Ŀ�ʼλ�������ţ�ȡֵ��Χ:[0,255]  ��������ģʽ�� �˲�����Ч                                            
	        count	��Ҫ��ȡ�ĸ�����ȡֵ��Χ:[0,255]  ��������ģʽ�� �˲�����Ч
���������  *position	��ȡ������λ���б�
���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetLatchNum(uint16 cardid,uint16 ltc_num,uint16 axis,uint16 *num);  
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
typedef struct
{ 
  double home_high_vel;//������٣���λ����pulse/s��,ȡֵ��Χ��0,4000000��
  double home_low_vel;//������٣� ��λ����pulse/s��,ȡֵ��Χ��0,4000000��
  double home_acc;//����Ӽ��ٶ�,  ��λ����pulse/s2��,ȡֵ��Χ��0,4000000000��
  uint16 home_mode;//0:ԭ�㲶�����;1��EZ�������;2:ԭ��+EZ������� 3��������EZ������� 4��һ�λ��� 5�����λ��� 6��һ�λ���ӷ��һ��� 7��ԭ���EZ���� 8��ez���� 9��������EZ����
  uint16 org_level;//ԭ����Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  uint16 org_ltc_source;//ԭ������Դ��0������λ�� 1��������λ��
  uint16 ez_level;//ez��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  uint16 ez_ltc_source;//ez����Դ��0������λ�� 1��������λ��
  uint16 org_ltc_level;//0������������ԭ��  1���½�������ԭ��
  uint16 ez_ltc_level;//0������������ez 1���½�������ez
}struct_home_config_parms;//����ģ�����ò���
PLT_API short __stdcall Plt_AxConfigHomeParms(uint16 cardid,uint16 axis,struct_home_config_parms homeparms);
/*ָ��ܣ����û������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
			homeparms	�������
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxReadHomeParms(uint16 cardid,uint16 axis,struct_home_config_parms *homeparms);
/*ָ��ܣ���ȡ�������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];			
���������  *homeparms	�������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxConfigHomeEncoderFactor(uint16 cardid,uint16 axis,double factor);
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
PLT_API short __stdcall Plt_AxReadHomeEncoderFactor(uint16 cardid,uint16 axis,double *factor);
/*ָ��ܣ���ѯ����������
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];			
���������  *factor	����������
���أ�      0�������*/
PLT_API short __stdcall Plt_AxHomeMove(uint16 cardid,uint16 axis,uint16 homedir);
/*ָ��ܣ����������˶�
���������  cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
			homedir	���㷽��0��������1��������
���������  ��
���أ�      0�������*/
PLT_API short __stdcall Plt_AxCheckHomeDone(uint16 cardid,uint16 axis,uint16 *done_flag);
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
PLT_API short __stdcall Plt_AxSetHomeSearchDistance(uint16 cardid,uint16 axis,double home_distance);
/*ָ��ܣ����û����������룬����������뵽�ﻹû���ҵ�ԭ�㣬���˶�����ֹͣ ֹͣԭ�������24
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
			home_distance �������� ��λ��ppu
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetHomeSearchDistance(uint16 cardid,uint16 axis,double *home_distance);
/*ָ��ܣ���ѯ�����������룬����������뵽�ﻹû���ҵ�ԭ�㣬���˶�����ֹͣ ֹͣԭ�������24
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
  ���������*home_distance �������� ��λ��ppu
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetHomeStopDelayTime(uint16 cardid,uint16 axis,uint32 delay_time);
/*ָ��ܣ����û���������˶�ֹͣ����ʱdelay_time�������������˶���
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
		    delay_time ��ʱʱ�� ����λ ms 
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetHomeStopDelayTime(uint16 cardid,uint16 axis,uint32 *delay_time);
/*ָ��ܣ���ȡ����������˶�ֹͣ����ʱʱ�䡣
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
  ���������delay_time ��ʱʱ�� ����λ ms 
  ���أ�      0�������*/

PLT_API short __stdcall Plt_AxSetHomeBackDistance(uint16 cardid,uint16 axis,double back_distance);
/*ָ��ܣ����û��㷴��ʱ����ԭ���Ļ��˾���
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
			back_distance �������� ��λ��ppu
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetHomeBackDistance(uint16 cardid,uint16 axis,double *back_distance);
/*ָ��ܣ��ض����㷴��ʱ����ԭ���Ļ��˾���
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
  ���������*back_distance �������� ��λ��ppu
  ���أ�      0�������*/
/*************************************************************************���㹦��*********************************************************/


/*************************************************************************���ֹ���*********************************************************/
typedef struct
{ 
  uint16 handwheelmode;//��������ģʽ��0�������ź�����ģʽ��1������+��������ģʽ��
  double radio;//���ֱ���;radio <0  ������  radio >0 ������
}struct_handwheel_config_parms;//�������ò���
PLT_API short __stdcall Plt_AxConfigHandwheelParms(uint16 cardid,uint16 axis,struct_handwheel_config_parms hwparms);	
/*ָ��ܣ����������˶�����
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			hwparms	�������ò���
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxReadHandwheelParms(uint16 cardid,uint16 axis,struct_handwheel_config_parms *hwparms);	//��ȡ�������������źŵĹ�����ʽ
/*ָ��ܣ���ȡ��������
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
  ���������*hwparms	�������ò���
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetHandwheelPosition(uint16 cardid,uint16 axis,double pos);//�������ֵ�ǰλ��
/*ָ��ܣ���������λ��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			pos	    λ��ֵ
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetHandwheelPosition(uint16 cardid,uint16 axis,double *pos);
/*ָ��ܣ���ȡ����λ��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	
  ���������*pos	    λ��ֵ
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxHandwheelMove(uint16 card,uint16 axis);
/*ָ��ܣ����������˶�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetHandwheelChannal(uint16 cardid,uint16 handwheelchannal);

PLT_API short __stdcall Plt_AxGetHandwheelInputState(uint16 cardid,uint16 *input_state);
/*ָ��ܣ���ȡ���ֶ��ӿ����ź�����״̬
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
  ���������input_state �� bit0: ��0��ѡ�����ź�״̬ bit1: ��1��ѡ�����ź�״̬ bit2: ��2��ѡ�����ź�״̬ bit3: ��3��ѡ�����ź�״̬
                           bit4: 1�����������ź�״̬ bit5: 10�����������ź�״̬ bit6: 100�����������ź�״̬
						   bit7: ���ּ�ͣ�����ź�״̬
  ���أ�      0�������*/
/*************************************************************************���ֹ���*********************************************************/



/*************************************************************************JOG�͵�λ�˶�����*********************************************************/
typedef struct
{
   double start_vel;     //��ʼ�ٶȣ���λ����ppu/s�� ;ȡֵ��Χ��0,4000000/PPU��
   double max_vel;       //����ٶȣ���λ����ppu/s��;ȡֵ��Χ(0,4000000/PPU��
   double end_vel;       //ֹͣ�ٶȣ���λ����ppu/s��;ȡֵ��Χ��0,4000000/PPU��
   double acc;           //���ٶ�,��λ��[ppu/s2];ȡֵ��Χ(0,4000000000/ppu]
   double dec;           //���ٶ�,��λ��[ppus/s2];ȡֵ��Χ(0,4000000000/ppu]
}struct_vel_plan_parms;//�ٶȹ滮����
//�ٶȲ������ã�
PLT_API short __stdcall Plt_AxSetSmoothFactor(uint16 cardid,uint16 axis,double smooth_factor);
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
PLT_API short __stdcall Plt_AxGetSmoothFactor(uint16 cardid,uint16 axis,double *smooth_factor);
/*ָ��ܣ������ٶ����ߵ�S����ϵ��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];  
  ���������*smooth_factor	����S�α���ϵ����ȡֵ��Χ :[0,1] 
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetSProfileMode(uint16 cardid,uint16 axis,uint16 SProfileMode);
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
PLT_API short __stdcall Plt_AxGetSProfileMode(uint16 cardid,uint16 axis,uint16 *SProfileMode);
/*ָ��ܣ�����S���ٶ����߹滮ģʽ(�ú������Զ����˶���Ч)
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];		    
  ���������SProfileMode	0����ʽ�滮ģʽ   1��T���ٶ�����+�˲�ģʽ
      ˵������SProfileModeȡ0ʱ��Plt_AxSetSmoothFactor�����еĲ���smooth_factor��ʾS�����ٶ�ƽ������ϵ����û������λ��
	        ��SProfileModeȡ1ʱ��Plt_AxSetSmoothFactor�����еĲ���smooth_factor��ʾ�˲�ʱ�䣬��λ��s,ȡֵ��Χ[0,1]
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetvelParms(uint16 cardid,uint16 axis,struct_vel_plan_parms axisplanparms);
/*ָ��ܣ������ٶ����ߵĹ滮����
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
		    axisplanparms	�ٶȹ滮����
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxGetvelParms(uint16 cardid,uint16 axis,struct_vel_plan_parms *axisplanparms);
/*ָ��ܣ������ٶ����߹滮����
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];	    
  ���������*axisplanparms	�ٶȹ滮����
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxMoveRel(uint16 cardid,uint16 axis,double dist);	
/*ָ��ܣ���ʼ��λ�˶����˶�һ��dist���룩
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			dist	��λ�˶��ľ��룬��λ��PPU distȡֵ��Χ����2147483640/ppu,-2147483640/ppu�� ע�⣺��dist���ϵ�ǰ�Ĵ���ֵ������Χ��2147483640/ppu,-2147483640/ppu�����ᱨ��
  ���������*axisplanparms	�ٶȹ滮����
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxMoveAbs(uint16 cardid,uint16 axis,double position);	
/*ָ��ܣ���ʼ��λ�˶����˶���positionλ�ã�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			position	��λ�˶���Ŀ��λ�ã���λ��PPU positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu��
  ���������*axisplanparms	�ٶȹ滮����
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxChangeVelMoveRel(uint16 cardid,uint16 axis,double change_vel,double start_change_vel_dist,double end_change_vel_dist,double dist);
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
PLT_API short __stdcall Plt_AxChangeVelMoveAbs(uint16 cardid,uint16 axis,double change_vel,double start_change_vel_pos,double end_change_vel_pos,double position);	// 
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
PLT_API short __stdcall Plt_AxMoveVel(uint16 cardid,uint16 axis,uint16 direction);	//ָ�����������˶�
/*ָ��ܣ�����JOG�˶�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			direction	JOG�˶��ķ���0��������1��������.ָ��λ�����ӵķ���Ϊ�������෴��Ϊ������
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxChangeTartetPos(uint16 cardid,uint16 axis,double position);
/*ָ��ܣ������иı�Ŀ��λ�ã�ԭ����Ŀ��λ���ټ���һ��position���룩
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			position	���߱�λ�˶�����λ�ã���λ��PPU positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu�����ģʽ���߱�λ
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxChangeTartetPosAbs(uint16 cardid,uint16 axis,double position);
/*ָ��ܣ������иı�Ŀ��λ�ã��µ�Ŀ��λ��Ϊposition��
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			position	���߱�λ�˶�����λ�ã�����λ�����꣩����λ��PPU positionȡֵ��Χ����2147483640/ppu,-2147483640/ppu������ģʽ���߱�λ
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxChangeVel(uint16 cardid,uint16 axis,double maxvel); //maxvelȡֵ��Χ��[-4000000/PPU,4000000/PPU]
/*ָ��ܣ������иı��ٶ�
  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
			axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                    EI800ȡֵ��Χ:[0,7];
                    EIC00ȡֵ��Χ:[0,11];
			maxvel	���߱��ٺ��µ�����ٶȣ���λ��PPU/s
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxChangeTartetPosMaxVelAcc(uint16 cardid,uint16 axis,double position,uint16 pos_mode,double max_vel,double acc,double dec);
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

PLT_API short __stdcall Plt_AxMoveRelAndSoftLanding(uint16 cardid,uint16 axis,double soft_landing_vel,double soft_landing_dist,double aim_dist);
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
PLT_API short __stdcall Plt_AxMoveAbsAndSoftLanding(uint16 cardid,uint16 axis,double soft_landing_vel,double soft_landing_pos,double aim_pos);
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
PLT_API short __stdcall Plt_TakingMaterisSetAxisParms(uint16 cardid,uint16 crd,uint16 wait_input_num,uint16 wait_input_logic,uint16 *axis,double ratio_1,double ratio_2);
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
PLT_API short __stdcall Plt_TakingMaterisGetAxisParms(uint16 cardid,uint16 crd,uint16 *wait_input_num,uint16 *wait_input_logic,uint16 *axis,double *ratio_1,double *ratio_2);
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
PLT_API short __stdcall Plt_TakingMaterisSetvelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms *axisplanparms,double change_vel);
//ָ��ܣ�ȡ�����˶��ٶȲ�������
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//            crd �������
//			axisplanparms[0] ��һ���˶�(����/�½�)�ٶȲ���
//			axisplanparms[1] �ڶ����˶�(XYƽ�ƺ�������ת)���ٶȲ���
//			axisplanparms[2] �������˶�(�½�/����)�ٶȲ���
//			change_vel:���߱����ٶ�
//  �����������
//  ���ز�����������
PLT_API short __stdcall Plt_TakingMaterisGetvelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms *axisplanparms,double *change_vel);
//ָ��ܣ���ȡȡ�����˶��ٶȲ�������
//  ���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//            crd �������
//���������axisplanparms[0] ��һ���˶�(����/�½�)�ٶȲ���
//			axisplanparms[1] �ڶ����˶�(XYƽ�ƺ�������ת)���ٶȲ���
//			axisplanparms[2] �������˶�(�½�/����)�ٶȲ���
//			change_vel:���߱����ٶ�
//  ���ز�����������
PLT_API short __stdcall Plt_TakingMaterisMoveAbs(uint16 cardid,uint16 crd,double pos_0,double *pos_1,double *pos_2,double *pos_3,double pos_4,double pos_5,uint16 motion_mode);
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
PLT_API short __stdcall Plt_TakingMaterisChangePosAbs(uint16 cardid,uint16 crd,double *pos);
//ָ��ܣ�ȡ���Ͼ����˶�
//���������cardid ���ţ�ȡֵ��Χ:[0,11]��
//          crd �������
//			  pos ���߱�λX/Y/R�����λ��
//�����������
//���ز�����0�������
/*************************************************************************ȡ/�����˶�����*********************************************************/

/*************************************************************************ֹͣ����*********************************************************/

PLT_API short __stdcall Plt_AxMotionStop(uint16 cardid,uint16 axis,uint16 stop_mode); //ָ���˶���ֹͣ 0������ֹͣ 1������ֹͣ
/*ָ��ܣ�ָֹͣ����
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
            stop_mode	ֹͣģʽ  0������ֹͣ 1������ֹͣ
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_CardMotionEmgStop(uint16 cardid);	
/*ָ��ܣ�ֹͣ������
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall Plt_AxSetStopAcc(uint16 cardid,uint16 axis,double Acc);
/*ָ��ܣ����ü���ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
            Acc  	����ֹͣ���ٶ�
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall  Plt_AxGetStopAcc(uint16 cardid,uint16 axis,double *Acc);
/*ָ��ܣ��ض�����ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
  ���������*Acc  	����ֹͣ���ٶ�
  ���أ�      0�������*/
  PLT_API short __stdcall Plt_AxSetUseStopAccFlag(uint16 cardid,uint16 axis,uint16 use_stop_acc_flag);
/*ָ��ܣ����ü���ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
            use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall  Plt_AxGetUseStopAccFlag(uint16 cardid,uint16 axis,uint16 *use_stop_acc_flag);
/*ָ��ܣ��ض�����ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
   ������� *use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
  ���أ�      0�������*/
/*************************************************************************ֹͣ����*********************************************************/

/*************************************************************************�ݾಹ������*********************************************************/
PLT_API short __stdcall Plt_AxEnableLeadScrewComp(uint16 cardid,uint16 axis,uint16 mode);  
/*ָ��ܣ�ʹ��/��ʹ���ݾಹ������
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];
			mode: 1��ʾʹ�ܣ�0��ʾ��ֹ�� 
  �����������
  ���ز�����0�������*/
PLT_API short __stdcall Plt_AxGetEnableLeadScrewComp(uint16 cardid,uint16 axis,uint16 *mode); 
/*ָ��ܣ���ѯ�ݾಹ����ʹ��״̬
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7];EIC00ȡֵ��Χ:[0,11];	
  ���������*mode: 1��ʾʹ�ܣ�0��ʾ��ֹ�� 
  ���ز�����0�������*/
PLT_API short __stdcall Plt_AxSetLeadScrewComp(uint16 cardid,uint16 axis,uint16 n,int32 startPos,int32 lenPos,int32 *pCompPos,int32 *pCompNeg);  
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
typedef struct
{ 
  uint16 dimension;//����ϵά����EI400\EI400Sȡֵ��Χ:[0,3];EI800ȡֵ��Χ:[0,7]��EIC00ȡֵ��Χ:[0,11];
  uint16 intermode;//�����岹ģʽ��0����ͨ�����岹��1��ǰհģʽ�����岹;2������
}struct_crd_config_parms;//����ϵ���ò���
PLT_API short __stdcall Plt_CrdConfigCrd(uint16 cardid,uint16 crd,struct_crd_config_parms crdparms,uint16 *Axismaparray);
/*ָ��ܣ���������ϵ
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			crdparms	����ϵ���ò���
			*Axismaparray	����ϵ����б������ɲ���crdparms�е�����ϵά��������
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdGetCrd(uint16 cardid,uint16 crd,struct_crd_config_parms *crdparms,uint16 *Axismaparray);
/*ָ��ܣ���ȡ����ϵ���ò���
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
���������	*crdparms	����ϵ���ò���
			*Axismaparray	����ϵ����б������ɲ���crdparms�е�����ϵά��������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdResetCrd(uint16 cardid,uint16 crd);
/*ָ��ܣ�ע������ϵ
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdClearCrdBuf(uint16 cardid,uint16 crd);
/*ָ��ܣ��������ϵ������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufMoveStart(uint16 cardid,uint16 crd);
/*ָ��ܣ���������ϵ�˶�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufMovePause(uint16 cardid,uint16 crd);
/*ָ��ܣ���ͣ����ϵ�˶�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufMoveStop(uint16 cardid,uint16 crd,uint16 stop_mode);
/*ָ��ܣ�ֹͣ����ϵ�˶�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
�����������
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdSetOpenSwitchAdvanceTime(uint16 cardid,uint16 crd,double time);
/*ָ��ܣ�������ǰ����ʱ�䣬�˺��������ڽ�������ϵǰ���� 
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			time ��ǰ����/�ؽ�ʱ�� ��λ��ms
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdGetOpenSwitchAdvanceTime(uint16 cardid,uint16 crd,double *time);
/*ָ��ܣ��ض���ǰ����ʱ�䣬�˺��������ڽ�������ϵǰ���� 
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
���������time ��ǰ����/�ؽ�ʱ�� ��λ��ms
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdSetStopAcc(uint16 cardid,uint16 crd,double Acc);
/*ָ��ܣ���������ϵ����ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
            Acc  	����ֹͣ���ٶ�
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall  Plt_CrdGetStopAcc(uint16 cardid,uint16 crd,double *Acc);
/*ָ��ܣ��ض�����ϵ����ֹͣר�ü��ٶ�(�����ڰ����������ֹͣ����λ�������쳣�������ֹͣ)
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
             crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
  ���������*Acc  	����ֹͣ���ٶ�
  ���أ�      0�������*/
  PLT_API short __stdcall Plt_CrdSetUseStopAccFlag(uint16 cardid,uint16 crd,uint16 use_stop_acc_flag);
/*ָ��ܣ���������ϵ����ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
            use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
  �����������
  ���أ�      0�������*/
PLT_API short __stdcall  Plt_CrdGetUseStopAccFlag(uint16 cardid,uint16 crd,uint16 *use_stop_acc_flag);
/*ָ��ܣ��ض�����ϵ����ֹͣʱ�Ƿ�ʹ�ü���ֹͣר�ü��ٶȱ�־
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
   ������� *use_stop_acc_flag  	1��ʹ�ü���ֹͣר�ü��ٶ� 0��ʹ��Plt_AxSetvelParms�������õļ��ٶȡ�Ĭ��Ϊ0
  ���أ�      0�������*/

PLT_API short __stdcall  Plt_CrdBufGetSpace(uint16 cardid,uint16 crd,long *crdspace);
/*ָ��ܣ���ѯ�岹������ʣ��ռ�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
���������*crdspace	������ʣ��ռ�
����ֵ��0�������*/
PLT_API short __stdcall  Plt_CrdBufGetRunningSegment(uint16 cardid,uint16 crd,long *CurSegment);
/*ָ��ܣ���ѯ��ǰ���жκ�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
���������*CurSegment	�����˶��Ķκ�
����ֵ��0�������*/
PLT_API short __stdcall  Plt_CrdBufGetRemainVectorLengthRatio(uint16 cardid,uint16 crd,double *ratio);
/*ָ��ܣ���ȡʣ��岹ʸ�����Ȱٷֱ�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
���������  *ratio ʣ��岹ʸ�����Ȱٷֱ�
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufChangeSpeed(uint16 cardid,uint16 crd,double ratio);
/*ָ��ܣ����߸ı��ٶ�
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			ratio	���ʣ�ȡֵ��Χ:[0,10]��
��������� ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufSetSmoothFactor(uint16 cardid,uint16 crd,double smooth_factor);
/*ָ��ܣ�����S�α�������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			smooth_factor	S�α�������,��Χ��[0,1]
��������� ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufGetSmoothFactor(uint16 cardid,uint16 crd,double *smooth_factor);
/*ָ��ܣ���ȡS�α�������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
��������� *smooth_factor	S�α�������,��Χ��[0,1]
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufSetVelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms bufvelparms);
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
PLT_API short __stdcall Plt_CrdBufGetVelParms(uint16 cardid,uint16 crd,struct_vel_plan_parms *bufvelparms);
/*ָ��ܣ���ȡ����ϵ�ٶȲ���
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
��������� *bufvelparms	�ٶȹ滮����
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufSetTrajectoryError(uint16 cardid,uint16 crd,double TrajectoryError);
/*ָ��ܣ���������Ĺ켣������ǰհģʽ����Ч��
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			TrajectoryError	����Ĺ켣���ֵ����λ��PPU��
��������� ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufGetTrajectoryError(uint16 cardid,uint16 crd,double *TrajectoryError);
/*ָ��ܣ���ѯ����Ĺ켣������ǰհģʽ����Ч��
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��			
��������� *TrajectoryError	����Ĺ켣���ֵ����λ��PPU��
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufSetMaxTransitAcc(uint16 cardid,uint16 crd,double MaxTransitAcc);
/*ָ��ܣ�������������Ӽ��ٶȣ�����ǰհģʽ����Ч��
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			MaxTransitAcc	����������ٶȣ���λ��[ppu/s2]��
��������� ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufGetMaxTransitAcc(uint16 cardid,uint16 crd,double *MaxTransitAcc);
/*ָ��ܣ���ѯ��������Ӽ��ٶȣ�����ǰհģʽ����Ч��
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
��������� *MaxTransitAcc	����������ٶȣ���λ��[ppu/s2]��
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdBufSetFollowAxis(uint16 cardid,uint16 crd,uint16 follow_axis_num,uint16 *axis_list);
/*ָ��ܣ���������ϵ������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
			follow_axis_num	���������
			axis_list ����ϵ�и�������� ȡֵ�� 0:��ʾ����ϵX�� 1����ʾ����ϵY�� 2����ʾ����ϵZ�� 3����ʾ����ϵU�� 4����ʾ����ϵV�� 5����ʾ����ϵW��
��������� ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufGetFollowAxis(uint16 cardid,uint16 crd,uint16 *follow_axis_num,uint16 *axis_list);
/*ָ��ܣ���ȡ����ϵ����������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��
���������  follow_axis_num	���������
		    axis_list ����ϵ�и�������� ȡֵ�� 0:��ʾ����ϵX�� 1����ʾ����ϵY�� 2����ʾ����ϵZ�� 3����ʾ����ϵU�� 4����ʾ����ϵV�� 5����ʾ����ϵW��
����ֵ��    0�������*/

PLT_API short __stdcall Plt_CrdBufMoveLinerRel(uint16 cardid,uint16 crd,uint16 axis_num,double* targetpos_array,uint32 segnum);
/*ָ��ܣ�ֱ�߲岹������˶���
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��		
           axis_num	����ֱ�߲岹����
           *targetpos_array	����ֱ�߲岹��������λ�ƣ���λ��PPU��
           segnum	�κ�
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufMoveLinerAbs(uint16 cardid,uint16 crd,uint16 axis_num,double* targetpos_array,uint32 segnum);
/*ָ��ܣ�ֱ�߲岹�������˶���
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            axis_num ����
            targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
            segnum �κ�
�����������
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdBufMoveLinerRelMulti_XYZ(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* targetpos_array_z,double* max_vel,double* acc);
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
PLT_API short __stdcall Plt_CrdBufMoveLinerAbsMulti_XYZ(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* targetpos_array_z,double* max_vel,double* acc);
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

PLT_API short __stdcall Plt_CrdBufMoveLinerRelMulti_XY(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* max_vel,double* acc);
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
PLT_API short __stdcall Plt_CrdBufMoveLinerAbsMulti_XY(uint16 cardid,uint16 crd,uint16 line_num,double* targetpos_array_x,double* targetpos_array_y,double* max_vel,double* acc);
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

typedef struct
{
  uint16 axis_num;//�岹����
  uint16 direction;//Բ������0��˳ʱ�룻1����ʱ�룻
  uint16 cirnum;//Բ��Ȧ��
  uint16 plane;//Բ�����ĸ�ƽ�棻0��XYƽ�棻1��YZƽ�� 2��XZƽ��
  uint16 mode;//λ��ģʽ��0�����λ��ģʽ��1������λ��ģʽ
}struct_center_cir_parms;//Բ���յ㷽ʽԲ������

PLT_API short __stdcall Plt_CrdBufMoveCenterCircular(uint16 cardid,uint16 crd,struct_center_cir_parms cencirparms,double *targetpos_array,double *cenpos_array,uint32 segnum);
/*ָ��ܣ�Բ���յ�ģʽԲ���岹 
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            cencirparms Բ���յ㷽ʽԲ������
			cenpos_arrayԲ�������б�
            targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
            segnum �κ�
�����������
����ֵ��0�������*/
typedef struct
{
  double radius;//Բ���뾶����λ����ppu��
  uint16 axis_num;//�岹����
  uint16 direction;//Բ������0��˳ʱ�룻1����ʱ�룻
  uint16 cirnum;//Բ��Ȧ��
  uint16 plane;//Բ�����ĸ�ƽ�棻0��XYƽ�棻1��YZƽ�� 2��XZƽ��
  uint16 mode;//λ��ģʽ��0�����λ��ģʽ��1������λ��ģʽ
}struct_radius_cir_parms;//�յ�뾶Բ������

PLT_API short __stdcall Plt_CrdBufMoveRadiusCircular(uint16 cardid,uint16 crd,struct_radius_cir_parms radcirparms,double *targetpos_array,uint32 segnum);
/*ָ��ܣ��յ�뾶ģʽԲ���岹 
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            radcirparms �յ�뾶Բ������
            targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
            segnum �κ�
�����������
����ֵ��0�������*/
typedef struct
{
  uint16 axis_num;//�岹����
  uint16 direction;//Բ������0��˳ʱ�룻1����ʱ�룻�˲�����Ч
  uint16 cirnum;//Բ��Ȧ��
  uint16 plane;//Բ�����ĸ�ƽ�棻0��XYƽ�棻1��YZƽ�� 2��XZƽ�� 3:�ռ�Բ��
  uint16 mode;//λ��ģʽ��0�����λ��ģʽ��1������λ��ģʽ
}struct_3point_cir_parms;//3��Բ������

PLT_API short __stdcall Plt_CrdBufMove3PointCircular(uint16 cardid,uint16 crd,struct_3point_cir_parms pointscirparms,double *targetpos_array,double *midpos_array,uint32 segnum);
/*ָ��ܣ�����ģʽԲ���岹 
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            radcirparms pointscirparms
			midpos_array �м��λ���б�
            targetpos_array Ŀ��λ���б���Ŀ��λ����ӳ��������ϵ��Ŀ��λ��
            segnum �κ�
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufDelay(uint16 cardid,uint16 crd,double time,uint32 segnum);//�岹��ʱ,��λ��[ms]
/*ָ��ܣ�������ʱ
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            time	��ʱʱ�䣨��λ��ms��
            segnum �κ�
�����������
����ֵ��0�������*/

typedef struct
{
  uint16 input_num;//����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
  uint16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  double check_time;//checkʱ��,��λ��[ms]
}struct_buf_check_input_parms;
PLT_API short __stdcall Plt_CrdBufCheckInput(uint16 cardid,uint16 crd,struct_buf_check_input_parms inputparms,uint32 segnum);
/*ָ��ܣ��ȴ�����IO
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            inputparms    ����IO����
            segnum �κ�
�����������
����ֵ��0�������*/

typedef struct
{
  uint16 output_num;//���io�ţ�EI800\EIC00 0-15 EI400S 0-31
  uint16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  double check_time;//checkʱ��,��λ��[ms]
}struct_buf_check_output_parms;//������ͨ�����IO����
PLT_API short __stdcall Plt_CrdBufCheckOutput(uint16 cardid,uint16 crd,struct_buf_check_output_parms outputparms,uint32 segnum);
/*ָ��ܣ��������ȴ����IO
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            outputparms    ���IO����
            segnum �κ�
�����������
����ֵ��0�������*/

typedef struct
{
  uint16 io_mode;//���������ioģʽ��//0���趨io��������趨��ƽ��1���趨io�ͺ��趨��������趨��ƽ��2���趨io�ͺ��趨ʱ������趨��ƽ 3:���趨io��ǰ�趨��������趨��ƽ
  uint16 output_num;//���io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
  uint16 active_level;//��Ч��ƽ��0���͵�ƽ��Ч��1���ߵ�ƽ��Ч
  double actionparm;//ʱ�䣨��λ��ms����������(��λ��ppu)
  double holdtime;//�趨��ƽ����ʱ��,��λ��[ms]
}struct_buf_out_io_parms;//������ͨ�����IO����
PLT_API short __stdcall Plt_CrdBufSetOutput(uint16 cardid,uint16 crd,struct_buf_out_io_parms outputparms,uint32 segnum);
/*ָ��ܣ����������IO
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            outputparms    ���IO����
            segnum �κ�
�����������
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdBufBlank(uint16 cardid,uint16 crd,uint32 segnum);
/*ָ��ܣ���������ָ��
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            segnum �κ�
�����������
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdBufClearIoAction(uint16 cardid,uint16 crd,uint32 io_mask,uint32 segnum);
/*ָ��ܣ����IO���� 
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
            io_mask ��Ҫ��������IO�ţ���0-15BIT��Ӧ0-15�����IO 1����ʾ��� 0����ʾ������
            segnum �κ�
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufOpenSwitchAdvance(uint16 cardid,uint16 crd,double* pos,uint16 active_level);
/*
ָ��ܣ��������ۿ���/�ؽ�λ��
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
           crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		   pos      ���۱Ƚ�λ��(X�������Y������ֵ)
		   active_level  �Ƚ������Ч��ƽ
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufOpenSwitchAdvanceMulti(uint16 cardid,uint16 crd,uint32 pos_num,double* pos_x,double* pos_y,uint16 active_level);
/*
ָ��ܣ��������ۿ���/�ؽ�λ��
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
           crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		   pos_num  ��ӱȽϵ����,һ�����������42���Ƚϵ� ȡֵ��Χ[1,42]
		   pos_x    ���۱Ƚ�X��λ��
		   pos_y    ���۱Ƚ�Y��λ��
		   active_level  �Ƚ������Ч��ƽ
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufSwitchRemainSpace(uint16 cardid,uint16 crd,uint32 *space);
/*
ָ��ܣ���ȡ����/�ؽ�λ��ʣ�໺��������
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
           crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
���������space ʣ�໺����
����ֵ��0�������*/

PLT_API short __stdcall Plt_CrdBufSwitchClear(uint16 cardid,uint16 crd);
/*
ָ��ܣ���ȡ����/�ؽ�λ��ʣ�໺��������
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
           crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
���������space ʣ�໺����
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufCompareSetStartLength(uint16 cardid,uint16 crd,double offset_length,uint16 active_level);
/*ָ��ܣ����þ��Ծ���ģʽ����/�ؽ���ʼλ��
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
           crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��
		   offset_length ��ǰλ�õ�ƫ�ƹ켣���ȣ�ȡֵ���ڵ�����
		   active_level  ��ʼλ�������ƽ
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufCompareAddLengthMulti(uint16 cardid,uint16 crd,uint32 pos_num,double* length,uint16 active_level);
/*
ָ��ܣ�ͬʱ��Ӷ�����Ծ���ģʽ����/�ؽ�λ��
��������� cardid	���ţ�ȡֵ��Χ:[0,11]��
           crd	    ����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		   pos_num  ��ӱȽϵ����,һ�����������42���Ƚϵ� ȡֵ��Χ[1,42]
		   length   ��Կ�ʼ��� ���Ծ��룬ȡֵ���ڵ�����
		   active_level  �Ƚ������Ч��ƽ
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufDistanceOutPut(uint16 cardid,uint16 crd,struct_crd_accurate_compare_parms compare_parms_2d,double start_length_ratio,double end_length_ratio,uint32 output_num,uint32 segnum);
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
PLT_API short __stdcall Plt_CrdBufDistanceOutPutConti(uint16 cardid,uint16 crd,struct_crd_accurate_compare_parms compare_parms_2d,uint16 enable_flag,double distance,uint32 segnum);
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
PLT_API short __stdcall Plt_CrdBufAxMoveRel(uint16 cardid,uint16 crd,uint16 axis,double dist,uint16 mode,uint32 segnum);
/*
ָ��ܣ�����������ϵ������趨�����ģʽ�˶�
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
		  axis ��
		  mode��0�� ���������趨���˶���ɺ���ܼ����������岹�˶�:1�����������������趨���˶�������������岹�˶�
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufAxMoveAbs(uint16 cardid,uint16 crd,uint16 axis,double dist,uint16 mode,uint32 segnum);
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
PLT_API short __stdcall Plt_AxGetMotionStatus(uint16 cardid,uint16 axis,uint16 *motionstatus);	
/*ָ��ܣ���ȡָ������˶�״̬
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                      EI800ȡֵ��Χ:[0,7];
                      EIC00ȡֵ��Χ:[0,11];
���������*motionstatus	���˶�״̬��0���˶��У�1��ֹͣ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_AxGetStatus(uint16 cardid,uint16 axis,uint16* mode,uint16 *stopreason);
/*ָ��ܣ���ȡ���˶�ģʽ��ֹͣԭ��
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                      EI800ȡֵ��Χ:[0,7];
                      EIC00ȡֵ��Χ:[0,11];
���������*status	���˶�ģʽ��0�����У�1����λ�˶���2��JOG�˶���3�������˶���4�������˶���5�������岹�˶���
          *stopreason ֹͣԭ��
����ֵ��0�������*/
PLT_API short __stdcall Plt_AxGetMotionSpeed(uint16 cardid,uint16 axis,double *motionspeed);//��ȡ�����ٶ�
/*ָ��ܣ���ȡָ������˶��ٶ�
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                      EI800ȡֵ��Χ:[0,7];
                      EIC00ȡֵ��Χ:[0,11];
���������*motionspeed	�ٶ�ֵ����λ:PPU/s
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdGetMotionSpeed(uint16 cardid,uint16 crd,double *motionspeed);
/*ָ��ܣ���ȡָ������˶��ٶ�
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
���������*motionspeed	����ϵ���ٶ�ֵ����λ:PPU/s
����ֵ��0�������*/
PLT_API short __stdcall Plt_AxClearStatus(uint16 cardid,uint16 axis);
/*ָ��ܣ����ֹͣԭ��
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          axis	��ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                      EI800ȡֵ��Χ:[0,7];
                      EIC00ȡֵ��Χ:[0,11];
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdBufGetStatus(uint16 cardid,uint16 crd,uint16 *crdstatus);
/*ָ��ܣ���ȡ�岹�˶�������ϵ״̬
���������cardid	���ţ�ȡֵ��Χ:[0,11]��
          crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
���������*crdstatus	����ϵ״̬��4:�ͷ� 3��������0���˶���1����ͣ 2��ֹͣ��5���쳣��
����ֵ��0�������*/
//��������ϵ��λ���
PLT_API short __stdcall Plt_CrdSetBand(uint16 cardid,uint16 crd,double *band,uint32 *hold_time,uint32 *check_time);
/*ָ��ܣ���������ϵ�ᵽλ���
���������  cardid ����
            crd �岹ϵ��
            *band ������С���� ��ÿ����������� ��λ�� ppu 
			*hold_time ���巢����Ϻ���������ͱ���������ƫ�����ֵ������������ʱ��  ÿ������ı���ʱ�����飬��λ��ms
            check_time  ���巢����Ϻ���������ͱ���������ƫ�����ֵ�����������ʱ�� ÿ������ļ��ʱ�����飬��λ��ms
�����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdGetBand(uint16 cardid,uint16 crd,double *band,uint32 *hold_time,uint32 *check_time);
/*ָ��ܣ���ѯ����ϵ�ᵽλ�������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
���������  *band ������С���� ��ÿ����������� ��λ�� ppu 
			*hold_time ���巢����Ϻ���������ͱ���������ƫ�����ֵ������������ʱ��  ÿ������ı���ʱ�����飬��λ��ms
            check_time  ���巢����Ϻ���������ͱ���������ƫ�����ֵ�����������ʱ�� ÿ������ļ��ʱ�����飬��λ��ms
����ֵ��0�������*/
PLT_API short __stdcall Plt_CrdGetBandFlag(uint16 cardid,uint16 crd,uint16 *band_flag);
/*ָ��ܣ���ȡ�������
���������  cardid	���ţ�ȡֵ��Χ:[0,11]��
            crd	����ϵ�ţ�ȡֵ��Χ:[0,1]��	
���������band_flag 1������ϵ������������λ�úͱ�����λ��ƫ�����ֵ�����趨������Χ�ڴ��ڵ����趨�ı���ʱ��
	                0������ϵ�������˶��л��������巢���Ѿ���ϵ�������λ�úͱ�����λ��ƫ�����ֵ�����趨������Χ��С���趨�ı���ʱ��
	                2������ϵ��������һ�������巢���Ѿ���ϵ����������ʱ�䵽ʱ������λ�úͱ�����λ��ƫ�����ֵ�����趨������Χ��С���趨�ı���ʱ��
����ֵ��0�������*/
/*************************************************************************״̬���*********************************************************/
/*************************************************************************����IO����������غ���*********************************************************/
PLT_API short __stdcall  Plt_IoConfigInputCountMode(uint16 cardid,uint16 bitno,uint16 count_mode,double filter_time);
/*ָ��ܣ���������IO����ģʽ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            bitno ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			count_mode ����ģʽ  0����ֹ����IO����  1�������ؼ��� 2���½��ؼ���
			filter_time ����IO�˲�ʱ�� ��λ��ms 
  �����������
����ֵ��0�������*/
PLT_API short __stdcall  Plt_IoReadInputCountMode(uint16 cardid,uint16 bitno,uint16 *count_mode,double *filter_time);
/*ָ��ܣ���ȡIO����ģʽ����
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            bitno ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			
  ���������*count_mode ����ģʽ  0����ֹ����IO����  1�������ؼ��� 2���½��ؼ���
			*filter_time ����IO�˲�ʱ�� ��λ��ms 
����ֵ��0�������*/
PLT_API short __stdcall  Plt_IoSetInputCountValue(uint16 cardid,uint16 bitno,uint32 init_value);
/*ָ��ܣ���������IO������ʼֵ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            bitno ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
			init_value ����io������ʼֵ
  �����������
����ֵ��0�������*/
PLT_API short __stdcall  Plt_IoGetInputCountValue(uint16 cardid,uint16 bitno,uint32 *count_value);
/*ָ��ܣ���ȡ����IO����ֵ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            bitno   ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
   ���������*count_value  ��ǰ����io����ֵ
����ֵ��0�������*/
/*************************************************************************����IO����������غ���*********************************************************/
/*************************************************************************PWM������غ���*********************************************************/
PLT_API short __stdcall Plt_PwmSetPwmEnablFlag(uint16 card,uint16 pwmno,uint16 pwmflag);
/*ָ��ܣ���ȡ����IO����ֵ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
            bitno   ����io�ţ�ȡֵ��Χ��EI400\EI400S:[0,31]��EI800\EIC00:[0,15];
   ���������*count_value  ��ǰ����io����ֵ
����ֵ��0�������*/
PLT_API short __stdcall Plt_PwmGetPwmEnablFlag(uint16 card,uint16 pwmno,uint16 *pwmflag);
PLT_API short __stdcall PLT_SetPwmOutMode(uint16 card, uint16 pwmno,uint16 out_mode);
/*ָ��ܣ�pwm���ģʽ
��������� cardid	���ţ�ȡֵ��Χ:[0,11]�� 
            pwmno  pwmͨ����
			out_mode pwm���ģʽ  0���Ǹ���ģʽ  1������ģʽ
���������  ��
����ֵ��0�������*/
PLT_API short __stdcall PLT_GetPwmOutMode(uint16 card, uint16 pwmno,uint16 *out_mode);
/*ָ��ܣ���ȡPWM���ģʽ
���������  card ����
             pwmno  pwmͨ����
���������  out_mode pwm���ģʽ  0���Ǹ���ģʽ  1������ģʽ
����ֵ��0�������*/
PLT_API short __stdcall PLT_SetPwmOut(uint16 card, uint16 pwmno,double fDuty, double fFre);
PLT_API short __stdcall PLT_GetPwmOut(WORD card,WORD pwmno,double* fDuty, double* fFre);
PLT_API short __stdcall PLT_CrdBufSetPwmOut(uint16 card,uint16 crd,uint16 pwmno,double fDuty, double fFre,uint32 segnum);
PLT_API short __stdcall PLT_CrdBufSetPwmFollowParms(uint16 card,uint16 crd,uint16 pwmno,uint16 follow_mode,double min_power,double max_power,double ratio,double fix_value);
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
PLT_API short __stdcall PLT_CrdBufGetPwmFollowParms(uint16 card,uint16 crd,uint16 pwmno,uint16 *follow_mode,double *min_power,double *max_power,double *ratio,double *fix_value);
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
/*************************************************************************AD����*********************************************************/
PLT_API short __stdcall PLT_AdGetVol(uint16 card,uint16 channal_id,float *vol);
/*ָ��ܣ����������ƽ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
            channal_id  ͨ����:��ЧֵΪ0��1   
            
  ��������� vol �����ѹֵ ��Χ[0,9.9]
����ֵ��0�������*/
/*************************************************************************AD����*********************************************************/
/*************************************************************************DA����*********************************************************/
PLT_API short __stdcall PLT_DaSetEnableFlag(uint16 card,uint16 channal_id,uint16 enable_flag);
/*ָ��ܣ�����DA���ʹ�ܱ�־
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
            channal_id  ͨ����:��ЧֵΪ0��1 
            enable_flag 1��ʹ�� 0����ֹ
  ��������� ��
����ֵ��0�������*/
PLT_API short __stdcall PLT_DaGetEnableFlag(uint16 card,uint16 channal_id,uint16 *enable_flag);
/*ָ��ܣ�����DA���ʹ�ܱ�־
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
            channal_id  ͨ����:��ЧֵΪ0��1   
            
  ���������enable_flag 1��ʹ�� 0����ֹ
����ֵ��0�������*/
PLT_API short __stdcall PLT_DaSetVol(uint16 card,uint16 channal_id,float vol);
/*ָ��ܣ����������ƽ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��  
            channal_id  ͨ����:��ЧֵΪ0��1 
            vol �����ѹֵ ��Χ[0,9.9]
  ��������� ��
����ֵ��0�������*/
PLT_API short __stdcall PLT_DaGetVol(uint16 card,uint16 channal_id,float *vol);
/*ָ��ܣ����������ƽ
  ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
            channal_id  ͨ����:��ЧֵΪ0��1   
            
  ��������� vol �����ѹֵ ��Χ[0,9.9]
����ֵ��0�������*/
/*************************************************************************DA����*********************************************************/
/*************************************************************************CAN�������IO**********************************************************/
PLT_API short __stdcall Plt_IoSetMasterBaudrate(uint16 cardid,uint16 baudrate);
/*ָ��ܣ�����EIX00���ƿ�CANͨѶ������
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]�� 
//            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
//  �����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoGetMasterBaudrate(uint16 cardid,uint16 *baudrate);
/*ָ��ܣ���ȡEIX00���ƿ�CANͨѶ������
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��  
//           
//  ��������� baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanReadInputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level); 	//��ȡָ��canģ������ڵ�״̬
/*ָ��ܣ���ȡָ��canģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
              bitno	����IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//  ���������  *active_level 
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanWriteOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 active_level); 	//����ָ��canģ������ڵ�״̬
/*ָ��ܣ�����ָ��canģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
              bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//			active_level �����ƽֵ  0��1
//  �����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanReadOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level);  	//��ȡָ��canģ������ڵ�״̬
/*ָ��ܣ���ȡָ��canģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
              bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//  ���������  *active_level
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanReadAllInput(uint16 cardid,uint16 can_id,uint32 *active_level_1); 	//��ȡָ��canģ������ͨ������IO��ֵ
/*ָ��ܣ���ȡָ��canģ������ͨ������IO��ֵ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
//            active_level	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31 RCAN32I32O: bit0-bit31λ����Ч��RCAN16I16O: bit0-bit15λ��Ч��
//  ���������  *active_level  active_level˳���0��31����0��31����IO��ƽ
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanReadAllOutput(uint16 cardid,uint16 can_id,uint32 *active_level); 	//��ȡָ��canģ������ͨ������ڵ�ֵ
/*ָ��ܣ���ȡָ��canģ������ͨ�����IO��ֵ
//  �������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
//            bitno IO�ں� ��ЧֵΪ[0,31]
//			  active_level	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31 RCAN32I32O: bit0-bit31λ����Ч��RCAN16I16O: bit0-bit15λ��Ч��
//  �����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanWriteAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	//����ָ��canģ������ͨ������ڵ�ֵ
/*ָ��ܣ�����ָ��canģ����������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
//           active_level	�����0--31��״̬, bit0��ӦIN0��bit31��ӦIN31 RCAN32I32O: bit0-bit31λ����Ч��RCAN16I16O: bit0-bit15λ��Ч��
//  �����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanGetLinkState(uint16 cardid,uint16 can_id,uint16 *link_state);  	//��ȡָ��canģ������״̬
/*ָ��ܣ���ȡָ��canģ������״̬
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��           
//  ���������  *link_state ����״̬ 1������  0���Ͽ�
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanInitAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	
/*ָ��ܣ�����ָ��canģ������ڳ�ʼ��ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
//			active_level  active_level˳���0��31����0��31���IO��ʼ��ƽ
//  �����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanGetNodeType(uint16 cardid,uint16 can_id,uint16 *type);  	
/*ָ��ܣ���ȡָ��canģ��ڵ�����
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
//  ���������type canģ��ڵ�����  1��rcan1616 2:rcan3232
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanGetNodeVersion(uint16 cardid,uint16 can_id,uint16 *version);  	
/*ָ��ܣ���ȡָ��canģ��ڵ�����
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
//  ���������version canģ��ڵ�̼��汾��  
����ֵ��0�������*/
PLT_API short __stdcall Plt_IoCanReverseOutputBit(uint16 cardid,uint16 can_id,uint16 bitno,double hold_time);
/*ָ��ܣ�CANIO��ת
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              can_id	canģ�����, ȡֵ��Χ:[0,7]��
			  bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
			  hold_time ��ת��ƽ����ʱ�� ��λ��s
//  �����������
����ֵ��0�������*/
/*************************************************************************CAN�������IO**********************************************************/

/*************************************************************************����ͬ������**********************************************************/
PLT_API short __stdcall Plt_GantrySetEnable(uint16 cardid,uint16 master_axis_id,uint16 slave_axis_id,uint16 enable_flag);  	
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
PLT_API short __stdcall Plt_GantryGetEnable(uint16 cardid,uint16 master_axis_id,uint16 *slave_axis_id,uint16 *enable_flag);  	
/*ָ��ܣ���ѯ����ʹ����Ƿ��������ͬ����ϵ
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];	  	
//  ������� *enable_flag       ����ʹ����Ƿ�������ͬ����ϵ  1������ 0�����
             *slave_axis_id	    ������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];	
����ֵ��0�������*/

PLT_API short __stdcall Plt_GantrySetParms(uint16 cardid,uint16 master_axis_id,double max_error,double encoder_factor,uint16 stop_mode);  	
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
PLT_API short __stdcall Plt_GantryGetParms(uint16 cardid,uint16 master_axis_id,double *max_error,double *encoder_factor,uint16 *stop_mode);  	
/*ָ��ܣ���ȡ����ͬ���������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];	  
//���������  *max_error	    ����ʹ����������������ƫ���λ��[PPU]
			  *encoder_factor   ���ͬ�����壬��������������ʹ��������������ֵ
			  *stop_mode        ƫ���ֹͣ��ʽ 0������ֹͣ  1������ֹͣ
����ֵ��0�������*/
PLT_API short __stdcall Plt_GantryGetError(uint16 cardid,uint16 master_axis_id,double *cur_error);  	
/*ָ��ܣ���ȡ����ͬ�����鵱ǰ���������ֵ
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              master_axis_id	������ţ�EI400\EI400Sȡֵ��Χ:[0,3];
                                EI800ȡֵ��Χ:[0,7];
                                EIC00ȡֵ��Χ:[0,11];	  
//���������  cur_error	        ����ʹ�������ĵ�ǰ������ƫ���λ��[PPU]
����ֵ��0�������*/
/*************************************************************************����ͬ������**********************************************************/
/*************************************************************************�����ģ��**********************************************************/
PLT_API short __stdcall  Plt_SetBlow(uint16 cardid,uint16 blow_num,uint16 blow_flag,uint32 cur_roll_num);	
/*ָ��ܣ�����/����ָ��
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              blow_num	        ���վվ��   0��CCD1  1��CCD2 2:�հ����ccd
              blow_flag         �� blow_num=0�� 0��OK  1:NG 2:NC �� blow_num=1��0��OK 1������  2��ȱ����  3��Mark��
			  cur_roll_num      ��ǰ����
//���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_get_roller_finish_flag(uint16 cardid,uint16 blow_num,uint16 *flag);
/*������������ȡ��λ��CCD���ռ��������־
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              blow_num	        ���վվ��   0��CCD1  1��CCD2 2:�հ����ccd
//���������  flag              0����Ҫ���  1����Ҫ���
����ֵ��0�������*/
PLT_API short __stdcall  Plt_clear_roller_finish_flag(uint16 cardid,uint16 blow_num);
/*����������֪ͨ��λ����λ��CCD���ռ��������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              blow_num	        ���վվ��   0��CCD1  1��CCD2 2:�հ����ccd
//���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_SetInternetHeartBeat(uint16 cardid,uint32 beat_time);
/*����������������̫��ͨ�ż������ʱ��
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              beat_time         ����ʱ��  ��λ��[s]  ��Сֵ����5s��������õ�ʱ�����0֮�󣬾���ζ�ſ�������̫�����߼�ع��ܣ����������ʱ�����ղ�����λ��
			                    �·������ݣ����ƿ���̫��ģ������³�ʼ����������λ���������´򿪿���
//���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_SetCommand(uint16 cardid,uint32 command_id);
/*����������ͨ����̫���·���������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              command_id        
//���������  ��
����ֵ��0�������*/

PLT_API short __stdcall  Plt_GetTesterFinishFlag(uint16 cardid,uint16 *finish_flag);
/*�������������������Ƿ����һ�β���
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��          
//���������  finish_flag   0:�����ǲ���û�����  1���������
����ֵ��0�������*/
PLT_API short __stdcall  Plt_SampleTest(uint16 cardid);
/*������������������Ʒ��������
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��          
����ֵ��0�������*/
PLT_API short __stdcall  Plt_SetTestDataFinisReadFlag(uint16 cardid);
/*������������λ����ɶ�ȡ�����ǽ������,֪ͨ��λ��
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��          
����ֵ��0�������*/

PLT_API short __stdcall  Plt_AlineCommand(uint16 cardid,uint16 command_id);
/*���������������Զ�У׼����
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              command_id  1:У׼��ʼ   0��У׼����      
//���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_GetAlineRdyFlag(uint16 cardid,uint16 *flag);
/*������������ȡ�豸�Զ�У׼׼��״̬
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��     
//���������  flag 1���Զ�У׼׼����(�����붥��λ) 0���Զ�У׼û��׼����
����ֵ��0�������*/

PLT_API short __stdcall  Plt_GetSystemState(uint16 cardid,uint16 *state);
/*������������ȡ�豸״̬
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��     
//���������  state 1���Զ�״̬  4���ֶ�״̬  3 ����ͣ״̬
����ֵ��0�������*/
PLT_API short __stdcall  Plt_WriteRegister(uint16 cardid,uint32 address,long value);
/*����������д�Ĵ���
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]�� 
             //5049    CCD1����  value = 1����value= 0��
			 //5050    CCD2����  value = 1����value= 0��
			 //3800    1963     ָ��ȱ�ݵ��ﱨ��     
����ֵ��0�������*/
PLT_API short __stdcall  Plt_ReadRegister(uint16 cardid,uint32 address,long *value);
/*�������������Ĵ���
//  ���������cardid	        ���ţ�ȡֵ��Χ:[0,11]��
//���������value
            //5049    CCD1����  value = 1����value= 0��
			//5050    CCD2����  value = 1����value= 0��
����ֵ��0�������*/
/*************************************************************************�����ģ��**********************************************************/
/*************************************************************************RS485��غ���*********************************************************/
PLT_API short __stdcall  Plt_Rs485SetBound(uint16 cardid,uint32 bound);
/*
��������������RS485������
���������cardid ����
          bound ������  �����õĲ����� 9600 19200 38400 
�����������
����ֵ��������  0�����óɹ�  2400����Ч�Ĳ�����ֵ*/
PLT_API short __stdcall  Plt_Rs485GetBound(uint16 cardid,uint32 *bound);
/*
�����������ض�RS485������
���������cardid ����       
���������bound ������
����ֵ��������*/
PLT_API short __stdcall  Plt_Rs485SetDataReceiveTimeOut(uint16 cardid,uint16 time_out);
/*
��������������RS485��վ�豸�յ����ƿ����͵�ָ��󣬿��ƿ��ȴ���վ���ݻش���ʱʱ��
���������cardid ����
          time_out����ʱʱ�� ȡֵ��Χ [10,1000] ��λ��ms
�����������
����ֵ��������  0�����óɹ�  2401����Ч�ĳ�ʱʱ��ֵ*/
PLT_API short __stdcall  Plt_Rs485GetDataReceiveTimeOut(uint16 cardid,uint16 *time_out);
/*
�����������ض�RS485������
���������cardid ����       
���������time_out����ʱʱ�� 
����ֵ��������*/

PLT_API short __stdcall  Plt_Rs485DataExchange(uint16 cardid,uint8 *data_send_buf,uint16 data_send_len,uint8 *data_receive_buf,uint16 *data_receive_len);
/*
����������RS485�������ɸ��ֽ����ݣ�����ȡ��վ���ص�����
���������cardid ����  
          data_send_buf ���͵�RS485��վ������
		  data_send_len ���͵�RS485��վ�����ݳ��ȣ�ȡֵ��Χ[1,100]
���������data_receive_buf����վ���ص�����
          data_receive_len ��վ���ص����ݳ���
����ֵ��������*/
/*************************************************************************RS485��غ���*********************************************************/
/******************************************************************ETHERCAT������غ���*********************************************************/
PLT_API short __stdcall Plt_EthercatDownLoadENIFile(uint16 cardid,const char *filename);
/*ָ��ܣ�����ethercat��վ���������ļ�
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        *filename	�¹̼�����·���� ע�⣺·���в����������ַ�
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatSetNodeOd(uint16 cardid,uint16 slave_id,uint16 Index,uint16 SubIndex,uint16 length,uint32 Value);
/*ָ��ܣ����ô�վ�����ֵ����ֵ
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        slave_id ��վid��
			Index �����ֵ�����
			SubIndex �����ֵ�������
			length �����ֵ���������(��λ�� byte)
			Value �����ֵ���������ֵ
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatGetNodeOd(uint16 cardid,uint16 slave_id,uint16 Index,uint16 SubIndex,uint16 length,uint32 *Value);
/*ָ��ܣ����ô�վ�����ֵ����ֵ
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
	        slave_id ��վid��
			Index �����ֵ�����
			SubIndex �����ֵ�������
			length �����ֵ���������(��λ�� byte)
���������	Value �����ֵ���������ֵ
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatGetSlaveCount(uint16 cardid,uint16 *count);
/*ָ��ܣ���ȡethercat����ϵͳ��վ����
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	count ��վ����
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatGetSlaveAxisCount(uint16 cardid,uint16 *count);
/*ָ��ܣ���ȡethercat����ϵͳ��վ�����
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	count ��վ�����
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatStart(uint16 cardid);
/*ָ��ܣ�����������ethercatģ��
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatStop(uint16 cardid);
/*ָ��ܣ�ֹͣ������ethercatģ��
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatGetSlaveState(uint16 cardid,uint16 slave_id,uint16 *state);
/*ָ��ܣ���ȡethercat��վ״̬
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
            slave_id ��վid��
���������	state ��վ״̬  0��δ��ʼ�� 1����ʼ��״̬ 2��Ԥ����״̬  3������״̬  4����ȫ����״̬  8������״̬  16������״̬
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatGetAxis402State(uint16 cardid,uint16 slave_id,uint16 *state);
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
PLT_API short __stdcall Plt_EthercatClearAxis402Error(uint16 cardid,uint16 slave_id);
/*ָ��ܣ�ethercat��վ״̬�������
���������  cardid	���ţ�ȡֵ��Χ[0,11]��
            slave_id ��վid��
���������	��
���أ�      0�������*/
PLT_API short __stdcall Plt_EthercatGetSlaveInfo(uint16 cardid,uint16 slave_id,uint16 info_type,int8 *info);
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
PLT_API short __stdcall Plt_EthercatIoReadInputByBit(uint16 cardid,uint16 slave_id,uint16 bitno,uint16 *active_level); 	
/*ָ��ܣ���ȡָ��ethercat��վģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
              bitno	����IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//  ���������  *active_level 
����ֵ��0�������*/
PLT_API short __stdcall Plt_EthercatIoWriteOutputByBit(uint16 cardid,uint16 slave_id,uint16 bitno,uint16 active_level); 	
/*ָ��ܣ�����ָ��ethercat��վģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
              bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//			active_level �����ƽֵ  0��1
//  �����������
����ֵ��0�������*/
PLT_API short __stdcall Plt_EthercatIoReadOutputByBit(uint16 cardid,uint16 slave_id,uint16 bitno,uint16 *active_level);  	
/*ָ��ܣ���ȡָ��ethercat��վģ��ĳ������ڵ�ƽ
//  ���������cardid	���ţ�ȡֵ��Χ:[0,11]��
              slave_id	ethercat��վģ�����, ȡֵ��Χ:[0,7]��
              bitno	���IO����ţ�RCAN16I16Oȡֵ��Χ��[0,15]RCAN32I32Oȡֵ��Χ��[0,31]
//  ���������  *active_level
����ֵ��0�������*/
/******************************************************************ETHERCAT������غ���*********************************************************/
/*************************************************************************���Ի���غ���**********************************************************/
PLT_API short __stdcall  Plt_TesterSetParam(uint16 cardid,uint16 param_id,uint32 param_value);	
/*ָ��ܣ�
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              param_id	        
              param_value       
  ���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_TesterGetParam(uint16 cardid,uint16 param_id,uint32 *param_value);
/*����������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              param_id	        
  ���������  param_value       
����ֵ��0�������*/
PLT_API short __stdcall  Plt_TesterGetCdTextDataSingle(uint16 cardid,uint16 num,uint32 *bin);
PLT_API short __stdcall  Plt_TesterGetCdOkNgSum(uint16 cardid,uint32 *value);
PLT_API short __stdcall  Plt_TesterGetIrTextDataSum(uint16 cardid,uint16 num,uint32 *value);
PLT_API short __stdcall  Plt_TesterGetIrOkNgSum(uint16 cardid,uint16 num,uint32 *value);
PLT_API short __stdcall  Plt_TesterGetBlowBinNum(uint16 cardid,uint16 num,uint32 *value);
PLT_API short __stdcall  Plt_TesterSetBlowBinChoose(uint16 cardid,uint16 bin_id,uint16 data);
/*************************************************************************���Ի���غ���**********************************************************/
PLT_API short __stdcall  Plt_WatchSetBufferDatasEnable(uint16 cardid,uint16 datas_id,uint16 enable_flag);
/*����������ʹ��/��ֹ�����Զ��ɼ���������ʹ��ʱ��ͬʱ��ѻ������д洢�������������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	
			  enable_flag       1:ʹ�� 0����ֹ
  ���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_WatchConfigBufferParams(uint16 cardid,uint16 datas_id,double start_pos,double end_pos,uint32 time_period);
/*������������ȡ���ƿ��ײ��Զ��ɼ�������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	
			  start_pos         �ɼ���ʼλ�ã���λ�����嵱����λ ppu
			  end_pos           �ɼ�����λ�ã���λ�����嵱����λ ppu
			  time_period       �ɼ�Ƶ��      ��λ��time_period ms/��
  ���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_WatchReadBufferParams(uint16 cardid,uint16 datas_id,double *start_pos,double *end_pos,uint32 *time_period);
/*������������ȡ���ƿ��ײ��Զ��ɼ�������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	 
  ���������  start_pos         �ɼ���ʼλ�ã���λ�����嵱����λ ppu
			  end_pos           �ɼ�����λ�ã���λ�����嵱����λ ppu
			  time_period       �ɼ�Ƶ��      ��λ��time_period ms/��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_WatchGetBufferDatas(uint16 cardid,uint16 datas_id,uint32 datas_num,uint32 *act_datas_num,double *datas_buffer);
/*������������ȡ���ƿ��ײ��Զ��ɼ�������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��
              datas_id          ��Ҫ��ȡ������id,0-11 ��Ӧ0-11���������  12-23 ��Ӧ0-11�����������	
			  datas_num         ��Ҫ��ȡ�����ݸ���,һ�������Զ�300����
  ���������  act_datas_num     ʵ�ʶ�ȡ�������ݸ���       
              datas_buffer      ��ȡ��������
����ֵ��0�������*/

/*************************************************************************���Ź�������غ���*********************************************************/
PLT_API short __stdcall  Plt_SetHostWatchDog(uint16 cardid,uint16 enable,uint16 watchtime,uint16 do_total_num,uint16 *do_num,uint16 *do_logic);
/*
�������������ÿ��Ź�����
���������cardid ����
          enable ���Ź�ʹ�ܱ�־ 1�����Ź�ʹ��  0�����Ź���ֹ  Ĭ���ǽ�ֹ
          watchtime ��ʱ����ʱ�䣬��λ[ms]
          do_total_num ��ʱ����ʱ��Ҫ���õ����IO������
          *do_num     ��ʱ����ʱ��Ҫ���õ����IO�����
          *do_logic    ��ʱ����ʱ��Ҫ���õ��������IO�ڵ�ƽ
�����������*/
PLT_API short __stdcall  Plt_GetHostWatchDog(uint16 cardid,uint16 *enable,uint16 *watchtime,uint16 *do_total_num,uint16 *do_num,uint16 *do_logic);
/*������������ȡ���Ź�����*/
PLT_API short __stdcall  Plt_FeedHostWatchDog(uint16 cardid);
/*�����������ڳ�ʱ����ʱ�䷶Χ�ڲ��ϵ��ô˺������Է�ֹ��ʱ����*/
PLT_API short __stdcall  Plt_InitHostWatchDog(uint16 cardid);
/*�������������Ź����ܸ�λ����λ�������Ҫ�ٴ��������Ź����ܣ���Ҫ�������ÿ��Ź�����*/
/*************************************************************************���Ź�������غ���*********************************************************/
/*************************************************************************�Զ����д���ݺ����ӿ�*********************************************************/
PLT_API short __stdcall  Plt_UserSetDatas(uint16 cardid,uint32 datas_id,uint32 datas_num,char *datas_buffer);
/*����������д���ݵ���λ��
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��	
              datas_id          ����ID,�û����Բ���idö���Զ���Ĳ���
			  datas_num         ��Ҫд������ݸ���,һ��������д1200����
			  datas_buffer      д����λ������������
  ���������  ��
����ֵ��0�������*/
PLT_API short __stdcall  Plt_UserGetDatas(uint16 cardid,uint32 datas_id,uint32 *datas_num,char *datas_buffer);
/*��������������λ��������
  ���������  cardid	        ���ţ�ȡֵ��Χ:[0,11]��	
              datas_id          ����ID,�û����Բ���idö���Զ���Ĳ���	  
  ���������  datas_buffer      ��ȡ������λ������������
              datas_num         ���ض�ȡ�����ݸ�����	
����ֵ��0�������*/
/*************************************************************************�Զ����д���ݺ����ӿ�*********************************************************/
#ifdef __cplusplus
}
#endif

#endif
