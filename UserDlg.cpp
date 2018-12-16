// UserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "UserDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserDlg dialog


CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserDlg)
	m_bIsAdmin = FALSE;
	m_strUser = _T("");
	m_strPass = _T("");
	m_strRePass = _T("");
	//}}AFX_DATA_INIT
}


void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserDlg)
	DDX_Control(pDX, IDOK, m_bntOK);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bntNew);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_bntDelete);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_bntCancel);
	DDX_Control(pDX, IDC_EDIT2, m_ctrPass);
	DDX_Control(pDX, IDC_EDIT1, m_ctrUser);
	DDX_Control(pDX, IDC_LIST_USERNAME, m_ctrList);
	DDX_Check(pDX, IDC_CHECK1, m_bIsAdmin);
	DDX_Text(pDX, IDC_EDIT1, m_strUser);
	DDX_Text(pDX, IDC_EDIT2, m_strPass);
	DDX_Text(pDX, IDC_EDIT3, m_strRePass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	//{{AFX_MSG_MAP(CUserDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST_USERNAME, OnClickListUsername)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserDlg message handlers

BOOL CUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//�����û��б�
	m_ctrList.InsertColumn(0,"�û���");
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrList.SetColumnWidth(0,120);
	//������û��б�������û���
	RefreshData();

	return TRUE;  
}
void CUserDlg::RefreshData() 
{

	m_ctrList.SetFocus();
	//����û��б�
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);
	
	CString strSQL;
	UpdateData(TRUE);
	//�򿪼�¼��
	strSQL="select * from password";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}	
	//����û������û��б���
	int i=0;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i++,m_recordset.m_user);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);

}
void CUserDlg::OnClickListUsername(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString strSQL;
	UpdateData(TRUE);
	//�����ݿ��л�ȡѡ���û���������
	int i = m_ctrList.GetSelectionMark();
	m_strUser = m_ctrList.GetItemText(i,0);
	strSQL.Format("select * from password where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}	
	//��ʾ�û�����
	m_strPass = m_recordset.m_passwd;
	m_strRePass = m_strPass;
	m_bIsAdmin = m_recordset.m_isadmin;
	m_recordset.Close();	
	UpdateData(FALSE);
	*pResult = 0;
}

void CUserDlg::OnButtonNew() 
{
	//����û�����
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	//�����û����༭��Ϊ����
	m_ctrUser.EnableWindow(TRUE);
	m_ctrUser.SetFocus();
	//�������ݵ�����
	UpdateData(FALSE);
}

void CUserDlg::OnButtonDelete() 
{

	UpdateData(TRUE);
	//�ж��Ƿ�ָ���û�
	if(m_strUser=="")
	{
		MessageBox("��ѡ��һ���û���");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from password where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}
	//ɾ�����û�
	m_recordset.Delete();
	m_recordset.Close();

	//ˢ���û��б�
	RefreshData();

	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	UpdateData(FALSE);
}

void CUserDlg::OnOK() 
{
	UpdateData();
	if(m_ctrUser.IsWindowEnabled())
	{//�������û���������
		if(m_strUser=="")
		{
			MessageBox("����д�û�����");
			m_ctrUser.SetFocus();
			return;
		}
	}
	else
	{//�޸��û���Ϣ��������
		if(m_strUser=="")
		{
			MessageBox("��ѡ��һ���û���");
			return;
		}
	}
	//�������벻��Ϊ��
	if(m_strPass=="")
	{ 
		MessageBox("���벻��Ϊ�գ����������룡");
		m_ctrPass.SetFocus();
		return;
	}
	//��֤������ȷ�������Ƿ�һ��
	if(m_strPass!=m_strRePass)
	{ 
		MessageBox("������������벻һ�£��������������룡");
		m_ctrPass.SetFocus();
		m_strPass = "";
		m_strRePass = "";
		UpdateData(FALSE);
		return;
	}
	//�򿪼�¼��
	CString strSQL;
	strSQL.Format("select * from password where user='%s'",m_strUser);
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return ;
	}
	if(m_ctrUser.IsWindowEnabled())
	{//�������û�
		//�ж��û��Ƿ��Ѿ�����
		if(m_recordset.GetRecordCount()!=0)
		{
			m_recordset.Close();
			MessageBox("���û��Ѿ����ڣ�");
			return;
		}
		m_recordset.AddNew();
		m_recordset.m_user = m_strUser;
		m_recordset.m_passwd = m_strPass;
		m_recordset.m_isadmin = m_bIsAdmin;
		m_recordset.Update();
		MessageBox("�û���ӳɹ������ס�û��������룡");
		m_recordset.Close();
	}
	else
	{//�޸��û���Ϣ
		//�ж��û��Ƿ񲻴���
		if(m_recordset.GetRecordCount()==0)
		{ 
			m_recordset.Close();
			MessageBox("���û������ڣ���������ݿ�");
			return;
		}
		m_recordset.Edit();
		m_recordset.m_user = m_strUser;
		m_recordset.m_passwd = m_strPass;
		m_recordset.m_isadmin = m_bIsAdmin;
		m_recordset.Update();
		MessageBox("�û��޸ĳɹ������ס�û��������룡");
		m_recordset.Close();
	}
	m_ctrUser.EnableWindow(FALSE);
	//�����û��б�	
	RefreshData();

}

void CUserDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	m_strUser = "";
	m_strPass = "";
	m_strRePass = "";
	m_bIsAdmin = FALSE;
	m_ctrUser.EnableWindow(FALSE);
	UpdateData(FALSE);	
}
