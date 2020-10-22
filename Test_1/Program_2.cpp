#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class Prog2
{
	int sum;
	public:
	Prog2()
	{
		sum=0;
	}
	void calc_sum()
	{
		int num;
		char ch[15];
		fstream file;
		file.open("sample.txt",ios::in);
		while(!file.eof())
		{
			file>>ch;
			if(ch[0]>='0' && ch[0]<='9')
			{
				num=atoi(ch);
				if(num>0)
					this->sum+=num;
			}
			
		}
		cout<<"\nRESULT :-\n\nSum of all positive integers in 'sample.txt' : "<<sum<<endl;
		file.close();
	}
};

int main()
{
	Prog2 p2;
	cout<<"\n\tCAT - Question - 2\n\n";
	p2.calc_sum();
	return 0;
}
//Created by Pirthvi Hasan.G on 05.05.2020 for OOPs CAT-1
