#if !defined(AFX_BROWSEDLG_H__E54D82F4_4501_4BF1_899D_BEDCD6FCE80C__INCLUDED_)
#define AFX_BROWSEDLG_H__E54D82F4_4501_4BF1_899D_BEDCD6FCE80C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BrowseDlg.h : header file
//
//属性页头文件///////////////
#include "TabSheet.h"
#include "BaseInfoDlg.h"
#include "FamilyDlg.h"
#include "HistoryDlg.h"
#include "HonorDlg.h"
#include "QualificationDlg.h"
#include "TrainDlg.h"
//////////////////////////////
//数据集头文件
#include "PersonSet.h"

/////////////////////////////////////////////////////////////////////////////
// CBrowseDlg dialog

class CBrowseDlg : public CDialog
{
// Construction
public:
	CBrowseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBrowseDlg)
	enum { IDD = IDD_DIALOG_BROWSE };
	CButton	m_ctrCancelBnt;
	CButton	m_ctrModify;
	CButton	m_ctrSaveBnt;
	CButton	m_ctrNewBnt;
	CButton	m_ctrDelBnt;
	CComboBox	m_ctrCondition;
	CComboBox	m_ctrContent;
	CListCtrl	m_ctrList;
	CTabSheet	m_ctrTabSheet;
	CString	m_strContent;
	CString	m_strCode;
	CString	m_strName;
	int		m_nCondition;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBrowseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeComboCondition();
	afx_msg void OnSelchangeComboContent();
	afx_msg void OnEditupdateComboContent();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonModify();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonCancel();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBaseInfoDlg		m_BaseInfoDlg;
	CFamilyDlg			m_FamilyDlg;
	CHistoryDlg			m_HistoryDlg;
	CHonorDlg			m_HonorDlg;
	CQualificationDlg	m_QualificationDlg;
	CTrainDlg			m_TrainDlg;

	CPersonSet			m_recordset;
private:
	void RefreshData(CString strSQL);
	BOOL  m_bNew;//是否正在新建员工
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEDLG_H__E54D82F4_4501_4BF1_899D_BEDCD6FCE80C__INCLUDED_)
