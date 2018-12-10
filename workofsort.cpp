#include<iostream>
#include<ctime>
#include<cstdlib>
#include<random>
using namespace std;
void duplicate_array(int *,int *,int);
void printout_array(int *,int);
void heap_sort(int *,int);
void quick_sort(int *,int);
void buildmaxheap(int *,int);
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
  //quick_sort(arrayb,n);
  cout<<"by heap_sort:\n";
  printout_array(arraya,n);
  //cout<<"by quick_sort:\n";
 // printout_array(arrayb);
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
   


 
}
void heap_sort(int arraya[],int n)
{
   int temp;
   int k=n;
   for(int j=0;j<n+1;j++)
  {
   buildmaxheap(arraya,k); 
   temp=arraya[k];
   arraya[k]=arraya[j];
   arraya[j]=temp;
   k--;
  }
}
//void quick_sort(int arrayb[],n)
//{

//}

