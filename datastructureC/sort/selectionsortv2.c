#include<stdio.h>
#include<stdlib.h>
void selectionsort(int [],int);
void print(int [],int);
int main()
{
   int i,input,n=5;
   int a[5];
   for(i=0;i<5;i++)
   {
     scanf("%d",&input);
     a[i]=input;
   }
   selectionsort(a,n);
   print(a,n);
}
void selectionsort(int a[],int n)
{
  int i,j,min;
  for(i=0;i<n-1;i++)
  {
   min=i;
   for(j=i+1;j<n;j++)  //choose the min at the i+1 data
   {
    if(a[j]<a[min])
      min=j;
   }
   if(min!=i)   //swap 
   {
      int temp;
      temp=a[min]; 
      a[min]=a[i];
      a[i]=temp;
   }
  }
}
void print(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
     printf("%d",a[i]);
   } 
}