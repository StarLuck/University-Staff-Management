// NotePadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "NotePadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg dialog


CNotePadDlg::CNotePadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNotePadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotePadDlg)
	m_strContent = _T("");
	m_strSort = _T("");
	m_strTitle = _T("");
	m_strComments = _T("");
	m_nCondition = -1;
	//}}AFX_DATA_INIT
	m_strID = "-1";
}


void CNotePadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotePadDlg)
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_bntModify);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDOK, m_bntOK);
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_COMBO_CONDITION, m_ctrCondition);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_bntCancel);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE, m_tmDate);
	DDX_Text(pDX, IDC_EDIT_CONTENT, m_strContent);
	DDX_Text(pDX, IDC_EDIT_SORT, m_strSort);
	DDX_Text(pDX, IDC_EDIT_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_RICHEDIT1, m_strComments);
	DDX_CBIndex(pDX, IDC_COMBO_CONDITION, m_nCondition);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNotePadDlg, CDialog)
	//{{AFX_MSG_MAP(CNotePadDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg message handlers

BOOL CNotePadDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.SetColumnWidth(0,40);
	
	m_ctrList.InsertColumn(1,"日期");
	m_ctrList.SetColumnWidth(1,60);
	
	m_ctrList.InsertColumn(2,"类别");
	m_ctrList.SetColumnWidth(2,60);

	m_ctrList.InsertColumn(3,"标题");
	m_ctrList.SetColumnWidth(3,100);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	CString strSQL;
	strSQL="select * from notepad";
	RefreshData(strSQL);

	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNotePadDlg::RefreshData(CString strSQL)
{
	m_ctrList.SetFocus();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	
	CString strTime;
	char  buffer[20];
	UpdateData(TRUE);

	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	

	int i=0;
	while(!m_recordset.IsEOF())
	{
		strTime.Format("%d-%d-%d",m_recordset.m_date.GetYear(),m_recordset.m_date.GetMonth(),m_recordset.m_date.GetDay());
		ltoa(m_recordset.m_ID,buffer,10);
		m_ctrList.InsertItem(i,buffer);
		m_ctrList.SetItemText(i,1,strTime);
		m_ctrList.SetItemText(i,2,m_recordset.m_sort);
		m_ctrList.SetItemText(i,3,m_recordset.m_caption);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);	
}

void CNotePadDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_strSort = "";
	m_strTitle = "";
	m_strComments = "";
	m_strID = "-1";
	m_tmDate = CTime::GetCurrentTime();
	m_bntOK.EnableWindow();
	m_bntCancel.EnableWindow();
	UpdateData(FALSE);
}

void CNotePadDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一条记录进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from notepad where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该用户
	m_recordset.Delete();
	m_recordset.Close();

	//更新用户列表

	strSQL="select * from notepad";
	RefreshData(strSQL);

	m_strSort = "";
	m_strTitle = "";
	m_strComments = "";
	UpdateData(FALSE);
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);	
}

void CNotePadDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	m_bntOK.EnableWindow();
	m_bntCancel.EnableWindow();	
}


void CNotePadDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);

	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	m_strID = m_ctrList.GetItemText(i,0);
	strSQL.Format("select * from notepad where ID=%s",m_strID);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	m_strSort = m_recordset.m_sort;
	m_strTitle = m_recordset.m_caption;
	m_tmDate = m_recordset.m_date;
	m_strComments = m_recordset.m_comments;
	m_recordset.Close();	
	UpdateData(FALSE);
	
	*pResult = 0;
}

void CNotePadDlg::OnOK() 
{
	UpdateData();
	if(m_strSort=="")
	{
		MessageBox("请输入类别！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from notepad where ID= %s",m_strID);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	if(m_recordset.GetRecordCount()==0)
	{//判断用户是否存在
		m_recordset.AddNew();
		m_recordset.m_sort = m_strSort ;
		m_recordset.m_caption = m_strTitle  ;
		m_recordset.m_date = m_tmDate ;
		m_recordset.m_comments = m_strComments ;
		m_recordset.Update();
	}
	else
	{//修改用户信息
		
		m_recordset.Edit();
		m_recordset.m_sort = m_strSort ;
		m_recordset.m_caption = m_strTitle  ;
		m_recordset.m_date = m_tmDate ;
		m_recordset.m_comments = m_strComments ;
		m_recordset.Update();
	}
	m_recordset.Close();

	strSQL="select * from notepad";
	RefreshData(strSQL);

	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);	
}

void CNotePadDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);	
}


void CNotePadDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSQL;
	if(0==m_nCondition)
		strSQL.Format("select * from notepad where sort='%s'",m_strContent);	
	else
		strSQL.Format("select * from notepad where caption='%s'",m_strContent);	
	//显示全部信息
	if(m_strContent=="")
		strSQL = "select * from notepad";
	RefreshData(strSQL);
	m_bntOK.EnableWindow(FALSE);
	m_bntCancel.EnableWindow(FALSE);	
}
