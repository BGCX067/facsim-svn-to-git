#include "../include/MyBase.h"

#include <vector>

#include "../include/Machine.h"

using namespace std;

Simulation::Simulation()
{
    sim_time=0.0;
    initialized=false;
    ElementList.clear();
    EventList.clear();
}
Simulation::~Simulation()
 {
     vector<MyBase*>::iterator itb=ElementList.begin();
     for(;itb!=ElementList.end();itb++)
     {
        MyBase *bs=(*itb);
        if(bs->getType()==MACHINE_TYPE)
        {
            ((Machine*)bs)->~Machine();
        }
        else if(bs->getType()==QUEUE_TYPE)
        {
            ((Queue*)bs)->~Queue();
        }
        else{
            cout<<"ERROR...simulation."<<endl;
        }
     }

     vector<Event*>::iterator ite=EventList.begin();
     for(;ite!=EventList.end();ite++)
     {
         if((*ite)!=(Event*)NULL){
            delete (*ite);
         }
     }
     ElementList.clear();
     EventList.clear();
 }

void Simulation::run()
{
    if(!initialized)
    {
        Event* INIT=new Event;
        INIT->Event_time=0.0;
        INIT->Event_Type=EVT_INIT;
        CollectEvent(INIT);
        initialized=true;
        //NextEvent();
    }
    showQueues();
    while(!(EventList.empty()))
    {
            NextEvent();
    }
    cout<<"Simulation Over.[At Time:"<<sim_time<<"]"<<endl;

}
void Simulation::NextEvent()
{
    vector<Event*>::iterator it=EventList.begin();
    vector<Event*>::iterator it_tmp=EventList.end();
    double tmp=-99.0;
    double tmp2=-10.0;
    Event* evt=(Event*)NULL;
    for(;it!=EventList.end();it++)
    {
        tmp2=(*it)->Event_time;
        if(tmp2<tmp || tmp<0)
        {
            tmp=tmp2;
            evt=(*it);
            it_tmp=it;
        }
    }
    //now evt is the nearest event;
    if(it_tmp!=EventList.end())
    {
        EventList.erase(it_tmp);
    }
    //
    sim_time=evt->Event_time;
    //cout<<"[TIME]"<<sim_time<<endl;

    vector<MyBase*>::iterator itb=ElementList.begin();
    for(;itb!=ElementList.end();itb++)
    {
        MyBase* theElement=(*itb);
        if(theElement->getType()==MACHINE_TYPE)
        {
            //cout<<"A machine is found to response."<<endl;
            ((Machine*)theElement)->RespondEvent(evt);
        }
        else if(theElement->getType()==QUEUE_TYPE)
        {
            //
        }
    }
}

void Simulation::CollectEvent(Event* evt)
{
    EventList.push_back(evt);
}

void Simulation::AddElement(MyBase* abs)
{
    abs->setSimulation(this);
    ElementList.push_back(abs);
}


void Simulation::showQueues()
{
    cout<<"==== TIME "<<sim_time<<" ======="<<endl;
    vector<MyBase*>::iterator itb=ElementList.begin();
    for(;itb!=ElementList.end();itb++)
    {
        MyBase* theElement=(*itb);
        if(theElement->getType()==QUEUE_TYPE)
        {
            Queue* q=(Queue*)(theElement);
            q->showContent();
        }
    }
    cout<<"=========================\n\n"<<endl;
}


int MyBase::ELE_ID=0;
MyBase::MyBase()
{
    //ctor
    ELE_ID++;
    ID=ELE_ID;
}

MyBase::~MyBase()
{
    //dtor
}

int MyBase::getID()
{
    return ID;
}

int MyBase::getType()
{
    return eType;
}

void MyBase::setSimulation(Simulation* asim)
{
    sim=asim;
}


/*
PrNum   Types
1      11-->21-->31
2      11-->22-->32
3      12-->23-->33
4      12-->23-->34
*/


double CalcAjustTime(int Type0, int Type1)//from type0 to type1
{
    double rs=0.0;
    if(Type0<0)
    {
        rs=0.0;
    }
    else if(Type0==11)
    {
        if(Type1==11)
        {
            rs=0.0;
        }
        else if(Type1==12)
        {
            rs=0.5;//11-->12 ajust time is 0.5
        }
    }
    else if(Type0==12)
    {
        if(Type1==12)
        {
            rs=0.0;
        }
        else if(Type1==11)
        {
            rs=0.5;//11-->12 ajust time is 0.5
        }
    }
    else if(Type0==21)
    {
        if(Type1==21)
        {
            rs=0.0;
        }
        else if(Type1==22)
        {
            rs=0.5;
        }
        else if(Type1==23)
        {
            rs=0.5;
        }
    }
    else if(Type0==22)
    {
        if(Type1==21)
        {
            rs=0.5;
        }
        else if(Type1==22)
        {
            rs=0.0;
        }
        else if(Type1==23)
        {
            rs=0.5;
        }
    }
    else if(Type0==23)
    {
        if(Type1==21)
        {
            rs=0.5;
        }
        else if(Type1==22)
        {
            rs=0.5;
        }
        else if(Type1==23)
        {
            rs=0.0;
        }
    }
    else if(Type0==31)
    {
    }
    else if(Type0==32)
    {
    }
    else if(Type0==33)
    {
    }
    else if(Type0==34)
    {
    }
    return rs;
}

double CalcSetupTime(int partType)
{
    double rs=0.0;
    if(partType==11)
    {
        rs=0.5;
    }
    else if(partType==12)
    {
        rs=0.5;
    }
    else if(partType==21)
    {
        rs=0.5;
    }
    else if(partType==22)
    {
        rs=0.5;
    }
    else if(partType==23)
    {
        rs=0.5;
    }
    else
    {
        cout<<"wrong part type."<<endl;
    }
    return rs;
}

double CalcProcessTime(int partType, int ProcessNum)
{
    double rs=0.0;
    if(partType==11)
    {
        if(ProcessNum==1)
        {
            rs=1;//11-->21
        }
        else if(ProcessNum==2)
        {
            rs=1.5;//11-->12
        }
        else
        {
            cout<<"wrong part type or process number."<<endl;
        }
    }
    else if(partType==12)
    {
        if(ProcessNum==3 || ProcessNum==4)
        {
            rs=1;//21-->23
        }
        else
        {
            cout<<"wrong part type or process number."<<endl;
        }
    }
    else if(partType==21)
    {
        if(ProcessNum==1)
        {
            rs=1;//21-->31
        }
        else
        {
            cout<<"wrong part type or process number."<<endl;
        }
    }
    else if(partType==22)
    {
        if(ProcessNum==2)
        {
            rs=1.5;//22->32
        }
        else
        {
            cout<<"wrong part type or process number."<<endl;
        }
    }
    else if(partType==23)
    {
        if(ProcessNum==3)
        {
            rs=1;//23-->33
        }
        else if(ProcessNum==4)
        {
            rs=2;//23-->34
        }
        else
        {
            cout<<"wrong part type or process number."<<endl;
        }
    }
    else
    {
        cout<<"wrong part type or process number."<<endl;
    }

    return rs;
}

int CalcPartType(int partType, int ProcessNum)
{
    int rs=-1;
    if(partType==11)
    {
        if(ProcessNum==1)
        {
            rs=21;
        }
        else if(ProcessNum==2)
        {
            rs=22;
        }
        else{
            cout<<"wrong process num."<<endl;
        }
    }
    else if(partType==12)
    {
        if(ProcessNum==3 || ProcessNum==4)
        {
            rs=23;
        }
        else
        {
            cout<<"wrong process num."<<endl;
        }
    }
    else if(partType==21)
    {
        if(ProcessNum==1)
        {
            rs=31;
        }
        else
        {
            cout<<"wrong process num."<<endl;
        }
    }
    else if(partType==22)
    {
        if(ProcessNum==2)
        {
            rs=32;
        }
        else
        {
            cout<<"wrong process num."<<endl;
        }
    }
    else if(partType==23)
    {
        cout<<"debug info : 23 process "<<ProcessNum<<endl;
        if(ProcessNum==3)
        {
            rs=33;
        }
        else if(ProcessNum==4)
        {
            rs=34;
        }
        else
        {
            cout<<"wrong process num."<<endl;
        }
    }
    else{
        cout<<"wrong process num or part type."<<endl;
    }
    return rs;
}

