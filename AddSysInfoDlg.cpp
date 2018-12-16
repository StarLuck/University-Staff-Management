// AddSysInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AddSysInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddSysInfoDlg dialog


CAddSysInfoDlg::CAddSysInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddSysInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddSysInfoDlg)
	m_strData = _T("");
	m_strLabel = _T("");
	//}}AFX_DATA_INIT
}


void CAddSysInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSysInfoDlg)
	DDX_Control(pDX, IDC_EDIT_DATA, m_ctrData);
	DDX_Text(pDX, IDC_EDIT_DATA, m_strData);
	DDX_Text(pDX, IDC_STATIC_DATA, m_strLabel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddSysInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CAddSysInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddSysInfoDlg message handlers

void CAddSysInfoDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_strData=="")
	{
		MessageBox("请输入设置信息！");
		m_ctrData.SetFocus();
		return;
	}
	CDialog::OnOK();
}
