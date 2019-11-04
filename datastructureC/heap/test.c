#include<stdio.h>
#include<stdlib.h>
void buildmaxheap(int [],int);
void rheapify(int [],int,int);
void iheapify(int [],int,int);
void swap(int *,int *);
int main()
{
   int n=10,i,input;
   int heap[10];
    for(i=1;i<=10;i++)  //input data  heap[1]~heap[n]
  {
    scanf("%d",&input);
    heap[i]=input;
  }
   buildmaxheap(heap,n);    
}
void buildmaxheap(int heap[],int n)   //build maxheap by bottom up 
{
  int i;
  for(i=n/2;i>=1;i--)
  {
    iheapify(heap,n,i); 
  }        
}
void iheapify(int heap[],int n,int i)
{
   int x,j;
   x=heap[i];
   j=2*i;
   while(j<=n)   //if the subtree has child
   {
     if(j<n)   //if it has the right child
     {
      if(heap[j]<heap[j+1])  //compare two childs
      {
         j=j+1;
      }
     }
      if(x>=heap[j])
      {
         break;
      }
      heap[j/2]=heap[j];        
      j=j*2; 
   }
   heap[j/2]=x;
}
void rheapify(int heap[],int n,int i)  
{
  int largest,left,right;
  left=2*i;
  right=2*i+1;
  if(left<n&&heap[left]>heap[largest])
  {
      largest=left;
  }
  if(left<n&&heap[right]>heap[largest])
  {
     largest=right;
  }
  if(largest!=i)
  {
    swap(&heap[largest],&heap[i]);     
    rheapify(heap,n,largest);
  }
}
void swap(int *a,int *b)
{
  int temp;
  temp=*b;
  *b=*a;
  *a=temp;
}
