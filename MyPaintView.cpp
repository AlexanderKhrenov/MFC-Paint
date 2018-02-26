
// MyPaintView.cpp : реализация класса CMyPaintView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MyPaint.h"
#endif

#include "MyPaintDoc.h"
#include "MyPaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyPaintView

IMPLEMENT_DYNCREATE(CMyPaintView, CView)

BEGIN_MESSAGE_MAP(CMyPaintView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// создание/уничтожение CMyPaintView

CMyPaintView::CMyPaintView() 
	: m_StartPoint(0)
    , m_EndPoint(0)
    , m_pTempElement(nullptr)
{
	// TODO: добавьте код создания

}

CMyPaintView::~CMyPaintView()
{
}

BOOL CMyPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMyPaintView

void CMyPaintView::OnDraw(CDC* /*pDC*/)
{
	CMyPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// печать CMyPaintView

BOOL CMyPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMyPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMyPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMyPaintView

#ifdef _DEBUG
void CMyPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CMyPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyPaintDoc* CMyPaintView::GetDocument() const 
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyPaintDoc)));
	return (CMyPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMyPaintView
CElement* CMyPaintView::CreateElement(void)
{
	CMyPaintDoc* pDoc = GetDocument(); // указатель на класс документа
	switch (pDoc->GetElementType())
	{
	case LINE:
		return new CLine(m_StartPoint, m_EndPoint, pDoc->GetElementColor(), pDoc->GetElementWidth());
	case RECTANGLE:
		return new CRectangle(m_StartPoint, m_EndPoint, pDoc->GetElementColor(), pDoc->GetElementWidth());
	case ELLIPSE:
		return new CEllipse(m_StartPoint, m_EndPoint, pDoc->GetElementColor(), pDoc->GetElementWidth());
	case CURVE:
		return new CCurve(m_StartPoint, m_EndPoint, pDoc->GetElementColor(), pDoc->GetElementWidth());
	default:
		AfxMessageBox(_T("не известный обьект, не удалось создать [CreateElement]"), MB_OK);
		AfxAbort();
	}
}

void CMyPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// перехват всех сообщений
	SetCapture(); 
	m_StartPoint = point;
}

void CMyPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC aDC(this);
	
	if ((nFlags&MK_LBUTTON) && (this == GetCapture()))
	{
		m_EndPoint = point;
		
		// если элемент уже существует - нужно очистить память
		if (m_pTempElement != nullptr)
		{
			// если рисуем кривую
			if (CURVE == GetDocument()->GetElementType()) 
			{
				// добавляем точку к временному элементу
				static_cast<CCurve*>(m_pTempElement)->AddSegment(m_EndPoint);
				m_pTempElement->Draw(&aDC);               // перерисовываем элемент
				return;
			}

			aDC.SetROP2(R2_NOTXORPEN);  
			m_pTempElement->Draw(&aDC); 
			delete m_pTempElement;   
			m_pTempElement = nullptr;
		}
		
		// рисование элемента
		m_pTempElement = CreateElement();
		m_pTempElement->Draw(&aDC);
	}
}

void CMyPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_pTempElement != nullptr)
	{
		ReleaseCapture();           // освободить мышь
		delete m_pTempElement;      // освобождить память
		m_pTempElement = nullptr;   // обнулить указатель
	}
}



