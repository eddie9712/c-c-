#include<stdio.h>
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node{
   int data;
   nodeptr left;
   nodeptr right;
}node;
void inorder(nodeptr p1)
{
    inoredr(p1->left);
    printf("%d",p1->data);
    inorder(p1->right);
}
nodeptr newnode(int key)
{
   nodeptr temp;
   temp=malloc(sizeof(node));
   temp->left=temp->right=NULL;
   temp->data=key;
   return temp;
}
nodeptr insert(nodeptr root,int key)
{
  if(root==NULL)
  {
    return newnode(key);  
  }
  else if(key<root->data)
  {
    root->left=insert(root->left,key); 
  }
  else
  {
    root->left=insert(root->left,key); 
  }
  return root;
}
int main()
{
 int i,input;
 nodeptr root=NULL;
 for(i=0;i<10;i++)
 {
  scanf("%d",&input);
  root=(root,input);
  }
 inorder(root);
}