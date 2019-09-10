#include<stdio.h>  //implemnt the binary search tree of variety of function
#include<stdlib.h>
#include<stdbool.h>
typedef struct node *nodeptr;
typedef struct node
{
  int data;
  nodeptr left;
  nodeptr right;
}node; 
void construct(nodeptr *);
void insert(nodeptr *,int);
nodeptr anotherinsert(nodeptr *,int);
nodeptr newnode(int);
void delete(nodeptr *,int);
nodeptr modifysearch(nodeptr,int);
nodeptr search(nodeptr,int);
void preorder(nodeptr);
void postorder(nodeptr);
void inorder(nodeptr);    //sorting the BST
nodeptr leftmost(nodeptr);  //min value
nodeptr rightmost(nodeptr);  //max value
int array[10];
int main()
{
  nodeptr root=NULL;
  int i,input;
  for(i=0;i<7;i++)  //input the data of the BST
 { 
  scanf("%d",&input);
  array[i]=input;   
 }
 construct(&root);  //build the tree
 printf("inoredr:\n");
 inorder(root);
 printf("\n");
 printf("preorder:\n");
 preorder(root);
 printf("\n");
 printf("postorder:\n");
 postorder(root);
 printf("\n");
 printf("check if the number in the tree:");
 scanf("%d",&input);
 if(search(root,input)!=NULL)
 {
    printf("in tree\n"); 
 }
 else
 {
   printf("not in tree\n");
 }
 delete(&root,3);
 printf("inoredr:\n");
 inorder(root);
 printf("test another way of insert:");
 root=anotherinsert(&root,19);
 inorder(root);
}
void construct(nodeptr *x)
{
  int i;
  for(i=0;i<7;i++)
  {
    insert(&(*x),array[i]);
  }
}
nodeptr search(nodeptr x,int key)  //check if the node in the BST
{
  if(x!=NULL)  //if tree not empty
  {
   if(x->data==key)
     return x;
   else if(x->data<key)
   {
     return search(x->right,key);   
   }
   else 
   {
     return search(x->left,key);   
   }
  }
  return NULL;
}
nodeptr modifysearch(nodeptr x,int key)   //find the place to insert(point to the last node to insert)
{
   nodeptr ptr;
   ptr=x;
   if(x==NULL)    //if tree empty
     return x;
   else
   {
     while(x!=NULL)
     {
       if(key==x->data)  //if k already in tree
       {
        return ptr;
       }
       if(key<x->data)   //if key<data
      {
         x=x->left;
         if(x==NULL||x->data==key)
           break;
         ptr=ptr->left;
      }
       else  
        {
         x=x->right;
         if(x==NULL||x->data==key)
           break;
         ptr=ptr->right;
        } 
     }
     return ptr;      
   }
}
void insert(nodeptr *root,int key)  
{
  nodeptr temp;
  temp=modifysearch((*root),key);
  if(((*root)==NULL)||(temp->data!=key))  //k不在樹中
  {
    nodeptr ptr=malloc(sizeof(node)); 
    ptr->data=key;
    ptr->left=ptr->right=NULL; 
    if((*root)!=NULL)   //non empty tree
    {
       if(key<temp->data)
        temp->left=ptr;
       else
       {
         temp->right=ptr;
       }
     }
     else
     {
       (*root)=ptr;
     }
  }
  else 
  {
    printf("already in tree");
  }
}
nodeptr newnode(int k)
{
  nodeptr p=malloc(sizeof(node));
   p->data=k;
   p->left=p->right=NULL;
   return p;  
}
nodeptr anotherinsert(nodeptr *root,int key)
{
   if((*root)==NULL)
  {
    return newnode(key);
   }
   else if(key<(*root)->data)
   {
    (*root)->left=anotherinsert(&((*root)->left),key);
   }
   else 
   {
    (*root)->right=anotherinsert(&((*root)->right),key);
   }
   return (*root);
} 
void preorder(nodeptr x)
{
   if(x!=NULL)
   {
    printf("%d",x->data);
    preorder(x->left);
    preorder(x->right);
   }
}
void postorder(nodeptr x)
{
  if(x!=NULL)
  {
    postorder(x->left);
    postorder(x->right);
    printf("%d",x->data); 
  }
}
void inorder(nodeptr x)
{
  if(x!=NULL)
  {
    inorder(x->left);
    printf("%d",x->data); 
    inorder(x->right);
  }
}
nodeptr leftmost(nodeptr x)   //find the smallest node of a tree
{
 if(x!=NULL)
  {
    if(x->left!=NULL)
   {
     x=x->left;
   }
  }
 return x; 
}
nodeptr rightmost(nodeptr x)   //find the largest node of a tree
{
   if(x!=NULL)
  {
    if(x->left!=NULL)
   {
     x=x->left;
   }
  }
  return x; 
}
void delete(nodeptr *root,int key)
{
  nodeptr temp;  //the parent of the deleted node
  nodeptr x;    //the deleted node
  nodeptr left;   //pointer point leftmost
  if((*root)==NULL)
  {
    printf("tree empty");
    return ;
  }
  else
  {
   temp=modifysearch((*root),key);   //the parent of the delete node
   printf("%d",temp->data);
   x=search(*(root),key);
   if((x->left==NULL)&&(x->right==NULL))   //if the node is leaf
   {
     if(temp->left==x)
     {
       temp->left=NULL;
     }
     else if(temp->right==x)
     {
      temp->right=NULL;
     }
   }
   else if((x->left!=NULL)||(x->right!=NULL))    //if the node is degree one
   {
     if(temp->left==x)
     {
       if(x->left!=NULL)
       {
        temp->left=x->left;
       }
       else
       {
        temp->left=x->right;
       }
     }
     else if(temp->right==x)
     {
       if(x->left!=NULL)
       {
        temp->right=x->left;
       }
       else
       {
        temp->right=x->right;
       }
     }
   }
   else   //if the node is degree 2
   {
    left=leftmost(x);
    x->data=left->data;
    delete(&left,left->data);
   }
  }
}



