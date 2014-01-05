// DeviceManageSystemDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "GConst.h"
#include "RecvUserInfo.h"
#include "ChangePasswd.h"
#include "UserInfoMage.h"
#include "MyLoginResult.h"
// CDeviceManageSystemDlg 对话框
class CDeviceManageSystemDlg : public CDialog
{
// 构造
public:
	CDeviceManageSystemDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DEVICEMANAGESYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	HICON m_treeIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CTreeCtrl m_Tree;
	CTabCtrl m_MainTab;
	afx_msg void OnTcnSelchangingTab1(NMHDR *pNMHDR, LRESULT *pResult);
	//CDlgTab1 m_DlgTab1;
	//CDlgTab2 m_DlgTab2;
	CRecvUserInfo m_UserInfo;
	CChangePasswd m_ChangePwd;
	CUserInfoMage m_UserInfoManage;
	MyLoginResult *m_LoginResult;

	void SetLoginResult(MyLoginResult *loginresult);

	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

	TreeItemDataHead m_TreeItemDataHead;
};
