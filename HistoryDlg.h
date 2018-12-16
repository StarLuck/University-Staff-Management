#if !defined(AFX_HISTORYDLG_H__07D91CF7_23F5_4EC3_B129_F35CA639304A__INCLUDED_)
#define AFX_HISTORYDLG_H__07D91CF7_23F5_4EC3_B129_F35CA639304A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistoryDlg.h : header file
//
#include "HistorySet.h"
/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg dialog

class CHistoryDlg : public CDialog
{
// Construction
public:
	CHistoryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryDlg)
	enum { IDD = IDD_PAGE_HISTORY };
	CListCtrl	m_ctrList;
	CButton	m_bntSave;
	CButton	m_bntNew;
	CButton	m_bntModify;
	CButton	m_bntDelete;
	CTime	m_tmDate1;
	CTime	m_tmDate2;
	CString	m_strDept;
	CString	m_strDuty;
	CString	m_strLevel;
	CString	m_strCompany;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonSave1();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_strID;
	CHistorySet  m_recordset;
public:
	void RefreshData(CString strID);
	

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYDLG_H__07D91CF7_23F5_4EC3_B129_F35CA639304A__INCLUDED_)
