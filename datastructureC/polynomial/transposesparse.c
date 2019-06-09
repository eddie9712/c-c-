//to transpose the sparse matrix
#define max 100
typedef struct 
{
    int col;
    int row;
    int value;
}terms;
terms a[max];
terms b[max];
void transpose()
{
  int n,i,j,current;
  b[0].value=a[0].value;
  b[0].row=a[0].col;
  b[0].col=a[0].row;
  if(n>0)  
  {
      current=1;
      for(i=0;i<a[0].col;i++) //find the column of a
      {
        for(j=1;j<=n;j++)  //find all of the values
        {
          if(a[i].col==i)  //each column
          {
             b[current].row=a[j].col;
             b[current].col=a[j].row;
             b[current].value=a[j].value;
             current++;   
          }
        }
      }
      
  }

}