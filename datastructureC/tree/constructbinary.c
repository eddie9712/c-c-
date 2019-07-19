#include<stdio.h>   //a program to construct bunary tree and traversal it in variety of ways 
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node
{
   nodeptr left;
   nodeptr right;
   int data;
}node;
void constructtree();    //construct tree from level order
void inordertraversali();
void inordertraversalr();
void postordertraversali();
void postordertraversalr();
void preordertraversali();
void preordertraversalr();
int main()
{

}
