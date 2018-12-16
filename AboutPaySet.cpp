// AboutPaySet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AboutPaySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutPaySet

IMPLEMENT_DYNAMIC(CAboutPaySet, CRecordset)

CAboutPaySet::CAboutPaySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAboutPaySet)
	m_ID = 0;
	m_aboutpay = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAboutPaySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CAboutPaySet::GetDefaultSQL()
{
	return _T("[aboutpay]");
}

void CAboutPaySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAboutPaySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[aboutpay]"), m_aboutpay);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAboutPaySet diagnostics

#ifdef _DEBUG
void CAboutPaySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAboutPaySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
