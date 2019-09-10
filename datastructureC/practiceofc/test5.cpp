#include<iostream> 
using namespace std;
void print(int i)
{
   int a,b,c; 
  for(a=1;a<=2*i-1;a++) 
 { 
   if(a<=i) 
  { 
   for(b=i;b>a;b--) 
   printf(" "); 
   printf("x"); 
   for(c=1;c<=2*a-3;c++) 
   printf(" "); 
  if(a>1) 
  printf("x"); 
  } 
  else 
 { 
   for(b=a;b>i;b--) 
   printf(" "); 
   printf("x"); 
  for(c=1;c<=4*i-2*a-3;c++) 
  printf(" "); 
  if(a<2*i-1) 
  printf("x"); 
} 
printf("\n"); 
} 

}
int main() 
{ 
  int i;
  while(1) 
  {
   printf("input:"); 
   scanf("%d",&i);
   print(i); 
  }
return 0; 
} 