#if !defined(AFX_FOLKDLG_H__7CED2BBD_2E24_4DC5_9D1C_5950480ACD93__INCLUDED_)
#define AFX_FOLKDLG_H__7CED2BBD_2E24_4DC5_9D1C_5950480ACD93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FolkDlg.h : header file
//
#include "FolkSet.h"
/////////////////////////////////////////////////////////////////////////////
// CFolkDlg dialog

class CFolkDlg : public CDialog
{
// Construction
public:
	CFolkDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFolkDlg)
	enum { IDD = IDD_DIALOG_FOLK };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFolkDlg)
	afx_msg void OnButtonNew();
	afx_msg void OnButtonDelete();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private :
	void RefreshData();
	CFolkSet m_recordset ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOLKDLG_H__7CED2BBD_2E24_4DC5_9D1C_5950480ACD93__INCLUDED_)
