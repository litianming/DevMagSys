#pragma once


// CChangePasswd 对话框

class CChangePasswd : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePasswd)

public:
	CChangePasswd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangePasswd();

// 对话框数据
	enum { IDD = IDD_DLG_CHANGEPASSWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_OriginPasswd;
	CString m_OldPasswd;
	CString m_NewPassweOne;
	CString m_NewPasswdTwo;
public:
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCancel();

	void SetOriginPasswd(char *passwd);
};
