#include<iostream>
#include<fstream>
using namespace std;

class Lines{
	int line_count;
	string line;
	
	public:
	Lines()
	{
		line_count=0;
	}
	
	void count()
	{
		fstream file;
		file.open("lines.txt",ios::in);
		
		if(!file)
		cout<<"No such file !\n";
		else
		{
			cout<<"\nLines starting with letter 'a' :-\n\n";
			while(!file.eof())
			{	
				getline(file,line);
				if(line[0]=='a')
				{
					line_count++;
					cout<<line_count<<". "<<line<<endl;
				}
			}
			cout<<"\nNo.of Lines starting with 'a' : "<<line_count<<endl;
			file.close();
		}
	}
};

int main()
{
	Lines l;
	l.count();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 12.04.2020, 11:34:26 A.M.
