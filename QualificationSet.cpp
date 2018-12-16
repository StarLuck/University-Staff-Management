// QualificationSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "QualificationSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQualificationSet

IMPLEMENT_DYNAMIC(CQualificationSet, CRecordset)

CQualificationSet::CQualificationSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CQualificationSet)
	m_ID = 0;
	m_code = _T("");
	m_tech = _T("");
	m_mode = _T("");
	m_duty = _T("");
	m_dept = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CQualificationSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CQualificationSet::GetDefaultSQL()
{
	return _T("[assess]");
}

void CQualificationSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CQualificationSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[tech]"), m_tech);
	RFX_Text(pFX, _T("[mode]"), m_mode);
	RFX_Date(pFX, _T("[date0]"), m_date0);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	RFX_Date(pFX, _T("[date1]"), m_date1);
	RFX_Date(pFX, _T("[date2]"), m_date2);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CQualificationSet diagnostics

#ifdef _DEBUG
void CQualificationSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CQualificationSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
