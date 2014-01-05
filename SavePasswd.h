#pragma once
#include "GConst.h"

class CSavePasswd
{

public:
	CSavePasswd(void);
	~CSavePasswd(void);

	void SetUserNamePasswd(char *username, char *passwd, int check, int autologin);
	void WriteInFile();
	char * GetPasswd();
	char * GetUsername();
	int GetCkeck();
	int GetAutoLogin();
	
private:
	void Init();
private:
	FILE *m_file;
	UserName m_userName;
};

