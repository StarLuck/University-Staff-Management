#if !defined(AFX_ADDSYSINFODLG_H__7115B940_D3D8_4A55_97D0_B51683E88768__INCLUDED_)
#define AFX_ADDSYSINFODLG_H__7115B940_D3D8_4A55_97D0_B51683E88768__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSysInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSysInfoDlg dialog

class CAddSysInfoDlg : public CDialog
{
// Construction
public:
	CAddSysInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSysInfoDlg)
	enum { IDD = IDD_DIALOG_ADD };
	CEdit	m_ctrData;
	CString	m_strData;
	CString	m_strLabel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSysInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSysInfoDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSYSINFODLG_H__7115B940_D3D8_4A55_97D0_B51683E88768__INCLUDED_)
