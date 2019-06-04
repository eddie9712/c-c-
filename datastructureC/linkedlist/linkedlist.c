#include<stdio.h>   //this program for implement the linkedlist
#include<stdlib.h>  
typedef struct node *nodeptr;
typedef struct node
{
  int data;
  nodeptr next;
}node;
void traversal(nodeptr);
nodeptr search(nodeptr,int);                    //SEARCH(S, k)
void insert(nodeptr,int);                    //INSERT(S, x)
void delete(nodeptr,int);                    //DELETE(S, x)
int minimum(nodeptr);                    //MINIMUM(S)
int maximun(nodeptr);                    //MAXIMUM(S)
int successor(nodeptr,int);                    //SUCCESSOR(S, x)
int predecessor(nodeptr,int);                   //PREDECESSOR(S, x)
int main()
{
   int n,i,temp;
   char c;   //input instruction
   printf("how many numbers to build to initialized the linked list");
   scanf("%d",&n);
   nodeptr head=NULL;   //initialize the linked list
   printf("input the series of numbers:");
   for(i=0;i<n;i++)   //build the linked list 
   {
    scanf("%d",&temp);
    insert(head,temp);     
   }
   while(1)   //input the char to decide the operation 
   {
     scanf("%c",&c);
     switch(c)
     {
        case t:
            traversal(head);
            break;
        case i:   //insert
        printf("input the data for inserting:");
            int input;
            scanf("%d",&input);
            insert(head,a);
            traversal(head);        
            break; 
        case d:    //delete
        prinf("input the number to delete:");
          scanf("%d",&a);
          delete(head,a);
          traversal(head);
        break; 
        case m:    //mini
          int k=minimum(head);
          printf("the smallest number:%d",k);
        break; 
        case a:    //max
          int j=maximum(head);
          printf("the largest number:%d",j); 
        break; 
        case s:   //successor
          printf("find the successor of ?:");
          scanf("%d",&input);
          k=successor(head,input);
          printf("find: %d",k);
        break; 
        case p:     //predecessor
          printf("find the predecessor of ?:");
          scanf("%d",&input);
          k=successor(head,input);
          printf("find: %d",k);
        break; 
        case e:    //search
         printf("number to search:");
         scanf("%d",&input);
         search(head,input);
        break; 
        default:
        printf("input error!");
        }
    }
}
void traversal(nodeptr p1);
{
    if(p1==NULL)
    {
      printf("linked list empty!\n");
    } 
    else
    {
      nodeptr x=NULL;
      x=p1;
      while(p1!=NULL)
      {
       printf("%d",p1->data); 
       p1=p1->next;
      }
    }
}
nodeptr search(nodeptr p1,int k);                    //SEARCH(S, k)
{
   if(p1=NULL)
   {
       printf("linkedlist empty");
   }  
   else
   {
       node x=NULL;
       x=p1;
       while(x!=NULL)
       {
         if(x->data==k)
          {
            nodeptr p2=x;
            return p2;
          }
       } 
      printf("not found");
   }
}
void insert(nodeptr p1,int a);                    //INSERT(S, x)
{ 
    nodeptr p2;
    p2=p1;
    nodeptr temp;
    temp=malloc(sizeof(node));
    temp->next=NULL;
    temp->data=a;
    while(1)
    {
      if(p1=NULL)   //empty
      {
        p1=temp;
        free(temp);
        break;
      }      
      else
      {
        if(p2->next==NULL) 
         {
            p2->next=temp;
            free(temp);
            break; 
         }
         p2=p2->next;      
      }
    }
}
void delete(nodeptr p1,int a);                    //DELETE(S, x)
{
   nodeptr deletenode;
   nodeptr acess=p1;
   if(p1==NULL)
    { 
     printf("nothing to delete!");
     return ;
    }
   while(1)
   {
     if(acess->next->data==k)   //peek at the next node
     {
        deletenode=acess->next;
        acess->next=acess->next->next;
        deletenode->next=NULL;                   //delete node
        free(deletenode);
        return ;
      } 
      acess=acess->next;  
   }
}
int minimum(nodeptr p1);                    //MINIMUM(S)
{
  int temp;
  nodeptr x=p1;
  if(p1==NULL)
    printf("empty\n");
  else
  {
    temp=p1->data;
    while(x->next!=NULL)
    {
     if(temp>x->data) 
     {
      temp=x->data; 
     } 
     x=x->next; 
    }
    return temp;
  }
}
int maximun(nodeptr p1);                    //MAXIMUM(S)
{
 int temp;
  nodeptr x=p1;
  if(p1==NULL)
    printf("empty\n");
  else
  {
    temp=p1->data;
    while(x->next!=NULL)
    {
     if(temp<x->data) 
     {
      temp=x->data; 
     } 
     x=x->next; 
    }
    return temp;
  }
}
int successor(nodeptr p1,int a);                    //SUCCESSOR(S, x)
{
   nodeptr x;
   if(p1==NULL)
     {
        printf("empty");
        return ;
     }
    else
    {
      while(x->next==NULL)
      {
         if(x->data==a)
         {
            return x->next->data; 
         }
         x=x->next;
      }
      printf("not exist\n");
    }
}
int predecessor(nodeptr p1,int a);    
{
    nodeptr x;
    if(p1==NULL)
    {
       printf("empty\n");
       return ;
    }
    else
    {
        while(x->next!=NULL)  //peek
        {
         if(x->next->data==a) 
          {
            return x->data;
          } 
          x=x->next;
        }
    }


}    