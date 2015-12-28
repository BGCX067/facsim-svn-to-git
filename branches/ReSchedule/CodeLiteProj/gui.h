///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 17 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __gui__
#define __gui__

#include <wx/intl.h>

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/treectrl.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/aui/auibook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menuBar;
		wxMenu* m_menuFile;
		wxMenu* m_menuView;
		wxMenu* m_menuModel;
		wxMenu* m_menuSimulation;
		wxMenu* m_menuReport;
		wxMenu* m_menuHelp;
		wxAuiNotebook* m_auinotebook1;
		wxPanel* m_panel_model;
		wxTreeCtrl* m_treeCtrl_model;
		wxPanel* m_panel_elements;
		wxBitmapButton* m_bpButton_machine;
		wxScrolledWindow* m_Window_Model;
		wxPanel* m_panel_simulation;
		wxPanel* m_panel_statictics;
		wxPanel* m_panel_report;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnCloseFrame( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnExitClick( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Simulator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 642,457 ), long style = wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrameBase();
	
};

#endif //__gui__
