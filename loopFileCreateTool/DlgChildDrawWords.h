#pragma once


// CDlgChildDrawWords �Ի���

class CDlgChildDrawWords : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgChildDrawWords)

public:
	CDlgChildDrawWords(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgChildDrawWords();

// �Ի�������
	enum { IDD = IDD_DIALOG_DRAW_WORDS };

	void RedrawGrid(int height, int width);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()

};
