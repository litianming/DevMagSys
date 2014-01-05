// DeviceManageSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "DeviceManageSystemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CDeviceManageSystemDlg �Ի���




CDeviceManageSystemDlg::CDeviceManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeviceManageSystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINFRAME);
	m_treeIcon = AfxGetApp()->LoadIcon(IDI_ICON_BRIEFCASE);
}

void CDeviceManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	DDX_Control(pDX, IDC_TAB1, m_MainTab);
}

BEGIN_MESSAGE_MAP(CDeviceManageSystemDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB1, &CDeviceManageSystemDlg::OnTcnSelchangingTab1)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &CDeviceManageSystemDlg::OnNMDblclkTree1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CDeviceManageSystemDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CDeviceManageSystemDlg ��Ϣ�������

BOOL CDeviceManageSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	HTREEITEM hSubItemOne, hSubItemTwo, hSubItemThree;
	HTREEITEM hPersonalSeting;
	HTREEITEM SystemManage;

	//����ͼ���б�ؼ�
	CImageList *m_imagelist=new CImageList;
	m_imagelist->Create(16,16,ILC_COLOR  |  ILC_MASK,10,10);//ǰ�������16�Ƕ���ͼ���С�������������ָ�����Ҫ���иı� 
	m_imagelist->Add(m_treeIcon); //��ͼ������ͼ���б�ؼ�
	m_Tree.SetImageList(m_imagelist,TVSIL_NORMAL );



	hPersonalSeting = m_Tree.InsertItem("��������",TVI_ROOT);		
	hSubItemOne = m_Tree.InsertItem("��������",hPersonalSeting);			
	hSubItemTwo = m_Tree.InsertItem("�޸�����",hPersonalSeting,hSubItemOne);

	TreeItemDataHead *p = &m_TreeItemDataHead;
	TreeItemData *pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemOne, (long)pData);

	p->m_Data = pData;									//����ÿһ��new�����Ľṹ�����,���ں����ͷ�;
	strcpy_s(pData->m_ChildStr[0], "��������");
	pData->m_Count = 1;
	pData->m_Type = 2;

	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemTwo, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "�޸�����");
	pData->m_Count = 1;
	pData->m_Type = 2;


	SystemManage = m_Tree.InsertItem("ϵͳ����", TVI_ROOT);
	hSubItemOne = m_Tree.InsertItem("�û���Ϣ����", SystemManage);
	hSubItemTwo = m_Tree.InsertItem("��ɫ��Ϣ����", SystemManage);
	hSubItemThree = m_Tree.InsertItem("������Ϣ����", SystemManage);


	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemOne, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "�û���Ϣ����");
	pData->m_Count = 1;
	pData->m_Type = 2;

	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemTwo, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "��ɫ��Ϣ����");
	pData->m_Count = 1;
	pData->m_Type = 2;

	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemThree, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "������Ϣ����");
	pData->m_Count = 1;
	pData->m_Type = 2;



	m_UserInfo.Create(IDD_DLG_USERINFO, &m_MainTab);
	m_ChangePwd.Create(IDD_DLG_CHANGEPASSWD, &m_MainTab);
	m_UserInfoManage.Create(IDD_DLG_UserInfoManage, &m_MainTab);
	//m_MainTab.InsertItem(0,"Option 1");
	//m_MainTab.InsertItem(1,"Option 2");

	/*m_DlgTab1.Create(IDD_DLG_TAB1, &m_MainTab);
	m_DlgTab2.Create(IDD_DLG_TAB2, &m_MainTab);

	RECT rc;
	m_MainTab.GetClientRect(&rc);
	rc.top += 20;

	m_DlgTab1.MoveWindow(&rc);
	m_DlgTab2.MoveWindow(&rc);


	m_DlgTab1.ShowWindow(SW_SHOWNA);
	m_DlgTab2.ShowWindow(SW_HIDE);*/
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDeviceManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDeviceManageSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDeviceManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDeviceManageSystemDlg::OnTcnSelchangingTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//int sel = m_MainTab.GetCurSel();

	//switch (sel)
	//{
	//case 0:
	//	m_DlgTab1.ShowWindow(SW_HIDE);
	//	break;
	//case 1:
	//	m_DlgTab2.ShowWindow(SW_HIDE);
	//	break;
	//default:
	//	break;
	//}

	//*pResult = 0;
}


void CDeviceManageSystemDlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POINT pt;
	GetCursorPos(&pt);
	m_Tree.ScreenToClient(&pt);
	HTREEITEM hitem = m_Tree.HitTest(pt);

	RECT rc;
	m_MainTab.GetClientRect(&rc);
	rc.top += 20;

	if (hitem)
	{
		TreeItemData *pData = (TreeItemData*)m_Tree.GetItemData(hitem);
		m_MainTab.DeleteAllItems();
		if (pData)
		{
			m_MainTab.InsertItem(0, pData->m_ChildStr[0]);
			if (0 == strcmp(pData->m_ChildStr[0], "��������"))
			{
				m_UserInfo.MoveWindow(&rc);
				m_UserInfo.ShowWindow(SW_SHOWNA);
			}
			else
			{
				m_UserInfo.ShowWindow(SW_HIDE);
			}
			if (0 == strcmp(pData->m_ChildStr[0], "�޸�����"))
			{
				m_ChangePwd.MoveWindow(&rc);
				m_ChangePwd.ShowWindow(SW_SHOWNA);
			}
			else
			{
				m_ChangePwd.ShowWindow(SW_HIDE);
			}

			if (0 == strcmp(pData->m_ChildStr[0], "�û���Ϣ����"))
			{
				m_UserInfoManage.MoveWindow(&rc);
				m_UserInfoManage.ShowWindow(SW_SHOWNA);
			}
			else
			{
				m_UserInfoManage.ShowWindow(SW_HIDE);
			}
		}
	}
}


void CDeviceManageSystemDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//int sel = m_MainTab.GetCurSel();

	//switch (sel)
	//{
	//case 0:
	//	m_DlgTab1.ShowWindow(SW_SHOWNA);
	//	break;
	//case 1:
	//	m_DlgTab2.ShowWindow(SW_SHOWNA);
	//	break;
	//default:
	//	break;
	//}
	//*pResult = 0;
}
