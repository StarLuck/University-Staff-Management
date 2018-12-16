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

	//添加部门类别
	CString strSQL;
	CDeptSet DeptSet ;
	strSQL="select * from dept";
	if(!DeptSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!DeptSet.IsEOF())
	{
		m_ctrDepartment.AddString(DeptSet.m_dept);
		DeptSet.MoveNext();
	}
	DeptSet.Close();
	// 设置出入情况
	((CButton*)GetDlgItem(IDC_RADIO_OUT))->SetCheck(TRUE);
	//创建列表
	int nWidth=110;
	m_cList.InsertColumn(0, "记录编号", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(1, "员工号", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(2, "出入情况", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(3, "时间", LVCFMT_LEFT, nWidth);
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//在列表中显示数据
	CAttendanceSet rs; 
	UpdateList(rs); 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


// 添加出勤记录
void CAttWork::AddRecord(CString strPersonID)
{
	CString strIO; 
	// 判断确定出入情况
	if(((CButton*)GetDlgItem(IDC_RADIO_OUT))->GetCheck())
		strIO="OUT";
	else strIO="IN";
	int nYear,nMonth,nDay,nHour,nMinute; // 年,月,日,时,分
	sscanf(m_strIOTime.Left(4), "%d", &nYear); // 得到年
	sscanf(m_strIOTime.Mid(5,2), "%d", &nMonth); // 得到月
	sscanf(m_strIOTime.Mid(8,2), "%d", &nDay); // 得到日
	sscanf(m_strIOTime.Mid(11,2), "%d", &nHour); // 得到时
	sscanf(m_strIOTime.Mid(14,2), "%d", &nMinute); // 得到分
	CTime IO_time(nYear,nMonth,nDay,nHour,nMinute,0);
	// 添加记录
	CAttendanceSet rs; 
	rs.Open(); 
	rs.AddNew(); 
	rs.m_PERSON=strPersonID;
	rs.m_IN_OUT=strIO;
	rs.m_IO_TIME=IO_time;
	rs.Update();
	rs.Close(); 
}
// 添加单个员工考勤记录
void CAttWork::OnBtnAddperson() 
{
	UpdateData();
	// 判断员工是否存在
	if(m_strPersonID.IsEmpty()) 
	{
		AfxMessageBox("请选择一个员工号");
		return;
	}
	//添加单个员工考勤记录
	AddRecord(m_strPersonID); 
	CAttendanceSet rs; 
	UpdateList(rs); 
}
//添加部门员工考勤记录
void CAttWork::OnBtnAdddepart() 
{

	CPersonSet personSet; 
	// 判断部门是否输入
	if(m_strDepartment.IsEmpty()) 
	{
		AfxMessageBox("请选择一个部门");
		return; 
	}
	// 打开员工信息表
	personSet.m_strFilter.Format("dept='%s'",m_strDepartment);
	personSet.Open(); 
	// 添加出勤记录
	while(!personSet.IsEOF()) 
	{
		AddRecord(personSet.m_ID); 
		personSet.MoveNext(); 
	}
	personSet.Close(); 
	CAttendanceSet rs; 
	// 更新列表
	UpdateList(rs); 
}
// 添加所有员工出勤记录
void CAttWork::OnBtnAddall() 
{
	CPersonSet personSet; 
	// 打开员工信息表
	personSet.Open(); 
	// 添加当前员工出勤记录
	while(!personSet.IsEOF()) 
	{
		AddRecord(personSet.m_ID); 
		personSet.MoveNext(); 
	}
	personSet.Close(); 
	CAttendanceSet rs; 
	// 更新列表
	UpdateList(rs); 
}
// 更新列表内容
void CAttWork::UpdateList(CAttendanceSet& rs) 
{
	// 清除列表框内容
	m_cList.DeleteAllItems(); 
	int i=0;
	CString strID,strTime;
	rs.Open(); 
	// 对数据表中所有记录进行处理
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
// 删除出勤记录列表中所选记录
void CAttWork::OnBtnDeleteattend() 
{
	// 得到第一个被选择Item的位置
	int nItem = m_cList.GetSelectionMark();
	if(nItem<0)
	{
		AfxMessageBox("没有选择记录!");
		return;
	}
	CAttendanceSet rs; 
	// 构造SQL语句
	CString strSQL="select * from attendance where ID="
		+ m_cList.GetItemText(nItem, 0);
	if(!rs.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该用户
	rs.Delete();
	rs.Close();
	// 更新列表
	UpdateList(rs); 
}

void CAttWork::OnBtnSearch() 
{
	CAttendanceSet rs; 

	CAttDlg *pDlg; 
	CString strFilter; 
	CString strSTime,strETime; 
	// 更新查询条件数据
	pDlg=(CAttDlg*)GetParent()->GetParent(); 
	pDlg->UpdateData(); 

	strSTime=pDlg->m_StartTime.Format("%Y-%m-%d");
	strETime=pDlg->m_EndTime.Format("%Y-%m-%d");
	// 添加过滤条件
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
	// 更新列表
	UpdateList(rs); 
}


//在员工工号下拉列表中添加数据
void CAttWork::OnSetfocusComboPersonid() 
{
	UpdateData();
	//清空ComboBox查询内容
	int nCount=m_ctrPersonID.GetCount();
	for(int i=0;i<nCount;i++)
	{
		m_ctrPersonID.DeleteString(0);
	}

	CString strSQL;
	//添加员工工号
	CPersonSet PersonSet ;
	strSQL.Format("select * from person where dept='%s'",m_strDepartment);
	if(!PersonSet.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);

	}	
	while(!PersonSet.IsEOF())
	{
		m_ctrPersonID.AddString(PersonSet.m_ID);
		PersonSet.MoveNext();
	}
	PersonSet.Close();		
}
