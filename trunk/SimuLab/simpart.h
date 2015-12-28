#ifndef SIMPART_H
#define SIMPART_H

#include "simbase.h"

class simPart
{
public:
    simPart();
    simPart(char* cname);
    virtual ~simPart();
protected:
    simBase info;//零件需要基本信息不？

    long partType;//零件类型

    long priority;//加工优先级

    long processID;//工艺ID

    long orderID;//订单ID

    double holdingCost;//在制品库存持有成本

private:
    //
public:
    long GetID()
    {
        return info.GetID();
    }
    char* GetName()
    {
        return info.GetName();
    }
    void SetName(char * ac)
    {
        info.SetName(ac);
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


    void SetType(long tp)
    {
        partType=tp;
    }
    long GetType()
    {
        return partType;
    }
    void SetPriority(long pr)
    {
        priority=pr;
    }
    long GetPriority()
    {
        return priority;
    }
    void SetProcess(long prcs)
    {
        processID=prcs;
    }
    long GetProcess()
    {
        return processID;
    }
    void SetOrder(long odr)
    {
        orderID=odr;
    }
    long GetOrder()
    {
        return orderID;
    }
    void SetHoldingCost(double hc)
    {
        holdingCost=hc;
    }
    double GetHodingCost()
    {
        return holdingCost;
    }
};

#endif // SIMPART_H
