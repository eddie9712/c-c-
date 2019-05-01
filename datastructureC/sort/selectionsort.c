#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int SELECT(int *,int,int);
int partition();
void insertionsort(int *,int);
{
  srand(time(NULL));
  int number,i,k;
  printf("decide the number of the array:");
  scanf("%d",&number);
  int *array=calloc(number,sizeof(int));//generate the array
  for(i=0;i<number;i++)
  {
    int temp;
    temp=rand()%1000;
    array[i]=temp;
  }
    printf("the numbers of the array:");
  for(i=0;i<number;i++)//printf the array
  {
    printf("%d\n",array[i]);
  }
  SELECT();
  printf("input the i-th array be sorted:");
  scanf("%d",k);
  //printf("the i-th number of the array");
  
}
int SELECT(int array1[],int array2int n,int k)
{
  int median;
  if(n==1)
   return median;
  group=n/5;//divide into n/5+1 group
  r=n%5;
  int groupn[group][5];
  int gruopr[r];
  int count=0;
  for(i=0;i<gruop;i++) //fill in groupn
  {
    for(j=0;j<5;j++)
    {
       groupn[i][j]=array[count];
       count++;
    }
  }
  for(i=0;i<r;i++) //fill in groupr
  {
    groupr[i]=array[count]; // **
  }
  for(i=0;i<groupn;i++) //do the insertion sort
  {
    insertionsort();
  }
  insertionsort()  //insertionsort of groupr
  findmedian()//find the median of all groups
  K=SELECT();//recusive SELECT
  if(i==k)
  {
     
  }
  if(i<k)
  {

  }
  if(i>k)
  {

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
void insertionsort(int array[],int n)
{
   int i,key,j;
   for(i=1;i<n;i++)
  {
    key=array[i];
    j=i-1;
    while(j>=0&&array[j]>key)
   {
     array[j+1]=array[j];
     j--;
   }
   array[j+1]=key;  
  }

}
