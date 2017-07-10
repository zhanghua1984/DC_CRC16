// CRCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CRC.h"
#include "CRCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCRCDlg dialog

CCRCDlg::CCRCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCRCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCRCDlg)
	m_csinput = _T("");
	m_csoutput = _T("");
	m_cscal = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCRCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCRCDlg)
	DDX_Text(pDX, IDC_INPUT, m_csinput);
	DDX_Text(pDX, IDC_OUTPUT, m_csoutput);
	DDX_Text(pDX, IDC_CAL, m_cscal);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCRCDlg, CDialog)
	//{{AFX_MSG_MAP(CCRCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALCULATE, OnCalculate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCRCDlg message handlers

BOOL CCRCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCRCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCRCDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCRCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCRCDlg::OnCalculate() 
{
	// TODO: Add your control notification handler code here
	CString m_str;
	int m_return;
	UpdateData(TRUE);
	m_cscal=m_csinput;
	for (int i=0;i<m_cscal.GetLength();i++)
	{
		m_str=m_csinput.Left(2);
		m_crcinput[i]=strtoul(m_str,NULL,16);
		if (m_csinput.GetLength()>0)
		{
			m_csinput.Delete(0,3);
		}
	}

	m_csinput=m_cscal;
	
	m_return=crc16(m_crcinput,22);

	m_csoutput.Format("%04X",m_return);

	m_str=m_csoutput.Left(2);

	m_csoutput.Delete(0,2);

	m_csoutput+=m_str;

	m_str=" ";

	m_csoutput.Insert(2,m_str);
	m_cscal+=" ";
	m_cscal+=m_csoutput;

	UpdateData(FALSE);
}



int CCRCDlg::crc16(unsigned char *pchMsg,unsigned int wDataLen)
{
	unsigned  int wCRCTalbeAbs[] =
	{
		0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 
			0x3C00, 0x2800, 0xE401, 0xA001, 0x6C00, 
			0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 
			0x4400
	};
	unsigned  int wCRC = 0xFFFF;
	unsigned  int i = 0;
	unsigned char chChar = 0;
	
	for (i = 0; i < wDataLen; i++)
	{
		chChar = *pchMsg++;
		wCRC = wCRCTalbeAbs[(chChar ^ wCRC) & 15] ^ (wCRC >> 4);
		wCRC = wCRCTalbeAbs[((chChar >> 4) ^ wCRC) & 15] ^ (wCRC >> 4);
	}
	
	return wCRC;
}
