// AttOvertime.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttOvertime.h"
#include "PersonSet.h"

#include "AttDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAttOvertime property page

IMPLEMENT_DYNCREATE(CAttOvertime, CPropertyPage)

CAttOvertime::CAttOvertime() : CPropertyPage(CAttOvertime::IDD)
{
	//{{AFX_DATA_INIT(CAttOvertime)
	m_nHour = 0;
	m_strPersonID = _T("");
	m_strPersonName = _T("");
	m_Date = CTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}

CAttOvertime::~CAttOvertime()
{
}

void CAttOvertime::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttOvertime)
	DDX_Control(pDX, IDC_LIST2, m_cList);
	DDX_Text(pDX, IDC_EDT_OVERTIME_HOUR, m_nHour);
	DDX_Text(pDX, IDC_EDT_OVERTIME_PERSONID, m_strPersonID);
	DDX_Text(pDX, IDC_EDT_OVERTIME_PERSONNAME, m_strPersonName);
	DDX_DateTimeCtrl(pDX, IDC_OVERTIME_DATETIMEPICKER, m_Date);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttOvertime, CPropertyPage)
	//{{AFX_MSG_MAP(CAttOvertime)
	ON_EN_CHANGE(IDC_EDT_OVERTIME_PERSONID, OnChangeEdtOvertimePersonid)
	ON_BN_CLICKED(IDC_BTN_OVERTIME_ADD, OnBtnOvertimeAdd)
	ON_BN_CLICKED(IDC_BTN_OVERTIME_DELETEATTEND, OnBtnOvertimeDeleteattend)
	ON_BN_CLICKED(IDC_BTN_OVERTIME_SEEKIO, OnBtnOvertimeSeekio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttOvertime message handlers

void CAttOvertime::OnChangeEdtOvertimePersonid() 
{
	UpdateData(); 

	CPersonSet rs; 
	rs.m_strFilter = "ID='" + m_strPersonID + "'"; 
	rs.Open(); 
	if(rs.GetRecordCount()==1) 
	{
		m_strPersonName=rs.m_name; 
	}
	else m_strPersonName.Empty(); 
	rs.Close(); 
	UpdateData(FALSE); 
}

void CAttOvertime::OnBtnOvertimeAdd() 
{   


	UpdateData(); 
	// �ж�Ա�����Ƿ���ȷ
	if(m_strPersonName.IsEmpty()) 
	{
		AfxMessageBox("������Ա���ţ�");
		return; 
	}

	// ��Ӽ�¼
	COvertimeSet rs_overtime; 
	rs_overtime.Open(); 
	rs_overtime.AddNew(); 

	rs_overtime.m_PERSON=m_strPersonID;
	rs_overtime.m_WORK_HOURS=m_nHour;
	rs_overtime.m_WORK_DATE=m_Date;
	rs_overtime.Update(); 
	rs_overtime.Close(); 
	// �����б��
	UpdateList(rs_overtime); 
}

BOOL CAttOvertime::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// �����Ӱ��¼�б�
	int nWidth=110;
	m_cList.InsertColumn(0, "��¼���", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(1, "Ա����", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(2, "�Ӱ�ʱ��", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(3, "�Ӱ�����", LVCFMT_LEFT, nWidth);
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// �����б�
	COvertimeSet rs; 
	UpdateList(rs); 	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAttOvertime::UpdateList(COvertimeSet &rs)
{
	int i=0;
	CString strID,strWorkHours,strTime;
	// ����б������
	m_cList.DeleteAllItems(); 
	// �����ݱ������м�¼���д���
	rs.Open(); 
	while(!rs.IsEOF()) 
	{
		m_cList.InsertItem(i, ""); 
		strID.Format("%d", rs.m_ID);
		m_cList.SetItemText(i, 0, strID);
		m_cList.SetItemText(i, 1, rs.m_PERSON);
		strWorkHours.Format("%d",rs.m_WORK_HOURS);
		m_cList.SetItemText(i, 2, strWorkHours);
		m_cList.SetItemText(i, 3, rs.m_WORK_DATE.Format("%Y-%m-%d"));
		rs.MoveNext(); 
		i++;
	}
	rs.Close(); 
}

void CAttOvertime::OnBtnOvertimeDeleteattend() 
{
	CString strSQL;
	int nItem;
	// �õ���һ����ѡ��Item��λ��
	POSITION pos = m_cList.GetFirstSelectedItemPosition();
	
	if(pos==NULL)
	{
		AfxMessageBox("û��ѡ���¼!");
		return;
	}
	COvertimeSet rs; 
	// �������б�ѡItem
	while(pos) 
	{
		nItem=m_cList.GetNextSelectedItem(pos); 
		// ����SQL���
		strSQL="select * from OVERTIME where ID=" + m_cList.GetItemText(nItem, 0);
		if(!rs.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
			return ;
		}
		//ɾ�����û�
		rs.Delete();
		rs.Close();

	}
	// �����б��
	UpdateList(rs); 
}

void CAttOvertime::OnBtnOvertimeSeekio() 
{
	COvertimeSet rs; 

	CAttDlg *pDlg; 
	CString strFilter; 
	CString strSTime,strETime; 
	// �����û�����Ĳ�ѯ����
	pDlg=(CAttDlg*)GetParent()->GetParent(); 
	pDlg->UpdateData(); 

	strSTime=pDlg->m_StartTime.Format("%Y-%m-%d");
	strETime=pDlg->m_EndTime.Format("%Y-%m-%d");
	// ��ӹ�������
	if(pDlg->m_bSeekbyperson) 
		strFilter="PERSON='" + pDlg->m_strPersonID + "'"; 
	if(pDlg->m_bSeekbytime) 
	{
		if(strFilter.GetLength()>0) 
			strFilter += " and "; 
		strFilter += "WORK_DATE>" + strSTime ; 
		strFilter += " and WORK_DATE<" + strETime ;
 
	}
	if(strFilter.GetLength()>0) 
		rs.m_strFilter=strFilter; 
	// �����б��
	UpdateList(rs); 
}
