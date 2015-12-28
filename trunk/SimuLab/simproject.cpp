/*
This is written by WANG MengChang
*/#include "simproject.h"
#include "simbase.h"
#include <string>

#include <wx/treebase.h>

simProject::simProject()
{
    //ctor
     theList=new simElementList();
     theViewList.clear();

}

simProject::~simProject()
{
    //dtor
    delete theList;
}

bool simProject::AddQueue(simQueue* aq)
{
    theList->AddQueue(aq);
    return true;
}

bool simProject::AddMachine(simMachine* am)
{
    theList->AddMachine(am);
    return true;
}
bool simProject::AddView(simView* av)
{
    theViewList.push_back(av);
    return true;
}

bool simProject::UpdateViews()
{
    printf("Begin update.\n");
    std::vector<simView*>::iterator it=theViewList.begin();
    for(;it!=theViewList.end();it++)
    {
        ((*it)->GetTree())->DeleteAllItems();
        printf("delete all items in the tree.\n");
        std::string text="Model";
        wxTreeItemId rootid=((*it)->GetTree())->AddRoot(_swxT(text));
        std::vector<simMachine*>::iterator itm=theList->MachineList.begin();
        for(;itm!=theList->MachineList.end();itm++)
        {
            text=(*itm)->GetName();
            ((*it)->GetTree())->AppendItem(rootid,_swxT(text));
            printf("An items is added into the tree.\n");
        }
        std::vector<simQueue*>::iterator itq=theList->QueueList.begin();
        for(;itq!=theList->QueueList.end();itq++)
        {
            text=(*itq)->GetName();
            ((*it)->GetTree())->AppendItem(rootid,_swxT(text));
            printf("An items is added into the tree.\n");
        }
        ((*it)->GetTree())->ExpandAll();
    }
    return true;
}
