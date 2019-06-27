#include<stdio.h>  //using linkedlist to implement stack structure(unlimited upperbound of insertion)
#include<stdlib.h>
#include<stdbool.h>
typedef struct node *nodeptr;
typedef struct node
{
   int data;
   nodeptr next;
}node;
void push(nodeptr *,int);
nodeptr pop(nodeptr *);
int topofstack(nodeptr);
bool isempty(nodeptr);
int main()
{
  int i,k;
  nodeptr top=NULL;
  for(i=0;i<5;i++) //push five items
  {
    scanf("%d",&k);
    push(&top,k);
  }
  for(i=0;i<3;i++)//pop out 3items
  {
    nodeptr p;
    p=pop(&top);     
    printf("the number poped out:%d",p->data);
  }
}
void push(nodeptr *top,int data)
{
  nodeptr temp=malloc(sizeof(node));
  temp->data=data;
  temp->next=(*top);
  (*top)=temp;
}
nodeptr pop(nodeptr *top)
{
   if((*top)==NULL)
   {
     printf("stack empty!");
     exit(1);
   }
   else
   {
     nodeptr x;
     x=(*top);
     (*top)=(*top)->next;
     x->next=NULL; 
     return x;
   }
}
int topofstack(nodeptr top)
{
   int item;
   item=top->data;
   return item;  
} 
bool isempty(nodeptr top)
{
   if(top==NULL)  
     return true;
    else
    {
        return false;
    }
}  