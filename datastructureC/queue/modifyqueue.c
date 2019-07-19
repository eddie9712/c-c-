#include<stdio.h>  //modify the circular queue with a tag which can help us to decide it is full or not
#include<stdlib.h>  //however it cost the waste of time  then circular queue
#include<stdbool.h>
#define n 5
void enqueue(int);
int dequeue();
void print();
int queue[5];
int rear=0;
int front=0;
bool flag=false;
int main()
{
  int i,input;
  for(i=0;i<5;i++) //initialize
  {
    queue[i]=0;   
  }
  printf("input 4 items:");
  for(i=0;i<4;i++)  //enqueue  4 items
  {
    scanf("%d",&input);
    enqueue(input);
  }
  print();
  printf("dequeue:\n");
  printf("%d",dequeue());
  printf("%d",dequeue());
  printf("input 2 items:");
  for(i=0;i<2;i++) //enqueue 2 items
  {
     scanf("%d",&input);
     enqueue(input); 
  }
  dequeue();
  dequeue();
  print();//print the queue
}
void enqueue(int item)
{
  if((rear==front)&&(flag==true)) //queue full
 {
    printf("queue full!");
    return ; 
 }
  else
  {
    rear=(rear+1)%n;
    queue[rear]=item;
    if(rear==front)
     flag=true;
  }
}
int dequeue()
{
  int item;
  if((front==rear)&&(flag==false))
   {
      printf("queue empty");
   }
  else
  {
    front=(front+1)%n;
    item=queue[front];
    if(front==rear)
      flag=false;
    return item;
  }
}
void print()
{
  int i,k;
  k=front;
  for(i=0;i<n;i++)
  {
    k=(k)%n; 
    if(queue[k]!=0)
    {
      printf("%d",queue[k]);
    }
    k++;
  }    
}