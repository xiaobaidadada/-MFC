// wzqDlg.h : header file
//

#if !defined(AFX_WZQDLG_H__7AE327DA_F1D9_473C_8856_12CD5E3FD4AF__INCLUDED_)
#define AFX_WZQDLG_H__7AE327DA_F1D9_473C_8856_12CD5E3FD4AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// Dlg dialog

class Dlg : public CDialog
{
// Construction
public:
	Dlg(CWnd* pParent = NULL);	// standard constructor
	////////////////////////////////////////////////////���涨������ݺͺ���������������Ϣӳ�亯������
	 POINT qipan[15][15];//��ͼ����
	 enum  CHESSPOINT{wu=1,bai,hei};//ö�ٽṹ�壬�������ࡣ����ÿһ����Ŀ������
	 CHESSPOINT	 score[15][15];//��Ӧ����ĵ�ͼ�����е�ÿ��Ԫ�ص�
     int cishu;//��һ����Ϊż�������Ե�һ���µ���Ϊ��,��Ϊ����Ϸ��ʼ��ÿһ�β���
	 int scorebai;//ͳ�ư���ĵ÷�
	 int scorehei;//ͳ�ƺ���ĵ÷�

     void setwu();//Ҫ��score����ȫ����������ΪwuΪʲô�����Զ�Ϊ�ޣ�����
	 void setvalue();//�Ե�ͼ���鸳ֵ���ݣ�//////���Ҫ���ڶԻ����ʼ�������У���������ʾ����ǰ��ȡȫ����Ļ��Ϣ
	 void outvalue();//���������ͼ��///////�������Ҫ���ڻ�ͼ��Ϣӳ�亯�����Ļһ��ʾ�Ͱ����̴�ӡ����
     void playchess( CPoint point);//��ÿ�����Ԫ�������жϣ�Ȼ�������ӵ���״��///////////////////////
	 void setstatus(CPoint point);//�жϵ����λ�ã�Ȼ�󰴴���Ե�����״̬     ////���������������������ӳ�亯���ֻ�ڵ����ʱ��������
	 void judgexy();//����score��������ڵ�ֵ�ж���Ӯ���������Ҫ����һֱ���еĺ����ڣ����ϼ����Ӯ��������˷����������ɣ�ÿ���һ���ж�һ��


// Dialog Data
	//{{AFX_DATA(Dlg)
	enum { IDD = IDD_WZQ_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZQDLG_H__7AE327DA_F1D9_473C_8856_12CD5E3FD4AF__INCLUDED_)
