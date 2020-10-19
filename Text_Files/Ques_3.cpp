#include<iostream>
#include<fstream>
using namespace std;

class Book {
	int alph_count;
	char ch;
	
	public:
	
	Book() {
		alph_count=0;
	}
	
	void lower_alph()  {
		fstream file;
		file.open("book.txt",ios::in);
		
		if(!file)
		cout<<"File not found !\n";
		
		else  {
			while(!file.eof())  {
				file>>ch;
				
				if(ch>='a' && ch<='z')
				alph_count++;
			}
			cout<<"QUESTION - 3\n\nThe no.of Lower_Case alphabets in 'book.txt' : "<<alph_count<<endl;
			file.close();
		}
	}
};

int main()
{	
	Book b1;
	b1.lower_alph();
	return 0;
}

//This code is created by Pirthvi Hasan.G on 12.04.2020, 12:25:44 P.M.
