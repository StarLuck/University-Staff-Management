#if !defined(AFX_ABOUTPAYSET_H__6B616BC7_DAD5_462D_B3C7_CF933C7E081C__INCLUDED_)
#define AFX_ABOUTPAYSET_H__6B616BC7_DAD5_462D_B3C7_CF933C7E081C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AboutPaySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAboutPaySet recordset

class CAboutPaySet : public CRecordset
{
public:
	CAboutPaySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAboutPaySet)

// Field/Param Data
	//{{AFX_FIELD(CAboutPaySet, CRecordset)
	long	m_ID;
	CString	m_aboutpay;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutPaySet)
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

#endif // !defined(AFX_ABOUTPAYSET_H__6B616BC7_DAD5_462D_B3C7_CF933C7E081C__INCLUDED_)
