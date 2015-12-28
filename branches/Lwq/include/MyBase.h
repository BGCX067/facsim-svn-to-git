#ifndef MYBASE_H
#define MYBASE_H

#include <vector>
#include <iostream>

using namespace std;
//元素类型定义
#define QUEUE_TYPE 1
#define MACHINE_TYPE 2
#define LWQ_STAGE_TYPE 3



/*
编号  状态                  进入事件                                   动作          离开事件
0   IDLE        E01：BEGIN_IDLE      PULL    E02：BEGIN_BUSY
1   SETING_UP   E11：SETUP_BEGIN     SETUP   E12：SETUP_OVER
2   PROCESSING  E21：PROCESS_BEGIN   PROCESS E22：PROCESS_OVER
3   BLOCKED     E31：BLOCK_BEGIN     PUSH    E32：BLOCK_OVER
*/
//事件类型定义
#define EVT_INIT            0
#define EVT_BEGIN_IDLE      1
#define EVT_BEGIN_BUSY      2
#define EVT_SETUP_BEGIN     3
#define EVT_SETUP_OVER      4
#define EVT_PROCESS_BEGIN   5
#define EVT_PROCESS_OVER    6
#define EVT_BLOCK_BEGIN     7
#define EVT_BLOCK_OVER      8

//状态类型定义
#define STATUS_IDLE         1
#define STATUS_SETING_UP    2
#define STATUS_PROCESSING   3
#define STATUS_BLOCKED      4

/*
 LWQ_STAGE Events Table
  * 编号 状态 进入事件 动作 离开事件
  * 0	IDEL
 */


struct Event
{
    int Element_ID;
    int Event_Type;
    double Event_time;
};

class MyBase;

class Simulation
{
public:
    Simulation();
    ~Simulation();
    void CollectEvent(Event* evt);
    void AddElement(MyBase* abs);
    void run();

    void showQueues();
protected:
    double sim_time;
    bool initialized;//已经启动了吗？
    vector<MyBase*> ElementList;
    vector<Event*> EventList;


    void NextEvent();
};

class MyBase
{
    public:
        MyBase();
        virtual ~MyBase();
        int getID();
        int getType();
        void setSimulation(Simulation* asim);
    protected:
        int eType;//元素类型
        int ID;
        static int ELE_ID;
        Simulation* sim;
    private:
};


//这里是调整时间、工艺参数的地方
double CalcAjustTime(int Type0, int Type1);//from type0 to type1
double CalcSetupTime(int partType);
double CalcProcessTime(int partType, int ProcessNum);
int CalcPartType(int partType, int ProcessNum);


#endif // MYBASE_H
