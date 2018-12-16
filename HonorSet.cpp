// HonorSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "HonorSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHonorSet

IMPLEMENT_DYNAMIC(CHonorSet, CRecordset)

CHonorSet::CHonorSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CHonorSet)
	m_ID = 0;
	m_code = _T("");
	m_sorts = _T("");
	m_reason1 = _T("");
	m_dept = _T("");
	m_reason2 = _T("");
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CHonorSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CHonorSet::GetDefaultSQL()
{
	return _T("[honor]");
}

void CHonorSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CHonorSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[sorts]"), m_sorts);
	RFX_Date(pFX, _T("[date1]"), m_date1);
	RFX_Text(pFX, _T("[reason1]"), m_reason1);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	RFX_Date(pFX, _T("[date2]"), m_date2);
	RFX_Text(pFX, _T("[reason2]"), m_reason2);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CHonorSet diagnostics

#ifdef _DEBUG
void CHonorSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CHonorSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
