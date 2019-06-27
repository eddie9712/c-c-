#include<stdio.h>
int main()
{
    int count=0;
    int k,i,j;
    for(k=1;k<=5;k++)
    {
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
            {
               if(i!=j)
                 count++;
            }
        }
    }
    printf("%d",count);
}