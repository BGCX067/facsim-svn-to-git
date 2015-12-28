/*
This is written by WANG MengChang
*/#include "simqueue.h"

simQueue::simQueue()
{
    //ctor
    SetElementTypeID(TYPE_QUEUE);
    SetCapacity(10);//default 10
    char abc[]="NameUnkown(Queue)";
    SetName(abc);
    content.clear();
}


simQueue::simQueue(long cp)
{
    //ctor
    SetElementTypeID(TYPE_QUEUE);
    SetCapacity(cp);
    char abc[]="NameUnkown(Queue)";
    SetName(abc);
}

simQueue::~simQueue()
{
    //dtor
}


bool simQueue::IsEmpty()
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
bool simQueue::IsFull()
{
    if(long(content.size())>=capacity){
        return true;
    }
    else{
        return false;
    }
}
bool simQueue::GetAPartIn(simPart* pP)
{
    if(!(IsFull()))
    {
        if(pP!=(simPart*)NULL){
            content.push_back(pP);
            return true;
        }
        else{
            std::cout<<"a NULL part is delevering"<<std::endl;
            return false;
        }
    }
    else{
        return false;
    }
}
simPart* simQueue::GetAPartOut()
{
    simPart* rs=(simPart*)NULL;
    if(!(content.empty()))
    {
        //rs=content.pop();
        std::vector<simPart*>::iterator it=content.begin();
        rs=(*it);
        content.erase(it);
    }
    return rs;
}
simPart* simQueue::GetPartOutByPriority(long prrt)
{
    simPart* rs=(simPart*)NULL;
    if(!(content.empty()))
    {
        std::vector<simPart*>::iterator it=content.begin();
        std::vector<simPart*>::iterator it_end=content.end();
        for(;it!=it_end;it++)
        {
            if((*it)->GetPriority()==prrt)
            {
                rs=(*it);
                content.erase(it);
                break;
            }
        }
    }
    return rs;
}
simPart* simQueue::GetPartOutPriorest()
{
    simPart* rs=(simPart*)NULL;
    //sort
    long pr=999000;
    std::vector<simPart*>::iterator it=content.begin();
    std::vector<simPart*>::iterator it_end=content.end();
    for(;it!=it_end;it++)
    {
        long tmppr=(*it)->GetPriority();
        if( tmppr>=0 && tmppr< pr)
        {
            pr=tmppr;
            rs=(*it);
        }
    }
    //after finding, now erase the list
    if(rs!=(simPart*)NULL)
    {
        content.erase(it);
    }
    return rs;
}

simPart* simQueue::GetAPartAt(long loc)
{
    simPart* rs=(simPart*)NULL;
    if(!(content.empty()))
    {
        if(loc<long(content.size()) && loc>=0)
        {
            rs=content[loc];
        }
    }
    return rs;
}


