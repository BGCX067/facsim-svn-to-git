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

#include "SimuLabDlg.h"

///////////////////////////////////////////////////////////////////////////

MachineSetting::MachineSetting( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_main_panel = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( m_main_panel, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer8->Add( m_staticText3, 0, wxALL, 5 );
	
	m_staticText4 = new wxStaticText( m_main_panel, wxID_ANY, wxT("Capacity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer8->Add( m_staticText4, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( m_main_panel, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer8->Add( m_staticText5, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_name = new wxTextCtrl( m_main_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_name, 0, wxALL, 5 );
	
	m_textCtrl2 = new wxTextCtrl( m_main_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_textCtrl2, 0, wxALL, 5 );
	
	m_textCtrl3 = new wxTextCtrl( m_main_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_textCtrl3, 0, wxALL, 5 );
	
	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	bSizer5->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button7 = new wxButton( m_main_panel, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button7, 0, wxALL, 5 );
	
	m_button8 = new wxButton( m_main_panel, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button8, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );
	
	m_main_panel->SetSizer( bSizer5 );
	m_main_panel->Layout();
	bSizer5->Fit( m_main_panel );
	m_notebook1->AddPage( m_main_panel, wxT("Main"), true );
	m_pull_panel = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_listBox1 = new wxListBox( m_pull_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer13->Add( m_listBox1, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_comboBox1 = new wxComboBox( m_pull_panel, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer14->Add( m_comboBox1, 0, wxALL, 5 );
	
	m_button5 = new wxButton( m_pull_panel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button5, 0, wxALL, 5 );
	
	m_button6 = new wxButton( m_pull_panel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button6, 0, wxALL, 5 );
	
	
	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button10 = new wxButton( m_pull_panel, wxID_ANY, wxT("Script on PULL..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button10, 0, wxALL, 5 );
	
	bSizer13->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_button_OK = new wxButton( m_pull_panel, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button_OK, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button_cancel = new wxButton( m_pull_panel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button_cancel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_button_apply = new wxButton( m_pull_panel, wxID_ANY, wxT("Apply"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button_apply, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer13->Add( bSizer15, 1, wxEXPAND, 5 );
	
	m_pull_panel->SetSizer( bSizer13 );
	m_pull_panel->Layout();
	bSizer13->Fit( m_pull_panel );
	m_notebook1->AddPage( m_pull_panel, wxT("Pull"), false );
	m_setup_panel = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_setup_panel, wxT("Set-Up"), false );
	m_push_panel = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook1->AddPage( m_push_panel, wxT("Push"), false );
	
	bSizer12->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer12 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MachineSetting::OnOK ), NULL, this );
	m_button_OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MachineSetting::OnOK ), NULL, this );
}

MachineSetting::~MachineSetting()
{
	// Disconnect Events
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MachineSetting::OnOK ), NULL, this );
	m_button_OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MachineSetting::OnOK ), NULL, this );
}
