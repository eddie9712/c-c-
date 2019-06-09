#include<stdio.h>
#include<stdlib.h>
#define max 1000
void find(float *,float *,int n);
int main()
{
   float array1[max];
   float array2[max]; 
   int number,i,j;
   printf("input the number of the data: ");
   scanf("%d",&number);
   printf("input the data: ");
   for(i=0;i<number;i++)
  {
     scanf("%f",&(array1[i]));
  }
   find(array1,array2,number);
}
 void find(float array1[],float array2[],int n)
{
  int k,count,h;
   for(k=0;k<n;k++)
  {
    if((int)array1[k]==array1[k])
   { 
     count++;
     array2[k]=array1[k];
   }
    else
   array2[k]=0;
  }
  printf("%d\n",count);
  for(h=0;h<n;h++)
 {
   if(array2[h]!=0)
    printf("%.0f\n",array2[h]);
 }


}




