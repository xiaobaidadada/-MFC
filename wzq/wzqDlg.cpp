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

BOOL Dlg::OnInitDialog()//��Ҫ����Ϣӳ�亯�����ڶԻ�����ʾ֮ǰ�Զ�����
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
		setvalue();//��ȡ���ڴ�С��������������еĵ�
		cishu=2;//����Ϸ��ʼ֮ǰ�����Ϊż
		scorebai=1,scorehei=1;//�ʼ��Ϸǰ���ǵ�ֵ��Ϊ1����Ϊ���1�����������������ͬ����������һ��1�����Ѿ����ڵ���һ������
	    setwu();//�������������score������ֵ����WΪwu


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
		outvalue();	//��������
	
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
void Dlg::OnLButtonDown(UINT nFlags, CPoint point) //���������Ϣӳ�亯��,��Ϸ�Ľ�����ȫ��������������������/////////////
{                                                                                                                //////////
setstatus(point);//�жϵ���ĵ��λ�ã����ð�����������״̬                                                        //////////
playchess(point);	//�ж�ÿ��ͼ���״̬�������л�ͼ     
judgexy();//�ж���Ӯ���                                                            //////////
	CDialog::OnLButtonDown(nFlags, point);//���ø���ĺ�����                                                     //////////
}                                                                                                                //////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void Dlg::setvalue()//�Ե�ͼ���鸳ֵ���ݣ����ȵ��Ѿ���ȡ����Ļ�ͻ�����С
 {   	CRect rect;
		GetClientRect(&rect);//��ȡ�û���Ұ����С
		int mx=(rect.right-30)/14;//��x��ֳ�14��15����
		int my=(rect.bottom-30)/14;//ͬ��
		 int b=0;//ÿһ���ϵ�yֵ����b����λ���ȵ�myֵ
		for(int hang=0;hang<15;hang++){
			int c=0;//ÿһ�С�������
           
			for(int lie=0;lie<15;lie++){
				qipan[hang][lie].x=mx*c+15;
				qipan[hang][lie].y=my*b+15;
				c++;
			}
			b++;
		}


 }



	 
	 
 void Dlg:: outvalue(){//���������ͼ
  POINT oldcity;//��һ��λ��
   
	CClientDC dc(this);//��ȡDC
  for(int i=0;i<15;i++)//�Ȼ�15��
  {   oldcity=dc.MoveTo(qipan[0][i]);//0�����һ�У�I����ÿһ��
      dc.LineTo(qipan[14][i]);

  }
  for(int i2=0;i2<15;i2++){//ͬ��
	   oldcity=dc.MoveTo(qipan[i2][0]);
      dc.LineTo(qipan[i2][14]);

  }

}

 void Dlg::playchess( CPoint point){

int a=10; 	 int sizeqizi=7; 
CClientDC dc(this);//��ȡDC,���ڻ�����
			  
	for(int hang=0;hang<15;hang++)
	{   
		for(int lie=0;lie<15;lie++)
		{
		  if( score[hang][lie]==wu);
		  else if(score[hang][lie]==bai)
		  {

			int a=dc.Ellipse(qipan[hang][lie].x-sizeqizi,qipan[hang][lie].y-sizeqizi , qipan[hang][lie].x+sizeqizi,qipan[hang][lie].y+sizeqizi);//��qipanΪ���Ļ�ԭ��
		
		  }
		   else if(score[hang][lie]==hei)
		   {CGdiObject  * oldbrush=dc.SelectStockObject(BLACK_BRUSH);

			int a=dc.Ellipse(qipan[hang][lie].x-sizeqizi,qipan[hang][lie].y-sizeqizi , qipan[hang][lie].x+sizeqizi,qipan[hang][lie].y+sizeqizi);//��qipanΪ���Ļ�ԭ��
			
		   dc.SelectObject(oldbrush);
		   }
	          
				
			
		}	 
		}


	}

 void Dlg:: setstatus(CPoint point){//��Ϸ���п�ʼ��ͨ���жϵ���Ĵ��������һ��������¼�������浽ÿһ����ļ�¼�����

			  int a=10;  //����һ������Χ�����εĳ��ȵ�һ��೤
			  
	for(int hang=0;hang<15;hang++)
	{  
		for(int lie=0;lie<15;lie++){
	         
	         if(qipan[hang][lie].x- point.x  <=a  && qipan[hang][lie].y-point.y<= a   && qipan[hang][lie].x-point.x>=(-a) && qipan[hang][lie].y-point.y>=(-a) )
			 { //�������if��Χ�������������ȫ�������ö�����ı���ĵ���бȽϵó���һ���������ڵķ�Χ����
				 if(score[hang][lie]==wu){
				if( cishu%2==0)score[hang][lie]=bai;//��
				else score[hang][lie]=hei;//��
				 }
			 }
		
		}
			 }
		 cishu++;//ÿ���һ�θı���ż��
	}
	

 void Dlg:: setwu()
 {//��score��������ȫ������Ϊwu
	
			 for(int h=0;h<15;h++)
				 for(int l=0;l<15;l++)
					 score[h][l]=wu;
 }

 void Dlg:: judgexy()//�Ծ��ƽ����ж�,�ȼ����ж�
 {
	 for(int hang=0;hang<15;hang++){//�ȶ�ÿһ�н����ж�
		 for(int lie=0;lie<15;lie++){
   
	
			 if(score[hang][lie]==bai&&score[hang][lie-1]==score[hang][lie]&&hang!=0&&lie!=0){scorebai++;scorehei=1;}
			 else if(score[hang][lie]==hei&& score[hang][lie-1]==score[hang][lie] &&hang!=0&&lie!=0){scorehei++;scorebai=1;}
			 //�������жϣ�����Ҫȷ����Ϊ�׻��ߺڣ������ޣ����Ϊ�׻��ߺڣ�Ҫ�ж��Ƿ��ǰ��һ�������һ��Ҫ+1�������Ϊ�ڰ׻��߲�һ��ִ��else�ж�
			 //�ܵ���˵������1.ȷ���ڰ� 2.�ж��Ƿ���ǰһ����ͬ 3.ȷ�����ǵ�һ������Ԫ�أ���Ϊ��һ������Ԫ��ǰ��û��Ԫ�أ����ܻᷢ�����벻��������
			 else {
				 if(scorebai==5||scorehei==5)break;//����Ѿ�����5�ˣ�����Ͳ����ټ����
				 scorebai=1,scorehei=1;}//���ͻȻ���������������Ҳ�����5����Ҫ��Ϊ1
		
	 }
		 if(scorebai==5)MessageBox("�׷�ʤ");
			 else if(scorehei==5)MessageBox("�ڷ�ʤ");//������Ժ��Ҫ������Ӯ�ж�
    scorebai=1,scorehei=1;//ÿһ����󼸸�����һ����жϵ������û�гɹ���Ҫ����
 }



	for(int lie=0;lie<15;lie++){//���ڶ�ÿһ�н����ж�
		 for(int hang=0;hang<15;hang++)
		 {  
			 
			 if(score[hang][lie]==bai&&score[hang][lie]==score[hang-1][lie]&&hang!=0&&lie!=0){scorebai++;scorehei=1;}
			 else if(score[hang][lie]==hei&&score[hang][lie]==score[hang-1][lie]&&hang!=0&&lie!=0){scorehei++;scorebai=1;}//ͬ��
			 else {
				 if(scorebai==5||scorehei==5)break;//����Ѿ�����5�ˣ�����Ͳ����ټ����
				 scorebai=1,scorehei=1;}//���ͻȻ���������������Ҳ�����5����Ҫ��Ϊ1

		 }
		  if(scorebai==5)MessageBox("�׷�ʤ");
			 else if(scorehei==5)MessageBox("�ڷ�ʤ");//������Ժ��Ҫ������Ӯ�ж�
    scorebai=1,scorehei=1;//���жϵ������û�гɹ���Ҫ����
	}


		
////////////////////////////////////////////////////////////////////////////////////////////////////////
       
		 for(int xie=14;xie>=0;xie--)
		 {//�����ϰ�ǵ�б�жϣ��ϰ벿xiede��ֵ���ڶ�Ӧ���е�x=y��ֵ
		 for(int hang=xie,int lie=0;hang>=0&& lie<=xie;hang--,lie++)//ÿһ��б�д����xie��0,��ؼ������к�����ͬ���仯�ģ���Ȼ������forѭ������������������
		 { 

			 if(score[hang][lie]==bai&&score[hang][lie]==score[hang+1][lie-1]&&hang!=xie&&lie!=0){scorebai++;scorehei=1;}
			 else if(score[hang][lie]==hei&&score[hang][lie]==score[hang+1][lie-1]&&hang!=xie&&lie!=0){scorehei++;scorebai=1;}//�жϵ�һ���±��Ƕ����for�ĵ�һ����Σ������еļӼ�������for��
			   else {
				 if(scorebai==5||scorehei==5)break;//����Ѿ�����5�ˣ�����Ͳ����ټ����
				 scorebai=1,scorehei=1;}//���ͻȻ���������������Ҳ�����5����Ҫ��Ϊ1
			 }
		 
			 if(scorebai==5)MessageBox("�׷�ʤ");
			 else if(scorehei==5)MessageBox("�ڷ�ʤ");//������Ժ��Ҫ������Ӯ�ж�
    scorebai=1,scorehei=1;//�жϵ������û�гɹ���Ҫ����
		 }


     for(int yxxie=14;yxxie>=1;yxxie--)//������б���ж�,Ҳ�Ǵ������ϵ��ж�
	 {  
		 for(int hang=14,int lie=yxxie;hang>=yxxie&& lie<=14;hang--,lie++)
	       //����������Ҫ���������������µ�һ���㣬���������һ����hang��lie����ֵ��������ʲô���仯��ʲô///////this is most importend  ֻҪ�������������ô���䶼û��
	   
	 
		 { if(score[hang][lie]==bai&&score[hang][lie]==score[hang+1][lie-1]&&hang!=14&&lie!=xie){scorebai++;scorehei=1;}//ͬ��
		 else if(score[hang][lie]==hei&&score[hang][lie]==score[hang+1][lie-1]&&hang!=14&&lie!=xie){scorehei++;scorebai=1;}
			   else {
				 if(scorebai==5||scorehei==5)break;//����Ѿ�����5�ˣ�����Ͳ����ټ����
				 scorebai=1,scorehei=1;}//���ͻȻ���������������Ҳ�����5����Ҫ��Ϊ1
			 }
		 
			 if(scorebai==5)MessageBox("�׷�ʤ");
			 else if(scorehei==5)MessageBox("�ڷ�ʤ");//������Ժ��Ҫ������Ӯ�ж�
    scorebai=1,scorehei=1;//�жϵ������û�гɹ���Ҫ����
		 }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


   for(int zxxie=14; zxxie>=0; zxxie--)//������Ե���0˵���������м��������,�����ϵ�����
   {  
	   for(int hang= zxxie,int lie=0;hang<=14;hang++,lie++)
	   {       if(score[hang][lie]==bai&&score[hang][lie]==score[hang-1][lie-1]&&hang!=zxxie&&lie!=0){scorebai++;scorehei=1;}
			    else if(score[hang][lie]==hei&& score[hang][lie]==score[hang-1][lie-1]&&hang!=zxxie&&lie!=0){scorehei++;scorebai=1;}
				else {
				 if(scorebai==5||scorehei==5)break;//����Ѿ�����5�ˣ�����Ͳ����ټ����
				 scorebai=1,scorehei=1;}//���ͻȻ���������������Ҳ�����5����Ҫ��Ϊ1
			 }
		 
			 if(scorebai==5)MessageBox("�׷�ʤ");
			 else if(scorehei==5)MessageBox("�ڷ�ʤ");//������Ժ��Ҫ������Ӯ�ж�
    scorebai=1,scorehei=1;//�жϵ������û�гɹ���Ҫ����
		 }



   for(int ysxie=14;ysxie>=1;ysxie--)//���ﲻ��0��Ϊ�������м��������
   {      
	   for(int hang=0,int lie=ysxie;lie<=14;hang++,lie++)//Ϊʲô���ܼ�hang<=ysxie&& ����������
	   { if(score[hang][lie]==bai&&score[hang][lie]==score[hang-1][lie-1]&&hang!=0&&lie!=ysxie){scorebai++;scorehei=1;}
	   else if(score[hang][lie]==hei&&score[hang][lie]==score[hang-1][lie-1]&&hang!=0&&lie&&ysxie){scorehei++;scorebai=1;}
			   else {
				 if(scorebai==5||scorehei==5)break;//����Ѿ�����5�ˣ�����Ͳ����ټ����
				 scorebai=1,scorehei=1;}//���ͻȻ���������������Ҳ�����5����Ҫ��Ϊ1
			 }
		 
			 if(scorebai==5)MessageBox("�׷�ʤ");
			 else if(scorehei==5)MessageBox("�ڷ�ʤ");//������Ժ��Ҫ������Ӯ�ж�
    scorebai=1,scorehei=1;//�жϵ������û�гɹ���Ҫ����
		 }



	
   
   
   
   
   }



