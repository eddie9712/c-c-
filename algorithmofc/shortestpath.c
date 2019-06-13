#include<stdio.h>    //implement shortest path algorithm
#include<stdlib.h>   //以某點做start point至各點之最小路徑algorithm 
#include<time.h>     //(沒加讀檔功能)
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
void buildminheap(heapnode *,int);
void minheapfy(heapnode *,int,int);
void find(heapnode *,nodeptr,int,int,int);
heapnode extractmin(heapnode *,int);
void relate(int,int,heapnode *,nodeptr *,int);
//int generateInput();  //產生輸入檔
//void read(int **);     //讀檔
nodeptr* buildLinkedlist(int *,nodeptr *,int);   //利用input建立linkedlist
nodeptr insert(nodeptr,int,int);
void findshortestath(nodeptr *,int *,int,int);    //找最小路徑 from  vertex i
int main()
{
    int size=6,i,j;
    //size=generateInput();
    int s;
    int array2d[6][6]={{0,8,0,0,0,1},{3,0,1,0,0,0},{5,0,0,2,2,0},{0,4,6,0,7,3},{0,0,0,0,0,0},{0,0,2,8,0,0}};   //因為沒有讀檔功能所以直接放入array
    //read(array2d);
    nodeptr *arraylinked=calloc(size,sizeof(nodeptr));
    for(i=0;i<size;i++)
    {
      arraylinked[i]=NULL;                       //initialize the linkedlinked list
    }
    arraylinked=buildLinkedlist(array2d,arraylinked,size);   //transform the matrix into linkedlist
    printf("chosing the starting point of the  path:");
    scanf("%d",&s);
    findshortestpath(arraylinked,printdata,size,s);   //find the shortest path of a input vertex(start)
}
/*int generateInput()
{
   srand(time(NULL));
   FILE *fp;
   int size,i,j;
   char c="\n";
   printf("input the networksize:(>=10)");   //input the networksize   
   scanf("%d",&size);
   fp=fopen("./input.txt","w+");//write the size of the network into the file
   fprintf(fp,"%d",size);
   fprintf(fp,"%c",c);
   for(i=0;i<size;i++)
   {
     for(j=0;j<size;j++)   //build the matrix
     { 
       int num;            //generate the number randomly(from 0-100)產生之數字為路徑之權重
       num=rand()%100;
       fprintf(fp,"%c ",num);     
     }
     fprintf(fp,"%c",c);
   }
   fclose(fp);
   return size;
}
void read(int **array2d)    //read the input file
{
    FILE *fp;
   fp=fopen("./input.txt","r+");
   int size,i,j;
   char c;
   fscanf(fp,"%d",&size);
       fscanf(fp,"\n",&c);
   printf("%d",size);
    int temp; 
     for(i=0;i<size;i++)
   {
      for(j=0;j<size;j++)
     {
       fscanf(fp,"%d ",&array2d[i][j]);
       printf("%d ",array2d[i][j]);
     }
      fscanf(fp,"\n",&c);
   }*/
   //fclose(fp);
nodeptr* buildLinkedlist(int *array2d,nodeptr arraylinked[],int size)   //將adjacency matrix 轉成 ajdacency linkedlist
{
  int array2d[6][6]={{0,8,0,0,0,1},{3,0,1,0,0,0},{5,0,0,2,2,0},{0,4,6,0,7,3},{0,0,0,0,0,0},{0,0,0,2,8,0}};
  nodeptr *p1;
  p1=arraylinked;
  int i,j;
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
    {
      if(array2d[i][j]!=0)   //如兩者間權重不是零(代表說兩者連通)
      {
        p1[i]=insert(p1[i],array2d[i][j],j);
       }
    }
  }
  return p1;
}
nodeptr insert(nodeptr p1,int data,int j) //建立linkedlist
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
void findshortestpath(nodeptr p1[],int printdata[],int size,int start)  //找尋shortestpath
{
   int i,j;
   heapnode min;
   heapnode heap[size+1];
   int sizeofheap;
   sizeofheap=size;
   for(i=1;i<=size;i++)   //initialize        
   {
      heap[i].predecessor=-1;    
      heap[i].distance=INT_MAX;
      heap[i].element=i-1;
   }
   heap[start+1].distance=0;  //start from the start point
   buildminheap(heap,size);
   for(j=0;j<size;j++)    //traversal all the vertices
   {
     min=extractmin(heap,sizeofheap);   //find the smallest element of the heap  and  move the element from the heap to the set of founded
     sizeofheap--;
     relate(min.element,min.distance,heap,p1,sizeofheap);   //find the vertex which near to the vertex fonded
     //printdata[j]=min;   //record the vertex
   }
   for(i=1;i<=size;i++)  //print heap content
   {
      printf("element:%d\n",heap[i].element);
      printf("distance:%d\n",heap[i].distance);
   }
}
heapnode extractmin(heapnode heap[],int sizeofheap)   //return the minimum distance of the heap，and delete the element in the queue
{
   heapnode min=heap[1];
   if(sizeofheap==0)
     printf("the heap empty!!!");
   swap(heap,1,sizeofheap);
   minheapfy(heap,1,sizeofheap-1);//do the heapify
   return min;
}
void relate(int from,int predistance,heapnode heap[],nodeptr p1[],int sizeofheap)
{
   nodeptr x;
   x=p1[from];
   while(x!=NULL)
   {
     find(heap,x,from,predistance,sizeofheap);   //modify the distance of each node
     x=x->next;
   }
   buildminheap(heap,sizeofheap);
}
void buildminheap(heapnode heap[],int size)
{
  int i;
  int n=size/2;  
  for(i=n;i>=1;i--)  //minheapfy n nodes
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
   smallest=k;
   if(l<=size&&heap[l].distance<heap[k].distance)
   {
     smallest=l; 
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
void find(heapnode heap[],nodeptr x,int from,int predis,int sizeofheap)   //更新heap 的資料
{
  int i; 
  for(i=1;i<=sizeofheap;i++)   //traversal the heap array
  {
     if(x->vertex==heap[i].element)   //find the node in heap
     {
        if(heap[i].distance>(predis+x->pathlength))//modify the heapnode if path smaller
        {
          heap[i].distance=(predis+x->pathlength);
        } 
     }
  }
}

