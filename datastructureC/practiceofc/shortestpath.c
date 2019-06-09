#include<stdio.h>    //implement of shortest path algorithm  (假設有可能vertex有自己的cycle) 
#include<stdlib.h>   //以某點做single source 至各點之最小路徑algorithm 
#include<time.h>
#include<limits.h>
typedef struct node *nodeptr;    //struct for adjacency linkedlist
typedef struct node
{
   int pathlength;
   int vertex;
   nodeptr next;  
}node;
typedef struct heapnode *heapnodeptr;
typedef struct heapnode
{
   int predecessor;
   int distance;
   int element;
}heapnode;
void swap(heapnode *,int,int);
void delete();
void buildminheap();
void minheapfy();
int extractmin();
void modify();
void relate();
void print();    //print the outcome
int generateInput();  //產生輸入檔
void read(int **);     //讀檔
nodeptr* buildLinkedlist(int **,nodeptr,int);   //利用input建立linkedlist
nodeptr insert(nodeptr,int,int);
void findShortestPath(nodeptr *,int *,int);    //找最小路徑 from  vertex i
int main()
{
    int size,i;
    size=generateInput();
    int *printdata=calloc(size,sizeof(int));   //the set of which is found
    int s;
    int array2d[size][size];
    read(array2d);
    nodeptr arraylinked[size+1];
    for(i=0;i<=size;i++)
    {
      arraylinked[i]=NULL;                       //initialize the linkedlinked list
    }
    arraylinked=buildLinkedlist(array2d,arraylinked,size);   //transform the matrix into linkedlist
    printf("chosing the starting point of the  path:");
    scanf("%d",&s);
    findShortestPath(arraylinked,printdata,size);   //find the shortest path of a input vertex(start)
    print();//print  the  shortest to all others vertex 
}
int generateInput()
{
   srand(time(NULL));
   FILE *fp;
   int size,i,j;
   printf("input the networksize:(>=10)");   //input the networksize   
   scanf("%d",&size);
   fp=fopen("./input.txt","w+");//write the size of the network into the file
   fprintf(fp,"%d",size);
   fprintf(fp,"%c","\n");
   for(i=0;i<size;i++)
   {
     for(j=0;j<size;j++)   //build the matrix
     { 
       int num;            //generate the number randomly(from 0-100)產生之數字為路徑之權重
       num=rand()%100;
       fprintf(fp,"%d ",num);     
     }
     fprintf(fp,"%c","\n");
   }
   fclose(fp);
   return size;
}
void read(int **array2d)    //read the input file
{
   FILE *fp;
   fp=fopen("./input.txt","r+");
   int size,i,j;
   fscanf(fp,"%d",&size);
   printf("%d",size);
   fgetc(fp);
      for(i=0;i<size;i++)
   {
     for(j=0;j<size;j++)
     {
       fscanf(fp,"%d ",&array2d[i][j]); 
     }
     fgetc(fp);
   }
   fclose(fp);
}
nodeptr* buildLinkedlist(int **array2d,nodeptr arraylinked[],int size)    //資料尚未修正
{
  int i,j;
  for(i=1;i<=size,i++)
  {
    for(j=1;j<=size;j++)
    {
      if(array2d[i-1][j-1]!=0)   //如兩者間權重不是零(代表說兩者連通)
      {
        arraylinked[i]=insert(arraylinked[i],array2d[i-1][j-1],j);
      }
    }
  }
  return arraylinked;
}
nodeptr insert(nodeptr p1,int data,int j) //
{
   nodeptr x;
   nodeptr temp;
   x=p1;
   temp=malloc(sizeof(node));
   temp->next=NULL;
   temp->pathlength=data;
   temp->vertex=j;
   if(p1==NULL)
    {
      p1=temp;
      return p1;
    }
    else
    {
      while(x!=NULL)   
      {
         if(x->next==NULL)
         {
            x->next=temp;
            return p1;   
         }
         x=x->next;   
      }
    }
}
void findshortestpath(nodeptr *p1,int printdata,int size,int start)
{
   int i,j,min;
   heapnode heap[size+1];
   int sizeofheap;
   sizeofheap=size;
   for(i=1;i<=size;i++)   //initialize        
   {
      heap[i].predecessor=-1;    
      heap[i].distance=INT_MAX;
      heap[i].element=i;
   }
   heap[start].distance=0;  //start from the start point
   buildminheap(heap,size);
   for(j=0;j<size;j++)    //traversal all the vertices
   {
     min=extractmin(heap,printdata,sizeofheap);   //find the smallest element of the heap  and  move the element from the heap to the set of founded
     sizeofheap--;
     relate(min,heap,p1,sizeofheap);   //find the vertex which near to the vertex fonded
     modify();   //modify the minheap
     printdata[j]=min;   //record the vertex
   }
}
int extractmin(heapnode heap[],int sizeofheap)   //return the minimum distance of the heap，and delete the element in the queue
{
   int min=heap[1].element;
   if(sizeofheap==0)
     printf("the heap empty!!!");
   heap[1].distance=heap[sizeofheap-1].distance;   //put the   last node to the first
   heap[1].element=heap[sizeofheap-1].element;   
   heap[1].predecessor=heap[sizeofheap-1].predecessor;
   minheapfy(heap,1,sizeofheap-1);//do the heapify
   return min;
}
void relate(int from,heapnode heap[],nodeptr p1[],int sizeofheap)
{
   nodeptr x;
   p1[]


}
void buildminheap(heapnode heap[],int size)
{
  int i;
  int n=size/2;  
  for(i=n;i>=1;i++)  //minheapfy n nodes
  {
    minheapfy(heap,i,size);
  }
}
void minheapfy(heapnode heap[],int k,int size)
{
   int l,r;
   int smallest;
   l=2*k;  //left child
   r=2*k+1;  //right child
   if(l<=size&&heap[l].distance<heap[k].distance)
   {
      smallest=l; 
   }
   else if(l<=size&&heap[l].distance>heap[k].distance)
   {
     smallest=k;  
   }
   if(r<=size&&heap[r].distance<heap[smallest].distance)
   {
     smallest=r ;
   }
    if(smallest!=k)
    {
      swap(heap,k,smallest);
      minheapfy(heap,smallest,size); 
    } 
}
void swap(heapnode heap[],int a,int b)
{
   int temp1,temp2,temp3; 
   temp1=heap[a].distance;
   temp2=heap[a].predecessor;
   temp3=heap[a].element;
   heap[a].distance=heap[b].distance;
   heap[a].predecessor=heap[b].predecessor;
   heap[a].element=heap[b].element;
   heap[b].distance=temp1;
   heap[b].predecessor=temp2;
   heap[b].element=temp3;
}

