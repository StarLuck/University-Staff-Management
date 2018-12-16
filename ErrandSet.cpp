// ErrandSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "ErrandSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CErrandSet

IMPLEMENT_DYNAMIC(CErrandSet, CRecordset)

CErrandSet::CErrandSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CErrandSet)
	m_ID = 0;
	m_PERSON = _T("");
	m_DESCRIPTION = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CErrandSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CErrandSet::GetDefaultSQL()
{
	return _T("[errand]");
}

void CErrandSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CErrandSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[PERSON]"), m_PERSON);
	RFX_Date(pFX, _T("[START_TIME]"), m_START_TIME);
	RFX_Date(pFX, _T("[END_TIME]"), m_END_TIME);
	RFX_Text(pFX, _T("[DESCRIPTION]"), m_DESCRIPTION);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CErrandSet diagnostics

#ifdef _DEBUG
void CErrandSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CErrandSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
