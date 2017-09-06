// DlgRepaitWords.cpp : 实现文件
//

#include "stdafx.h"
#include "loopFileCreateTool.h"
#include "DlgRepaitWords.h"
#include "afxdialogex.h"


// CDlgRepaitWords 对话框

IMPLEMENT_DYNAMIC(CDlgRepaitWords, CDialogEx)

CDlgRepaitWords::CDlgRepaitWords(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgRepaitWords::IDD, pParent)
{
}

CDlgRepaitWords::~CDlgRepaitWords()
{
}

void CDlgRepaitWords::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRepaitWords, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_REPAINT01, &CDlgRepaitWords::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_REPAINT02, &CDlgRepaitWords::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BTN_REPAINT03, &CDlgRepaitWords::OnBnClickedBtnRepaint03)
	ON_BN_CLICKED(IDC_BTN_REPAINT04, &CDlgRepaitWords::OnBnClickedBtnRepaint04)
	ON_BN_CLICKED(IDC_BTN_REPAINT05, &CDlgRepaitWords::OnBnClickedBtnRepaint05)
	ON_BN_CLICKED(IDC_BTN_REPAINT06, &CDlgRepaitWords::OnBnClickedBtnRepaint06)
	ON_BN_CLICKED(IDC_BTN_REPAINT07, &CDlgRepaitWords::OnBnClickedBtnRepaint07)
	ON_BN_CLICKED(IDC_BTN_REPAINT08, &CDlgRepaitWords::OnBnClickedBtnRepaint08)
	ON_BN_CLICKED(IDC_BTN_REPAINT09, &CDlgRepaitWords::OnBnClickedBtnRepaint09)
	ON_BN_CLICKED(IDC_BTN_REPAINT10, &CDlgRepaitWords::OnBnClickedBtnRepaint10)
	ON_BN_CLICKED(IDC_BTN_REPAINT11, &CDlgRepaitWords::OnBnClickedBtnRepaint11)
	ON_BN_CLICKED(IDC_BTN_REPAINT12, &CDlgRepaitWords::OnBnClickedBtnRepaint12)
	ON_BN_CLICKED(IDC_BTN_REPAINT13, &CDlgRepaitWords::OnBnClickedBtnRepaint13)
	ON_BN_CLICKED(IDC_BTN_REPAINT14, &CDlgRepaitWords::OnBnClickedBtnRepaint14)
	ON_WM_MOVE()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CDlgRepaitWords 消息处理程序
void CDlgRepaitWords::createDialog(void)
{
	InitButtonCombineWithPic();
	InitRepaintArea();
}


void CDlgRepaitWords::reshowDialog(void)
{
	ShowWindow(SW_SHOW);
	childDlgDrawWords.ShowWindow(SW_SHOW);
}


void CDlgRepaitWords::InitButtonCombineWithPic(void)
{
	btn1.LoadBitmaps(IDB_BITMAP2);//关联按钮图片
	btn1.SubclassDlgItem(IDC_BTN_REPAINT01, this);
	btn1.SizeToContent();

	btn2.LoadBitmaps(IDB_BITMAP3);
	btn2.SubclassDlgItem(IDC_BTN_REPAINT02, this);
	btn2.SizeToContent();

	btn3.LoadBitmaps(IDB_BITMAP4);//关联按钮图片
	btn3.SubclassDlgItem(IDC_BTN_REPAINT03, this);
	btn3.SizeToContent();

	btn4.LoadBitmaps(IDB_BITMAP5);
	btn4.SubclassDlgItem(IDC_BTN_REPAINT04, this);
	btn4.SizeToContent();

	btn5.LoadBitmaps(IDB_BITMAP5);
	btn5.SubclassDlgItem(IDC_BTN_REPAINT05, this);
	btn5.SizeToContent();

	btn6.LoadBitmaps(IDB_BITMAP5);//关联按钮图片
	btn6.SubclassDlgItem(IDC_BTN_REPAINT06, this);
	btn6.SizeToContent();

	btn7.LoadBitmaps(IDB_BITMAP5);
	btn7.SubclassDlgItem(IDC_BTN_REPAINT07, this);
	btn7.SizeToContent();

	btn8.LoadBitmaps(IDB_BITMAP5);//关联按钮图片
	btn8.SubclassDlgItem(IDC_BTN_REPAINT08, this);
	btn8.SizeToContent();

	btn9.LoadBitmaps(IDB_BITMAP5);
	btn9.SubclassDlgItem(IDC_BTN_REPAINT09, this);
	btn9.SizeToContent();

	btn10.LoadBitmaps(IDB_BITMAP5);
	btn10.SubclassDlgItem(IDC_BTN_REPAINT10, this);
	btn10.SizeToContent();

	btn11.LoadBitmaps(IDB_BITMAP5);//关联按钮图片
	btn11.SubclassDlgItem(IDC_BTN_REPAINT11, this);
	btn11.SizeToContent();

	btn12.LoadBitmaps(IDB_BITMAP5);
	btn12.SubclassDlgItem(IDC_BTN_REPAINT12, this);
	btn12.SizeToContent();

	btn13.LoadBitmaps(IDB_BITMAP5);
	btn13.SubclassDlgItem(IDC_BTN_REPAINT13, this);
	btn13.SizeToContent();

	btn14.LoadBitmaps(IDB_BITMAP5);
	btn14.SubclassDlgItem(IDC_BTN_REPAINT14, this);
	btn14.SizeToContent();
}


void CDlgRepaitWords::SelectButton(int sel)
{
		GetDlgItem(IDC_BTN_REPAINT01)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT01)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT02)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT02)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT03)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT03)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT04)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT04)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT05)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT05)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT06)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT06)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT07)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT07)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT08)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT08)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT09)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT09)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT10)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT10)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT11)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT11)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT12)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT12)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT13)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT13)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
		GetDlgItem(IDC_BTN_REPAINT14)->ModifyStyleEx(WS_EX_STATICEDGE,0);
		GetDlgItem(IDC_BTN_REPAINT14)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 

		GetDlgItem(sel)->ModifyStyleEx(0,WS_EX_STATICEDGE);
		GetDlgItem(sel)->SetWindowPos(0,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME); 
}


void CDlgRepaitWords::InitRepaintArea(void)
{
	if(NULL == childDlgDrawWords.m_hWnd)
	{
		//创建文字编辑子对话框
		childDlgDrawWords.Create(IDD_DIALOG_DRAW_WORDS,this);
		
		CRect rect;
		((CEdit*)(GetDlgItem(IDC_EDIT_DLG_DRAW_WORDS)))->GetWindowRect(rect);
		childDlgDrawWords.MoveWindow(rect);	
	}
}


void CDlgRepaitWords::OnBnClickedButton1()
{
	SelectButton(IDC_BTN_REPAINT01);
}


void CDlgRepaitWords::OnBnClickedButton2()
{
	SelectButton(IDC_BTN_REPAINT02);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint03()
{
	SelectButton(IDC_BTN_REPAINT03);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint04()
{
	SelectButton(IDC_BTN_REPAINT04);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint05()
{
	SelectButton(IDC_BTN_REPAINT05);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint06()
{
	SelectButton(IDC_BTN_REPAINT06);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint07()
{
	SelectButton(IDC_BTN_REPAINT07);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint08()
{
	SelectButton(IDC_BTN_REPAINT08);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint09()
{
	SelectButton(IDC_BTN_REPAINT09);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint10()
{
	SelectButton(IDC_BTN_REPAINT10);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint11()
{
	SelectButton(IDC_BTN_REPAINT11);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint12()
{
	SelectButton(IDC_BTN_REPAINT12);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint13()
{
	SelectButton(IDC_BTN_REPAINT13);
}


void CDlgRepaitWords::OnBnClickedBtnRepaint14()
{
	SelectButton(IDC_BTN_REPAINT14);
}

void CDlgRepaitWords::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);

	// TODO: 在此处添加消息处理程序代码
	CRect rect;
	//创建文字编辑子对话框
	((CEdit*)(GetDlgItem(IDC_EDIT_DLG_DRAW_WORDS)))->GetWindowRect(rect);
	childDlgDrawWords.MoveWindow(rect);
}


void CDlgRepaitWords::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(ID_SYS_MENU_CLOSE == nID)
	{
		childDlgDrawWords.ShowWindow(SW_HIDE);
	}
	else
	{
	}
	CDialogEx::OnSysCommand(nID, lParam);
}
