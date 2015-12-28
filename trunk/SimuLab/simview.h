#ifndef SIMVIEW_H
#define SIMVIEW_H

//simuLab的视图类，用于在主窗口绘图

#include <wx/treectrl.h>

#include "simproject.h"
class simProject;
class simView
{
    public:
        simView();
        virtual ~simView();
        void bind(simProject*);
        void refresh();

        void SetTree(wxTreeCtrl*);
        wxTreeCtrl* GetTree(){return theTreeCtrl;}
    protected:
        simProject* theProject;
        wxTreeCtrl* theTreeCtrl;
    private:
};

#endif // SIMVIEW_H
