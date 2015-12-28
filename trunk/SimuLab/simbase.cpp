/*
This is written by WANG MengChang
*/#include "simbase.h"
#include "simscript.h"

long simBase::count=0;

simBase::simBase()
{
    //ctor
    count++;
    SetID(count);
    theList=(simElementList*)NULL;
}

simBase::~simBase()
{
    //dtor
}

char des_str[256];//临时交换用
char* GetElementTypeDescription(long tp)
{
    ///////////////////////////////////
    //////////////////////////////
    //类成员函数指针代码例子
    void(simEvent::*fn)(double) ;
    fn=&simEvent::SetTime;
////////////////////////////////////////////////////////////


    switch (tp)
    {
    case 0:
        strcpy(des_str,"part");
        break;
    case 1:
        strcpy(des_str,"PartSource");
        break;
    case 2:
        strcpy(des_str,"Queue");
        break;
    case 3:
        strcpy(des_str,"Machine");
        break;
        //
    default:
        strcpy(des_str,"Not Defined");
    }
    return des_str;
}



simEvent::simEvent(double t,long elmt,long elmt_type,long evt_type)
{
    SetTime(t);
    SetElementID(elmt);
    SetElementTypeID(elmt_type);
    SetEventType(evt_type);
}
simEvent::simEvent(double t,long elmt,long elmt_type,long evt_type,long p1,long p2)
{
    SetTime(t);
    SetElementID(elmt);
    SetElementTypeID(elmt_type);
    SetEventType(evt_type);
    SetPara1(p1);
    SetPara2(p2);
}

simEvent::~simEvent()
{
}










simClock::simClock(simElementList* EL)
{
    currentTime=0.0;
    nextTime=0.0;
    bind(EL);
}
simClock::~simClock()
{

}

void simClock::bind(simElementList* EL)
{
    theList=EL;

}

void simClock::forward()
{
}






////////

simElementList::simElementList()
{
    clock=new simClock(this);
    engine=asCreateScriptEngine(ANGELSCRIPT_VERSION);
    int r=engine->SetMessageCallback(asFUNCTION(ScriptMessageCallback),0,asCALL_CDECL);
    assert(r>=0);
    r=engine->RegisterGlobalFunction("void EmptyAction()",asFUNCTION(EmptyAction),asCALL_CDECL);
    assert(r>=0);
}
simElementList::~simElementList()
{
    engine->Release();
    delete clock;
    BlockedMachineList.clear();
    HungryMachineList.clear();

    std::vector<simEvent*>::iterator it_e=EventList.begin();
    for (;it_e!=EventList.end();it_e++)
    {
        if ((*it_e)!=(simEvent*)NULL)
        {
            delete (*it_e);
        }
    }
    EventList.clear();

    std::vector<simQueue*>::iterator it_q=QueueList.begin();
    for (;it_q!=QueueList.end();it_q++)
    {
        if ((*it_q)!=(simQueue*)NULL)
        {
            delete (*it_q);
        }
    }
    QueueList.clear();

    std::vector<simMachine*>::iterator it_m=MachineList.begin();
    for (;it_m!=MachineList.end();it_m++)
    {
        if ((*it_m)!=(simMachine*)NULL)
        {
            delete (*it_m);
        }
    }
    MachineList.clear();


}

asIScriptEngine* simElementList::GetScriptEngine()
{
    return engine;

}


void simElementList::CollectEvent(simEvent* evt)
{
    EventList.push_back(evt);
}

double  simElementList::GetClockTime()
{
    return clock->GetClockTime();
}

void simElementList::AddMachine(simMachine* am)
{
    MachineList.push_back(am);
}
void simElementList::AddQueue(simQueue* aq)
{
    QueueList.push_back(aq);
}


simMachine* simElementList::ID2Machine(long theID)//;//from ID to find the Machine
{
    simMachine* rs=(simMachine*)NULL;
    std::vector<simMachine*>::iterator it=MachineList.begin();
    for(;it!=MachineList.end();it++)
    {
        if((*it)->GetID()==theID)
        {
            rs=(*it);
        }
    }
    return rs;
}
simQueue* simElementList::ID2Queue(long theID)//;//from ID to find out the Queue
{
    simQueue* rs=(simQueue*)NULL;
    std::vector<simQueue*>::iterator it=QueueList.begin();
    for(;it!=QueueList.end();it++)
    {
        if((*it)->GetID()==theID)
        {
            rs=(*it);
        }
    }
    return rs;
}



void EmptyAction()
{
    return;
}


wxString stdString2wxString(std::string& std_Str)
{
    return wxString::FromUTF8(std_Str.c_str());
}

std::string wxString2stdString(wxString& wxStr)
{
    std::string std_str="";
    std_str=wxStr.char_str();
    return std_str;
}
