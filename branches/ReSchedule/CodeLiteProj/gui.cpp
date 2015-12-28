///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 17 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menuBar = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* menuFileExit;
	menuFileExit = new wxMenuItem( m_menuFile, wxID_EXIT, wxString( _("E&xit") ) + wxT('\t') + wxT("Alt+X"), wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( menuFileExit );
	
	m_menuBar->Append( m_menuFile, _("&File") );
	
	m_menuView = new wxMenu();
	m_menuBar->Append( m_menuView, _("&View") );
	
	m_menuModel = new wxMenu();
	m_menuBar->Append( m_menuModel, _("&Model") );
	
	m_menuSimulation = new wxMenu();
	m_menuBar->Append( m_menuSimulation, _("&Simulation") );
	
	m_menuReport = new wxMenu();
	m_menuBar->Append( m_menuReport, _("&Report") );
	
	m_menuHelp = new wxMenu();
	wxMenuItem* m_menuAbout;
	m_menuAbout = new wxMenuItem( m_menuHelp, wxID_HELP, wxString( _("About") ) + wxT('\t') + wxT("Ctrl+H"), wxEmptyString, wxITEM_NORMAL );
	m_menuHelp->Append( m_menuAbout );
	
	m_menuBar->Append( m_menuHelp, _("&Help") );
	
	this->SetMenuBar( m_menuBar );
	
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_auinotebook1 = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_EXTERNAL_MOVE|wxAUI_NB_WINDOWLIST_BUTTON );
	m_panel_model = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel_model, wxID_ANY, _("label") ), wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_treeCtrl_model = new wxTreeCtrl( m_panel_model, wxID_ANY, wxDefaultPosition, wxSize( 120,-1 ), wxTR_DEFAULT_STYLE );
	m_treeCtrl_model->SetMinSize( wxSize( 120,-1 ) );
	
	bSizer2->Add( m_treeCtrl_model, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_panel_elements = new wxPanel( m_panel_model, wxID_ANY, wxDefaultPosition, wxSize( -1,60 ), wxTAB_TRAVERSAL );
	m_panel_elements->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );
	m_panel_elements->SetMinSize( wxSize( -1,60 ) );
	m_panel_elements->SetMaxSize( wxSize( -1,60 ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel_elements, wxID_ANY, _("Elements") ), wxVERTICAL );
	
	sbSizer2->SetMinSize( wxSize( -1,60 ) ); 
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton_machine = new wxBitmapButton( m_panel_elements, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( 32,32 ), wxBU_AUTODRAW );
	m_bpButton_machine->SetToolTip( _("Create a machine") );
	m_bpButton_machine->SetMinSize( wxSize( 32,32 ) );
	m_bpButton_machine->SetMaxSize( wxSize( 32,32 ) );
	
	m_bpButton_machine->SetToolTip( _("Create a machine") );
	m_bpButton_machine->SetMinSize( wxSize( 32,32 ) );
	m_bpButton_machine->SetMaxSize( wxSize( 32,32 ) );
	
	bSizer4->Add( m_bpButton_machine, 0, wxALL, 5 );
	
	sbSizer2->Add( bSizer4, 1, wxEXPAND, 5 );
	
	m_panel_elements->SetSizer( sbSizer2 );
	m_panel_elements->Layout();
	bSizer5->Add( m_panel_elements, 0, wxALL|wxEXPAND, 5 );
	
	m_Window_Model = new wxScrolledWindow( m_panel_model, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_Window_Model->SetScrollRate( 5, 5 );
	m_Window_Model->SetBackgroundColour( wxColour( 81, 144, 174 ) );
	
	bSizer5->Add( m_Window_Model, 1, wxEXPAND | wxALL, 5 );
	
	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );
	
	sbSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	m_panel_model->SetSizer( sbSizer1 );
	m_panel_model->Layout();
	sbSizer1->Fit( m_panel_model );
	m_auinotebook1->AddPage( m_panel_model, _("Model"), true, wxNullBitmap );
	m_panel_simulation = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook1->AddPage( m_panel_simulation, _("Simulation"), false, wxNullBitmap );
	m_panel_statictics = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook1->AddPage( m_panel_statictics, _("Statistics"), false, wxNullBitmap );
	m_panel_report = new wxPanel( m_auinotebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_auinotebook1->AddPage( m_panel_report, _("Report"), false, wxNullBitmap );
	
	mainSizer->Add( m_auinotebook1, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( mainSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	this->Connect( menuFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnExitClick ) );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrameBase::OnCloseFrame ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::OnExitClick ) );
}
