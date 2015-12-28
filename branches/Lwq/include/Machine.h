#ifndef MACHINE_H
#define MACHINE_H

#include "MyBase.h"
#include "Part.h"
#include "Queue.h"


class Machine : public MyBase
{
    public:
        Machine();
        virtual ~Machine();
        Part* getThePart();
        int getStatus();

        void setQueues(Queue* from,Queue* to);
        void setProcessNum(int prcsnum);
        int getProcessNum();

        bool RespondEvent(Event* evt);

        bool TryPull();
        bool TryPush();
        void Process();

        void setSetupTime(double stt);
        void setProcessTime(double pst);
    protected:
        Part* thePart;
        int status;
        Queue* FROM;//源头
        Queue* TO;//去向
        int ProcessNum;//工艺路线序号

        double ajusttime;//如果与上一次加工零件不同，需要重新调整的时间
        double setuptime;//装夹时间
        double processtime;//加工时间

        void CalcAjustTime();
        void CalcSetupTime();
        void CalcProcessTime();

        //double ;
        int NowPartType;
        int LastPartType;
    private:
};

#endif // MACHINE_H
