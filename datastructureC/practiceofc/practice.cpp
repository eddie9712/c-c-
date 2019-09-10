#include<iostream>
#include<cstdlib>
using namespace std;
//float *findmax(float a[],int n)
//{
//  int i;
//  float *themax=&(a[0]);
//  for(i=0;i<n;i++)
//  {
//     if(a[i]>*themax)
//     {
//       themax=&(a[i]);
//     }
//  }
//  return themax;
//}
int main()
{
   //int x=42;
   //cout.setf(ios::oct|ios::hex);
   //cout<<x<<"\n";
   //cout.setf(ios::dec,ios::basefield);
   //cout<<x<<"\n";
   //cout.setf(ios::hex,ios::basefield);
   //cout<<x<<"\n";
   //int x=42;// show the basis
   //float y=3.1412;
   //cout.setf(ios::showpos);   //give the sign
   //cout<<x<<"\n";
   //cout<<y<<"\n";
   //int x=42;
   //cout.setf(ios::uppercase);
   //cout.setf(ios::hex,ios::basefield);
   //cout<<x<<"\n";
   //setting the width
   //int x=42;
   //cout.width(5);
   //cout<<x<<"\n";
   //cout.width(20);
   //cout<<x<<"\n";
   //int x=42;
   //cout.width(5);
   //cout.fill('x');
   //cout<<x<<'\n';
   //int x=42;
   //cout.setf(ios::showpos);
   //cout.fill('x');
   //cout.setf(ios::right,ios::adjustfield);   //adjustfield turn off another flag
   //cout.width(6);
   //cout<<x<<"\n";
   //cout.setf(ios::left,ios::adjustfield);
   //cout.width(6); 
   //cout<<x<<"\n";
   //cout.setf(ios::internal,ios::adjustfield);   //after the sign or basis
   //cout.width(6);
   //cout<<x<<'\n';
   //float y=3.0;   //to make sure demical point appears in output
   //cout<<y<<'\n';
   //cout.setf(ios::showpoint);
   //cout<<y<<'\n';
   //float y=23.1415;//using function precision to set the number
   //cout.precision(1);
   //cout<<y<<'\n';
   //cout.precision(2);
   ///cout<<y<<'\n';
   //cout.precision(3);
   //cout<<y<<'\n';
   //using the ios::scientific(科學記號表示)  ios::fixed(一般小數表示)
   //cout.setf(ios::scientific,ios::floatfield);
   //cout<<123.45<<endl;
   //cout.setf(ios::fixed,ios::floatfield);
   //cout<<5.67E1<<endl;
   //bool b=true;
   //cout.setf(ios::boolalpha);
   //cout<<b<<'\n';
   //cout<<(!b)<<'\n';
   //int a,*ap,b,*bp;//test pointer
   //ap=&a;
   //bp=&b;
   //a=5;
   //b=6;
   //cout<<a<<endl<<ap<<endl<<b<<endl<<bp<<endl<<&a<<endl<<&ap<<endl<<*ap;
   //int c[10];
   //int *p;  //*(p+4)=*(a+4);
   //p=c;
   //char *a="hello";
   //cout<<*a;
   //int array[10][10];
   //int i,j;
   //for(i=0;i<10;i++)
   // {
   //  for(j=0;j<10;j++)
   // {
   //    array[i][j]=j;
   // }
   // }
   // cout<<*(array[0]+2);
   //int x=101;
   //int *p=&x;
   //int **q=&p;
   float a[6]={1.0,2.0,1.0,0.5,3.0,2.0};
   float *themin=&(a[0]);
   float *walker=&(a[1]);
   while(walker<&(a[6]))
   {
    if(*walker<*themin)
    {
       themin=walker;
    }
    walker=walker+1;
   }
  printf("%.1f");  
}
