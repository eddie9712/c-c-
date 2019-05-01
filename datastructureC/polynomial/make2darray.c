#include<stdlib.h>
#include<stdio.h>
int** make2darray(int,int);
#define MALLOC(p,s) \
  if(!((p)=malloc(s))){ \
    fprintf(stderr,"insufficient memory"); \
  }
int main()
{
  int i,j;
  int **myarray;
  myarray=make2darray(5,10);
   for(i=0;i<5;i++)
  {
    for(j=0;j<10;j++){
    printf("%d",myarray[i][j]);
    }
    printf("\n");
  }

}   
int**  make2darray(int rows,int cols) 
{
   int **x,i;
   MALLOC(x,rows*sizeof(*x));
   for(i=0;i<rows;i++)
   {
     MALLOC(x[i],cols*sizeof(*x));
   }
   printf("%d",x[i]);
   return x;
}
