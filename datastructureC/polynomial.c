#include<stdio.h>   //to do tha addition of the polynomial
#include<stdlib.h>
#define maxsize 15
void add(int *,int *,int *,int,int);
typedef struct{
   int poly[maxsize];
   int high;
}polynomial;
polynomial a,b,d;
  int main()
{
    int i,j;
    for(i=0;i<maxsize;i++)
   {
      a.poly[i]=0;
   }  
  printf("input the highest degree of the polynomial: ");
  scanf("%d",&(a.high));
  printf("input the coefficient of the polynomial:(if=0,input0)");
   for(i=0;i<a.high;i++)
  {
     scanf("%d",&(a.poly[i]));

  }
  printf("input the highest degree of the polynomial2: ");
  scanf("%d",&(b.high));
  printf("input the coefficient of the polynomial2: ");
   for(i=0;i<a.high;i++)
  {
     scanf("%d",&(a.poly[i]));

  }
}
  void add(int [],int [],int [],int,int)
{
   
 


}  
