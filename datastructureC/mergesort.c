#include<stdio.h>
#include<stdlib.h>
#define max 10
void merge(int *,int,int,int);
void mergesort(int *,int,int); 
int main()
{
  int n,i;
  int array[max];
  printf("input the numbers for sorting:");
  scanf("%d",&n);
  printf("input:");
  for(i=0;i<n;i++)
  {
     scanf("%d",&array[i]);
  }
  mergesort(array,1,n);
  printf("output:");
  for(i=0;i<n;i++)
  {
     printf("%d\n",array[i]);
  }
}
void merge(int array[],int p,int q,int r)
{
  int l1,l2,i,j,k;
  l1=q-p+1;
  l2=r-q;
  int *left=calloc(l1+1,sizeof(int));
  int *right=calloc(l2+1,sizeof(int));
  for(i=0;i<l1;i++) 
  {
    left[i]=array[i+p-1];
  }
  for(j=0;j<l2;j++)
  {
    right[j]=array[j+q];
  }
  left[l1]=10000;  
  right[l2]=10000;
  i=0;
  j=0;
  for(k=p-1;k<r;k++)
  {
   if (left[i]>=right[j]) {
     array[k]=right[j];
     j++;
   }
    else
    {
      array[k]=left[i];
      i++;
    }
  }
  free(left);
  free(right); 
}
void mergesort(int array[],int p,int r)
{
 int q;
 if(p<r)
 {
   q=(p+r)/2;    
   mergesort(array,p,q);  //left part
   mergesort(array,q+1,r);  //right part
   merge(array,p,q,r); 
 }
}