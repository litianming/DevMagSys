#pragma once
#include "afxcmn.h"


// CUserInfoMage 对话框

class CUserInfoMage : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInfoMage)

public:
	CUserInfoMage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserInfoMage();

// 对话框数据
	enum { IDD = IDD_DLG_UserInfoManage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ListCtrl;
	afx_msg void OnBnClickedOk();
};
