// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "LoginDlg.h"
#include "password.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_strUser = _T("");
	m_strPass = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_EDIT1, m_ctrPass);
	DDX_Control(pDX, IDC_COMBO1, m_ctrUser);
	DDX_CBString(pDX, IDC_COMBO1, m_strUser);
	DDX_Text(pDX, IDC_EDIT1, m_strPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	CPassWord recordset;
	CString strSQL;
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	UpdateData(TRUE);
	//检查用户名是否输入
	if(m_strUser.IsEmpty())
	{
		AfxMessageBox("请输入用户名！");
		m_ctrUser.SetFocus();
		return;
	}
	if(m_strPass.IsEmpty())
	{
		AfxMessageBox("请输入密码！");
		m_ctrPass.SetFocus();
		return;
	}
	//从用户表中检查用户名密码是否正确
	strSQL.Format("select * from password where user='%s' AND passwd='%s'",m_strUser,m_strPass);
	if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	if(recordset.GetRecordCount()==0)
	{
		//密码错误处理
		recordset.Close();
		MessageBox("密码错误，请重新输入！");
		m_strPass="";
		m_ctrPass.SetFocus();
		UpdateData(FALSE);
	}
	else
	{
		//分配用户权限
		ptheApp->m_bIsAdmin = recordset.m_isadmin;
		recordset.Close();
		CDialog::OnOK();
	}
}

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CPassWord recordset ;
	CString strSQL;
	UpdateData(TRUE);
	//strSQL.Format("select * from password where user='%s' AND passwd='%s'",m_strUser,m_strPass);
	strSQL="select * from password";
	if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return FALSE;
	}	

	while(!recordset.IsEOF())
	{
		m_ctrUser.AddString(recordset.m_user);
		recordset.MoveNext();
	}
	recordset.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
