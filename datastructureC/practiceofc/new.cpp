#include<iostream>      //passing an array to a function
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
int countid;
char output[10];
int numof=0;
class Person
{
public:
	int Id;
	int age;
	char name[10];
  int t;
  char coursename[10];
  int Grade;
	Person()
	{
	}
	Person(int id)
	{
		Id =id;
        
	}
	int getage()
	{
		return age;
	}
	virtual void WhoAmI()  
	{
		
	}
};
Person **Member = new Person * [20];
void genRandomString(int length, char* ouput)   //radom generate
{
	int flag, i;
	srand((unsigned)time(NULL));
	for (i = 0; i < length - 1; i++)
	{
		flag = rand() % 3;
		switch (flag)
		{
		case 0:
			ouput[i] = 'A' + rand() % 26;
			break;
		case 1:
			ouput[i] = 'a' + rand() % 26;
			break;
		case 2:
			ouput[i] = '0' + rand() % 10;
			break;
		default:
			ouput[i] = 'x';
			break;
		}
	}
}

class Student : public Person 
{
	public:
  int Grade;
	Student(int sid): Person(sid)
	{
	    t=0;
        genRandomString(10,output);
        strcpy(name,output);
        Grade=rand()%100;
        WhoAmI(); 
    }
	void PrintGrade()
    {
		cout << Grade <<endl;  
	}
virtual void WhoAmI()
	{
		cout << "I am a student  "<<endl;
	    cout<<"ID:"<<Id<<"\n";
        cout<<"name:"<<name<<"\n";
        cout<<"grade:";
        PrintGrade();
        cout<<"enter age:";
        cin>>age;
	}	
};
class Teacher : public Person 
{
public:
	char coursename[10];
	Teacher(int sid): Person(sid)
	{
      t=1;
      genRandomString(10,output);
      strcpy(name,output);
      genRandomString(10,output);
      strcpy(coursename,output);
	  WhoAmI();
	}
virtual void WhoAmI()
	{
		cout << "I am a teacher  " <<endl;
	    cout<<"Id:"<<Id<<"\n";
		cout<<"name:";
    cout<<name<<"\n";
    cout<<"coursename:";
		cout<<coursename<<"\n";  
		cout<<"please enter the age:\n";
		cin>>age;
	}
};
void printall()
{
  int i;
  float sum,t;
  for(i=0;i<numof;i++)
  {
   cout << "I am a student  "<<endl;
   cout<<"ID"<<Member[i]->Id<<"\n";
   cout<<"name:"<<Member[i]->name<<"\n";
   if(Member[i]->t!=0)
   {
    cout<<"coursename"<<Member[i]->coursename<<"\n";
   }
   else
   {
     cout<<"grade:"<<Member[i]->Grade<<"\n";
   }
    sum+=Member[i]->age;
  }
  cout<<"average"<<sum/numof;
}
void print2(int t)
{
   int i;
   float sum=0,t1=0;
  for(i=0;i<numof;i++)
  {
    if(Member[i]->t==1)
   {
    t1++;
    cout << "I am a teacher  "<<endl;
    cout<<"ID"<<Member[i]->Id<<"\n";
    cout<<"name:"<<Member[i]->name<<"\n";
    cout<<"coursename"<<Member[i]->coursename<<"\n";
    sum+=Member[i]->age; 
   }
  }
   cout<<"age:"<<sum/t1<<"\n";
}
void print1(int t)
{
   int i;
   float sum=0,t1=0;
  for(i=0;i<numof;i++)
  {
    if(Member[i]->t==0)
   {
    t1++;
    cout << "I am a student"<<endl;
    cout<<"ID"<<Member[i]->Id<<"\n";
    cout<<"name:"<<Member[i]->name<<"\n";
    cout<<"coursename"<<Member[i]->Grade<<"\n";
    sum+=Member[i]->age; 
   }
  }
   cout<<"age:"<<sum/t1<<"\n";
}
void print(int k,Person **Member)
{
  int i;
   for(i=0;i<numof;i++)
  {
    if(Member[i]->Id==k) 
    {
     cout << "I am a student  "<<endl;
    cout<<"ID"<<Member[i]->Id<<"\n";
    cout<<"name:"<<Member[i]->name<<"\n";
    if(Member[i]->t!=0)
    {
    cout<<"coursename"<<Member[i]->coursename<<"\n";
   }
   else
   {
     cout<<"grade:"<<Member[i]->Grade<<"\n";
   }
   cout<<"enter age:"<<Member[i]->age<<"\n";
  }
   }
  }
void remove(int dele)
{
    int i=0,temp,change=0;   
	   if (numof == 0)
	 {
		cout <<"the group is empty"<<endl;
		return ;
	 }
	 for(i=0;i<numof;i++)	   //find the person 
	 {
		if(Member[i]->Id==dele)
	   {
		  temp=i;
		  change=1;  //if found
	     //    printf("%d",temp);
	   }
   }
	 if(change!=1)
	{
       cout<<"the person not found"<<"\n";          
      return ;
	}
	if(numof!=1)
    {
      for (i = temp; i <numof-1; i++)  //adjust the member array
	 {
	   Member[i]=Member[i+1];	
	 }	  	
	}
	Member[numof-1]=NULL;		
	numof--;
}
void getinstruction(char c)
{
    switch (c)
    {
     case '1':
     {
     Teacher T(countid);
     Member[numof]=&T;
     numof++;
     countid++; 
     break;
     }
    case '2':
     {
     Student S(countid);
     Member[numof]=&S;
     cout<<Member[1]->Id;
     numof++;
     countid++; 
     }
    break;
    case '3':
     int k;
     cout<<"input id:";
     cin>>k;
     print(k,Member);
     break;
    case '4':
     print1(0);
    break;
   case '5':
    print2(1);
    break;
   case '6':
   printall();
    break;
   case '7':
   cout<<"input id";
   int f;
   remove(f); 
   break;
    }
  }  
int main()
{
  char c;
  while(1)
  {
   printf("input instrucction:");
   cin>>c;
   if(c==0)
   {
    printf("end");
     break;
   }
   getinstruction(c);
  }
}