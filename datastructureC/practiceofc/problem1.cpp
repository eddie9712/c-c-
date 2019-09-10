#include<iostream>
#include<cstdlib>
using namespace std;
void print(int);
int main()
{
   int input;
   while(1)
   {
    cout<<"input the number:";
     cin>>input;
     print(input);
   }
}
void print(int n)
{
  int i,j;
  for(i=0;i<n-1;i++)
  {
     cout<<" ";
  }
  cout<<"x";
  for(i=0;i<n-1;i++)
  {
     cout<<" ";
  }
  cout<<"\n";
  for(i=0;i<n*2-3;i++)
  {
     for(j=i;j<n-2;j++)
     {
        cout<<" ";
     }  //part1
     cout<<"x";
     if(n>=2)
     {
     for(j=0;j<2*i-1;j++)//part2
     {
       cout<<"e";
     } 
     }
     cout<<"x";
      for(j=i;j<n-2;j++)
     {
        cout<<" ";
     }  //part3  
     cout<<"\n";
  } 
  for(i=0;i<n-1;i++)
  {
     cout<<" ";
  }
  cout<<"x";
  for(i=0;i<n-1;i++)
  {
     cout<<" ";
  }

}
