#if !defined(AFX_SEARCHDLG_H__8B7F33C6_3521_4581_95B1_70E9AF440A04__INCLUDED_)
#define AFX_SEARCHDLG_H__8B7F33C6_3521_4581_95B1_70E9AF440A04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDlg.h : header file
//
#include "PersonSet.h"
/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog

class CSearchDlg : public CDialog
{
// Construction
public:
	CSearchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchDlg)
	enum { IDD = IDD_DIALOG_SEARCH };
	CListCtrl	m_ctrList;
	CComboBox	m_ctrTechnical;
	CComboBox	m_ctrPolitical;
	CComboBox	m_ctrMarry;
	CComboBox	m_ctrIsWorker;
	CComboBox	m_ctrFolk;
	CComboBox	m_ctrEducation;
	CComboBox	m_ctrDuty;
	CComboBox	m_ctrDept;
	CComboBox	m_ctrAboutPay;
	CString	m_strAboutPay;
	CString	m_strDept;
	CString	m_strDuty;
	CString	m_strEducation;
	CString	m_strFolk;
	CString	m_strIsWorker;
	CString	m_strMarry;
	CString	m_strPolitical;
	CString	m_strSex;
	CString	m_strTechnical;
	int		m_nAge;
	CString	m_strDept2;
	CString	m_strDept3;
	CString	m_strName;
	CString	m_strNative;
	BOOL	m_bType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPersonSet m_PersonSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDLG_H__8B7F33C6_3521_4581_95B1_70E9AF440A04__INCLUDED_)
