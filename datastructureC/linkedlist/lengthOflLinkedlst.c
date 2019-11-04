#include<stdio.h>
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node{
   int data;
   nodeptr next;
}node;
int rlen(nodeptr);
void insert(nodeptr *,int);
nodeptr new(int);
int main()
{
   int i,input;
   nodeptr head=NULL;
   printf("input a linkedlst");   
   for(i=0;i<5;i++)   //input five node
   {
     scanf("%d",&input);
     insert(&head,input); 
   }
   printf("%d",rlen(head));
}
nodeptr new(int key)
{
  nodeptr t;
  t=malloc(sizeof(node));
  t->data=key;
  t->next=NULL;
  return t;
}
void insert(nodeptr *p1,int key)
{
    if((*p1)==NULL)
    {
      (*p1)=new(key); 
    }
    else
    {
      nodeptr p=new(key);
      p->next=(*p1); 
      (*p1)=p;
      p=NULL; 
    }
}
int rlen(nodeptr p1)   //recursive version
{
   if(p1==NULL)
     return 0;
   else 
     return 1+rlen(p1->next);
}    


