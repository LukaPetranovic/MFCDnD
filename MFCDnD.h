#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCDnDApp:
// See MFCDnD.cpp for the implementation of this class
//

class CMFCDnDApp : public CWinApp
{
public:
	CMFCDnDApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCDnDApp theApp;
