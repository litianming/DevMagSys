#pragma once


// CRecvUserInfo 对话框

class CRecvUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CRecvUserInfo)

public:
	CRecvUserInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRecvUserInfo();

// 对话框数据
	enum { IDD = IDD_DLG_USERINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


	afx_msg LRESULT SetValues(WPARAM wParam, LPARAM lParam);
public:
	CString m_UserName;
	CString m_Passwd;
	CString m_LoginAccount;
	CString m_UserID;
	CString m_Department;
	CString m_Role;
	CString m_Position;
	CString m_JobState;
	CString m_Email;
	CString m_WetherLogin;
	CString m_Sex;
};
