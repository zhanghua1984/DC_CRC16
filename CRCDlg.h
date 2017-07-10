// CRCDlg.h : header file
//

#if !defined(AFX_CRCDLG_H__B958BF87_5926_44EF_B2E5_D0097DCDA414__INCLUDED_)
#define AFX_CRCDLG_H__B958BF87_5926_44EF_B2E5_D0097DCDA414__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCRCDlg dialog

class CCRCDlg : public CDialog
{
// Construction
public:
	CCRCDlg(CWnd* pParent = NULL);	// standard constructor
	int crc16(unsigned char *pchMsg,unsigned int wDataLen);
	unsigned char m_crcinput[200];

// Dialog Data
	//{{AFX_DATA(CCRCDlg)
	enum { IDD = IDD_CRC_DIALOG };
	CString	m_csinput;
	CString	m_csoutput;
	CString	m_cscal;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCRCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCRCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCalculate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRCDLG_H__B958BF87_5926_44EF_B2E5_D0097DCDA414__INCLUDED_)
