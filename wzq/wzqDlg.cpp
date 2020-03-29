// wzqDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wzq.h"
#include "wzqDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


/////////////////////////////////////////////////////////////////////////////
// Dlg dialog

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(Dlg, CDialog)
	//{{AFX_MSG_MAP(Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SYSCOMMAND()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dlg message handlers

BOOL Dlg::OnInitDialog()//重要的消息映射函数，在对话框显示之前自动调用
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
		setvalue();//获取窗口大小和设计棋盘上所有的点
		cishu=2;//在游戏开始之前令次数为偶
		scorebai=1,scorehei=1;//令开始游戏前他们的值都为1，因为这个1代表了如果有两个相同的棋子连在一起，1代表已经存在的上一个棋子
	    setwu();//调用这个函数把score内所有值设置W为wu


	return TRUE;  // return TRUE  unless you set the focus to a control
}


void Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	
	}
	else
	{
	

		CDialog::OnPaint();
	}
		outvalue();	//画出棋盘
	
}

HCURSOR Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL Dlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Dlg::OnLButtonDown(UINT nFlags, CPoint point) //按下左键消息映射函数,游戏的进行完全依靠这个函数，这个动作/////////////
{                                                                                                                //////////
setstatus(point);//判断点击的点的位置，设置按次序点变量的状态                                                        //////////
playchess(point);	//判断每个图点的状态变量进行绘图     
judgexy();//判断输赢情况                                                            //////////
	CDialog::OnLButtonDown(nFlags, point);//调用父类的函干嘛                                                     //////////
}                                                                                                                //////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void Dlg::setvalue()//对地图数组赋值数据，首先得已经获取的屏幕客户区大小
 {   	CRect rect;
		GetClientRect(&rect);//获取用户视野区大小
		int mx=(rect.right-30)/14;//把x轴分成14份15个点
		int my=(rect.bottom-30)/14;//同上
		 int b=0;//每一行上的y值增加b个单位长度的my值
		for(int hang=0;hang<15;hang++){
			int c=0;//每一列。。。。
           
			for(int lie=0;lie<15;lie++){
				qipan[hang][lie].x=mx*c+15;
				qipan[hang][lie].y=my*b+15;
				c++;
			}
			b++;
		}


 }



	 
	 
 void Dlg:: outvalue(){//画出这个地图
  POINT oldcity;//上一个位置
   
	CClientDC dc(this);//获取DC
  for(int i=0;i<15;i++)//先画15列
  {   oldcity=dc.MoveTo(qipan[0][i]);//0代表第一行，I代表每一列
      dc.LineTo(qipan[14][i]);

  }
  for(int i2=0;i2<15;i2++){//同上
	   oldcity=dc.MoveTo(qipan[i2][0]);
      dc.LineTo(qipan[i2][14]);

  }

}

 void Dlg::playchess( CPoint point){

int a=10; 	 int sizeqizi=7; 
CClientDC dc(this);//获取DC,用于画棋子
			  
	for(int hang=0;hang<15;hang++)
	{   
		for(int lie=0;lie<15;lie++)
		{
		  if( score[hang][lie]==wu);
		  else if(score[hang][lie]==bai)
		  {

			int a=dc.Ellipse(qipan[hang][lie].x-sizeqizi,qipan[hang][lie].y-sizeqizi , qipan[hang][lie].x+sizeqizi,qipan[hang][lie].y+sizeqizi);//以qipan为中心画原点
		
		  }
		   else if(score[hang][lie]==hei)
		   {CGdiObject  * oldbrush=dc.SelectStockObject(BLACK_BRUSH);

			int a=dc.Ellipse(qipan[hang][lie].x-sizeqizi,qipan[hang][lie].y-sizeqizi , qipan[hang][lie].x+sizeqizi,qipan[hang][lie].y+sizeqizi);//以qipan为中心画原点
			
		   dc.SelectObject(oldbrush);
		   }
	          
				
			
		}	 
		}


	}

 void Dlg:: setstatus(CPoint point){//游戏运行开始，通过判断点击的次序来标记一方，并记录下来保存到每一个点的记录变量里。

			  int a=10;  //决定一个点周围正方形的长度的一半多长
			  
	for(int hang=0;hang<15;hang++)
	{  
		for(int lie=0;lie<15;lie++){
	         
	         if(qipan[hang][lie].x- point.x  <=a  && qipan[hang][lie].y-point.y<= a   && qipan[hang][lie].x-point.x>=(-a) && qipan[hang][lie].y-point.y>=(-a) )
			 { //这里这个if范围就是拿这个点与全部的设置额数组的保存的点进行比较得出在一个正方形内的范围区域
				 if(score[hang][lie]==wu){
				if( cishu%2==0)score[hang][lie]=bai;//白
				else score[hang][lie]=hei;//黑
				 }
			 }
		
		}
			 }
		 cishu++;//每点击一次改变奇偶性
	}
	

 void Dlg:: setwu()
 {//令score数组内容全部设置为wu
	
			 for(int h=0;h<15;h++)
				 for(int l=0;l<15;l++)
					 score[h][l]=wu;
 }

 void Dlg:: judgexy()//对局势进行判断,先检查后判断
 {
	 for(int hang=0;hang<15;hang++){//先对每一行进行判断
		 for(int lie=0;lie<15;lie++){
   
	
			 if(score[hang][lie]==bai&&score[hang][lie-1]==score[hang][lie]&&hang!=0&&lie!=0){scorebai++;scorehei=1;}
			 else if(score[hang][lie]==hei&& score[hang][lie-1]==score[hang][lie] &&hang!=0&&lie!=0){scorehei++;scorebai=1;}
			 //这两个判断，首先要确定是为白或者黑，或者无，如果为白或者黑，要判断是否跟前面一样，如果一样要+1，如果不为黑白或者不一样执行else判断
			 //总的来说，就是1.确定黑白 2.判断是否与前一个相同 3.确定不是第一个数组元素，因为第一个数组元素前面没有元素，可能会发生意想不到的意外
			 else {
				 if(scorebai==5||scorehei==5)break;//如果已经等于5了，下面就不用再检测了
				 scorebai=1,scorehei=1;}//如果突然发生不连续，而且不等于5，就要清为1
		
	 }
		 if(scorebai==5)MessageBox("白方胜");
			 else if(scorehei==5)MessageBox("黑方胜");//检查完以后就要进行输赢判断
    scorebai=1,scorehei=1;//每一行最后几个连在一起的判断的情况下没有成功就要归零
 }



	for(int lie=0;lie<15;lie++){//现在对每一列进行判断
		 for(int hang=0;hang<15;hang++)
		 {  
			 
			 if(score[hang][lie]==bai&&score[hang][lie]==score[hang-1][lie]&&hang!=0&&lie!=0){scorebai++;scorehei=1;}
			 else if(score[hang][lie]==hei&&score[hang][lie]==score[hang-1][lie]&&hang!=0&&lie!=0){scorehei++;scorebai=1;}//同上
			 else {
				 if(scorebai==5||scorehei==5)break;//如果已经等于5了，下面就不用再检测了
				 scorebai=1,scorehei=1;}//如果突然发生不连续，而且不等于5，就要清为1

		 }
		  if(scorebai==5)MessageBox("白方胜");
			 else if(scorehei==5)MessageBox("黑方胜");//检查完以后就要进行输赢判断
    scorebai=1,scorehei=1;//行判断的情况下没有成功就要归零
	}


		
////////////////////////////////////////////////////////////////////////////////////////////////////////
       
		 for(int xie=14;xie>=0;xie--)
		 {//对左上半角的斜判断，上半部xiede的值等于对应行列的x=y的值
		 for(int hang=xie,int lie=0;hang>=0&& lie<=xie;hang--,lie++)//每一次斜行从最大xie到0,最关键的是行和列是同步变化的，居然可以在for循环里面设置两个变量
		 { 

			 if(score[hang][lie]==bai&&score[hang][lie]==score[hang+1][lie-1]&&hang!=xie&&lie!=0){scorebai++;scorehei=1;}
			 else if(score[hang][lie]==hei&&score[hang][lie]==score[hang+1][lie-1]&&hang!=xie&&lie!=0){scorehei++;scorebai=1;}//判断第一个下标是多大在for的第一定义段，行与列的加减靠最后的for段
			   else {
				 if(scorebai==5||scorehei==5)break;//如果已经等于5了，下面就不用再检测了
				 scorebai=1,scorehei=1;}//如果突然发生不连续，而且不等于5，就要清为1
			 }
		 
			 if(scorebai==5)MessageBox("白方胜");
			 else if(scorehei==5)MessageBox("黑方胜");//检查完以后就要进行输赢判断
    scorebai=1,scorehei=1;//判断的情况下没有成功就要归零
		 }


     for(int yxxie=14;yxxie>=1;yxxie--)//对右下斜的判断,也是从下往上的判断
	 {  
		 for(int hang=14,int lie=yxxie;hang>=yxxie&& lie<=14;hang--,lie++)
	       //条件的设置要这样来做，从左下第一个点，到右上最后一个点hang，lie两个值都经历了什么，变化了什么///////this is most importend  只要掌握了这个，怎么样变都没事
	   
	 
		 { if(score[hang][lie]==bai&&score[hang][lie]==score[hang+1][lie-1]&&hang!=14&&lie!=xie){scorebai++;scorehei=1;}//同上
		 else if(score[hang][lie]==hei&&score[hang][lie]==score[hang+1][lie-1]&&hang!=14&&lie!=xie){scorehei++;scorebai=1;}
			   else {
				 if(scorebai==5||scorehei==5)break;//如果已经等于5了，下面就不用再检测了
				 scorebai=1,scorehei=1;}//如果突然发生不连续，而且不等于5，就要清为1
			 }
		 
			 if(scorebai==5)MessageBox("白方胜");
			 else if(scorehei==5)MessageBox("黑方胜");//检查完以后就要进行输赢判断
    scorebai=1,scorehei=1;//判断的情况下没有成功就要归零
		 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   for(int zxxie=14; zxxie>=0; zxxie--)//这里可以等于0说明包括了中间的那条线,从左上到右下
   {  
	   for(int hang= zxxie,int lie=0;hang<=14;hang++,lie++)
	   {       if(score[hang][lie]==bai&&score[hang][lie]==score[hang-1][lie-1]&&hang!=zxxie&&lie!=0){scorebai++;scorehei=1;}
			    else if(score[hang][lie]==hei&& score[hang][lie]==score[hang-1][lie-1]&&hang!=zxxie&&lie!=0){scorehei++;scorebai=1;}
				else {
				 if(scorebai==5||scorehei==5)break;//如果已经等于5了，下面就不用再检测了
				 scorebai=1,scorehei=1;}//如果突然发生不连续，而且不等于5，就要清为1
			 }
		 
			 if(scorebai==5)MessageBox("白方胜");
			 else if(scorehei==5)MessageBox("黑方胜");//检查完以后就要进行输赢判断
    scorebai=1,scorehei=1;//判断的情况下没有成功就要归零
		 }



   for(int ysxie=14;ysxie>=1;ysxie--)//这里不到0因为不包括中间的那条线
   {      
	   for(int hang=0,int lie=ysxie;lie<=14;hang++,lie++)//为什么不能加hang<=ysxie&& ？？？？？
	   { if(score[hang][lie]==bai&&score[hang][lie]==score[hang-1][lie-1]&&hang!=0&&lie!=ysxie){scorebai++;scorehei=1;}
	   else if(score[hang][lie]==hei&&score[hang][lie]==score[hang-1][lie-1]&&hang!=0&&lie&&ysxie){scorehei++;scorebai=1;}
			   else {
				 if(scorebai==5||scorehei==5)break;//如果已经等于5了，下面就不用再检测了
				 scorebai=1,scorehei=1;}//如果突然发生不连续，而且不等于5，就要清为1
			 }
		 
			 if(scorebai==5)MessageBox("白方胜");
			 else if(scorehei==5)MessageBox("黑方胜");//检查完以后就要进行输赢判断
    scorebai=1,scorehei=1;//判断的情况下没有成功就要归零
		 }



	
   
   
   
   
   }



