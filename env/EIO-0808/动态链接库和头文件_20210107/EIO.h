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

//#define PLT_API

#ifdef __cplusplus
extern "C" {
#endif

//���ƿ�����غ���	
PLT_API short __stdcall Plt_CardOpen(uint16 TotalCards,uint16 *CardIdArray,uint16 *Section,uint16* Host_id);//��ʼ�����ƿ�
PLT_API short __stdcall Plt_CardClose(void);	//�رտ��ƿ�

PLT_API short __stdcall Plt_IoACardOpen(uint16 cardid,uint16 Section,uint16 Host_id);
/*�����������򿪵�cardid���˶����ƿ�
���������  cardid ����
            Section IP��ַ�����ζκ�
			Host_id IP��ַ���Ķζκ�
�����������
���أ�0�������*/
PLT_API short __stdcall Plt_IoACardClose(uint16 cardid);	//�رտ��ƿ�
/*�����������رյ�cardid���˶����ƿ�
���������  cardid ����
�����������
���أ�0�������*/

PLT_API short __stdcall Plt_CardGetVerson(uint16 cardid,DWORD *verson1,DWORD *verson2); //verson1 �̼��汾��  verson2 ��汾��
/*************************************************************************ͨ���������IO**********************************************************/
PLT_API short __stdcall Plt_IoReadInputByBit(uint16 cardid,uint16 bitno,uint16 *active_level); 	//��ȡ����ڵ�״̬
PLT_API short __stdcall Plt_IoWriteOutputByBit(uint16 cardid,uint16 bitno,uint16 active_level); 	//��������ڵ�״̬
PLT_API short __stdcall Plt_IoReadOutputByBit(uint16 cardid,uint16 bitno,uint16 *active_level);  	//��ȡ����ڵ�״̬
PLT_API short __stdcall Plt_IoReadAllInput(uint16 cardid,DWORD *active_level_1); 	//��ȡ����ͨ������IO��ֵ
PLT_API short __stdcall Plt_IoReadAllOutput(uint16 cardid,DWORD *active_level); 	//��ȡͨ������˿ڵ�ֵ
PLT_API short __stdcall Plt_IoWriteAllOutput(uint16 cardid,DWORD active_level);  	//����ͨ������˿ڵ�ֵ
PLT_API short __stdcall Plt_IoReverseOutputBit(uint16 cardid,uint16 bitno,double hold_time); //��ת��ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
/*************************************************************************ͨ���������IO**********************************************************

/*************************************************************************CAN�������IO**********************************************************/
PLT_API short __stdcall Plt_IoSetMasterBaudrate(uint16 cardid,uint16 baudrate);
//*����������������վ������
//  ���������card  ����  
//            baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
//  �����������
//*/
PLT_API short __stdcall Plt_IoGetMasterBaudrate(uint16 cardid,uint16 *baudrate);
//*����������������վ������
//  ���������card  ����  
//           
//  ��������� baudrate 0:500kbps  1:250kbps 2:125kbps 3:1Mbps
//*/
PLT_API short __stdcall Plt_IoCanReadInputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level); 	//��ȡָ��canģ������ڵ�״̬
//*������������ȡָ��canģ������ڵ�״̬
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            bitno IO�ں� ��ЧֵΪ[0,15]
//  ���������  *active_level 
//*/
PLT_API short __stdcall Plt_IoCanWriteOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 active_level); 	//����ָ��canģ������ڵ�״̬
///*��������������ָ��canģ������ڵ�״̬
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            bitno IO�ں� ��ЧֵΪ[0,15]
//			active_level �����ƽֵ  0��1
//  �����������
//*/
PLT_API short __stdcall Plt_IoCanReadOutputByBit(uint16 cardid,uint16 can_id,uint16 bitno,uint16 *active_level);  	//��ȡָ��canģ������ڵ�״̬
///*������������ȡָ��canģ������ڵ�״̬
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            bitno IO�ں� ��ЧֵΪ[0,15]
//  ���������  *active_level �����ƽֵ  0��1
//*/
PLT_API short __stdcall Plt_IoCanReadAllInput(uint16 cardid,uint16 can_id,uint32 *active_level_1); 	//��ȡָ��canģ������ͨ������IO��ֵ
///*������������ȡָ��canģ������ͨ������IO��ֵ
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            bitno IO�ں� ��ЧֵΪ[0,15]
//  ���������  *active_level  active_level˳���0��31����0��15����IO��ƽ
//*/
PLT_API short __stdcall Plt_IoCanReadAllOutput(uint16 cardid,uint16 can_id,uint32 *active_level); 	//��ȡָ��canģ������ͨ������ڵ�ֵ
///*������������ȡָ��canģ������ͨ������ڵ�ֵ
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            bitno IO�ں� ��ЧֵΪ[0,31]		
//  ���������*active_level  active_level˳���0��31����0��15���IO��ƽ
//*/
PLT_API short __stdcall Plt_IoCanWriteAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	//����ָ��canģ������ͨ������ڵ�ֵ
///*��������������ָ��canģ������ͨ������ڵ�ֵ
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            bitno IO�ں� ��ЧֵΪ[0,31]
//			active_level  active_level˳���0��31����0��31���IO��ƽ
//  �����������
//*/
PLT_API short __stdcall Plt_IoCanGetLinkState(uint16 cardid,uint16 can_id,uint16 *link_state);  	//��ȡָ��canģ������״̬
///*������������ȡָ��canģ������״̬
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//            
//  ���������  *link_state ����״̬ 1������  0���Ͽ�
//*/
PLT_API short __stdcall Plt_IoCanReverseOutputBit(uint16 cardid,uint16 can_id,uint16 bitno,double hold_time); //��תָ��canģ�鵱ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
///*����������/��תָ��canģ�鵱ǰ����ڵ�״̬,�������趨ʱ���ָ��ط�תǰ��״̬
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15] 
//            bitno IO�ں� ��ЧֵΪ[0,15]
//            hold_time����λ��s 
//  �����������
//*/
PLT_API short __stdcall Plt_IoCanInitAllOutput(uint16 cardid,uint16 can_id,uint32 active_level);  	
///*��������������ָ��canģ�����IO��ʼ��ƽ
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//			active_level  active_level˳���0��31����0��31���IO��ʼ��ƽ
//  �����������
//*/
PLT_API short __stdcall Plt_IoCanGetNodeType(uint16 cardid,uint16 can_id,uint16 *type);  	
///*��������������ָ��canģ�����IO��ʼ��ƽ
//  ���������card  ����  
//            can_id  can id��:��ЧֵΪ[0,15]   
//  ���������type canģ��ڵ�����  1��rcan1616 2:rcan3232
//*/
/*************************************************************************CAN�������IO**********************************************************/
PLT_API short __stdcall Plt_IoReSetIP(uint16 cardid,uint16 section_3,uint16 section_4);//����IP��ַ���������ϵ����Ч
PLT_API short __stdcall Plt_IoGetIP(uint16 cardid,uint16 *section_3,uint16 *section_4);//��ȡIP��ַ����
PLT_API short __stdcall Plt_IoSetInitIO(uint16 cardid,uint16 *io_init_value);//�������IO��ʼ��ƽ
#ifdef __cplusplus
}
#endif

#endif
