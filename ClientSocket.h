#pragma once

// CClientSocket ����Ŀ��
#include "Message.h"


class CClientSocket : public CSocket
{
public:
	CClientSocket();
	virtual ~CClientSocket();

	int SendMsg(Message *msg);

	virtual void OnReceive(int nErrorCode);
private:

};


