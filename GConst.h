#pragma once

typedef struct TreeItemData
{
	int m_Type;				//0 ��ʾ���ڵ�, 1 ��ʾ�м�ڵ�, 2 ��ʾҶ�ӽڵ�
	char m_ChildStr[32][32];
	int m_Count;
};

typedef struct TreeItemDataHead
{
	TreeItemData *m_Data;
	TreeItemDataHead *next;
};


typedef struct UserName
{
	char m_username[32];
	char m_passwd[32];
	int m_check;
	int m_autologin;
	UserName *next;
};

//�Զ�����Ϣ
#define WM_LoginMessage (WM_USER+101)
#define WM_ReceiveUserInfo (WM_USER+102)

//��ʾ��Ϣ����
typedef short MSGTYPE;

#define SHORT_SIZE sizeof(short)
#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)

const short MSGTYPE_LOGIN				= 1;
const short MSGTYPE_LOGIN_RESULT		= 11;
const short MSGTYPE_LOGOUT				= 111;

const short MSGTYPE_ADDDEVICE			= 2;
const short MSGTYPE_ADDDEVICE_RESULT	= 22;

const short MSGTYPE_DELDEVICE			= 3;
const short MSGTYPE_DELDEVICE_RESULT	= 33;