#if !defined(AFX_PERSONSET_H__9EBD8EBD_547D_4236_8FD5_7CFC2472FFE2__INCLUDED_)
#define AFX_PERSONSET_H__9EBD8EBD_547D_4236_8FD5_7CFC2472FFE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonSet recordset

class CPersonSet : public CRecordset
{
public:
	CPersonSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPersonSet)

// Field/Param Data
	//{{AFX_FIELD(CPersonSet, CRecordset)
	CString	m_ID;
	CString	m_name;
	CString	m_sex;
	CTime	m_birth;
	int		m_age;
	CString	m_folk;
	CString	m_ismarry;
	CString	m_cardID;
	CString	m_phone;
	CString	m_email;
	CString	m_mphone;
	CString	m_native;
	CString	m_addr;
	CString	m_school;
	CString	m_subject;
	CTime	m_gdate;
	CString	m_dept;
	CString	m_dept_1;
	CString	m_dept_2;
	CString	m_group;
	CString	m_isworker;
	CString	m_aboutpay;
	CTime	m_date1;
	CTime	m_date2;
	CString	m_education;
	int		m_workage;
	int		m_hereworkage;
	CString	m_political;
	CString	m_technical;
	CString	m_duty;
	CString	m_comments;
	CLongBinary	m_picture;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonSet)
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

#endif // !defined(AFX_PERSONSET_H__9EBD8EBD_547D_4236_8FD5_7CFC2472FFE2__INCLUDED_)
