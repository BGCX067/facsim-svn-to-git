#ifndef SIMBASE_H
#define SIMBASE_H

#include "string.h"
#include <vector>

class simElementList;

class simBase
{
public:
    simBase();
    virtual ~simBase();

protected:
    long ID;//对象标识
    char name[256];//名称标识
    long ElementTypeID;//
    simElementList* theList;

private:
public:
    static long count;
    long GetID()
    {
        return ID;
    }
    void SetID(long id)
    {
        ID=id;
    }
    void SetName(char* ac)
    {
        strcpy(name,ac);
    }
    char* GetName()
    {
        return name;
    }
    void SetElementTypeID(long etID)
    {
        ElementTypeID=etID;
    }
    long GetElementTypeID()
    {
        return ElementTypeID;
    }
    simElementList* GetElementList()
    {
        return theList;
    }
    void BindElementList(simElementList* aL)
    {
        theList=aL;
    }

};

#define TYPE_PART           0
#define TYPE_PART_SOURCE    1
#define TYPE_QUEUE          2
#define TYPE_MACHINE        3

#define ELEMENT_TYPE_STR des_str

char* GetElementTypeDescription(long tp);

/*
ElementTypeID    String
0               Part
1               PartSource
2               Queue
3               Machine



*/

#include "simqueue.h"
#include "simmachine.h"

#ifndef __WIN_PATH__
   #include "angelscript.h"
#else
   #include "Add-ons/include/angelscript.h"
#endif

class simEvent
{

    double m_time;
    long element_type_id;
    long elementID;
    long event_type;
    long para1;
    long para2;
public:
    simEvent(double,long,long,long);
    simEvent(double,long,long,long,long,long);
    ~simEvent();
    double GetTime()
    {
        return m_time;
    }
    void SetTime(double tm)
    {
        m_time=tm;
    }
    void SetElementID(long el_id)
    {
        elementID=el_id;
    }
    long GetElementID()
    {
        return elementID;
    }
    void SetElementTypeID(long tid)
    {
        element_type_id=tid;
    }
    long GetElementTypeID()
    {
        return element_type_id;
    }
    void SetEventType(long etp)
    {
        event_type=etp;
    }
    long GetEventType()
    {
        return event_type;
    }
    void SetPara1(long pr1)
    {
        para1=pr1;
    }
    long GetPara1()
    {
        return para1;
    }
    void SetPara2(long pr2)
    {
        para2=pr2;
    }
    long GetPara2()
    {
        return para2;
    }
};

class simMachine;
class simClock;
class simElementList
{
    protected:
    std::vector<simQueue*> QueueList;
    std::vector<simMachine*> MachineList;

    //for running
    std::vector<simMachine*> BlockedMachineList; //被堵机器列表，每一事件均检测是否可推出
    std::vector<simMachine*> HungryMachineList;//饿机器列表，每一事件均检测是否可拉入

    std::vector<simEvent*> EventList;

    asIScriptEngine* engine;

    simClock* clock;

public:
    simElementList();
    ~simElementList();
    simMachine* ID2Machine(long theID);//from ID to find the Machine
    simQueue* ID2Queue(long theID);//from ID to find out the Queue

    void AddMachine(simMachine*);
    void AddQueue(simQueue*);

    double GetClockTime();//{return clock->GetClockTime();}

    asIScriptEngine* GetScriptEngine();

    void CollectEvent(simEvent* evt);

friend class simProject;
friend class simView;

};



class simClock
{
protected:
    double currentTime;
    double nextTime;
    simElementList* theList;
public:
    void forward();
    void bind(simElementList* EL);
    double GetClockTime(){return currentTime;}
    simClock(simElementList* EL);
    ~simClock();
};

////Event Type Define////
//for machine
/*
#define EVENT_PULL      1
#define EVENT_PUSH      2
#define EVENT_SETUP     3
#define EVENT_PROCESS   4
#define EVENT_SETUP_OVER    5
#define EVENT_PROCESS_OVER  6
#define EVENT_BLOCKED  7

*/

//for queue
#define SIM_EVT_PART_OUT  11
#define SIM_EVT_PART_IN   12
#define SIM_EVT_FULL   13

//for machine
#define SIM_EVT_BEGIN_IDLE      101
#define SIM_EVT_BEGIN_BUSY      102
#define SIM_EVT_SETUP_BEGIN     103
#define SIM_EVT_SETUP_OVER      104
#define SIM_EVT_PROCESS_BEGIN   105
#define SIM_EVT_PROCESS_OVER    106
#define SIM_EVT_BLOCK_BEGIN     107
#define SIM_EVT_BLOCK_OVER      108







///////////////////////////

void EmptyAction();

//////Element Status Define  ////

#define IDLE 1
#define BUSY 2
#define PROCESS_ING 3
#define SETUP_ING   4
#define BLOCKED     5


////////////////////////////////

#include <wx/string.h>
#include <string>

wxString stdString2wxString(std::string& std_Str);
std::string wxString2stdString(wxString& wxStr);
#ifndef _swxT
#define _swxT stdString2wxString
#endif

#endif // SIMBASE_H
