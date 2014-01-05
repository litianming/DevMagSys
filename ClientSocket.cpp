// ClientSocket.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "ClientSocket.h"
#include "Message.h"
#include "MyLoginResult.h"
#include "MyDialog.h"

static void InitSock()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		return;
	}

	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 2 ) {
			/* Tell the user that we could not find a usable */
			/* WinSock DLL.                                  */
			WSACleanup( );
			return; 
	}
}
// CClientSocket

CClientSocket::CClientSocket()
{
	InitSock();
}

CClientSocket::~CClientSocket()
{
}

int CClientSocket::SendMsg(Message *msg)
{
	char* pCode = new char[msg->GetMessageLen()];
	msg->EnCode(pCode, msg->GetMessageLen());
	Send(pCode, msg->GetMessageLen());

	return 0;
}

void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	char recvBuff[1024] = {0};
	int len = Receive(recvBuff, 1024);

	short msgid = *(short*)recvBuff;

	switch (msgid)
	{
	case MSGTYPE_LOGIN_RESULT:
		{
			//�������ڴ�й¶���⡢δ����loginResult���ͷ����⣬�ݻ�����
			MyLoginResult *loginResult = new MyLoginResult;

			//msg.DeCode(recvBuff, len);
			loginResult->DeCode(recvBuff, len);

			if (loginResult->GetLoginResult() == 1)
			{
				//�򴰿ڷ����Զ�����Ϣ
				::SendMessage(::AfxGetMainWnd()->m_hWnd, WM_LoginMessage, (WPARAM)loginResult, 1);
			}
			else
			{
				::SendMessage(::AfxGetMainWnd()->m_hWnd, WM_LoginMessage, 0, -1);
				//�򴰿ڷ����Զ�����Ϣ
			}
		}
		break;
	}
	
	CSocket::OnReceive(nErrorCode);
}