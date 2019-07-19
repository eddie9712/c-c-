#include<stdio.h>   //modify linear queue 
#include<stdlib.h>    //a way which waste time
void enqueue(int,int);
int dequeue();
int rear=0;
int front=0; 
int queue[10];
int main()
{
  int n,i;
  for(i=0;i<10;i++)  //initialize
  {
   queue[i]=0;
  }
  printf("input:");
  for(i=0;i<3;i++)  //enqueue
  {
    scanf("%d",&n);
    enqueue(10,n);
  }
  printf("%d\n",dequeue());
  printf("%d\n",dequeue());
  printf("numbers in queue:\n");
  for(i=front+1;i<=rear;i++)
  {
   printf("%d\n",queue[i]);
  }
}
void enqueue(int queuesize,int input)
{
  int i,k=1;
  if((rear==queuesize-1)&&(front>0))  //amount of  space
  {
   for(i=front+1;i<queuesize-1;i++)//shift the element left   
    {
      queue[k]=queue[i];
      queue[i]=0;
      k++;
    }
    front=0;
    rear=rear-front;
  }
  else if((rear==queuesize-1)&&(front==0))   //really full
  {
    printf("queue full");
    return ; 
  }
  rear++;
  queue[rear]=input;
}
int dequeue()   
{
  int item;
  if(rear==front)
  {
     printf("queue empty") ; 
     return 0;
  }
  else
  {
    front++;
    item=queue[front];     
    return item;
  }
}