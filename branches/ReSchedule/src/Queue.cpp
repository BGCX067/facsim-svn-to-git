#include "../include/Queue.h"

using namespace std;

Queue::Queue()
{
    //ctor
    eType=QUEUE_TYPE;
    content.clear();
}

Queue::~Queue()
{
    //dtor
    std::vector<Part*>::iterator it=content.begin();
    for (;it!=content.end();it++)
    {
        if ((*it)!=(Part*)NULL)
        {
            delete (*it);
        }
    }
    content.clear();
}

Part* Queue::givePartHighestGPriority()
//取出最高全局优先级零件
{
    Part* rs=(Part*)NULL;
    rs=AtByGPriority(getNowHighestGPriority());
    if(rs==(Part*)NULL)
    {
        //If Failed;
        return rs;
    }
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getID()==rs->getID())
        {
            content.erase(it);
            break;
        }
    }
    return rs;
}


Part* Queue::givePartByGPriority(int gpr)
{
    Part* rs=(Part*)NULL;
    rs=AtByGPriority(gpr);
    if(rs==(Part*)NULL)
    {
        return rs;
    }
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getID()==rs->getID())
        {
            content.erase(it);
            break;
        }
    }
    return rs;
}

Part* Queue::givePartHighestLPriority()
{
    Part* rs=(Part*)NULL;
    rs=AtByLPriority(getNowHighestLPriority());
    if(rs==(Part*)NULL)
    {
        //If Failed;
        //std::cout<<"CANNOT find the NowHighestLPriority part.[Queue.cpp]"<<std::endl;
        return rs;
    }
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getID()==rs->getID())
        {
            content.erase(it);
            break;
        }
    }
    return rs;
}
Part* Queue::givePartByLPriority(int lpr)
{
    Part* rs=(Part*)NULL;
    rs=AtByLPriority(lpr);
    if(rs==(Part*)NULL)
    {
        return rs;
    }
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getID()==rs->getID())
        {
            content.erase(it);
            break;
        }
    }
    return rs;
}

Part* Queue::givePartByType(int wip_type)
{
    Part* rs=(Part*)NULL;
    rs=AtByType(wip_type);
    if(rs==(Part*)NULL)
    {
        return rs;
    }
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getID()==rs->getID())
        {
            content.erase(it);
            break;
        }
    }
    return rs;
}

int Queue::getNowHighestGPriority()//The Heighest Global Priority in the Queue
{
    int rs=-1;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        int tmp=(*it)->getGPriority();
        if(tmp>=0 && (tmp<rs || rs<0))
        {
            rs=tmp;
        }
    }
    return rs;
}
int Queue::getNowHighestLPriority()//The Heighest Local  Priority in the Queue
{
    int rs=-1;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        int tmp=(*it)->getLPriority();
        if(tmp>=0 && (tmp<rs || rs<0))
        {
            rs=tmp;
        }
    }
    return rs;
}
Part* Queue::AtByType(int wip_type)//find the first part that belongs to wip_type
{
    Part* rs=(Part*)NULL;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getType()==wip_type)
        {
            rs=(*it);
            break;
        }
    }
    return rs;
}
Part* Queue::AtByGPriority(int gpr)//
{
    Part* rs=(Part*)NULL;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getGPriority()==gpr)
        {
            rs=(*it);
            break;
        }
    }
    return rs;
}
Part* Queue::AtByLPriority(int lpr)//
{
    Part* rs=(Part*)NULL;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getLPriority()==lpr)
        {
            rs=(*it);
            break;
        }
    }
    return rs;
}
Part* Queue::AtByProcessNum(int prc_num)//
{
    Part* rs=(Part*)NULL;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getProcessNum()==prc_num)
        {
            rs=(*it);
            break;
        }
    }
    return rs;
}
Part* Queue::AtByID(int id)//
{
    Part* rs=(Part*)NULL;
    vector<Part*>::iterator it=content.begin();
    for(;it!=content.end();it++)
    {
        if((*it)->getID()==id)
        {
            rs=(*it);
            break;
        }
    }
    return rs;
}

bool Queue::getAPartIn(Part* ap)
{
    content.push_back(ap);
    return true;
}

void Queue::showContent()
{
    vector<Part*>::iterator itp=content.begin();
    cout<<"Q["<<ID<<"] ";
    for(;itp!=content.end();itp++)
    {
        cout<<"<"<<(*itp)->getType()<<"> ";
    }
    cout<<endl;
}

