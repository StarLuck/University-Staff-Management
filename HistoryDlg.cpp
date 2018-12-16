// HistoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "HistoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg dialog


CHistoryDlg::CHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryDlg)
	m_tmDate1 = 0;
	m_tmDate2 = 0;
	m_strDept = _T("");
	m_strDuty = _T("");
	m_strLevel = _T("");
	m_strCompany = _T("");
	//}}AFX_DATA_INIT
	m_strID = "";
}


void CHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_BUTTON_SAVE1, m_bntSave);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_bntModify);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE1, m_tmDate1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE2, m_tmDate2);
	DDX_Text(pDX, IDC_EDIT_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_DUTY, m_strDuty);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strLevel);
	DDX_Text(pDX, IDC_EDIT_UNIT, m_strCompany);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHistoryDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE1, OnButtonSave1)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg message handlers

BOOL CHistoryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"���");
	m_ctrList.InsertColumn(1,"��ʼʱ��");
	m_ctrList.InsertColumn(2,"����ʱ��");
	m_ctrList.InsertColumn(3,"������λ");
	m_ctrList.InsertColumn(4,"��������");
	m_ctrList.InsertColumn(5,"����ְ��");
	m_ctrList.InsertColumn(6,"����");

	m_ctrList.SetColumnWidth(0,40);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	//���ð�ť״̬
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CHistoryDlg::RefreshData(CString strID)
{
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	UpdateData(TRUE);
	CString strSQL;
	m_strID.Format("%s",strID);
	strSQL.Format( "select * from history where code = '%s'",strID);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}	
	
	int i=0;
	CString strTime;
	char buffer[20];
	while(!m_recordset.IsEOF())
	{
		_ltoa(m_recordset.m_ID,buffer,10);
		m_ctrList.InsertItem(i,buffer);
		strTime.Format("%d-%d-%d",m_recordset.m_date1.GetYear(),m_recordset.m_date1.GetMonth(),m_recordset.m_date1.GetDay());
		m_ctrList.SetItemText(i,1,strTime);
		strTime.Format("%d-%d-%d",m_recordset.m_date2.GetYear(),m_recordset.m_date2.GetMonth(),m_recordset.m_date2.GetDay());
		m_ctrList.SetItemText(i,2,strTime);
		m_ctrList.SetItemText(i,3,m_recordset.m_company);
		m_ctrList.SetItemText(i,4,m_recordset.m_dept);
		m_ctrList.SetItemText(i,5,m_recordset.m_duty);
		m_ctrList.SetItemText(i,6,m_recordset.m_level1);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);
	//���ð�ť״̬
	m_bntSave.EnableWindow(FALSE);
	if(m_strID=="")
		m_bntNew.EnableWindow(FALSE);
	else
		m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
}
void CHistoryDlg::OnButtonNew() 
{
	// TODO: Add your control notification handler code here
	m_tmDate1		=	0;
	m_tmDate2		=	0;
	m_strCompany	=	"";
	m_strDept		=	"";
	m_strDuty		=	"";
	m_strLevel		=	"";
	
	m_bntSave.EnableWindow();
	m_bntNew.EnableWindow(FALSE);
	m_bntDelete.EnableWindow(FALSE);
	m_bntModify.EnableWindow(FALSE);
	UpdateData(FALSE);		
}

void CHistoryDlg::OnButtonSave1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if(m_strCompany=="")
	{
		MessageBox("�����빤����λ��");
		return;
	}	
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}
	m_recordset.AddNew();
	m_recordset.m_company	=	m_strCompany	;	
	m_recordset.m_date1		=	m_tmDate1		;	
	m_recordset.m_date2		=	m_tmDate2		;
	m_recordset.m_dept		=	m_strDept		;
	m_recordset.m_duty		=	m_strDuty		;
	m_recordset.m_level1	=	m_strLevel		;
	m_recordset.m_code		=   m_strID			;

	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);	
}

void CHistoryDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("��ѡ��һ����¼����ɾ����");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from history where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}
	//ɾ���ü�¼
	m_recordset.Delete();
	m_recordset.Close();

	//�����û�����
	RefreshData(m_strID);

	m_tmDate1		=	0;
	m_tmDate2		=	0;
	m_strCompany	=	"";
	m_strDept		=	"";
	m_strDuty		=	"";
	m_strLevel		=	"";
	UpdateData(FALSE);	
	
}

void CHistoryDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("��ѡ��һ����¼�����޸ģ�");
		return;
	}

	if(m_strCompany=="")
	{
		MessageBox("�����빤����λ��");
		return;
	}	

	CString strSQL;
	strSQL.Format("select * from history where ID= %s ",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}
	m_recordset.Edit();
	m_recordset.m_company	=	m_strCompany	;	
	m_recordset.m_date1		=	m_tmDate1		;	
	m_recordset.m_date2		=	m_tmDate2		;
	m_recordset.m_dept		=	m_strDept		;
	m_recordset.m_duty		=	m_strDuty		;
	m_recordset.m_level1	=	m_strLevel		;
	m_recordset.Update();

	m_recordset.Close();
	
	RefreshData(m_strID);	
}

void CHistoryDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	UpdateData(TRUE);
	int i = m_ctrList.GetSelectionMark();
	strSQL.Format("select * from history where ID=%s",m_ctrList.GetItemText(i,0));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}	
	m_strCompany= 	m_recordset.m_company	;
	m_tmDate1	= 	m_recordset.m_date1		;
	m_tmDate2	= 	m_recordset.m_date2		;
	m_strDept	= 	m_recordset.m_dept		;
	m_strDuty	= 	m_recordset.m_duty		;
	m_strLevel	= 	m_recordset.m_level1	;

	
	m_recordset.Close();	

	UpdateData(FALSE);	
	m_bntSave.EnableWindow(FALSE);
	m_bntNew.EnableWindow();
	m_bntDelete.EnableWindow();
	m_bntModify.EnableWindow();
	
	*pResult = 0;
}
