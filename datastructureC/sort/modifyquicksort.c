#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void modifyinsertionsort(int *,int,int);
void modifyquicksort(int *,int,int,int);
int partition(int *,int,int);
int main()
{
  clock_t t1,t2;
  int i,buff,m,k;
  m=0;
  k=9000;     //for the length of insertionsort 
  FILE *fin,*fout1;                   //read the file
  fin = fopen("./nearlysorted.txt","r");
  int *array=calloc(10000,sizeof(int));
   while(1)
  {
    if(m==10000)
     break;
    fscanf(fin,"%d",&buff);
    array[m]=buff;
    m++;
  }  
  fclose(fin);
  clock_t t3,t4;
  t1=clock();
  for(i=0;i<100;i++)
  {
  modifyquicksort(array,0,9999,k);
  }
  t2=clock();
  fout1=fopen("./comparersult.txt", "a");    //write the output into the a file to compare which is the fastet algorithm 
  fprintf(fout1,"the time of the modifyquicksort: %d\n",t2-t1);
  //fprintf(fout1,"the time of the modifyquicksort: %d\n",t4-t3);
  fclose(fout1);
}
void modifyquicksort(int array[],int p,int r,int k)
{
  int q;
   if(r-p+1>k)
   {
    if(p<r)
    {
     q=partition(array,p,r);  
     modifyquicksort(array,p,q-1,k);
     modifyquicksort(array,q+1,r,k); 
    }
   }
  modifyinsertionsort(array,r-p+1,p);
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
void modifyinsertionsort(int array[],int n,int a) //insertionsort 要一起modify
{
   int i,key,j;
   for(i=a;i<n;i++)
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