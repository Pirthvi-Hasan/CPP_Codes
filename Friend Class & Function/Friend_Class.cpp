#include<iostream>
using namespace std;

class Employee	{
	static int Basic_Salary;
	friend class Teacher;
};
class Teacher	{
	char name[30],dept[40];
	int salary;
	public:
	void get_data()	{
		cout<<"\nEnter Your Name : ";
		gets(name);
		cout<<"\nEnter your Department : ";
		gets(dept);
		salary=Employee::Basic_Salary+25000;    // Every object of this class can access private members of Employee class....
	}
	void display()	{
		cout<<"\nDETAILS :-\n\nTeacher Name   : "<<name<<"\nTeacher Dept.  : "<<dept<<"\nTeacher Salary : "<<salary<<endl;
	}
};
int Employee::Basic_Salary=15000;

int main()	{
	Teacher t1;
	t1.get_data();
	t1.display();
	return 0;
}
