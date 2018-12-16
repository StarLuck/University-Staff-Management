#if !defined(AFX_EDUCATIONSET_H__EF353A9F_0BF6_41EE_9CE6_4F6414269682__INCLUDED_)
#define AFX_EDUCATIONSET_H__EF353A9F_0BF6_41EE_9CE6_4F6414269682__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EducationSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEducationSet recordset

class CEducationSet : public CRecordset
{
public:
	CEducationSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CEducationSet)

// Field/Param Data
	//{{AFX_FIELD(CEducationSet, CRecordset)
	long	m_ID;
	CString	m_education;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEducationSet)
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

#endif // !defined(AFX_EDUCATIONSET_H__EF353A9F_0BF6_41EE_9CE6_4F6414269682__INCLUDED_)
