// RecvUserInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "RecvUserInfo.h"
#include "MyLoginResult.h"
#include "afxdialogex.h"


// CRecvUserInfo 对话框

IMPLEMENT_DYNAMIC(CRecvUserInfo, CDialogEx)

	CRecvUserInfo::CRecvUserInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRecvUserInfo::IDD, pParent)
	, m_UserName(_T(""))
	, m_Passwd(_T(""))
	, m_LoginAccount(_T(""))
	, m_UserID(_T(""))
	, m_Department(_T(""))
	, m_Role(_T(""))
	, m_Position(_T(""))
	, m_JobState(_T(""))
	, m_Email(_T(""))
	, m_WetherLogin(_T(""))
	, m_Sex(_T(""))
{

}

CRecvUserInfo::~CRecvUserInfo()
{
}

void CRecvUserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_UserName);
	DDX_Text(pDX, IDC_EDIT1, m_Passwd);
	DDX_Text(pDX, IDC_EDIT7, m_LoginAccount);
	DDX_Text(pDX, IDC_EDIT3, m_UserID);
	DDX_Text(pDX, IDC_EDIT2, m_Department);
	DDX_Text(pDX, IDC_EDIT6, m_Role);
	DDX_Text(pDX, IDC_EDIT8, m_Position);
	DDX_Text(pDX, IDC_EDIT9, m_JobState);
	DDX_Text(pDX, IDC_EDIT10, m_Email);
	DDX_Text(pDX, IDC_EDIT11, m_WetherLogin);
	DDX_Text(pDX, IDC_EDIT12, m_Sex);
}


BEGIN_MESSAGE_MAP(CRecvUserInfo, CDialogEx)
END_MESSAGE_MAP()


// CRecvUserInfo 消息处理程序
void CRecvUserInfo::SetValues(MyLoginResult *loginresult)
{
	m_UserName.Format("%s", loginresult->GetUserNamePoint());
	m_Passwd.Format("%s", loginresult->GetPasswdPoint());
	m_LoginAccount.Format("%s", loginresult->GetLoginAccountPoint());
	m_UserID.Format("%s", loginresult->GetUserIDPoint());
	m_Department.Format("%s", loginresult->GetDepartmentPoint());
	m_Role.Format("%s", loginresult->GetRolePoint());
	m_Position.Format("%s", loginresult->GetPositionPoint());
	m_JobState.Format("%s", loginresult->GetJobStatePoint());
	m_Email.Format("%s", loginresult->GetEmailPoint());
	m_WetherLogin.Format("%s", loginresult->GetWetherLoginPoint());
	m_Sex.Format("%s", loginresult->GetSexPoint());
	UpdateData(FALSE);
}
