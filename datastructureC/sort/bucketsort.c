#include<stdio.h>    //buckect sort (10 bucket)
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node{
   int key;
   nodeptr next;
}node;
void bucketsort(int *,int *,int);
void insertionsort(int,int);  //linkedlist version insertionsort 
void addnode(int,int *,int);
nodeptr bucket[10];
int main()
{
   int *record=calloc(10,sizeof(int));
   int n,i;
   for (i = 0; i <10; i++)
   {
    bucket[i]=NULL;
   }
   printf("how many numbers for sorting:");
   scanf("%d",&n);
   int *array=calloc(n,sizeof(int));
   printf("input the numbers for sorting:(0-99)");
   for(i=0;i<n;i++)
   {
     scanf("%d",&array[i]);
   }
   bucketsort(array,record,n);
   printf("@@@@@@@@@\n");
   for(i=0;i<n;i++)
   {
     printf("%d\n",array[i]);
   }
  }
void bucketsort(int array[],int record[],int n)
{
   int i,j=0;
   for(i=0;i<n;i++)  //for ten buckets
   {
     int data1;
     int data2;
     data1=array[i]/10;
     data2=array[i];
     addnode(data1,record,data2);
   }
   for(i=0;i<10;i++)
   {
     insertionsort(i,record[i]);
   }
   for(i=0;i<10;i++)  //put the numbers back into the array
   {
     nodeptr acess;
     acess=bucket[i];
    while(acess!=NULL)
    {
      array[j]=acess->key;
      j++;
      acess=acess->next;
    }
     free(acess); 
   }
}
void addnode(int i,int record[],int data)
{
  nodeptr acess=NULL;
  nodeptr temp;
  temp=malloc(sizeof(node));
  temp->key=data;
  temp->next=NULL;
  if(bucket[i]==NULL)   //bucket empty
  {
    bucket[i]=temp;
    temp=NULL;
  }
  else    //bucket not empty
  {
     acess=bucket[i];
     while(1)
    {
      if(acess->next==NULL)  //add node
      {
        acess->next=temp;
        temp=NULL;
        break; 
      }
      else   //next node
      {
        acess=acess->next;
      }
    }
  }
}
void insertionsort(int i,int n)   //doing insertionsort at the bucket(i)
{
   nodeptr current=NULL;
   nodeptr insert=NULL; 
   int temp;
   if(bucket[i]==NULL||bucket[i]->next==NULL) //empty bucket 
    return;
   else  //do inserting
   {
    current=bucket[i]->next;
       while(current!=NULL)
    {   
       insert=bucket[i];
      while(insert!=current)
      {
        if(insert->key>current->key) //swap
        {
           temp=current->key;
           current->key=insert->key;
           insert->key=temp;
        }
        insert=insert->next;
      }
      current=current->next;
    }
   }
}