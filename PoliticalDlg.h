#if !defined(AFX_POLITICALDLG_H__6821F2DC_47AE_405E_B04E_A4181D6A37ED__INCLUDED_)
#define AFX_POLITICALDLG_H__6821F2DC_47AE_405E_B04E_A4181D6A37ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PoliticalDlg.h : header file
//
#include "PoliticalSet.h"
/////////////////////////////////////////////////////////////////////////////
// CPoliticalDlg dialog

class CPoliticalDlg : public CDialog
{
// Construction
public:
	CPoliticalDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPoliticalDlg)
	enum { IDD = IDD_DIALOG_POLITICAL };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoliticalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPoliticalDlg)
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private :
	void RefreshData();
	CPoliticalSet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLITICALDLG_H__6821F2DC_47AE_405E_B04E_A4181D6A37ED__INCLUDED_)
