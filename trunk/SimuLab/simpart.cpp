/*
This is written by WANG MengChang
*/#include "simpart.h"

simPart::simPart()
{
    //ctor
    SetElementTypeID(TYPE_PART);

    partType=-1;//零件类型

    priority=-1;//加工优先级

    processID=-1;//工艺ID

    orderID=-1;//订单ID

    holdingCost=-1;//在制品库存持有成本

    char abc[]="name unknown";
    SetName(abc);

}

simPart::simPart(char* cname)
{
    SetElementTypeID(TYPE_PART);
        partType=-1;//零件类型

    priority=-1;//加工优先级

    processID=-1;//工艺ID

    orderID=-1;//订单ID

    holdingCost=-1;//在制品库存持有成本

    SetName(cname);

}

simPart::~simPart()
{
    //dtor
}
