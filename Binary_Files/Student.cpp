#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student
{
	char adm_no[10],name[30];
	int perc;
	public:
	void enter_data();
	void display_data();
	
	void write_file();
	void read_file();
	void disp_higher();
};

void Student::enter_data()
{
	cout<<"\n - STUDENT -\n\nEnter Student's Name    : ";
	gets(this->name);
	cout<<"Enter Admission Number  : ";
	gets(this->adm_no);
	cout<<"Enter % of Marks scored : ";
	cin>>this->perc;
}

void Student::display_data()
{
	cout<<"\n - STUDENT DATA - \n\n";
	cout<<"Name       : "<<this->name<<"\nAdmn.Num   : "<<this->adm_no<<"\n% of Marks  : "<<this->perc<<" %\n\n";
}

void Student::write_file()
{
	fstream file;
	file.open("Student.dat",ios::app);
	Student temp;
	strcpy(temp.adm_no,this->adm_no);
	strcpy(temp.name,this->name);
	temp.perc = this->perc;
	file.write((char *) &temp,sizeof(temp));
	file.close();
}

void Student::read_file()
{
	fstream file;
	Student temp;
	int rec_count;
	file.open("Student.dat",ios::in);
	do{
		file.read((char *) &temp,sizeof(temp));
		if(file.eof()) break;
		rec_count++;
		cout<<"\n RECORD - "<<rec_count<<"\n\n";
		cout<<"Name       : "<<temp.name<<"\nAdmn.Num   : "<<temp.adm_no<<"\n% of Marks : "<<temp.perc<<" %\n\n";
	}while(!file.eof());
	cout<<"Total No.of Records : "<<rec_count<<endl;
	file.close();
}

void Student::disp_higher()
{
	Student temp;
	fstream file;
	int count=0;
	file.open("Student.dat",ios::in);
	cout<<"\n\nStudents above 75 % Scores :-\n\n";
	do{
		file.read((char *) &temp,sizeof(temp));
		if(file.eof()) break;
		if(temp.perc>=75)
		{
			++count;
			cout<<"\n STUDENT - "<<count<<"\n\n";
			cout<<"Name       : "<<temp.name<<"\nAdmn.Num   : "<<temp.adm_no<<"\n% of Marks : "<<temp.perc<<" %\n\n";
		}
		if(count==0)
			cout<<"\nNo one Scored above 75 % :( !\n";
	}while(!file.eof());
	file.close();
}

int main()
{
	Student s1;
	s1.enter_data();
	s1.display_data();
	cout<<"\n\t- - - FILE CONTENT - - -\n\n";
	s1.write_file();
	s1.read_file();
	s1.disp_higher();
	return 0;
}

// This code is created by Pirthvi Hasan.G , 1932030 on Theni , 27.04.2020.
