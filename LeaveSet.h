#if !defined(AFX_LEAVESET_H__97ABB308_3807_40EA_B480_B66A99260538__INCLUDED_)
#define AFX_LEAVESET_H__97ABB308_3807_40EA_B480_B66A99260538__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeaveSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeaveSet recordset

class CLeaveSet : public CRecordset
{
public:
	CLeaveSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLeaveSet)

// Field/Param Data
	//{{AFX_FIELD(CLeaveSet, CRecordset)
	long	m_ID;
	CString	m_PERSON;
	CTime	m_START_TIME;
	CTime	m_END_TIME;
	CString	m_REASON;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeaveSet)
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

#endif // !defined(AFX_LEAVESET_H__97ABB308_3807_40EA_B480_B66A99260538__INCLUDED_)
