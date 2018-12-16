#if !defined(AFX_OVERTIMESET_H__1597426E_9FC6_4E83_A6A5_82821CF23AB8__INCLUDED_)
#define AFX_OVERTIMESET_H__1597426E_9FC6_4E83_A6A5_82821CF23AB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OvertimeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COvertimeSet recordset

class COvertimeSet : public CRecordset
{
public:
	COvertimeSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COvertimeSet)

// Field/Param Data
	//{{AFX_FIELD(COvertimeSet, CRecordset)
	long	m_ID;
	CString	m_PERSON;
	BYTE	m_WORK_HOURS;
	CTime	m_WORK_DATE;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COvertimeSet)
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

#endif // !defined(AFX_OVERTIMESET_H__1597426E_9FC6_4E83_A6A5_82821CF23AB8__INCLUDED_)
