#include<stdio.h>
#include<stdlib.h>
int find(int *,int);
 int main()
{
   int number,i,l;
  scanf("%d",&number);  //input the times to find
   for(i=0;i<number;i++)
  {
   int array[100];
   int p=0;
   int j;
    int k;
   char y;
   int temp=0;
   do
   {
    scanf("%d",&array[p]);
    p++;
   }while(y=getchar()!='\n');
   int n=array[0];
   int *array2=calloc(n,sizeof(int));
    for(j=0;j<n;j++)
   {
      array2[j]=array[j+1];
   }
   temp=find(array2,n);
   free(array2); 
   printf("%d\n",temp); 
}
}
int find(int array2[],int n)
{
  int i;
   int temp1;
  int count;
  for(i=0;i<n;i++)
 {
    temp1=array2[i];  
    count=0;
    while(1)
  { 
     if(count>n-1)
    {
       return temp1;
    }
    if((array2[count]==temp1)&&(count!=i))
   { 
     break;
   }
    else
    count++;
  }
 }
}

