#if !defined(AFX_QUALIFICATIONDLG_H__8BFF1670_B3AD_413E_A19E_0F74DB058388__INCLUDED_)
#define AFX_QUALIFICATIONDLG_H__8BFF1670_B3AD_413E_A19E_0F74DB058388__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QualificationDlg.h : header file
//
#include "QualificationSet.h"
/////////////////////////////////////////////////////////////////////////////
// CQualificationDlg dialog

class CQualificationDlg : public CDialog
{
// Construction
public:
	CQualificationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQualificationDlg)
	enum { IDD = IDD_PAGE_QUALIFICATION };
	CListCtrl	m_ctrList;
	CButton	m_bntSave;
	CButton	m_bntNew;
	CButton	m_bntModify;
	CButton	m_bntDelete;
	CTime	m_tmDate0;
	CTime	m_tmDate1;
	CTime	m_tmDate2;
	CString	m_strDept;
	CString	m_strDuty;
	CString	m_strMode;
	CString	m_strTech;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQualificationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQualificationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonNew();
	afx_msg void OnButtonSave1();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString				m_strID;
	CQualificationSet	m_recordset;
public:
	void RefreshData(CString strID);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUALIFICATIONDLG_H__8BFF1670_B3AD_413E_A19E_0F74DB058388__INCLUDED_)
