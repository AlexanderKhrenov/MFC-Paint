// Element.cpp: файл реализации
//

#include "stdafx.h"
#include "MyPaint.h"
#include "Element.h"


// CElement



CElement::CElement()
{

}

CElement::~CElement()
{

}

// получение описывающего четырехугольника
CRect CElement::GetBoundRect()
{
	CRect r(m_EnclosingRect);
	r.InflateRect(m_PenWidth, m_PenWidth);
	return r;
}



/*определение функций для линии*/

CLine::CLine(const CPoint& start, const CPoint& end, COLORREF elementColor, int elementWidth)
{
	m_StartPoint = start;
	m_EndPoint = end;
	m_elemСolor = elementColor;
	m_PenWidth = elementWidth;
	m_EnclosingRect = CRect(start, end);  // описывающий четырехугольник
	m_EnclosingRect.NormalizeRect();      // нормализация
}

void CLine::Draw(CDC* pDC)
{
	CPen aPen;// перо 
			  // если не удалось создать перо, то выводим сообщение и закрываем программу
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elemСolor))
	{
		AfxMessageBox(_T("Не удалось создать перо для линии"), MB_OK);
		AfxAbort();
	}

	// запомнить старое перо + выбрать новое
	CPen* pOldPen = pDC->SelectObject(&aPen);

	// нарисовать линию
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);

	// восстановить старое перо
	pDC->SelectObject(pOldPen);
}



/*определение функций для прямоугольника*/
CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth)
	:m_StartPoint(start)
	, m_EndPoint(end)
{
	m_elemСolor = aColor;                              // цвет элемента
	m_PenWidth = elementWidth;                         // ширина пера
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint); // описывающий четырехугольник
	m_EnclosingRect.NormalizeRect();                   // нормализация
}


void CRectangle::Draw(CDC* pDC)
{
	CPen aPen;//перо
			  //если не удалось создать перо, то выводим сообщение и закрываем программу
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elemСolor))
	{
		AfxMessageBox(_T("Не удалось создать перо для прямоугольника"), MB_OK);
		AfxAbort();
	}

	// запомнить старые перо и кисть  + выбрать новые
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	// нарисовать четырехугольник
	pDC->Rectangle(m_EnclosingRect);

	// восстановить старые перо и кисть
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}



/*определение функций для эллипса*/
CEllipse::CEllipse(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth)
	:m_StartPoint(start)
	, m_EndPoint(end)
{
	m_elemСolor = aColor;                              // цвет элемента
	m_PenWidth = elementWidth;                         // ширина пера
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint); // описывающий четырехугольник
	m_EnclosingRect.NormalizeRect();                   // нормализация
}

void CEllipse::Draw(CDC* pDC)
{
	CPen aPen;// перо
			  // если не удалось создать перо, то сообщение и выход
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elemСolor))
	{
		AfxMessageBox(_T("не удалось создать перо для круга"), MB_OK);
		AfxAbort();
	}

	// запомнить старые перо и кисть  + выбрать новые
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	// нарисовать эллипс
	pDC->Ellipse(m_EnclosingRect);

	// восстановить старые перо и кисть
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}



/*определение функций для кривой*/
CCurve::CCurve(const CPoint& p1, const CPoint& p2, COLORREF aColor, int elementWidth)
{
	m_PenWidth = elementWidth;
	m_elemСolor = aColor;
	//добавляем в массив две точки
	m_Points.push_back(p1);
	m_Points.push_back(p2);

	//описывающий четырехугольник
	m_EnclosingRect = CRect(min(p1.x, p2.x),
		min(p1.y, p2.y),
		max(p1.x, p2.x),
		max(p1.y, p2.y));
	m_EnclosingRect.NormalizeRect();//нормализация
}

void CCurve::AddSegment(const CPoint& point)
{
	m_Points.push_back(point);

	m_EnclosingRect = CRect(min(m_EnclosingRect.left, point.x),
		min(m_EnclosingRect.top, point.y),
		max(m_EnclosingRect.right, point.x),
		max(m_EnclosingRect.bottom, point.y));
}

void CCurve::Draw(CDC* pDC)
{
	CPen aPen;
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elemСolor))
	{
		AfxMessageBox(_T(""), MB_OK);
		AfxAbort();
	}

	CPen* pOldPen = pDC->SelectObject(&aPen);

	pDC->MoveTo(m_Points[0]);
	for (int i = 1; i<m_Points.size(); ++i)
		pDC->LineTo(m_Points[i]);

	pDC->SelectObject(pOldPen);
}