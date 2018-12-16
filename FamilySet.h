#if !defined(AFX_FAMILYSET_H__805848CB_6930_4B24_9615_7E4C47DFC322__INCLUDED_)
#define AFX_FAMILYSET_H__805848CB_6930_4B24_9615_7E4C47DFC322__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FamilySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFamilySet recordset

class CFamilySet : public CRecordset
{
public:
	CFamilySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFamilySet)

// Field/Param Data
	//{{AFX_FIELD(CFamilySet, CRecordset)
	long	m_ID;
	CString	m_code;
	CString	m_name;
	CString	m_relation;
	CTime	m_date;
	CString	m_dept;
	CString	m_duty;
	CString	m_political;
	CString	m_phone;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFamilySet)
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

#endif // !defined(AFX_FAMILYSET_H__805848CB_6930_4B24_9615_7E4C47DFC322__INCLUDED_)
