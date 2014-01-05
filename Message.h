#pragma once
#include "GConst.h"
class Message
{
public:
	Message(void);
	~Message(void);

public:
	virtual void EnCode(char *pCode, int maxLen) = 0;
	virtual void DeCode(char *pCode, int length) = 0;
	virtual int GetMessageLen()					 = 0;

	MSGTYPE m_msgType;
};

