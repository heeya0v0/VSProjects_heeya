
// Practice3_3.h : Practice3_3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPractice3_3App:
// �� Ŭ������ ������ ���ؼ��� Practice3_3.cpp�� �����Ͻʽÿ�.
//

class CPractice3_3App : public CWinAppEx
{
public:
	CPractice3_3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPractice3_3App theApp;
