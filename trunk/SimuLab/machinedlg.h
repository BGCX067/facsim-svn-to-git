#ifndef MACHINEDLG_H
#define MACHINEDLG_H

#include "SimuLabDlg.h"


class MachineDlg : public MachineSetting
{
    public:
        wxString the_name;
        MachineDlg(wxWindow *frame);
        virtual ~MachineDlg();
    protected:
        virtual void OnOK( wxCommandEvent& event );
    private:
};

#endif // MACHINEDLG_H
