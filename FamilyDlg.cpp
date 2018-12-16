// FamilyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "FamilyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFamilyDlg dialog


CFamilyDlg::CFamilyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFamilyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFamilyDlg)
	m_tmDate = 0;
	m_strDuty = _T("");
	m_strName = _T("");
	m_strPhone = _T("");
	m_strPolitical = _T("");
	m_strRelation = _T("");
	m_strDept = _T("");
	//}}AFX_DATA_INIT
	m_strID = "";
}


void CFamilyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFamilyDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_BUTTON_SAVE1, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_bntModify);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTH, m_tmDate);
	DDX_Text(pDX, IDC_EDIT_DUTY, m_strDuty);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	DDX_Text(pDX, IDC_EDIT_POLITICAL, m_strPolitical);
	DDX_Text(pDX, IDC_EDIT_RELATION, m_strRelation);
	DDX_Text(pDX, IDC_EDIT_UNIT, m_strDept);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFamilyDlg, CDialog)
	//{{AFX_MSG_MAP(CFamilyDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE1, OnButtonSave1)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFamilyDlg message handlers

BOOL CFamilyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"成员姓名");
	m_ctrList.InsertColumn(2,"与本人关系");
	m_ctrList.InsertColumn(3,"出生日期");
	m_ctrList.InsertColumn(4,"工作单位");
	m_ctrList.InsertColumn(5,"担任职务");
	m_ctrList.InsertColumn(6,"政治面貌");
	m_ctrList.InsertColumn(7,"联系电话");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,80);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//设置按钮状态
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);

//	RefreshData();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CFamilyDlg::RefreshData(CString strID)
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	UpdateData(TRUE);
	CString strSQL;
	m_strID.Format("%s",strID);
	strSQL.Format( "select * from family where code = '%s'",strID);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	
	int i=0;
	CString strTime;
	char buffer[20];
	while(!m_recordset.IsEOF())
	{
		_ltoa(m_recordset.m_ID,buffer,10);
		m_ctrList.InsertItem(i,buffer);
		m_ctrList.SetItemText(i,1,m_recordset.m_name);
		m_ctrList.SetItemText(i,2,m_recordset.m_relation);
		strTime.Format("%d-%d-%d",m_recordset.m_date.GetYear(),m_recordset.m_date.GetMonth(),m_recordset.m_date.GetDay());
		m_ctrList.SetItemText(i,3,strTime);
		m_ctrList.SetItemText(i,4,m_recordset.m_dept);
		m_ctrList.SetItemText(i,5,m_recordset.m_duty);
		m_ctrList.SetItemText(i,6,m_recordset.m_political);
		m_ctrList.SetItemText(i,7,m_recordset.m_phone);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);
	//设置按钮状态
	m_bntSave.EnableWindow(FALSE);
	if(m_strID=="")
		m_bntNew.EnableWindow(FALSE);
	else
		m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
}
void CFamilyDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	strSQL.Format("select * from family where ID=%s",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	m_strName		= m_recordset.m_name;
	m_strRelation	= m_recordset.m_relation;
	m_tmDate		= m_recordset.m_date;
	m_strDept		= m_recordset.m_dept;
	m_strDuty		= m_recordset.m_duty;
	m_strPolitical	= m_recordset.m_political;
	m_strPhone		= m_recordset.m_phone;
	
	m_recordset.Close();	

	UpdateData(FALSE);	
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow();
	m_bntModify.EnableWindow();

	*pResult = 0;
}

void CFamilyDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_strName		=	"";
	m_strRelation	=	"";
	m_strDept		=	"";
	m_strDuty		=	"";
	m_strPolitical	=	"";
	m_strPhone		=	"";
	m_tmDate		= CTime::GetCurrentTime();
	m_bntSave.EnableWindow();
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	UpdateData(FALSE);	
}

void CFamilyDlg::OnButtonSave1() 
{
	UpdateData();


	if(m_strName=="")
	{
		MessageBox("请输入姓名！");
		return;
	}
	if(m_strRelation=="")
	{
		MessageBox("请输入与本人关系！");
		return;
	}
	
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.AddNew();
	m_recordset.m_name		=	m_strName		;	
	m_recordset.m_relation	=	m_strRelation	;	
	m_recordset.m_date		=	m_tmDate		;
	m_recordset.m_dept		=	m_strDept		;
	m_recordset.m_duty		=	m_strDuty		;
	m_recordset.m_political	=	m_strPolitical	;
	m_recordset.m_phone		=	m_strPhone		;
	m_recordset.m_code		=   m_strID			;
	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);
}

void CFamilyDlg::OnButtonDelete() 
{

	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from family where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该记录
	m_recordset.Delete();
	m_recordset.Close();

	//更新用户界面
	RefreshData(m_strID);

	m_strName		=	"";
	m_strRelation	=	"";
	m_strDept		=	"";
	m_strDuty		=	"";
	m_strPolitical	=	"";
	m_strPhone		=	"";
	m_tmDate		= CTime::GetCurrentTime();
	UpdateData(FALSE);	

	
}

void CFamilyDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here

	UpdateData();
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}

	if(m_strName=="")
	{
		MessageBox("请输入姓名！");
		return;
	}
	if(m_strRelation=="")
	{
		MessageBox("请输入与本人关系！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from family where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.Edit();
	m_recordset.m_name		=	m_strName		;	
	m_recordset.m_relation	=	m_strRelation	;	
	m_recordset.m_date		=	m_tmDate		;
	m_recordset.m_dept		=	m_strDept		;
	m_recordset.m_duty		=	m_strDuty		;
	m_recordset.m_political	=	m_strPolitical	;
	m_recordset.m_phone		=	m_strPhone		;
	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);
}
