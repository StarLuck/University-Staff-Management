#if !defined(AFX_ATTSTATSET_H__F1947EB7_0592_4AD0_B564_F65BB9AF92C6__INCLUDED_)
#define AFX_ATTSTATSET_H__F1947EB7_0592_4AD0_B564_F65BB9AF92C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttStatSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttStatSet recordset

class CAttStatSet : public CRecordset
{
public:
	CAttStatSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAttStatSet)

// Field/Param Data
	//{{AFX_FIELD(CAttStatSet, CRecordset)
	long	m_ID;
	CString	m_YEAR_MONTH;
	CString	m_PERSON;
	int		m_WORK_HOUR;
	long	m_OVER_HOUR;
	int		m_LEAVE_HDAY;
	int		m_ERRAND_HDAY;
	BYTE	m_LATE_TIMES;
	BYTE	m_EARLY_TIMES;
	BYTE	m_ABSENT_TIMES;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttStatSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTSTATSET_H__F1947EB7_0592_4AD0_B564_F65BB9AF92C6__INCLUDED_)
