#include<stdio.h>  //implemention of the quicksort in version of radomized
#include<stdlib.h>   //quicksort having the worst case when the partitioning routine produces one subproblem 
#include<time.h>    //for random piviot
int randomizedPartition(int *,int,int); 
int partition(int*,int,int);
void randomizedQuicksort(int *,int,int);
void swap(int *,int *);
int main()           //with n – 1 elements and one with 0 elements so we use the randomized quickaort
{
   int n,i;
   printf("numbers of the input:");
   scanf("%d",&n);
   int *array=calloc(n,sizeof(int));
   for(i=0;i<n;i++)
   {
       scanf("%d",&array[i]);
   }
   randomizedQuicksort(array,0,n-1);
   printf("the outcome of the sorting:");
   for(i=0;i<n;i++)
   {
      printf("%d\n",array[i]); 
   }
}
void randomizedQuicksort(int array[],int p,int r)
{
  int q;
  if(p<r)
  {
    q=randomizedPartition(array,p,r);
    randomizedQuicksort(array,p,q-1);
    randomizedQuicksort(array,q+1,r);
  }
}
int randomizedPartition(int array[],int p,int r)
{
  srand(time(NULL));
  int seed=rand()%(r-p)+p;   //choose the index in random(p~r)
  printf("seed:%d@",seed);
  swap(&array[r],&array[seed]);   //swap array[r] and array[seed] 
  return partition(array,p,r); 
}
int partition(int array[],int p,int r)
{
   int i,j;
   int key=array[r];
   i=p-1;
   for(j=p;j<r;j++)
   {
     if(array[j]<key)  //swap
     {
       i++;
       swap(&array[i],&array[j]);
     }
   }
   swap(&array[i+1],&array[r]);
   return i+1;   
}
void swap(int *a,int *b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}