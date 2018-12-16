#if !defined(AFX_DUTYSET_H__C9910261_2C6C_471C_912C_353ED8C12DD5__INCLUDED_)
#define AFX_DUTYSET_H__C9910261_2C6C_471C_912C_353ED8C12DD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DutySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDutySet recordset

class CDutySet : public CRecordset
{
public:
	CDutySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDutySet)

// Field/Param Data
	//{{AFX_FIELD(CDutySet, CRecordset)
	long	m_ID;
	CString	m_duty;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDutySet)
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

#endif // !defined(AFX_DUTYSET_H__C9910261_2C6C_471C_912C_353ED8C12DD5__INCLUDED_)
