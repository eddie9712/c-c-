#include<stdio.h>
#include<stdlib.h>
void change(int *);
int main()
{
   int array[10];
   int i=0,k=1;
   for(i=0;i<10;i++)
   {
     array[i]=k;
     k++;
   }  
   for(i=0;i<10;i++) 
   {
      printf("%d",array[i]);
   }
   change(array);
   for(i=0;i<10;i++) 
   {
    printf("%d",array[i]);
   }
}
void change(int array[])
{
    array[9]=5;
    array[8]=5;
    array[7]=5;
}