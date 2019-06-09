//fast version of transpose sparse matrix
#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct{
    int value;
    int row;
    int col;
}term;
void fasttranspose(term *,term *);
void printmatrix(term *,int);
int main()
{
    term a[max];
    term b[max];
    int n,i;
    printf("input the numbers of the terms:");
    scanf("%d",&n);
    a[0].value=n;
    printf("input the matrix:(first for row and col and )");
    scanf("%d,%d",&a[0].row,&a[0].col);
    printf("input the terms for matrix:");
    for(i=1;i<n;i++)
    {
      printf("row:");
      scanf("%d",&a[i].row);
      printf("col:");
      scanf("%d",&a[i].col);
    }
    printf("matrix a:\n");
    printmatrix(a);    
    fasttranspose(a,b);
    printmartix(b,n);
}
void fasttranspose(term a[],term b)
{
  int i,j,K,t,numcol,numterms;
  int rowterms[max];
  int startposition[max];
  numcol=a[0].col; //b row
  numterms=a[0].value;
  for(i=0;i<max;i++) //initialize  
    rowterms[i]=0;
  for(j=0;j<max;j++) //initialize  
    rowterms[j]=0;
  b[0].col=a[0].row;
  b[0].row=a[0].col;
  b[0].value=a[0].value;
  if(numterms>0)
  {
    for(i = 1; i <=numterms; i++)
    {
      rowterms[a[i].col]++;
    }
    startposition[0]=1;
    for(j=1;j<numcols;j++)
    {
      startposition[j]=startposition[j-1]+rowterms[j-1];
    }
    for(j=1;j<numterms;j++)
    {
      k=startposition[a[j].col];
      b[k].col=a[j].row;
      b[k].row=a[j].col;
      b[k].value=a[j].value;
      startposition[a[j].col]++; 
    }
  }  
}
void printmatrix(term k[],int n)  //print matrix for sparse
{
  int i;
  printf("sparse martix:\n");
  printf("b[0] %d %d %d\n",k[0].row,k[0].col,k[0].value);
  for(i=1;i<n;i++)
  {
    printf("b[0] %d %d %d\n",k[i].row,k[i].col,k[i].value);
    printf("\n");
  }
}