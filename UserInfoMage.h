#pragma once
#include "afxcmn.h"


// CUserInfoMage �Ի���

class CUserInfoMage : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInfoMage)

public:
	CUserInfoMage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserInfoMage();

// �Ի�������
	enum { IDD = IDD_DLG_UserInfoManage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedOk();
};
