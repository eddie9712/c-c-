#include<stdio.h>   //implement stack using queues
#include<stdlib.h>
#include<queue>
using namespace std;
queue<int> q1;
void push(int);
int pop();
int main()
{
   int i;
   int input;
   int k;
   for(i=0;i<5;i++)   //push 5 items
   {
     scanf("%d",&input);
     push(input);
   }
   printf("pop from the stack");
   for(i=0;i<3;i++)   //pop 3 items  
   {
    k=pop();
    printf("%d",k);
   }
}
void push(int x)  //push
{
  q1.push(x);
}
int pop()
{
   int out;
   if(q1.empty())
   {
      printf("queue empty");
   }
   else
   {
      int n,i,temp;
      n=q1.size; 
      for(i=0;i<n-1;i++)
      {
        temp=q1.front;
        q1.pop();
        q1.push(temp);
      }         
   }
   out=q1.front;
   q1.pop();
   return out;
}

