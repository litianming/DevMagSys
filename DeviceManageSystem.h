// DeviceManageSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "ClientSocket.h"

// CDeviceManageSystemApp:
// �йش����ʵ�֣������ DeviceManageSystem.cpp
//

class CDeviceManageSystemApp : public CWinApp
{
public:
	CDeviceManageSystemApp();

	// ��д
public:
	virtual BOOL InitInstance();

	// ʵ��

	DECLARE_MESSAGE_MAP()


	afx_msg LRESULT SetUserInfoValues(WPARAM wParam, LPARAM lParam);
public:
	CClientSocket m_socket;
};

extern CDeviceManageSystemApp theApp;