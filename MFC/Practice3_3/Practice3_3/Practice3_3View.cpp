
// Practice3_3View.cpp : CPractice3_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice3_3.h"
#endif

#include "Practice3_3Doc.h"
#include "Practice3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice3_3View

IMPLEMENT_DYNCREATE(CPractice3_3View, CView)

BEGIN_MESSAGE_MAP(CPractice3_3View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CPractice3_3View ����/�Ҹ�

CPractice3_3View::CPractice3_3View()
: m_strOutput(_T(""))
, m_ptLocation(0)
, m_ptClientSize(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPractice3_3View::~CPractice3_3View()
{
}

BOOL CPractice3_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice3_3View �׸���

void CPractice3_3View::OnDraw(CDC* pDC)
{
	CPractice3_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutW(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// CPractice3_3View �μ�

BOOL CPractice3_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice3_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice3_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CPractice3_3View ����

#ifdef _DEBUG
void CPractice3_3View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice3_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice3_3Doc* CPractice3_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice3_3Doc)));
	return (CPractice3_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice3_3View �޽��� ó����


void CPractice3_3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();

	if (nChar == VK_BACK)
		m_strOutput.Delete(nCharIndex - 1, 1);
	else
		m_strOutput += (WCHAR)nChar;

	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CPractice3_3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)
	{
	case VK_LEFT:
		m_ptLocation.x--;
		break;
	case VK_RIGHT:
		m_ptLocation.x++;
		break;
	case VK_UP:
		m_ptLocation.y--;
		break;
	case VK_DOWN:
		m_ptLocation.y++;
		break;
	case VK_PRIOR:
		m_ptLocation.y -= 50;
		break;
	case VK_NEXT:
		m_ptLocation.y += 50;
		break;
	case VK_HOME:
		m_ptLocation = CPoint(0, 0);
		break;

	}
	if (m_ptLocation.x < 0)
	{
		m_ptLocation.x = 0;
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptLocation.y < 0)
	{
		m_ptLocation.y = 0;
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptLocation.x > m_ptClientSize.x)
	{
		m_ptLocation.x = m_ptClientSize.x;
		AfxMessageBox(_T("���������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptLocation.y > m_ptClientSize.y)
	{
		m_ptLocation.y = m_ptClientSize.y;
		AfxMessageBox(_T("�Ʒ������� �� �̻� �̵��� �� �����ϴ�."));
	}






	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPractice3_3View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	Invalidate();
}


void CPractice3_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptLocation.x = point.x;
	m_ptLocation.y = point.y;
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CPractice3_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_strOutput.IsEmpty() == false)
	{
		if (AfxMessageBox(_T("���ڸ� ��� ����ðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
			m_strOutput.Empty();
	}
	else
	{
		AfxMessageBox(_T("���ڿ��� �Է��Ͻÿ�."));
	}

	Invalidate();


	CView::OnRButtonDown(nFlags, point);
}
