// DeptSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "DeptSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptSet

IMPLEMENT_DYNAMIC(CDeptSet, CRecordset)

CDeptSet::CDeptSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDeptSet)
	m_ID = 0;
	m_dept = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CDeptSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CDeptSet::GetDefaultSQL()
{
	return _T("[dept]");
}

void CDeptSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDeptSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CDeptSet diagnostics

#ifdef _DEBUG
void CDeptSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDeptSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
