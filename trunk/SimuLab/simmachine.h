#ifndef SIMMACHINE_H
#define SIMMACHINE_H
/*

[From]--PULL--->[--SETUP-->--PROCESS-->--(--BLOCKED-->)]--PUSH--->[To]




*/





#include <vector>

#include "simpart.h"
#include "simqueue.h"
#include "simscript.h"
#include <string>
class simScript;

class simQueue;
class simEvent;
class simElementList;


#define MACHINE_IDLE 0
#define MACHINE_SETTING_UP  1
#define MACHINE_PROCESSING  2
#define MACHINE_BLOCKED     3


class simMachine
{
public:
    simMachine();
    virtual ~simMachine();
    void AddFrom(simQueue* aQ);
    void AddTo(simQueue* aQ);
protected:
    simBase info;
    long capacity;
    long in_batch;//一次加工/处理的零件数量，普通机器是1，批加工是n，装配是n
    long out_batch;//输出的零件数量
    std::vector<simPart*> content;
    //double setuptime;//时刻
    //double setup_period;//时长,可以考虑为一个字符串，由脚本引擎解释计算其值
    simScript* setup_period;//(DOUBLE_R_TYPE);

    //double setupcost;//也可用脚本
    simScript* setup_cost;//(DOUBLE_R_TYPE);
    //double processtime;
    //double process_period;
    simScript* process_period;//(DOUBLE_R_TYPE);

    long STATE;//当前状态

//response function pointers
    void (*OnPull)(void);
    void (*OnPush)(void);
    void (*OnSetup)(void);
    void (*OnSetupOver)(void);
    void (*OnProcess)(void);
    void (*OnProcessOver)(void);
    void (*OnBlocked)(void);

    simScript* OnPullScript;
    simScript* OnPushScript;
    simScript* OnSetupScript;
    simScript* OnSetupOverScript;
    simScript* OnProcessScript;
    simScript* OnPrecessOverScript;
    simScript* OnBlockedScript;
    simScript* OnHungryScript;

    //动作自定义条件
    simScript* PullConditionScript;
    simScript* SetupConditionScript;
    simScript* ProcessConditionScript;
    simScript* PushConditionScript;


    //links
    std::vector<long> From; //源列表
    std::vector<long> To;   //渊列表
    std::vector<long> Relevant;//相关元素列表

private:
public:
    void SetName(char* ac)
    {
        info.SetName(ac);
    }
    char* GetName()
    {
        return info.GetName();
    }
    long GetID()
    {
        return info.GetID();
    }
    void SetElementTypeID(long etID)
    {
        info.SetElementTypeID(etID);
    }
    long GetElementTypeID()
    {
        return info.GetElementTypeID();
    }
    simElementList* GetElementList()
    {
        return info.GetElementList();
    }
    void BindElementList(simElementList* aL);

    bool IsEmpty();
    bool IsFull();

    bool pull(simQueue* aQ);
    bool pullPriorest(simQueue* aQ);
    bool pull(simMachine* aM);

    bool push(simQueue* aQ);
    bool push(simMachine* aM);

//    void GenerateAPullEvent(double t);
//    void GenerateAPushEvent(double t);
//    void GenerateASetupEvnet(double t);
//    void GenerateAProcessEvnet(double t);
//    void GenerateASetupOverEvnet(double t);
//    void GenerateAProcessOverEvnet(double t);
//    void GenerateABlockedEvent(double t);

    //计算事件发生时刻
    double CalcPullTime();
    double CalcPushTime();
    double CalcSetupTime();
    double CalcSetupOvetTime();
    double CalcProcessTime();
    double CalcProcessOverTime();

    //
    void GenerateBEGIN_IDLEevent(double t);
//PULL
    void GenerateBEGIN_BUSYEevent(double t);
    void GenerateSETUP_BEGINEevent(double t);
//SETUP
    void GenerateSETUP_OVEREevent(double t);
    void GeneratePROCESS_BEGINEevent(double t);
//PROCESS
    void GeneratePROCESS_OVEREevent(double t);
    void GenerateBLOCK_BEGINEevent(double t);
//PUSH
    void GenerateBLOCK_OVEREevent(double t);

    bool PullAPartFrom(simQueue* aq,const char *match_expression="");
    bool PullAPartFrom(simMachine* am,const char *match_expression="");

    bool PushAPartTo(simQueue* aQ);
    bool PushAPartTo(simMachine* aM);

    void TryPull();

    long GetState(){return STATE;}

    //事件响应总调度
    void Respond(simEvent* evt);
    bool ReadyforANY;

    bool PULL(simQueue* aq, long lotsize, const char* expresstion);


};

#endif // SIMMACHINE_H
