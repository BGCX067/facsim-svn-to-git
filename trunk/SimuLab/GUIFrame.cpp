///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 17 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );
	
	mbar->Append( fileMenu, wxT("&File") );
	
	viewmenu = new wxMenu();
	wxMenuItem* m_show_welcome;
	m_show_welcome = new wxMenuItem( viewmenu, wxID_SHOW_WELCOME, wxString( wxT("Show Welcome Page") ) + wxT('\t') + wxT("CTRL+W"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_show_welcome->SetBitmaps( wxBitmap( wxT("icons/16x16/apps/internet-web-browser.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_show_welcome->SetBitmap( wxBitmap( wxT("icons/16x16/apps/internet-web-browser.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	viewmenu->Append( m_show_welcome );
	
	wxMenuItem* m_menu_model_page;
	m_menu_model_page = new wxMenuItem( viewmenu, wxID_M_SHOW_MODEL, wxString( wxT("Show Model Page") ) + wxT('\t') + wxT("CTRL+M"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menu_model_page->SetBitmaps( wxBitmap( wxT("icons/actions/view-fullscreen.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_menu_model_page->SetBitmap( wxBitmap( wxT("icons/actions/view-fullscreen.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	viewmenu->Append( m_menu_model_page );
	
	mbar->Append( viewmenu, wxT("&View") );
	
	m_menu_simulation = new wxMenu();
	wxMenuItem* m_menuItem_start;
	m_menuItem_start = new wxMenuItem( m_menu_simulation, wxID_M_START, wxString( wxT("Start") ) + wxT('\t') + wxT("ALT+S"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem_start->SetBitmaps( wxBitmap( wxT("icons/16x16/actions/media-playback-start.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_menuItem_start->SetBitmap( wxBitmap( wxT("icons/16x16/actions/media-playback-start.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_menu_simulation->Append( m_menuItem_start );
	
	wxMenuItem* m_menuItem_pause;
	m_menuItem_pause = new wxMenuItem( m_menu_simulation, wxID_M_PAUSE, wxString( wxT("Pause") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem_pause->SetBitmaps( wxBitmap( wxT("icons/16x16/actions/media-playback-pause.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_menuItem_pause->SetBitmap( wxBitmap( wxT("icons/16x16/actions/media-playback-pause.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_menu_simulation->Append( m_menuItem_pause );
	
	wxMenuItem* m_menuItem_stop;
	m_menuItem_stop = new wxMenuItem( m_menu_simulation, wxID_M_STOP, wxString( wxT("Stop") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem_stop->SetBitmaps( wxBitmap( wxT("icons/16x16/actions/media-playback-stop.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_menuItem_stop->SetBitmap( wxBitmap( wxT("icons/16x16/actions/media-playback-stop.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_menu_simulation->Append( m_menuItem_stop );
	
	mbar->Append( m_menu_simulation, wxT("&Simulation") );
	
	helpMenu = new wxMenu();
	wxMenuItem* m_menu_content;
	m_menu_content = new wxMenuItem( helpMenu, wxID_HELP_CONTENT, wxString( wxT("contents") ) + wxT('\t') + wxT("CTRL+H"), wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menu_content->SetBitmaps( wxBitmap( wxT("icons/16x16/actions/system-search.png"), wxBITMAP_TYPE_ANY ) );
	#elif defined( __WXGTK__ )
	m_menu_content->SetBitmap( wxBitmap( wxT("icons/16x16/actions/system-search.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	helpMenu->Append( m_menu_content );
	
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );
	
	mbar->Append( helpMenu, wxT("&Help") );
	
	this->SetMenuBar( mbar );
	
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_toolBar1->SetToolBitmapSize( wxSize( 24,24 ) );
	m_toolBar1->AddTool( wxID_ANY, wxT("New"), wxBitmap( wxT("icons/actions/document-new.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("New..."), wxT("Create a new file") );
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/actions/document-open.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/actions/document-save.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/actions/document-save-as.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddSeparator();
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/actions/edit-cut.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/actions/edit-copy.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddTool( wxID_ANY, wxT("tool"), wxBitmap( wxT("icons/actions/edit-paste.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddSeparator();
	m_toolBar1->AddTool( wxID_TB_WELCOME, wxT("tool"), wxBitmap( wxT("icons/actions/go-home.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddTool( wxID_TB__SHOW_MODEL, wxT("tool"), wxBitmap( wxT("icons/actions/view-fullscreen.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar1->AddTool( wxID_TOOLBAR_HELP, wxT("tool"), wxBitmap( wxT("icons/actions/system-search.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Show Help"), wxT("Show Help") );
	m_toolBar1->AddSeparator();
	m_toolBar1->AddTool( wxID_TB_START, wxT("Start"), wxBitmap( wxT("icons/actions/media-playback-start.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Start the Simulation"), wxT("Simulate!") );
	m_toolBar1->AddTool( wxID_TB_PAUSE, wxT("Pause"), wxBitmap( wxT("icons/actions/media-playback-pause.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("PAUSE"), wxT("Pause") );
	m_toolBar1->AddTool( wxID_TB_STOP, wxT("Stop"), wxBitmap( wxT("icons/actions/media-playback-stop.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Stop"), wxT("Stop") );
	m_toolBar1->AddTool( wxID_TB_RESET, wxT("Reset"), wxBitmap( wxT("icons/actions/media-skip-backward.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Reset"), wxT("Reset") );
	m_toolBar1->AddSeparator();
	m_toolBar1->Realize();
	
	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	m_scrolledWindow1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_treeCtrl_model = new wxTreeCtrl( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxHSCROLL|wxSIMPLE_BORDER|wxVSCROLL );
	m_treeCtrl_model->SetMinSize( wxSize( 200,-1 ) );
	m_treeCtrl_model->SetMaxSize( wxSize( 200,-1 ) );
	
	bSizer2->Add( m_treeCtrl_model, 0, wxALL|wxEXPAND, 1 );
	
	m_scrolledWindow2 = new wxScrolledWindow( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxSIMPLE_BORDER|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	m_scrolledWindow2->SetBackgroundColour( wxColour( 92, 143, 155 ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebook1 = new wxAuiNotebook( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_CLOSE_ON_ALL_TABS|wxAUI_NB_DEFAULT_STYLE );
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
	m_panel_help = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_htmlWin3 = new wxHtmlWindow( m_panel_help, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer8->Add( m_htmlWin3, 1, wxEXPAND, 5 );
	
	m_panel_help->SetSizer( bSizer8 );
	m_panel_help->Layout();
	bSizer8->Fit( m_panel_help );
	m_auinotebook1->AddPage( m_panel_help, wxT("SimuLab Help"), false, wxBitmap( wxT("icons/16x16/actions/system-search.png"), wxBITMAP_TYPE_ANY ) );
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
	
	bSizer4->Add( m_auinotebook1, 1, wxEXPAND, 5 );
	
	m_scrolledWindow2->SetSizer( bSizer4 );
	m_scrolledWindow2->Layout();
	bSizer4->Fit( m_scrolledWindow2 );
	bSizer2->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 1 );
	
	m_scrolledWindow1->SetSizer( bSizer2 );
	m_scrolledWindow1->Layout();
	bSizer2->Fit( m_scrolledWindow1 );
	bSizer1->Add( m_scrolledWindow1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( GUIFrame::OnIdle ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( m_show_welcome->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnShowWelcome ) );
	this->Connect( m_menu_model_page->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnShowModelPage ) );
	this->Connect( m_menuItem_start->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSimulationStart ) );
	this->Connect( m_menuItem_pause->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSimulationPause ) );
	this->Connect( m_menuItem_stop->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSimulationStop ) );
	this->Connect( m_menu_content->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnShowHelp ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Connect( wxID_TB_WELCOME, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnShowWelcome ) );
	this->Connect( wxID_TB__SHOW_MODEL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnShowModelPage ) );
	this->Connect( wxID_TOOLBAR_HELP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnShowHelp ) );
	this->Connect( wxID_TB_START, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationStart ) );
	this->Connect( wxID_TB_PAUSE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationPause ) );
	this->Connect( wxID_TB_STOP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationStop ) );
	this->Connect( wxID_TB_RESET, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationReset ) );
	m_auinotebook1->Connect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, wxAuiNotebookEventHandler( GUIFrame::OnPageClose ), NULL, this );
	m_bt_part->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnAddPart ), NULL, this );
	m_bt_machine->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnAddMachine ), NULL, this );
	m_bt_queue->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnAddQueue ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUIFrame::OnIdle ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnShowWelcome ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnShowModelPage ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSimulationStart ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSimulationPause ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnSimulationStop ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnShowHelp ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Disconnect( wxID_TB_WELCOME, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnShowWelcome ) );
	this->Disconnect( wxID_TB__SHOW_MODEL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnShowModelPage ) );
	this->Disconnect( wxID_TOOLBAR_HELP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnShowHelp ) );
	this->Disconnect( wxID_TB_START, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationStart ) );
	this->Disconnect( wxID_TB_PAUSE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationPause ) );
	this->Disconnect( wxID_TB_STOP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationStop ) );
	this->Disconnect( wxID_TB_RESET, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::OnSimulationReset ) );
	m_auinotebook1->Disconnect( wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE, wxAuiNotebookEventHandler( GUIFrame::OnPageClose ), NULL, this );
	m_bt_part->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnAddPart ), NULL, this );
	m_bt_machine->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnAddMachine ), NULL, this );
	m_bt_queue->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::OnAddQueue ), NULL, this );
}
