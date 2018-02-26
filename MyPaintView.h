
// MyPaintView.h : интерфейс класса CMyPaintView
//

#pragma once


class CMyPaintView : public CView
{
protected: // создать только из сериализации
	CMyPaintView();
	DECLARE_DYNCREATE(CMyPaintView)

// Атрибуты
public:
	CMyPaintDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMyPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_StartPoint;        // начало некоторого элемента
	CPoint m_EndPoint;          // конец некоторого элемента
	CElement* m_pTempElement;   // для хранения некоторого элемента

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CElement* CreateElement(void);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // отладочная версия в MyPaintView.cpp
inline CMyPaintDoc* CMyPaintView::GetDocument() const
   { return reinterpret_cast<CMyPaintDoc*>(m_pDocument); }
#endif

