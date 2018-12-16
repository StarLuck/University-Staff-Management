// HonorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "HonorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHonorDlg dialog


CHonorDlg::CHonorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHonorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHonorDlg)
	m_tmDate1 = 0;
	m_tmDate2 = 0;
	m_strDept = _T("");
	m_strReason1 = _T("");
	m_strReason2 = _T("");
	m_strSorts = _T("");
	//}}AFX_DATA_INIT
	m_strID = "";
}


void CHonorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHonorDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_BUTTON_SAVE1, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_bntModify);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tmDate1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_tmDate2);
	DDX_Text(pDX, IDC_EDIT_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_REASON1, m_strReason1);
	DDX_Text(pDX, IDC_EDIT_REASON2, m_strReason2);
	DDX_Text(pDX, IDC_EDIT_SORTS, m_strSorts);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHonorDlg, CDialog)
	//{{AFX_MSG_MAP(CHonorDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE1, OnButtonSave1)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHonorDlg message handlers

BOOL CHonorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"奖惩种类");
	m_ctrList.InsertColumn(2,"奖惩日期");
	m_ctrList.InsertColumn(3,"奖惩原因");
	m_ctrList.InsertColumn(4,"奖惩批准单位");
	m_ctrList.InsertColumn(5,"解除处分日期");
	m_ctrList.InsertColumn(6,"解除处分原因");

	m_ctrList.SetColumnWidth(0,40);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,100);
	m_ctrList.SetColumnWidth(5,100);
	m_ctrList.SetColumnWidth(6,100);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//设置按钮状态
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHonorDlg::RefreshData(CString strID)
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	UpdateData(TRUE);
	CString strSQL;
	m_strID.Format("%s",strID);
	strSQL.Format( "select * from honor where code = '%s'",strID);
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

		m_ctrList.SetItemText(i,1,m_recordset.m_sorts);
		strTime.Format("%d-%d-%d",m_recordset.m_date1.GetYear(),m_recordset.m_date1.GetMonth(),m_recordset.m_date1.GetDay());
		m_ctrList.SetItemText(i,2,strTime);
		m_ctrList.SetItemText(i,3,m_recordset.m_reason1);
		m_ctrList.SetItemText(i,4,m_recordset.m_dept);
		strTime.Format("%d-%d-%d",m_recordset.m_date2.GetYear(),m_recordset.m_date2.GetMonth(),m_recordset.m_date2.GetDay());
		m_ctrList.SetItemText(i,5,strTime);
		m_ctrList.SetItemText(i,6,m_recordset.m_reason2);
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

void CHonorDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	strSQL.Format("select * from honor where ID=%s",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	m_tmDate1		= 	m_recordset.m_date1		;
	m_tmDate2		= 	m_recordset.m_date2		;
	m_strSorts		= 	m_recordset.m_sorts		;
	m_strDept		= 	m_recordset.m_dept		;
	m_strReason1	= 	m_recordset.m_reason1	;
	m_strReason2	= 	m_recordset.m_reason2	;

	m_recordset.Close();	

	UpdateData(FALSE);	
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow();
	m_bntModify.EnableWindow();
	
	*pResult = 0;
}

void CHonorDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_tmDate1		=	0;
	m_tmDate2		=	0;
	m_strSorts		=	"";
	m_strDept		=	"";
	m_strReason1	=	"";
	m_strReason2	=	"";
	
	m_bntSave.EnableWindow();
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	UpdateData(FALSE);			
}

void CHonorDlg::OnButtonSave1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if(m_strSorts=="")
	{
		MessageBox("请输入奖惩种类！");
		return;
	}	
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.AddNew();
	m_recordset.m_date1		=	m_tmDate1		;	
	m_recordset.m_date2		=	m_tmDate2		;	
	m_recordset.m_sorts		=	m_strSorts		;
	m_recordset.m_dept		=	m_strDept		;
	m_recordset.m_reason1	=	m_strReason1	;
	m_recordset.m_reason2	=	m_strReason2	;
	m_recordset.m_code		=   m_strID			;

	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);		
}

void CHonorDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}

	if(m_strSorts=="")
	{
		MessageBox("请输入奖惩种类！");
		return;
	}	

	CString strSQL;
	strSQL.Format("select * from honor where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.Edit();
	m_recordset.m_date1		=	m_tmDate1		;	
	m_recordset.m_date2		=	m_tmDate2		;	
	m_recordset.m_sorts		=	m_strSorts		;
	m_recordset.m_dept		=	m_strDept		;
	m_recordset.m_reason1	=	m_strReason1	;
	m_recordset.m_reason2	=	m_strReason2	;
	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);		
}

void CHonorDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from honor where ID= %s ",m_ctrList.GetItemText(i,0));
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

	m_tmDate1		=	0;
	m_tmDate2		=	0;
	m_strSorts		=	"";
	m_strDept		=	"";
	m_strReason1	=	"";
	m_strReason2	=	"";
	UpdateData(FALSE);		
}
