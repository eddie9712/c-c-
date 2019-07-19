#include<stdio.h>  //using two stacks to implement the queue
#include<stdlib.h>
#include<stack>
using namespace std;
stack<int> s;
stack<int> t;
void enqueue(int);
int dequeue();
int main()
{
  int i;
  int input;
  for(i=0;i<5;i++)//enqueue 5 items
  {
   scanf("%d",&input);
   enqueue(input);
  }
  printf("dequeue:\n");
  for(i=0;i<3;i++)  //dequeue 3 items
  {
    int item;
    item=dequeue();
    printf("%d",item);
  }
}
void enqueue(int x)
{
  s.push(x); 
}
int dequeue()
{
   int temp;
   int k;
   if(t.empty())  //if empty
   {
    if(s.empty())
    {
       printf("queue empty");
    }
    else
    {
      while(!s.empty())
      {
        k=s.top;
        s.pop;
        t.push(k);
      }
    }
   }
   else   //if t not empty
   {
     temp=t.top;
     t.pop();   
   }
}