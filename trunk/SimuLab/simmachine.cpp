/*
This is written by WANG MengChang
*/#include "simmachine.h"

simMachine::simMachine()
{
    //ctor
    STATE=MACHINE_IDLE;

    capacity=1;
    in_batch=1;
    out_batch=1;

    SetElementTypeID(TYPE_MACHINE);
    char abc[]="NameUnkown(Machine)";
    SetName(abc);
    content.clear();
    OnPush=EmptyAction;
    OnPull=EmptyAction;
    OnSetup=EmptyAction;
    OnSetupOver=EmptyAction;
    OnProcess=EmptyAction;
    OnProcessOver=EmptyAction;
    OnBlocked=EmptyAction;
    From.clear();
    To.clear();

    setup_cost=new simScript(DOUBLE_R_TYPE);
    setup_period=new simScript(DOUBLE_R_TYPE);
    process_period=new simScript(DOUBLE_R_TYPE);

    (*setup_cost)="0.0";
    (*setup_period)="0.0";
    (*process_period)="1.0";


    OnPullScript=new simScript(VOID_R_TYPE);
    OnPushScript=new simScript(VOID_R_TYPE);
    OnSetupScript=new simScript(VOID_R_TYPE);
    OnSetupOverScript=new simScript(VOID_R_TYPE);
    OnProcessScript=new simScript(VOID_R_TYPE);
    OnPrecessOverScript=new simScript(VOID_R_TYPE);
    OnBlockedScript=new simScript(VOID_R_TYPE);
    OnHungryScript=new simScript(VOID_R_TYPE);

    (*OnPullScript)="EmptyAction();";
    (*OnPushScript)="EmptyAction();";
    (*OnSetupScript)="EmptyAction();";
    (*OnSetupOverScript)="EmptyAction();";
    (*OnProcessScript)="EmptyAction();";
    (*OnPrecessOverScript)="EmptyAction();";
    (*OnBlockedScript)="EmptyAction();";
    (*OnHungryScript)="EmptyAction();";

    PullConditionScript=new simScript(BOOL_R_TYPE);
    SetupConditionScript=new simScript(BOOL_R_TYPE);
    ProcessConditionScript=new simScript(BOOL_R_TYPE);
    PushConditionScript=new simScript(BOOL_R_TYPE);

    (*PullConditionScript)="true";
    (*SetupConditionScript)="true";
    (*ProcessConditionScript)="true";
    (*PushConditionScript)="true";

    ReadyforANY=false;

    //setup_cost->RegisterScriptEngine()
}

simMachine::~simMachine()
{
    //dtor
    delete setup_cost;
    delete setup_period;
    delete process_period;

    delete OnPullScript;
    delete OnPushScript;
    delete OnSetupScript;
    delete OnSetupOverScript;
    delete OnProcessScript;
    delete OnPrecessOverScript;
    delete OnBlockedScript;
    delete OnHungryScript;

    delete PullConditionScript;
    delete SetupConditionScript;
    delete ProcessConditionScript;
    delete PushConditionScript;


}
void simMachine::BindElementList(simElementList* aL)
{
    info.BindElementList(aL);
    setup_cost->RegisterScriptEngine(aL->GetScriptEngine());
    setup_period->RegisterScriptEngine(aL->GetScriptEngine());
    process_period->RegisterScriptEngine(aL->GetScriptEngine());
}

void simMachine::AddFrom(simQueue* aQ)
{
    From.push_back(aQ->GetID());
}

void simMachine::AddTo(simQueue* aQ)
{
    To.push_back(aQ->GetID());
}



bool simMachine::IsEmpty()
{
    if (content.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool simMachine::IsFull()
{
    if (long(content.size())>=capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}




bool simMachine::pull(simQueue* aQ)
{
//#not completed.
    if (IsFull())
    {
        return false;
    }
    else if (aQ->IsEmpty())
    {
        return false;
    }
    else
    {
        simPart* ap=(simPart*)NULL;
        ap=aQ->GetAPartOut();
        if (ap!=(simPart*)NULL)
        {
            content.push_back(ap);
        }
        else
        {
            return false;
        }

    }
    return true;
}

bool simMachine::pull(simMachine* aM)
{
    return true;
}

bool simMachine::push(simQueue* aQ)
{
    std::vector<simPart*>::iterator it=content.begin();
    std::vector<simPart*>::iterator it_end=content.end();
    for (;it!=it_end;it++)
    {
        simPart* rs=(*it);
        if (rs!=(simPart*)NULL)
        {
            if (aQ->GetAPartIn(rs)) //nothing
            {
                *it=(simPart*)NULL;
            }
            else
            {
                //failure
                return false;
            }
        }
    }
    //
    content.clear();
    return true;
}

bool simMachine::push(simMachine* aM)
{
    return true;
}

bool simMachine::pullPriorest(simQueue* aQ)
{
    if (IsFull())
    {
        return false;
    }
    else if (aQ->IsEmpty())
    {
        return false;
    }
    else
    {
        simPart* ap=(simPart*)NULL;
        ap=aQ->GetPartOutPriorest();
        if (ap!=(simPart*)NULL)
        {
            content.push_back(ap);
        }
        else
        {
            return false;
        }
    }
    return true;
}

//void simMachine::GenerateAPullEvent(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_PULL);
//    GetElementList()->CollectEvent(rs);
//}
//
//void  simMachine::GenerateAPushEvent(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_PUSH);
//    GetElementList()->CollectEvent(rs);
//}
//
//void simMachine::GenerateASetupEvnet(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_SETUP);
//    GetElementList()->CollectEvent(rs);
//}
//void simMachine::GenerateAProcessEvnet(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_PROCESS);
//    GetElementList()->CollectEvent(rs);
//}
//void simMachine::GenerateASetupOverEvnet(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_SETUP_OVER);
//    GetElementList()->CollectEvent(rs);
//}
//void simMachine::GenerateAProcessOverEvnet(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_PROCESS_OVER);
//    GetElementList()->CollectEvent(rs);
//}
//void simMachine::GenerateABlockedEvent(double t)
//{
//    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),EVENT_BLOCKED);
//    GetElementList()->CollectEvent(rs);
//}


//计算事件发生时刻
double simMachine::CalcPullTime()
{
    double rs=-1;//invalid when less than 0
    return rs;
}
double simMachine::CalcPushTime()
{
    double rs=-1;//invalid when less than 0
    return rs;
}
double simMachine::CalcSetupTime()
{
    double rs=-1;//invalid when less than 0
    return rs;
}
double simMachine::CalcSetupOvetTime()
{
    double rs=-1;//invalid when less than 0
    return rs;
}
double simMachine::CalcProcessTime()
{
    double rs=-1;//invalid when less than 0
    return rs;
}
double simMachine::CalcProcessOverTime()
{
    double rs=-1;//invalid when less than 0
    return rs;
}


void simMachine::GenerateBEGIN_IDLEevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_BEGIN_IDLE);
    GetElementList()->CollectEvent(rs);
}
//PULL
void simMachine::GenerateBEGIN_BUSYEevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_BEGIN_BUSY);
    GetElementList()->CollectEvent(rs);
}
void simMachine::GenerateSETUP_BEGINEevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_SETUP_BEGIN);
    GetElementList()->CollectEvent(rs);
}
//SETUP
void simMachine::GenerateSETUP_OVEREevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_SETUP_OVER);
    GetElementList()->CollectEvent(rs);
}
void simMachine::GeneratePROCESS_BEGINEevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_PROCESS_BEGIN);
    GetElementList()->CollectEvent(rs);
}
//PROCESS
void simMachine::GeneratePROCESS_OVEREevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_PROCESS_OVER);
    GetElementList()->CollectEvent(rs);
}
void simMachine::GenerateBLOCK_BEGINEevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_BLOCK_BEGIN);
    GetElementList()->CollectEvent(rs);
}
//PUSH
void simMachine::GenerateBLOCK_OVEREevent(double t)
{
    simEvent* rs=new simEvent(t,info.GetID(),info.GetElementTypeID(),SIM_EVT_BLOCK_OVER);
    GetElementList()->CollectEvent(rs);
}

bool simMachine::PullAPartFrom(simQueue* aQ,const char *match_expression)
{
    //if(match_expression
    printf("[Note]Finding a part with a special condition is not completed yet.\n");
    //
    if (IsFull())
    {
        return false;
    }
    else if (aQ->IsEmpty())
    {
        return false;
    }
    else
    {
        simPart* ap=(simPart*)NULL;
        ap=aQ->GetAPartOut();
        if (ap!=(simPart*)NULL)
        {
            content.push_back(ap);
        }
        else
        {
            return false;
        }

    }
    return true;
}
bool simMachine::PullAPartFrom(simMachine* aM,const char *match_expression)
{
    if (aM->GetState()!=BLOCKED)
    {
        return false;
    }
    else
    {
        //
        printf("[Failure: simmachine.cpp]How Machine Pull another Machine is not clear now.\n");
        return false;
    }
}

bool simMachine::PushAPartTo(simQueue* aQ)
{
    if (aQ->IsFull())
    {
        return false;
    }
    else
    {
        if (this->IsEmpty())
        {
            return false;
        }
        else
        {
            simPart* rs=(simPart*)NULL;
            rs=content.back();
            if (rs!=(simPart*)NULL)
            {
                if (aQ->GetAPartIn(rs))
                {
                    content.pop_back();
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
bool simMachine::PushAPartTo(simMachine* aM)
{
    printf("[Failure]Pushing to a Machine is not completed yet.\n [simmachine.cpp]\n");
    return false;
}

bool simMachine::PULL(simQueue* aq, long lotsize, const char* expresstion)
{
    //使用对象的属性，动态的，要用到this的或指针的angelscript
    return true;
}



void simMachine::TryPull()
{
    bool pull_cond=false;
    PullConditionScript->SetValue(&pull_cond);
    if (pull_cond)
    {
        //pull and onpull
        for (int i=content.size();i<in_batch;i++)
        {
            //依次拉取列表中的对象，直到成功为止
            //if(content.size()>=in_batch){break;}
            std::vector<long>::iterator it=From.begin();
            for (;it!=From.end();it++)
            {
                simQueue* theq=GetElementList()->ID2Queue((*it));
                simMachine* them=GetElementList()->ID2Machine((*it));
                if (theq!=(simQueue*)NULL)
                {
                    if (PullAPartFrom(theq))
                    {
                        //执行脚本
                        OnPullScript->run();

                        if (long(content.size())>=in_batch)
                        {
                            //全部拉入了
                            this->GenerateBEGIN_BUSYEevent(this->GetElementList()->GetClockTime());
                            this->STATE=MACHINE_SETTING_UP;
                            ReadyforANY=false;
                            return;
                        }
                        break;
                    }
                }
                else if (them!=(simMachine*)NULL)
                {
                    //
                    printf("Here need to pull a part from a machine.[not completed yet]\n ");
                }
                else
                {
                    //
                    printf("CONNOT FIND the ID=%ld",(*it));
                }
            }
        }
    }
}


//事件响应总调度
void simMachine::Respond(simEvent* evt)
{
    //判断是否有关联
    //判断是否响应
    //1-计算下一事件发生时间
    //2-执行固有动作
    //3-执行自定义动作
    //4-生成下一事件
    if (evt->GetElementID()==GetID())
    {
        //自身产生的事件
        if (evt->GetEventType()==SIM_EVT_BEGIN_IDLE)
        {
            TryPull();
            if (long(content.size())<in_batch)//仍没拉满
            {
                //Ready for response ANY event
                ReadyforANY=true;
            }

        }
    }
    else if (ReadyforANY)
    {
        if (STATE==MACHINE_IDLE)
        {
            TryPull();
        }
        else if (STATE==MACHINE_SETTING_UP)
        {
        }
        else if (STATE==MACHINE_PROCESSING)
        {
        }
        else if (STATE==MACHINE_BLOCKED)
        {
        }
        else
        {
            printf("WRONG: Machine is at a WRONG state.\n");
        }
    }
}


