#include "../include/Part.h"

int Part::Part_ID=0;


Part::Part()
{
    //ctor
    Part_ID++;
    ID=Part_ID;
    WIP_Type=-1;//非法的，小于0
    enter_time=0.0;
    leave_time=999999.99999;
}

Part::~Part()
{
    //dtor
}

int Part::getType()
{
    return WIP_Type;
}

void Part::setType(int tp)
{
    WIP_Type=tp;
}

void Part::setGPriority(int gp)
{
    global_priority=gp;
}
void Part::setLPriority(int lp)
{
    local_priority=lp;
}
int Part::getGPriority()
{
    return global_priority;
}
int Part::getLPriority()
{
    return local_priority;
}

int Part::getProcessNum()
{
    return process_num;
}
void Part::setProcessNum(int pr)
{
    process_num=pr;
}

int Part::getID()
{
    return ID;
}
