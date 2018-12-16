// SearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "SearchDlg.h"


#include "AboutPaySet.h"
#include "DeptSet.h"
#include "DutySet.h"
#include "EducationSet.h"
#include "FolkSet.h"
#include "PoliticalSet.h"
#include "TechnicalSet.h"
#include "WorkerStatusSet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg dialog


CSearchDlg::CSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDlg)
	m_strAboutPay = _T("");
	m_strDept = _T("");
	m_strDuty = _T("");
	m_strEducation = _T("");
	m_strFolk = _T("");
	m_strIsWorker = _T("");
	m_strMarry = _T("");
	m_strPolitical = _T("");
	m_strSex = _T("");
	m_strTechnical = _T("");
	m_nAge = 0;
	m_strDept2 = _T("");
	m_strDept3 = _T("");
	m_strName = _T("");
	m_strNative = _T("");
	m_bType = FALSE;
	//}}AFX_DATA_INIT
}


void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDlg)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_COMBO_TECHNICAL, m_ctrTechnical);
	DDX_Control(pDX, IDC_COMBO_POLITICAL, m_ctrPolitical);
	DDX_Control(pDX, IDC_COMBO_MARRY, m_ctrMarry);
	DDX_Control(pDX, IDC_COMBO_ISWORKER, m_ctrIsWorker);
	DDX_Control(pDX, IDC_COMBO_FOLK, m_ctrFolk);
	DDX_Control(pDX, IDC_COMBO_EDUCATION, m_ctrEducation);
	DDX_Control(pDX, IDC_COMBO_DUTY, m_ctrDuty);
	DDX_Control(pDX, IDC_COMBO_DEPT, m_ctrDept);
	DDX_Control(pDX, IDC_COMBO_ABOUTPAY, m_ctrAboutPay);
	DDX_CBString(pDX, IDC_COMBO_ABOUTPAY, m_strAboutPay);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_strDept);
	DDX_CBString(pDX, IDC_COMBO_DUTY, m_strDuty);
	DDX_CBString(pDX, IDC_COMBO_EDUCATION, m_strEducation);
	DDX_CBString(pDX, IDC_COMBO_FOLK, m_strFolk);
	DDX_CBString(pDX, IDC_COMBO_ISWORKER, m_strIsWorker);
	DDX_CBString(pDX, IDC_COMBO_MARRY, m_strMarry);
	DDX_CBString(pDX, IDC_COMBO_POLITICAL, m_strPolitical);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_strSex);
	DDX_CBString(pDX, IDC_COMBO_TECHNICAL, m_strTechnical);
	DDX_Text(pDX, IDC_EDIT_AGE, m_nAge);
	DDX_Text(pDX, IDC_EDIT_DEPT2, m_strDept2);
	DDX_Text(pDX, IDC_EDIT_DEPT3, m_strDept3);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NATIVE, m_strNative);
	DDX_Check(pDX, IDC_CHECK1, m_bType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDlg, CDialog)
	//{{AFX_MSG_MAP(CSearchDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDlg message handlers

BOOL CSearchDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//初始化员工列表///////////////////////////////////////////////////
	m_ctrList.InsertColumn(0,"员工号");
	m_ctrList.InsertColumn(1,"姓名");
	m_ctrList.InsertColumn(2,"性别");
	m_ctrList.InsertColumn(3,"生日");
	m_ctrList.InsertColumn(4,"年龄");
	m_ctrList.InsertColumn(5,"婚否");
	m_ctrList.InsertColumn(6,"职务");
	m_ctrList.InsertColumn(7,"职称");
	m_ctrList.InsertColumn(8,"职工类型");
	m_ctrList.InsertColumn(9,"工资类别");
	m_ctrList.InsertColumn(10,"文化程度");
	m_ctrList.InsertColumn(11,"政治面貌");
	m_ctrList.InsertColumn(12,"入职时间");

	RECT rect;
	m_ctrList.GetWindowRect(&rect);
	int wid = rect.right - rect.left;
	m_ctrList.SetColumnWidth(0,wid/13);
	m_ctrList.SetColumnWidth(1,wid/13);
	m_ctrList.SetColumnWidth(2,wid/13-15);
	m_ctrList.SetColumnWidth(3,wid/13+15);
	m_ctrList.SetColumnWidth(4,wid/13-15);
	m_ctrList.SetColumnWidth(5,wid/13-15);
	m_ctrList.SetColumnWidth(6,wid/13);
	m_ctrList.SetColumnWidth(7,wid/13);
	m_ctrList.SetColumnWidth(8,wid/13);
	m_ctrList.SetColumnWidth(9,wid/13);
	m_ctrList.SetColumnWidth(10,wid/13);
	m_ctrList.SetColumnWidth(11,wid/13);
	m_ctrList.SetColumnWidth(12,wid/13+15);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	/////////////////////////////////////////////////////////////////////////////////////

	//初始化查询条件中的ComboBox///////////////////////////////////////////////////////
	CString strSQL;
	//部门
	CDeptSet DeptSet ;
	strSQL="select * from dept";
	if(!DeptSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!DeptSet.IsEOF())
	{
		m_ctrDept.AddString(DeptSet.m_dept);
		DeptSet.MoveNext();
	}
	DeptSet.Close();
	//职工职务
	CDutySet DutySet ;
	strSQL="select * from duty";
	if(!DutySet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!DutySet.IsEOF())
	{
		m_ctrDuty.AddString(DutySet.m_duty);
		DutySet.MoveNext();
	}
	DutySet.Close();

	//职工职称
	CTechnicalSet TechnicalSet ;
	strSQL="select * from technical";
	if(!TechnicalSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!TechnicalSet.IsEOF())
	{
		m_ctrTechnical.AddString(TechnicalSet.m_technical);
		TechnicalSet.MoveNext();
	}
	TechnicalSet.Close();
	//职工类型
	CWorkerStatusSet WorkerStatusSet ;
	strSQL="select * from status";
	if(!WorkerStatusSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!WorkerStatusSet.IsEOF())
	{
		m_ctrIsWorker.AddString(WorkerStatusSet.m_workstatus);
		WorkerStatusSet.MoveNext();
	}
	WorkerStatusSet.Close();
	//工资类别
	CAboutPaySet AboutPaySet ;
	strSQL="select * from aboutpay";
	if(!AboutPaySet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!AboutPaySet.IsEOF())
	{
		m_ctrAboutPay.AddString(AboutPaySet.m_aboutpay);
		AboutPaySet.MoveNext();
	}
	AboutPaySet.Close();
	//职工民族
	CFolkSet FolkSet ;
	strSQL="select * from folk";
	if(!FolkSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!FolkSet.IsEOF())
	{
		m_ctrFolk.AddString(FolkSet.m_folk);
		FolkSet.MoveNext();
	}
	FolkSet.Close();
	//政治面貌
	CPoliticalSet PoliticalSet ;
	strSQL="select * from political";
	if(!PoliticalSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!PoliticalSet.IsEOF())
	{
		m_ctrPolitical.AddString(PoliticalSet.m_political);
		PoliticalSet.MoveNext();
	}
	PoliticalSet.Close();
	//文化程度
	CEducationSet EducationSet ;
	strSQL="select * from education";
	if(!EducationSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!EducationSet.IsEOF())
	{
		m_ctrEducation.AddString(EducationSet.m_education);
		EducationSet.MoveNext();
	}
	EducationSet.Close();	
	///////////////////////////////////////////////////////////////////////////////////

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSearchDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSQL;
	CString strTemp;
	CString strType;
	BOOL	bNoCondition = TRUE;

	//选择是否进行模糊查询
	if(m_bType)
		strType = " = ";
	else
		strType = " like ";
	//根据查询条件构造SQL语句///////////////////////////////////////////////
	strSQL = "select * from person where ";
	if(m_strAboutPay!="")
	{
		strTemp.Format(" aboutpay %s '%s' ",strType,m_strAboutPay);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strDept!="")
	{
		strTemp.Format(" dept %s '%s' ",strType,m_strDept);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strDuty!="")
	{
		strTemp.Format(" duty %s '%s' ",strType,m_strDuty);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strEducation!="")
	{
		strTemp.Format(" education %s '%s' ",strType,m_strEducation);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;	
	}
	if(m_strFolk!="")
	{
		strTemp.Format(" folk %s '%s' ",strType,m_strFolk);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strIsWorker!="")
	{
		strTemp.Format(" isworker %s '%s' ",strType,m_strIsWorker);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strMarry!="")
	{
		strTemp.Format(" ismarry %s '%s' ",strType,m_strMarry);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strPolitical!="")
	{
		strTemp.Format(" political %s '%s' ",strType,m_strPolitical);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strSex!="")
	{
		strTemp.Format(" sex %s '%s' ",strType,m_strSex);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strTechnical!="")
	{
		strTemp.Format(" technical %s '%s' ",strType,m_strTechnical);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_nAge>0)
	{
		
		strTemp.Format(" age = %d ",strType,m_nAge);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strDept2!="")
	{
		strTemp.Format(" dept2 %s '%s' ",strType,m_strDept2);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;	
	}
	if(m_strDept3!="")
	{
		strTemp.Format(" dept3 %s '%s' ",strType,m_strDept3);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strName!="")
	{
		strTemp.Format(" name %s '%s' ",strType,m_strName);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}
	if(m_strNative!="")
	{
		strTemp.Format(" native %s '%s' ",strType,m_strNative);
		if(!bNoCondition)
			strSQL += " and ";
		strSQL += strTemp;
		bNoCondition = FALSE;
	}

	if(bNoCondition)
	{
		strSQL = "select * from person";
	}
	///////////////////////////////////////////////////////////
//MessageBox(strSQL);

	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);


	if(!m_PersonSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	
	char buffer[20];
	CString   strTime;
	int i=0;
	while(!m_PersonSet.IsEOF())
	{
		
		m_ctrList.InsertItem(i,m_PersonSet.m_ID);
		m_ctrList.SetItemText(i,1,m_PersonSet.m_name);
		m_ctrList.SetItemText(i,2,m_PersonSet.m_sex);
		strTime.Format("%d-%d-%d",m_PersonSet.m_birth.GetYear(),m_PersonSet.m_birth.GetMonth(),m_PersonSet.m_birth.GetDay());
		m_ctrList.SetItemText(i,3,strTime);
		_itoa(m_PersonSet.m_age,buffer,10);
		m_ctrList.SetItemText(i,4,buffer);
		m_ctrList.SetItemText(i,5,m_PersonSet.m_ismarry);
		m_ctrList.SetItemText(i,6,m_PersonSet.m_duty);
		m_ctrList.SetItemText(i,7,m_PersonSet.m_technical);
		m_ctrList.SetItemText(i,8,m_PersonSet.m_isworker);
		m_ctrList.SetItemText(i,9,m_PersonSet.m_aboutpay);
		m_ctrList.SetItemText(i,10,m_PersonSet.m_education);
		m_ctrList.SetItemText(i,11,m_PersonSet.m_political);
		strTime.Format("%d-%d-%d",m_PersonSet.m_date2.GetYear(),m_PersonSet.m_date2.GetMonth(),m_PersonSet.m_date2.GetDay());
		m_ctrList.SetItemText(i,12,strTime);

		i++;
		m_PersonSet.MoveNext();
	}
	m_PersonSet.Close();
	m_ctrList.SetRedraw(TRUE);

}
