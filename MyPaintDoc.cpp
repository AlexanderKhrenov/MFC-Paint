// MyPaintDoc.cpp : реализация класса CMyPaintDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MyPaint.h"
#endif

#include "MyPaintDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyPaintDoc

IMPLEMENT_DYNCREATE(CMyPaintDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyPaintDoc, CDocument)
	ON_COMMAND(ID_ELEMENTS_LINE, &CMyPaintDoc::OnElementsLine)
	ON_COMMAND(ID_ELEMENTS_RE, &CMyPaintDoc::OnElementsRe)
	ON_COMMAND(ID_ELEMENTS_ELLIPSE, &CMyPaintDoc::OnElementsEllipse)
	ON_COMMAND(ID_ELEMENTS_CURVE, &CMyPaintDoc::OnElementsCurve)
	ON_COMMAND(ID_COLOR_BLACK, &CMyPaintDoc::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CMyPaintDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CMyPaintDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CMyPaintDoc::OnColorBlue)
	ON_COMMAND(ID_COLOR_WHITE, &CMyPaintDoc::OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_ELEMENTS_LINE, &CMyPaintDoc::OnUpdateElementsLine)
	ON_UPDATE_COMMAND_UI(ID_ELEMENTS_RE, &CMyPaintDoc::OnUpdateElementsRe)
	ON_UPDATE_COMMAND_UI(ID_ELEMENTS_ELLIPSE, &CMyPaintDoc::OnUpdateElementsEllipse)
	ON_UPDATE_COMMAND_UI(ID_ELEMENTS_CURVE, &CMyPaintDoc::OnUpdateElementsCurve)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CMyPaintDoc::OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CMyPaintDoc::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CMyPaintDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CMyPaintDoc::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, &CMyPaintDoc::OnUpdateColorWhite)
	ON_COMMAND(ID_WIDTH_1PX, &CMyPaintDoc::OnWidth1px)
	ON_COMMAND(ID_WIDTH_2PX, &CMyPaintDoc::OnWidth2px)
	ON_COMMAND(ID_WIDTH_5PX, &CMyPaintDoc::OnWidth5px)
	ON_COMMAND(ID_WIDTH_10PX, &CMyPaintDoc::OnWidth10px)
	ON_COMMAND(ID_WIDTH_20PX, &CMyPaintDoc::OnWidth20px)
	ON_COMMAND(ID_WIDTH_50PX, &CMyPaintDoc::OnWidth50px)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_1PX, &CMyPaintDoc::OnUpdateWidth1px)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_2PX, &CMyPaintDoc::OnUpdateWidth2px)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_5PX, &CMyPaintDoc::OnUpdateWidth5px)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_10PX, &CMyPaintDoc::OnUpdateWidth10px)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_20PX, &CMyPaintDoc::OnUpdateWidth20px)
	ON_UPDATE_COMMAND_UI(ID_WIDTH_50PX, &CMyPaintDoc::OnUpdateWidth50px)
END_MESSAGE_MAP()


// создание/уничтожение CMyPaintDoc

CMyPaintDoc::CMyPaintDoc()
{
	// TODO: добавьте код для одноразового вызова конструктора
	elementType = LINE;
	elementColor = BLACK;
	elementWidth = 1;
}

CMyPaintDoc::~CMyPaintDoc()
{
}

BOOL CMyPaintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация CMyPaintDoc

void CMyPaintDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMyPaintDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CMyPaintDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMyPaintDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика CMyPaintDoc

#ifdef _DEBUG
void CMyPaintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyPaintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CMyPaintDoc


/*выбор типа элемента для рисования*/
void CMyPaintDoc::OnElementsLine()
{
	elementType = LINE;
}


void CMyPaintDoc::OnElementsRe()
{
	elementType = RECTANGLE;
}


void CMyPaintDoc::OnElementsEllipse()
{
	elementType = ELLIPSE;
}


void CMyPaintDoc::OnElementsCurve()
{
	elementType = CURVE;
}


/*выбор цвета элемента*/
void CMyPaintDoc::OnColorBlack()
{
	elementColor = BLACK;
}


void CMyPaintDoc::OnColorRed()
{
	elementColor = RED;
}


void CMyPaintDoc::OnColorGreen()
{
	elementColor = GREEN;
}


void CMyPaintDoc::OnColorBlue()
{
	elementColor = BLUE;
}


void CMyPaintDoc::OnColorWhite()
{
	elementColor = WHITE;
}


/*выбор толщины пера*/
void CMyPaintDoc::OnWidth1px()
{
	elementWidth = 1;
}


void CMyPaintDoc::OnWidth2px()
{
	elementWidth = 2;
}


void CMyPaintDoc::OnWidth5px()
{
	elementWidth = 5;
}


void CMyPaintDoc::OnWidth10px()
{
	elementWidth = 10;
}


void CMyPaintDoc::OnWidth20px()
{
	elementWidth = 20;
}


void CMyPaintDoc::OnWidth50px()
{
	elementWidth = 50;
}

void CMyPaintDoc::OnUpdateElementsLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == LINE);
}


/*отмечаю активные кнопки*/
void CMyPaintDoc::OnUpdateElementsRe(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == RECTANGLE);
}


void CMyPaintDoc::OnUpdateElementsEllipse(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == ELLIPSE);
}


void CMyPaintDoc::OnUpdateElementsCurve(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementType == CURVE);
}


void CMyPaintDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementColor == BLACK);
}


void CMyPaintDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementColor == RED);
}


void CMyPaintDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementColor == GREEN);
}


void CMyPaintDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementColor == BLUE);
}


void CMyPaintDoc::OnUpdateColorWhite(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementColor == WHITE);
}




void CMyPaintDoc::OnUpdateWidth1px(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementWidth == 1);
}


void CMyPaintDoc::OnUpdateWidth2px(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementWidth == 2);
}


void CMyPaintDoc::OnUpdateWidth5px(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementWidth == 5);
}


void CMyPaintDoc::OnUpdateWidth10px(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementWidth == 10);
}


void CMyPaintDoc::OnUpdateWidth20px(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementWidth == 20);
}


void CMyPaintDoc::OnUpdateWidth50px(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(elementWidth == 50);
}


/*функции, которые возвращают параметры для рисования(тип фигуры, цвет, толщину пера)*/
ElementType CMyPaintDoc::GetElementType(void)
{
	return elementType;
}

COLORREF CMyPaintDoc::GetElementColor(void)
{
	return elementColor;
}

int CMyPaintDoc::GetElementWidth(void)
{
	return elementWidth;
}