// UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "UserDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog


CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserDlg)
	m_bIsAdmin = FALSE;
	m_strUser = _T("");
	m_strPass = _T("");
	m_strRePass = _T("");
	//}}AFX_DATA_INIT
}


void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserDlg)
	DDX_Control(pDX, IDOK, m_bntOK);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_bntCancel);
	DDX_Control(pDX, IDC_EDIT2, m_ctrPass);
	DDX_Control(pDX, IDC_EDIT1, m_ctrUser);
	DDX_Control(pDX, IDC_LIST_USERNAME, m_ctrList);
	DDX_Check(pDX, IDC_CHECK1, m_bIsAdmin);
	DDX_Text(pDX, IDC_EDIT1, m_strUser);
	DDX_Text(pDX, IDC_EDIT2, m_strPass);
	DDX_Text(pDX, IDC_EDIT3, m_strRePass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	//{{AFX_MSG_MAP(CUserDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST_USERNAME, OnClickListUsername)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserDlg message handlers

BOOL CUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//创建用户列表
	m_ctrList.InsertColumn(0,"用户名");
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrList.SetColumnWidth(0,120);
	//在添加用户列表中添加用户名
	RefreshData();

	return TRUE;  
}
void CUserDlg::RefreshData() 
{

	m_ctrList.SetFocus();
	//清空用户列表
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);
	
	CString strSQL;
	UpdateData(TRUE);
	//打开记录集
	strSQL="select * from password";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	//添加用户名到用户列表中
	int i=0;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i++,m_recordset.m_user);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);

}
void CUserDlg::OnClickListUsername(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString strSQL;
	UpdateData(TRUE);
	//从数据库中获取选择用户名的资料
	int i = m_ctrList.GetSelectionMark();
	m_strUser = m_ctrList.GetItemText(i,0);
	strSQL.Format("select * from password where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	//显示用户资料
	m_strPass = m_recordset.m_passwd;
	m_strRePass = m_strPass;
	m_bIsAdmin = m_recordset.m_isadmin;
	m_recordset.Close();	
	UpdateData(FALSE);
	*pResult = 0;
}

void CUserDlg::OnButtonNew() 
{
	//清空用户资料
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	//设置用户名编辑框为可用
	m_ctrUser.EnableWindow(TRUE);
	m_ctrUser.SetFocus();
	//更新数据到界面
	UpdateData(FALSE);
}

void CUserDlg::OnButtonDelete() 
{

	UpdateData(TRUE);
	//判断是否指定用户
	if(m_strUser=="")
	{
		MessageBox("请选择一个用户！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from password where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该用户
	m_recordset.Delete();
	m_recordset.Close();

	//刷新用户列表
	RefreshData();

	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	UpdateData(FALSE);
}

void CUserDlg::OnOK() 
{
	UpdateData();
	if(m_ctrUser.IsWindowEnabled())
	{//增加新用户的输入检查
		if(m_strUser=="")
		{
			MessageBox("请填写用户名！");
			m_ctrUser.SetFocus();
			return;
		}
	}
	else
	{//修改用户信息的输入检查
		if(m_strUser=="")
		{
			MessageBox("请选择一个用户！");
			return;
		}
	}
	//限制密码不能为空
	if(m_strPass=="")
	{ 
		MessageBox("密码不能为空，请输入密码！");
		m_ctrPass.SetFocus();
		return;
	}
	//验证密码与确认密码是否一致
	if(m_strPass!=m_strRePass)
	{ 
		MessageBox("两次输入地密码不一致，请重新输入密码！");
		m_ctrPass.SetFocus();
		m_strPass = "";
		m_strRePass = "";
		UpdateData(FALSE);
		return;
	}
	//打开记录集
	CString strSQL;
	strSQL.Format("select * from password where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	if(m_ctrUser.IsWindowEnabled())
	{//增加新用户
		//判断用户是否已经存在
		if(m_recordset.GetRecordCount()!=0)
		{
			m_recordset.Close();
			MessageBox("该用户已经存在！");
			return;
		}
		m_recordset.AddNew();
		m_recordset.m_user = m_strUser;
		m_recordset.m_passwd = m_strPass;
		m_recordset.m_isadmin = m_bIsAdmin;
		m_recordset.Update();
		MessageBox("用户添加成功！请记住用户名和密码！");
		m_recordset.Close();
	}
	else
	{//修改用户信息
		//判断用户是否不存在
		if(m_recordset.GetRecordCount()==0)
		{ 
			m_recordset.Close();
			MessageBox("该用户不存在！请更新数据库");
			return;
		}
		m_recordset.Edit();
		m_recordset.m_user = m_strUser;
		m_recordset.m_passwd = m_strPass;
		m_recordset.m_isadmin = m_bIsAdmin;
		m_recordset.Update();
		MessageBox("用户修改成功！请记住用户名和密码！");
		m_recordset.Close();
	}
	m_ctrUser.EnableWindow(FALSE);
	//更新用户列表	
	RefreshData();

}

void CUserDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	m_ctrUser.EnableWindow(FALSE);
	UpdateData(FALSE);	
}
