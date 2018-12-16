#if !defined(AFX_USERDLG_H__BDD8A8A2_39A0_4A63_901C_08359A7BD892__INCLUDED_)
#define AFX_USERDLG_H__BDD8A8A2_39A0_4A63_901C_08359A7BD892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserDlg.h : header file
//
#include "password.h"
/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog

class CUserDlg : public CDialog
{
// Construction
public:
	CUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserDlg)
	enum { IDD = IDD_DIALOG_USER };
	CButton	m_bntOK;
	CButton	m_bntNew;
	CButton	m_bntDelete;
	CButton	m_bntCancel;
	CEdit	m_ctrPass;
	CEdit	m_ctrUser;
	CListCtrl	m_ctrList;
	BOOL	m_bIsAdmin;
	CString	m_strUser;
	CString	m_strPass;
	CString	m_strRePass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickListUsername(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	virtual void OnOK();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void RefreshData();
	CPassWord m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERDLG_H__BDD8A8A2_39A0_4A63_901C_08359A7BD892__INCLUDED_)
