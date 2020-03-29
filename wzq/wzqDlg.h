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
	////////////////////////////////////////////////////下面定义的数据和函数用来被其他消息映射函数调用
	 POINT qipan[15][15];//地图数组
	 enum  CHESSPOINT{wu=1,bai,hei};//枚举结构体，类似与类。代表每一个点的可能情况
	 CHESSPOINT	 score[15][15];//对应上面的地图数组中的每个元素点
     int cishu;//第一个数为偶数，可以第一个下的棋为白,作为从游戏开始的每一次步骤
	 int scorebai;//统计白旗的得分
	 int scorehei;//统计黑旗的得分

     void setwu();//要把score数组全部内容设置为wu为什么不是自动为无？？？
	 void setvalue();//对地图数组赋值数据，//////这个要放在对话框初始化函数中，在棋盘显示出来前获取全部屏幕信息
	 void outvalue();//画出这个地图，///////这个函数要放在绘图消息映射函数里，屏幕一显示就把棋盘打印出来
     void playchess( CPoint point);//对每个点的元素类型判断，然后制棋子的形状。///////////////////////
	 void setstatus(CPoint point);//判断点击的位置，然后按次序对点设置状态     ////这两个函数放在左键单击映射函数里，只在点击的时候起作用
	 void judgexy();//依据score这个数组内的值判断输赢，这个函数要放在一直运行的函数内，不断检测输赢情况，算了放在鼠标点击里吧，每点击一次判断一次


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
