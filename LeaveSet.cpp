// LeaveSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "LeaveSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeaveSet

IMPLEMENT_DYNAMIC(CLeaveSet, CRecordset)

CLeaveSet::CLeaveSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLeaveSet)
	m_ID = 0;
	m_PERSON = _T("");
	m_REASON = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CLeaveSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CLeaveSet::GetDefaultSQL()
{
	return _T("[leave]");
}

void CLeaveSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLeaveSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[PERSON]"), m_PERSON);
	RFX_Date(pFX, _T("[START_TIME]"), m_START_TIME);
	RFX_Date(pFX, _T("[END_TIME]"), m_END_TIME);
	RFX_Text(pFX, _T("[REASON]"), m_REASON);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLeaveSet diagnostics

#ifdef _DEBUG
void CLeaveSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLeaveSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
