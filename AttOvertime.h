#if !defined(AFX_AttOvertime_H__678D0383_ABEA_11D6_8649_0088CC174723__INCLUDED_)
#define AFX_AttOvertime_H__678D0383_ABEA_11D6_8649_0088CC174723__INCLUDED_

#include "OvertimeSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttOvertime.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttOvertime dialog

class CAttOvertime : public CPropertyPage
{
	DECLARE_DYNCREATE(CAttOvertime)

// Construction
public:
	void UpdateList(COvertimeSet& rs);

	CAttOvertime();
	~CAttOvertime();

// Dialog Data
	//{{AFX_DATA(CAttOvertime)
	enum { IDD = IDD_PAGE_ATTOVERTIME };
	CListCtrl	m_cList;
	int		m_nHour;
	CString	m_strPersonID;
	CString	m_strPersonName;
	CTime	m_Date;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAttOvertime)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAttOvertime)
	afx_msg void OnChangeEdtOvertimePersonid();
	afx_msg void OnBtnOvertimeAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnOvertimeDeleteattend();
	afx_msg void OnBtnOvertimeSeekio();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AttOvertime_H__678D0383_ABEA_11D6_8649_0088CC174723__INCLUDED_)
