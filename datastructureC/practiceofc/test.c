#include<stdio.h>
#include<stdlib.h>
typedef struct heapnode *heapnodeptr;
typedef struct heapnode
{
   int key;
}heapnode;
void test(heapnode *,int);
int main()
{
  int i;
  int num=10; 
  int temp;
  heapnode heap[num];
  for(i=0;i<num;i++)
  {
    scanf("%d",&temp);
    heap[i].key=temp;
  }
  for(i=0;i<num;i++)
  {
    printf("%d\n",heap[i].key);
  }
  test(heap,num);
  for(i=0;i<num;i++)
  {
    printf("%d\n",heap[i].key);
  }
}
void test(heapnode heap[],int num)
{
  int i;
  for(i=0;i<num;i++)
  {
    heap[i].key=0;
  }     
}