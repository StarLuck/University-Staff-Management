// AttendanceSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttendanceSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAttendanceSet

IMPLEMENT_DYNAMIC(CAttendanceSet, CRecordset)

CAttendanceSet::CAttendanceSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAttendanceSet)
	m_ID = 0;
	m_PERSON = _T("");
	m_IN_OUT = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAttendanceSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CAttendanceSet::GetDefaultSQL()
{
	return _T("[attendance]");
}

void CAttendanceSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAttendanceSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[PERSON]"), m_PERSON);
	RFX_Text(pFX, _T("[IN_OUT]"), m_IN_OUT);
	RFX_Date(pFX, _T("[IO_TIME]"), m_IO_TIME);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAttendanceSet diagnostics

#ifdef _DEBUG
void CAttendanceSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAttendanceSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
