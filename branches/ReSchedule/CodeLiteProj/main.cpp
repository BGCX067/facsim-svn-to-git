#include "main.h"

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation 
////////////////////////////////////////////////////////////////////////////////

bool MainApp::OnInit()
{
	SetTopWindow( new MainFrame( NULL ) );
	GetTopWindow()->Show();
	
	// true = enter the main loop
	return true;
}

////////////////////////////////////////////////////////////////////////////////
// main application frame implementation 
////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow *parent) : MainFrameBase( parent )
{
	m_treeCtrl_model->AddRoot(wxT("Empty Model"));
	int w,h;
	m_treeCtrl_model->GetSize(&w,&h);
	if(w<350){w=350;}

	m_treeCtrl_model->SetSize(w,h);
	//(wxTreeCtrl*)m_treeCtrl3->AddChild(wxT("def"));
	//
	//wxTreeCtrl* abc;
	//abc->DrawLine()
	//m_treeCtrl3->
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnCloseFrame(wxCloseEvent& event)
{
	Destroy();
}

void MainFrame::OnExitClick(wxCommandEvent& event)
{
	Destroy();
}
