#include "stdafx.h"
#include "MyLogin.h"
#include "GConst.h"

MyLogin::MyLogin()
{
	m_msgType = MSGTYPE_LOGIN;
}
MyLogin::MyLogin(char *name, char *passwd)
{
	strcpy_s(m_username, name);
	strcpy_s(m_passwd, passwd);
	m_msgType = MSGTYPE_LOGIN;
	m_size = CHAR_SIZE * 32 + CHAR_SIZE * 32 + SHORT_SIZE;
}

MyLogin::~MyLogin(void)
{
}

int MyLogin::GetMessageLen()
{
	return m_size;
}

void MyLogin::EnCode(char *pCode, int maxLen)
{
	int len = GetMessageLen();
	int index = 0;
	if(pCode && maxLen >= len)
	{
		memcpy(pCode, &m_msgType, SHORT_SIZE);
		index += SHORT_SIZE;
		memcpy(pCode + index, m_username, sizeof(m_username));
		index += sizeof(m_username);
		memcpy(pCode + index, m_passwd, sizeof(m_passwd));
	}
}

void MyLogin::DeCode(char *pCode, int len)
{
	int index = 0;
	if(pCode && len >= GetMessageLen())
	{
		memcpy(&m_msgType, pCode, SHORT_SIZE);
		index += SHORT_SIZE;
		memcpy(m_username, pCode + index, sizeof(m_username));
		index += sizeof(m_username);
		memcpy(m_passwd, pCode + index, sizeof(m_passwd));
	}
	return;
}

char *MyLogin::GetUsernamePoint()
{
	return m_username;
}

char *MyLogin::GetPasswdPoint()
{
	return m_passwd;
}
