#include<stdio.h>
#include<stdlib>
void heapsort(int *);
void maxheap(int *,int);
void buildmaxheap(int *,int);
int main()
{
   int i;
   int array[10]={4,565,67,24,78,2345,34,67,34,537};  //set an array
   int size=sizeof(array)/sizeof(array[0]);
   buildmaxheap(array,size/2);//do the maxheap
   printf("ans should be:\n");
   for(i=0;i<10;i++)
   {
      printf("%d\n",array[i]);
   } 
   heapsort(array);//do the heapsort
   

}
void maxheap(int array[];int i)   //each node max heap
{
   int left,right,largest;
   int length=sizeof(array)/sizeof(array[0]);
   left=2i;
   right=2i+1;
   if(left<=length&&array[left]>array[i])  //left is the largest
   {
     largest=2i; 
   }
   else if(left<=length&&array[i]>array[left])   
   largest=i;
   if(right<=length&&array[right]>array[largest])
   largest=2i+1;
   if(largest!=i)
   {
    int temp;//swap the node element    
    temp=array[i];
    array[i]=array[largest];
    array[i]=temp;
    maxheap(array,largest);
   }   
}
void buildmaxheap(int array,int k)
{
    int i;
    for(i=k;i>=0;i--)
    {
      maxheap(array,i);
    }

}
void heapsort(int array)
{
   int i;
   int length=sizeof(array)/sizeof(array[0]);
   int temp;
   buildmaxheap(array,length);
   for(i=length-1;i>=2;i--) 
   {
     temp=array[0];//swap the root and the last item  
     array[0]=array[i];
     array[i]=temp; 
     length--;
     maxheap(array,0); //pass the n-1 array for parameter
   }
  

}