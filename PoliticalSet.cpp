// PoliticalSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "PoliticalSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPoliticalSet

IMPLEMENT_DYNAMIC(CPoliticalSet, CRecordset)

CPoliticalSet::CPoliticalSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPoliticalSet)
	m_ID = 0;
	m_political = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPoliticalSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CPoliticalSet::GetDefaultSQL()
{
	return _T("[political]");
}

void CPoliticalSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPoliticalSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[political]"), m_political);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPoliticalSet diagnostics

#ifdef _DEBUG
void CPoliticalSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPoliticalSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
