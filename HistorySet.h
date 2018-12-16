#if !defined(AFX_HISTORYSET_H__60CD995C_4435_49C8_9498_0C9D0069B0F3__INCLUDED_)
#define AFX_HISTORYSET_H__60CD995C_4435_49C8_9498_0C9D0069B0F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistorySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistorySet recordset

class CHistorySet : public CRecordset
{
public:
	CHistorySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CHistorySet)

// Field/Param Data
	//{{AFX_FIELD(CHistorySet, CRecordset)
	long	m_ID;
	CString	m_code;
	CTime	m_date1;
	CTime	m_date2;
	CString	m_company;
	CString	m_duty;
	CString	m_dept;
	CString	m_level1;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistorySet)
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

#endif // !defined(AFX_HISTORYSET_H__60CD995C_4435_49C8_9498_0C9D0069B0F3__INCLUDED_)
