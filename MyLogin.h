#pragma once

#include "Message.h"

class MyLogin : public Message
{
public:
	MyLogin();
	MyLogin(char *name, char *passwd);
	~MyLogin(void);

	void EnCode(char *pCode, int maxLen);
	void DeCode(char *pCode, int len);
	int GetMessageLen();

	char *GetUsernamePoint();
	char *GetPasswdPoint();

private:
	char m_username[32];
	char m_passwd[32];
	int m_size;
};


