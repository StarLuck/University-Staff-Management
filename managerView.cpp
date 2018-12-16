// managerView.cpp : implementation of the CManagerView class
//

#include "stdafx.h"
#include "manager.h"

#include "managerDoc.h"
#include "managerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManagerView

IMPLEMENT_DYNCREATE(CManagerView, CView)

BEGIN_MESSAGE_MAP(CManagerView, CView)
	//{{AFX_MSG_MAP(CManagerView)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagerView construction/destruction

CManagerView::CManagerView()
{
	// TODO: add construction code here

}

CManagerView::~CManagerView()
{
}

BOOL CManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CManagerView drawing

void CManagerView::OnDraw(CDC* pDC)
{
	CManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CManagerView printing

BOOL CManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CManagerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CManagerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CManagerView diagnostics

#ifdef _DEBUG
void CManagerView::AssertValid() const
{
	CView::AssertValid();
}

void CManagerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CManagerDoc* CManagerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CManagerDoc)));
	return (CManagerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CManagerView message handlers



void CManagerView::OnPaint() 
{
	CPaintDC* pDC=new CPaintDC(this); // device context for painting
	
	CBitmap bmp;	  
	RECT	Rect;
	RECT	RectView;
	POINT	ptSize;
	CDC		dcmem;
	BITMAP	bm;

	int b = bmp.LoadBitmap(IDB_BITMAP_BG);        //将位图取出；
	dcmem.CreateCompatibleDC(pDC);                //创建兼容设备上下文。
	dcmem.SelectObject(&bmp);                     //用设备上下文选择位图；
	dcmem.SetMapMode(pDC->GetMapMode());          //设置映射方式；
	GetObject(bmp.m_hObject, sizeof(BITMAP), (LPSTR)&bm); //映射位图；

	GetClientRect(&Rect);
	ptSize.x=bm.bmWidth;
	ptSize.y=bm.bmHeight;
	pDC->DPtoLP((LPPOINT)&ptSize,1);//设备单元to逻辑单元;
	
	GetClientRect(&RectView);
	CRect RectBmp = RectView;

	if((RectView.right - RectView.left) > bm.bmWidth) //位图宽度容纳不下；
	{
		RectBmp.left = RectView.left + (RectView.right - RectView.left - bm.bmWidth) / 2;
		RectBmp.right = bm.bmWidth;
	}
	else
	{
		RectBmp.left = RectView.left;
		RectBmp.right = RectView.right - RectBmp.left;
	}

	if((RectView.bottom - RectView.top) > bm.bmHeight)
	{
		RectBmp.top = RectView.top + (RectView.bottom - RectView.top - bm.bmHeight) / 2;
		RectBmp.bottom = bm.bmHeight;
	}
	else
	{
		RectBmp.top = RectView.top;
		RectBmp.bottom = RectView.bottom - RectBmp.top;
	}

	pDC->StretchBlt(RectBmp.left, RectBmp.top, RectBmp.right,\
		RectBmp.bottom, &dcmem, 0, 0, bm.bmWidth, bm.bmHeight,\
		SRCCOPY);

	dcmem.DeleteDC();
}
