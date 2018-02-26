
// MyPaintDoc.h : интерфейс класса CMyPaintDoc
//


#pragma once


class CMyPaintDoc : public CDocument
{
protected: // создать только из сериализации
	CMyPaintDoc();
	DECLARE_DYNCREATE(CMyPaintDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMyPaintDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnElementsLine();
	afx_msg void OnUpdateElementsLine(CCmdUI *pCmdUI);
	afx_msg void OnElementsRe();
	afx_msg void OnUpdateElementsRe(CCmdUI *pCmdUI);
	afx_msg void OnElementsEllipse();
	afx_msg void OnUpdateElementsEllipse(CCmdUI *pCmdUI);
	afx_msg void OnElementsCurve();
	afx_msg void OnUpdateElementsCurve(CCmdUI *pCmdUI);
	afx_msg void OnColorBlack();
	afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
	afx_msg void OnColorWhite();
	afx_msg void OnUpdateColorWhite(CCmdUI *pCmdUI);
	afx_msg void OnColorRed();
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnColorGreen();
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnWidth1px();
	afx_msg void OnUpdateWidth1px(CCmdUI *pCmdUI);
	afx_msg void OnWidth2px();
	afx_msg void OnUpdateWidth2px(CCmdUI *pCmdUI);
	afx_msg void OnWidth5px();
	afx_msg void OnUpdateWidth5px(CCmdUI *pCmdUI);
	afx_msg void OnWidth10px();
	afx_msg void OnUpdateWidth10px(CCmdUI *pCmdUI);
	afx_msg void OnWidth20px();
	afx_msg void OnUpdateWidth20px(CCmdUI *pCmdUI);
	afx_msg void OnWidth50px();
	afx_msg void OnUpdateWidth50px(CCmdUI *pCmdUI);

protected:
	// выбранный тип элемента
	ElementType elementType;

	// выбранный цвет элемента
	COLORREF elementColor;

	// выбранная толщина пера
	int elementWidth;
public:
	ElementType GetElementType(void);
	COLORREF GetElementColor(void);
	int GetElementWidth(void);
};
