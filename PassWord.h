#if !defined(AFX_PASSWORD_H__DCF3AE57_F26D_4117_9795_91FE8B04B819__INCLUDED_)
#define AFX_PASSWORD_H__DCF3AE57_F26D_4117_9795_91FE8B04B819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PassWord.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPassWord recordset

class CPassWord : public CRecordset
{
public:
	CPassWord(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPassWord)

// Field/Param Data
	//{{AFX_FIELD(CPassWord, CRecordset)
	CString	m_user;
	CString	m_passwd;
	BOOL	m_isadmin;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassWord)
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

#endif // !defined(AFX_PASSWORD_H__DCF3AE57_F26D_4117_9795_91FE8B04B819__INCLUDED_)
