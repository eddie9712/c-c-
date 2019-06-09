#include<stdio.h>   //counting  sort practice 
#include<stdlib.h>
void countsort(int *,int *,int);
int main()
{
  int i=0;
  int arraya[10]={0,6,4,6,3,0,7,7,5,6};//input the array for range 0-7
  int *arrayb=calloc(10,sizeof(int));
  for(i=0;i<10;i++) //print the array
  {
    printf("%d\n",arraya[i]);
  }
  countsort(arraya,arrayb,8);//do the countin sort
  for(i=0;i<10;i++)//check the outcome
  {
      printf("%d\n",arrayb[i]);
  }
}
void countsort(int arraya[],int arrayb[],int k)
{
   int i;
   int *arrayc=calloc(k,sizeof(int));  //workplace
   for(i=0;i<10;i++)
   {
    arrayc[arraya[i]]++;    
   } 
   for(i = 1;i<k;i++)
   {
    arrayc[i]=arrayc[i]+arrayc[i-1];
   }
   for(i =9;i>=0; i--)
   {
       arrayb[arrayc[arraya[i]]]=arraya[i];
       arrayc[arraya[i]]--;
   }
}