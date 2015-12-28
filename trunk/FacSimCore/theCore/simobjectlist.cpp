// Class automatically generated by Dev-C++ New Class wizard

#include <iostream>
#include "simobject.h"
#include "simmachine.h"
#include "simevent.h"
#include "simpart.h"
#include "simqueue.h"
#include "simclock.h"

#include "simobjectlist.h" // class's header file

// class constructor
simObjectList::simObjectList()
{
	// insert your code here
	TotalObject=0;
	for(int i=0;i<MAX_OBJECT_NUM;i++) 
	{ 
	   theList[i]=(simObject*)NULL;
	} 
}

// class destructor
simObjectList::~simObjectList()
{
	// insert your code here
}

bool simObjectList::AddSimObject(simObject* asimObj)
{
    theList[TotalObject]=asimObj;
    TotalObject++;
    return true; 
} 
 

