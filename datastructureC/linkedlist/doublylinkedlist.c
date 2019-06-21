#include<stdio.h>    //implement the datastructure of double linkedlist
#include<stdlib.h>    //does
void  insert(nodeptr *,int);   
void  delete(nodeptr *,int);
void traversal(nodeptr);
typedef struct node *nodeptr;
typedef struct node
{
   int data;
   nodeptr left;
   nodeptr right;
}node;
int main()
{
  int n,i;
  nodeptr head=NULL;
  printf("amount of input:");
  scanf("%d",&n);
  for(i=0;i<n;i++) 
  {
    printf("insert:");
    insert(head,n);
  }
  printf("input the number want to delete:");
  scanf("%d",&n);
  delete(head,n);
  traversal(head);
}
void insert(nodeptr *head,int data)
{
   nodeptr x;
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
        if(x->right==NULL)  //location for insert
        {
          temp->left=x;
          x->right=temp;
        }
        x=x->right;
     }
   }
}
void traversal()
{
  


}
void delete()
{
  
}