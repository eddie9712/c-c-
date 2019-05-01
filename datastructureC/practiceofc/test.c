#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    pid_t pid;
    int n=0;
    for(n=0;n<10;n++){
      pid=fork();
    if(pid>0) {
       printf("i am father\n");
    }
    else if(pid==0)
    {
        printf("i am child\n");
         exit(0);
     }
    }
}
