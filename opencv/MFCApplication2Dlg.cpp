
// MFCApplication2Dlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
#include "afxdialogex.h"
#include <opencv2/opencv.hpp>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace cv;
using namespace std;
// 對 App About 使用 CAboutDlg 對話方塊
CEdit *wedit;
CString str;
Mat flipping,dst,original,gaussianoutput,sobelxoutput,sobelyoutput;
int alpha_slider;
const  int alpha_slider_max = 100;
double alpha;
double beta;
void sobely(Mat input)   //detection the edge of y-direction
{
    	int i, j,m,n;
	int sobelyfilter[3][3] = { 
		-1,-2,-1,
		0,0,-0,
		1,2,1
	};
	int sum=0;
	int width = input.cols;
	int height = input.rows;
	 Mat sobely(height,width, CV_8U, Scalar(0));   //output image
	for (i=0;i<height-2;i++)       
	{
		for (j=0;j<width-2;j++)
		{
			sum = 0;
			for (m = 0; m < 3; m++)    //caculate the outcome of the filter
			{
				 for (n=0;n<3;n++)
				 {
					 sum+=sobelyfilter[m][n]*input.at<uchar>(m+i, n+j);
				 }
			}
			if (sum > 255)
			{
				sum = 255;
			}
			else if(sum<0)
			{
				sum = 0;
			}
			sobely.at<uchar>(i+1,j+1)=sum;//the pixel of the output image
		}
	}
	sobelyoutput=sobely;
}
void sobelx(Mat input)   //detection the edge of x-direction
{
    	int i, j,m,n;
	int sobelxfilter[3][3] = { 
		1,0,-1,
		2,0,-2,
		1,0,-1
	};
	int sum=0;
	int width = input.cols;
	int height = input.rows;
	 Mat sobelx(height,width, CV_8U, Scalar(0));   //output image
	for (i=0;i<height-2;i++)       
	{
		for (j=0;j<width-2;j++)
		{
			sum = 0;
			for (m = 0; m < 3; m++)    //caculate the outcome of the filter
			{
				 for (n=0;n<3;n++)
				 {
					 sum+=sobelxfilter[m][n]*input.at<uchar>(m+i, n+j);
				 }
			}
			if (sum > 255)
			{
				sum = 255;
			}
			else if(sum<0)
			{
				sum = 0;
			}
			sobelx.at<uchar>(i+1,j+1)=sum;//the pixel of the output image
		}
	}
	sobelxoutput=sobelx;
}
void gaussianfilter(Mat input)   //smoothing the picture
{
   	int i, j,m,n;
	int gaussianfilter[3][3] = { 
		1,2,1,
		2,4,2,
		1,2,1
	};
	int sum=0;
	int width = input.cols;
	int height = input.rows;
	printf("hi");
	 Mat gaussian(height,width, CV_8U, Scalar(0));   //output image
	for (i=0;i<height-2;i++)       
	{
		for (j=0;j<width-2;j++)
		{
			sum = 0;
			for (m = 0; m < 3; m++)    //caculate the outcome of the filter
			{
				 for (n=0;n<3;n++)
				 {
					 sum+=gaussianfilter[m][n]*input.at<uchar>(m+i, n+j);
				 }
			}
			gaussian.at<uchar>(i+1,j+1)=sum / 16;//the pixel of the output image
		}
	}
	gaussianoutput=gaussian;
}
void trackbar(int , void *)   //control tracker
{
	alpha=(double)alpha_slider / alpha_slider_max;
  	beta = (1.0 - alpha); 
	addWeighted(original,alpha,flipping,beta,0,dst);
	imshow("blending",dst);
}
//void mouse_callback()  
//{

//}
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()
// CMFCApplication2Dlg 對話方塊

CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)    
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication2Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication2Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication2Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication2Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication2Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication2Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication2Dlg::OnBnClickedButton12)
END_MESSAGE_MAP()

// CMFCApplication2Dlg 訊息處理常式
BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 將 [關於...] 功能表加入系統功能表。
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。
void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCApplication2Dlg::OnBnClickedButton3()  //for button 1.1
{
	Mat img = imread("./dog.bmp",1);
	original = img;
	if (!img.empty())
	{
		namedWindow("test", WINDOW_AUTOSIZE);
		imshow("test",img);
		cout << "height:" <<img.size() .height<<"\n";
		cout << "width:" << img.size().width << "\n";
		waitKey(0);
		destroyWindow("test");
	}
	else
	{
		printf("open fail");
	}
}
void CMFCApplication2Dlg::OnBnClickedButton5()    //image flipping
{
	Mat img = imread("./dog.bmp",1);
	int width, height, i, j,times;
	Vec3b temp;
    height=img.size() .height;   
	width=img.size().width ;
	times = width /2;
	for (i = 0;i<height;i++)  
	{
		for (j = 0; j < times; j++)
		{
		    temp=img.at<Vec3b>(i,j);     //sawp the chanel of pixel B,R
			img.at<Vec3b>(i,j ) = img.at<Vec3b>(i,width-j-1);
			img.at<Vec3b>(i,width-j-1)=temp;
		}
	}
	flipping = img;
	imshow("test",img);
}
void CMFCApplication2Dlg::OnBnClickedButton4()   //for color conversion
{
	Mat img = imread("./color.png",1);
	int x, y, i, j, temp;
	y=img.size() .height;   //get the size of picture
	x=img.size().width ;
	for (i=0;i<y;i++)
	{
		for (j=0;j<x;j++)
		{
			temp=img.at<Vec3b>(j,i)[0];     //sawp the chanel of pixel B,R
			img.at<Vec3b>(j, i)[0] = img.at<Vec3b>(j, i)[1];
			img.at<Vec3b>(j,i)[1]=temp;
		  	
			temp=img.at<Vec3b>(j,i)[2];   //swap the channel of pixel G,B
			img.at<Vec3b>(j, i)[2] = img.at<Vec3b>(j, i)[1];
			img.at<Vec3b>(j,i)[1]=temp;
		}
	}
	imshow("test",img);
}
void CMFCApplication2Dlg::OnBnClickedButton6()    //for picture blending
{
	Mat imgoriginal, flipping;
	imgoriginal = imread("./dog,bmp");
	namedWindow("blending",WINDOW_AUTOSIZE);   //create window
	createTrackbar("blending", "blending",&alpha_slider,alpha_slider_max, trackbar);
	trackbar(alpha_slider,0);
	waitKey(0);
}
void CMFCApplication2Dlg::OnBnClickedButton7()   //global threshold
{
	Mat img = imread("./QR.png",1);
	imshow("original",img);
	Mat output;
	threshold( img,output, 80,255, 3);
	imshow("output",output);
}
void CMFCApplication2Dlg::OnBnClickedButton8()   //local threshold
{
    Mat img = imread("./QR.png",1);
   	imshow("original",img);
	Mat output;
	cvtColor(img,output,CV_BGR2GRAY);
	adaptiveThreshold(output,img,255,0,0,19,1);
    imshow("output",img);
}
void CMFCApplication2Dlg::OnBnClickedButton1()
{
	wedit = (CEdit*)GetDlgItem(IDC_EDIT1);
     wedit->GetWindowText(str);
	wedit->SetWindowText(str);         
	float angle = _ttof(str);
	cout << angle;
    wedit = (CEdit*)GetDlgItem(IDC_EDIT2);
     wedit->GetWindowText(str);
	wedit->SetWindowText(str);         
	float scale= _ttof(str);
	cout << scale;
    wedit = (CEdit*)GetDlgItem(IDC_EDIT3);
     wedit->GetWindowText(str);
	wedit->SetWindowText(str);         
	float Tx= _ttof(str);
	cout << Tx;
    wedit = (CEdit*)GetDlgItem(IDC_EDIT4);
     wedit->GetWindowText(str);
	wedit->SetWindowText(str);         
	float Ty= _ttof(str);
	cout << Ty;
	Mat img=imread("./OriginalTransform.png", 1);
	imshow("test",img);
	Mat dst1,dst2;
	Point2f center(130,125);
	Mat rotmat=getRotationMatrix2D(center,angle,scale);
	warpAffine(img,dst1,rotmat,img.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());
	Point2f srctri[] =
	{
		Point2f(0,0),
		Point2f(130,125),
		Point2f(140,135)
	};
     Point2f dsttri[] =
	{
		Point2f(Tx,Ty),
		Point2f(130+Tx,125+Ty),
		Point2f(140+Tx,135+Ty)
	};
	 Mat warp = getAffineTransform(srctri,dsttri);
     warpAffine(dst1,dst2,warp,img.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());
	 imshow("test",dst2);
}
void CMFCApplication2Dlg::OnBnClickedButton2()   //for perspective transform
{
	Mat img = imread("./PerspectiveTransform.png");



}
void CMFCApplication2Dlg::OnBnClickedButton9()   //for gaussian filter
{
	Mat gray;
	Mat img=imread("./School.jpg",1);
	cvtColor(img,gray,CV_BGR2GRAY);
	imshow("original",gray);
	gaussianfilter(gray);     //gaussian filter working
	imshow("after smoothing",gaussianoutput);
}
void CMFCApplication2Dlg::OnBnClickedButton10()   //sobel x
{
	Mat gray;
	Mat img = imread("./School.jpg",1);
    cvtColor(img,gray,CV_BGR2GRAY);
    imshow("original",gray);
	sobelx(gray);     //detection the edge of the picture
	imshow("after sobeling",sobelxoutput);
}
void CMFCApplication2Dlg::OnBnClickedButton11()   //sobel y
{
   	Mat gray;
	Mat img = imread("./School.jpg",1);
    cvtColor(img,gray,CV_BGR2GRAY);
    imshow("original",gray);
	sobely(gray);     //detection the edge of the picture
	imshow("after sobeling",sobelyoutput);
}
void CMFCApplication2Dlg::OnBnClickedButton12()   //magnitde
{
	int i, j;
	Mat gray;
	Mat img = imread("./School.jpg",1);
	 cvtColor(img,gray,CV_BGR2GRAY);
	int width = img.cols;
	int height = img.rows;
	double sumofsquare;
	double x, y;
	double pixel;
	Mat magnitudeoutput(height,width, CV_8U, Scalar(0));   //output image
	sobelx(gray);
	sobely(gray);
	for (i=1;i<height-1;i++)
	{
	   for (j=1;j<width-1;j++)
 	  {
		   x = pow(sobelxoutput.at<uchar>(i, j), 2);   //x^2
		   y = pow(sobelyoutput.at<uchar>(i, j), 2);  //y^2
		   sumofsquare= x + y;
		   pixel=sqrt(sumofsquare);
		   if (pixel > 255)
			   pixel = 255;
		   else if (pixel < 0)
			   pixel = 0;
		   magnitudeoutput.at<uchar>(i, j) = pixel;
		}
     }
	imshow("outcome",magnitudeoutput);
}
