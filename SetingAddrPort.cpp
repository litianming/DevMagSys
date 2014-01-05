// SetingAddrPort.cpp : 实现文件
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "SetingAddrPort.h"
#include "afxdialogex.h"


// CSetingAddrPort 对话框

IMPLEMENT_DYNAMIC(CSetingAddrPort, CDialogEx)

	CSetingAddrPort::CSetingAddrPort(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetingAddrPort::IDD, pParent)
	, m_ipAddress(2130706433)
	, m_port(8090)
{

}

CSetingAddrPort::~CSetingAddrPort()
{
}

void CSetingAddrPort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_IPAddress(pDX, IDC_IPADDRESS_ADDRESS, m_ipAddress);
	DDX_Text(pDX, IDC_EDIT_PORT, m_port);
}


BEGIN_MESSAGE_MAP(CSetingAddrPort, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetingAddrPort::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSetingAddrPort::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSetingAddrPort 消息处理程序


void CSetingAddrPort::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ipAddress = 0;
	UpdateData(FALSE);
}


void CSetingAddrPort::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	OnOK();
}

DWORD CSetingAddrPort::GetIpAddr()
{
	return m_ipAddress;
}

int CSetingAddrPort::GetPort()
{
	return m_port;
}
