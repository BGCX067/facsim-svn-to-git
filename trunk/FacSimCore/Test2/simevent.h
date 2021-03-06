// Class automatically generated by Dev-C++ New Class wizard

#ifndef SIMEVENT_H
#define SIMEVENT_H
#include "simobject.h"
/*
 * 事件类型
 * 本程序仅考虑机器、缓冲区的基本事件
 */
 
#define MACHINE_PULL  0
#define MACHINE_BLOCK 1
#define MACHINE_PUSH  2

#define QUEUE_PART_IN 0
#define QUEUE_PART_OUT 1

#define EVENT_LIST_CHANGED 99 
 
typedef int EventType; 
 
class simEvent
{
	public:
        simObject *theObj;
        EventType theType;
        double happenTime; 
        bool happen(); 
        simEvent(simObject *pObj,EventType evTp,double hpTime){theObj=pObj;theType=evTp;happenTime=hpTime;} 
		// class constructor
		simEvent();
		// class destructor
		~simEvent();
};

#endif // SIMEVENT_H
