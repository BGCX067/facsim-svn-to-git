//Global settings here
#ifndef GLOBAL_H
#define GLOBAL_H

#define WORKSTATION_NUM    2 //工位数 

#define TOTAL_PRODUCT_TYPE 4   //总成品类数 

#define PLAN_LIST_LENGTH   10 //计划长度 

#define MAX_PROC_TABLE_SCALE  30 



#define PULL_TYPE 1
//1-先到先抽取，传统型
//2-优化抽取



void setProcTable();
float procTime(int Instance, int inType, int OutType); 
int queryPartType(int curType,int targetType,int curMachineNum); 

#endif//GLOBAL_H
