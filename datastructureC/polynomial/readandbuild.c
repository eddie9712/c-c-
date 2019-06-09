#include<stdio.h>
#include<stdlib.h>
#define max 100
char  str[100]={'0'};
int length=0;
void readpoly();
void printpoly();
typedef struct{
  int coef;
  int exp;
}polynomial;
polynomial array[max];
void main()
{
 readpoly();
 printpoly();
}
void readpoly()
{
  int i=0;
  int k=0;
  printf("input the polynomial:(ax^b+cx+d)");
  fgets(str,sizeof(str),stdin);
  while(str[i]!='\0')
  {
    if((str[i]!='x')&&(str[i]!='+')&&(str[i]!='-'))
    {
      array[k].coef=str[i];
      i++;
      if(str[i+2]!='^')
       array[k].exp=0;
    }
      else if(str[i]=='^')
    {  
      array[k].exp=str[i+1];
      i+=2;
    }
    else
      i++;
    length=k;
  }
}
void printpoly()
{
   int i=0;
   printf("output:\n");  
  for(i=0;i<=length;i++)
  {  
    printf("%c\n",array[i].coef);
    printf("%c\n",array[i].exp);
  }
