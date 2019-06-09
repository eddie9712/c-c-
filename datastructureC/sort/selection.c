#include<stdio.h>
#include<stdlib.h>
int selection(int *,int,int,int);
int  partition(int *,int,int);
int main()
{
  int i,p,r;
  int array[7]={3,6,5,7,4,2,1};
  for(i=0;i<7;i++)
  {
     printf("%d\n",array[i]);
  }
  int q;
  printf("find the 3-th smallest number(expected to 3)");
  q=selection(array,0,6,3);
  //printf("%d",q);
}
int selection(int array[],int p,int r,int k)
{
   int q,i;
   if(p==r)
     return array[p];
   q=partition(array,p,r);
   i=q-p+1;
   if(i==k)
     return array[k];
   if(i>k)
   {
     selection(array,p,q-1,k);
   }
   else 
   {
      selection(array,q+1,r,k-i);
   }
}
int partition(int array[],int p,int r)
{
   int key=0,temp,i,j;
   key=array[r];
   i=p-1;
   for(j=p;j<=r-1;j++)
   {
      if(array[j]<key)
      {
       i=i+1;
       temp=array[j];//change a[j] a[i]
       array[j]=array[i];
       array[i]=temp;
      }
    }
   temp=array[r];//change a[r] a[i]
   array[r]=array[i+1];
   array[i+1]=temp;
   return i+1;
}