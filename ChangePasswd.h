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
