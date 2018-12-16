#if !defined(AFX_WORKERSTATUSSET_H__F752333D_778F_4774_94A9_D8D89039AFD6__INCLUDED_)
#define AFX_WORKERSTATUSSET_H__F752333D_778F_4774_94A9_D8D89039AFD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkerStatusSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWorkerStatusSet recordset

class CWorkerStatusSet : public CRecordset
{
public:
	CWorkerStatusSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CWorkerStatusSet)

// Field/Param Data
	//{{AFX_FIELD(CWorkerStatusSet, CRecordset)
	long	m_ID;
	CString	m_workstatus;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkerStatusSet)
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

#endif // !defined(AFX_WORKERSTATUSSET_H__F752333D_778F_4774_94A9_D8D89039AFD6__INCLUDED_)
