// AddrbookSet.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AddrbookSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddrbookSet

IMPLEMENT_DYNAMIC(CAddrbookSet, CRecordset)

CAddrbookSet::CAddrbookSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAddrbookSet)
	m_ID = 0;
	m_name = _T("");
	m_sex = _T("");
	m_phone1 = _T("");
	m_phone2 = _T("");
	m_call = _T("");
	m_mphone = _T("");
	m_oicq = _T("");
	m_email = _T("");
	m_comments = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAddrbookSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CAddrbookSet::GetDefaultSQL()
{
	return _T("[addrbook]");
}

void CAddrbookSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAddrbookSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[sex]"), m_sex);
	RFX_Text(pFX, _T("[phone1]"), m_phone1);
	RFX_Text(pFX, _T("[phone2]"), m_phone2);
	RFX_Text(pFX, _T("[call]"), m_call);
	RFX_Text(pFX, _T("[mphone]"), m_mphone);
	RFX_Text(pFX, _T("[oicq]"), m_oicq);
	RFX_Text(pFX, _T("[email]"), m_email);
	RFX_Text(pFX, _T("[comments]"), m_comments);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAddrbookSet diagnostics

#ifdef _DEBUG
void CAddrbookSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAddrbookSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
