// UserInfoMage.cpp : 实现文件
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "UserInfoMage.h"
#include "afxdialogex.h"


// CUserInfoMage 对话框

IMPLEMENT_DYNAMIC(CUserInfoMage, CDialogEx)

	CUserInfoMage::CUserInfoMage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserInfoMage::IDD, pParent)
{

}

CUserInfoMage::~CUserInfoMage()
{
}

void CUserInfoMage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST7, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(CUserInfoMage, CDialogEx)
	ON_BN_CLICKED(IDOK, &CUserInfoMage::OnBnClickedOk)
END_MESSAGE_MAP()


// CUserInfoMage 消息处理程序


BOOL CUserInfoMage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT); 
	DWORD dwStyle; // 设置新风格  
	dwStyle=::GetWindowLong(m_ListCtrl.m_hWnd,GWL_STYLE);  
	dwStyle|=LVS_REPORT | LVS_SHOWSELALWAYS | LVS_EDITLABELS;  
	::SetWindowLong(m_ListCtrl.m_hWnd,GWL_STYLE,dwStyle);  
	dwStyle=m_ListCtrl.GetExtendedStyle();  
	dwStyle|=LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;  
	m_ListCtrl.SetExtendedStyle(dwStyle);  

	m_ListCtrl.InsertColumn( 0, "用户名", LVCFMT_LEFT, 110 );//插入列
	m_ListCtrl.InsertColumn( 1, "登陆账号", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 2, "员工编号", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 3, "所属部门", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 4, "所属角色", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 5, "登陆系统", LVCFMT_LEFT, 110 );



	int nRow = m_ListCtrl.InsertItem(0, "123");//插入行
	m_ListCtrl.SetItemText(nRow, 1, "111");//设置数据



	return 0;
}


void CUserInfoMage::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
