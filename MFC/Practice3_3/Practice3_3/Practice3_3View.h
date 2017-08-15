
// Practice3_3View.h : CPractice3_3View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CPractice3_3View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice3_3View();
	DECLARE_DYNCREATE(CPractice3_3View)

// Ư���Դϴ�.
public:
	CPractice3_3Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CPractice3_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutput;
	CPoint m_ptLocation;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_ptClientSize;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Practice3_3View.cpp�� ����� ����
inline CPractice3_3Doc* CPractice3_3View::GetDocument() const
   { return reinterpret_cast<CPractice3_3Doc*>(m_pDocument); }
#endif

