#include<stdio.h>
#include<stdlib.h>
#define max1 100
#define max2 10000
typedef struct 
{
    int coef;
    int expon;
}polynomial;
void multipoly();
int main()
{
    int first,second,i,j;
    polynomial terms1[max];
    polynomial terms2[max];
    polynomial  terms3[max];
    printf("enter the terms of first polynomial:");  //input the polynomial
    scanf("%d",&first);
    printf("enter the first polynomial:");
    for(i=0;i<first;i++)
    {
      printf("coefficient:");
      scanf("%d",terms1[i].coef);
      printf("exponent:");
      scanf("%d",terms1[i].expon);
    }
    printf("enter the terms of second polynomial:");
    scanf("%d",&second);
    printf("enter the first polynomial:");
    for(j=0;j<second;j++)
    {
       printf("coefficient:");
      scanf("%d",terms2[i].coef);
      printf("exponent:");
      scanf("%d",terms2[i].expon);
    }
    multipoly(terms1,terms2,terms3,first,second);

}
void multipoly(polynomial terms1[],polynomial terms2[],polynomial terms3[],int a,int b)
{
  int i,j,expon3,coef3;
  for(i=0;i<a;i++)
  {
    for(j=0;j<b;j++)
    {
      expon3=terms1[i].expon+terms2[i].expon;
      coef3=terms1[i].coef*terms2[i].coef;
      terms3[expon3].coef+=coef3;  //same coef accumulate  expon for inde
      
    }
  }
}

