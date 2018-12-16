#if !defined(AFX_DEPTDLG_H__CBCBBD6D_4418_41F6_868C_0E87B21953E0__INCLUDED_)
#define AFX_DEPTDLG_H__CBCBBD6D_4418_41F6_868C_0E87B21953E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptDlg.h : header file
//
#include "DeptSet.h"
/////////////////////////////////////////////////////////////////////////////
// CDeptDlg dialog

class CDeptDlg : public CDialog
{
// Construction
public:
	CDeptDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeptDlg)
	enum { IDD = IDD_DIALOG_DEPT };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private :
	void RefreshData();
	CDeptSet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPTDLG_H__CBCBBD6D_4418_41F6_868C_0E87B21953E0__INCLUDED_)
