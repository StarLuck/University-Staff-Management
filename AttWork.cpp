// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttWork.h"

#include "PersonSet.h"
#include "deptset.h"
#include "AttDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAttWork property page

IMPLEMENT_DYNCREATE(CAttWork, CPropertyPage)

CAttWork::CAttWork() : CPropertyPage(CAttWork::IDD)
{
	//{{AFX_DATA_INIT(CAttWork)
	m_strIOTime = CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M");
	m_strDepartment = _T("");
	m_strPersonID = _T("");
	//}}AFX_DATA_INIT
}

CAttWork::~CAttWork()
{
}

void CAttWork::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttWork)
	DDX_Control(pDX, IDC_COMBO_PERSONID, m_ctrPersonID);
	DDX_Control(pDX, IDC_COMBO_DEPARTMENT, m_ctrDepartment);
	DDX_Control(pDX, IDC_LIST1, m_cList);
	DDX_Text(pDX, IDC_EDT_IOTIME, m_strIOTime);
	DDX_CBString(pDX, IDC_COMBO_DEPARTMENT, m_strDepartment);
	DDX_CBString(pDX, IDC_COMBO_PERSONID, m_strPersonID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttWork, CPropertyPage)
	//{{AFX_MSG_MAP(CAttWork)
	ON_BN_CLICKED(IDC_BTN_ADDPERSON, OnBtnAddperson)
	ON_BN_CLICKED(IDC_BTN_ADDDEPART, OnBtnAdddepart)
	ON_BN_CLICKED(IDC_BTN_ADDALL, OnBtnAddall)
	ON_BN_CLICKED(IDC_BTN_DELETEATTEND, OnBtnDeleteattend)
	ON_BN_CLICKED(IDC_BTN_SEEKIO, OnBtnSearch)
	ON_CBN_SETFOCUS(IDC_COMBO_PERSONID, OnSetfocusComboPersonid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttWork message handlers

BOOL CAttWork::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	//��Ӳ������
	CString strSQL;
	CDeptSet DeptSet ;
	strSQL="select * from dept";
	if(!DeptSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);

	}	
	while(!DeptSet.IsEOF())
	{
		m_ctrDepartment.AddString(DeptSet.m_dept);
		DeptSet.MoveNext();
	}
	DeptSet.Close();
	// ���ó������
	((CButton*)GetDlgItem(IDC_RADIO_OUT))->SetCheck(TRUE);
	//�����б�
	int nWidth=110;
	m_cList.InsertColumn(0, "��¼���", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(1, "Ա����", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(2, "�������", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(3, "ʱ��", LVCFMT_LEFT, nWidth);
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//���б�����ʾ����
	CAttendanceSet rs; 
	UpdateList(rs); 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


// ��ӳ��ڼ�¼
void CAttWork::AddRecord(CString strPersonID)
{
	CString strIO; 
	// �ж�ȷ���������
	if(((CButton*)GetDlgItem(IDC_RADIO_OUT))->GetCheck())
		strIO="OUT";
	else strIO="IN";
	int nYear,nMonth,nDay,nHour,nMinute; // ��,��,��,ʱ,��
	sscanf(m_strIOTime.Left(4), "%d", &nYear); // �õ���
	sscanf(m_strIOTime.Mid(5,2), "%d", &nMonth); // �õ���
	sscanf(m_strIOTime.Mid(8,2), "%d", &nDay); // �õ���
	sscanf(m_strIOTime.Mid(11,2), "%d", &nHour); // �õ�ʱ
	sscanf(m_strIOTime.Mid(14,2), "%d", &nMinute); // �õ���
	CTime IO_time(nYear,nMonth,nDay,nHour,nMinute,0);
	// ��Ӽ�¼
	CAttendanceSet rs; 
	rs.Open(); 
	rs.AddNew(); 
	rs.m_PERSON=strPersonID;
	rs.m_IN_OUT=strIO;
	rs.m_IO_TIME=IO_time;
	rs.Update();
	rs.Close(); 
}
// ��ӵ���Ա�����ڼ�¼
void CAttWork::OnBtnAddperson() 
{
	UpdateData();
	// �ж�Ա���Ƿ����
	if(m_strPersonID.IsEmpty()) 
	{
		AfxMessageBox("��ѡ��һ��Ա����");
		return;
	}
	//��ӵ���Ա�����ڼ�¼
	AddRecord(m_strPersonID); 
	CAttendanceSet rs; 
	UpdateList(rs); 
}
//��Ӳ���Ա�����ڼ�¼
void CAttWork::OnBtnAdddepart() 
{

	CPersonSet personSet; 
	// �жϲ����Ƿ�����
	if(m_strDepartment.IsEmpty()) 
	{
		AfxMessageBox("��ѡ��һ������");
		return; 
	}
	// ��Ա����Ϣ��
	personSet.m_strFilter.Format("dept='%s'",m_strDepartment);
	personSet.Open(); 
	// ��ӳ��ڼ�¼
	while(!personSet.IsEOF()) 
	{
		AddRecord(personSet.m_ID); 
		personSet.MoveNext(); 
	}
	personSet.Close(); 
	CAttendanceSet rs; 
	// �����б�
	UpdateList(rs); 
}
// �������Ա�����ڼ�¼
void CAttWork::OnBtnAddall() 
{
	CPersonSet personSet; 
	// ��Ա����Ϣ��
	personSet.Open(); 
	// ��ӵ�ǰԱ�����ڼ�¼
	while(!personSet.IsEOF()) 
	{
		AddRecord(personSet.m_ID); 
		personSet.MoveNext(); 
	}
	personSet.Close(); 
	CAttendanceSet rs; 
	// �����б�
	UpdateList(rs); 
}
// �����б�����
void CAttWork::UpdateList(CAttendanceSet& rs) 
{
	// ����б������
	m_cList.DeleteAllItems(); 
	int i=0;
	CString strID,strTime;
	rs.Open(); 
	// �����ݱ������м�¼���д���
	while(!rs.IsEOF()) 
	{
		m_cList.InsertItem(i, ""); 
		strID.Format("%d", rs.m_ID); 
		m_cList.SetItemText(i, 0, strID);
		m_cList.SetItemText(i, 1, rs.m_PERSON);
		m_cList.SetItemText(i, 2, rs.m_IN_OUT);
		m_cList.SetItemText(i, 3, rs.m_IO_TIME.Format("%Y-%m-%d %H:%M"));
		rs.MoveNext(); 
		i++;
	}
	rs.Close(); 
}
// ɾ�����ڼ�¼�б�����ѡ��¼
void CAttWork::OnBtnDeleteattend() 
{
	// �õ���һ����ѡ��Item��λ��
	int nItem = m_cList.GetSelectionMark();
	if(nItem<0)
	{
		AfxMessageBox("û��ѡ���¼!");
		return;
	}
	CAttendanceSet rs; 
	// ����SQL���
	CString strSQL="select * from attendance where ID="
		+ m_cList.GetItemText(nItem, 0);
	if(!rs.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}
	//ɾ�����û�
	rs.Delete();
	rs.Close();
	// �����б�
	UpdateList(rs); 
}

void CAttWork::OnBtnSearch() 
{
	CAttendanceSet rs; 

	CAttDlg *pDlg; 
	CString strFilter; 
	CString strSTime,strETime; 
	// ���²�ѯ��������
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
		strFilter += "IO_TIME>" + strSTime ; 
		strFilter += " and IO_TIME<" + strETime ; 
	}
	if(strFilter.GetLength()>0) 
		rs.m_strFilter=strFilter; 
	// �����б�
	UpdateList(rs); 
}


//��Ա�����������б����������
void CAttWork::OnSetfocusComboPersonid() 
{
	UpdateData();
	//���ComboBox��ѯ����
	int nCount=m_ctrPersonID.GetCount();
	for(int i=0;i<nCount;i++)
	{
		m_ctrPersonID.DeleteString(0);
	}

	CString strSQL;
	//���Ա������
	CPersonSet PersonSet ;
	strSQL.Format("select * from person where dept='%s'",m_strDepartment);
	if(!PersonSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);

	}	
	while(!PersonSet.IsEOF())
	{
		m_ctrPersonID.AddString(PersonSet.m_ID);
		PersonSet.MoveNext();
	}
	PersonSet.Close();		
}
