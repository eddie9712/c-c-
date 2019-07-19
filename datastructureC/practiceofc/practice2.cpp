#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
   int input,i,j,k;
   while(1)
   {
     cout<<"input the number:\n";
     cin>>input;
     for(i=1;i<=input;i++)
     {
       for(k=0;k<input-i;k++)
       {
         cout<<" ";   
       }
       for(j=1;j<=i;j++)
       {
           cout<<"*";
       } 
       cout<<"\n";
     }
   }
}