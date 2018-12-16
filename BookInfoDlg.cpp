// BookInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "BookInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookInfoDlg dialog


CBookInfoDlg::CBookInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookInfoDlg)
	m_strSex = _T("");
	m_strCall = _T("");
	m_strComments = _T("");
	m_strEmail = _T("");
	m_strMphone = _T("");
	m_strName = _T("");
	m_strPhone1 = _T("");
	m_strPhone2 = _T("");
	m_strQQ = _T("");
	//}}AFX_DATA_INIT
}


void CBookInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookInfoDlg)
	DDX_CBString(pDX, IDC_COMBO1, m_strSex);
	DDX_Text(pDX, IDC_EDIT_CALL, m_strCall);
	DDX_Text(pDX, IDC_EDIT_COMMENTS, m_strComments);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_EDIT_MPHONE, m_strMphone);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PHONE1, m_strPhone1);
	DDX_Text(pDX, IDC_EDIT_PHONE2, m_strPhone2);
	DDX_Text(pDX, IDC_EDIT_QQ, m_strQQ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CBookInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookInfoDlg message handlers

void CBookInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_strName=="")
	{
		MessageBox("请输入联系人姓名！");
		return;
	}
	CDialog::OnOK();
}
