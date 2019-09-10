#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define n 10
void insert();
void insort();
int main()
{
 int i,input;
 int a[11];
 for(i=1;i<=10;i++)
 {
    scanf("%d",&input);
    a[i]=input;
 }
 insort(a);//sort from a[1] to a[10]
}
void insort(int a[])
{
   int i;
   a[0]=INT_MIN;
   for(i=2;i<=10;i++)
   {
      insert(a,a[i],i-1);
   }
}
void insert(int a[],int r,int i)
{
  int j;
  j=i;
  while(r<a[j])
  {
    a[j+1]=a[j];
    j--;
  } 
  a[j+1]=r;
}