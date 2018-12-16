#if !defined(AFX_DEPTSET_H__6DB80F43_D26C_4F23_B27A_5EF4DC76149D__INCLUDED_)
#define AFX_DEPTSET_H__6DB80F43_D26C_4F23_B27A_5EF4DC76149D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptSet recordset

class CDeptSet : public CRecordset
{
public:
	CDeptSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDeptSet)

// Field/Param Data
	//{{AFX_FIELD(CDeptSet, CRecordset)
	long	m_ID;
	CString	m_dept;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptSet)
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

#endif // !defined(AFX_DEPTSET_H__6DB80F43_D26C_4F23_B27A_5EF4DC76149D__INCLUDED_)
