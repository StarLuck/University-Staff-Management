#if !defined(AFX_HONORDLG_H__E551C088_69A0_4ADC_AA01_4F8F2143C15A__INCLUDED_)
#define AFX_HONORDLG_H__E551C088_69A0_4ADC_AA01_4F8F2143C15A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HonorDlg.h : header file
//
#include "honorset.h"
/////////////////////////////////////////////////////////////////////////////
// CHonorDlg dialog

class CHonorDlg : public CDialog
{
// Construction
public:
	CHonorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHonorDlg)
	enum { IDD = IDD_PAGE_HONOR };
	CListCtrl	m_ctrList;
	CButton	m_bntSave;
	CButton	m_bntNew;
	CButton	m_bntModify;
	CButton	m_bntDelete;
	CTime	m_tmDate1;
	CTime	m_tmDate2;
	CString	m_strDept;
	CString	m_strReason1;
	CString	m_strReason2;
	CString	m_strSorts;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHonorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHonorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonNew();
	afx_msg void OnButtonSave1();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_strID;
	CHonorSet  m_recordset;
public:
	void RefreshData(CString strID);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HONORDLG_H__E551C088_69A0_4ADC_AA01_4F8F2143C15A__INCLUDED_)
