#include<stdio.h>   //build a binary tree with some function to it 
#include<stdlib.h>
#include<stdbool.h>
typedef struct node *nodeptr;
typedef struct node
{
   nodeptr left;
   nodeptr right;
   int data;
}node;
nodeptr construct();    //construct by level order
void inordertraversal();
void postordertraversal();
void preordertraversal();
nodeptr copy(nodeptr);
nodeptr newnode(int);
bool equal(nodeptr,nodeptr);
int numbers(nodeptr);
int height(nodeptr);
void swap();
int queue[10]; //for construct binary tree
nodeptr root1=NULL;
nodeptr root2=NULL;
nodeptr root3=NULL;
int main()
{
  int i;        
  int input;
  for(i=0;i<5;i++)
  {
    scanf("%d",&input);
    queue[i]=input;
  }
  root1=construct(root1,0,5);    //construct binary tree
  // for(i=0;i<5;i++)
 // {
 //   scanf("%d",&input);
 //   queue[i]=input;
 // }
  //root3=construct(root3,0,5);
  printf("inorder:\n");
  inordertraversal(root1);
  printf("preorder\n");
  preordertraversal(root1);
  printf("postorder\n");
  postordertraversal(root1);
  root2=copy(root1);    //copy the binary tree  
  inordertraversal(root2);
  printf("\n");
  if(equal(root1,root3))
  {
    printf("the trees equal!\n");
  }
  else
  {
    printf("the trees are not equal");    
  }
  int number=numbers(root1);//return the number of a tree
  printf("number of nodes:%d\n",number);
  int h=height(root1);
  printf("%d",h);
  swap(root1); 
  inordertraversal(root1);
}
nodeptr newnode(int x)
{
    nodeptr t;
    t=malloc(sizeof(node));
    t->right=t->left=NULL;
    t->data=x;
    return t;
}
nodeptr construct(nodeptr x,int i,int n)    //construct by level order
{
  if(i<n)
  {
    nodeptr t=newnode(queue[i]);
    x=t;
    x->left=construct(x->left,2*i+1,n);
    x->right=construct(x->right,2*i+2,n);
  }
  return x;
}
void inordertraversal(nodeptr x)
{
  if(x!=NULL)
  {
    inordertraversal(x->left);
    printf("%d",x->data);
    inordertraversal(x->right);
  }
}   
void postordertraversal(nodeptr x)
{
  if(x!=NULL)
  {
    postordertraversal(x->left);
    postordertraversal(x->right);
    printf("%d",x->data);
  }
}
void preordertraversal(nodeptr x)
{
  if(x!=NULL)
  {
    printf("%d",x->data);
    preordertraversal(x->left);
    preordertraversal(x->right);
  }
}  
nodeptr copy(nodeptr x)
{
  nodeptr t;
  if(x==NULL)
  {
    t=NULL;
  }
  else
  {
    t=newnode(x->data);
    t->left=copy(x->left);
    t->right=copy(x->right); 
  }
  return t;
}
bool equal(nodeptr x1,nodeptr x2)  //test if the tree equal
{
   bool ans=false;
   if((x1==NULL)&&(x2==NULL))
   {
      ans=true; 
   }
   if((x1!=NULL)&&(x2!=NULL))
   {
     if(equal(x1->left,x2->left))
    {
      if(equal(x1->right,x2->right))
      {
        if((x1->data)==(x2->data))
        {
          ans=true;
        }
      }
    }
   }
   return ans;
}
int numbers(nodeptr x)  //calculate the numbers of a tree
{
  int nl,nr;
  if(x==NULL)
  {
    return 0;
  }
  else
  {
     nl=numbers(x->left);
     nr=numbers(x->right);
  }
  return nl+nr+1;
}
int height(nodeptr x)   //height of a binary tree
{
  int hl,hr; 
  int max;
  if(x==NULL)
  {
    return 0;
  }
  else
  {
    hl=height(x->left);
    hr=height(x->right);
    if(hl>hr)
    {
       max=hl;
    }
    else
    {
      max=hr;
    }
  }
  return max+1;
}
void swap(nodeptr x)   //swap the child of a tree
{
  nodeptr t;
  if(x!=NULL)
 {
  swap(x->left);
  swap(x->right);
  t=x->left;
  x->left=x->right;
  x->right=t;
 }
}
