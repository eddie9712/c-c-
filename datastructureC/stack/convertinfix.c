#include<stdio.h>  //convert infix format to others(not finished yet)
#include<stdlib.h>
#include<stdbool.h>
#define stacksize 50
typedef enum{
  lparen,rparen,plus,minus,times,divide,eos,operand
}precedence;
int isp[]={0,19,12,12,13,13,0};  //the priority in stack
int icp[]={20,19,12,12,13,13,0};   //the  priority incoming
int n=0;    //information of current char
char symbol;
bool isempty();    //using stack
void push(char);
int pop();
precedence topofstack();
int top=0;      //stack part
char stack[stacksize]={'\0'};
char input[50]={'\0'};   //store the character in the array
char output[50]={'\0'};   //store the output character
int k=0;  //the current output 
precedence getoken(); 
void postfix();
void prefix();
int main()
{
  push('\0');  //push eos
  int i,a;
  push(eos);
  printf("input the format of infix:");
  scanf("%s",input); 
  postfix();
  printf("the format of postfix:\n");
  printf("%s",output);
  prefix();
  printf("the format of postfix:\n");
  printf("%s",output);
}
void postfix()   
{
   precedence token;
   while((token=getoken())!=eos)   //reading the string
   {
    if(token==operand)  //if operand
     {
        output[k]=symbol;
        k++;
     }
    else if(token==rparen)  //if right rparen
     {
        while(1)   //pop the items in stack until lparen
        {
          char temp;
          temp=pop();
          if(temp==')')
            break;
          output[k]=temp
          k++;
        }
     }
    else   
     {
       if(icp[token]<isp[topofstack()])//the symbol priority > the top of the stack   
       {
         while(icp[token]<=isp[topofstack()])  //pop until the icp>=isp 
          {
            output[k]=pop();
            k++; 
          }
       }
       push(symbol);   
     }
  }
  while(!(isempty()))  //output the remain items in stack
  {
    output[k]=pop();
    k++;2
  }
  output[k]='\0';
}
void prefix()  //turn the infix into prefix
{


}
precedence getoken()
{
   symbol=input[n];
   switch (symbol)
   {
     case '(': return lparen;
     case ')': return lparen;
     case '+': return plus;
     case '-': return minus;
     case '*': return times;
     case '/': return divide;
     case '\0': return eos;
     default : return operand;
   } 
   n++;
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
void push(char data)
{
    stack[top]=data;
    top++;
}
int pop()
{
   char temp;
   temp=stack[top-1];
   top--; 
   return temp;
}
precedence topofstack()
{
  char l;
  l=stack[top-1]; 
  switch (l)
  {
     case '(': return lparen;
     case ')': return lparen;
     case '+': return plus;
     case '-': return minus;
     case '*': return times;
     case '/': return divide;
     case '\0': return eos;
     default : return operand;
  } 
}