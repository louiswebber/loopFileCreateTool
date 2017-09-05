
// loopFileCreateToolDlg.h : ͷ�ļ�
//

#pragma once
#include "DlgUsrFontDisp.h"

#define FILE_CONFIG_NAME	"config.ini"
// CloopFileCreateToolDlg �Ի���
class CloopFileCreateToolDlg : public CDialogEx
{
// ����
public:
	CloopFileCreateToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOOPFILECREATETOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	CDlgUsrFontDisp childDlgDispUsrFont;		//�û��ֿ���ʾ�Ӵ���
	FILE *pFileConfig;
	CFile fileConfig;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMove(int x, int y);
};
