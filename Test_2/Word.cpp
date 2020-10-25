#include<iostream>
#include<string.h>
using namespace std;

class Word
{
	char word[50];
	
	public:
	int operator ==(Word &obj)	{
		int l1=strlen(word),l2=strlen(obj.word),i;
		if(l1!=l2) return 0;
		else	{
			for(i=0;i<l1;i++)	{
				if(word[i]!=obj.word[i])	{
					return 0;
		}   }   }
		return 1;
	}
	int operator !=(Word &obj)	{
		int l1=strlen(word),l2=strlen(obj.word),i;
		
		if(l1!=l2) return 1;
		else	{
			for(i=0;i<l1;i++)	{
				if(word[i]!=obj.word[i])	{
					return 1;
		}   }   }
		return 0;
	}
	int operator >(Word &obj)	{
		if(word[0] > obj.word[0]) return 1;
		else return 0;
	}
	int operator <(Word &obj)	{
		if(word[0] < obj.word[0]) return 1;
		else return 0;
	}
	int operator >=(Word &obj)	{
		if(word[0] < obj.word[0]) return 0;
		else return 1;
		}
	int operator <=(Word &obj)	{
		if(word[0] > obj.word[0]) return 0;
		else return 1;
	}
	
	int length()	{
		int l=0;
		while(word[l]!='\0') l++;
		return l;
	}
	void concat(char *temp)	{
		int i=this->length(),j=0;
		while(temp[j]!='\0')	word[i++] = temp[j++];
		word[i]='\0';
	}
	void copy(char *temp)	{
		int l=strlen(temp),i;
		for(i=0;i<l;i++) word[i]=temp[i];
		word[i]='\0';
	}
	void reverse()	{
		int l=this->length(),i=0,j=0;
		char temp[50];
		for(i=l-1;i>=0;i--,j++)	temp[j]=word[i];
		temp[j]='\0';
		this->copy(temp);
	}
	void lower()	{
		int i;
		for(i=0;i<length();i++)	{
			if(word[i]>=65 && word[i]<=90) word[i]+=32;
		}
	}
	void upper()	{
		int i;
		for(i=0;i<length();i++)	{
			if(word[i]>=97 && word[i]<=122) word[i]-=32;
		}
	}
	
	void getdata()	{
		cout<<"Enter a string : ";
		cin>>word;
	}
	void print()	{
		cout<<"\nString Value   : "<<word;
	}	
};

int main()
{
	Word w1,w2;
	w1.getdata();
	w2.getdata();
	if(w1==w2) cout<<"\nw1 == w2 !\n";
	if(w1!=w2) cout<<"\nw1 != w2 !\n";
	if(w1>=w2) cout<<"\nw1 >= w2 !\n";
	if(w1<=w2) cout<<"\nw1 <= w2 !\n";
	if(w1>w2) cout<<"\nw1 > w2 !\n";
	if(w1<w2) cout<<"\nw1 < w2 !\n";
	
	cout<<"\nLength of String :- "<<w1.length()<<endl;       // String Length
	
	cout<<"\nConcated String :-";
	char temp[]="Sample";                                    // String CONCATENATION
	w1.concat(temp);
	w1.print();
	
	cout<<"\n\nCopied String :-";
	w1.copy(temp);                                           // String COPY
	w1.print();
	
	cout<<"\n\nReversed String :-";
	w1.reverse();                                            // String Reverse
	w1.print();
	
	cout<<"\n\nLower_Case String :-";
	w1.lower();                                              // String Lower_Case Conversion
	w1.print();
	
	cout<<"\n\nUpper_Case String :-";
	w1.upper();                                              // String Upper_Case Conversion
	w1.print();
	return 0;
}
