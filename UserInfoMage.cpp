// UserInfoMage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "UserInfoMage.h"
#include "afxdialogex.h"


// CUserInfoMage �Ի���

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


// CUserInfoMage ��Ϣ�������


BOOL CUserInfoMage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT); 
	DWORD dwStyle; // �����·��  
	dwStyle=::GetWindowLong(m_ListCtrl.m_hWnd,GWL_STYLE);  
	dwStyle|=LVS_REPORT | LVS_SHOWSELALWAYS | LVS_EDITLABELS;  
	::SetWindowLong(m_ListCtrl.m_hWnd,GWL_STYLE,dwStyle);  
	dwStyle=m_ListCtrl.GetExtendedStyle();  
	dwStyle|=LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;  
	m_ListCtrl.SetExtendedStyle(dwStyle);  

	m_ListCtrl.InsertColumn( 0, "�û���", LVCFMT_LEFT, 110 );//������
	m_ListCtrl.InsertColumn( 1, "��½�˺�", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 2, "Ա�����", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 3, "��������", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 4, "������ɫ", LVCFMT_LEFT, 110 );
	m_ListCtrl.InsertColumn( 5, "��½ϵͳ", LVCFMT_LEFT, 110 );



	int nRow = m_ListCtrl.InsertItem(0, "123");//������
	m_ListCtrl.SetItemText(nRow, 1, "111");//��������



	return 0;
}


void CUserInfoMage::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
