#include<stdio.h>  //radix sort for digit d(using array)
#include<math.h>
#include<stdlib.h>
void radixsort(int *,int,int);
void insertionsort(int *,int *,int);
int main()
{
  int d,i,n;
  printf("input the digit of d");
  scanf("%d",&d);
  printf("input the  numbers of interger:");
  scanf("%d",&n);
  int *array=calloc(n,sizeof(int));
   printf("input the  numbers of radix sort:");
  for(i=0;i<n;i++)
  {
   scanf("%d",&array[i]);
  }
  radixsort(array,d,n);
  printf("output:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",array[i]);         
  }  
}
void radixsort(int array[],int d,int n)
{
  int k=1;
  int j,i;
  int *lsd=calloc(n,sizeof(int)) ;
  for(i=1;i<=d;i++)
  {
    for(j=0;j<n;j++)
    {
      lsd[j]=(array[j]/k)%10;
    }
    insertionsort(array,lsd,n);
    k*=10;
  }
}
void insertionsort(int array[],int lsd[],int n)  //using a stable sort for radix sort
{
  int i,j,key;
  int temp;
  for(j=1;j<n;j++)
  {
    i=j-1;
    key=lsd[j];
    temp=array[j];
    while(i>=0&&lsd[i]>key) 
    {
      array[i+1]=array[i];
      lsd[i+1]=lsd[i];
      i--;
    }
    array[i+1]=temp;
    lsd[i+1]=key;
  }
 // printf("@@@@@\n");
 // for(i=0;i<n;i++)
 //  printf("%d\n",lsd[i]); 
}