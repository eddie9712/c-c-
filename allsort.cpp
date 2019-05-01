#include<iostream>
#include<cstdlib>
using namespace std;
is_A_desc(A,n)
mytimer() 
void duplicate_array(int *,int *,int);
IS(A,n) : do the insertion sort
MS(A,1,n) : do the merge sort
HS(A,n) : do the heap sort
QS(A,1,n) : do the quick sort
CS(A,n,k) : do the counting sort
RS(A,n,k) : do the radix sort
BS(A,n) : do the bucket sort
void printout_array(int *,int);
void heap_sort(int *,int);
void quick_sort(int *,int,int);
void buildmaxheap(int *,int);
void swap(int *,int,int);
 int main()
{
  int is_p,n,a_min,a_max,rs;
  cout<<"Input [is_p,n,a_min,a_max,rs]=";
  cin>>is_p>>n>>a_min>>a_max>>rs;
  
}
void swap(int a[],int b,int c)
{
  int temp;
  temp=a[b];
  a[b]=a[c];
  a[c]=temp;
}
void duplicate_array(int arraya[],int arrayb[],int n)
{
  int j;
  for(j=0;j<n;j++)
 {
    arrayb[j]=arraya[j];
 }
}
void printout_array(int arraya[],int n)
{
   int j;
  for(j=0;j<n;j++)
 { 
  cout<<arraya[j]<<"\n";
 }
  cout<<"\n";
}
void buildmaxheap(int arraya[],int n)
{
     for (int i=(n/2)-1;i>=0;i--) 
    {
       int child=2*i+1; //left child
       int temp;
       int root=i; 
       while(child<n)
      {
        if(child+1<n&&arraya[child]<arraya[child+1]) //compare the right and left child
         child++;
        if(arraya[root]<arraya[child])  //compare the child and parent
        {
           swap(arraya,child,root);
        }
         root++;
         child=2*root+1;
      }  
    }
}
void heap_sort(int arraya[],int n)
{
   int temp;
   int k=n;
   int j;
   for(int j=0;j<n-1;j++)
  {
   buildmaxheap(arraya,k); 
   swap(arraya,k-1,0);
   k--;
  }
}
void quick_sort(int arrayb[],int left,int right)
{
     if(left < right)
	 {
	    int pivot = arrayb[left];//假設pivot在第一個的位置
	    int l = left;
            int r = right+1 ;
           while (1)
		{
			while (l < right && arrayb[++l] < pivot);//向右找小於pivot的數值的位置
			while (r > 0 && arrayb[--r] > pivot);//向左找大於pivot的數值的位置

			if (l >= r)//範圍內pivot右邊沒有比pivot小的數,反之亦然
			{
				break;
			}
		
			swap(arrayb[l], arrayb[r]);//比pivot大的數移到右邊，比pivot小的數換到左邊
		}

		swap(arrayb[left], arrayb[r]);//將pivot移到中間

		quick_sort(arrayb, left, r - 1);//左子數列做遞迴
		quick_sort(arrayb, r + 1, right);//右子數列做遞迴
    }
}
