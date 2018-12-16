#if !defined(AFX_HONORSET_H__0020B4E2_F775_49A7_B5B5_BF1CB9ACECCC__INCLUDED_)
#define AFX_HONORSET_H__0020B4E2_F775_49A7_B5B5_BF1CB9ACECCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HonorSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHonorSet recordset

class CHonorSet : public CRecordset
{
public:
	CHonorSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CHonorSet)

// Field/Param Data
	//{{AFX_FIELD(CHonorSet, CRecordset)
	long	m_ID;
	CString	m_code;
	CString	m_sorts;
	CTime	m_date1;
	CString	m_reason1;
	CString	m_dept;
	CTime	m_date2;
	CString	m_reason2;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHonorSet)
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

#endif // !defined(AFX_HONORSET_H__0020B4E2_F775_49A7_B5B5_BF1CB9ACECCC__INCLUDED_)
