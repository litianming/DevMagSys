#pragma once


// CSetingAddrPort 对话框

class CSetingAddrPort : public CDialogEx
{
	DECLARE_DYNAMIC(CSetingAddrPort)

public:
	CSetingAddrPort(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetingAddrPort();

	// 对话框数据
	enum { IDD = IDD_DIALOG_SETING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
