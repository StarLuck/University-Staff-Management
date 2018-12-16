// WorkerStatusDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "WorkerStatusDlg.h"
#include "AddSysInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkerStatusDlg dialog


CWorkerStatusDlg::CWorkerStatusDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWorkerStatusDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWorkerStatusDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWorkerStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWorkerStatusDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWorkerStatusDlg, CDialog)
	//{{AFX_MSG_MAP(CWorkerStatusDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkerStatusDlg message handlers

BOOL CWorkerStatusDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"职工类型");
	m_ctrList.SetColumnWidth(0,120);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	
	RefreshData();	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CWorkerStatusDlg::RefreshData()
{

	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);


	CString strSQL;
	UpdateData(TRUE);

	strSQL="select * from status";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	

	int i=0;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i++,m_recordset.m_workstatus);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);
	
}
void CWorkerStatusDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	CAddSysInfoDlg AddSysInfoDlg;
	AddSysInfoDlg.m_strLabel = "职工类型：";

	if(AddSysInfoDlg.DoModal()!=IDOK)
		return;


	CString strSQL;
	strSQL.Format("select * from status where workstatus='%s'",AddSysInfoDlg.m_strData);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//判断记录是否已经存在
	if(m_recordset.GetRecordCount()!=0)
	{
		m_recordset.Close();
		MessageBox("该记录已经存在！");
		return;
	}
	//添加新记录
	m_recordset.AddNew();
	m_recordset.m_workstatus = AddSysInfoDlg.m_strData;
	m_recordset.Update();
	m_recordset.Close();
	
	RefreshData();	
}

void CWorkerStatusDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	if(i<0)
	{
		MessageBox("请选择一个用户！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from status where workstatus='%s'",	m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该记录
	m_recordset.Delete();
	m_recordset.Close();

	//刷新用户列表
	RefreshData();		
}
