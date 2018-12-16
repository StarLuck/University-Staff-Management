#if !defined(AFX_WORKERSTATUSDLG_H__73745A2F_F7F5_4BFF_AE38_4C78636DF389__INCLUDED_)
#define AFX_WORKERSTATUSDLG_H__73745A2F_F7F5_4BFF_AE38_4C78636DF389__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkerStatusDlg.h : header file
//
#include "WorkerStatusSet.h"
/////////////////////////////////////////////////////////////////////////////
// CWorkerStatusDlg dialog

class CWorkerStatusDlg : public CDialog
{
// Construction
public:
	CWorkerStatusDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkerStatusDlg)
	enum { IDD = IDD_DIALOG_STATUS };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerStatusDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWorkerStatusDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private :
	void RefreshData();
	CWorkerStatusSet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKERSTATUSDLG_H__73745A2F_F7F5_4BFF_AE38_4C78636DF389__INCLUDED_)
