#if !defined(AFX_BASEINFODLG_H__FD74490D_1207_4D67_8565_84FEB6A76D0C__INCLUDED_)
#define AFX_BASEINFODLG_H__FD74490D_1207_4D67_8565_84FEB6A76D0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BaseInfoDlg.h : header file
//
#include "PersonSet.h"

/////////////////////////////////////////////////////////////////////////////
// CBaseInfoDlg dialog

class CBaseInfoDlg : public CDialog
{
// Construction
public:
	CBaseInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBaseInfoDlg)
	enum { IDD = IDD_PAGE_BASEINFO };
	CEdit	m_ctrID;
	CComboBox	m_ctrTechnical;
	CComboBox	m_ctrPolitical;
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
	CTime	m_tmBirth;
	CTime	m_tmDate1;
	CTime	m_tmDate2;
	CTime	m_tmGDate;
	CString	m_strAddress;
	CString	m_strAge;
	CString	m_strCardID;
	CString	m_strID;
	CString	m_strDept2;
	CString	m_strDept3;
	CString	m_strEMail;
	CString	m_strMobile;
	CString	m_strName;
	CString	m_strNative;
	CString	m_strPhone;
	CString	m_strSchool;
	CString	m_strSubject;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBaseInfoDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public :
	void RefreshData();
	void Clear();
	BOOL Save();
	BOOL Modify();
	CPersonSet *m_pPersonSet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEINFODLG_H__FD74490D_1207_4D67_8565_84FEB6A76D0C__INCLUDED_)
