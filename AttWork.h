#if !defined(AFX_PAGE1_H__678D0381_ABEA_11D6_8649_0088CC174723__INCLUDED_)
#define AFX_PAGE1_H__678D0381_ABEA_11D6_8649_0088CC174723__INCLUDED_

#include "AttendanceSet.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//

/////////////////////////////////////////////////////////////////////////////


class CAttWork : public CPropertyPage
{
	DECLARE_DYNCREATE(CAttWork)

// Construction
public:
	void UpdateList(CAttendanceSet& rs);
	void AddRecord(CString strPersonID);

	CAttWork();
	~CAttWork();

// Dialog Data
	//{{AFX_DATA(CAttWork)
	enum { IDD = IDD_PAGE_ATTWORK };
	CComboBox	m_ctrPersonID;
	CComboBox	m_ctrDepartment;
	CListCtrl	m_cList;
	CString	m_strIOTime;
	CString	m_strDepartment;
	CString	m_strPersonID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAttWork)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAttWork)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnAddperson();
	afx_msg void OnBtnAdddepart();
	afx_msg void OnBtnAddall();
	afx_msg void OnBtnDeleteattend();
	afx_msg void OnBtnSearch();
	afx_msg void OnSetfocusComboPersonid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE1_H__678D0381_ABEA_11D6_8649_0088CC174723__INCLUDED_)
