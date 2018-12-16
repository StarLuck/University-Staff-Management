// TrainSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "TrainSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrainSet

IMPLEMENT_DYNAMIC(CTrainSet, CRecordset)

CTrainSet::CTrainSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CTrainSet)
	m_ID = 0;
	m_code = _T("");
	m_mode = _T("");
	m_term = _T("");
	m_subject = _T("");
	m_dept = _T("");
	m_content = _T("");
	m_outlay = _T("");
	m_result = _T("");
	m_nFields = 11;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CTrainSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CTrainSet::GetDefaultSQL()
{
	return _T("[train]");
}

void CTrainSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CTrainSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[code]"), m_code);
	RFX_Text(pFX, _T("[mode]"), m_mode);
	RFX_Date(pFX, _T("[date1]"), m_date1);
	RFX_Date(pFX, _T("[date2]"), m_date2);
	RFX_Text(pFX, _T("[term]"), m_term);
	RFX_Text(pFX, _T("[subject]"), m_subject);
	RFX_Text(pFX, _T("[dept]"), m_dept);
	RFX_Text(pFX, _T("[content]"), m_content);
	RFX_Text(pFX, _T("[outlay]"), m_outlay);
	RFX_Text(pFX, _T("[result]"), m_result);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CTrainSet diagnostics

#ifdef _DEBUG
void CTrainSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTrainSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
