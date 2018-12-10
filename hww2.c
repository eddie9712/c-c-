#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000
void add();
void attach(char,char,int);
char *endofodd;
char *endofeven; 
char odd[max];
char even[max];
char temp[max];
int output[max];
int main()
{
  endofodd=odd;
  endofeven=even; 
  int number,i;
  printf("input the number of the amount:");
  scanf(" %d",&number);
   for(i=1;i<=number;i++)
  {
  	 char *temp=calloc(1000, sizeof(char)); 
         if(i%2==1) //if the terms is odd
        {
         setbuf(stdin, NULL);
	 fgets(temp,1000,stdin);
         attach(temp,odd,1);
        }
        if(i%2==0)  //if the terms is even
        {
          setbuf(stdin, NULL);
	 fgets(temp,1000,stdin);
         attach(temp,even,0);
        }
        free(temp);
  }
  add(odd,even);
  printf("%s",output)
} 
  void add(char odd[],char even[])
{
   int a=strlen(odd);
   int b=strlen(even);
   if(a-b<0) //even long
   {
     
   }
   if(a-b==0) //equal
   {
     
   }
   if(a-b>0)  //odd long
   {

   }
}
void attach(char temp[],int num)
{
   int j=0;
   if(num==1)
  {
    while(temp[j]!='\n')
   {
      *(endofodd)=temp[j];
      endofodd++;
      j++;
   }
  }
  if(num==0)
  {
    while(temp[j]!='\n')
   {
      *(endofeven)=temp[j];
      endofeven++;
      j++;
   } 
  }
}
