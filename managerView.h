// managerView.h : interface of the CManagerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGERVIEW_H__150A0E70_D9A6_4FA4_9450_0A4E1C7F3EFA__INCLUDED_)
#define AFX_MANAGERVIEW_H__150A0E70_D9A6_4FA4_9450_0A4E1C7F3EFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CManagerView : public CView
{
protected: // create from serialization only
	CManagerView();
	DECLARE_DYNCREATE(CManagerView)

// Attributes
public:
	CManagerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CManagerView)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in managerView.cpp
inline CManagerDoc* CManagerView::GetDocument()
   { return (CManagerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGERVIEW_H__150A0E70_D9A6_4FA4_9450_0A4E1C7F3EFA__INCLUDED_)
