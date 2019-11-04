#include<stdio.h>  //the operation of max heap
#include<stdlib.h>
void swap(int *,int *);
void insert(int [],int,int);
void print(int *,int);
void delete(int [],int);
void copytheheap(int [],int [],int);
void iheapify(int [],int,int);    //the version of iterative
void rheapify(int [],int,int);    //the version of recursive
void buildmaxheap(int [],int);   //build maxheap by bottom up
int n=10;
int main()
{
  int i,input;  //assume the size of the heap is 10
  int heap[20];
  int heap2[20];
  for(i=1;i<=10;i++)  //input data  heap[1]~heap[n]
  {
    scanf("%d",&input);
    heap[i]=input;
  }
  copytheheap(heap2,heap,n);   //(to,from)
  buildmaxheap(heap,n);   //iterative version
  buildmaxheap(heap2,n);   //recursive version
  printf("heap 1:\n");
  print(&heap,n);
  printf("\n");
  printf("heap 2:\n");
  print(&heap2,n);
  printf("\n");
  printf("input the number for inserting:");
  scanf("%d",&input);
  print(heap,n);
  printf("input the number to delete:");
  scanf("%d",&input);
  print(heap,n);
}
void copytheheap(int heap2[],int heap[],int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      heap2[i]=heap[i];
   }  
}
void print(int *p,int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d",p[i]);
   }
}
void iheapify(int heap[],int n,int i)  //to heapify a subtree rooted with node i
{
   int j,x;
   x=heap[i];   //put the root into the key
   j=2*i;    //left node
   while(j<=n)   //if the tree has child
   {
     if(j<n)   //if root have right child
    {
      if(heap[j]<heap[j+1]) 
        j++; 
    }
    if(x>=heap[j])
    {
      break;   
    }
    else
    {
      heap[j/2]=x;
      j*=2;  
    }
   }
  heap[j/2]=x;
}
void rheapify(int heap[],int n,int i)   //the recursive version of heapify
{
  int largest,left,right;
  largest=i;      //initial the root  
  left=2*i;
  right=2*i+1;
  if(left<n&&heap[left]>heap[largest])
  {
   largest=left; 
  }
  if(right<n&&heap[right]>heap[largest])
  {
    largest=right;
  }
  if(largest!=i)   //if the largest number isn't root
  {
    swap(&heap[i],&heap[largest]);
    rheapify(heap,n,largest);
  }
}
void buildmaxheap(int heap[],int n)   //build maxheap by bottom up 
{
  int i;
  for(i=n/2;i>=1;i--)
  {
    heapify(heap,n,i); 
  }        
}
void insert(int heap[],int n,int key)
{
  int i,j;
  heap[n+1]=key;
  i=2/(n+1);
  j=n+1;
  while(i>=1)
  {
    if(heap[j]<=heap[i])  //if key <= parent node,else swap
    {
      break;   
    }
    else
    {
      int x;
      x=heap[i]; 
      heap[i]=heap[j];
      heap[j]=x;
    }
    i=i/2;
    j=j/2;
  }
  n++;
}
void delete(int heap[],int n)   //delete
{
  int max,i,x;
  i=1;
  heap[1]=heap[n];  //put the last node in root
  while(2*i<=n)   //adjust the heap
  {
   x=heap[i];
   if(heap[2*i]<heap[2*i+1])  //right child bigger
   {
      max=2*i+1;
   }
   else
   {
       max=2*i;
   }
   if(heap[i]<heap[max])
   {
     heap[i]=heap[max];
     heap[max]=x;
   }
   i=max; 
  } 
  n--;   
}