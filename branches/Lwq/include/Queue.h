#ifndef QUEUE_H
#define QUEUE_H

#include "MyBase.h"
#include "Part.h"
#include <vector>

class Queue : public MyBase
{
    public:
        Queue();
        virtual ~Queue();

        Part* givePartHighestGPriority();//取出最高全局优先级零件
        Part* givePartByGPriority(int gpr);

        Part* givePartHighestLPriority();
        Part* givePartByLPriority(int lpr);

        Part* givePartByType(int wip_type);

        int getNowHighestGPriority();//The Heighest Global Priority in the Queue
        int getNowHighestLPriority();//The Heighest Local  Priority in the Queue

        Part* AtByType(int wip_type);//find the part that belongs to wip_type
        Part* AtByGPriority(int gpr);//
        Part* AtByLPriority(int lpr);//
        Part* AtByProcessNum(int prc_num);//
        Part* AtByID(int id);//

        bool getAPartIn(Part* ap);

        void showContent();

    protected:
        std::vector<Part*> content;
    private:
};

#endif // QUEUE_H
