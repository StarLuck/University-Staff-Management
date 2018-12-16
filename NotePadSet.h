#if !defined(AFX_NOTEPADSET_H__0FC62C49_59D3_4353_8335_2BFC564FC712__INCLUDED_)
#define AFX_NOTEPADSET_H__0FC62C49_59D3_4353_8335_2BFC564FC712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NotePadSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNotePadSet recordset

class CNotePadSet : public CRecordset
{
public:
	CNotePadSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CNotePadSet)

// Field/Param Data
	//{{AFX_FIELD(CNotePadSet, CRecordset)
	long	m_ID;
	CTime	m_date;
	CString	m_sort;
	CString	m_caption;
	CString	m_comments;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadSet)
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

#endif // !defined(AFX_NOTEPADSET_H__0FC62C49_59D3_4353_8335_2BFC564FC712__INCLUDED_)
