#pragma once
#include "DlgChildDrawWords.h"

// CDlgRepaitWords 对话框
#define ID_SYS_MENU_CLOSE		0x0000f060
class CDlgRepaitWords : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRepaitWords)

public:
	CDlgRepaitWords(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgRepaitWords();

// 对话框数据
	enum { IDD = IDD_DIALOG_REPAINT_WORDS };
	void createDialog(void);
	void reshowDialog(void);
	CDlgChildDrawWords childDlgDrawWords;
	CBitmapButton  btn1;//用于关联按钮图片
	CBitmapButton  btn2;
	CBitmapButton  btn3;
	CBitmapButton  btn4;
	CBitmapButton  btn5;
	CBitmapButton  btn6;//用于关联按钮图片
	CBitmapButton  btn7;
	CBitmapButton  btn8;
	CBitmapButton  btn9;
	CBitmapButton  btn10;
	CBitmapButton  btn11;
	CBitmapButton  btn12;
	CBitmapButton  btn13;
	CBitmapButton  btn14;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	void InitButtonCombineWithPic(void);
	void InitRepaintArea(void);
	void SelectButton(int sel);
	void RedrawGrid(int height, int width);
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedBtnRepaint03();
	afx_msg void OnBnClickedBtnRepaint04();
	afx_msg void OnBnClickedBtnRepaint05();
	afx_msg void OnBnClickedBtnRepaint06();
	afx_msg void OnBnClickedBtnRepaint07();
	afx_msg void OnBnClickedBtnRepaint08();
	afx_msg void OnBnClickedBtnRepaint09();
	afx_msg void OnBnClickedBtnRepaint10();
	afx_msg void OnBnClickedBtnRepaint11();
	afx_msg void OnBnClickedBtnRepaint12();
	afx_msg void OnBnClickedBtnRepaint13();
	afx_msg void OnBnClickedBtnRepaint14();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
};
