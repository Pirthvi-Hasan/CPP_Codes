#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Story
{
	int word_count;
	char ch[20];
	
	public:
	
	Story()
	{
		word_count=0;
	}
	
	void count()
	{
		fstream file;
		file.open("story.txt",ios::in);
		
		while(!file.eof())
		{
			file>>ch;
			if(strcmp(ch,"the")==0)
			word_count++;
		}
		
		cout<<"\nThe word 'the' occured in file 'story.txt' -> "<<word_count<<" times .\n";
		file.close();
	}
};

int main()
{
	Story s1;
	s1.count();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 12.04.2020, 11:43:38 A.M.
