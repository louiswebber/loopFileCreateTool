// DlgUsrFontDisp.cpp : 实现文件
//

#include "stdafx.h"
#include "loopFileCreateTool.h"
#include "DlgUsrFontDisp.h"
#include "afxdialogex.h"


// CDlgUsrFontDisp 对话框

IMPLEMENT_DYNAMIC(CDlgUsrFontDisp, CDialogEx)

CDlgUsrFontDisp::CDlgUsrFontDisp(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgUsrFontDisp::IDD, pParent)
{

}

CDlgUsrFontDisp::~CDlgUsrFontDisp()
{
}

void CDlgUsrFontDisp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgUsrFontDisp, CDialogEx)
END_MESSAGE_MAP()


// CDlgUsrFontDisp 消息处理程序

void CDlgUsrFontDisp::usrFontDispInitDialog(void)
{
}
