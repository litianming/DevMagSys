// ChangePasswd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "ChangePasswd.h"
#include "afxdialogex.h"


// CChangePasswd �Ի���

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


// CChangePasswd ��Ϣ�������


void CChangePasswd::OnBnClickedButtonOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_OriginPasswd == m_OldPasswd)
	{
		if (m_NewPasswdTwo == m_NewPassweOne)
		{

			//theApp.m_socket.SendMsg();
		}
		else
		{
			MessageBox(TEXT("������������벻ƥ��!"),TEXT("Warning!!"),MB_ICONWARNING | MB_OK);
		}

	}
	else
	{
		MessageBox(TEXT("���������"),TEXT("Warning!!"),MB_ICONWARNING | MB_OK);
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
