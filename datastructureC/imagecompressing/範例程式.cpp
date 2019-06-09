#include "stdafx.h"
#include "CImg.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace cimg_library;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	string input;
	int i,j,count=0;
	int y;
	cout << "intput the image name to compress:" ;
	cin >> input;
	CImg<unsigned char> src_image(input.c_str());//read in an image
	CImgDisplay main_disp(src_image, "Original");  //display the image of the input
	int width = src_image.width(); //get width of the image
	int height = src_image.height(); //get height of the image
	int *x = (int*)calloc(width*height, sizeof(int));
	int *y = (int*)calloc(height, sizeof(int));
	int scanlines=0;
	int numofsegment=0;
	for(i=0;i<width;i++)   
	{
       int status=0;
	   int statusbefore=0;	
		for (j=0;j<height;j++)
		{
			if (*src_image.data(i,j)==0)
			{
			   status=1;
			   if(status!=statusbefore) //not equal then record it			   
			   {
                 x[count]=j;
				 count++;
			   }		
			}
			else
			{
				status=0;
				if(status!=statusbefore)  //not equal then record it
				{
					x[count]=j-1;
					count++;
					y[i]++;
					numofsegment++;
				}
			}
			beforestatus=status;
		}
	}
    for(i=0;i<height;i++) 
	{
	  if(y[i]!=0)
	   scanlines++; 
	} 
    fp=fopen("./compressed.txt","w+")//put the compressed data into the output file
	fprintf("%d",width); //width of the image
	printf("\n");
	fprintf("%d",height); //height of the image	
	fprintf("\n");
	for(i=0;i<numofsegment*2;i++)//first linefor x,secondline for y element
	{
	  fprintf("%d",x[i]);
	}
	fprintf("\n");
	for(i=0;i<height;i++)
	{
		fprintf("%d",y[i]);
	}
	fprintf("\n");
    for(i=0;i<numofsegment*2;i++) //display the text.file
	{
	  printf("%d",x[i]);
	}
    fclose(fp);    //close the file
	for(i=0;i<height;i++)
	{
	   printf("%d",y[i]);
	}
	cout<<"input the compressed file:"; //input the name of compressed file
	cin>>input;
    CImg<unsigned char> image(width,height,1,1);  //create a empty image
    image.fill(255);
	//decompress the textfile to picture
	fp=fopen("./compressed.txt","r+")//open the textfile
	int eachlineseg=0;
	int countn=0;
	char c;
    int *x1 = (int*)calloc(width*height, sizeof(int));
	int *y1 = (int*)calloc(height, sizeof(int));
	c=fgetc(fp);//read the width 
	width=(int)c-'0';
	c=fgetc(fp); //ignore the '\n'
    c=fgetc(fp); 
	height=(int)c-'0';//read the height
	c=fgetc(fp); //igonre '\n'
	while(1)  //read the x array
	{
       i=0;   
	   c=fgetc(fp); 
	   if(c=='\n')
	   break;
	   x1[i]=(int)c='0';
	   i++; 
	}
	while(1)  //read the y array
	{
       i=0;   
	   c=fgetc(fp); 
	   if(c=='\n')
	   break;
	   y1[i]=(int)c='0';
	   i++; 
	}
	int pos=0;
    for(i=0;i<height;i++)//put x arrays element back to image
	{
		int j;
		for(j=0;j<y1[i];j++)  //segment for each line
		{
           int k;      
		  for(k=x1[pos];k<=x1[pos+1];k++) //filling the block for each segment
		  {
            unsigned char* ptr = image.data(i,k); // get pointer to pixel @ 10,10
		    *ptr=0;
		  }
		}
	}
    //int grayValue = *ptr;//get grayvalue of pixel @ 10,10
	//cout << width << "\n";
	//cout << height << "\n";
	//cout << grayValue << "\n";
	//save an image with file name:"output_image.bmp"
	image.save("output_image.bmp");
	//open a window to display an image on the screen with title : "Original"
	// wait until main window is closed
	CImgDisplay main_disp(image, "Original");
	while (!main_disp.is_closed()){
    	main_disp.wait();
	}
	system("pause");
	return 0;
}


