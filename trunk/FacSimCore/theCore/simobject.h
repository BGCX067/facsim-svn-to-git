// Class automatically generated by Dev-C++ New Class wizard




#ifndef SIMOBJECT_H
#define SIMOBJECT_H

typedef int ObjectType;

#define MACHINE_TYPE 1
#define QUEUE_TYPE   2 
 

//#include "simevent.h"
/*
 * �������¼�����������
 */
class simObject
{
	public:
        
        ObjectType theObjectType; 
        int InstanceNum;//������ 
		// class constructor
		simObject();
		// class destructor
		~simObject();
		virtual bool response(int eventTypeID) {return true;}
        bool setInstanceNum(int kk){InstanceNum=kk;} 
};

#endif // SIMOBJECT_H