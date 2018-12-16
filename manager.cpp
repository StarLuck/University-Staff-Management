// manager.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "manager.h"

#include "MainFrm.h"
#include "managerDoc.h"
#include "managerView.h"
#include "LoginDlg.h"
#include ".\skins\SkinPlusPlus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManagerApp

BEGIN_MESSAGE_MAP(CManagerApp, CWinApp)
	//{{AFX_MSG_MAP(CManagerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagerApp construction

CManagerApp::CManagerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_bIsAdmin = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CManagerApp object

CManagerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CManagerApp initialization

BOOL CManagerApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
/************************************************************************/
//	     函数功能说明:实现ODBC数据源的自动安装;
/*             SQLConfigDataSource()的具体用法说明
  1.     HWND hwndParent:调用ConfigDataSource的窗口句柄
         若hwndParent取值为:m_pMainWnd->m_hWnd,则在App启动的时候弹出
		 创建数据源的对话框要求用户自己添加数据源
		 若若hwndParent取值为:NULL,则系统自动的创建数据源,
		 不会弹出创建数据源的对话框;
  2.     WORD      fRequest:
         ODBC_ADD_DSN :添加用户数据源
         ODBC_ADD_SYS_DSN:添加系统用户数据源
  3.     第三个参数:驱动程序的描叙
  4.     数据库的具体属性
                
/************************************************************************/
	SQLConfigDataSource(NULL,ODBC_ADD_DSN,
		"Microsoft Access Driver (*.mdb)",
		"DSN=Manager\0"
		"Description=Hotel\0"
        "FileType=Access\0"
        "DBQ=.\\Manager.mdb\0"
		               );
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)
	InitializeSkin(_T("XPCorona.ssk"));

	
	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.
	CLoginDlg loginDlg;
	if(loginDlg.DoModal()!=IDOK)
		return FALSE;

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CManagerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CManagerView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->SetWindowText("XXX企业人事管理系统");
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CManagerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CManagerApp message handlers

