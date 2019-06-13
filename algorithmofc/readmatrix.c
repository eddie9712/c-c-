#include<stdio.h>    //a module to read an input file of matrix(type char) and transform the type to integer
#include<stdlib.h>   //and put them into an 2d array
int** transform(int *);    //input a file names "input.txt" with format :size
int main()               //                                         and martix n*n
{
    int **array2d;
    int i,j; 
    int size=0;
    array2d=transform(&size);
    for(i=0;i<size;i++)
    {
      for(j=0;j<size;j++)
      {
       printf("%d",array2d[i][j]);
      }
     printf("\n");
    }
}
int **transform(int *input)
{
   FILE *fp;
   int h;
   fp=fopen("./input.txt","r+");
   char buff[50]={'\0'};
   char c;
   int i=0,k,j=0;
   while(c=fgetc(fp)!='\n')//scan the size
  {
     printf("%c",c);
     buff[i]=c;
     i++;
  }
  printf("%c",buff[0]);
  int size=atoi(buff);//read the size of the matrix
  printf("%d",size);
  (*input)=size;
  int **array=calloc(size*size,sizeof(int));
  while(c=fgetc(fp)!=EOF)
 {
   if(c=='\n'||c==' ')   //if c=space or '\n'=>transform a number
   {
       if(c=='\n')   //array2d++
      {
        i++;  
      }
      array[i][k]=atoi(buff);
      k++;
      for(h=0;h<50;h++)
      {
         buff[h]='\0'; 
      }
   } 
   else
   {
      buff[i]=c;
      i++;
   }
 }
//for(i=0;i<size;i++)
//    {
//      for(j=0;j<size;j++)
//      {
//       printf("%d",array[i][j]);
//      }
//     printf("\n");
//    }
} 