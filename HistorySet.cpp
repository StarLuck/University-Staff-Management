// HistorySet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "HistorySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistorySet

IMPLEMENT_DYNAMIC(CHistorySet, CRecordset)

CHistorySet::CHistorySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CHistorySet)
	m_ID = 0;
	m_code = _T("");
	m_company = _T("");
	m_duty = _T("");
	m_dept = _T("");
	m_level1 = _T("");
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CHistorySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CHistorySet::GetDefaultSQL()
{
	return _T("[history]");
}

void CHistorySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CHistorySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Date(pFX, _T("[date1]"), m_date1);
	RFX_Date(pFX, _T("[date2]"), m_date2);
	RFX_Text(pFX, _T("[company]"), m_company);
	RFX_Text(pFX, _T("[duty]"), m_duty);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	RFX_Text(pFX, _T("[level1]"), m_level1);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CHistorySet diagnostics

#ifdef _DEBUG
void CHistorySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CHistorySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
