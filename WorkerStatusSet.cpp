// WorkerStatusSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "WorkerStatusSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkerStatusSet

IMPLEMENT_DYNAMIC(CWorkerStatusSet, CRecordset)

CWorkerStatusSet::CWorkerStatusSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWorkerStatusSet)
	m_ID = 0;
	m_workstatus = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CWorkerStatusSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CWorkerStatusSet::GetDefaultSQL()
{
	return _T("[status]");
}

void CWorkerStatusSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWorkerStatusSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[workstatus]"), m_workstatus);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWorkerStatusSet diagnostics

#ifdef _DEBUG
void CWorkerStatusSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CWorkerStatusSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
