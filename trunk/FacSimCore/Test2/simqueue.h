// Class automatically generated by Dev-C++ New Class wizard
#include "simpart.h" 

#ifndef SIMQUEUE_H
#define SIMQUEUE_H

#include "simobject.h" // inheriting class's header file


#define QUEUE_LENGTH_MAX 100 

/*
 * 队列/缓冲区类
 */
class simQueue : public simObject
{
	public:
		// class constructor
		int Capacity;//容量
        simPart *content[QUEUE_LENGTH_MAX];
        int nowIn; 
		simQueue();
		simQueue(int Capa);
		// class destructor
		~simQueue();
		simPart *GivePart();
		bool setCapacity(int capa); 
        bool GetPart(simPart *aPart); 
		bool canIn();
		bool canOut();
		bool showContent(); 
};

#endif // SIMQUEUE_H
