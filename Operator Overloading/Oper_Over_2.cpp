#include<iostream>
#include<string.h>
using namespace std;

class String
{
	char str[50];
	
	public:
	String operator +(String &obj)	{
		String s;
		char sen[25];
		strcpy(sen,str);
		strcat(sen,obj.str);
		strcpy(s.str,sen);
		return s;
	}
	int operator ==(String &obj)	{
		String s;
		int l1=strlen(str),l2=strlen(obj.str),i,flag=1;
		
		if(l1!=l2) flag=0;
		else	{
			for(i=0;i<l1;i++)	{
				if(str[i]!=obj.str[i])	{
					flag=0;
					return flag;
		}   }   }
		return flag;
	}
	int operator >=(String &obj)	{
		if(str[0] < obj.str[0]) return 0;
		else return 1;
		}
	int operator <=(String &obj)	{
		if(str[0] > obj.str[0]) return 0;
		else return 1;
	}
	
	void getdata()	{
		cout<<"Enter a string : ";
		cin>>str;
	}
	void print()	{
		cout<<"\nString Value   : "<<str;
	}	
};

int main()
{
	String s1,s2;
	s1.getdata();
	s2.getdata();
	if(s1==s2) cout<<"\ns1 == s2 !\n";
	if(s1>=s2) cout<<"\ns1 >= s2 !\n";
	if(s1<=s2) cout<<"\ns1 <= s2 !\n";
	String s3 = s1 + s2;
	s3.print();
	return 0;
}
