#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
struct man {
	string name;
	int age;
	int phonenumber;
};
class Person 
{
	protected:
		int Id;
		int age;
		string address;
		int PhoneNo;
	public:
		Person()//constructor
		{
		}
		Person(int id)//constructor
		{
			Id = id;
			age	= 6 + rand() % 10;
			PhoneNo = rand() % 1000000;
		}
		void PrintPhoneNo()
		{
			cout << "Id:  " << Id << "    PhoneNo:   " << PhoneNo << endl;
		}
		virtual void WhoAmI() = 0;
};
class Student :public Person
{
	private:
		int Grade;
	public:
		Student(int sid) : Person(sid)
		{

		}
		Student(int sid, int grade) :Person(sid)
		{
			Grade = grade;
		}
		void PrintGrade()
		{
			cout << "Id:  " << Id << "    Grade:  " << Grade << endl;
		}
		virtual void WhoAmI()
		{
			cout << "I am a student   " << Id << endl;
		}
};
class Teacher :public Person
{
	private:
		int Salary;
	public:
		Teacher(int sid) :Person(sid)
		{
		}
		Teacher(int sid, int salary) :Person(sid)
		{
			Salary = salary;
		}
		void PrintSalary()
		{
			cout << "Id:  " << Id << "    Salary:   " << Salary << endl;
		}
		virtual void WhoAmI()
		{
			cout << "I am a teacher   " << Id << ", and my age is " << age << endl;
		}

};
class Group
{
	private:
		Person** Member;
		//1個* = pointer 只要是pointer可以當array使用
		//2個* = array, array中的每一個變數都是pointer可以分別指向不同person
	public:
		static int acceptedPerson;
		static int removedPerson;//static是靜態資料成員，屬於類別所擁有，而不是個別物件
		static int Max;
		Group()
		{
			Member = new Person * [Max];
		}
		void Accept(Person* APerson)//接收pointer
		{
			if (acceptedPerson == Max)
			{
				cout << "The group is full." << endl;
				return;
			}
			Member[acceptedPerson] = APerson;
			acceptedPerson++;
		}
		void Remove(Person* APerson)
		{
			
			Member[acceptedPerson] = APerson;
			acceptedPerson--;
		}
		void Print()
		{
			cout << "the group member are   " << endl;
			for (int i = 0; i < acceptedPerson; i++)
			{
				Member[i]->WhoAmI();
				Member[i]->PrintPhoneNo();
			}
		}
};
int Group::acceptedPerson = 0;
int Group::Max = 20;
int main()
{
	Group Groupp;
	Student S1(1,123), S2(2), S3(3,3), S6(6);//初始化  S6不給參數 
	Teacher T1(1), T2(2), T3(3);
	//S6.name = "chen"; <--error
	//因為在class person中宣告的是private，外面沒辦法用   如果要做要在student的Class中public做一個function->changAge(int ID; int age1){if(password()) else cout<<"Fail"<<endl; Age=age1;}
												 //protected繼承後可以用
	Groupp.Accept(&S1);
	Groupp.Accept(&T3);
	Groupp.Accept(&S2);
	Groupp.Accept(&S3);
	Groupp.Remove(&S1);
	Groupp.Print();
	//HW3-1程式要可以跑
	//HW3-2加入remove
	//HW3-3print age average
	system("pause");
	return 0;
}