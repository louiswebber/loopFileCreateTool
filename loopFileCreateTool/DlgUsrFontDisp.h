#pragma once


// CDlgUsrFontDisp �Ի���

class CDlgUsrFontDisp : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUsrFontDisp)

public:
	CDlgUsrFontDisp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgUsrFontDisp();

// �Ի�������
	enum { IDD = IDD_DIALOG_DISP_USR_FONT };

	void usrFontDispInitDialog(void);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
