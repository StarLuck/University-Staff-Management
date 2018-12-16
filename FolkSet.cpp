// FolkSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "FolkSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFolkSet

IMPLEMENT_DYNAMIC(CFolkSet, CRecordset)

CFolkSet::CFolkSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CFolkSet)
	m_ID = 0;
	m_folk = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CFolkSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CFolkSet::GetDefaultSQL()
{
	return _T("[folk]");
}

void CFolkSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CFolkSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[folk]"), m_folk);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CFolkSet diagnostics

#ifdef _DEBUG
void CFolkSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFolkSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
