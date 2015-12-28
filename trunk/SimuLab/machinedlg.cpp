/*
This is written by WANG MengChang
*/#include "machinedlg.h"
//#include

MachineDlg::MachineDlg(wxWindow *frame)
    :MachineSetting(frame)
{
    //ctor
    the_name=wxT("NoName(Machine)");
    m_name->SetValue(the_name);
}


void MachineDlg::OnOK( wxCommandEvent& event )
{
    the_name=m_name->GetValue();
    this->EndModal(0);
}


MachineDlg::~MachineDlg()
{
    //dtor
}
