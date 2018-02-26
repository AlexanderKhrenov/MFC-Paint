#pragma once
#include <cmath>
#include <vector>
using std::vector;

// CElement - ������� ����

class CElement : public CObject
{
protected:
	int m_PenWidth;                // ������ ����
	COLORREF m_elem�olor;          // ���� ������
	CRect m_EnclosingRect;         // ����������� ���������������

public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC) {};// ��� ��������� ������
	virtual CRect GetBoundRect();  // ��������� ������������ ����������������
protected:
	CElement();                    // �������������� ������ � �������
};


// ���� ��� �����
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


// ���� ��� ��������������
class CRectangle :
	public CElement
{
protected:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
public:
	virtual void Draw(CDC* pDC);//������� ���������
	CRectangle(const CPoint& start, const CPoint& end, COLORREF aColor, int elementWidth);
protected:
	CRectangle(void);
};


// ���� ��� �������
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
	CEllipse(void);//������ ������
};


// ���� ��� �������
class CCurve :
	public CElement
{
protected:
	vector<CPoint> m_Points;              // ������ � �������
public:
	virtual void Draw(CDC* pDC);
	void AddSegment(const CPoint& point); // ��������� ����� � �������
	CCurve(const CPoint& p1, const CPoint& p2, COLORREF aColor, int eWidth);
protected:
	CCurve(void);
};