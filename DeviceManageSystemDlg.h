// DeviceManageSystemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "GConst.h"
#include "RecvUserInfo.h"
#include "ChangePasswd.h"
#include "UserInfoMage.h"
#include "MyLoginResult.h"
// CDeviceManageSystemDlg �Ի���
class CDeviceManageSystemDlg : public CDialog
{
// ����
public:
	CDeviceManageSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DEVICEMANAGESYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	HICON m_treeIcon;
	// ���ɵ���Ϣӳ�亯��
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
