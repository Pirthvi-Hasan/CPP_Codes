#include<iostream>
#include<conio.h>
using namespace std;

class Publication	{
	protected:
	int price;
	char title[40];
	virtual void  get_data() =0;
	virtual void disp_data() =0;
};

class Book : private Publication	{
	int pg_count;
	public:
	void get_data()	{
		cout<<"\n\nEnter Title : ";
		scanf(" %[^\n]s",title);
		cout<<"\nEnter Price : ";
		cin>>price;
		cout<<"\nNo.of Pages : ";
		cin>>pg_count;
	}
	void disp_data()	{
		cout<<"\nBook  Title : "<<title<<"\nBook  Price : "<<price<<"\nNo.of Pages : "<<pg_count;
	}
	int get_pg()	{
		return pg_count;
	}
};

class Tape : private Publication	{
	int play_time;
	public:
	void get_data()	{
		cout<<"\n\nEnter Title     : ";
		scanf(" %[^\n]s",title);
		cout<<"\nEnter Price     : ";
		cin>>price;
		cout<<"\nEnter Play_Time (in min) : ";
		cin>>play_time;
	}
	void disp_data()	{
		cout<<"\nAudio Tape Title   : "<<title<<"\nAudio Tape Price   : "<<price<<"\nPlay_Time (in min) : "<<play_time;
	}
	int get_time()	{
		return play_time;
	}
};

main()	{
	char opt,wait;
	int b,t,n,i;
	cout<<"\nEnter no.of Books : ";
	cin>>b;
	cout<<"\nEnter no.of Tapes : ";
	cin>>t;
	Book B[b];
	Tape T[t];
	do{
		system("cls");
		cout<<"\n1.Enter Data\n2.Display All Books\n3.Display All Tapes\n4.Books with atleast 'n' Pages\n5.Tapes with 'n' mins. of Play_Time\n6.Exit\n\nEnter your Option : ";
		opt=getche();
		switch(opt)	{
			case '1':
				cout<<"\n\nEnter Details :-";
				for(i=0;i<b;i++)	{
					cout<<"\n\nBOOK - "<<i+1<<" :";
					B[i].get_data();
				}
				for(i=0;i<t;i++)	{
					cout<<"\n\nTAPE - "<<i+1<<" :";
					T[i].get_data();
				}
				break;
			case '2':
				for(i=0;i<b;i++)	{
					cout<<"\n\nBOOK -"<<i+1<<" :";
					B[i].disp_data();
				}
				break;
			case '3':
				for(i=0;i<t;i++)	{
					cout<<"\n\nTAPE -"<<i+1<<" :";
					T[i].disp_data();
				}
				break;
			case '4':
				cout<<"\n\nEnter minimum no.of Pages : ";
				cin>>n;
				cout<<"\nBOOKS having above "<<n<<" Pages :-";
				 for(i=0;i<b;i++)	{
					if(B[i].get_pg()>n)	{
						cout<<"\n\nBOOK -"<<i+1<<" :";
						B[i].disp_data();
					}
				}
				break;
			case '5':
				cout<<"\n\nEnter minimum Play_Time(in mins) : ";
				cin>>n;
				cout<<"\nTAPES with Play_Time of alteast "<<n<<" mins :-";
				for(i=0;i<t;i++)	{
					if(T[i].get_time()>=n)	{
						cout<<"\n\nTAPE -"<<i+1<<" :";
						T[i].disp_data();
					}
				}
				break;
			case '6':
				cout<<"\n\nGoodBye ! Have a Nice Day !\n";
				exit(0);
			default:
				cout<<"\n\nEnter a Valid Option !\n";
		}
		cout<<"\n\nPress Any Key to Continue....";
		wait=getche();
	}while(opt!='6');
}
