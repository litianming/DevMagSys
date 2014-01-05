#include "stdafx.h"
#include "SavePasswd.h"


CSavePasswd::CSavePasswd(void)
{
	Init();
}


CSavePasswd::~CSavePasswd(void)
{
}

void CSavePasswd::SetUserNamePasswd(char *username, char *passwd, int check, int autologin)
{
	strcpy_s(m_userName.m_username, username);
	strcpy_s(m_userName.m_passwd, passwd);
	m_userName.m_check = check;
	m_userName.m_autologin = autologin;
}

void CSavePasswd::WriteInFile()
{
	m_file = fopen("UserPasswd.txt", "w");
	fprintf(m_file, "%d\t%d\t%s\t%s\n", m_userName.m_check, m_userName.m_autologin, m_userName.m_username, m_userName.m_passwd);
}

void CSavePasswd::Init()
{
	memset(m_userName.m_username, 0, sizeof(m_userName.m_username));
	memset(m_userName.m_passwd, 0, sizeof(m_userName.m_passwd));
	m_userName.m_check = 0;
	m_userName.m_autologin = 0;
	if(!(m_file = fopen("UserPasswd.txt", "r")))
	{
	}
	else
	{
		fscanf(m_file, "%d\t%d\t%s\t%s", &m_userName.m_check, &m_userName.m_autologin, m_userName.m_username, m_userName.m_passwd);
	}
}

char * CSavePasswd::GetUsername()
{
	return m_userName.m_username;
}

char *CSavePasswd::GetPasswd()
{
	return m_userName.m_passwd;
}

int CSavePasswd::GetCkeck()
{
	return m_userName.m_check;
}

int CSavePasswd::GetAutoLogin()
{
	return m_userName.m_autologin;
}
