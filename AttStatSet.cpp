// AttStatSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttStatSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttStatSet

IMPLEMENT_DYNAMIC(CAttStatSet, CRecordset)

CAttStatSet::CAttStatSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAttStatSet)
	m_ID = 0;
	m_YEAR_MONTH = _T("");
	m_PERSON = _T("");
	m_WORK_HOUR = 0;
	m_OVER_HOUR = 0;
	m_LEAVE_HDAY = 0;
	m_ERRAND_HDAY = 0;
	m_LATE_TIMES = 0;
	m_EARLY_TIMES = 0;
	m_ABSENT_TIMES = 0;
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAttStatSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CAttStatSet::GetDefaultSQL()
{
	return _T("[attendance_stat]");
}

void CAttStatSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAttStatSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[YEAR_MONTH]"), m_YEAR_MONTH);
	RFX_Text(pFX, _T("[PERSON]"), m_PERSON);
	RFX_Int(pFX, _T("[WORK_HOUR]"), m_WORK_HOUR);
	RFX_Long(pFX, _T("[OVER_HOUR]"), m_OVER_HOUR);
	RFX_Int(pFX, _T("[LEAVE_HDAY]"), m_LEAVE_HDAY);
	RFX_Int(pFX, _T("[ERRAND_HDAY]"), m_ERRAND_HDAY);
	RFX_Byte(pFX, _T("[LATE_TIMES]"), m_LATE_TIMES);
	RFX_Byte(pFX, _T("[EARLY_TIMES]"), m_EARLY_TIMES);
	RFX_Byte(pFX, _T("[ABSENT_TIMES]"), m_ABSENT_TIMES);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAttStatSet diagnostics

#ifdef _DEBUG
void CAttStatSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAttStatSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
