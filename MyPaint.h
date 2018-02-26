
// MyPaint.h : главный файл заголовка для приложения MyPaint
//
#pragma once

#include "MyPaintConstants.h"
#include "Element.h"

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMyPaintApp:
// О реализации данного класса см. MyPaint.cpp
//

class CMyPaintApp : public CWinApp
{
public:
	CMyPaintApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyPaintApp theApp;
