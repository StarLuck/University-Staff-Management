#if !defined(AFX_ABOUTPAYDLG_H__BC03866C_9FAA_4965_966A_3AB748B4360F__INCLUDED_)
#define AFX_ABOUTPAYDLG_H__BC03866C_9FAA_4965_966A_3AB748B4360F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AboutPayDlg.h : header file
//
#include "AboutPaySet.h"
/////////////////////////////////////////////////////////////////////////////
// CAboutPayDlg dialog

class CAboutPayDlg : public CDialog
{
// Construction
public:
	CAboutPayDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAboutPayDlg)
	enum { IDD = IDD_DIALOG_PAY };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutPayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAboutPayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private :
	void RefreshData();
	CAboutPaySet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUTPAYDLG_H__BC03866C_9FAA_4965_966A_3AB748B4360F__INCLUDED_)
