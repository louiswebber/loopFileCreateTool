
// loopFileCreateToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "loopFileCreateTool.h"
#include "loopFileCreateToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CloopFileCreateToolDlg �Ի���



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


// CloopFileCreateToolDlg ��Ϣ�������

BOOL CloopFileCreateToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//HBITMAP hBmp=LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP1));   
	//((CButton*)GetDlgItem(IDC_BUTTON1))->SetBitmap(hBmp);
	ShowWindow(SW_SHOWNORMAL) ;

	{
		//�������ֱ༭�ӶԻ���
		CRect rect;
		((CEdit*)(GetDlgItem(IDC_EDIT_FOR_USR_FONT_DISP)))->GetWindowRect(rect);
		childDlgDispUsrFont.Create(IDD_DIALOG_DISP_USR_FONT,this);
		childDlgDispUsrFont.MoveWindow(rect); 
		childDlgDispUsrFont.InitDialog();
		childDlgDispUsrFont.ShowWindow(SW_SHOW);
	}

	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	char ret = TRUE;
	//ret = AddFontResource(_T("..\\res\\����.TTF"));
	if(FALSE == ret)
	{
		//MessageBox(_T("�ֿⲻ���ڣ�"), _T("����"));
		((CMFCFontComboBox*)GetDlgItem(IDC_MFCFONTCOMBO1))->SelectFont(_T("Arial"));
	}
	else
	{
		//::SendMessage( HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
		((CMFCFontComboBox*)GetDlgItem(IDC_MFCFONTCOMBO1))->SelectFont(_T("����"));
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

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CloopFileCreateToolDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CloopFileCreateToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CloopFileCreateToolDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	// TODO: �ڴ˴������Ϣ����������
	CRect rect;
	//�������ֱ༭�ӶԻ���
	((CEdit*)(GetDlgItem(IDC_EDIT_FOR_USR_FONT_DISP)))->GetWindowRect(rect);
	childDlgDispUsrFont.MoveWindow(rect); 
}
