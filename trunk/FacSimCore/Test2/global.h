//Global settings here
#ifndef GLOBAL_H
#define GLOBAL_H

#define WORKSTATION_NUM    2 //��λ�� 

#define TOTAL_PRODUCT_TYPE 4   //�ܳ�Ʒ���� 

#define PLAN_LIST_LENGTH   10 //�ƻ����� 

#define MAX_PROC_TABLE_SCALE  30 



#define PULL_TYPE 1
//1-�ȵ��ȳ�ȡ����ͳ��
//2-�Ż���ȡ



void setProcTable();
float procTime(int Instance, int inType, int OutType); 
int queryPartType(int curType,int targetType,int curMachineNum); 

#endif//GLOBAL_H
