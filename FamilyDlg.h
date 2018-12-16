#if !defined(AFX_FAMILYDLG_H__0B33D285_80E2_4733_AAF6_B0CCD8B5DC99__INCLUDED_)
#define AFX_FAMILYDLG_H__0B33D285_80E2_4733_AAF6_B0CCD8B5DC99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FamilyDlg.h : header file
//
#include "familyset.h"
/////////////////////////////////////////////////////////////////////////////
// CFamilyDlg dialog

class CFamilyDlg : public CDialog
{
// Construction
public:
	CFamilyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFamilyDlg)
	enum { IDD = IDD_PAGE_FAMILY };
	CListCtrl	m_ctrList;
	CButton	m_bntSave;
	CButton	m_bntNew;
	CButton	m_bntModify;
	CButton	m_bntDelete;
	CTime	m_tmDate;
	CString	m_strDuty;
	CString	m_strName;
	CString	m_strPhone;
	CString	m_strPolitical;
	CString	m_strRelation;
	CString	m_strDept;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFamilyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFamilyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonNew();
	afx_msg void OnButtonSave1();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
	CFamilySet  m_recordset;
public:
	void RefreshData(CString strID);
	CString m_strID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FAMILYDLG_H__0B33D285_80E2_4733_AAF6_B0CCD8B5DC99__INCLUDED_)
