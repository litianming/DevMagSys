// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "MyDialog.h"
#include "MyLogin.h"
#include "GConst.h"

// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

	MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialog::IDD, pParent)
	, m_passwd(_T(""))
	, m_username(_T(""))
	, m_remberPwd(FALSE)
	, m_autoLogin(FALSE)
{
	strcpy_s(m_IP, "127.0.0.1");
	m_port = 8090;
	m_LoginRet = 0;
	m_ConnectState = theApp.m_socket.Connect(m_IP, m_port);
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_passwd);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDV_MaxChars(pDX, m_username, 16);
	DDX_Check(pDX, IDC_CHECK1, m_remberPwd);
	DDX_Check(pDX, IDC_CHECK2, m_autoLogin);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_BN_CLICKED(IDOK, &MyDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_SETING, &MyDialog::OnBnClickedButtonSeting)
	ON_BN_CLICKED(IDC_CHECK1, &MyDialog::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &MyDialog::OnBnClickedCheck2)
	ON_EN_CHANGE(IDC_EDIT1, &MyDialog::OnEnChangeEdit1)
	ON_WM_PAINT()
	ON_MESSAGE(WM_LoginMessage, OnLoginMessage)
END_MESSAGE_MAP()


// MyDialog 消息处理程序

void MyDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//同步用户名,密码输入框的数据到类成员变量中
	UpdateData(TRUE);

	m_savePasswd.SetUserNamePasswd(m_username.GetBuffer(), m_passwd.GetBuffer(), m_remberPwd, m_autoLogin);
	m_savePasswd.WriteInFile();

	if(!strcmp(m_username.GetBuffer(), "") || !strcmp(m_passwd.GetBuffer(), ""))
	{
		MessageBox(TEXT("用户名和密码不能为空!"),TEXT("Warning!!"),MB_ICONWARNING | MB_OK);
	}
	else
	{
		if(m_ConnectState)
		{
			MyLogin login(m_username.GetBuffer(), m_passwd.GetBuffer());
			theApp.m_socket.SendMsg(&login);
		}
		else
		{
			MessageBox(TEXT("网络连接错误!"),TEXT("Warning!!"),MB_ICONWARNING | MB_OK);
		}
	}
}


LRESULT MyDialog::OnLoginMessage(WPARAM wParam, LPARAM lParam)
{
	//MessageBox("recv msg success");
	//添加自己的消息处理
	if ((int)lParam == 1)
	{
		m_loginResult = (MyLoginResult*)wParam;
		AfxMessageBox("登陆成功");
		m_LoginRet = 1;
		OnOK();
	}
	else
	{
		m_loginResult = 0x0;
		AfxMessageBox("登陆失败");
		m_LoginRet = -1;
	}
	return 0;
}

void MyDialog::OnBnClickedButtonSeting()
{
	// TODO: 在此添加控件通知处理程序代码
	//弹出设置对话框
	CSetingAddrPort addrPort;
	addrPort.DoModal();
	//获取IP和端口号
	m_IpAddr = addrPort.GetIpAddr();
	m_port = addrPort.GetPort();

	WORD  wd1=LOWORD(m_IpAddr);//取高十六位
	WORD  wd2=HIWORD(m_IpAddr);//取低十六位
	BYTE  bte1=LOBYTE(wd1);
	BYTE  bte2=HIBYTE(wd1);
	BYTE  bte3=LOBYTE(wd2);
	BYTE  bte4=HIBYTE(wd2);

	sprintf_s(m_IP, "%d.%d.%d.%d", bte4, bte3, bte2, bte1);
	//CString serverIp;
	//serverIp.Format(_T("%d.%d.%d.%d"), bte4, bte3, bte2, bte1);
}


void MyDialog::OnBnClickedCheck1()
{
	m_remberPwd = !m_remberPwd;
}

BOOL MyDialog::OnInitDialog()
{
	if(m_savePasswd.GetCkeck())
	{
		if (m_savePasswd.GetAutoLogin())
		{
			m_autoLogin = TRUE;
		}
		m_remberPwd = TRUE;
		m_username.Format("%s", m_savePasswd.GetUsername());
		m_passwd.Format("%s", m_savePasswd.GetPasswd());
	}
	else
	{
		m_remberPwd = FALSE;
		m_username.Format("%s", m_savePasswd.GetUsername());
		m_passwd.Format("%s", "");
	}
	UpdateData(FALSE);

	return TRUE;
}


void MyDialog::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_autoLogin = !m_autoLogin;
}

int MyDialog::GetLoginRet()
{
	return m_LoginRet;
}

void MyDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDialog::OnPaint()
{
	CPaintDC dc(this);
	CBitmap   bitmap;
	bitmap.LoadBitmap(IDB_BITMAP_LOGIN);    //这个IDB_BITMAP1要自己添加
	CBrush   brush;
	brush.CreatePatternBrush(&bitmap);
	CBrush*   pOldBrush   =   dc.SelectObject(&brush);
	dc.Rectangle(0,0,365,225);   // 这些参数可以调整图片添加位置和大小
	dc.SelectObject(pOldBrush);
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
}

MyLoginResult *MyDialog::GetLoginResult()
{
	return m_loginResult;
}
