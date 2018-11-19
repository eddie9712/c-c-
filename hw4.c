#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000 
char input[max]={'\0'};
char* replace(char *,char *,char *);
int main()
{
   char word[max]={'\0'};
   char target[max]={'\0'};
   fgets(input,1000,stdin);  //input the data to replace
   fgets(target,1000,stdin);
   fgets(word,1000,stdin);
   char *s2=replace(input,target,word);
   printf("%s",s2);  //outcome
}
  int word_L=strlen(word);
  while(1)
 {
   char *find;
   printf("%s",target);
   find=strstr(input,target);
   if(find==NULL)
   { 
       break;
   } 
   strncpy(find,word,word_L);
  } 
}  










