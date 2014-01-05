#pragma once
#include "Message.h"

class MyLoginResult:public Message
{
public:
	MyLoginResult(void);
	~MyLoginResult(void);

	void EnCode(char *pCode, int maxLen);
	void DeCode(char *pCode, int len);
	int GetMessageLen();
	short GetLoginResult();

	char *GetUserNamePoint();
	
	void SetLoginResult(short result);

	void SetUserName(char *username);
	void SetPasswd(char *passwd);
	char *GetPasswdPoint();
	void SetLoginAccount(char *loginaccount);
	char *GetLoginAccountPoint();
	void SetUserID(char *userID);
	char *GetUserIDPoint();
	void SetDepartment(char *department);
	char *GetDepartmentPoint();
	void SetRole(char *role);
	char *GetRolePoint();
	void SetPosition(char *position);
	char *GetPositionPoint();
	void SetJobState(char *jobstate);
	char *GetJobStatePoint();
	void SetEmail(char *email);
	char *GetEmailPoint();
	void SetWetherLogin(char *wetherlogin);
	char *GetWetherLoginPoint();
	void SetSex(char *sex);
	char *GetSexPoint();
private:
	//标志登陆结果
	short m_loginResult;

	char m_username[32];
	char m_passwd[32];
	char m_LoginAccount[32];
	char m_UserID[16];
	char m_Department[32];
	char m_Role[16];
	char m_Position[32];
	char m_JobState[16];
	char m_Email[32];
	char m_WetherLogin[16];
	char m_Sex[16];

	//不算入类大小中
	int m_size;
};

