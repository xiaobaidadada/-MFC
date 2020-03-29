// wzq.h : main header file for the WZQ application
//

#if !defined(AFX_WZQ_H__3176076E_9CC3_4841_82D6_D78A797C6D78__INCLUDED_)
#define AFX_WZQ_H__3176076E_9CC3_4841_82D6_D78A797C6D78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// App:
// See wzq.cpp for the implementation of this class
//

class App : public CWinApp
{
public:
	App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZQ_H__3176076E_9CC3_4841_82D6_D78A797C6D78__INCLUDED_)
