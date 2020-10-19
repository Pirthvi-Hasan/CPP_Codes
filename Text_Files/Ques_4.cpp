#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Article{
	
	int word1_count,word2_count;
	char ch[20];
	
	public:
	Article(){
		word1_count=0;
		word2_count=0;
	}
	
	void count(){
		fstream file;
		file.open("article.txt",ios::in);
		while(!file.eof())
		{
			file>>ch;
			if(strcmp(ch,"this")==0)
			word1_count++;
			else if(strcmp(ch,"these")==0)
			word2_count++;
		}
		cout<<"QUESTION - 4\n\nThe words 'this' occured in file 'article.txt' -> "<<word1_count<<" times .\n";
		cout<<"\nThe word 'these' occured in file 'article.txt' -> "<<word2_count<<" times .\n";
		file.close();
	}
};

int main()
{
	Article artc;
	artc.count();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 12.04.2020, 4:10:34 P.M.
