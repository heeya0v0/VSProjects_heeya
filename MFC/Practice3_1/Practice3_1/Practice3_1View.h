
// Practice3_1View.h : CPractice3_1View Ŭ������ �������̽�
//

#pragma once


class CPractice3_1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice3_1View();
	DECLARE_DYNCREATE(CPractice3_1View)

// Ư���Դϴ�.
public:
	CPractice3_1Doc* GetDocument() const;

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
	virtual ~CPractice3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // Practice3_1View.cpp�� ����� ����
inline CPractice3_1Doc* CPractice3_1View::GetDocument() const
   { return reinterpret_cast<CPractice3_1Doc*>(m_pDocument); }
#endif

