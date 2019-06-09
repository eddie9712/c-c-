#include<stdio.h>  //implement permtation of a string of recursive version
#include<stdlib.h>
void perm(char *,int,int);
void swap(char *,char *);
int main()
{
 int l,i;
 char c;
 printf("input the string length:");
 scanf("%d",&l);
 printf("input the string to permutate:");
 char *array=calloc(l,sizeof(char));
 scanf("%s",array);
 perm(array,0,l-1);
}
void perm(char array[],int i,int n)
{
   int k,j;
   if(i==n)
  {
    for(k=0;k<=n;k++)
    {
       printf("%c",array[k]);
    }
     printf("\n");
  }
  for(j=i;j<=n;j++)
  {
    swap(&array[i],&array[j]);
    perm(array,i+1,n);
    swap(&array[i],&array[j]);
  }
}
void swap(char *a,char *b)
{
  char temp;
  temp=*b;
  *b=*a;
  *a=temp;
}