#include<stdio.h>
#include<stdlib.h>
#define max 100000
void reverse(char *,char *);
 int main()
{
   int number,g;
    scanf("%d",&number);
   for(g=0;g<number;g++)
  { 
    char *array=calloc(max,sizeof(char));
    char *array1=calloc(max,sizeof(char));
    getchar();
    fgets(array,100000,stdin);
    reverse(array,array1); 
    free(array);
    free(array1);   
  }
}
 void reverse(char array[],char array1[])
{
   int i=0;
   int n=0;
   int k=0;
   int t=0;
    int final;
    int r;
    while(array[i]!='\0')
   {
     if(array[i]==' ')
    {
       r=i;
        while(n!=i)
      {
       if(t==0)
      {
       array1[n]=array[i-n-1];
       n++;
       }
       if(t==1)
       {
         array1[n]=array[r-1];    
         r--;
         n++; 
       }
      }
      array1[n]=' ';
      n++;       
     t=1; 
     }
     i++;
   }
    int a=i;
   while(n!=i-1)
   {
      if(t==0)
    {
      array1[n]=array[i-n-2];
      n++;
    }
     else
    {
     array1[n]=array[a-2];
     a--;
     n++;
    }
  }
   while(1)
  {
    if(array1[k]=='\0') 
    {
      final=k;
      break;
     }
     k++;
  }
   int p;
   for(p=final;p>=0;p--)
  {
     printf("%c",array1[p]);


  }

}
