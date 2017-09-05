
// loopFileCreateToolDlg.h : 头文件
//

#pragma once
#include "DlgUsrFontDisp.h"

#define FILE_CONFIG_NAME	"config.ini"
// CloopFileCreateToolDlg 对话框
class CloopFileCreateToolDlg : public CDialogEx
{
// 构造
public:
	CloopFileCreateToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOOPFILECREATETOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	CDlgUsrFontDisp childDlgDispUsrFont;		//用户字库显示子窗口
	FILE *pFileConfig;
	CFile fileConfig;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMove(int x, int y);
};
