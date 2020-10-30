#include<iostream>
#include<string.h>
using namespace std;

void count_letter(char &ch,int &con,int &vow)	{
	try {
		if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))	{
			if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U') vow+=1;
			else con+=1;
		}
		else throw(ch);
	}
	catch(char c)	{
		cout<<"\nNon-Alphabet Character - '"<<c<<"' found !";
	}
}

main()	{
	char str[75];
	int con=0,vow=0;
	cout<<"\nEnter a Sentence : ";
	scanf(" %[^\n]s",str);
	for(int i=0;i<strlen(str);i++)	{
		count_letter(str[i],con,vow);
	}
	cout<<"\n\nRESULT :-\n\nVOWELS     : "<<vow<<"\nCONSONANTS : "<<con<<"\n";
}
