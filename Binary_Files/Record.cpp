#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

class Data
{
	public:
	char name[30],numb[15];
};

class Record
{
	public:
	void add_rec();
	void find_num();
	void find_name();
	void upd_num();
	void disp_rec();
	void del_rec();
};

void Record::add_rec()
{
	Data temp;
	fstream file;
	file.open("Record.dat",ios::app | ios::binary);
	
	cout<<"\n\nEnter Person Name    : ";
	gets(temp.name);
	printf("Enter Telephone Num. : ");
	gets(temp.numb);
	
	file.write((char*) &temp,sizeof(temp));
	file.close();
}

void Record::find_num()
{
	Data temp;
	fstream file;
	int count=0;
	char name[30];
	file.open("Record.dat",ios::in | ios::binary);
	cout<<"\n\nEnter Name to find Telephone Num. : ";
	gets(name);
	do{
		file.read((char *) &temp,sizeof(temp));
		if(file.eof()) break;
		++count;
		if(strcmp(name,temp.name)==0)
		{
			cout<<"\nName           : "<<temp.name<<"\nTelephone Num. : "<<temp.numb<<"\n\n";
			break;
		}
	}while(!file.eof());
	if(count==0 || file.eof())
		cout<<"\nNo Records found :( !\nTry entering correct name.\n";
	file.close();
}

void Record::find_name()
{
	Data temp;
	fstream file;
	int count=0;
	char numb[30];
	file.open("Record.dat",ios::in | ios::binary);
	cout<<"\n\nEnter Number to find Person's Name : ";
	gets(numb);
	do{
		file.read((char *) &temp,sizeof(temp));
		if(file.eof()) break;
		++count;
		if(strcmp(numb,temp.numb)==0)
		{
			cout<<"\nName           : "<<temp.name<<"\nTelephone Num. : "<<temp.numb<<"\n\n";
			break;
		}
	}while(!file.eof());
	if(count==0 || file.eof())
		cout<<"\nNo Records found :( !\nTry entering exact Number.\n";
	file.close();
}

void Record::upd_num()
{
	Data temp;
	fstream oldf,newf;
	int flag=0;
	char key[30],key_num[15];
	oldf.open("Record.dat",ios::in | ios::binary);
	newf.open("temp.dat",ios::out | ios::binary);
	cout<<"\n\nEnter Person name to update number : ";
	gets(key);
	while(!oldf.eof()) {
		if( oldf.read((char *) &temp,sizeof(temp)) )  {
			if(oldf.eof()) break;
			if(strcmp(key,temp.name)==0 || strcmp(key,temp.numb)==0)  {
				flag=1;
				cout<<"\nOld Data :-\n\nName           : "<<temp.name<<"\nTelephone Num. : "<<temp.numb<<"\n";
				cout<<"\nEnter New number : ";
				cin>>key_num;
				strcpy(temp.numb,key_num);
			}
				newf.write((char*) &temp,sizeof(temp));
		}
	}
	if(!flag)
		cout<<"\nNo Records match current info :( !\n";
	oldf.close();
	newf.close();
	remove("Record.dat");
	rename("temp.dat","Record.dat");
	if(flag) this->disp_rec();
}

void Record::disp_rec()
{
	Data temp;
	fstream file;
	int count=0;
	file.open("Record.dat",ios::in | ios::binary);
	cout<<"\n\nRecords in the file 'Record.dat' :-\n";
	do{
		file.read((char *) &temp,sizeof(temp));
		if(file.eof()) break;
		++count;
		cout<<"\n - RECORD "<<count<<" -\n\n";
		cout<<"Name           : "<<temp.name<<"\nTelephone Num. : "<<temp.numb<<"\n\n";
	}while(!file.eof());
	if(count==0)
		cout<<"\nNo Records stored Yet :( !\n";
	file.close();
}

void Record::del_rec()
{
	Data temp;
	fstream oldf,newf;
	int flag=0;
	char key[30];
	oldf.open("Record.dat",ios::in | ios::binary);
	newf.open("temp.dat",ios::out | ios::binary);
	cout<<"\n\nEnter Number / Name to delete Record : ";
	gets(key);
	while(!oldf.eof()) {
		if( oldf.read((char *) &temp,sizeof(temp)) )  {
			if(oldf.eof()) break;
			if(strcmp(key,temp.name)==0 || strcmp(key,temp.numb)==0)  {
				flag=1;
				cout<<"\nDeleted content :-\n";
				cout<<"\nName           : "<<temp.name<<"\nTelephone Num. : "<<temp.numb<<"\n\n";
			}
			else {
				newf.write((char*) &temp,sizeof(temp));
			}
		}
	}
	if(!flag)
		cout<<"\nNo Records found with current info :( !\n";
	oldf.close();
	newf.close();
	remove("Record.dat");
	rename("temp.dat","Record.dat");
	if(flag) this->disp_rec();
}

int main()
{
	Record rec;
	char opt,skip;
	do{
		system("cls");
		cout<<"\n\tFile handling - Set 2\n\n1.Add new Record\n2.Find Telephone Number\n3.Find Name of Person\n4.Update Telephone Number\n5.Display all Records\n6.Delete a Record\n7.Exit\n\nEnter your option : ";
		opt=getche();
		switch(opt)
		{
			case '1':
				rec.add_rec();
				break;
			case '2':
				rec.find_num();
				break;
			case '3':
				rec.find_name();
				break;
			case '4':
				rec.upd_num();
				break;
			case '5':
				rec.disp_rec();
				break;
			case '6':
				rec.del_rec();
				break;
			case '7':
				cout<<"\n\nGoodBye ! Have a Nice Day !\n";
				exit(0);
			default:
				cout<<"\n\nEnter a Valid Option !\n";
		}
		cout<<"\nPress Any Key to Continue ....";
		skip=getche();
	}while(opt!='7');
	return 0;
}
