#if !defined(AFX_POLITICALSET_H__E34369B0_1D48_4DB8_9106_596C4208A572__INCLUDED_)
#define AFX_POLITICALSET_H__E34369B0_1D48_4DB8_9106_596C4208A572__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PoliticalSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPoliticalSet recordset

class CPoliticalSet : public CRecordset
{
public:
	CPoliticalSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPoliticalSet)

// Field/Param Data
	//{{AFX_FIELD(CPoliticalSet, CRecordset)
	long	m_ID;
	CString	m_political;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoliticalSet)
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

#endif // !defined(AFX_POLITICALSET_H__E34369B0_1D48_4DB8_9106_596C4208A572__INCLUDED_)
