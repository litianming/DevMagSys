// DeviceManageSystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DeviceManageSystem.h"
#include "DeviceManageSystemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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


// CDeviceManageSystemDlg 对话框




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


// CDeviceManageSystemDlg 消息处理程序

BOOL CDeviceManageSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	HTREEITEM hSubItemOne, hSubItemTwo, hSubItemThree;
	HTREEITEM hPersonalSeting;
	HTREEITEM SystemManage;

	//创建图像列表控件
	CImageList *m_imagelist=new CImageList;
	m_imagelist->Create(16,16,ILC_COLOR  |  ILC_MASK,10,10);//前面的两个16是定义图标大小，后面两个数字更具需要自行改变 
	m_imagelist->Add(m_treeIcon); //把图标载入图像列表控件
	m_Tree.SetImageList(m_imagelist,TVSIL_NORMAL );



	hPersonalSeting = m_Tree.InsertItem("个人设置",TVI_ROOT);		
	hSubItemOne = m_Tree.InsertItem("基本资料",hPersonalSeting);			
	hSubItemTwo = m_Tree.InsertItem("修改密码",hPersonalSeting,hSubItemOne);

	TreeItemDataHead *p = &m_TreeItemDataHead;
	TreeItemData *pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemOne, (long)pData);

	p->m_Data = pData;									//保存每一个new出来的结构体对象,便于后面释放;
	strcpy_s(pData->m_ChildStr[0], "基本资料");
	pData->m_Count = 1;
	pData->m_Type = 2;

	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemTwo, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "修改密码");
	pData->m_Count = 1;
	pData->m_Type = 2;


	SystemManage = m_Tree.InsertItem("系统管理", TVI_ROOT);
	hSubItemOne = m_Tree.InsertItem("用户信息管理", SystemManage);
	hSubItemTwo = m_Tree.InsertItem("角色信息管理", SystemManage);
	hSubItemThree = m_Tree.InsertItem("部门信息管理", SystemManage);


	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemOne, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "用户信息管理");
	pData->m_Count = 1;
	pData->m_Type = 2;

	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemTwo, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "角色信息管理");
	pData->m_Count = 1;
	pData->m_Type = 2;

	pData = new TreeItemData;
	m_Tree.SetItemData(hSubItemThree, (long)pData);
	p->next = new TreeItemDataHead;
	p = p->next;
	p->m_Data = pData;
	strcpy_s(pData->m_ChildStr[0], "部门信息管理");
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
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDeviceManageSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDeviceManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDeviceManageSystemDlg::OnTcnSelchangingTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
			if (0 == strcmp(pData->m_ChildStr[0], "基本资料"))
			{
				m_UserInfo.MoveWindow(&rc);
				m_UserInfo.ShowWindow(SW_SHOWNA);
			}
			else
			{
				m_UserInfo.ShowWindow(SW_HIDE);
			}
			if (0 == strcmp(pData->m_ChildStr[0], "修改密码"))
			{
				m_ChangePwd.MoveWindow(&rc);
				m_ChangePwd.ShowWindow(SW_SHOWNA);
			}
			else
			{
				m_ChangePwd.ShowWindow(SW_HIDE);
			}

			if (0 == strcmp(pData->m_ChildStr[0], "用户信息管理"))
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
	// TODO: 在此添加控件通知处理程序代码
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
