// FamilySet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "FamilySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFamilySet

IMPLEMENT_DYNAMIC(CFamilySet, CRecordset)

CFamilySet::CFamilySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFamilySet)
	m_ID = 0;
	m_code = _T("");
	m_name = _T("");
	m_relation = _T("");
	m_dept = _T("");
	m_duty = _T("");
	m_political = _T("");
	m_phone = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CFamilySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CFamilySet::GetDefaultSQL()
{
	return _T("[family]");
}

void CFamilySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFamilySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[relation]"), m_relation);
	RFX_Date(pFX, _T("[date]"), m_date);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	RFX_Text(pFX, _T("[political]"), m_political);
	RFX_Text(pFX, _T("[phone]"), m_phone);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFamilySet diagnostics

#ifdef _DEBUG
void CFamilySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFamilySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
