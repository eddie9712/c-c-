#include"stdio.h"   //try dynamic programming
#include"stdlib.h"
typedef struct{ 
      int value;
      int weight;
    }item;
int main()    //input the 1.max weight  2.sets of weights    3.sets of the value  4.numbers of the items
{
  int maxweight;
  int number;
  int i,j;
  printf("input the max weight of the knapsack:"); 
  scanf("%d",&maxweight);
  printf("input the numbers of items:");
  scanf("%d",&number);
  item *item1=calloc(number,sizeof(item));
  int *record=calloc(number,sizeof(int));
  int c[number+1][maxweight+1]; //allocate the memory
  for(i=0;i<=number;i++)
  {
    for(j=0;j<=maxweight;j++)
    {
      c[i][j]=0;
    }
  }
  for(i=1;i<=number;i++)  //input the sequence of items
  {
     printf("input the number %d item's value:",i+1);
     scanf("%d",&item1[i].value);
     printf("input the number %d item's weight:",i+1);
     scanf("%d",&item1[i].weight);
  }
 //for(i=0;i<8;i++)
 // {
 //    printf("%d\n",item1[i].weight);
  //}
  for(i=1;i<=number;i++)   //add the items into the knapsack
 {
   for(j=1;j<=maxweight;j++)
   {
       if(item1[i].weight<=j) 
        {
            if(item1[i].value+c[i-1][j-item1[i].weight]>c[i-1][j])  //add item or not 
            {
              c[i][j]=item1[i].value+c[i-1][j-item1[i].weight]; 
              
            }
             else
            {
               c[i][j]=c[i-1][j];        
               record[i]=1; 
            }
        }   
        else
        {
          c[i][j]=c[i-1][j];     
          record[i]=1; 
        }
   }
 }
 int compare=maxweight;
  printf("%d",c[number-1][maxweight]);
 printf("%d",c[number][maxweight]);
 printf("output the choice of the thief:");//output the choice of the thief
  for(i=number;i>0;i--)//trace the outcome
  {
    if(c[i][compare]!=c[i-1][compare]) //condition 1
    {
       if(compare<=0)
       break;
       compare=compare-item1[i].weight;
       printf("%d\n",i);
    }
  }
}