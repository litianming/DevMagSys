#pragma once

#include "SetingAddrPort.h"
#include "SavePasswd.h"
// MyDialog �Ի���


class MyDialog : public CDialog
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog();

// �Ի�������
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//�Զ����½��Ϣ������
	afx_msg LRESULT OnLoginMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL OnInitDialog();
private:
	int m_LoginRet;
public:
	int GetLoginRet();
private:
	CString m_passwd;
	CString m_username;
public:
	afx_msg void OnBnClickedButtonSeting();
private:
	int m_port;
	DWORD m_IpAddr;
	char m_IP[32];
	int m_ConnectState;

	BOOL m_remberPwd;
	BOOL m_autoLogin;
public:
	afx_msg void OnBnClickedCheck1();
private:
	CSavePasswd m_savePasswd;
public:
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnPaint();
};
