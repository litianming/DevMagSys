#pragma once


// CSetingAddrPort �Ի���

class CSetingAddrPort : public CDialogEx
{
	DECLARE_DYNAMIC(CSetingAddrPort)

public:
	CSetingAddrPort(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetingAddrPort();

	// �Ի�������
	enum { IDD = IDD_DIALOG_SETING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();

private:
	DWORD m_ipAddress;
	int m_port;
public:
	afx_msg void OnBnClickedButton1();

public:
	DWORD GetIpAddr();
	int GetPort();
};
