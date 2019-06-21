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
nodeptr insert(nodeptr,int);                    //INSERT(S, x)
nodeptr delete(nodeptr,int);                    //DELETE(S, x)
int minimum(nodeptr);                    //MINIMUM(S)
int maximum(nodeptr);                    //MAXIMUM(S)
int successor(nodeptr,int);                    //SUCCESSOR(S, x)
int predecessor(nodeptr,int);                   //PREDECESSOR(S, x)
nodeptr* reverse(nodeptr *);
int main()
{
   int n,i,temp,input,k,j;
   char c;   //input instruction
   printf("how many numbers to build to initialized the linked list");
   scanf("%d",&n);
   nodeptr head=NULL;   //initialize the linked list
   printf("input the series of numbers:");
   for(i=0;i<n;i++)   //build the linked list 
   {
    scanf("%d",&temp);
    head=insert(head,temp);
   }
   while(1)   //input the char to decide the operation 
   {
     printf("input the operations:(t,s,i,d,m,a,e,p):");
     getchar();
     scanf("%c",&c);
     switch(c)
     {
        case 'r': //reverse the linked list
          traversal(head);
          reverse(&head);
           break;           
        case 't':
            traversal(head);
            break;
        case 'i':   //insert
        printf("input the data for inserting:");
            scanf("%d",&input);
            head=insert(head,input);
            printf("after insertion\n");
            traversal(head);        
            break; 
        case 'd':    //delete
        printf("input the number to delete:");
          scanf("%d",&input);
          head=delete(head,input);
          printf("after deletio\n");
          traversal(head);
        break; 
        case 'm':    //mini
          k=minimum(head);
          printf("the smallest number:%d",k);
        break; 
        case 'a':    //max
          j=maximum(head);
          printf("the largest number:%d",j); 
        break; 
        case 's':   //successor
          printf("find the successor of ?:");
          scanf("%d",&input);
          k=successor(head,input);
          printf("find: %d",k);
        break; 
        case 'p':     //predecessor
          printf("find the predecessor of ?:");
          scanf("%d",&input);
          k=successor(head,input);
          printf("find: %d",k);
        break; 
        case 'e':    //search
         printf("number to search:");
         nodeptr test;
         scanf("%d",&input);
         test=search(head,input);
         if(test!=0)
         printf("exist");
         break; 
          default:
           printf("input error!");
        }
    }
}
void traversal(nodeptr ptr)
{
    if(ptr==NULL)
    {
      printf("linked list empty!\n");
    } 
    else
    {
      nodeptr x=NULL;
      x=ptr;
      while(x!=NULL)
      {
       printf("%d",x->data); 
       x=x->next;
      }
    }
}
nodeptr search(nodeptr p1,int k)                    //SEARCH(S, k)
{
   if(p1==NULL)
   {
     printf("linkedlist empty");
   }  
   else
   {
       nodeptr x=NULL;
       x=p1;
       while(x!=NULL)
       {
         if(x->data==k)
          {
            return x;
          }
          x=x->next;
       } 
      printf("not found");
   }
}
nodeptr insert(nodeptr p1,int a)                   //INSERT(S, x)
{ 
    nodeptr p2;
    p2=p1;
    nodeptr temp;
    temp=malloc(sizeof(node));
    temp->next=NULL;
    temp->data=a;
    while(1)
    {
      if(p1==NULL)   //empty
      {
        p1=temp;
        break;
      }      
      else
      {
        if(p2->next==NULL) 
         {
            p2->next=temp;
            return p1;
         }
      }
      p2=p2->next; 
    }
}
nodeptr delete(nodeptr p1,int a)                  //DELETE(S, x)
{
   nodeptr deletenode;
   nodeptr acess=p1;
   if(p1==NULL)
    { 
     printf("nothing to delete!");
    }
   while(1)
   {
     if(acess->next->data==a)   //peek at the next node
     {
        deletenode=acess->next;
        acess->next=acess->next->next;
        deletenode->next=NULL;                   //delete node
        return p1;
      } 
      acess=acess->next;  
   }
}
int minimum(nodeptr head)                    //MINIMUM(S)
{
  int temp;
  nodeptr x=head;
  if(head==NULL)
    printf("empty\n");
  else
  {
    temp=head->data;
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
int maximum(nodeptr p1)                    //MAXIMUM(S)
{
 int temp;
  nodeptr x=p1;
  if(p1==NULL)
    printf("empty\n");
  else
  {
    temp=p1->data;
    while(x!=NULL)
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
int successor(nodeptr p1,int a)                    //SUCCESSOR(S, x)
{
   nodeptr x;
   x=p1;
   if(p1==NULL)
     {
        printf("empty");
     }
    else
    {
      while(x->next!=NULL)
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
int predecessor(nodeptr p1,int a)    
{
    nodeptr x;
    x=p1;
    if(p1==NULL)
    {
       printf("empty\n");
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
nodeptr *reverse(nodeptr *p1)  //parameter is the head of the linkedlist
{
  printf("before reverse:"); //berfore reverse
  traversal((*p1));
  if((*p1)==NULL)
  {
    printf("empty list");
  }
  else
  {
    nodeptr pre,cur,nextone;
    pre=(*p1);   
    cur=(*p1)->next;
    nextone=cur->next;
    pre->next=NULL;
    while(1)
   {
    cur->next=pre;
    if(nextone==NULL)
      break;
    pre=cur;
    cur=nextone;
    nextone=nextone->next;    
   }
   (*p1)=cur;
   printf("after reverse:");
   traversal((*p1)); 
  }
  } 