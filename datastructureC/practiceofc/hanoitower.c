#include<stdio.h>   //try to implement hanoi tower of recursive
#include<stdlib.h>
void hanoi(int,char,char,char);
int main()
{
  int n;
  char a='a',b='b',c='c';
  printf("input the number of disk:");
  scanf("%d",&n);
  hanoi(n,a,b,c);
}
void hanoi(int n,char res,char temp,char dest)
{
    if(n==1)
    {
     printf("%c->%c\n",res,dest);
    }
    else
    {
      hanoi(n-1,res,dest,temp);    //first step:move n-1
      printf("%c->%c\n",res,dest);//second step
      hanoi(n-1,temp,res,dest);//third step
    }
}    