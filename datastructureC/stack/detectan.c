#include<stdio.h>   //detect is the input the form of a^nb^n(n>=0)
#include<stdlib.h>
#define stacksize 20
#include<stdbool.h>
bool isempty();
void push(char);
char pop();
bool isvalid();
int top=0;
char input[stacksize]={'\0'};
char stack[stacksize]={'\0'};
int main()
{
  printf("input the string"); 
  scanf("%s",input);
  if(isvalid())
  {
    printf("the input string is valid");
  }
  else
  {
    printf("input is not valid");
  }
}
bool isvalid()
{
   int n=0; 
   int flag=0;
   while(input[n]!='\0')     //get token
   {
     if(input[n]=='a')
      {
         if(flag==1)
        {
           return false;
        }
         else
        {
          push('a');
          n++;
        }
      }
    else
     {
        flag=1; 
        if(isempty())
         return false;
        else
        {
           pop();           
           n++;
        }
     }
   }   //end while
   if(isempty())
   {
      return true;
   }
   else
   {
       return false;
   }
}
bool isempty()
{
   if(top==0)
  {
    return true;
  }
  else 
   return false;
}
void push(char c)
{
    stack[top]=c;
    top++;
}
char pop()
{
   char temp;
   temp=stack[top-1];
   top--; 
   return temp;
}
