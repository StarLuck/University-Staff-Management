#if !defined(AFX_PAGE3_H__6AFEEA01_ABF0_11D6_8649_0088CC174723__INCLUDED_)
#define AFX_PAGE3_H__6AFEEA01_ABF0_11D6_8649_0088CC174723__INCLUDED_

#include "LeaveSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// 

class CAttLeave : public CPropertyPage
{
	DECLARE_DYNCREATE(CAttLeave)

// Construction
public:
	void UpdateList(CLeaveSet& rs);
	CBrush m_brush;
	CAttLeave();
	~CAttLeave();

// Dialog Data
	//{{AFX_DATA(CAttLeave)
	enum { IDD = IDD_PAGE_ATTLEAVE };
	CListCtrl	m_cList;
	CString	m_strSTime;
	CString	m_strETime;
	CString	m_strReason;
	CString	m_strPersonID;
	CString	m_strPersonName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAttLeave)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAttLeave)
	afx_msg void OnChangeEdtLeavePersonid();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnLeaveAdd();
	afx_msg void OnBtnLeaveDeleteattend();
	afx_msg void OnBtnLeaveSeekio();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3_H__6AFEEA01_ABF0_11D6_8649_0088CC174723__INCLUDED_)
