// DlgChildDrawWords.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "loopFileCreateTool.h"
#include "DlgChildDrawWords.h"
#include "afxdialogex.h"


// CDlgChildDrawWords �Ի���

IMPLEMENT_DYNAMIC(CDlgChildDrawWords, CDialogEx)

CDlgChildDrawWords::CDlgChildDrawWords(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgChildDrawWords::IDD, pParent)
{

}

CDlgChildDrawWords::~CDlgChildDrawWords()
{
}

void CDlgChildDrawWords::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgChildDrawWords, CDialogEx)
END_MESSAGE_MAP()


// CDlgChildDrawWords ��Ϣ�������
int Gridwidth	= 20;
void CDlgChildDrawWords::RedrawGrid(int height, int width)
{
	CDC *pDC	= GetDC();
	HDC hDC		= pDC->m_hDC;
#if 1
	LOGFONT lf;
	memset(&lf,0,sizeof(LOGFONT)); 
	lf.lfHeight	= 20;
	lstrcpy(lf.lfFaceName,_T("����"));
	HFONT hFont = CreateFontIndirect( &lf) ;
	CFont* pFont = CFont::FromHandle( hFont );
	CFont* pOldFont = pDC->SelectObject( pFont );
#endif
	MAT2 mat2;
	GLYPHMETRICS gm;
	memset(&mat2, 0, sizeof(mat2));
	mat2.eM11.value = 1; 
    mat2.eM22.value = 1; 

	TCHAR ch = _T('��');
	DWORD dwNeedSize = pDC->GetGlyphOutline(ch,GGO_METRICS,&gm,0,NULL,&mat2);

	if (dwNeedSize > 0 && dwNeedSize < 0xFFFF)
	{ 
		byte *m_pBuf = NULL;
		int m_nWidth = 0, m_nHeight = 0;
		m_pBuf = (byte*)(malloc(dwNeedSize));
		if ( m_pBuf)
		{
			//��ȡ�ַ�ͼ�ε����ݵ���������
			pDC->GetGlyphOutline(ch,GGO_BITMAP,&gm,dwNeedSize,m_pBuf,&mat2);
			m_nWidth = gm.gmBlackBoxX;
			m_nHeight = gm.gmBlackBoxY;

			//����ֻ��Ϊ���ڵ��Դ��鿴���ݣ����Բ�Ҫ
			//����ͼ��ÿ��ռ�õ��ֽ�����
			int nByteCount = ((gm.gmBlackBoxX + 31) >> 5) << 2;   
			//��ʾÿ��ͼ�ε����ݡ�   
			for (int i = 0; i < gm.gmBlackBoxY; i++)
			{
				for (int j = 0; j < nByteCount; j++)
				{
					BYTE btCode = m_pBuf[i* nByteCount + j];
					CString str;

					str.Format( _T("%x "),btCode );
					OutputDebugString( str );                        
				}
				OutputDebugString(_T("/r/n"));
			} 
			//////////////////////////////////////////////////////////////////////////
		}

		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		CRect rect;
		GetClientRect(&rect);
		ClientToScreen(rect);
		int x = rect.left + 10;
		int y = rect.top + 10;
		int dx = 0;
		int dy = 0;
		int dsize = 10;

		byte* pStr = m_pBuf;
		//����ͼ��ÿ��ռ�õ��ֽ���(4�ֽڶ���)
		int nLen = ((m_nWidth +31) >> 5) << 2; 
		for( int j=0; j<m_nHeight; j++)
		{
			dy = y + j * dsize;
			for(int i=0; i<nLen; i++)
			{
				dx = x + i * 8 * dsize; 
				byte val = *pStr;
				for( int bit=0; bit<8 ; bit++)
				{
					dc.FillSolidRect(dx, dy, dsize, dsize, (val & (0x80 >> bit)) ? RGB(0,0,255) : pDC->GetPixel(0,0));
					dx = dx + dsize;    
				}
				pStr++;
			}
		}
		Invalidate( TRUE );
	}

	pDC->SelectObject(pOldFont);
	DeleteObject(hFont);
	ReleaseDC(pDC);
}


