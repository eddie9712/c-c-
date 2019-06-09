#include<stdio.h>
#include<stdlib.h>
#define maxterms 100 //the most terms of poly
#define maxpoly 15   //the most amounts of polynmial
typedef struct 
{
  int coef;
  int expon;
}polynmial;
void readpoly(polynomial [][maxterms],int [],int *);
void printpoly(polynomial [],int);
int main()
{
 int x;
 polynmial terms[maxpoly][maxterms];
 int nes[maxpoly];
 int totalpoly=0;
 readpoly(terms,nes,&totalpolys);
 readpoly(terms,nes,&totalpolys);
 printpoly(terms[0],nes[0]);
 printpoly(terms[1],nes[1]);
}
void printpoly(polynomial terms[],int n)
{
  int i;
  for(i=0;i<n-1;i++)
   printf("%dx^%d+",terms[i].coef,terms[i].coef);
  printf("%dx^%d",terms[n-1].coef,terms[n-1].expon);
}
void readpoly(polynomial terms[][],int nes[],int *total)
{
  int i,expon,nterms;
  int coef;
  printf("enter the number of terms in your polynomial\n");
  scanf("%d",&nterms);
  while(nterms>=maxterms)
  {
    printf("too many terms in the polynmial")
  }
  for(i=0;i<nterms;i++)
  {
    printf("coefficient");
    scanf("%d",&coef);
    printf("exponent: ");
    scanf("%d",&expon);
    terms[*total][i].coef=coef;
    terms[*total][i].expon=expon;
  }
   nes[*total]=nterms;
   (*total)++;
}
