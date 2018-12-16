#if !defined(AFX_TECHNICALDLG_H__C5ACA53A_128A_4147_BC58_E99816D82CD6__INCLUDED_)
#define AFX_TECHNICALDLG_H__C5ACA53A_128A_4147_BC58_E99816D82CD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TechnicalDlg.h : header file
//
#include "technicalSet.h"
/////////////////////////////////////////////////////////////////////////////
// CTechnicalDlg dialog

class CTechnicalDlg : public CDialog
{
// Construction
public:
	CTechnicalDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTechnicalDlg)
	enum { IDD = IDD_DIALOG_TECHNICAL };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTechnicalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTechnicalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void RefreshData();
	CTechnicalSet m_recordset;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TECHNICALDLG_H__C5ACA53A_128A_4147_BC58_E99816D82CD6__INCLUDED_)
