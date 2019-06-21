#include<stdio.h>      //inplment pass by reference(insert)
#include<stdlib.h>
typedef struct node *listpointer;
typedef struct node
{
   int data;
   listpointer next;
}node;
void insert(listpointer *,int);
void traversal(listpointer *);
int main()
{
    int i;
    listpointer head=NULL;
    for(i=0;i<5;i++)
    {
     printf("input the number for insert:");
     int n;
     scanf("%d",&n);
     insert(&head,n);  //insert the number pass by reference
    }
  traversal(&head);
}
void insert(listpointer *headref,int input)
{ 
    listpointer temp;
    temp=malloc(sizeof(node));
    temp->data=input;
    temp->next=NULL;
    listpointer ptr;
    ptr=(*headref);
    if((*headref)==NULL)
    {
      (*headref)=temp; 
    }
    else
    {
       while(1)
       {
          if(ptr->next==NULL)
          {
            ptr->next=temp;
            break;
          }
          ptr=ptr->next;
       }
    }
}
void traversal(listpointer *headef)
{ 
   listpointer ptr;  //pointer to traversal
   ptr=(*headef);
   while(ptr!=NULL)
   {
      printf("%d\n",ptr->data);  
      ptr=ptr->next;
   }
}