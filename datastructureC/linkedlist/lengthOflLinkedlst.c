#include<stdio.h>
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node{
   int data;
   nodeptr next;
}node;
int ilen(nodeptr);
int rlen(nodeptr);
void insert(nodeptr *,int);
int main()
{
   int i,input;
   nodeptr head=NULL;
   printf("input a linkedlst");   
   for(i=0;i<5;i++)   //input five node
   {
     scanf("%d",&input);
     insert(head,input); 
   }
   printf("%d",rlen(head));
   printf("%d",ilen(head));  

}
void insert()
{
   
}
int rlen()
{

}    
int ilen()
{

}