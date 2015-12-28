#include "../include/Machine.h"

Machine::Machine()
{
    //ctor
    eType=MACHINE_TYPE;
    status=STATUS_IDLE;
    NowPartType=-1;
    LastPartType=-1;
}

Machine::~Machine()
{
    //dtor
}
Part* Machine::getThePart()
{
    return thePart;
}
int Machine::getStatus()
{
    return status;
}

void Machine::setQueues(Queue* from,Queue* to)
{
    FROM=from;
    TO=to;
}
void Machine::setProcessNum(int prcsnum)
{
    thePart->setProcessNum(prcsnum);
    ProcessNum=prcsnum;
}

int Machine::getProcessNum()
{
    return ProcessNum;
}

void Machine::setSetupTime(double stt)
{
    setuptime=stt;
}
void Machine::setProcessTime(double pst)
{
    processtime=pst;
}


void Machine::CalcAjustTime()
{
    if(thePart->getType()==LastPartType)
    {
        ajusttime=0.0;
    }
    else{
        ajusttime=::CalcAjustTime(LastPartType,NowPartType);
    }

}
void Machine::CalcSetupTime()
{
    setuptime=::CalcSetupTime(NowPartType);
}

void Machine::CalcProcessTime()
{
    processtime=::CalcProcessTime(NowPartType,thePart->getProcessNum());
}


bool Machine::TryPull()
{
    Part* tmp=(Part*)NULL;
    tmp= FROM->givePartHighestLPriority();
    if (tmp!=(Part*)NULL)
    {
        thePart=tmp;
        NowPartType=thePart->getType();
        //std::cout<<"A Part is Pulled by a Machine[Machine ID="<<ID<<"]."<<std::endl;
        return true;
    }
    return false;
}
bool Machine::TryPush()
{
    //int tmpType=thePart->getType();
    if (TO->getAPartIn(thePart))
    {
        thePart=(Part*)NULL;
        LastPartType=NowPartType;
        NowPartType=-1;
        //std::cout<<"[Machine ID="<<ID<<"]A Part is Pushed into a Queue."<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Machine::Process()
{
    //chage the part type into another one.
    //std::cout<<"Machine::Process() Not finished.\n";
    int tmp=::CalcPartType(NowPartType,thePart->getProcessNum());
    thePart->setType(tmp);
    //cout<<"Part of Type "<<NowPartType<<" ---> Part of Type "<<tmp<<endl;
}


bool Machine::RespondEvent(Event* evt)
{
    //cout<<"This Machine is ready to response[Machine.cpp]"<<endl;
    if (STATUS_IDLE==status)
    {
        //Try to pull FROM
        if (TryPull())
        {
            // If success, Then generator a EVT_BEGIN_BUSY Event
            sim->showQueues();
            Event* evt1= new Event;
            evt1->Element_ID=ID;
            evt1->Event_time=evt->Event_time;
            evt1->Event_Type=EVT_BEGIN_BUSY;
            //Gather the event
            sim->CollectEvent(evt1);
            //generate a EVT_SETUP_BEGIN Event
            Event* evt2=new Event;
            evt2->Element_ID=ID;
            evt2->Event_time=evt->Event_time;
            evt2->Event_Type=EVT_SETUP_BEGIN;
            //Gather the event
            sim->CollectEvent(evt2);

            //Chage the status to STATUS_SETTING_UP
            status=STATUS_SETING_UP;
            //cout<<"Setting_up...[Machine ID="<<ID<<"]"<<endl;

            //Calc the Event EVT_SETUP_OVER 's time
            CalcAjustTime();
            CalcSetupTime();
            Event* evt3=new Event;
            evt3->Element_ID=ID;
            evt3->Event_time=evt->Event_time+ajusttime+setuptime;
            evt3->Event_Type=EVT_SETUP_OVER;
            //generate a EVT_SETUP_OVER event.
            sim->CollectEvent(evt3);
        }

    }
    else if ( STATUS_SETING_UP==status)
    {
        if (evt->Element_ID==ID && evt->Event_Type==EVT_SETUP_OVER)
        {
            //if evt == EVT_SETUP_OVER

            //generate a PROCESS_BEGIN event
            Event* evt4=new Event;
            evt4->Element_ID=ID;
            evt4->Event_Type=EVT_PROCESS_BEGIN;
            evt4->Event_time=evt->Event_time;
            sim->CollectEvent(evt4);

            status=STATUS_PROCESSING;
            //cout<<"Processing...[Machine ID="<<ID<<"]"<<endl;

            //chage the status to PROCESSING

            //Calc the event PROCESS_OVER time and then generate the PROCESS_OVER EVENT
            CalcProcessTime();
            Event* evt5=new Event;
            evt5->Element_ID=ID;
            evt5->Event_time=evt->Event_time+processtime;
            evt5->Event_Type=EVT_PROCESS_OVER;
            sim->CollectEvent(evt5);
            Process();
            //try to set the Part attributes


        }
    }
    else if (STATUS_PROCESSING==status)
    {
        if (evt->Element_ID==ID && evt->Event_Type==EVT_PROCESS_OVER)
        {
            //if evt== EVT_PROCESS_OVER

            //chage the status to BLOCKED
            status=STATUS_BLOCKED;
            //cout<<"Blocked...[Machine ID="<<ID<<"]"<<endl;

            Event* evt6=new Event;
            evt6->Element_ID=ID;
            evt6->Event_time=evt->Event_time;
            evt6->Event_Type=EVT_BLOCK_BEGIN;
            sim->CollectEvent(evt6);

            //generate EVT_BLOCK_BEGIN
        }
    }
    else if (STATUS_BLOCKED==status)
    {
        //try to push to TO
        if (TryPush())
        {
            //if success, chage the status to IDLE
            sim->showQueues();

            status=STATUS_IDLE;
            //cout<<"Idle...[Machine ID="<<ID<<"]"<<endl;
            //generate EVT_BEGIN_IDLE event
            Event* evt7=new Event;
            evt7->Element_ID=ID;
            evt7->Event_time=evt->Event_time;
            evt7->Event_Type=EVT_BEGIN_IDLE;

            sim->CollectEvent(evt7);
        }
    }
    return true;
}
