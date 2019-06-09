#include<stdio.h>     //suppose there are processes running(with types of resources) (not test yet)
#include<stdlib.h>    //using banker's algorithm to decide which request can be admitted
void saftey(int,int,int **,int **,int *,int *,int *,char);  //check if the request is safety
bool workcomplete(int,int **,int *);
int main()            
{ 
  int numofprocess;
  int type,i,j,k,t=0,y;
  printf("input the numbers of process to run:");
  scanf("%d",&numofprocess);
  printf("input the numbers of the resources types:");
  scanf("%d",&type);
  printf("input for the resources:");
  int amount[type];
  int *finish=calloc(numofprocess,sizeof(int));
  int allocation[numofprocess][type];
  int max[numofprocess][type];
  int need[numofprocess][type];
  int available[type];
  for(i=0;i<type;i++)  //set all resources 
  {
    scanf("%d",&amount[i]);  
  }
  printf("input the resources allocation of processes:\n");
  for(i=0;i<numofprocess;i++)  //set the allocation
  {
   printf("p%d:\n",i);
   for(j=0;j<type;j++)
   {
    scanf("%d",&allocation[i][j]);   
   }
   printf("P%d:\t",i);
   for(k=0;k<type;k++)
   {
     printf("%d\t",allocation[i][k]);
   }
   printf("\n");
  }
  printf("input the resources max for each process:\n");
  for(i=0;i<numofprocess;i++)  //set the max
  {
   printf("p%d:\n",i);
   for(j=0;j<type;j++)
   {
    scanf("%d",&max[i][j]);   
   }
   printf("P%d:\t",i);
   for(k=0;k<type;k++)
   {
     printf("%d\t",max[i][k]);
   }
   printf("\n");
  }
  printf("all of the information with each processes:\n");
  for(i=0;i<numofprocess;i++)  // print the allocation
  {
    printf("p%d:");
    for(j=0;j<type;j++)
    {
      printf("\t%d",allocation[i][j]);
    }
    printf("\n");   
  }
  for(i=0;i<numofprocess;i++)  // print the max
  {
    printf("p%d:");
    for(j=0;j<type;j++)
    {
      printf("\t%d",max[i][j])
    }
    printf("\n");   
  }
  printf("resources available:\n");
  for(i=0;i<type;i++)  //print available
  {
    int temp=0;
    for(j=0;j<numofprocess;j++)
    {
       temp+=allocation[j][i];
    } 
    available[i]=amount[i]-temp;
    printf("\t%d",available[i]);
  }  
  printf("\n");
  printf("resources needed:\n");
  for(i=0;i<numofprocess;i++)  //print need
  {
   printf("p%d:",i);
   for(j=0;j<type;j++)
   {
     need[i][j]=max[i][j]-allocation[i][j];
     printf("\t%d",need[i][j]);
   }
   printf("\n"); 
  }
  int *request=calloc(type,sizeof(int));
  printf("requset or not:(y/n)");
  scanf("%c",&y);
  if(y=='y')
  {
    printf("which process create the request:");
    scanf("%d",&t);
    for(i=0;i<type;i++)
   {
    scanf("%d",&request[i]);
   }
  }
   printf("print the outcome of the predict:\n");
   int outcome=saftey(type,t,allocation,need,available,request,finish,y);
   switch(outcome)
    {
     case 1:
      {
        printf("there is no probability for deadlock"); 
        printf("print the saftey sequence:");
        for(i=0;i<numofprocess;i++)  //printf the saftey sequence
        {
          printf();
        }
        break;
      }
      case 2:
       {
          printf("the requset may cause deadlock!"); 
          break;
       }
      case 3:
      {
        printf("request exceed the maximum of the process!");
        break;
      }
      case 4:
      {
        printf("this request must wait for the resource!");
        break;
      }  
    }

}
void safety(int type,int process,int numofprocess,int allocation[][],int need[][],int available[],int request[],int finish[],char y)
{
  int i;
  int *work=calloc(type,sizeof(int));
  if(y=='y')
  {
     for(i=0;i<type;i++)  //if request exceed it maximum
     {
        if(request[i]>need[process][i])
        return 3;
     }
     for(i=0;i<type;i++)  //if there are enough resources
     {
       if(request[i]>available[i]);
       return 4;
     }
     //if the request reasonable
     for(i=0;i<type;i++)
     {
      available[i]=available[i]-request[i];  
      allocation[t][i]=allocation[t][i]+request[i];
      need[t][i]=need[t][i]-request[i]; 
     }
 } 
  for(i=0;i<type;i++)  //initialize
 {
    work[i]=available[i]; 
 }
 int change=0;
 int all=0;
 while(1)
 {
   change=0;
   for(i=0;i<numofprocess;i++)  //find which process can complete
   {
    if(finish[i]==0&&workcomplete(type,need,i,work))
    {
     finish[i]=1;
     for(j=0;j<type;j++)   //give the resource back
     {
       work[k]=work[k]+allocation[i][j];
     }
    change=1;  //which mean it have comeplete any work for a iterative
    }   
   }
   if(change==0)//if there is deadlock happening
   {
     for(i=0;i<numofprocess;i++)
     {
       if(finish[i]==1)
         all++;
     } 
     if(all==numofprocess)
     {
        return 1; 
     }
     else
     {
       return 2;
     }
   }
 }
}
bool workcomplete(int type,int need[][],int process,int work[])
{
  int i;
  for(i=0;i<type;i++)
  {
    if(need[proces][i]>work[i])
      return 0;     
  }
}  
