#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
int main()
{
   int array[2];
   array[0]=2;
   array[1]=3;
   swap(&array[0],&array[1]); 
   printf("%d",array[0]);
   printf("%d",array[1]);
   
}