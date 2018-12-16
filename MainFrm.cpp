// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "manager.h"

#include "MainFrm.h"

#include "UserDlg.h"
#include "LoginDlg.h"
#include "FolkDlg.h"
#include "WorkerStatusDlg.h"
#include "EducationDlg.h"
#include "PoliticalDlg.h"
#include "DeptDlg.h"
#include "AboutPayDlg.h"
#include "DutyDlg.h"
#include "TechnicalDlg.h"

#include "BrowseDlg.h"
#include "SearchDlg.h"
#include "StatDlg.h"

#include "AttDlg.h"
#include "AttStatDlg.h"
#include "WorkplanDlg.h"

#include "notepaddlg.h"
#include "AddrBookDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_SYS_DEPTYPE, OnSysDeptype)
	ON_COMMAND(ID_SYS_FOLK, OnSysFolk)
	ON_COMMAND(ID_SYS_KNOWLEAGE, OnSysKnowleage)
	ON_COMMAND(ID_SYS_POLITY, OnSysPolity)
	ON_COMMAND(ID_SYS_POST, OnSysPost)
	ON_COMMAND(ID_SYS_QUIT, OnSysQuit)
	ON_COMMAND(ID_SYS_RELOAD, OnSysReload)
	ON_COMMAND(ID_SYS_SALARY, OnSysSalary)
	ON_COMMAND(ID_SYS_SET, OnSysSet)
	ON_COMMAND(ID_SYS_TECH, OnSysTech)
	ON_COMMAND(ID_SYS_USER, OnSysUser)
	ON_COMMAND(ID_SYS_WORKERTYPE, OnSysWorkertype)
	ON_COMMAND(ID_PER_BROWSE, OnPerBrowse)
	ON_COMMAND(ID_PER_SEARCH, OnPerSearch)
	ON_COMMAND(ID_PER_SUM, OnPerSum)
	ON_COMMAND(ID_MEMO_NOTEPAD, OnMemoNotepad)
	ON_COMMAND(ID_MEMO_BOOK, OnMemoBook)
	ON_WM_CLOSE()
	ON_UPDATE_COMMAND_UI(ID_SYS_DEPTYPE, OnUpdateSysDeptype)
	ON_UPDATE_COMMAND_UI(ID_SYS_FOLK, OnUpdateSysFolk)
	ON_UPDATE_COMMAND_UI(ID_SYS_KNOWLEAGE, OnUpdateSysKnowleage)
	ON_UPDATE_COMMAND_UI(ID_SYS_POLITY, OnUpdateSysPolity)
	ON_UPDATE_COMMAND_UI(ID_SYS_POST, OnUpdateSysPost)
	ON_UPDATE_COMMAND_UI(ID_SYS_SALARY, OnUpdateSysSalary)
	ON_UPDATE_COMMAND_UI(ID_SYS_TECH, OnUpdateSysTech)
	ON_UPDATE_COMMAND_UI(ID_SYS_USER, OnUpdateSysUser)
	ON_UPDATE_COMMAND_UI(ID_SYS_WORKERTYPE, OnUpdateSysWorkertype)
	ON_UPDATE_COMMAND_UI(ID_PER_SUM, OnUpdatePerSum)
	ON_UPDATE_COMMAND_UI(ID_PER_BROWSE, OnUpdatePerBrowse)
	ON_COMMAND(ID_ATT_RECORD, OnAttRecord)
	ON_UPDATE_COMMAND_UI(ID_ATT_RECORD, OnUpdateAttRecord)
	ON_COMMAND(ID_ATT_STAT, OnAttStat)
	ON_UPDATE_COMMAND_UI(ID_ATT_STAT, OnUpdateAttStat)
	ON_COMMAND(ID_DATABASE_BACKUP, OnDatabaseBackup)
	ON_UPDATE_COMMAND_UI(ID_DATABASE_BACKUP, OnUpdateDatabaseBackup)
	ON_COMMAND(ID_DATABASE_RECOVER, OnDatabaseRecover)
	ON_UPDATE_COMMAND_UI(ID_DATABASE_RECOVER, OnUpdateDatabaseRecover)
	ON_COMMAND(ID_ATT_SET, OnAttSet)
	ON_UPDATE_COMMAND_UI(ID_ATT_SET, OnUpdateAttSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSysDeptype() 
{
	// TODO: Add your command handler code here
	CDeptDlg	Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysFolk() 
{
	// TODO: Add your command handler code here
	CFolkDlg	Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysKnowleage() 
{
	// TODO: Add your command handler code here
	CEducationDlg	Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysPolity() 
{
	// TODO: Add your command handler code here
	CPoliticalDlg   Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysPost() 
{
	// TODO: Add your command handler code here
	CDutyDlg   Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysQuit() 
{//退出系统
	// TODO: Add your command handler code here
	CFrameWnd::OnClose();
}

void CMainFrame::OnSysReload() 
{//重新登录
	// TODO: Add your command handler code here
	CLoginDlg Dlg;
	int nRes=0;
	do
	{
		nRes=Dlg.DoModal();
		//回到主界面
		if(nRes==IDOK)
			return;
		//退出系统
		if(nRes==IDCANCEL)
		{
			if(AfxMessageBox("您确定要退出系统吗?",MB_OKCANCEL)==IDCANCEL)
			{
				return;
			}		
			CFrameWnd::OnClose();
			return;
		}
	}while(1);
}

void CMainFrame::OnSysSalary() 
{
	// TODO: Add your command handler code here
	CAboutPayDlg	Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysSet() 
{
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnSysTech() 
{
	// TODO: Add your command handler code here
	CTechnicalDlg	Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnSysUser() 
{
	// TODO: Add your command handler code here
	CUserDlg  UserDlg;
	UserDlg.DoModal();
}

void CMainFrame::OnSysWorkertype() 
{
	// TODO: Add your command handler code here
	CWorkerStatusDlg Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnPerBrowse() 
{
	// TODO: Add your command handler code here
	CBrowseDlg Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnPerSearch() 
{
	// TODO: Add your command handler code here
	CSearchDlg  Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnPerSum() 
{
	// TODO: Add your command handler code here
	CStatDlg	Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnMemoNotepad() 
{
	// TODO: Add your command handler code here
	CNotePadDlg  Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnMemoBook() 
{
	// TODO: Add your command handler code here
	CAddrBookDlg  Dlg;
	Dlg.DoModal();
}

void CMainFrame::OnClose() 
{
    if(AfxMessageBox("您确定要退出系统吗?",MB_OKCANCEL)==IDCANCEL)
	{
		return;
	}		
	CFrameWnd::OnClose();
}

void CMainFrame::OnUpdateSysDeptype(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);
}

void CMainFrame::OnUpdateSysFolk(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysKnowleage(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysPolity(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysPost(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysSalary(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysTech(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysUser(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdateSysWorkertype(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnUpdatePerSum(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnUpdatePerBrowse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}

void CMainFrame::OnAttRecord() 
{
	// TODO: Add your command handler code here
	CAttDlg Dlg;
	Dlg.DoModal();

}

void CMainFrame::OnUpdateAttRecord(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);		
}

void CMainFrame::OnAttStat() 
{
	// TODO: Add your command handler code here
	CAttStatDlg Dlg;
	Dlg.DoModal();	
}

void CMainFrame::OnUpdateAttStat(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnDatabaseBackup() 
{
	// TODO: Add your command handler code here
	if(AfxMessageBox("您确定要备份数据库吗?",MB_OKCANCEL)==IDCANCEL) 
	{ 
		return; 
	}   
	if(CopyFile(".\\manager.mdb",".\\backup\\manager.bak",FALSE)) 
		AfxMessageBox("数据库备份成功！"); 
	else 
		AfxMessageBox("数据库备份失败！"); 
	
}

void CMainFrame::OnUpdateDatabaseBackup(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);		
}

void CMainFrame::OnDatabaseRecover() 
{
	// TODO: Add your command handler code here
	if(AfxMessageBox("还原数据库将覆盖原来的数据库。您确定要还原吗?",MB_OKCANCEL)==IDCANCEL) 
	{ 
		return; 
	}   
	if(CopyFile(".\\backup\\manager.bak",".\\manager.mdb",FALSE)) 
		AfxMessageBox("数据库还原成功！"); 
	else 
		AfxMessageBox("数据库还原失败！");  
	
}

void CMainFrame::OnUpdateDatabaseRecover(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);		
}

void CMainFrame::OnAttSet() 
{
	// TODO: Add your command handler code here
	CWorkplanDlg Dlg;
	Dlg.DoModal();	
}

void CMainFrame::OnUpdateAttSet(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CManagerApp*  ptheApp = (CManagerApp *) AfxGetApp();
	pCmdUI->Enable(ptheApp->m_bIsAdmin);	
}
