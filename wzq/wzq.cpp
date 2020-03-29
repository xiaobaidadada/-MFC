// wzq.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "wzq.h"
#include "wzqDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// App

BEGIN_MESSAGE_MAP(App, CWinApp)
	//{{AFX_MSG_MAP(App)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// App construction

App::App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only App object

App theApp;

/////////////////////////////////////////////////////////////////////////////
// App initialization

BOOL App::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)//创建成功
	{
		
	}
	else if (nResponse == IDCANCEL)
	{
	}


	return FALSE;
}
