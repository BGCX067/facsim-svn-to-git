// Class automatically generated by Dev-C++ New Class wizard

#include <iostream>
#include "simobject.h"
#include "simmachine.h"
#include "simevent.h"
#include "simpart.h"
#include "simqueue.h"
#include "simclock.h"

#include "simmodel.h"
extern simModel theModel;

#include "simeventlist.h" // class's header file

// class constructor
simEventList::simEventList()
{
	// insert your code here
	nowEventNum=0;
    for(int i=0;i<EVENT_MAX;i++)
    {
        theList[i]=(simEvent*)NULL;
    } 
}

// class destructor
simEventList::~simEventList()
{
	// insert your code here
}
bool simEventList::AddEvent(simEvent* pEvt)
{
    //
    //printf("\n\tAdding Event\n");
    //printf("\t%f\t:%d\n",pEvt->happenTime,pEvt->theType); 
    theList[nowEventNum]=pEvt;
    nowEventNum++;
    return true; 
} 

simEvent* simEventList::theFirstEvent()
{
    //simEventList::
    double deltaTime=32766.9999;
    int k=-1;
    int i=0;
    simEvent* pEvt=(simEvent*)NULL;
    for(i=0;i<nowEventNum;i++)
    {
        if(theList[i]==(simEvent*)NULL)
        {
            continue;
        }
        double xx=theList[i]->happenTime-theModel.theClock.nowTime;
        if(xx<deltaTime)
        {
            deltaTime=xx;
            k=i;
        }
    }
    if(k<0||k>=EVENT_MAX)
    {
        return (simEvent*)NULL;        
    }
    else
    {
        if(theList[k]==(simEvent*)NULL)
        {
            return (simEvent*)NULL;
        }
        pEvt=theList[k];
        //��������
        for(int i=k;i<nowEventNum-1;i++)
        {
            theList[i]=theList[i+1]; 
        } 
        theList[nowEventNum-1]= (simEvent*)NULL;
        nowEventNum--;
        return pEvt;
    }    
} 

bool simEventList::notifyObjects()
{
    //�����¼�����ʱ��֪ͨ��״̬��Ԫ��
    for(int i=0;i<theModel.theObjectList.TotalObject;i++)
    {
        if(MACHINE_TYPE==theModel.theObjectList.theList[i]->theObjectType)
        {
            simMachine* pM=(simMachine*)theModel.theObjectList.theList[i];
            if(pM->haveToResponseEventList){ 
                pM->check();  
            } 
        } 
        else{
            continue; 
        } 
    } 
    return true; 
} 


bool simEventList::happenFirst()
{
    simEvent* pEvt = theFirstEvent();
    if(pEvt==(simEvent*)NULL)
    {
        return false; 
    } 
    else
    {
        pEvt->happen(); 
        
        notifyObjects(); 
        return true; 
    } 
} 



