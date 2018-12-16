// TrainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "TrainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrainDlg dialog


CTrainDlg::CTrainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrainDlg)
	m_tmDate1 = 0;
	m_tmDate2 = 0;
	m_strContent = _T("");
	m_strDept = _T("");
	m_strMode = _T("");
	m_strOutlay = _T("");
	m_strResult = _T("");
	m_strSubject = _T("");
	m_strTerm = _T("");
	//}}AFX_DATA_INIT
	m_strID = "";
}


void CTrainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrainDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_BUTTON_SAVE1, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_bntModify);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tmDate1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER3, m_tmDate2);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_Text(pDX, IDC_EDIT_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_MODE, m_strMode);
	DDX_Text(pDX, IDC_EDIT_OUTLAY, m_strOutlay);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
	DDX_Text(pDX, IDC_EDIT_SUBJECT, m_strSubject);
	DDX_Text(pDX, IDC_EDIT_TERM, m_strTerm);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTrainDlg, CDialog)
	//{{AFX_MSG_MAP(CTrainDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE1, OnButtonSave1)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainDlg message handlers

BOOL CTrainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"培训方式");
	m_ctrList.InsertColumn(2,"开始时间");
	m_ctrList.InsertColumn(3,"结束时间");
	m_ctrList.InsertColumn(4,"培训期限");
	m_ctrList.InsertColumn(5,"所学专业");
	m_ctrList.InsertColumn(6,"培训单位");
	m_ctrList.InsertColumn(7,"培训内容");
	m_ctrList.InsertColumn(8,"培训经费");
	m_ctrList.InsertColumn(9,"培训结果");

	m_ctrList.SetColumnWidth(0,40);
	m_ctrList.SetColumnWidth(1,60);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,80);
	m_ctrList.SetColumnWidth(8,80);
	m_ctrList.SetColumnWidth(9,80);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//设置按钮状态
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CTrainDlg::RefreshData(CString strID)
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	UpdateData(TRUE);
	CString strSQL;
	m_strID.Format("%s",strID);
	strSQL.Format( "select * from train where code = '%s'",strID);
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

		m_ctrList.SetItemText(i,1,m_recordset.m_mode);
		strTime.Format("%d-%d-%d",m_recordset.m_date1.GetYear(),m_recordset.m_date1.GetMonth(),m_recordset.m_date1.GetDay());
		m_ctrList.SetItemText(i,2,strTime);
		strTime.Format("%d-%d-%d",m_recordset.m_date2.GetYear(),m_recordset.m_date2.GetMonth(),m_recordset.m_date2.GetDay());
		m_ctrList.SetItemText(i,3,strTime);
		m_ctrList.SetItemText(i,4,m_recordset.m_term);
		m_ctrList.SetItemText(i,5,m_recordset.m_subject);
		m_ctrList.SetItemText(i,6,m_recordset.m_dept);
		m_ctrList.SetItemText(i,7,m_recordset.m_content);
		m_ctrList.SetItemText(i,8,m_recordset.m_outlay);
		m_ctrList.SetItemText(i,9,m_recordset.m_result);
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

void CTrainDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	strSQL.Format("select * from train where ID=%s",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	m_tmDate1		= 	m_recordset.m_date1		;
	m_tmDate2		= 	m_recordset.m_date2		;
	m_strMode		= 	m_recordset.m_mode		;
	m_strDept		= 	m_recordset.m_dept		;
	m_strTerm		= 	m_recordset.m_term		;
	m_strContent	= 	m_recordset.m_content	;
	m_strOutlay		= 	m_recordset.m_outlay	;
	m_strSubject	= 	m_recordset.m_subject	;
	m_strResult		= 	m_recordset.m_result	;

	m_recordset.Close();	

	UpdateData(FALSE);	
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow();
	m_bntModify.EnableWindow();	
	*pResult = 0;
}

void CTrainDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_tmDate1		=	0;
	m_tmDate2		=	0;
	m_strMode		= 	""	;
	m_strDept		= 	""	;
	m_strTerm		= 	""	;
	m_strContent	= 	""	;
	m_strOutlay		= 	""	;
	m_strSubject	= 	""	;
	m_strResult		= 	""	;

	m_bntSave.EnableWindow();
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	UpdateData(FALSE);				
}

void CTrainDlg::OnButtonSave1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if(m_strMode=="")
	{
		MessageBox("请输入培训方式！");
		return;
	}	
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.AddNew();
	m_recordset.m_date1			= 	m_tmDate1		;	
	m_recordset.m_date2			= 	m_tmDate2		;	
	m_recordset.m_mode			= 	m_strMode		;
	m_recordset.m_dept			= 	m_strDept		;
	m_recordset.m_term			= 	m_strTerm		;
	m_recordset.m_content		= 	m_strContent	;
	m_recordset.m_outlay		=	m_strOutlay		;
	m_recordset.m_subject		=	m_strSubject	;
	m_recordset.m_result		=	m_strResult		;
	
	m_recordset.m_code			=   m_strID			;

	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);			
}

void CTrainDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行修改！");
		return;
	}

	if(m_strMode=="")
	{
		MessageBox("请输入培训方式！");
		return;
	}	

	CString strSQL;
	strSQL.Format("select * from Train where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.Edit();
	m_recordset.m_date1			= 	m_tmDate1		;	
	m_recordset.m_date2			= 	m_tmDate2		;	
	m_recordset.m_mode			= 	m_strMode		;
	m_recordset.m_dept			= 	m_strDept		;
	m_recordset.m_term			= 	m_strTerm		;
	m_recordset.m_content		= 	m_strContent	;
	m_recordset.m_outlay		=	m_strOutlay		;
	m_recordset.m_subject		=	m_strSubject	;
	m_recordset.m_result		=	m_strResult		;
	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);			
}

void CTrainDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from train where ID= %s ",m_ctrList.GetItemText(i,0));
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
	m_strMode		= 	""	;
	m_strDept		= 	""	;
	m_strTerm		= 	""	;
	m_strContent	= 	""	;
	m_strOutlay		= 	""	;
	m_strSubject	= 	""	;
	m_strResult		= 	""	;

	UpdateData(FALSE);			
}
