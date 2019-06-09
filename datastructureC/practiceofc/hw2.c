#include<stdio.h> //to add polynomial (algorithm) 
#include<stdlib.h> 
#define compare(x,y) ((x)<(y))?-1:((x)==(y))?0:1  
#define max 100
typedef struct{
  float coef;
  int expon;
 }polynomial;
polynomial terms[max];
int avail=0;
int starta=0;
int finisha=0;
int startb=0;
int finishb=0;
void attach(int,int);
void add(int,int,int,int,int *,int *);
void add(int starta,int finisha,int startb,int finishb,int *startd,int *finishd)
{
  float coefficien;
  *startD=avail;
  while(starta<=finisha&&starb<=finishb)
 {
   switch(compare(terms[starta].expon,terms[startb].expon))
  {
   case -1: //exponential a<b
    attach(terms[startb].coef,terms[startb].expon);
    start b++;
    braek;
   case 0: //exponential a==b
    cofficient=terms[startb]+terms[startb];
    if(cofficient)
     attach(cofficient,terms[startb].expon);
    starta++;
    startb++;
    break;
   case 1:
    attach(terms[starta].coef,terms[starta].expon);
    start b++;
    braek;
  } // maybe one of the polynomial get finished first 
   for(;startb<=finishb;startb++)  //if a empty
   {
     attach(terms[startb].coef,terms[startb].expon);
   }
   for(;starta<=starta;starta++)   //if b empty
   {  
      attach(terms[starta].coef,terms[starta].expon);
   }
   *finishd=avail-1;
 }
}
 void attach(float coefficient,int exponent)
{
  if(avail>=max)
 {
   fprintf(stderr,"too many terms in the poly \n");
   exit();
 }
  terms[avail].coef=coefficent;
  terms[avail].expon=exponent;
  avail++;
}


 




