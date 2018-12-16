// DutySet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "DutySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDutySet

IMPLEMENT_DYNAMIC(CDutySet, CRecordset)

CDutySet::CDutySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDutySet)
	m_ID = 0;
	m_duty = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDutySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CDutySet::GetDefaultSQL()
{
	return _T("[duty]");
}

void CDutySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDutySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDutySet diagnostics

#ifdef _DEBUG
void CDutySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDutySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
