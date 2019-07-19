#include<stdio.h>    //implement the queue in linked list
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node
{
  int data;
  nodeptr next;
}node;
nodeptr front=NULL;
nodeptr rear=NULL;
void enqueue(int);
int dequeue();
void print();
int main()
{
  int i,input;
  for(i=0;i<5;i++)  //input 5 items
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
  printf("\n");
  print(); //print the queue
}
void enqueue(int x)
{
  nodeptr t;
  t=malloc(sizeof(node));
  t->data=x;
  t->next=NULL;
  if(front==NULL) //queue 空
  {
    front=t;
    rear=front;
  }     
  else
  {
    rear->next=t; 
    rear=t;
  }
}
int dequeue()
{
  int temp;
  nodeptr t;
  if(front==NULL)  //queue empty
  {
     printf("queue empty"); 
  }
  else
  {
    t=front;
    front=t->next;
    temp=t->data;
    t->next=NULL;
    free(t);
  }
  return temp;
}
void print()
{
   nodeptr t;
   t=front;
   while(t!=NULL)
   {
     printf("%d",t->data);
     t=t->next;
   }
}