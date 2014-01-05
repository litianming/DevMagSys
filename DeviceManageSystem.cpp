// DeviceManageSystem.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "DeviceManageSystemDlg.h"
#include "MyDialog.h"
#include "GConst.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDeviceManageSystemApp

BEGIN_MESSAGE_MAP(CDeviceManageSystemApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
	
END_MESSAGE_MAP()



afx_msg LRESULT CDeviceManageSystemApp::SetUserInfoValues(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

// CDeviceManageSystemApp ����

CDeviceManageSystemApp::CDeviceManageSystemApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDeviceManageSystemApp ����

CDeviceManageSystemApp theApp;


// CDeviceManageSystemApp ��ʼ��

BOOL CDeviceManageSystemApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	//����socket
	m_socket.Create();

	//������ʾ��½�Ի���
	MyDialog dlg;
	INT_PTR ret = dlg.DoModal();

	//��½��ȷ���������ʾ���Ի���
	if(ret == IDOK)
	{
		if(dlg.GetLoginRet() == 1)
		{
			CDeviceManageSystemDlg dmsdlg;
			m_pMainWnd = &dmsdlg;
			dmsdlg.SetLoginResult(dlg.GetLoginResult());
			INT_PTR nResponse = dmsdlg.DoModal();
			
		}
	}
	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
