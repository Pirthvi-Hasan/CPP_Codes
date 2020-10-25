#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

typedef struct 
{
	char name[30],addr[50],area_code[10],ph_no[15];
}Data;

class Record
{
	public:
	void add_rec();
	void transfer();
	void disp_rec();
};

void Record::add_rec()
{
	int n,i;
	fstream file;
	file.open("PHONE.dat",ios::app | ios::binary);
	cout<<"\nEnter no.of Records to add : ";
	cin>>n;
	for(i=0;i<n;i++)	{
		Data temp;
		cout<<"\nRECORD - "<<i+1<<"\n\nEnter Person Name    : ";
		scanf("%*c %[^\n]s",temp.name);
		cout<<"Enter your Address   : ";
		scanf("%*c %[^\n]s",temp.addr);
		cout<<"Enter Area Code      : ";
		scanf("%*c %[^\n]s",temp.area_code);
		cout<<"Enter Phone Num.     : ";
		scanf("%*c %[^\n]s",temp.ph_no);
		file.write((char*) &temp,sizeof(temp));
	}
	file.close();
}

void Record::transfer()
{
	Data temp;
	fstream oldf,newf;
	
	oldf.open("PHONE.dat",ios::in | ios::binary);
	newf.open("PHONBACK.dat",ios::out | ios::binary);
	while(!oldf.eof()) {
		if( oldf.read((char *) &temp,sizeof(temp)) )  {
			if(oldf.eof()) break;
			if(strcmp("DEL",strupr(temp.area_code))==0)  {
				newf.write((char*) &temp,sizeof(temp));
			}
		}
	}
	oldf.close();
	newf.close();
}

void Record::disp_rec()
{
	Data temp;
	fstream file;
	int count=0;
	file.open("PHONBACK.dat",ios::in | ios::binary);
	cout<<"\n\nRecords in the file 'PHONBACK.dat' :-\n";
	do{
		file.read((char *) &temp,sizeof(temp));
		if(file.eof()) break;
		++count;
		cout<<"\n - RECORD - "<<count<<" :-\n\n";
		cout<<"Name           : "<<temp.name<<"\nPostal Address : "<<temp.addr<<"\nArea Code      : "<<temp.area_code<<"\nPhone Number   : "<<temp.ph_no<<"\n\n";
	}while(!file.eof());
	if(count==0)
		cout<<"\nNo Records stored Yet :( !\n";
	file.close();
}

int main()
{
	Record rec;
	rec.add_rec();
	rec.transfer();
	rec.disp_rec();
	return 0;
}
