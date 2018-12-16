// AttLeave.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "AttLeave.h"
#include "PersonSet.h"

#include "AttDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAttLeave property page

IMPLEMENT_DYNCREATE(CAttLeave, CPropertyPage)

CAttLeave::CAttLeave() : CPropertyPage(CAttLeave::IDD)
{
	// 得到当前时间并格式化
	CTime t=CTime::GetCurrentTime();
	CString str=t.Format("%Y-%m-%d %H:%M");
	//{{AFX_DATA_INIT(CAttLeave)
	m_strSTime = str;
	m_strETime = str;
	m_strReason = _T("");
	m_strPersonID = _T("");
	m_strPersonName = _T("");
	//}}AFX_DATA_INIT
}

CAttLeave::~CAttLeave()
{
}

void CAttLeave::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAttLeave)
	DDX_Control(pDX, IDC_LIST3, m_cList);
	DDX_Text(pDX, IDC_EDT_LEAVE_STARTTIME, m_strSTime);
	DDX_Text(pDX, IDC_EDT_LEAVE_ENDTIME, m_strETime);
	DDX_Text(pDX, IDC_EDT_LEAVE_REASON, m_strReason);
	DDX_Text(pDX, IDC_EDT_LEAVE_PERSONID, m_strPersonID);
	DDX_Text(pDX, IDC_EDT_LEAVE_PERSONNAME, m_strPersonName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAttLeave, CPropertyPage)
	//{{AFX_MSG_MAP(CAttLeave)
	ON_EN_CHANGE(IDC_EDT_LEAVE_PERSONID, OnChangeEdtLeavePersonid)
	ON_BN_CLICKED(IDC_BTN_LEAVE_ADD, OnBtnLeaveAdd)
	ON_BN_CLICKED(IDC_BTN_LEAVE_DELETEATTEND, OnBtnLeaveDeleteattend)
	ON_BN_CLICKED(IDC_BTN_LEAVE_SEEKIO, OnBtnLeaveSeekio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAttLeave message handlers

void CAttLeave::OnChangeEdtLeavePersonid() 
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

BOOL CAttLeave::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// 设置列表
	int nWidth=90;
	m_cList.InsertColumn(0, "记录编号", LVCFMT_LEFT, nWidth-20);
	m_cList.InsertColumn(1, "员工号", LVCFMT_LEFT, nWidth-20);
	m_cList.InsertColumn(2, "开始时间", LVCFMT_LEFT, nWidth+20);
	m_cList.InsertColumn(3, "结束时间", LVCFMT_LEFT, nWidth+20);
	m_cList.InsertColumn(4, "缘由", LVCFMT_LEFT, nWidth);
	// 更新List	
	CLeaveSet rs; 
	UpdateList(rs); 
	m_cList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAttLeave::UpdateList(CLeaveSet &rs)
{
	int i=0;
	CString strID,strSTime,strETime;
	// 清除列表框内容
	m_cList.DeleteAllItems(); 
	rs.Open(); 
	// 对数据表中所有记录进行处理
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
		m_cList.SetItemText(i, 4, rs.m_REASON);
		rs.MoveNext(); 
		i++;
	}
	rs.Close(); 
}

void CAttLeave::OnBtnLeaveAdd() 
{

	UpdateData(); 

	// 添加记录
	int nYear,nMonth,nDay,nHour,nMinute; // 年,月,日,时,分
	// 转换起始时间类型
	sscanf(m_strSTime.Left(4), "%d", &nYear); // 得到年
	sscanf(m_strSTime.Mid(5,2), "%d", &nMonth); // 得到月
	sscanf(m_strSTime.Mid(8,2), "%d", &nDay); // 得到日
	sscanf(m_strSTime.Mid(11,2), "%d", &nHour); // 得到时
	sscanf(m_strSTime.Mid(14,2), "%d", &nMinute); // 得到分
	// 得到起始时间
	CTime S_time(nYear,nMonth,nDay,nHour,nMinute,0);
	// 转换结束时间类型
	sscanf(m_strETime.Left(4), "%d", &nYear); // 得到年
	sscanf(m_strETime.Mid(5,2), "%d", &nMonth); // 得到月
	sscanf(m_strETime.Mid(8,2), "%d", &nDay); // 得到日
	sscanf(m_strETime.Mid(11,2), "%d", &nHour); // 得到时
	sscanf(m_strETime.Mid(14,2), "%d", &nMinute); // 得到分
	// 得到结束时间
	CTime E_time(nYear,nMonth,nDay,nHour,nMinute,0);
	// 添加请假记录
	CLeaveSet rs_leave; 
	rs_leave.Open(); 
	rs_leave.AddNew(); 
	rs_leave.m_PERSON=m_strPersonID;
	rs_leave.m_START_TIME=S_time;
	rs_leave.m_END_TIME=E_time;
	rs_leave.m_REASON=m_strReason;
	rs_leave.Update();
	rs_leave.Close(); 
	// 更新列表
	UpdateList(rs_leave); 

}
	



void CAttLeave::OnBtnLeaveDeleteattend() 
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
	CLeaveSet rs; 
	while(pos) // 遍历所有被选Item
	{
		nItem=m_cList.GetNextSelectedItem(pos); 
		// 构造SQL语句
		strSQL="select * from LEAVE where ID=" + m_cList.GetItemText(nItem, 0);
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

void CAttLeave::OnBtnLeaveSeekio() 
{
	CLeaveSet rs; 

	CAttDlg *pDlg; 
	CString strFilter; 
	CString strSTime,strETime; 
	// 更新用户输入查询条件数据
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
		strFilter += "END_TIME>" + strSTime ; 
		strFilter += " and START_TIME<" + strETime ; 
	}
	if(strFilter.GetLength()>0) 
		rs.m_strFilter=strFilter; 
	// 更新列表
	UpdateList(rs); 
}
