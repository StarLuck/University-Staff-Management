#if !defined(AFX_NOTEPADDLG_H__C1B6E7C8_063C_487B_B230_8CBC0F7A4D6D__INCLUDED_)
#define AFX_NOTEPADDLG_H__C1B6E7C8_063C_487B_B230_8CBC0F7A4D6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NotePadDlg.h : header file
//
#include "NotePadSet.h"
/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg dialog

class CNotePadDlg : public CDialog
{
// Construction
public:
	CNotePadDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNotePadDlg)
	enum { IDD = IDD_DIALOG_NOTEPAD };
	CButton	m_bntNew;
	CButton	m_bntModify;
	CButton	m_bntDelete;
	CButton	m_bntOK;
	CListCtrl	m_ctrList;
	CComboBox	m_ctrCondition;
	CButton	m_bntCancel;
	CTime	m_tmDate;
	CString	m_strContent;
	CString	m_strSort;
	CString	m_strTitle;
	CString	m_strComments;
	int		m_nCondition;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNotePadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnButtonCancel();
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void RefreshData(CString strSQL);
	CNotePadSet  m_recordset;
	CString m_strID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPADDLG_H__C1B6E7C8_063C_487B_B230_8CBC0F7A4D6D__INCLUDED_)
