// AttErrand.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttErrand.h"
#include "PersonSet.h"

#include "AttDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAttErrand property page

IMPLEMENT_DYNCREATE(CAttErrand, CPropertyPage)

CAttErrand::CAttErrand() : CPropertyPage(CAttErrand::IDD)
{
	// �õ���ǰʱ�䲢��ʽ��
	CTime t=CTime::GetCurrentTime();
	CString str=t.Format("%Y-%m-%d %H:%M");
	//{{AFX_DATA_INIT(CAttErrand)
	m_strSTime = str;
	m_strETime = str;
	m_strPersonID = _T("");
	m_strPersonName = _T("");
	m_strDescription = _T("");
	//}}AFX_DATA_INIT
}

CAttErrand::~CAttErrand()
{
}

void CAttErrand::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttErrand)
	DDX_Control(pDX, IDC_LIST4, m_cList);
	DDX_Text(pDX, IDC_EDT_ERRAND_STARTTIME, m_strSTime);
	DDX_Text(pDX, IDC_EDT_ERRAND_ENDTIME, m_strETime);
	DDX_Text(pDX, IDC_EDT_ERRAND_PERSONID, m_strPersonID);
	DDX_Text(pDX, IDC_EDT_ERRAND_PERSONNAME, m_strPersonName);
	DDX_Text(pDX, IDC_EDT_ERRAND_DESCRIPTION, m_strDescription);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttErrand, CPropertyPage)
	//{{AFX_MSG_MAP(CAttErrand)
	ON_EN_CHANGE(IDC_EDT_ERRAND_PERSONID, OnChangeEdtErrandPersonid)
	ON_BN_CLICKED(IDC_BTN_ERRAND_ADD, OnBtnErrandAdd)
	ON_BN_CLICKED(IDC_BTN_ERRAND_DELETEATTEND, OnBtnErrandDeleteattend)
	ON_BN_CLICKED(IDC_BTN_ERRAND_SEEKIO, OnBtnErrandSeekio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttErrand message handlers

BOOL CAttErrand::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	// �����б�
	int nWidth=90;
	m_cList.InsertColumn(0, "��¼���", LVCFMT_LEFT, nWidth-20);
	m_cList.InsertColumn(1, "Ա����", LVCFMT_LEFT, nWidth-20);
	m_cList.InsertColumn(2, "��ʼʱ��", LVCFMT_LEFT, nWidth+20);
	m_cList.InsertColumn(3, "����ʱ��", LVCFMT_LEFT, nWidth+20);
	m_cList.InsertColumn(4, "��������", LVCFMT_LEFT, nWidth);
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// �����б�	
	CErrandSet rs;
	UpdateList(rs); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAttErrand::UpdateList(CErrandSet &rs)
{
	int i=0;
	CString strID,strSTime,strETime;
	// ����б������
	m_cList.DeleteAllItems(); 
	// �����ݼ������м�¼��ӵ��б���
	rs.Open(); 
	while(!rs.IsEOF()) 
	{
		m_cList.InsertItem(i, ""); 
		strID.Format("%d", rs.m_ID);
		m_cList.SetItemText(i, 0, strID);
		m_cList.SetItemText(i, 1, rs.m_PERSON);
		strSTime=rs.m_START_TIME.Format("%y-%m-%d %H:%M");
		m_cList.SetItemText(i, 2, strSTime);
		strETime=rs.m_END_TIME.Format("%y-%m-%d %H:%M");
		m_cList.SetItemText(i, 3, strETime);
		m_cList.SetItemText(i, 4, rs.m_DESCRIPTION);
		rs.MoveNext(); 
		i++;
	}
	rs.Close(); 
}

void CAttErrand::OnChangeEdtErrandPersonid() 
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

void CAttErrand::OnBtnErrandAdd() 
{

	UpdateData(); // ��������

	int nYear,nMonth,nDay,nHour,nMinute; // ��,��,��,ʱ,��
	// ת����ʼʱ������
	sscanf(m_strSTime.Left(4), "%d", &nYear); // �õ���
	sscanf(m_strSTime.Mid(5,2), "%d", &nMonth); // �õ���
	sscanf(m_strSTime.Mid(8,2), "%d", &nDay); // �õ���
	sscanf(m_strSTime.Mid(11,2), "%d", &nHour); // �õ�ʱ
	sscanf(m_strSTime.Mid(14,2), "%d", &nMinute); // �õ���
	// �õ���ʼʱ��
	CTime S_time(nYear,nMonth,nDay,nHour,nMinute,0);
	// ת������ʱ������
	sscanf(m_strETime.Left(4), "%d", &nYear); // �õ���
	sscanf(m_strETime.Mid(5,2), "%d", &nMonth); // �õ���
	sscanf(m_strETime.Mid(8,2), "%d", &nDay); // �õ���
	sscanf(m_strETime.Mid(11,2), "%d", &nHour); // �õ�ʱ
	sscanf(m_strETime.Mid(14,2), "%d", &nMinute); // �õ���
	// �õ�����ʱ��
	CTime E_time(nYear,nMonth,nDay,nHour,nMinute,0);
	// ��ӳ����¼
	CErrandSet rs_errand; 
	rs_errand.Open(); 
	rs_errand.AddNew(); 
	rs_errand.m_PERSON=m_strPersonID;
	rs_errand.m_START_TIME=S_time;
	rs_errand.m_END_TIME=E_time;
	rs_errand.m_DESCRIPTION=m_strDescription;
	rs_errand.Update();
	rs_errand.Close(); 
	UpdateList(rs_errand); 
}

void CAttErrand::OnBtnErrandDeleteattend() 
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
	CErrandSet rs; 
	while(pos) 
	{
		nItem=m_cList.GetNextSelectedItem(pos); 
		// ����SQL���
		strSQL="select * from ERRAND where ID=" + m_cList.GetItemText(nItem, 0);
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

void CAttErrand::OnBtnErrandSeekio() 
{
	CErrandSet rs; 

	CAttDlg *pDlg; 
	CString strFilter; 
	CString strSTime,strETime; 

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
		strFilter += "END_TIME>" + strSTime ;
		strFilter += " and START_TIME<" + strETime ;
	}
	if(strFilter.GetLength()>0) 
		rs.m_strFilter=strFilter; 
	 // �����б��
	UpdateList(rs);
}
