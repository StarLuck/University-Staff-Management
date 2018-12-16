#if !defined(AFX_ATTENDANCESET_H__CD3C6C2C_D9AF_420D_B3B3_4B2004623623__INCLUDED_)
#define AFX_ATTENDANCESET_H__CD3C6C2C_D9AF_420D_B3B3_4B2004623623__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AttendanceSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAttendanceSet recordset

class CAttendanceSet : public CRecordset
{
public:
	CAttendanceSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAttendanceSet)

// Field/Param Data
	//{{AFX_FIELD(CAttendanceSet, CRecordset)
	long	m_ID;
	CString	m_PERSON;
	CString	m_IN_OUT;
	CTime	m_IO_TIME;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttendanceSet)
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

#endif // !defined(AFX_ATTENDANCESET_H__CD3C6C2C_D9AF_420D_B3B3_4B2004623623__INCLUDED_)
