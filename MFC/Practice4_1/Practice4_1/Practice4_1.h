
// Practice4_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice4_1App:
// �� Ŭ������ ������ ���ؼ��� Practice4_1.cpp�� �����Ͻʽÿ�.
//

class CPractice4_1App : public CWinApp
{
public:
	CPractice4_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice4_1App theApp;