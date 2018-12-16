#if !defined(AFX_TRAINDLG_H__FAA3AA0B_91BC_4078_9D0D_2857FFD0737D__INCLUDED_)
#define AFX_TRAINDLG_H__FAA3AA0B_91BC_4078_9D0D_2857FFD0737D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TrainDlg.h : header file
//
#include "TrainSet.h"
/////////////////////////////////////////////////////////////////////////////
// CTrainDlg dialog

class CTrainDlg : public CDialog
{
// Construction
public:
	CTrainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTrainDlg)
	enum { IDD = IDD_PAGE_TRAIN };
	CListCtrl	m_ctrList;
	CButton	m_bntSave;
	CButton	m_bntNew;
	CButton	m_bntModify;
	CButton	m_bntDelete;
	CTime	m_tmDate1;
	CTime	m_tmDate2;
	CString	m_strContent;
	CString	m_strDept;
	CString	m_strMode;
	CString	m_strOutlay;
	CString	m_strResult;
	CString	m_strSubject;
	CString	m_strTerm;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTrainDlg)
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
	CTrainSet  m_recordset;
public:
	void RefreshData(CString strID);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINDLG_H__FAA3AA0B_91BC_4078_9D0D_2857FFD0737D__INCLUDED_)
