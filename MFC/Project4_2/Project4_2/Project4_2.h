
// Project4_2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CProject4_2App:
// �� Ŭ������ ������ ���ؼ��� Project4_2.cpp�� �����Ͻʽÿ�.
//

class CProject4_2App : public CWinApp
{
public:
	CProject4_2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CProject4_2App theApp;