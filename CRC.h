// CRC.h : main header file for the CRC application
//

#if !defined(AFX_CRC_H__83E96ADC_4274_4099_A7E2_49DBE3B3539B__INCLUDED_)
#define AFX_CRC_H__83E96ADC_4274_4099_A7E2_49DBE3B3539B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCRCApp:
// See CRC.cpp for the implementation of this class
//

class CCRCApp : public CWinApp
{
public:
	CCRCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCRCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCRCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRC_H__83E96ADC_4274_4099_A7E2_49DBE3B3539B__INCLUDED_)
