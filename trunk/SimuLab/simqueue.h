#ifndef SIMQUEUE_H
#define SIMQUEUE_H

#include "simbase.h"
#include "simpart.h"

#include <vector>
#include <iostream>
class simPart;

class simQueue
{
public:
    simQueue();
    simQueue(long cp);
    virtual ~simQueue();
protected:
    simBase info;
    long capacity;//容量
    std::vector<simPart*> content;//内容，指向零件的指针向量。
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
    void BindElementList(simElementList* aL)
    {
        info.BindElementList(aL);
    }

    void SetCapacity(long cp)
    {
        capacity=cp;
    }
    long GetCapacity()
    {
        return capacity;
    }

    bool IsEmpty();
    bool IsFull();
    bool GetAPartIn(simPart* pP);
    simPart* GetAPartOut();
    simPart* GetPartOutByPriority(long prrt);//取出零件，取出后删除
    simPart* GetPartOutPriorest();

    simPart* GetAPartAt(long loc);//不取出，仅获取其地址
};

#endif // SIMQUEUE_H
