#include<stdio.h>
int main()
{
    int i=0;
    int array[5]={1,2,3,4,5};
    printf("%d",array[i++]);   //means array[i],then i++  print 1
    printf("%d",i);    //print 1
}