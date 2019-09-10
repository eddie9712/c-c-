#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
using namespace std;
class Person
{
protected:
	int Id;
	int age;
	string address;
	int PhoneNo;
public:
	Person()
	{
	}
	Person(int id)
	{
		Id =id;
		age = 6+ rand()% 10;
		PhoneNo = rand()%1000000;
	}
	void PrintPhoneNo()
	{
		cout << "Id:" << Id << "   PhoneNo:  " << PhoneNo <<" age: "<< age <<endl;  
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
	int Salary;
public:
	Teacher(int sid): Person(sid)
	{
	}
	
	Teacher(int sid, int salary): Person(sid)
	{
		Salary = salary;
	}

	void PrintSalary()
    {
		cout << "Id:" << Id << "   Salary  " << Salary <<endl;  
	}
virtual void WhoAmI()
	{
		cout << "I am a teacher  " << Id <<endl;
	    PrintSalary();  
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
			Member[i]->PrintPhoneNo();
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
int Group::NoOfPerson =0;
int Group::Max =20;
int main()
{
	
	Group Groupp;
	Student S1(1), S2(2), S3(3), S4(4), S5(5),S6(6);
	Teacher T1(1), T2(2), T3(3), T4(4), T5(5);

	Groupp.Accept(&S1);
	Groupp.Accept(&S2);
	Groupp.Accept(&S3);
	Groupp.Accept(&T1);
	Groupp.Accept(&T3);
	Groupp.Accept(&S6);
	Groupp.Print();
	cout<<"average age:"<<fixed<<setprecision(3)<<Groupp.average()<<endl;
	cout<<"remove s1"<<"\n";
    Groupp.remove(&S1);
    Groupp.remove(&T1);
	Groupp.remove(&T3);
    Groupp.remove(&S5);
	cout<<"average age:"<<fixed<<setprecision(3)<<Groupp.average()<<endl;
	Groupp.Print();
	system("pause");
	return 0;
}


