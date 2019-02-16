#include<stdio.h>            //polynomial addition
#include<stdlib.h>           //輸入係數次方係數次方...輸入0coef代表結束輸入
#define max 100 
int compare(int,int);
typedef struct{
  int coef;
  int exp;
}polynomial;
polynomial term[max];
int avail=0;
void padd(int,int,int,int,int *,int *);     //for coef and exp
void attach(int,int);
int main()
{
   int n=0;
   int starta,finisha,startb,finishb;
   int *startd;
   int *finishd;
   starta=0;
   finisha=starta;
   printf("give the poly1:");
    while(1)   //to read the polynomial
   {
     if(starta==max)
       printf("overflow");
     scanf("%d",&term[starta].coef);
     if(term[starta].coef==0)
       break;
     scanf("%d",&term[starta].exp);
     finisha++;
   }
   printf("give the poly2:");
   finisha--;
   startb=finisha+1;
   finishb=startb;
   while(1)
   {
     if(startb==max)
       printf("overflow");
     scanf("%d",&term[startb].coef);
     if(term[startb].coef==0)
       break;
     scanf("%d",&term[startb].exp);
     finishb++;
   }
   finishb--;
   avail=finishb+1;
   padd(starta,finisha,startb,finishb,startd,finishd);   //add two polynomial
    ///print the polynomial
}
void padd(int starta,int finisha,int startb,int finishb,int *startd,int *finishd)
{
   int addcoef; 
   while(starta<=finisha&&startb<=finishb)
  {
    switch(compare(term[starta].exp,term[startb].exp))
    { 
     case 1:
     attach(term[starta].coef,term[starta].exp);
     starta++;
     break;
     case -1:
     attach(term[startb].coef,term[startb].exp);
     startb++;
     break;
     case 0:
     addcoef=term[starta].coef+term[startb].coef;
     starta++;
     startb++;
     if(addcoef!=0)
      attach(addcoef,term[starta].exp);
    }
  }
  for(;starta<=finisha;starta++) //the remain part of the polynomial1
 {
   attach(term[starta].coef,term[starta].exp);
 }
  for(;startb<=finishb;startb++)   //the remain part of the polynomial2
 {
    attach(term[startb].coef,term[startb].exp);
 }
}
void attach(int coef,int exp)
{
   if(avail>=max)
     printf("to many terms");
   term[avail].coef=coef;
   term[avail].exp=exp;
   avail++;  
}
int compare(int a,int b)
{
  if(a>b)
   return 1;
  else if(a==b)
   return 0;
  else if(a<b)
   return -1; 
}  
