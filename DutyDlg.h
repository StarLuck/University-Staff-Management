#if !defined(AFX_DUTYDLG_H__EB1145CB_224B_4F1A_B70F_B5C38FA0A6C7__INCLUDED_)
#define AFX_DUTYDLG_H__EB1145CB_224B_4F1A_B70F_B5C38FA0A6C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DutyDlg.h : header file
//
#include "DutySet.h"
/////////////////////////////////////////////////////////////////////////////
// CDutyDlg dialog

class CDutyDlg : public CDialog
{
// Construction
public:
	CDutyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDutyDlg)
	enum { IDD = IDD_DIALOG_DUTY };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDutyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDutyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private :
	void RefreshData();
	CDutySet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUTYDLG_H__EB1145CB_224B_4F1A_B70F_B5C38FA0A6C7__INCLUDED_)
