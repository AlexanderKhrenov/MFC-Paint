
// MyPaint.h : ������� ���� ��������� ��� ���������� MyPaint
//
#pragma once

#include "MyPaintConstants.h"
#include "Element.h"

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMyPaintApp:
// � ���������� ������� ������ ��. MyPaint.cpp
//

class CMyPaintApp : public CWinApp
{
public:
	CMyPaintApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyPaintApp theApp;
