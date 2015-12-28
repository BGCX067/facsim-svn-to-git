#ifndef SIMPROJECT_H
#define SIMPROJECT_H

//SimuLab的文档类，用于维护模型数据

#include <vector>
#include <string>
#include "simbase.h"
#include "simmachine.h"
#include "simqueue.h"

#include "simview.h"
class simView;

class simProject
{
    public:
        simProject();
        virtual ~simProject();
        bool AddPartSource();
        bool AddMachine(simMachine*);
        bool AddQueue(simQueue*);

        bool AddView(simView*);//do not use in your code, it called by simView::bind()
        bool UpdateViews();



    protected:
        simElementList* theList;
        std::vector<simView*> theViewList;
    private:
};

#endif // SIMPROJECT_H
