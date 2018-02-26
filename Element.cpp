// Element.cpp: ���� ����������
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

// ��������� ������������ ����������������
CRect CElement::GetBoundRect()
{
	CRect r(m_EnclosingRect);
	r.InflateRect(m_PenWidth, m_PenWidth);
	return r;
}



/*����������� ������� ��� �����*/

CLine::CLine(const CPoint& start, const CPoint& end, COLORREF elementColor, int elementWidth)
{
	m_StartPoint = start;
	m_EndPoint = end;
	m_elem�olor = elementColor;
	m_PenWidth = elementWidth;
	m_EnclosingRect = CRect(start, end);  // ����������� ���������������
	m_EnclosingRect.NormalizeRect();      // ������������
}

void CLine::Draw(CDC* pDC)
{
	CPen aPen;// ���� 
			  // ���� �� ������� ������� ����, �� ������� ��������� � ��������� ���������
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elem�olor))
	{
		AfxMessageBox(_T("�� ������� ������� ���� ��� �����"), MB_OK);
		AfxAbort();
	}

	// ��������� ������ ���� + ������� �����
	CPen* pOldPen = pDC->SelectObject(&aPen);

	// ���������� �����
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);

	// ������������ ������ ����
	pDC->SelectObject(pOldPen);
}



/*����������� ������� ��� ��������������*/
CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth)
	:m_StartPoint(start)
	, m_EndPoint(end)
{
	m_elem�olor = aColor;                              // ���� ��������
	m_PenWidth = elementWidth;                         // ������ ����
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint); // ����������� ���������������
	m_EnclosingRect.NormalizeRect();                   // ������������
}


void CRectangle::Draw(CDC* pDC)
{
	CPen aPen;//����
			  //���� �� ������� ������� ����, �� ������� ��������� � ��������� ���������
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elem�olor))
	{
		AfxMessageBox(_T("�� ������� ������� ���� ��� ��������������"), MB_OK);
		AfxAbort();
	}

	// ��������� ������ ���� � �����  + ������� �����
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	// ���������� ���������������
	pDC->Rectangle(m_EnclosingRect);

	// ������������ ������ ���� � �����
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}



/*����������� ������� ��� �������*/
CEllipse::CEllipse(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth)
	:m_StartPoint(start)
	, m_EndPoint(end)
{
	m_elem�olor = aColor;                              // ���� ��������
	m_PenWidth = elementWidth;                         // ������ ����
	m_EnclosingRect = CRect(m_StartPoint, m_EndPoint); // ����������� ���������������
	m_EnclosingRect.NormalizeRect();                   // ������������
}

void CEllipse::Draw(CDC* pDC)
{
	CPen aPen;// ����
			  // ���� �� ������� ������� ����, �� ��������� � �����
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elem�olor))
	{
		AfxMessageBox(_T("�� ������� ������� ���� ��� �����"), MB_OK);
		AfxAbort();
	}

	// ��������� ������ ���� � �����  + ������� �����
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	// ���������� ������
	pDC->Ellipse(m_EnclosingRect);

	// ������������ ������ ���� � �����
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}



/*����������� ������� ��� ������*/
CCurve::CCurve(const CPoint& p1, const CPoint& p2, COLORREF aColor, int elementWidth)
{
	m_PenWidth = elementWidth;
	m_elem�olor = aColor;
	//��������� � ������ ��� �����
	m_Points.push_back(p1);
	m_Points.push_back(p2);

	//����������� ���������������
	m_EnclosingRect = CRect(min(p1.x, p2.x),
		min(p1.y, p2.y),
		max(p1.x, p2.x),
		max(p1.y, p2.y));
	m_EnclosingRect.NormalizeRect();//������������
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
	if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_elem�olor))
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