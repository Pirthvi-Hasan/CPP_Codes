#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

class File
{
	int count;
	char *ch;
	public:
	
	void reverse()
	{
		fstream rfile,wfile;
		rfile.open("read_6.txt",ios::in);
		wfile.open("write_6.txt",ios::out);
		
		if(!rfile || !wfile)
			cout<<"\nSome error occured while opening files !\n";
		else
		{
			int i=-1;
			ch=(char*)malloc(1);
			cout<<"\nFiles opened Successfully !"<<endl;
			while(!rfile.eof())
			{
				ch[++i]=rfile.get();
			}
			ch[i]='\0';
			
			while(i>-1)
			{
				wfile<<ch[i--];
			}
			cout<<"\nContents written to 'write_6.txt' successfully !"<<endl;
		}
	}
};

int main()
{
	File f1;
	f1.reverse();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 13.04.2020, 11:06:42 A.M.
