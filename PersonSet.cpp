// PersonSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "PersonSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonSet

IMPLEMENT_DYNAMIC(CPersonSet, CRecordset)

CPersonSet::CPersonSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPersonSet)
	m_ID = _T("");
	m_name = _T("");
	m_sex = _T("");
	m_age = 0;
	m_folk = _T("");
	m_ismarry = _T("");
	m_cardID = _T("");
	m_phone = _T("");
	m_email = _T("");
	m_mphone = _T("");
	m_native = _T("");
	m_addr = _T("");
	m_school = _T("");
	m_subject = _T("");
	m_dept = _T("");
	m_dept_1 = _T("");
	m_dept_2 = _T("");
	m_group = _T("");
	m_isworker = _T("");
	m_aboutpay = _T("");
	m_education = _T("");
	m_workage = 0;
	m_hereworkage = 0;
	m_political = _T("");
	m_technical = _T("");
	m_duty = _T("");
	m_comments = _T("");
	m_nFields = 32;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPersonSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CPersonSet::GetDefaultSQL()
{
	return _T("[person]");
}

void CPersonSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPersonSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Date(pFX, _T("[birth]"), m_birth);
	RFX_Int(pFX, _T("[age]"), m_age);
	RFX_Text(pFX, _T("[folk]"), m_folk);
	RFX_Text(pFX, _T("[ismarry]"), m_ismarry);
	RFX_Text(pFX, _T("[cardID]"), m_cardID);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	RFX_Text(pFX, _T("[email]"), m_email);
	RFX_Text(pFX, _T("[mphone]"), m_mphone);
	RFX_Text(pFX, _T("[native]"), m_native);
	RFX_Text(pFX, _T("[addr]"), m_addr);
	RFX_Text(pFX, _T("[school]"), m_school);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Date(pFX, _T("[gdate]"), m_gdate);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	RFX_Text(pFX, _T("[dept_1]"), m_dept_1);
	RFX_Text(pFX, _T("[dept_2]"), m_dept_2);
	RFX_Text(pFX, _T("[group]"), m_group);
	RFX_Text(pFX, _T("[isworker]"), m_isworker);
	RFX_Text(pFX, _T("[aboutpay]"), m_aboutpay);
	RFX_Date(pFX, _T("[date1]"), m_date1);
	RFX_Date(pFX, _T("[date2]"), m_date2);
	RFX_Text(pFX, _T("[education]"), m_education);
	RFX_Int(pFX, _T("[workage]"), m_workage);
	RFX_Int(pFX, _T("[hereworkage]"), m_hereworkage);
	RFX_Text(pFX, _T("[political]"), m_political);
	RFX_Text(pFX, _T("[technical]"), m_technical);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	RFX_Text(pFX, _T("[comments]"), m_comments);
	RFX_LongBinary(pFX, _T("[picture]"), m_picture);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPersonSet diagnostics

#ifdef _DEBUG
void CPersonSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPersonSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
