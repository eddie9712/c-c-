#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct
{
  int coef;
  int expon;

}polynomial
polynomial terms[max];
int main()
{
  readpoly();
  printpoly();

}
void printpoly(polynomial terms [],int n)
{
 int i;
 for(i=0;i<n-1;i++)
  printf("%dx^%d\n")




}
void readpoly()
{




}
