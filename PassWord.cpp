// PassWord.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "PassWord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassWord

IMPLEMENT_DYNAMIC(CPassWord, CRecordset)

CPassWord::CPassWord(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPassWord)
	m_user = _T("");
	m_passwd = _T("");
	m_isadmin = FALSE;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPassWord::GetDefaultConnect()
{
	return _T("ODBC;DSN=Manager");
}

CString CPassWord::GetDefaultSQL()
{
	return _T("[password]");
}

void CPassWord::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPassWord)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[user]"), m_user);
	RFX_Text(pFX, _T("[passwd]"), m_passwd);
	RFX_Bool(pFX, _T("[isadmin]"), m_isadmin);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPassWord diagnostics

#ifdef _DEBUG
void CPassWord::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPassWord::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
