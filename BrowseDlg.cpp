// BrowseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "BrowseDlg.h"

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
// CBrowseDlg dialog


CBrowseDlg::CBrowseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrowseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrowseDlg)
	m_strContent = _T("");
	m_strCode = _T("");
	m_strName = _T("");
	m_nCondition = -1;
	//}}AFX_DATA_INIT
	m_bNew = FALSE;
}


void CBrowseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrowseDlg)
	DDX_Control(pDX, IDC_BUTTON_CANCEL, m_ctrCancelBnt);
	DDX_Control(pDX, IDC_BUTTON_MODIFY, m_ctrModify);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_ctrSaveBnt);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_ctrNewBnt);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_ctrDelBnt);
	DDX_Control(pDX, IDC_COMBO_CONDITION, m_ctrCondition);
	DDX_Control(pDX, IDC_COMBO_CONTENT, m_ctrContent);
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	DDX_Control(pDX, IDC_TAB1, m_ctrTabSheet);
	DDX_CBString(pDX, IDC_COMBO_CONTENT, m_strContent);
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_CBIndex(pDX, IDC_COMBO_CONDITION, m_nCondition);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBrowseDlg, CDialog)
	//{{AFX_MSG_MAP(CBrowseDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_CBN_SELCHANGE(IDC_COMBO_CONDITION, OnSelchangeComboCondition)
	ON_CBN_SELCHANGE(IDC_COMBO_CONTENT, OnSelchangeComboContent)
	ON_CBN_EDITUPDATE(IDC_COMBO_CONTENT, OnEditupdateComboContent)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, OnButtonModify)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB1, OnSelchangingTab1)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrowseDlg message handlers

BOOL CBrowseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//设置员工基本档案属性页的记录集
	//实现主体对话框与属性页对话框的数据一致
	m_BaseInfoDlg.m_pPersonSet = &m_recordset;
	//建立员工列表
	m_ctrList.InsertColumn(0,"姓名");
	m_ctrList.InsertColumn(1,"员工号");
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ctrList.SetColumnWidth(0,80);
	m_ctrList.SetColumnWidth(1,80);
	//在员工列表中显示员工姓名和员工号
	CString strSQL;
	strSQL="select * from person";
	RefreshData(strSQL);
	//添加各个属性页
	m_ctrTabSheet.AddPage("基本档案", &m_BaseInfoDlg, IDD_PAGE_BASEINFO);
	m_ctrTabSheet.AddPage("家庭成员", &m_FamilyDlg, IDD_PAGE_FAMILY);
	m_ctrTabSheet.AddPage("工作经历", &m_HistoryDlg, IDD_PAGE_HISTORY);
	m_ctrTabSheet.AddPage("奖惩纪录", &m_HonorDlg, IDD_PAGE_HONOR);
	m_ctrTabSheet.AddPage("职称评定", &m_QualificationDlg, IDD_PAGE_QUALIFICATION);
	m_ctrTabSheet.AddPage("培训纪录", &m_TrainDlg, IDD_PAGE_TRAIN);
	m_ctrTabSheet.Show();
	
	return TRUE;  
}
void CBrowseDlg::RefreshData(CString strSQL)
{

	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);


	UpdateData(TRUE);

//	strSQL="select * from dept";
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}	

//	m_recordset.MoveFirst();
	int i=0;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i,m_recordset.m_name);
		m_ctrList.SetItemText(i++,1,m_recordset.m_ID);
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);
	
}

void CBrowseDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//更新当前记录信息
	int i = m_ctrList.GetSelectionMark();
	
	m_strName = m_ctrList.GetItemText(i,0);
	m_strCode = m_ctrList.GetItemText(i,1);
	m_BaseInfoDlg.m_strID = m_strCode;
	m_BaseInfoDlg.RefreshData();
	UpdateData(FALSE);
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(TRUE);
	m_ctrDelBnt.EnableWindow(TRUE);
	m_ctrSaveBnt.EnableWindow(FALSE);
	m_ctrCancelBnt.EnableWindow(FALSE);
	m_ctrModify.EnableWindow(TRUE);
	m_bNew = FALSE;

	m_BaseInfoDlg.m_ctrID.EnableWindow(FALSE);


	//更新各属性页信息
	m_FamilyDlg.RefreshData(m_strCode);
	m_HistoryDlg.RefreshData(m_strCode);
	m_HonorDlg.RefreshData(m_strCode);
	m_QualificationDlg.RefreshData(m_strCode);
//	m_RecordDlg.RefreshData(m_strCode);
	m_TrainDlg.RefreshData(m_strCode);


	*pResult = 0;
}

void CBrowseDlg::OnSelchangeComboCondition() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString strSQL;
	//清空ComboBox查询内容//////////////////////
	int nCount=m_ctrContent.GetCount();
	for(int i=0;i<nCount;i++)
	{
		m_ctrContent.DeleteString(0);
	}
	///////////////////////////////////////////

	//按照选择的查询条件，添加查询内容///////////////////////////////////
	if(0==m_nCondition)
	{//按部门查询
		CDeptSet recordset ;
		strSQL="select * from dept";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_dept);
			recordset.MoveNext();
		}
		recordset.Close();

	}
	else if(1==m_nCondition)
	{//按职工职务查询
		CDutySet recordset ;
		strSQL="select * from duty";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_duty);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	else if(2==m_nCondition)
	{//按职工职称查询
		CTechnicalSet recordset ;
		strSQL="select * from technical";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_technical);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	else if(3==m_nCondition)
	{//按职工类型查询
		CWorkerStatusSet recordset ;
		strSQL="select * from status";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_workstatus);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	else if(4==m_nCondition)
	{//按工资类别查询
		CAboutPaySet recordset ;
		strSQL="select * from aboutpay";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_aboutpay);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	else if(5==m_nCondition)
	{//按职工性别查询
		m_ctrContent.AddString("男");
		m_ctrContent.AddString("女");
	}
	else if(6==m_nCondition)
	{//按婚姻状况查询
		m_ctrContent.AddString("未婚");
		m_ctrContent.AddString("已婚");
	}
	else if(7==m_nCondition)
	{//按职工民族查询
		CFolkSet recordset ;
		strSQL="select * from folk";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_folk);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	else if(8==m_nCondition)
	{//按政治面貌查询
		CPoliticalSet recordset ;
		strSQL="select * from political";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_political);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	else if(9==m_nCondition)
	{//按文化程度查询
		CEducationSet recordset ;
		strSQL="select * from education";
		if(!recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}	
		while(!recordset.IsEOF())
		{
			m_ctrContent.AddString(recordset.m_education);
			recordset.MoveNext();
		}
		recordset.Close();
	}
	///////////////////////////////////////////////////////////////////
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(TRUE);
	m_ctrDelBnt.EnableWindow(TRUE);
	m_ctrSaveBnt.EnableWindow(FALSE);
	m_ctrCancelBnt.EnableWindow(FALSE);
	m_ctrModify.EnableWindow(TRUE);
	m_bNew = FALSE;
	m_BaseInfoDlg.m_ctrID.EnableWindow(FALSE);
}

void CBrowseDlg::OnSelchangeComboContent() 
{
	// TODO: Add your control notification handler code here
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(TRUE);
	m_ctrDelBnt.EnableWindow(TRUE);
	m_ctrSaveBnt.EnableWindow(FALSE);
	m_ctrCancelBnt.EnableWindow(FALSE);
	m_ctrModify.EnableWindow(TRUE);
	m_bNew = FALSE;
	m_BaseInfoDlg.m_ctrID.EnableWindow(FALSE);
}



void CBrowseDlg::OnEditupdateComboContent() 
{
	// TODO: Add your control notification handler code here


}



void CBrowseDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if(m_nCondition<0)
	{
		MessageBox("请选择查询条件！");
		m_ctrCondition.SetFocus();
		return;
	}
	if(m_strContent=="")
	{
		MessageBox("请输入查询内容！");
		m_ctrContent.SetFocus();
		return;
	}

	CString strSQL;
	if(0==m_nCondition)
	{//按部门查询
		strSQL.Format("select * from person where dept='%s'",m_strContent);
		RefreshData(strSQL);
	}
	else if(1==m_nCondition)
	{//按职工职务查询
		strSQL.Format("select * from person where duty='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(2==m_nCondition)
	{//按职工职称查询
		strSQL.Format("select * from person where technical='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(3==m_nCondition)
	{//按职工类型查询
		strSQL.Format("select * from person where isworker='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(4==m_nCondition)
	{//按工资类别查询
		strSQL.Format("select * from person where aboutpay='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(5==m_nCondition)
	{//按职工性别查询
		strSQL.Format("select * from person where sex='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(6==m_nCondition)
	{//按婚姻状况查询
		strSQL.Format("select * from person where ismarry='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(7==m_nCondition)
	{//按职工民族查询
		strSQL.Format("select * from person where folk='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(8==m_nCondition)
	{//按政治面貌查询
		strSQL.Format("select * from person where political='%s'",m_strContent);
		RefreshData(strSQL);

	}
	else if(9==m_nCondition)
	{//按文化程度查询
		strSQL.Format("select * from person where education='%s'",m_strContent);
		RefreshData(strSQL);

	}
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(TRUE);
	m_ctrDelBnt.EnableWindow(TRUE);
	m_ctrSaveBnt.EnableWindow(FALSE);
	m_ctrCancelBnt.EnableWindow(FALSE);
	m_bNew = FALSE;
	m_ctrModify.EnableWindow(TRUE);
	m_BaseInfoDlg.m_ctrID.EnableWindow(FALSE);

}

void CBrowseDlg::OnButtonNew() 
{
	//选择基本档案信息属性页
	m_ctrTabSheet.SetCurSel(0);
	//清空基本档案信息属性页中数据
	m_BaseInfoDlg.Clear();
	//设置基本档案信息属性页状态
	m_BaseInfoDlg.m_ctrID.EnableWindow();
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(FALSE);
	m_ctrDelBnt.EnableWindow(FALSE);
	m_ctrSaveBnt.EnableWindow(TRUE);
	m_ctrCancelBnt.EnableWindow(TRUE);
	m_ctrModify.EnableWindow(FALSE);
	m_bNew = TRUE;
}

void CBrowseDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	//保存数据到数据库中
	if(!m_BaseInfoDlg.Save())
		return;
	m_BaseInfoDlg.RefreshData();
	m_BaseInfoDlg.m_ctrID.EnableWindow(FALSE);
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(TRUE);
	m_ctrDelBnt.EnableWindow(TRUE);
	m_ctrSaveBnt.EnableWindow(FALSE);
	m_ctrCancelBnt.EnableWindow(FALSE);
	m_ctrModify.EnableWindow(TRUE);
	m_bNew = FALSE;

	//更新对话框上当前记录信息
	m_strName = m_BaseInfoDlg.m_strName;
	m_strCode = m_BaseInfoDlg.m_strID;
	UpdateData(FALSE);
	//更新列表信息
	CString strSQL;
	strSQL="select * from person";
	RefreshData(strSQL);

	//更新各属性页信息
	m_FamilyDlg.RefreshData(m_strCode);
	m_HistoryDlg.RefreshData(m_strCode);
	m_HonorDlg.RefreshData(m_strCode);
	m_QualificationDlg.RefreshData(m_strCode);
//	m_RecordDlg.RefreshData(m_strCode);
	m_TrainDlg.RefreshData(m_strCode);

	
}

void CBrowseDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i = m_ctrList.GetSelectionMark();
	if(0>i)
	{
		MessageBox("请选择一个职工进行删除！");
		return;
	}

	CString strSQL;
	strSQL.Format("select * from person where ID='%s'",m_ctrList.GetItemText(i,1));
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	//删除该用户
	m_recordset.Delete();
	m_recordset.Close();

	//更新用户列表
	strSQL = "select * from person";
	RefreshData(strSQL);
	//更新对话框上当前记录信息
	m_strCode = "";
	m_strName = "";
	UpdateData(FALSE);
	m_BaseInfoDlg.Clear();

	//更新各属性页信息
	m_FamilyDlg.RefreshData(m_strCode);
	m_HistoryDlg.RefreshData(m_strCode);
	m_HonorDlg.RefreshData(m_strCode);
	m_QualificationDlg.RefreshData(m_strCode);
//	m_RecordDlg.RefreshData(m_strCode);
	m_TrainDlg.RefreshData(m_strCode);


}

void CBrowseDlg::OnButtonModify() 
{
	// TODO: Add your control notification handler code here
	//保存数据到数据库中
	if(!m_BaseInfoDlg.Modify())
		return;
	m_BaseInfoDlg.RefreshData();
	//更新对话框上当前记录信息
	m_strName = m_BaseInfoDlg.m_strName;
	m_strCode = m_BaseInfoDlg.m_strID;
	UpdateData(FALSE);
	//更新列表信息
	CString strSQL;
	strSQL="select * from person";
	RefreshData(strSQL);
	//更新各属性页信息
	m_FamilyDlg.RefreshData(m_strCode);
	m_HistoryDlg.RefreshData(m_strCode);
	m_HonorDlg.RefreshData(m_strCode);
	m_QualificationDlg.RefreshData(m_strCode);
//	m_RecordDlg.RefreshData(m_strCode);
	m_TrainDlg.RefreshData(m_strCode);
	
}

void CBrowseDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	if(m_bNew)
	{	
		m_ctrTabSheet.SetCurSel(1);

		m_ctrTabSheet.SetCurSel(0);
		m_ctrTabSheet.UpdateWindow();
		*pResult = 0;
		return;
	}


	*pResult = 0;
}

void CBrowseDlg::OnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

void CBrowseDlg::OnButtonCancel() 
{
	//设置按钮状态
	m_ctrNewBnt.EnableWindow(TRUE);
	m_ctrDelBnt.EnableWindow(TRUE);
	m_ctrSaveBnt.EnableWindow(FALSE);
	m_ctrCancelBnt.EnableWindow(FALSE);
	m_ctrModify.EnableWindow(TRUE);
	m_bNew = FALSE;
	
}

void CBrowseDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnClose();
}

void CBrowseDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}
