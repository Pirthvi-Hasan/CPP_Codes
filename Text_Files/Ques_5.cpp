#include<iostream>
#include<fstream>
using namespace std;

class Replace
{
	char ch;
	int space_count;
	
	public:
		Replace()
		{
			space_count=0;
		}
		
		void replace()
		{
			fstream rfile,wfile;
			rfile.open("read_5.txt",ios::in);
			wfile.open("write_5.txt",ios::out);
			
			if(!rfile || !wfile)
				cout<<"Error on opening files !\n";
			else
			{
				cout<<"\nFiles opened Successfully !"<<endl;
				while(!rfile.eof())
				{
					ch=rfile.get();
					if(ch==' ')
					{
						space_count++;
						if(space_count==1)  wfile<<' ';				
					}
					
					else if(rfile.eof())
					continue;
					
					else
					{
						wfile<<ch;
						space_count=0;
					}
				}
				cout<<"\nContents written to 'write_5.txt' successfully !"<<endl;
				rfile.close(),wfile.close();
			}
		}
};

int main()
{
	Replace r1;
	r1.replace();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 13.04.2020, 08:29:52 A.M.
