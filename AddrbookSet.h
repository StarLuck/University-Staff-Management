#if !defined(AFX_ADDRBOOKSET_H__14E02AF4_0E99_49EB_8B56_8815389CFFE5__INCLUDED_)
#define AFX_ADDRBOOKSET_H__14E02AF4_0E99_49EB_8B56_8815389CFFE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddrbookSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddrbookSet recordset

class CAddrbookSet : public CRecordset
{
public:
	CAddrbookSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAddrbookSet)

// Field/Param Data
	//{{AFX_FIELD(CAddrbookSet, CRecordset)
	long	m_ID;
	CString	m_name;
	CString	m_sex;
	CString	m_phone1;
	CString	m_phone2;
	CString	m_call;
	CString	m_mphone;
	CString	m_oicq;
	CString	m_email;
	CString	m_comments;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddrbookSet)
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

#endif // !defined(AFX_ADDRBOOKSET_H__14E02AF4_0E99_49EB_8B56_8815389CFFE5__INCLUDED_)
