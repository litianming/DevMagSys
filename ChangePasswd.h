#pragma once


// CChangePasswd �Ի���

class CChangePasswd : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePasswd)

public:
	CChangePasswd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangePasswd();

// �Ի�������
	enum { IDD = IDD_DLG_CHANGEPASSWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
