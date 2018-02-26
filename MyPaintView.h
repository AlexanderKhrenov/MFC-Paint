
// MyPaintView.h : ��������� ������ CMyPaintView
//

#pragma once


class CMyPaintView : public CView
{
protected: // ������� ������ �� ������������
	CMyPaintView();
	DECLARE_DYNCREATE(CMyPaintView)

// ��������
public:
	CMyPaintDoc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CMyPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_StartPoint;        // ������ ���������� ��������
	CPoint m_EndPoint;          // ����� ���������� ��������
	CElement* m_pTempElement;   // ��� �������� ���������� ��������

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CElement* CreateElement(void);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ���������� ������ � MyPaintView.cpp
inline CMyPaintDoc* CMyPaintView::GetDocument() const
   { return reinterpret_cast<CMyPaintDoc*>(m_pDocument); }
#endif

