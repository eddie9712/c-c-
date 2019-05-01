#include<iostream>   
#include<algorithm> 
#include<climits>
#include<ctime> 
using namespace std;
int partition(int *, int,int,int); // A simple function to find median of arr[].   
int Median(int *, int); 
int partition(int *,int,int,int); 
void swap(int *, int *);
int kth(int *,int,int,int); 
int main() 
{ 
    srand(time(NULL));
    int number,i,k;
    cout<<"decide the number of the array:";
    cin>>number;
    int *arr = new int[number]; 
    for(i=0;i<number;i++)
     {
       int temp;
       temp=rand()%1000;
       arr[i]=temp;
     }
   cout<<"the numbers of the array:";
   for(i=0;i<number;i++)//print the array
    {
      cout<<arr[i]<<"\n";
    }
    cout<<"decide the k-th of the numbers:"; 
    cin>>k;
    cout << "K'th smallest element is "<< kth(arr, 0, number-1, k); 
} 
int Median(int arr[], int n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 
int kth(int arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups; 
        for (i=0; i<n/5; i++) 
            median[i] = Median(arr+l+i*5, 5); 
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = Median(arr+l+i*5, n%5);  
            i++; 
        }     
        int medOfMed = (i == 1)? median[i-1]: 
            kth(median, 0, i-1, i/2); 
        int pos = partition(arr, l, r, medOfMed); 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kth(arr, l, pos-1, k); 
        return kth(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
int partition(int arr[], int l, int r, int x) 
{ 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
 