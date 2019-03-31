#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionsort(int *,int);
void quicksort(int *,int,int);
void generate(int *,int *);
int partition(int *,int,int);
int main()
{
  FILE *fout1;
  int i,time1,time2;
  clock_t t1,t2,t3,t4; 
  int *array=calloc(10000,sizeof(int));
  int *array1=calloc(10000,sizeof(int));
  generate(array,array1);   //generate a file with 10000 number
  t1=clock();
  for(i=0;i<100;i++)
  {
  insertionsort(array1,10000);
  }
  t2=clock();
  t3=clock();
  for(i=0;i<100;i++)
  {
    quicksort(array,0,9999);
   }
  t4=clock();
  free(array);
  free(array1);
  fout1=fopen("./comparersult.txt", "w+");    //write the output into the a file to compare which is the fastet algorithm 
  fprintf(fout1,"the time of the insertionsort: %d\n",t2-t1);
  fprintf(fout1,"the time of the quicksort: %d\n",t4-t3);
  fclose(fout1);
}
void quicksort(int array[],int p,int r)
{
   int q;
   if(p<r)
   {
    q=partition(array,p,r);  
    quicksort(array,p,q-1);
    quicksort(array,q+1,r); 
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
void insertionsort(int array1[],int n)
{
   int i,key,j;
   for(i=1;i<n;i++)
  {
    key=array1[i];
    j=i-1;
    while(j>=0&&array1[j]>key)
   {
     array1[j+1]=array1[j];
     j--;
   }
   array1[j+1]=key;  
  }
}
void generate(int array[],int array1[])  //generate 10000 "nearly" sorted numbers input and put them into a input file,and put them into two array for sorting
{
   int temp[10000];
   int i,j;
   for(i=0;i<10000;i++)  //generate 10000 numbers in order 
   {
     temp[i]=i+1;
   }
   srand(time(NULL));
   for(j=0;j<1000;j++)//choosing 1000 pairs to exchange randomly
   {
      int n,temp1;
      n=rand()%9999+1;
      temp1=temp[n];//change a[n] and a[n-1]
      temp[n]=temp[n+1];
      temp[n+1]=temp1;
   }
   for(i=0;i<10000;i++)  //put the "nearly" sorted array into the two arrays  
   {
     array[i]=temp[i];
     array1[i]=temp[i];
   }
   FILE *fout;
   fout=fopen("./nearlysorted.txt", "w+");    //write the "nearly" sorted array into a file for next work
   for(i=0;i<10000;i++)
   {
      fprintf(fout,"%d\n",array[i]);
   }
   fclose(fout);
}