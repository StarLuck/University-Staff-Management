#if !defined(AFX_TECHNICALSET_H__CE3442AE_96B4_4EB2_AB2E_35AC8A473D91__INCLUDED_)
#define AFX_TECHNICALSET_H__CE3442AE_96B4_4EB2_AB2E_35AC8A473D91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TechnicalSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTechnicalSet recordset

class CTechnicalSet : public CRecordset
{
public:
	CTechnicalSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTechnicalSet)

// Field/Param Data
	//{{AFX_FIELD(CTechnicalSet, CRecordset)
	long	m_ID;
	CString	m_technical;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTechnicalSet)
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

#endif // !defined(AFX_TECHNICALSET_H__CE3442AE_96B4_4EB2_AB2E_35AC8A473D91__INCLUDED_)
