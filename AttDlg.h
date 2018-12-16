#if !defined(AFX_ATTDLG_H__678D0382_ABEA_11D6_8649_0088CC174723__INCLUDED_)
#define AFX_ATTDLG_H__678D0382_ABEA_11D6_8649_0088CC174723__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttDlg.h : header file
//
#include "AttWork.h"	
#include "AttLeave.h"	
#include "AttOvertime.h"	
#include "AttErrand.h"	
/////////////////////////////////////////////////////////////////////////////
// CAttDlg dialog

class CAttDlg : public CDialog
{
// Construction
public:
	CAttDlg(CWnd* pParent = NULL);   // standard constructor
	CAttWork		m_Page1; // ³öÇÚÒ³
	CAttOvertime	m_Page2; // ¼Ó°àÒ³
	CAttLeave		m_Page3; // Çë¼ÙÒ³
	CAttErrand		m_Page4; // ³ö²îÒ³
	CPropertySheet	m_Sheet;
// Dialog Data
	//{{AFX_DATA(CAttDlg)
	enum { IDD = IDD_DIALOG_ATT_EDIT };
	CTime	m_StartTime;
	CTime	m_EndTime;
	CString	m_strPersonID;
	CString	m_strName;
	BOOL	m_bSeekbyperson;
	BOOL	m_bSeekbytime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAttDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdtSeekpersonid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTDLG_H__678D0382_ABEA_11D6_8649_0088CC174723__INCLUDED_)
