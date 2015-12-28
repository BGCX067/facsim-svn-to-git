//MyModel.cpp 
#include <iostream>
#include "simobject.h"
#include "simmachine.h"
#include "simevent.h"
#include "simpart.h"
#include "simqueue.h"
#include "simclock.h"

#include "simobjectlist.h" 
#include "simmodel.h"
using namespace std;

extern simModel theModel;


void EditModel()
{
    simPart theP[6];
    
    simMachine* ap=new simMachine();
    ap->setInstanceNum(1);
    
    simMachine* ap2=new simMachine();
    ap2->setInstanceNum(2);
    
    simMachine* ap3=new simMachine();
    ap3->setInstanceNum(3);
    
    simQueue* aQ=new simQueue();
    aQ->setInstanceNum(1);
    aQ->GetPart(&theP[0]);
    aQ->GetPart(&theP[1]);
    aQ->GetPart(&theP[2]);
    aQ->GetPart(&theP[3]);
    aQ->GetPart(&theP[4]);
    aQ->GetPart(&theP[5]);
    
    simQueue* aQ2=new simQueue();
    aQ2->setInstanceNum(2);
    
    simQueue* aQ3=new simQueue();
    aQ3->setInstanceNum(3);
    
    ap->theSource=aQ;
    ap->theDestination=aQ2;
    
    ap2->theSource=aQ2;
    ap2->theDestination=aQ3;
    
    ap3->theSource=aQ;
    ap3->theDestination=aQ3; 
    
    theModel.theObjectList.AddSimObject(ap);
    theModel.theObjectList.AddSimObject(ap2);
    theModel.theObjectList.AddSimObject(aQ);
    theModel.theObjectList.AddSimObject(aQ2);
    theModel.theObjectList.AddSimObject(aQ3);
    theModel.theObjectList.AddSimObject(ap3);
}

void RunModel()
{
    theModel.run();
}

void MyModel()
{
    EditModel();
    RunModel();
}

 

