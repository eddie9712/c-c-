#include<stdio.h>   //repeatedly swapping the adjacent element for sorting
#include<stdlib.h>
void bubblesort(int [],int);   
void copyarray(int [],int [],int);
void printarray(int [],int);
int main()
{
    int i,input,n=10;
    int a[10];
    int b[10];
    for(i=0;i<10;i++)  //input ten data 
    {
        scanf("%d",&input);
        a[i]=input;
    }
    bubblesort(a,n);
    printarray(a,n);
}
void copyarray(int a[],int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
      b[i]=a[i];
    }
}
void printarray(int *ptr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
      printf("%d",ptr[i]);
    }
}
void bubblesort(int a[],int n)    
{
   int i,j,f;
   for(i=0;i<n-1;i++)
  {
    f=0;
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {  
        int temp;
        temp=a[j+1];
        a[j+1]=a[j];
        a[j]=temp;
        f=1;
      }   
    }
    if(f==0)
     break;
  }
}