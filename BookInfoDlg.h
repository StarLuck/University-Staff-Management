#if !defined(AFX_BOOKINFODLG_H__D84A3037_0B26_4E86_A25C_6CAE81ED4F54__INCLUDED_)
#define AFX_BOOKINFODLG_H__D84A3037_0B26_4E86_A25C_6CAE81ED4F54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookInfoDlg dialog

class CBookInfoDlg : public CDialog
{
// Construction
public:
	CBookInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBookInfoDlg)
	enum { IDD = IDD_DIALOG_BOOKINFO };
	CString	m_strSex;
	CString	m_strCall;
	CString	m_strComments;
	CString	m_strEmail;
	CString	m_strMphone;
	CString	m_strName;
	CString	m_strPhone1;
	CString	m_strPhone2;
	CString	m_strQQ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookInfoDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKINFODLG_H__D84A3037_0B26_4E86_A25C_6CAE81ED4F54__INCLUDED_)
