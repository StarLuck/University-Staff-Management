#if !defined(AFX_AttErrand_H__6AFEEA08_ABF0_11D6_8649_0088CC174723__INCLUDED_)
#define AFX_AttErrand_H__6AFEEA08_ABF0_11D6_8649_0088CC174723__INCLUDED_

#include "ErrandSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttErrand.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttErrand dialog

class CAttErrand : public CPropertyPage
{
	DECLARE_DYNCREATE(CAttErrand)

// Construction
public:
	void UpdateList(CErrandSet& rs);

	CAttErrand();
	~CAttErrand();

// Dialog Data
	//{{AFX_DATA(CAttErrand)
	enum { IDD = IDD_PAGE_ATTERRAND };
	CListCtrl	m_cList;
	CString	m_strSTime;
	CString	m_strETime;
	CString	m_strPersonID;
	CString	m_strPersonName;
	CString	m_strDescription;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAttErrand)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAttErrand)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdtErrandPersonid();
	afx_msg void OnBtnErrandAdd();
	afx_msg void OnBtnErrandDeleteattend();
	afx_msg void OnBtnErrandSeekio();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AttErrand_H__6AFEEA08_ABF0_11D6_8649_0088CC174723__INCLUDED_)
