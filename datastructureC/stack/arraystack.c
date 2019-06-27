#include<stdio.h>    //a module of stack which using array(type of integer)
#include<stdlib.h>
#include<stdbool.h>
#define stacksize 10
bool isempty();
void push(int *,int);
int pop(int *);
bool isfull();
int topofstack(int *);
int top=0;
int main()   //for testing the function of stack
{
  int i,k;
  int *stack=calloc(stacksize,sizeof(int));
  for(i=0;i<5;i++) //push five items
  {
    scanf("%d",&k);
    push(stack,k);
  }
  for(i=0;i<3;i++)//pop out 3items
  {
    int o;
    o=pop(stack);     
    printf("the number poped out:%d",o);
  }
  // int p=topofstack(stack);
 //  printf("%d",p);   //print the top of the stack
}
bool isempty()
{
   if(top==0)
  {
    printf("the stack is empty!");
    return true;
  }
  else 
   return false;
}
bool isfull()
{
   if(top==stacksize)
    {
     printf("stack full");    
     return true;
    }
    else 
     return false;
}
void push(int stack[],int data)
{
   if(isfull())
   {
      return;
   }
   else   //PUSH THE ELEMENT IN 
   {
    stack[top]=data;
    top++;
   }
}
int pop(int stack[])
{
  if(isempty())
  {
  }
  else
  {
   int temp;
   temp=stack[top-1];
   top--; 
   return temp;
  }
}
int topofstack(int stack[])
{
   return stack[top-1]; 
}