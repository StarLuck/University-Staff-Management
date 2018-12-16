// EducationSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "EducationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEducationSet

IMPLEMENT_DYNAMIC(CEducationSet, CRecordset)

CEducationSet::CEducationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CEducationSet)
	m_ID = 0;
	m_education = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CEducationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CEducationSet::GetDefaultSQL()
{
	return _T("[education]");
}

void CEducationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CEducationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[education]"), m_education);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CEducationSet diagnostics

#ifdef _DEBUG
void CEducationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEducationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
