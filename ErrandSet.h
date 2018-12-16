#if !defined(AFX_ERRANDSET_H__6400A98F_0492_4AB0_A86B_37F41AFCD4A1__INCLUDED_)
#define AFX_ERRANDSET_H__6400A98F_0492_4AB0_A86B_37F41AFCD4A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ErrandSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CErrandSet recordset

class CErrandSet : public CRecordset
{
public:
	CErrandSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CErrandSet)

// Field/Param Data
	//{{AFX_FIELD(CErrandSet, CRecordset)
	long	m_ID;
	CString	m_PERSON;
	CTime	m_START_TIME;
	CTime	m_END_TIME;
	CString	m_DESCRIPTION;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CErrandSet)
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

#endif // !defined(AFX_ERRANDSET_H__6400A98F_0492_4AB0_A86B_37F41AFCD4A1__INCLUDED_)
