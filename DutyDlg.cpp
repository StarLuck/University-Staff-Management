// DutyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "DutyDlg.h"
#include "AddSysInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDutyDlg dialog


CDutyDlg::CDutyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDutyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDutyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDutyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDutyDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDutyDlg, CDialog)
	//{{AFX_MSG_MAP(CDutyDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDutyDlg message handlers

BOOL CDutyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"职务类别");
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrList.SetColumnWidth(0,120);
	
	RefreshData();		
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CDutyDlg::RefreshData()
{

	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);


	CString strSQL;
	UpdateData(TRUE);

	strSQL="select * from duty";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	

	int i=0;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i++,m_recordset.m_duty);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);
	
}
void CDutyDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	CAddSysInfoDlg AddSysInfoDlg;
	AddSysInfoDlg.m_strLabel = "职务类别：";

	if(AddSysInfoDlg.DoModal()!=IDOK)
		return;


	CString strSQL;
	strSQL.Format("select * from duty where duty='%s'",AddSysInfoDlg.m_strData);
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
	m_recordset.m_duty = AddSysInfoDlg.m_strData;
	m_recordset.Update();
	m_recordset.Close();
	
	RefreshData();					
}

void CDutyDlg::OnButtonDelete() 
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
	strSQL.Format("select * from duty where duty='%s'",	m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该记录
	m_recordset.Delete();
	m_recordset.Close();

	//刷新列表
	RefreshData();			
}
