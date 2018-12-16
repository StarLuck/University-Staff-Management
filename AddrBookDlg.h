#if !defined(AFX_ADDRBOOKDLG_H__4BFEE65F_C25C_4ADB_B095_414D03C3F2B6__INCLUDED_)
#define AFX_ADDRBOOKDLG_H__4BFEE65F_C25C_4ADB_B095_414D03C3F2B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddrBookDlg.h : header file
//
#include "AddrbookSet.h"
#include "BookInfoDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CAddrBookDlg dialog

class CAddrBookDlg : public CDialog
{
// Construction
public:
	CAddrBookDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddrBookDlg)
	enum { IDD = IDD_DIALOG_BOOK };
	CListCtrl	m_ctrList;
	int		m_nCondition;
	CString	m_strContent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddrBookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddrBookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void RefreshData(CString strSQL);
	CAddrbookSet   m_recordset;
	CBookInfoDlg    m_BookInfoDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRBOOKDLG_H__4BFEE65F_C25C_4ADB_B095_414D03C3F2B6__INCLUDED_)
