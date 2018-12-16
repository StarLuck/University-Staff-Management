// AddrBookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AddrBookDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddrBookDlg dialog


CAddrBookDlg::CAddrBookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddrBookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddrBookDlg)
	m_nCondition = -1;
	m_strContent = _T("");
	//}}AFX_DATA_INIT
}


void CAddrBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddrBookDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_CBIndex(pDX, IDC_COMBO_CONDITION, m_nCondition);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddrBookDlg, CDialog)
	//{{AFX_MSG_MAP(CAddrBookDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_ALL, OnButtonAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddrBookDlg message handlers

BOOL CAddrBookDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.SetColumnWidth(0,40);
	
	m_ctrList.InsertColumn(1,"姓名");
	m_ctrList.SetColumnWidth(1,60);
	
	m_ctrList.InsertColumn(2,"性别");
	m_ctrList.SetColumnWidth(2,40);
	
	m_ctrList.InsertColumn(3,"家庭电话");
	m_ctrList.SetColumnWidth(3,80);

	m_ctrList.InsertColumn(4,"办公电话");
	m_ctrList.SetColumnWidth(4,80);

	m_ctrList.InsertColumn(5,"呼机");
	m_ctrList.SetColumnWidth(5,80);

	m_ctrList.InsertColumn(6,"手机");
	m_ctrList.SetColumnWidth(6,80);

	m_ctrList.InsertColumn(7,"QQ");
	m_ctrList.SetColumnWidth(7,80);

	m_ctrList.InsertColumn(8,"电子邮件");
	m_ctrList.SetColumnWidth(8,120);

	m_ctrList.InsertColumn(9,"备注");
	m_ctrList.SetColumnWidth(9,100);


	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	CString strSQL;
	strSQL="select * from addrbook";
	RefreshData(strSQL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddrBookDlg::RefreshData(CString strSQL)
{
	m_ctrList.SetFocus();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	UpdateData(TRUE);

	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	char buffer[20];
	int i=0;
	while(!m_recordset.IsEOF())
	{
		ltoa(m_recordset.m_ID,buffer,10);
		m_ctrList.InsertItem(i,buffer);
		m_ctrList.SetItemText(i,1,m_recordset.m_name);
		m_ctrList.SetItemText(i,2,m_recordset.m_sex);
		m_ctrList.SetItemText(i,3,m_recordset.m_phone1);
		m_ctrList.SetItemText(i,4,m_recordset.m_phone2);
		m_ctrList.SetItemText(i,5,m_recordset.m_call);
		m_ctrList.SetItemText(i,6,m_recordset.m_mphone);
		m_ctrList.SetItemText(i,7,m_recordset.m_oicq);
		m_ctrList.SetItemText(i,8,m_recordset.m_email);
		m_ctrList.SetItemText(i,9,m_recordset.m_comments);

		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);	
}

void CAddrBookDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	if(IDOK!=m_BookInfoDlg.DoModal())
		return;
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}

	m_recordset.AddNew();

	m_recordset.m_name		= m_BookInfoDlg.m_strName;	
	m_recordset.m_sex		= m_BookInfoDlg.m_strSex;	
	m_recordset.m_phone1	= m_BookInfoDlg.m_strPhone1;	
	m_recordset.m_phone2	= m_BookInfoDlg.m_strPhone2;
	m_recordset.m_call		= m_BookInfoDlg.m_strCall;
	m_recordset.m_mphone	= m_BookInfoDlg.m_strMphone;
	m_recordset.m_oicq		= m_BookInfoDlg.m_strQQ;
	m_recordset.m_email		= m_BookInfoDlg.m_strEmail;
	m_recordset.m_comments	= m_BookInfoDlg.m_strComments;

	m_recordset.Update();

	m_recordset.Close();

	RefreshData("select * from addrbook");	
}

void CAddrBookDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from addrbook where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该用户
	m_recordset.Delete();
	m_recordset.Close();

	//更新用户列表
	strSQL="select * from addrbook";
	RefreshData(strSQL);	
}

void CAddrBookDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}

	m_BookInfoDlg.m_strName		=	m_ctrList.GetItemText(i,1)	;
	m_BookInfoDlg.m_strSex		=	m_ctrList.GetItemText(i,2)	;
	m_BookInfoDlg.m_strPhone1	=	m_ctrList.GetItemText(i,3)	;
	m_BookInfoDlg.m_strPhone2	=	m_ctrList.GetItemText(i,4)	;
	m_BookInfoDlg.m_strCall		=	m_ctrList.GetItemText(i,5)	;
	m_BookInfoDlg.m_strMphone	=	m_ctrList.GetItemText(i,6)	;
	m_BookInfoDlg.m_strQQ		=	m_ctrList.GetItemText(i,7)	;
	m_BookInfoDlg.m_strEmail	=	m_ctrList.GetItemText(i,8)	;
	m_BookInfoDlg.m_strComments	=	m_ctrList.GetItemText(i,9)	;

	if(IDOK!=m_BookInfoDlg.DoModal())
		return;
	CString strSQL;
	strSQL.Format("select * from addrbook where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	
	m_recordset.Edit();

	m_recordset.m_name		= m_BookInfoDlg.m_strName		;	
	m_recordset.m_sex		= m_BookInfoDlg.m_strSex		;	
	m_recordset.m_phone1	= m_BookInfoDlg.m_strPhone1		;	
	m_recordset.m_phone2	= m_BookInfoDlg.m_strPhone2		;
	m_recordset.m_call		= m_BookInfoDlg.m_strCall		;
	m_recordset.m_mphone	= m_BookInfoDlg.m_strMphone		;
	m_recordset.m_oicq		= m_BookInfoDlg.m_strQQ			;
	m_recordset.m_email		= m_BookInfoDlg.m_strEmail		;
	m_recordset.m_comments	= m_BookInfoDlg.m_strComments	;

	m_recordset.Update();

	m_recordset.Close();

	strSQL="select * from addrbook";
	RefreshData(strSQL);
}

void CAddrBookDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSQL;
	if(0==m_nCondition)
		strSQL.Format("select * from addrbook where name='%s'",m_strContent);	
	else
		strSQL.Format("select * from addrbook where sex='%s'",m_strContent);	
	//显示全部信息
	if(m_strContent=="")
		strSQL = "select * from addrbook";
	RefreshData(strSQL);	
}

void CAddrBookDlg::OnButtonAll() 
{
	CString strSQL;
	strSQL = "select * from addrbook";
	RefreshData(strSQL);		
}
