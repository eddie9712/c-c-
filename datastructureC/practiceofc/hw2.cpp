#include<iostream>      //passing an array to a function
#include<cstdlib>
#include<string>
using namespace std;
struct date{    //date strctre
  int day;
  int month;
  int year;
};
struct student{   //student structure
    int id;
    char department[10];
    date birthday;
    int age;
    char name[15];
};
int f1(student &);
int f2(student *);
void f3(student &);
void f4(student *,int);
int main()
{
   int count2;
   student s[300];
   count2=f2(&s[0]);
   f4(&s[0],count2);  
}
int f1(student *s)   //get student data
{
   cout<<"input the student data:\n";
   cout<<"input id:(id=-1 exit)\n";
   cin>>s->id;
   if(s->id==-1)  
   {
       return 0;
   } 
   if(s->id==0)
   {
      return 0;
   }     
   cout<<"input name:\n";
   cin>>s->name;
   cout<<"input age:\n";
   cin>>s->age;
   cout<<"input department:\n";
   cin>>s->department;
   cout<<"input birthday:\n";
   cout<<"year:";
   cin>>s->birthday.year;
   cout<<"month:";
   cin>>s->birthday.month;
   cout<<"day:";
   cin>>s->birthday.day;
   return 2;
}
int f2(student s[])   //retrn student amounts
{
  int count1=0,control=1,i=0;
  while(control!=0&&i!=299)
  {
   control=f1(&s[i]);
   if(control==2)
     count1++;
   i++; 
  }     
  return count1;
}
void f3(student *s)   //print student data
{
   cout<<"name:\n";
   cout<<s->name<<"\n";
   cout<<"age:\n";
   cout<<s->age<<"\n";
   cout<<"department:\n";
   cout<<s->department<<"\n";
   cout<<"birthday:\n";
   cout<<"year:\n";
   cout<<s->birthday.year<<"\n";
   cout<<"month:\n";
   cout<<s->birthday.month<<"\n";
   cout<<"day:\n";
   cout<<s->birthday.day<<"\n";
}
void f4(student s[],int count)   //print all
{
   int i;
   for(i=0;i<count;i++)
   {
     f3(&s[i]);   
   }
}