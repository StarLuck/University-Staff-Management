// OvertimeSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "OvertimeSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COvertimeSet

IMPLEMENT_DYNAMIC(COvertimeSet, CRecordset)

COvertimeSet::COvertimeSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COvertimeSet)
	m_ID = 0;
	m_PERSON = _T("");
	m_WORK_HOURS = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString COvertimeSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString COvertimeSet::GetDefaultSQL()
{
	return _T("[overtime]");
}

void COvertimeSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COvertimeSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[PERSON]"), m_PERSON);
	RFX_Byte(pFX, _T("[WORK_HOURS]"), m_WORK_HOURS);
	RFX_Date(pFX, _T("[WORK_DATE]"), m_WORK_DATE);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// COvertimeSet diagnostics

#ifdef _DEBUG
void COvertimeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COvertimeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
