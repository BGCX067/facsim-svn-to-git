///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 17 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SimuLabDlg__
#define __SimuLabDlg__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MachineSetting
///////////////////////////////////////////////////////////////////////////////
class MachineSetting : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_main_panel;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_name;
		wxTextCtrl* m_textCtrl2;
		wxTextCtrl* m_textCtrl3;
		
		
		wxButton* m_button7;
		wxButton* m_button8;
		wxPanel* m_pull_panel;
		wxListBox* m_listBox1;
		wxComboBox* m_comboBox1;
		wxButton* m_button5;
		wxButton* m_button6;
		
		wxButton* m_button10;
		wxButton* m_button_OK;
		wxButton* m_button_cancel;
		wxButton* m_button_apply;
		wxPanel* m_setup_panel;
		wxPanel* m_push_panel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		MachineSetting( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Machine"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 561,381 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MachineSetting();
	
};

#endif //__SimuLabDlg__
