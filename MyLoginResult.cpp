#include "stdafx.h"
#include "MyLoginResult.h"


MyLoginResult::MyLoginResult(void)
{
	m_msgType = MSGTYPE_LOGIN_RESULT;
	m_size = CHAR_SIZE * 32 * 6 + SHORT_SIZE * 16 * 5 + SHORT_SIZE;
}


MyLoginResult::~MyLoginResult(void)
{
}


int MyLoginResult::GetMessageLen()
{
	return  CHAR_SIZE * 32 * 6 + SHORT_SIZE * 16 * 5 + SHORT_SIZE;
}

void MyLoginResult::EnCode(char *pCode, int maxLen)
{
	int len = GetMessageLen();
	int index = 0;
	if(pCode && maxLen >= len)
	{
		memcpy(pCode, &m_msgType, SHORT_SIZE);
		index += SHORT_SIZE;
		memcpy(pCode + index , &m_loginResult, SHORT_SIZE);
		index += SHORT_SIZE;
		memcpy(pCode+index, m_username, sizeof(m_username));
		index += sizeof(m_username);
		memcpy(pCode + index, m_passwd, sizeof(m_passwd));
		index += sizeof(m_passwd);
		memcpy(pCode + index, m_LoginAccount, sizeof(m_LoginAccount));
		index += sizeof(m_LoginAccount);
		memcpy(pCode + index, m_UserID, sizeof(m_UserID));
		index += sizeof(m_UserID);
		memcpy(pCode + index, m_Department, sizeof(m_Department));
		index += sizeof(m_Department);
		memcpy(pCode + index, m_Role, sizeof(m_Role));
		index += sizeof(m_Role);
		memcpy(pCode + index, m_Position, sizeof(m_Position));
		index += sizeof(m_Position);
		memcpy(pCode + index, m_JobState, sizeof(m_JobState));
		index += sizeof(m_JobState);
		memcpy(pCode + index, m_Email, sizeof(m_Email));
		index += sizeof(m_Email);
		memcpy(pCode + index, m_WetherLogin, sizeof(m_WetherLogin));
		index += sizeof(m_WetherLogin);
		memcpy(pCode + index, m_Sex, sizeof(m_Sex));
		index += sizeof(m_Sex);
	}
}

void MyLoginResult::DeCode(char *pCode, int len)
{
	int index = 0;
	if(pCode && len >= GetMessageLen())
	{
		memcpy(&m_msgType, pCode, SHORT_SIZE);
		index += SHORT_SIZE;
		memcpy(&m_loginResult, pCode + index , SHORT_SIZE);
		index += SHORT_SIZE;
		memcpy(m_username, pCode+index, sizeof(m_username));
		index += sizeof(m_username);
		memcpy(m_passwd, pCode + index, sizeof(m_passwd));
		index += sizeof(m_passwd);
		memcpy(m_LoginAccount, pCode + index, sizeof(m_LoginAccount));
		index += sizeof(m_LoginAccount);
		memcpy(m_UserID, pCode + index, sizeof(m_UserID));
		index += sizeof(m_UserID);
		memcpy(m_Department, pCode + index, sizeof(m_Department));
		index += sizeof(m_Department);
		memcpy(m_Role, pCode + index, sizeof(m_Role));
		index += sizeof(m_Role);
		memcpy(m_Position, pCode + index, sizeof(m_Position));
		index += sizeof(m_Position);
		memcpy(m_JobState, pCode + index, sizeof(m_JobState));
		index += sizeof(m_JobState);
		memcpy(m_Email, pCode + index, sizeof(m_Email));
		index += sizeof(m_Email);
		memcpy(m_WetherLogin, pCode + index, sizeof(m_WetherLogin));
		index += sizeof(m_WetherLogin);
		memcpy(m_Sex, pCode + index, sizeof(m_Sex));
		index += sizeof(m_Sex);
	}
	return;
}

void MyLoginResult::SetLoginResult(short result)
{
	m_loginResult = result;
}

short MyLoginResult::GetLoginResult()
{
	return m_loginResult;
}

void MyLoginResult::SetUserName(char *username)
{
	memset(m_username, 0, sizeof(m_username));
	strcpy_s(m_username, username);
}

char *MyLoginResult::GetUserNamePoint()
{
	return m_username;
}

void MyLoginResult::SetPasswd(char *passwd)
{
	memset(m_passwd, 0, sizeof(m_passwd));
	strcpy_s(m_passwd, passwd);
}

char *MyLoginResult::GetPasswdPoint()
{
	return m_passwd;
}

void MyLoginResult::SetLoginAccount(char *loginaccount)
{
	memset(m_LoginAccount, 0, sizeof(m_LoginAccount));
	strcpy_s(m_LoginAccount, loginaccount);
}

char *MyLoginResult::GetLoginAccountPoint()
{
	return m_LoginAccount;
}

void MyLoginResult::SetDepartment(char *department)
{
	memset(m_Department, 0, sizeof(m_Department));
	strcpy_s(m_Department, department);
}

char *MyLoginResult::GetDepartmentPoint()
{
	return m_Department;
}

void MyLoginResult::SetUserID(char *userID)
{
	memset(m_UserID, 0, sizeof(m_UserID));
	strcpy_s(m_UserID, userID);
}

char *MyLoginResult::GetUserIDPoint()
{
	return m_UserID;
}

void MyLoginResult::SetRole(char *role)
{
	memset(m_Role, 0, sizeof(m_Role));
	strcpy_s(m_Role, role);
}

char *MyLoginResult::GetRolePoint()
{
	return m_Role;
}

void MyLoginResult::SetPosition(char *position)
{
	memset(m_Position, 0, sizeof(m_Position));
	strcpy_s(m_Position, position);
}

char *MyLoginResult::GetPositionPoint()
{
	return m_Position;
}

void MyLoginResult::SetJobState(char *jobstate)
{
	memset(m_JobState, 0, sizeof(m_JobState));
	strcpy_s(m_JobState, jobstate);
}

char *MyLoginResult::GetJobStatePoint()
{
	return m_JobState;
}

void MyLoginResult::SetEmail(char *email)
{
	memset(m_Email, 0, sizeof(m_Email));
	strcpy_s(m_Email, email);
}

char *MyLoginResult::GetEmailPoint()
{
	return m_Email;
}

void MyLoginResult::SetWetherLogin(char *wetherlogin)
{
	memset(m_WetherLogin, 0, sizeof(m_WetherLogin));
	strcpy_s(m_WetherLogin, wetherlogin);
}

char *MyLoginResult::GetWetherLoginPoint()
{
	return m_WetherLogin;
}

void MyLoginResult::SetSex(char *sex)
{
	memset(m_Sex, 0, sizeof(m_Sex));
	strcpy_s(m_Sex, sex);
}

char *MyLoginResult::GetSexPoint()
{
	return m_Sex;
}
