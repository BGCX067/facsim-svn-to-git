/***************************************************************
 * Name:      SimuLabMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    WANG Mengchang (wangmengchang@gmail.com)
 * Created:   2009-07-10
 * Copyright: WANG Mengchang (http://hi.baidu.com/thym)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include <wx/msgdlg.h>
#include "SimuLabMain.h"

#include <wx/artprov.h>

#include "simlab.h"

#include "machinedlg.h"

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


SimuLabFrame::SimuLabFrame(wxFrame *frame)
        : GUIFrame(frame)
{


    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_HOME")),wxART_BUTTON));
    SetIcon(FrameIcon);

#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Simu Lab"), 0);
    statusBar->SetStatusText(_("Ready"), 1);
#endif
    //wxSize cs=    GetClientSize();

    //m_htmlWin2->SetMinSize( wxSize(-1,cs.GetHeight()) );
    //m_htmlWin2->SetPage(_("<html><body><h3>Simu Lab</h3><p>Simulation Lab.</p><input type=submit value=百度一下 id=sb><p>OK.</p></body></html>"));


    wxTreeItemId theRoot=    m_treeCtrl_model->AddRoot(_("empty"));
    //m_treeCtrl_model->SetItemImage();
    if (wxNOT_FOUND!=m_auinotebook1->GetPageIndex(m_panel_help))
    {
        m_auinotebook1->DeletePage(m_auinotebook1->GetPageIndex(m_panel_help));
    }
    m_panel_help=(wxPanel*)NULL;
    if (wxNOT_FOUND!=m_auinotebook1->GetPageIndex(m_panel_model))
    {
        m_auinotebook1->DeletePage(m_auinotebook1->GetPageIndex(m_panel_model));
    }
    m_panel_model=(wxPanel*)NULL;

    ////
    theProject=(simProject*)NULL;
    theView=(simView*)NULL;
}

SimuLabFrame::~SimuLabFrame()
{
    if (theProject!=(simProject*)NULL)
    {
        delete theProject;
    }
}

void SimuLabFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void SimuLabFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void SimuLabFrame::OnAbout(wxCommandEvent &event)
{
    //wxString msg = wxbuildinfo(long_f);
    wxMessageBox(_("SimuLab\nby WANG MengChang\n2009"), _("About SimuLab"));
}

void SimuLabFrame::OnIdle( wxIdleEvent& event )
{
    //
    //   wxSize cs=    GetClientSize();

    //m_htmlWin2->SetMinSize( wxSize(-1,cs.GetHeight()) );
}

void SimuLabFrame::OnPageClose( wxAuiNotebookEvent& event )
{
    //
    //wxMessageBox(_("A page closed"));
    //
    //m_auinotebook1->DeletePage(m_auinotebook1->GetSelection());
    if (wxNOT_FOUND==m_auinotebook1->GetPageIndex(m_panel_help))
    {
        m_panel_help=(wxPanel*)NULL;
    }
    if (wxNOT_FOUND==m_auinotebook1->GetPageIndex(m_panel_model))
    {
        m_panel_model=(wxPanel*)NULL;
    }
    if (wxNOT_FOUND==m_auinotebook1->GetPageIndex(m_panel_welcome))
    {
        m_panel_welcome=(wxPanel*)NULL;
    }

}

void SimuLabFrame::OnShowHelp( wxCommandEvent& event )
{
    //
    ShowHelpPage();
}

void SimuLabFrame::OnShowWelcome(wxCommandEvent& event)
{
    ShowWelcomePage();
}

void SimuLabFrame::ShowWelcomePage()
{
    if (wxNOT_FOUND==m_auinotebook1->GetPageIndex(m_panel_welcome))
    {
        m_panel_welcome = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        m_panel_welcome->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );

        wxBoxSizer* bSizer5;
        bSizer5 = new wxBoxSizer( wxVERTICAL );


        bSizer5->Add( 0, 30, 0, 0, 5 );

        m_staticText1 = new wxStaticText( m_panel_welcome, wxID_ANY, wxT("Welcome to"), wxDefaultPosition, wxDefaultSize, 0 );
        m_staticText1->Wrap( -1 );
        m_staticText1->SetFont( wxFont( 13, 74, 93, 90, false, wxT("Sans") ) );

        bSizer5->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

        m_bitmap2 = new wxStaticBitmap( m_panel_welcome, wxID_ANY, wxBitmap( wxT("icons/Logo.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
        bSizer5->Add( m_bitmap2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

        wxStaticBoxSizer* sbSizer1;
        sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel_welcome, wxID_ANY, wxT("SimuLab") ), wxVERTICAL );

        wxBoxSizer* bSizer81;
        bSizer81 = new wxBoxSizer( wxHORIZONTAL );


        bSizer81->Add( 30, 0, 0, 0, 5 );

        wxBoxSizer* bSizer9;
        bSizer9 = new wxBoxSizer( wxVERTICAL );

        m_button_new_project = new wxButton( m_panel_welcome, wxID_BT_NEW, wxT("New Project..."), wxDefaultPosition, wxDefaultSize, wxBU_LEFT|wxNO_BORDER );
        m_button_new_project->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

        bSizer9->Add( m_button_new_project, 0, wxALL, 5 );

        m_button_open = new wxButton( m_panel_welcome, wxID_BT_OPEN, wxT("Open a project..."), wxDefaultPosition, wxDefaultSize, wxBU_LEFT|wxNO_BORDER );
        m_button_open->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

        bSizer9->Add( m_button_open, 0, wxALL, 5 );

        bSizer81->Add( bSizer9, 1, wxEXPAND, 5 );

        wxBoxSizer* bSizer10;
        bSizer10 = new wxBoxSizer( wxVERTICAL );

        m_button4 = new wxButton( m_panel_welcome, wxID_ANY, wxT("File_1"), wxDefaultPosition, wxDefaultSize, wxBU_LEFT|wxNO_BORDER );
        m_button4->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

        bSizer10->Add( m_button4, 0, wxALL, 5 );

        m_button5 = new wxButton( m_panel_welcome, wxID_ANY, wxT("File_2"), wxDefaultPosition, wxDefaultSize, wxBU_LEFT|wxNO_BORDER );
        m_button5->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

        bSizer10->Add( m_button5, 0, wxALL, 5 );

        bSizer81->Add( bSizer10, 1, wxEXPAND, 5 );

        sbSizer1->Add( bSizer81, 1, wxEXPAND, 5 );

        bSizer5->Add( sbSizer1, 1, wxEXPAND, 5 );

        wxBoxSizer* bSizer6;
        bSizer6 = new wxBoxSizer( wxHORIZONTAL );


        bSizer6->Add( 20, 0, 0, wxALIGN_CENTER_VERTICAL, 5 );

        wxBoxSizer* bSizer7;
        bSizer7 = new wxBoxSizer( wxVERTICAL );

        m_staticText2 = new wxStaticText( m_panel_welcome, wxID_ANY, wxT("Simulation Lab"), wxDefaultPosition, wxDefaultSize, 0 );
        m_staticText2->Wrap( -1 );
        bSizer7->Add( m_staticText2, 0, wxALL, 5 );

        m_staticText3 = new wxStaticText( m_panel_welcome, wxID_ANY, wxT("http://facsim.googlecode.com"), wxDefaultPosition, wxDefaultSize, 0 );
        m_staticText3->Wrap( -1 );
        bSizer7->Add( m_staticText3, 0, wxALL, 5 );


        bSizer7->Add( 0, 20, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

        m_staticText4 = new wxStaticText( m_panel_welcome, wxID_ANY, wxT("WANG MengChang"), wxDefaultPosition, wxDefaultSize, 0 );
        m_staticText4->Wrap( -1 );
        bSizer7->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

        m_staticText5 = new wxStaticText( m_panel_welcome, wxID_ANY, wxT("2009"), wxDefaultPosition, wxDefaultSize, 0 );
        m_staticText5->Wrap( -1 );
        bSizer7->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

        bSizer6->Add( bSizer7, 1, wxEXPAND, 5 );

        bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );

        m_panel_welcome->SetSizer( bSizer5 );
        m_panel_welcome->Layout();
        bSizer5->Fit( m_panel_welcome );
        m_auinotebook1->AddPage( m_panel_welcome, wxT("Welcome to SimuLab"), true, wxBitmap( wxT("icons/16x16/apps/internet-web-browser.png"), wxBITMAP_TYPE_ANY ) );


    }
    else
    {
        m_auinotebook1->SetSelection(m_auinotebook1->GetPageIndex(m_panel_welcome));
    }

}



void SimuLabFrame::ShowHelpPage()
{
    wxString cnt=_("<html><body><p><img src=\"Logo.png\" width=50 height=14></p><hr><h3>SimuLab Help</h3><p>1<hr><p>1<hr><p>1<hr><p>1<hr><p>1<hr><p>1<hr><p>2<hr><p>1<hr><p>1<hr><p>3<hr><p>1<hr><p>1<hr><p>6<hr><p>1<hr><p>1<hr></body></html>");
    if (wxNOT_FOUND==m_auinotebook1->GetPageIndex(m_panel_help))
    {
        m_panel_help = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        wxBoxSizer* bSizer8;
        bSizer8 = new wxBoxSizer( wxVERTICAL );

        m_htmlWin3 = new wxHtmlWindow( m_panel_help, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
        bSizer8->Add( m_htmlWin3, 1, wxALL|wxEXPAND, 5 );

        m_panel_help->SetSizer( bSizer8 );
        m_panel_help->Layout();
        bSizer8->Fit( m_panel_help );
        //
        m_htmlWin3->SetPage(cnt);
        //
        m_auinotebook1->AddPage( m_panel_help, wxT("SimuLab Help"), true, wxBitmap( wxT("icons/16x16/actions/system-search.png"), wxBITMAP_TYPE_ANY ) );
    }
    else
    {
        m_htmlWin3->SetPage(cnt);
        m_auinotebook1->SetSelection(m_auinotebook1->GetPageIndex(m_panel_help));
    }
}

void SimuLabFrame::ShowModelView()
{
    if (wxNOT_FOUND==m_auinotebook1->GetPageIndex(m_panel_model))
    {
        m_panel_model = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
        wxBoxSizer* bSizer14;
        bSizer14 = new wxBoxSizer( wxVERTICAL );

        wxStaticBoxSizer* Elements;
        Elements = new wxStaticBoxSizer( new wxStaticBox( m_panel_model, wxID_ANY, wxT("Elements") ), wxHORIZONTAL );

        Elements->SetMinSize( wxSize( -1,30 ) );
        m_bt_part = new wxBitmapButton( m_panel_model, wxID_ANY, wxBitmap( wxT("icons/Elements/Part-32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        Elements->Add( m_bt_part, 0, wxALL, 5 );

        m_bt_machine = new wxBitmapButton( m_panel_model, wxID_ANY, wxBitmap( wxT("icons/Elements/Machine-32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        Elements->Add( m_bt_machine, 0, wxALL, 5 );

        m_bt_queue = new wxBitmapButton( m_panel_model, wxID_ANY, wxBitmap( wxT("icons/Elements/Queue-32.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
        Elements->Add( m_bt_queue, 0, wxALL, 5 );

        bSizer14->Add( Elements, 0, 0, 5 );

        m_model_window = new wxScrolledWindow( m_panel_model, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxSIMPLE_BORDER|wxVSCROLL );
        m_model_window->SetScrollRate( 5, 5 );
        m_model_window->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

        bSizer14->Add( m_model_window, 1, wxEXPAND, 5 );

        m_panel_model->SetSizer( bSizer14 );
        m_panel_model->Layout();
        bSizer14->Fit( m_panel_model );
        m_auinotebook1->AddPage( m_panel_model, wxT("Model"), false, wxBitmap( wxT("icons/16x16/actions/view-fullscreen.png"), wxBITMAP_TYPE_ANY ) );

        m_auinotebook1->SetSelection(m_auinotebook1->GetPageIndex(m_panel_model));

        m_bt_part->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimuLabFrame::OnAddPart ), NULL, this );
        m_bt_machine->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimuLabFrame::OnAddMachine ), NULL, this );
        m_bt_queue->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SimuLabFrame::OnAddQueue ), NULL, this );

    }
    else
    {
        m_auinotebook1->SetSelection(m_auinotebook1->GetPageIndex(m_panel_model));
    }
}


extern void TestScript();
void SimuLabFrame::OnShowModelPage(wxCommandEvent& event )
{
    printf("OnShowModelPage.\n");
    ShowModelView();
    simScript ascript(STRING_R_TYPE);
    ascript="Hello,还有中文!";

    std::string tmps=ascript.GetScript();
    //wxMessageBox(stdString2wxString(tmps));
    //wxMessageBox(_swxT(tmps));
    TestScript();
    if (theProject==(simProject*)NULL)
    {
        theProject=new simProject();
    }
    if (theView==(simView*)NULL)
    {
        theView=new simView();
        theView->bind(theProject);
        theView->SetTree(m_treeCtrl_model);
    }
}

void SimuLabFrame::OnAddPart( wxCommandEvent& event )
{
    printf("On Add Part.\n");
    //simPart* tmp=new simPart();

}
void SimuLabFrame::OnAddMachine( wxCommandEvent& event )
{
    simMachine* tmp=new simMachine();
    printf("A machine OK.\n");
    //MachineSetting dlg(this);
    //dlg.ShowModal();
    MachineDlg dlg2(this);
    dlg2.ShowModal();
    char tmpc[512];
    strcpy(tmpc,wxString2stdString(dlg2.the_name).c_str());
    tmp->SetName(tmpc);

    theProject->AddMachine(tmp);
    printf("Add OK.\n");
    theProject->UpdateViews();
}
void SimuLabFrame::OnAddQueue( wxCommandEvent& event )
{
    printf("On Add Queue.\n");
    simQueue* tmp=new simQueue();
    theProject->AddQueue(tmp);
    printf("A Queue OK.\n");
    theProject->UpdateViews();
}


void SimuLabFrame::OnSimulationStart( wxCommandEvent& event )
{
    //Reset the engine
    //register all functions
    //register all properties
    //reset all scripts' hasCompiled flag
    //then RUN in a new Thread
}
void SimuLabFrame::OnSimulationPause( wxCommandEvent& event )
{
}
void SimuLabFrame::OnSimulationStop( wxCommandEvent& event )
{
}
void SimuLabFrame::OnSimulationReset( wxCommandEvent& event )
{
}



