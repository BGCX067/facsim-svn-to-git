//MyModel.cpp 
#include <iostream>
#include "simobject.h"
#include "simmachine.h"
#include "simevent.h"
#include "simpart.h"
#include "simqueue.h"
#include "simclock.h"

#include "global.h"
#include "my_random.h"

#include "simobjectlist.h" 
#include "simmodel.h"
using namespace std;

extern simModel theModel;

void InitialSequence(int* S)
{
    //PLAN_LIST_LENGTH
    for(int i=0;i<PLAN_LIST_LENGTH;i++)
    {
        *(S+i)=1+int(random(0,TOTAL_PRODUCT_TYPE));
    }
} 


//bool validRoute[WORKSTATION_NUM+1][TOTAL_PRODUCT_TYPE+1][TOTAL_PRODUCT_TYPE+1];//[机器号][输入类型][生成类型] 

//void setProccess()
//{
//    //设置工艺路线
//    int i,j,k;
//    for(i=0;i<=WORKSTATION_NUM;i++){
//        for(j=0;j<=TOTAL_PRODUCT_TYPE;j++){
//            for(k=0;k<=TOTAL_PRODUCT_TYPE;k++){
//                validRoute[i][j][k]=false;
//            }
//
//        }
//    }
//    // //
//    validRoute[1][1][1]=true;
//    validRoute[1][1][2]=true;
//    validRoute[1][2][3]=true;
//
//    validRoute[2][1][1]=true;
//    validRoute[2][2][2]=true;
//    validRoute[2][3][3]=true;
//    validRoute[2][3][4]=true;
//
//
//}


int ProccessTable[MAX_PROC_TABLE_SCALE][WORKSTATION_NUM+1];//[工艺序号][路线长度]
float ProcTimeTable[WORKSTATION_NUM+1][TOTAL_PRODUCT_TYPE+1][TOTAL_PRODUCT_TYPE+1]; //机器号、进、出 
void setProcTable()
{
    int i,j,k;
    for(i=0;i<MAX_PROC_TABLE_SCALE;i++)
    {
        for(j=0;j<=WORKSTATION_NUM;j++)
        {
           ProccessTable[i][j]=0;
        }
    }  
    for(i=0;i<=WORKSTATION_NUM;i++){
        for(j=0;j<=TOTAL_PRODUCT_TYPE;j++){
            for(k=0;k<=TOTAL_PRODUCT_TYPE;k++){
                ProcTimeTable[i][j][k]=-0.1;
            }

        }
    }

    
    //第一条工艺 1->1->1 
    ProccessTable[0][0]=1;//毛坯类型  -        1
    ProccessTable[0][1]=1;//第一工位输出类型-  1 
    ProccessTable[0][2]=1;//第二工位输出类型-  1  
    //第二条1->2->2
    ProccessTable[1][0]=1; 
    ProccessTable[1][1]=2; 
    ProccessTable[1][2]=2; 
    //第三条2->3->3
    ProccessTable[2][0]=2; 
    ProccessTable[2][1]=3; 
    ProccessTable[2][2]=3; 
    //第四条2->3->4
    ProccessTable[3][0]=2; 
    ProccessTable[3][1]=3; 
    ProccessTable[3][2]=4;
    
    
    //处理时间设置
    ProcTimeTable[1][1][1]=4; //M1,1->1 ,4 
    ProcTimeTable[1][1][2]=3; //M1,1->2 ,3
    ProcTimeTable[1][2][3]=5; //M1,2->3 ,5
    
    ProcTimeTable[2][1][1]=5; //M2 
    ProcTimeTable[2][2][2]=3;
    ProcTimeTable[2][3][3]=6; 
    ProcTimeTable[2][3][4]=4; 
} 

float procTime(int Instance, int inType, int outType)
{
    return  ProcTimeTable[Instance][inType][outType]; 
} 

//ProccessInfo[当前零件类型][目标类型][当前机器号]=当前应生成的型号 
int queryPartType(int curType,int targetType,int curMachineNum)
{
    //1.抽取目标ProccessTable[*][WORKSTATION_NUM]为 targetType 的所有工艺
    //2.抽取ProccessTable[*][curMachineNum-1]==curType的工艺
    //3.返回ProccessTable[**][curMachineNum]
    cout<<"queryPartType("<<curType<<","<<targetType<<","<<curMachineNum<<")\n"; 
    int i=0;
    int procNum[10];
    int rsLength=0;
    for(int j=0;j<10;j++){procNum[j]=-1;}
    while(ProccessTable[i][WORKSTATION_NUM]>0)
    {
        if(targetType==ProccessTable[i][WORKSTATION_NUM])
        {
            procNum[rsLength]=i;
            rsLength++;
        }
        i++;
    }
//    printf("queryPartType:rsLength=%d\n",rsLength); 
    for(i=0;i<rsLength;i++)
    {
       if(ProccessTable[procNum[i]][curMachineNum-1]==curType)
       {
            return ProccessTable[procNum[i]][curMachineNum];
        }
        else{
//            std::cout<<"ProccessTable[procNum[i]][curMachineNum-1]=" <<ProccessTable[procNum[i]][curMachineNum-1]<<endl; 
        } 
    }
    ////如果没成功
    printf("未找到相应工艺信息\n"); 
    printf("curType:%d\tTargetType:%d\tMachine:%d\n",curType,targetType,curMachineNum);
    system("PAUSE"); 
    return -1; 
} 


simQueue q[3];

void EditModel()
{
    
    /*
        [][][][][]....[][][][][] ->  [[ M1 ]] ->  |[][][][][]| ->[[ M2 ]] -> [][][][][] 
    */
    
    setProcTable(); 
    
    
    //调整好上线顺序后再填入Q0中
    // 1.随机生成目标序列（10个）
    // 2.反推出毛坯序列
    // 3.抽取序列放入Q0
         
    int initType[10];
    InitialSequence(initType); 
    simPart *theP1[10];
    for(int j=0;j<10;j++)
    {
        theP1[j]=new simPart();
    }
    

    for(int i=0;i<10;i++){
        theP1[i]->setTargetType(initType[i]);//初始序列 
        int k=0; 
        while(ProccessTable[k][WORKSTATION_NUM]>0)
        {
            if(initType[i]==ProccessTable[k][WORKSTATION_NUM]){
                printf("part %d:setPartType=%d\n",i,ProccessTable[k][0]);
                theP1[i]->setType(ProccessTable[k][0]);
                break; 
            } 
            k++; 
        } 
         
    }
    //
    
    q[0].setInstanceNum(0); 
    q[1].setInstanceNum(1);
    q[2].setInstanceNum(2);
    
    q[0].setCapacity(50);
    q[1].setCapacity(5);
    q[2].setCapacity(50);
    
    for(int i=0;i<10;i++)
    {
        q[0].GetPart(theP1[i]);
        //毛坯已经准备好 
    } 
    q[0].showContent(); 
    /////
    //to do 初始目标序列设置代码在这里设定 
    //生成序列，然后设置q[0]中的优先级 
    
    
    //////////// 
    
    simMachine* pM1=new simMachine();
    simMachine* pM2=new simMachine(); 
    //simMachine MM2;
    
    pM1->setInstanceNum(1);
    pM1->theSource=&q[0];
    pM1->theDestination=&q[1]; 
     
    pM2->setInstanceNum(2);
    pM2->theSource=&q[1];
    pM2->theDestination=&q[2];
    
    //
    theModel.theObjectList.AddSimObject(&q[0]);
    theModel.theObjectList.AddSimObject(pM1);
    theModel.theObjectList.AddSimObject(pM2); 
    
    theModel.theObjectList.AddSimObject(&q[1]);
    theModel.theObjectList.AddSimObject(&q[2]);
    
    
}

void testEditModel()
{
    simPart theP[6];
    
    simMachine* ap=new simMachine();
    ap->setInstanceNum(1);
    
    simMachine* ap2=new simMachine();
    ap2->setInstanceNum(2);
    
    simMachine* ap3=new simMachine();
    ap3->setInstanceNum(3);
    
    simQueue* aQ=new simQueue();
    aQ->setInstanceNum(1);
    aQ->GetPart(&theP[0]);
    aQ->GetPart(&theP[1]);
    aQ->GetPart(&theP[2]);
    aQ->GetPart(&theP[3]);
    aQ->GetPart(&theP[4]);
    aQ->GetPart(&theP[5]);
    
    simQueue* aQ2=new simQueue();
    aQ2->setInstanceNum(2);
    
    simQueue* aQ3=new simQueue();
    aQ3->setInstanceNum(3);
    aQ3->Capacity=3;
    
    ap->theSource=aQ;
    ap->theDestination=aQ2;
    
    ap2->theSource=aQ2;
    ap2->theDestination=aQ3;
    
    ap3->theSource=aQ;
    ap3->theDestination=aQ3; 
    
    theModel.theObjectList.AddSimObject(ap);
    theModel.theObjectList.AddSimObject(ap2);
    theModel.theObjectList.AddSimObject(aQ);
    theModel.theObjectList.AddSimObject(aQ2);
    theModel.theObjectList.AddSimObject(aQ3);
    theModel.theObjectList.AddSimObject(ap3);
}

void RunModel()
{
    theModel.run();
}

void MyModel()
{
    EditModel();
    RunModel();
    q[2].showContent(); 
}

 

