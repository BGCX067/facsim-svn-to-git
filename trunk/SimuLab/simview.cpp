/*
This is written by WANG MengChang
*/#include "simview.h"

simView::simView()
{
    //ctor
    theProject=(simProject*)NULL;
    theTreeCtrl=(wxTreeCtrl*)NULL;
}

simView::~simView()
{
    //dtor
}

void simView::bind(simProject* ap)
{
    theProject=ap;
    ap->AddView(this);
}

void simView::refresh()
{
    if(theProject==(simProject*)NULL) return;
    if(theTreeCtrl==(wxTreeCtrl*)NULL) return;


}

void simView::SetTree(wxTreeCtrl* atree)
{
    theTreeCtrl=atree;
}
