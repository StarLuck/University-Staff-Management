#if !defined(AFX_FOLKSET_H__0C3F5A75_A3E2_4FB1_8034_E53286CC6E51__INCLUDED_)
#define AFX_FOLKSET_H__0C3F5A75_A3E2_4FB1_8034_E53286CC6E51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FolkSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFolkSet recordset

class CFolkSet : public CRecordset
{
public:
	CFolkSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFolkSet)

// Field/Param Data
	//{{AFX_FIELD(CFolkSet, CRecordset)
	long	m_ID;
	CString	m_folk;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFolkSet)
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

#endif // !defined(AFX_FOLKSET_H__0C3F5A75_A3E2_4FB1_8034_E53286CC6E51__INCLUDED_)
