#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void duplicate_array(int *,int *,int);
void printout_array(int *,int);
void heap_sort(int *,int);
void quick_sort(int *,int,int);
void buildmaxheap(int *,int);
void swap(int *,int,int);
 int main()
{
  srand(time(NULL)); //time for the seed
  int n,a_max,a_min,k,i;
  cout<<"Please input [n, a_min, a_max]:";
  cin>>n;
  int *arraya=(int *)malloc(n*sizeof(int));
  int *arrayb=(int *)malloc(n*sizeof(int));
  cin>>a_min;
  cin>>a_max;
  for(i=0;i<n;i++)  //generate the random numbers
  {
   k=rand()%(a_max-a_min+1)+a_min;
   arraya[i]=k;
  }
  duplicate_array(arraya,arrayb,n);
  heap_sort(arraya,n);
  quick_sort(arrayb,0,n-1);
  cout<<"by heap_sort:\n";
  printout_array(arraya,n);
  cout<<"by quick_sort:\n";
  printout_array(arrayb,n);
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
