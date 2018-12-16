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
	// 判断员工号是否正确
	if(m_strPersonName.IsEmpty()) 
	{
		AfxMessageBox("请输入员工号！");
		return; 
	}

	// 添加记录
	COvertimeSet rs_overtime; 
	rs_overtime.Open(); 
	rs_overtime.AddNew(); 

	rs_overtime.m_PERSON=m_strPersonID;
	rs_overtime.m_WORK_HOURS=m_nHour;
	rs_overtime.m_WORK_DATE=m_Date;
	rs_overtime.Update(); 
	rs_overtime.Close(); 
	// 更新列表框
	UpdateList(rs_overtime); 
}

BOOL CAttOvertime::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// 创建加班记录列表
	int nWidth=110;
	m_cList.InsertColumn(0, "记录编号", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(1, "员工号", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(2, "加班时间", LVCFMT_LEFT, nWidth);
	m_cList.InsertColumn(3, "加班日期", LVCFMT_LEFT, nWidth);
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// 更新列表
	COvertimeSet rs; 
	UpdateList(rs); 	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAttOvertime::UpdateList(COvertimeSet &rs)
{
	int i=0;
	CString strID,strWorkHours,strTime;
	// 清除列表框内容
	m_cList.DeleteAllItems(); 
	// 对数据表中所有记录进行处理
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
	// 得到第一个被选择Item的位置
	POSITION pos = m_cList.GetFirstSelectedItemPosition();
	
	if(pos==NULL)
	{
		AfxMessageBox("没有选择记录!");
		return;
	}
	COvertimeSet rs; 
	// 遍历所有被选Item
	while(pos) 
	{
		nItem=m_cList.GetNextSelectedItem(pos); 
		// 构造SQL语句
		strSQL="select * from OVERTIME where ID=" + m_cList.GetItemText(nItem, 0);
		if(!rs.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}
		//删除该用户
		rs.Delete();
		rs.Close();

	}
	// 更新列表框
	UpdateList(rs); 
}

void CAttOvertime::OnBtnOvertimeSeekio() 
{
	COvertimeSet rs; 

	CAttDlg *pDlg; 
	CString strFilter; 
	CString strSTime,strETime; 
	// 更新用户输入的查询条件
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
		strFilter += "WORK_DATE>" + strSTime ; 
		strFilter += " and WORK_DATE<" + strETime ;
 
	}
	if(strFilter.GetLength()>0) 
		rs.m_strFilter=strFilter; 
	// 更新列表框
	UpdateList(rs); 
}
