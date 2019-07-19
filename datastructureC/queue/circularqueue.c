#include<stdio.h>  //implement circular queue
#include<stdlib.h>  //waste the space of n-1
#define n 5
void enqueue(int);
int dequeue();
void print();
int queue[5];
int rear=0;
int front=0;
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
  rear=(rear+1)%n;
  if(rear==front) //queue full
  {
    printf("queue full!");
    if(rear==0)
    rear=n-1;
    else
    rear--;
    return ;
  }
  else
  {
    queue[rear]=item;
  }
}
int dequeue()
{
  int temp;  
  if(rear==front)  //if empty
  {
    printf("queue empty!");  
  }
  else
  {
    front=(front+1)%n;
    temp=queue[front];
    queue[front]=0;
  }
  return temp;
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