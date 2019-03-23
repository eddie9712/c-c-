#include<stdio.h>
#include<stdlib.h>
void insertionsort(int *,int);
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
  insertionsort(array,n);
  fout=fopen("./output.txt", "w+");//output the file
  fprintf(fout,"%d\n",n);
   for(i=0;i<n;i++)
  {
     fprintf(fout,"%d\n",array[i]);
  }
 fclose(fout);
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
