#include<stdio.h>   //using the DP to solve the cutting rod(length of 10)
#include<stdlib.h>   //and find the way simutaneosly
#include<limits.h>
int main()
{
  int i,n;
  int p[11];  //the price of the rods
  int r[11];
  r[0]=0;
  p[0]=0;
  n=10;
  for(i=1;i<10;i++)     
  {
    scanf("%d",&p[i]);    
  }
  for(i=0;i<11;i++)
  {
    printf("%d",p[i]); 
  }
  int j,s,i;
  for(j=1;j<11;j++)
  {
   s=INT_MIN;
  for(i=1;i<=j;i++)
  {

  
  }
  
  }  
  

}