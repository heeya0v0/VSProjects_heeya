
// Practice3_1.h : Practice3_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPractice3_1App:
// �� Ŭ������ ������ ���ؼ��� Practice3_1.cpp�� �����Ͻʽÿ�.
//

class CPractice3_1App : public CWinAppEx
{
public:
	CPractice3_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPractice3_1App theApp;
