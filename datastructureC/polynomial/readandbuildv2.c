#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct
{
  int coef;
  int expon;

}polynomial
int main()
{
  int n;
  poliynomial terms[max];
  printf("enter the terms of the polynomial:");
  scanf("%d",&n);
  readpoly(terms,n);
  printpoly(terms,n);

}
void printpoly(polynomial terms [],int n)
{
 int i;
 for(i=0;i<n-1;i++)
  printf("%dx^%d+",terms[i].coef,terms[i].expon);
 printf("%dx^%d\n",terms[n-1].coef,terms[i].expon);
}
void readpoly(polynomial terms[],int n)
{
  int i,expon,coef;
  if(n>max){
    printf("too many terms in your polymial!");
  }
  for(i=0;i<n;i++){
   printf("coefficient: ");
   scanf("%d",&coef);
   printf("exponent: ");
   terms[i].coef=coef;
   terms[i].expon=expon;
  }
}
