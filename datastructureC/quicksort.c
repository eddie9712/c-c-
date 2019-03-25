#include<stdio.h>
#include<stdlib.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
int main()
{            
  int n,i,buff,k;
  k=0;
  FILE *fin,*fout;                   //read the file
  fin = fopen("./input.txt","r");
  fscanf(fin,"%d",&n);
  int *array=calloc(n,sizeof(int));
    while(1)
  {
    if(k==n)
     break;
    fscanf(fin,"%d",&buff);
    array[k]=buff;
    k++;
  }  
  fclose(fin);
  quicksort(array,0,n-1);
  fout=fopen("./output.txt", "w+");//output the file
  fprintf(fout,"%d\n",n);
   for(i=0;i<n;i++)
  {
     fprintf(fout,"%d\n",array[i]);
  }
 fclose(fout);
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