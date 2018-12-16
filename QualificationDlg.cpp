// QualificationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "QualificationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQualificationDlg dialog


CQualificationDlg::CQualificationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQualificationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQualificationDlg)
	m_tmDate0 = 0;
	m_tmDate1 = 0;
	m_tmDate2 = 0;
	m_strDept = _T("");
	m_strDuty = _T("");
	m_strMode = _T("");
	m_strTech = _T("");
	//}}AFX_DATA_INIT
	m_strID = "";
}


void CQualificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQualificationDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_BUTTON_SAVE1, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_bntModify);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE0, m_tmDate0);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE1, m_tmDate1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE2, m_tmDate2);
	DDX_Text(pDX, IDC_EDIT_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_DUTY, m_strDuty);
	DDX_Text(pDX, IDC_EDIT_MODE, m_strMode);
	DDX_Text(pDX, IDC_EDIT_TECH, m_strTech);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQualificationDlg, CDialog)
	//{{AFX_MSG_MAP(CQualificationDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE1, OnButtonSave1)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQualificationDlg message handlers

BOOL CQualificationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"专业技术资格名称");
	m_ctrList.InsertColumn(2,"取得方式");
	m_ctrList.InsertColumn(3,"取得日期");
	m_ctrList.InsertColumn(4,"聘用专业技术职务");
	m_ctrList.InsertColumn(5,"聘用开始时间");
	m_ctrList.InsertColumn(6,"聘用结束时间");
	m_ctrList.InsertColumn(7,"聘用单位");

	m_ctrList.SetColumnWidth(0,40);
	m_ctrList.SetColumnWidth(1,100);
	m_ctrList.SetColumnWidth(2,60);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,100);
	m_ctrList.SetColumnWidth(5,100);
	m_ctrList.SetColumnWidth(6,100);
	m_ctrList.SetColumnWidth(7,80);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//设置按钮状态
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQualificationDlg::RefreshData(CString strID)
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	UpdateData(TRUE);
	CString strSQL;
	m_strID.Format("%s",strID);
	strSQL.Format( "select * from assess where code = '%s'",strID);
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

		m_ctrList.SetItemText(i,1,m_recordset.m_tech);//专业技术资格
		m_ctrList.SetItemText(i,2,m_recordset.m_mode);//取得方式
		strTime.Format("%d-%d-%d",m_recordset.m_date0.GetYear(),m_recordset.m_date0.GetMonth(),m_recordset.m_date0.GetDay());
		m_ctrList.SetItemText(i,3,strTime);//取得时间
		m_ctrList.SetItemText(i,4,m_recordset.m_duty);//聘用专业技术职务
		strTime.Format("%d-%d-%d",m_recordset.m_date1.GetYear(),m_recordset.m_date1.GetMonth(),m_recordset.m_date1.GetDay());
		m_ctrList.SetItemText(i,5,strTime);//聘用开始时间
		strTime.Format("%d-%d-%d",m_recordset.m_date2.GetYear(),m_recordset.m_date2.GetMonth(),m_recordset.m_date2.GetDay());
		m_ctrList.SetItemText(i,6,strTime);//聘用结束时间
		m_ctrList.SetItemText(i,7,m_recordset.m_dept);//聘用部门
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
void CQualificationDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	strSQL.Format("select * from assess where ID=%s",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	m_tmDate0		= 	m_recordset.m_date0		;	//取得时间
	m_tmDate1		= 	m_recordset.m_date1		;	//聘用开始时间
	m_tmDate2		= 	m_recordset.m_date2		;	//聘用结束时间
	m_strTech		= 	m_recordset.m_tech		;	//专业技术资格
	m_strDept		= 	m_recordset.m_dept		;	//聘用部门
	m_strMode		= 	m_recordset.m_mode		;	//取得方式
	m_strDuty		= 	m_recordset.m_duty		;	//聘用专业技术职务

	m_recordset.Close();	

	UpdateData(FALSE);	
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow();
	m_bntModify.EnableWindow();	
	*pResult = 0;
}

void CQualificationDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_tmDate0	=	0;
	m_tmDate1	=	0;
	m_tmDate2	=	0;
	m_strTech	=	"";
	m_strDept	=	"";
	m_strMode	=	"";
	m_strDuty	=	"";

	m_bntSave.EnableWindow();
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	UpdateData(FALSE);				
}

void CQualificationDlg::OnButtonSave1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if(m_strTech=="")
	{
		MessageBox("请输入专业技术资格名称！");
		return;
	}	
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.AddNew();
	m_recordset.m_date0		=	m_tmDate0	;	
	m_recordset.m_date1		=	m_tmDate1	;	
	m_recordset.m_date2		=	m_tmDate2	;
	m_recordset.m_tech		=	m_strTech	;
	m_recordset.m_dept		=	m_strDept	;
	m_recordset.m_mode		=	m_strMode	;
	m_recordset.m_duty		=	m_strDuty	;
	m_recordset.m_code		=   m_strID		;

	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);			
}

void CQualificationDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}

	if(m_strTech=="")
	{
		MessageBox("请输入专业技术资格名称！");
		return;
	}	

	CString strSQL;
	strSQL.Format("select * from assess where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.Edit();
	m_recordset.m_date0		=	m_tmDate0	;	
	m_recordset.m_date1		=	m_tmDate1	;	
	m_recordset.m_date2		=	m_tmDate2	;
	m_recordset.m_tech		=	m_strTech	;
	m_recordset.m_dept		=	m_strDept	;
	m_recordset.m_mode		=	m_strMode	;
	m_recordset.m_duty		=	m_strDuty	;
	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);			
}

void CQualificationDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from assess where ID= %s ",m_ctrList.GetItemText(i,0));
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

	m_tmDate0	=	0;
	m_tmDate1	=	0;
	m_tmDate2	=	0;
	m_strTech	=	"";
	m_strDept	=	"";
	m_strMode	=	"";
	m_strDuty	=	"";
	UpdateData(FALSE);			
}
