// BaseInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "BaseInfoDlg.h"


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
// CBaseInfoDlg dialog


CBaseInfoDlg::CBaseInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBaseInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaseInfoDlg)
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
	m_tmBirth = 0;
	m_tmDate1 = 0;
	m_tmDate2 = 0;
	m_tmGDate = 0;
	m_strAddress = _T("");
	m_strAge = _T("");
	m_strCardID = _T("");
	m_strID = _T("");
	m_strDept2 = _T("");
	m_strDept3 = _T("");
	m_strEMail = _T("");
	m_strMobile = _T("");
	m_strName = _T("");
	m_strNative = _T("");
	m_strPhone = _T("");
	m_strSchool = _T("");
	m_strSubject = _T("");
	//}}AFX_DATA_INIT
	m_pPersonSet=NULL;
}


void CBaseInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseInfoDlg)
	DDX_Control(pDX, IDC_EDIT_CODE, m_ctrID);
	DDX_Control(pDX, IDC_COMBO_TECHNICAL, m_ctrTechnical);
	DDX_Control(pDX, IDC_COMBO_POLITICAL, m_ctrPolitical);
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
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTHDAY, m_tmBirth);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE1, m_tmDate1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_DATE2, m_tmDate2);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_GDATE, m_tmGDate);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_Text(pDX, IDC_EDIT_CARDCODE, m_strCardID);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strID);
	DDX_Text(pDX, IDC_EDIT_DEPT2, m_strDept2);
	DDX_Text(pDX, IDC_EDIT_DEPT3, m_strDept3);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEMail);
	DDX_Text(pDX, IDC_EDIT_MOBILE, m_strMobile);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NATIVE, m_strNative);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strPhone);
	DDX_Text(pDX, IDC_EDIT_SCHOOL, m_strSchool);
	DDX_Text(pDX, IDC_EDIT_SUBJECT, m_strSubject);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBaseInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CBaseInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseInfoDlg message handlers

BOOL CBaseInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
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


	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CBaseInfoDlg::RefreshData()
{
	CString strSQL;
	strSQL.Format("select * from person where ID='%s'",m_strID);
	if(!m_pPersonSet->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return;
	}
	char buffer[20];
    _itoa(m_pPersonSet->m_age,buffer,10);

	m_strAddress = m_pPersonSet->m_addr;
	m_strAge = buffer;
	m_strCardID = m_pPersonSet->m_cardID;
	m_strDept2 = m_pPersonSet->m_dept_1;
	m_strDept3 = m_pPersonSet->m_dept_2;
	m_strEMail = m_pPersonSet->m_email;
	m_strMobile = m_pPersonSet->m_mphone;
	m_strName = m_pPersonSet->m_name;
	m_strNative = m_pPersonSet->m_native;
	m_strPhone = m_pPersonSet->m_phone;
	m_strSchool = m_pPersonSet->m_school;
	m_strSubject = m_pPersonSet->m_subject;	

	m_strAboutPay = m_pPersonSet->m_aboutpay;
	m_strDept = m_pPersonSet->m_dept;
	m_strDuty = m_pPersonSet->m_duty;
	m_strEducation = m_pPersonSet->m_education;
	m_strFolk = m_pPersonSet->m_folk;
	m_strIsWorker = m_pPersonSet->m_isworker;
	m_strMarry = m_pPersonSet->m_ismarry;
	m_strPolitical = m_pPersonSet->m_political;
	m_strSex = m_pPersonSet->m_sex;
	m_strTechnical = m_pPersonSet->m_technical;
	m_tmBirth = m_pPersonSet->m_birth;
	m_tmDate1 = m_pPersonSet->m_date1;
	m_tmDate2 = m_pPersonSet->m_date2;
	m_tmGDate = m_pPersonSet->m_gdate;
	m_pPersonSet->Close();	
	UpdateData(FALSE);

}

void CBaseInfoDlg::Clear()
{
	m_strID = "";
	m_strAddress = "";
	m_strAge = "";
	m_strCardID = "";
	m_strDept2 = "";
	m_strDept3 = "";
	m_strEMail = "";
	m_strMobile = "";
	m_strName = "";
	m_strNative = "";
	m_strPhone = "";
	m_strSchool = "";
	m_strSubject = "";
	m_strAboutPay = "";
	m_strDept = "";
	m_strDuty = "";
	m_strEducation = "";
	m_strFolk = "";
	m_strIsWorker = "";
	m_strMarry = "";
	m_strPolitical = "";
	m_strSex = "";
	m_strTechnical = "";
	m_tmBirth = 0;
	m_tmDate1 = 0;
	m_tmDate2 = 0;
	m_tmGDate = 0;	
	UpdateData(FALSE);
}
BOOL CBaseInfoDlg::Save()
{
	UpdateData();
	if(m_strID=="")
	{
		MessageBox("员工号不能为空，请输入员工号");
		return FALSE;
	}
	if(m_strName=="")
	{
		MessageBox("姓名不能为空，请输入姓名");
		return FALSE;
	}
	CString strSQL;
	strSQL.Format("select * from person where ID='%s'",m_strID);
	if(!m_pPersonSet->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return FALSE;
	}
	if(m_pPersonSet->GetRecordCount()!=0)
	{
		MessageBox("该员工已经存在！");
		m_pPersonSet->Close();
		return FALSE;
	}
	m_pPersonSet->AddNew();

	m_pPersonSet->m_ID = m_strID;
	m_pPersonSet->m_addr = m_strAddress;
	m_pPersonSet->m_age = atoi(m_strAge);
	m_pPersonSet->m_cardID = m_strCardID;
	m_pPersonSet->m_dept_1 = m_strDept2;
	m_pPersonSet->m_dept_2 = m_strDept3;
	m_pPersonSet->m_email = m_strEMail;
	m_pPersonSet->m_mphone = m_strMobile;
	m_pPersonSet->m_name = m_strName;
	m_pPersonSet->m_native = m_strNative ;
	m_pPersonSet->m_phone = m_strPhone;
	m_pPersonSet->m_school = m_strSchool;
	m_pPersonSet->m_subject = m_strSubject ;	

	m_pPersonSet->m_aboutpay = m_strAboutPay  ;
	m_pPersonSet->m_dept = m_strDept ;
	m_pPersonSet->m_duty = m_strDuty;
	m_pPersonSet->m_education = m_strEducation  ;
	m_pPersonSet->m_folk = m_strFolk  ;
	m_pPersonSet->m_isworker = m_strIsWorker  ;
	m_pPersonSet->m_ismarry = m_strMarry ;
	m_pPersonSet->m_political = m_strPolitical ;
	m_pPersonSet->m_sex = m_strSex ;
	m_pPersonSet->m_technical = m_strTechnical  ;
	m_pPersonSet->m_birth = m_tmBirth ;
	m_pPersonSet->m_date1 = m_tmDate1 ;
	m_pPersonSet->m_date2 = m_tmDate2 ;
	m_pPersonSet->m_gdate = m_tmGDate ;
	
	m_pPersonSet->Update();

	m_pPersonSet->Close();

	return TRUE;
}
BOOL CBaseInfoDlg::Modify()
{
	UpdateData();
	if(m_strID=="")
	{
		MessageBox("员工号不能为空，请输入员工号");
		return FALSE;
	}
	if(m_strName=="")
	{
		MessageBox("姓名不能为空，请输入姓名");
		return FALSE;
	}
	CString strSQL;
	strSQL.Format("select * from person where ID='%s'",m_strID);
	if(!m_pPersonSet->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return FALSE;
	}
	if(m_pPersonSet->GetRecordCount()==0)
	{
		MessageBox("该员工不存在！");
		m_pPersonSet->Close();
		return FALSE;
	}
	m_pPersonSet->Edit ();

//	m_pPersonSet->m_ID = m_strID;
	m_pPersonSet->m_addr = m_strAddress;
	m_pPersonSet->m_age = atoi(m_strAge);
	m_pPersonSet->m_cardID = m_strCardID;
	m_pPersonSet->m_dept_1 = m_strDept2;
	m_pPersonSet->m_dept_2 = m_strDept3;
	m_pPersonSet->m_email = m_strEMail;
	m_pPersonSet->m_mphone = m_strMobile;
	m_pPersonSet->m_name = m_strName;
	m_pPersonSet->m_native = m_strNative ;
	m_pPersonSet->m_phone = m_strPhone;
	m_pPersonSet->m_school = m_strSchool;
	m_pPersonSet->m_subject = m_strSubject ;	

	m_pPersonSet->m_aboutpay = m_strAboutPay  ;
	m_pPersonSet->m_dept = m_strDept ;
	m_pPersonSet->m_duty = m_strDuty;
	m_pPersonSet->m_education = m_strEducation  ;
	m_pPersonSet->m_folk = m_strFolk  ;
	m_pPersonSet->m_isworker = m_strIsWorker  ;
	m_pPersonSet->m_ismarry = m_strMarry ;
	m_pPersonSet->m_political = m_strPolitical ;
	m_pPersonSet->m_sex = m_strSex ;
	m_pPersonSet->m_technical = m_strTechnical  ;
	m_pPersonSet->m_birth = m_tmBirth ;
	m_pPersonSet->m_date1 = m_tmDate1 ;
	m_pPersonSet->m_date2 = m_tmDate2 ;
	m_pPersonSet->m_gdate = m_tmGDate ;
	
	m_pPersonSet->Update();

	m_pPersonSet->Close();

	return TRUE;
}

