
// Project4_2Dlg.h : ��� ����
//

#pragma once
#include "ClockHelpDlg.h"


// CProject4_2Dlg ��ȭ ����
class CProject4_2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CProject4_2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROJECT4_2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strYear;
	CString m_strMonth;
	CString m_strDay;
	CString m_strAMPM;
	CString m_strHour;
	CString m_strMinute;
	CString m_strSecond;
	bool m_bRadioClockType;
	afx_msg void OnRadio12();
	afx_msg void OnRadio24();
	bool m_bCheckYear;
	bool m_bCheckHour;
	afx_msg void OnClickedCheckYear();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool m_bViewHelp;
	CClockHelpDlg m_dlgClockHelp;
	afx_msg void OnClickedButtonHelp();
};
