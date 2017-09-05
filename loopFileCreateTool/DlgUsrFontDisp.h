#pragma once


// CDlgUsrFontDisp 对话框

class CDlgUsrFontDisp : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUsrFontDisp)

public:
	CDlgUsrFontDisp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgUsrFontDisp();

// 对话框数据
	enum { IDD = IDD_DIALOG_DISP_USR_FONT };

	void usrFontDispInitDialog(void);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
