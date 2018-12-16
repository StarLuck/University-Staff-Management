#if !defined(AFX_QUALIFICATIONSET_H__0747C492_3EF3_4FA8_BBF1_D4CCA52161F5__INCLUDED_)
#define AFX_QUALIFICATIONSET_H__0747C492_3EF3_4FA8_BBF1_D4CCA52161F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QualificationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQualificationSet recordset

class CQualificationSet : public CRecordset
{
public:
	CQualificationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CQualificationSet)

// Field/Param Data
	//{{AFX_FIELD(CQualificationSet, CRecordset)
	long	m_ID;
	CString	m_code;
	CString	m_tech;
	CString	m_mode;
	CTime	m_date0;
	CString	m_duty;
	CTime	m_date1;
	CTime	m_date2;
	CString	m_dept;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQualificationSet)
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

#endif // !defined(AFX_QUALIFICATIONSET_H__0747C492_3EF3_4FA8_BBF1_D4CCA52161F5__INCLUDED_)
