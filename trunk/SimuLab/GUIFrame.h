///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 17 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/treectrl.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/html/htmlwin.h>
#include <wx/bmpbuttn.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define wxID_SHOW_WELCOME 1001
#define wxID_M_SHOW_MODEL 1002
#define wxID_M_START 1003
#define wxID_M_PAUSE 1004
#define wxID_M_STOP 1005
#define wxID_HELP_CONTENT 1006
#define idMenuAbout 1007
#define wxID_TB_WELCOME 1008
#define wxID_TB__SHOW_MODEL 1009
#define wxID_TOOLBAR_HELP 1010
#define wxID_TB_START 1011
#define wxID_TB_PAUSE 1012
#define wxID_TB_STOP 1013
#define wxID_TB_RESET 1014
#define wxID_BT_NEW 1015
#define wxID_BT_OPEN 1016

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* viewmenu;
		wxMenu* m_menu_simulation;
		wxMenu* helpMenu;
		wxToolBar* m_toolBar1;
		wxStatusBar* statusBar;
		wxScrolledWindow* m_scrolledWindow1;
		wxTreeCtrl* m_treeCtrl_model;
		wxScrolledWindow* m_scrolledWindow2;
		wxAuiNotebook* m_auinotebook1;
		wxPanel* m_panel_welcome;
		
		wxStaticText* m_staticText1;
		wxStaticBitmap* m_bitmap2;
		
		wxButton* m_button_new_project;
		wxButton* m_button_open;
		wxButton* m_button4;
		wxButton* m_button5;
		
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxPanel* m_panel_help;
		wxHtmlWindow* m_htmlWin3;
		wxPanel* m_panel_model;
		wxBitmapButton* m_bt_part;
		wxBitmapButton* m_bt_machine;
		wxBitmapButton* m_bt_queue;
		wxScrolledWindow* m_model_window;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnIdle( wxIdleEvent& event ){ event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnShowWelcome( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnShowModelPage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSimulationStart( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSimulationPause( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSimulationStop( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnShowHelp( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSimulationReset( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPageClose( wxAuiNotebookEvent& event ){ event.Skip(); }
		virtual void OnAddPart( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddMachine( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddQueue( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SimuLab"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 827,554 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~GUIFrame();
	
};

#endif //__GUIFrame__
