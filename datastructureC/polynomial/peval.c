//to find the value of a polynomial
#include<stdio.h>
#include<math.h>
typedef struct 
{
  int coef;
  int expon;   
}polynomial;
int peval(ploynomial terms[],int number,int length)
{
  int i,result;
  for(i=0;i<length;i++)
  {
   result=terms[i].coef*pow(number,terms[i].expon);    
  }
}