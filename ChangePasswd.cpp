// ChangePasswd.cpp : 实现文件
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "ChangePasswd.h"
#include "afxdialogex.h"


// CChangePasswd 对话框

IMPLEMENT_DYNAMIC(CChangePasswd, CDialogEx)

	CChangePasswd::CChangePasswd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangePasswd::IDD, pParent)
	, m_OldPasswd(_T(""))
	, m_NewPassweOne(_T(""))
	, m_NewPasswdTwo(_T(""))
{

}

CChangePasswd::~CChangePasswd()
{
}

void CChangePasswd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OLDPASSWD, m_OldPasswd);
	DDX_Text(pDX, IDC_EDIT_NEWPASSWDONE, m_NewPassweOne);
	DDX_Text(pDX, IDC_EDIT_NEWPASSWDTWO, m_NewPasswdTwo);
}


BEGIN_MESSAGE_MAP(CChangePasswd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CChangePasswd::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CChangePasswd::OnBnClickedButtonCancel)
END_MESSAGE_MAP()


// CChangePasswd 消息处理程序


void CChangePasswd::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_OriginPasswd == m_OldPasswd)
	{
		if (m_NewPasswdTwo == m_NewPassweOne)
		{

			//theApp.m_socket.SendMsg();
		}
		else
		{
			MessageBox(TEXT("两次输入的密码不匹配!"),TEXT("Warning!!"),MB_ICONWARNING | MB_OK);
		}

	}
	else
	{
		MessageBox(TEXT("旧密码错误！"),TEXT("Warning!!"),MB_ICONWARNING | MB_OK);
	}
}


void CChangePasswd::OnBnClickedButtonCancel()
{
	m_OldPasswd = "";
	m_NewPassweOne = "";
	m_NewPasswdTwo = "";
	UpdateData(FALSE);
}

void CChangePasswd::SetOriginPasswd(char *passwd)
{
	m_OriginPasswd.Format("%s", passwd);
}
