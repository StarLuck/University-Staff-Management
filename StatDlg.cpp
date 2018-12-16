// StatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "manager.h"
#include "StatDlg.h"
#include "PersonSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatDlg dialog


CStatDlg::CStatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatDlg)
	//}}AFX_DATA_INIT
}


void CStatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatDlg)
	DDX_Control(pDX, IDC_LIST2, m_ctrResult);
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatDlg, CDialog)
	//{{AFX_MSG_MAP(CStatDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatDlg message handlers

BOOL CStatDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_ctrList.InsertColumn(0,"统计类别");
	m_ctrList.SetColumnWidth(0,125);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrList.InsertItem(0,"按性别统计");
	m_ctrList.InsertItem(1,"按年龄统计");
	m_ctrList.InsertItem(2,"按民族统计");
	m_ctrList.InsertItem(3,"按籍贯统计");
	m_ctrList.InsertItem(4,"按职务统计");
	m_ctrList.InsertItem(5,"按职称统计");
	m_ctrList.InsertItem(6,"按文化程度统计");
	m_ctrList.InsertItem(7,"按政治面貌统计");
	m_ctrList.InsertItem(8,"按部门统计");
	m_ctrList.InsertItem(9,"按职工类型统计");
	m_ctrList.InsertItem(10,"按工资类型统计");
	m_ctrList.InsertItem(11,"按婚姻状况统计");


	m_ctrResult.InsertColumn(0,"");
	m_ctrResult.SetColumnWidth(0,100);
	m_ctrResult.InsertColumn(1,"");
	m_ctrResult.SetColumnWidth(1,100);

	m_ctrResult.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStatDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	CString strValue="0";

	CDatabase db;
	db.Open(_T("Manager"));
	CRecordset recordset(&db);

	UpdateData(TRUE);
	//获得统计类型
	int nType = m_ctrList.GetSelectionMark();
	int i=0;
	switch(nType)
	{
	case 0://按性别统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		
		m_ctrResult.InsertColumn(0,"性别");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,sex from person group by sex";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("sex",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	

		break;
	case 1://按年龄统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);
		
		m_ctrResult.InsertColumn(0,"年龄");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,age from person group by age";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("age",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 2://按民族统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"民族");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,folk from person group by folk";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("folk",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 3://按籍贯统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"籍贯");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,native from person group by native";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("native",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 4://按职务类别统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"职务");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,duty from person group by duty";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("duty",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 5://按职称类别统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"职称");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,technical from person group by technical";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("technical",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 6://按文化程度统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"文化程度");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,education from person group by education";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("education",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 7://按政治面貌统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"政治面貌");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,political from person group by political";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("political",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 8://按所在部门统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"部门");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,dept from person group by dept";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("dept",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 9://按职工类型统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"职工类型");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,isworker from person group by isworker";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("isworker",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;
	case 10://按工资类型统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"工资类型");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,aboutpay from person group by aboutpay";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("aboutpay",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;

	case 11://按婚姻状况统计
		m_ctrResult.DeleteAllItems();
		m_ctrResult.DeleteColumn(1);
		m_ctrResult.DeleteColumn(0);

		m_ctrResult.InsertColumn(0,"婚姻状况");
		m_ctrResult.InsertColumn(1,"人数");
		m_ctrResult.SetColumnWidth(0,100);
		m_ctrResult.SetColumnWidth(1,100);
		strSQL="select count(ID) as num ,ismarry from person group by ismarry";
		if(!recordset.Open(CRecordset::forwardOnly,strSQL))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		while(!recordset.IsEOF())
		{	
			recordset.GetFieldValue("ismarry",strValue);
			m_ctrResult.InsertItem(i,strValue);
			recordset.GetFieldValue("num",strValue);
			m_ctrResult.SetItemText(i,1,strValue);
			i++;
			recordset.MoveNext();
		}
		recordset.Close();	
		break;

	default:
		return;
	}

	UpdateData(FALSE);	
	*pResult = 0;
}
