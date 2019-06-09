#include<stdio.h> //iterrative
#include<stdio.h>
int fibonacci(int);
int main()
{
    int n;
    printf("input the number:");
    scanf("%d",&n);
    printf("%d",fibonacci(n));
}
int fibonacci(int n)
{
   if(n==1)
     return 0;
   if(n==2)
     return 1;
   int a=0,b=1,c,i;
   for(i=0;i<n-2;i++)
   {
     c=a+b;
     a=b;
     b=c;
   }
    return c;
}