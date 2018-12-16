// TechnicalSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "TechnicalSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTechnicalSet

IMPLEMENT_DYNAMIC(CTechnicalSet, CRecordset)

CTechnicalSet::CTechnicalSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTechnicalSet)
	m_ID = 0;
	m_technical = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTechnicalSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CTechnicalSet::GetDefaultSQL()
{
	return _T("[technical]");
}

void CTechnicalSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTechnicalSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[technical]"), m_technical);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTechnicalSet diagnostics

#ifdef _DEBUG
void CTechnicalSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTechnicalSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
