#if !defined(AFX_ATTSTATDLG_H__18133862_B5B6_4CE5_BB6F_C706751F064D__INCLUDED_)
#define AFX_ATTSTATDLG_H__18133862_B5B6_4CE5_BB6F_C706751F064D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttStatDlg.h : header file
//
#include "AttStatSet.h"
/////////////////////////////////////////////////////////////////////////////
// CAttStatDlg dialog

class CAttStatDlg : public CDialog
{
// Construction
public:
	CAttStatDlg(CWnd* pParent = NULL);   // standard constructor
	void UpdateList(CAttStatSet& rs);
// Dialog Data
	//{{AFX_DATA(CAttStatDlg)
	enum { IDD = IDD_DIALOG_ATT_STAT };
	CListCtrl	m_cList;
	CString	m_strTime;
	CTime	m_STime;
	CTime	m_ETime;
	BOOL	m_bSeekbytime;
	BOOL	m_bSeekbyperson;
	CString	m_strSeektime;
	CString	m_strPersonID;
	CString	m_strPersonName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttStatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAttStatDlg)
	afx_msg void OnChangeStatEdtSeekpersonid();
	afx_msg void OnStatBtnSeek();
	virtual BOOL OnInitDialog();
	afx_msg void OnStatBtnStat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CTime StrToTime(CString str);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTSTATDLG_H__18133862_B5B6_4CE5_BB6F_C706751F064D__INCLUDED_)
