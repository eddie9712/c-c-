#include<iostream>      //passing an array to a function
#include<cstdlib>
#include<string>
using namespace std;
int countid;
struct student{   //student structure
    int id;
    int age;
    char name[15];
};
int f1(student &);
int f2(student *);
void f3(student &);
void f4(student *,int);
class Person
{
protected:
	int Id;
	int age;
	string name;
public:
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
class Student : public Person 
{
private:
	int Grade;
public:
	Student(int sid): Person(sid)
	{
	}
	
	Student(int sid, int grade): Person(sid)
	{
		Grade = grade;
	}

	void PrintGrade()
    {
		cout << "Id:" << Id << "   Grade :  " << Grade <<endl;  
	}
virtual void WhoAmI()
	{
		cout << "I am a student  " << Id <<endl;
	    PrintGrade();
	}	
};
class Teacher : public Person 
{
private:
	string coursename;
public:
	Teacher(int sid): Person(sid)
	{
	  strcpy(name,output);
	  WhoAmI();
	}
virtual void WhoAmI()
	{
		cout << "I am a teacher  " <<endl;
	    cout<<Id<<"\n";
		cout<<name<<"\n";
		cout<<coursename;  
		cout<<"please enter the age:\n";
		cin>>age;
	}
};
class Group
{
private:
	static int NoOfPerson;
	static int Max;
	Person **Member;
public:
	Group ()
	{
	  Member = new Person * [Max];
	}
	void Accept(Person *APerson)
	{
		if (NoOfPerson == Max)
		{
			cout <<"the group is full"<<endl;
			return;
		}
		Member[NoOfPerson] = APerson;
		NoOfPerson =NoOfPerson + 1;
    }
	void Print()
	{
		int i;
        cout << "the group members are  "<<endl;
		for (i = 0; i<NoOfPerson; i++)
		{     	
			Member[i]->WhoAmI();
        }
	}
	void remove(Person *aperson)   //remove a person from group
   {
	 int i=0,temp,change=0;   
	 if (NoOfPerson == 0)
	 {
		cout <<"the group is empty"<<endl;
		return;
	 }
	 for(i=0;i<NoOfPerson;i++)	   //find the person 
	 {
		if(Member[i]==aperson)
	   {
		 printf("%d",i);
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
	if(NoOfPerson!=1)
    {
      for (i = temp; i <NoOfPerson-1; i++)  //adjust the member array
	 {
	   Member[i]=Member[i+1];	
	 }	  	
	}
	Member[NoOfPerson-1]=NULL;		
	NoOfPerson--;
   }
   float average()   //return average age
   {
     int i;
	 float sum=0;
     for(i=0;i<NoOfPerson;i++)	  
     {
       sum+=Member[i]->getage();
	 }
	 float ans=sum/NoOfPerson;
	 return ans;
   }
};
Group Groupp;
int Group::NoOfPerson =0;
int Group::Max =20;
int main()
{
	
	//Student S1(1), S2(2), S3(3), S4(4), S5(5),S6(6);
	//Teacher T1(1), T2(2), T3(3), T4(4), T5(5);
	//Groupp.Print();
	//cout<<"average age:"<<fixed<<setprecision(3)<<Groupp.average()<<endl;
	//cout<<"remove s1"<<"\n";
    //Groupp.remove(&S1);
    //Groupp.remove(&T1);
	//Groupp.remove(&T3);
    //Groupp.remove(&S5);
	//cout<<"average age:"<<fixed<<setprecision(3)<<Groupp.average()<<endl;
	//Groupp.Print();
	int c;
	while(1)
	{
      cout<<"input the instruction:";
      cin>>c;
	  if(c==0)
	  {
		 cout<<"end";
		 break; 
	  }
	  getinstruction(c);
	}
}
void getinstruction(int k)
{
   switch (k)
   case '1':
   Teacher T1(countid);
   Groupp.Accept(&T1);  
   countid++;
   break;
   case '2';
   
}
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
}
void f4(student s[],int count)   //print all
{
   int i;
   for(i=0;i<count;i++)
   {
     f3(&s[i]);   
   }
}
void genRandomString(int length, char* ouput)
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
