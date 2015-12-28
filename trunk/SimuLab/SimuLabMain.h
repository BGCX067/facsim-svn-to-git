/***************************************************************
 * Name:      SimuLabMain.h
 * Purpose:   Defines Application Frame
 * Author:    WANG Mengchang (wangmengchang@gmail.com)
 * Created:   2009-07-10
 * Copyright: WANG Mengchang (http://hi.baidu.com/thym)
 * License:
 **************************************************************/

#ifndef SIMULABMAIN_H
#define SIMULABMAIN_H



#include "SimuLabApp.h"


#include "GUIFrame.h"

class simProject;
class simView;


class SimuLabFrame: public GUIFrame
{
    public:
        SimuLabFrame(wxFrame *frame);
        ~SimuLabFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnShowWelcome(wxCommandEvent& event);

        virtual void OnIdle( wxIdleEvent& event );
        virtual void OnPageClose( wxAuiNotebookEvent& event );
        virtual void OnShowHelp( wxCommandEvent& event );
        virtual void OnShowModelPage(wxCommandEvent& event );

        virtual void OnAddPart( wxCommandEvent& event );
		virtual void OnAddMachine( wxCommandEvent& event );
		virtual void OnAddQueue( wxCommandEvent& event );

		virtual void OnSimulationStart( wxCommandEvent& event );
		virtual void OnSimulationPause( wxCommandEvent& event );
		virtual void OnSimulationStop( wxCommandEvent& event );
		virtual void OnSimulationReset( wxCommandEvent& event );

        void ShowWelcomePage();
        void ShowHelpPage();

        //ModelViewPage* mvPage;
        void ShowModelView();

        simProject* theProject;
        simView* theView;
};

#endif // SIMULABMAIN_H
