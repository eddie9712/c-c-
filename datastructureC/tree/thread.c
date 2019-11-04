//the operation of thread binary tree(insert)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node *nodeptr;
typedef struct node
{
   bool lthread,rthread;   //lthread true:point to the predecessor,false:child
   nodeptr lptr,rptr;      //rthread true:point to the successor
   int data;
}node;
nodeptr newnode(int);
nodeptr insuc(nodeptr);  //find the inorder successor 
void inorder();    //output the tree  
nodeptr inpre();   //find the onorder predecessor 
int main()   
{
  nodeptr head;
  head=newnode(0);        //initialize the head node
  head->lptr=head;        //point to it self
  head->rptr=head;         
  head->lthread=true;
  head->rthread=false;
  //start to insert the  binary thread tree
}
nodeptr newnode(int data)
{
  nodeptr temp;
  temp=malloc(sizeof(node));
  temp->lptr=NULL;
  temp->data=data;
  temp->rptr=NULL;
  temp->rthread=true;
  temp->lthread=true;
  return temp;
}
nodeptr inpre()
{

}
nodeptrin()
{

}