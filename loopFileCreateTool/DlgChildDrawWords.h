#pragma once


// CDlgChildDrawWords 对话框

class CDlgChildDrawWords : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgChildDrawWords)

public:
	CDlgChildDrawWords(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgChildDrawWords();

// 对话框数据
	enum { IDD = IDD_DIALOG_DRAW_WORDS };

	void RedrawGrid(int height, int width);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()

};
