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
{

}

CChangePasswd::~CChangePasswd()
{
}

void CChangePasswd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChangePasswd, CDialogEx)
END_MESSAGE_MAP()


// CChangePasswd 消息处理程序
