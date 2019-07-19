#include<stdio.h>  //just using a pointer rear for the queue
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node
{
  int data;
  nodeptr next;
}node;
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
  if(rear==NULL)  //queue empty
  {
    t->next=t;  
  }
  else
  {
     t->next=rear->next;
     rear->next=t;
  }
  rear=t;
  t=NULL;     
}
int dequeue()   
{
  int temp;
  nodeptr t;
  if(rear!=NULL)  //queue empty
  {
    if(rear->next==rear)  //one node
    {
       t=rear;
       temp=t->data;
       rear=NULL;
       free(t); 
    }
    else
    {
       t=rear->next;
       temp=t->data;
       rear->next=t->next;
       t->next=NULL;
       free(t);  
    }
    return temp;
  }
}
void print()  //print the queue
{
  nodeptr t;
  t=rear->next;  
  while(1)
  {
    if(rear==NULL)
    break;
    printf("%d\n",t->data);
    t=t->next;
    if(t==rear)
    break;
  }
  printf("%d\n",t->data);
}