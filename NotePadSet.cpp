// NotePadSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "NotePadSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotePadSet

IMPLEMENT_DYNAMIC(CNotePadSet, CRecordset)

CNotePadSet::CNotePadSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CNotePadSet)
	m_ID = 0;
	m_sort = _T("");
	m_caption = _T("");
	m_comments = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CNotePadSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CNotePadSet::GetDefaultSQL()
{
	return _T("[notepad]");
}

void CNotePadSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CNotePadSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Date(pFX, _T("[date]"), m_date);
	RFX_Text(pFX, _T("[sort]"), m_sort);
	RFX_Text(pFX, _T("[caption]"), m_caption);
	RFX_Text(pFX, _T("[comments]"), m_comments);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CNotePadSet diagnostics

#ifdef _DEBUG
void CNotePadSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CNotePadSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
