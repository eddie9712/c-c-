#include<stdio.h>    //implement the datastructure of double linkedlist
#include<stdlib.h>    //ignoring memory leak
typedef struct node *nodeptr;
typedef struct node
{
   int data;
   nodeptr left;
   nodeptr right;
}node;
void  insert(nodeptr *,int);   
void  delete(nodeptr *,int);
void traversal(nodeptr);
int main()
{
  int n,i,k;
  nodeptr head=NULL;
  printf("amount of input:");
  scanf("%d",&n);
  for(i=0;i<n;i++) 
  {
    printf("insert:");
    scanf("%d",&k); 
    insert(&head,k);
  }
  printf("input the number want to delete:");
  scanf("%d",&n);
  delete(&head,n);
  traversal(head);
}
void insert(nodeptr *head,int data)
{
   nodeptr x;
   x=(*head);
   nodeptr temp=malloc(sizeof(node));
   temp->data=data;
   temp->left=NULL;
   temp->right=NULL;
   if((*head)==NULL) 
  {
     (*head)=temp;
     return;
  }
   else
  {
     while(1)
    {
      if(x->right==NULL)  //location be inserted
        {
          temp->left=x;
          x->right=temp;
          return ;
        }
        x=x->right;
     }
  }
}
void traversal(nodeptr p1)
{
  nodeptr x;
  x=p1;
   while(x!=NULL)
  {
    printf("%d\n",x->data);
    x=x->right;
  }  
}
void delete(nodeptr *head,int key)   //delete the key input
{
  nodeptr x;
  x=(*head);
  if((*head)==NULL)
  { 
     printf("the list empty!");
     return ;
  }
  else
  {
      while(1)
      {
        if(x->data==key)  //find delete node
        {
          if(x->left==NULL)   //front
          {
            (*head)=x->right;
            if((*head)!=NULL)
            {
              (*head)->left=NULL;
            }
            x->right=NULL;
            return ;
          }
          if((x->left!=NULL)&&(x->right!=NULL))       //middle
          {
            nodeptr p1,p2;
            p1=x->left;
            p1->right=x->right;
            p2=x->right;
            p2->left=p1;
            x->left=NULL;
            x->right=NULL;
            return ;
          }
          if(x->right==NULL)       //tail
          {
            nodeptr p;
            p=x->left;
            p->right=NULL;
            x->left=NULL;
            x->right=NULL;
            return ;
          }
        }
        x=x->right;
      }
      printf("the key not found!");
    }
}