
// loopFileCreateToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "loopFileCreateTool.h"
#include "loopFileCreateToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CloopFileCreateToolDlg 对话框



CloopFileCreateToolDlg::CloopFileCreateToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CloopFileCreateToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CloopFileCreateToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CloopFileCreateToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOVE()
END_MESSAGE_MAP()


// CloopFileCreateToolDlg 消息处理程序

BOOL CloopFileCreateToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	//HBITMAP hBmp=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));   
	//((CButton*)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBmp);
	ShowWindow(SW_SHOWNORMAL) ;

	{
		//创建文字编辑子对话框
		CRect rect;
		((CEdit*)(GetDlgItem(IDC_EDIT_FOR_USR_FONT_DISP)))->GetWindowRect(rect);
		childDlgDispUsrFont.Create(IDD_DIALOG_DISP_USR_FONT,this);
		childDlgDispUsrFont.MoveWindow(rect); 
		childDlgDispUsrFont.InitDialog();
		childDlgDispUsrFont.ShowWindow(SW_SHOW);
	}

	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	char ret = TRUE;
	//ret = AddFontResource(_T("..\\res\\老宋.TTF"));
	if(FALSE == ret)
	{
		//MessageBox(_T("字库不存在！"), _T("警告"));
		((CMFCFontComboBox*)GetDlgItem(IDC_MFCFONTCOMBO1))->SelectFont(_T("Arial"));
	}
	else
	{
		//::SendMessage( HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
		((CMFCFontComboBox*)GetDlgItem(IDC_MFCFONTCOMBO1))->SelectFont(_T("老宋"));
	}

	{
		CFont * f;
		f = new CFont;
		f->CreateFont(11, // nHeight 
						11, // nWidth 
						0, // nEscapement 
						0, // nOrientation 
						FW_NORMAL, // nWeight 
						FALSE, // bItalic 
						FALSE, // bUnderline 
						0, // cStrikeOut 
						GB2312_CHARSET, // nCharSet 
						OUT_DEFAULT_PRECIS, // nOutPrecision 
						CLIP_DEFAULT_PRECIS, // nClipPrecision 
						DEFAULT_QUALITY, // nQuality 
						DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
						(LPCTSTR)(((CMFCFontComboBox*)GetDlgItem(IDC_MFCFONTCOMBO1))->GetSelFont())); // lpszFac
		((CEdit*)GetDlgItem(IDC_EDIT1))->SetFont(f);
	}

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CloopFileCreateToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CloopFileCreateToolDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CloopFileCreateToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CloopFileCreateToolDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	// TODO: 在此处添加消息处理程序代码
	CRect rect;
	//创建文字编辑子对话框
	((CEdit*)(GetDlgItem(IDC_EDIT_FOR_USR_FONT_DISP)))->GetWindowRect(rect);
	childDlgDispUsrFont.MoveWindow(rect); 
}
