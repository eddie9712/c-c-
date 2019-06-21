#include<stdio.h>   //a program for testing
#include<stdlib.h>  
typedef struct node *nodeptr;
typedef struct node
{
  int data;
  nodeptr next;
}node;
void traversal(nodeptr);
void insert(nodeptr,int); 
int main()
{
    
    int i;
    nodeptr head=NULL;
    for(i=0;i<4;i++)
    {
       int n;
       scanf("%d",&n);
       insert(head,n);   
    }
    traversal(head);
}
void traversal(nodeptr ptr)
{
    if(ptr==NULL)
    {
      printf("linked list empty!\n");
    } 
    else
    {
      nodeptr x=NULL;
      x=ptr;
      while(x!=NULL)
      {
       printf("%d",x->data); 
       x=x->next;
      }
    }
}
void insert(nodeptr p1,int a)                   //INSERT(S, x)
{ 
    nodeptr p2;
    p2=p1;
    nodeptr temp;
    temp=malloc(sizeof(node));
    temp->next=NULL;
    temp->data=a;
    while(1)
    {
      if(p1==NULL)   //empty
      {
        p1=temp;
        break;
      }      
      else
      {
        if(p2->next==NULL) 
         {
            p2->next=temp;
         }
      }
      p2=p2->next; 
    }
    traversal(p1);
}