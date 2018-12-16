#if !defined(AFX_EDUCATIONDLG_H__1ACEDA1B_9ADA_46C2_921F_5E6AD239A90C__INCLUDED_)
#define AFX_EDUCATIONDLG_H__1ACEDA1B_9ADA_46C2_921F_5E6AD239A90C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EducationDlg.h : header file
//
#include "EducationSet.h"
/////////////////////////////////////////////////////////////////////////////
// CEducationDlg dialog

class CEducationDlg : public CDialog
{
// Construction
public:
	CEducationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEducationDlg)
	enum { IDD = IDD_DIALOG_EDUCATION };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEducationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEducationDlg)
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private :
	void RefreshData();
	CEducationSet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDUCATIONDLG_H__1ACEDA1B_9ADA_46C2_921F_5E6AD239A90C__INCLUDED_)
