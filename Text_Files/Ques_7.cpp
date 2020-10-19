#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Poem
{
	int line_count,word_count,lower,upper,word_size,tot_size;
	float avg_size;
	
	public:
	Poem()
	{
		line_count=word_count=tot_size=lower=upper=word_size=0;
		avg_size=0.0;
	}
	
	void get_poem()
	{
		char str[80];
		fstream file;
		file.open("POEM.txt",ios::out);
		
		if(!file) cerr<<"Error while opening 'POEM.txt' !\n";
		
		else
		{
			cout<<"\n\n\t\t - POEM -x- ANALYSIS -\n\n\nWrite your 'Poem' below :\n\n";
			do{
				cin.getline(str,80);
				if(strlen(str)==0) continue;
				file<<str<<"\n";
			}while(strlen(str)!=0);
			cout<<"Poem stored in 'POEM.txt' successfully !\n";
		}
	}
	
	void line_ops()
	{
		fstream file;
		file.open("POEM.txt",ios::in);
		string line;
		int count_1=0,count_2=0;
		
		while(!file.eof())
		{	
			getline(file,line);
			if(line[0]=='S')
				count_1++;
			if(line[0]=='M')
				count_2++;
			line_count++;
		}
		line_count--;
		cout<<"\n\n\t --- LINES --- \n\n\nTotal no.of lines : "<<line_count;
		cout<<"\nNo.of Lines starting with 'S' : "<<count_1;
		cout<<"\nNo.of Lines starting with 'M' : "<<count_2<<endl;
		file.close();
	}
	
	void word_ops()
	{
		fstream file;
		file.open("POEM.txt",ios::in);
		char ch[20];
		
		cout<<"\n\n\t --- WORDS --- \n\n\n";
		while(!file.eof())
		{
			file>>ch;
			if( strcmp(ch,".")==0 || strcmp(ch,",")==0 || strcmp(ch,"!")==0 || strcmp(ch,";")==0 || file.eof() ) continue;
			word_size=strlen(ch);
			cout<<ch<<" - "<<word_size<<endl;
			tot_size+=word_size;
			word_count++;
		}
		avg_size=(float)tot_size/word_count;
		cout<<"\nTotal no.of words : "<<word_count;
		cout<<"\nAverage Word Length : "<<avg_size<<endl;
		file.close();
	}
	
	void letter_ops()
	{
		fstream file;
		file.open("POEM.txt",ios::in);
		char ch;
		
		while(!file.eof())
		{
			file>>ch;
			if(ch >='a' && ch<='z')
				lower++;
			else if(ch>='A' && ch<='Z')
				upper++;
		}
		cout<<"\n\n\t --- LETTERS --- \n\n";
		cout<<"\nNo.of LowerCase Letters : "<<lower;
		cout<<"\nNo.of UpperCase Letters : "<<upper<<endl;
		file.close();
	}
};

int main()
{
	Poem p1;
	p1.get_poem();
	cout<<"\n\nThe ANALYSIS :\n";
	p1.line_ops();
	p1.word_ops();
	p1.letter_ops();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 21.04.2020, 08:53:38 P.M.
