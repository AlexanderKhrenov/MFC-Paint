#pragma once
#include <cmath>
#include <vector>
using std::vector;

// CElement - базовый клас

class CElement : public CObject
{
protected:
	int m_PenWidth;                // ширина пера
	COLORREF m_elemСolor;          // цвет фигуры
	CRect m_EnclosingRect;         // описывающий четырехугольник

public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC) {};// для рисования фигуры
	virtual CRect GetBoundRect();  // получение описывающего четырехугольника
protected:
	CElement();                    // предотвращение вызова в предках
};


// клас для линии
class CLine :
	public CElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;

public:
	virtual void Draw(CDC* pDC);
	CLine(const CPoint& start, const CPoint& end, COLORREF elementColor, int elementWidth);
protected:
	CLine();
};


// клас для прямоугольника
class CRectangle :
	public CElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
public:
	virtual void Draw(CDC* pDC);//функция рисования
	CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth);
protected:
	CRectangle(void);
};


// клас для эллипса
class CEllipse :
	public CElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
public:
	virtual void Draw(CDC* pDC);
	CEllipse(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth);
protected:
	CEllipse(void);//запрет вызова
};


// клас для ластика
class CCurve :
	public CElement
{
protected:
	vector<CPoint> m_Points;              // вектор с точками
public:
	virtual void Draw(CDC* pDC);
	void AddSegment(const CPoint& point); // добавляет точку к вектору
	CCurve(const CPoint& p1, const CPoint& p2, COLORREF aColor, int eWidth);
protected:
	CCurve(void);
};