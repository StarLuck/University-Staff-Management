#if !defined(AFX_TRAINSET_H__AB9869A6_A319_4DF0_A98F_B9DC3777CB02__INCLUDED_)
#define AFX_TRAINSET_H__AB9869A6_A319_4DF0_A98F_B9DC3777CB02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TrainSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTrainSet recordset

class CTrainSet : public CRecordset
{
public:
	CTrainSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTrainSet)

// Field/Param Data
	//{{AFX_FIELD(CTrainSet, CRecordset)
	long	m_ID;
	CString	m_code;
	CString	m_mode;
	CTime	m_date1;
	CTime	m_date2;
	CString	m_term;
	CString	m_subject;
	CString	m_dept;
	CString	m_content;
	CString	m_outlay;
	CString	m_result;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainSet)
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

#endif // !defined(AFX_TRAINSET_H__AB9869A6_A319_4DF0_A98F_B9DC3777CB02__INCLUDED_)
