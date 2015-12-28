#include <iostream>
#include "include/MyBase.h"
#include "include/Part.h"
#include "include/Machine.h"
#include "include/Queue.h"

using namespace std;

/*
设置时间、工艺参数，请修改以下几个全局函数，在src/MyBase.cpp文件中
double CalcAjustTime(int Type0, int Type1);//from type0 to type1
double CalcSetupTime(int partType);
double CalcProcessTime(int partType, int ProcessNum);
int CalcPartType(int partType, int ProcessNum);
*/

int main()
{
    cout << "================================" << endl;
    cout << "\tReScheduling" << endl;
    cout << "================================" << endl;

    Simulation asim;
    Machine* am=new Machine();
    Machine* am2=new Machine();
    Queue* aq1=new Queue();
    Queue* aq2=new Queue();
    Queue* aq3=new Queue();

    Part* ap=new Part();
    Part* ap2=new Part();
    Part* ap3=new Part();
    ap->setLPriority(1);
    ap->setGPriority(1);
    ap->setType(11);
    ap->setProcessNum(1);

    ap2->setLPriority(2);
    ap2->setGPriority(2);
    ap2->setType(12);
    ap2->setProcessNum(4);

    ap3->setLPriority(3);
    ap3->setGPriority(3);
    ap3->setType(11);
    ap3->setProcessNum(2);

    aq1->getAPartIn(ap);
    aq1->getAPartIn(ap2);
    aq1->getAPartIn(ap3);

    am->setQueues(aq1,aq2);
    //am->setSetupTime(1.0);
    //am->setProcessTime(2.0);

    am2->setQueues(aq2,aq3);

    asim.AddElement(am);
    asim.AddElement(am2);
    asim.AddElement(aq1);
    asim.AddElement(aq2);
    asim.AddElement(aq3);
//
    asim.run();
    //asim.run();



    return 0;
}
