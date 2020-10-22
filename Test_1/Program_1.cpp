#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Machine
{
	string products[4];
	int prices[4];
	public:
	Machine(string s1,string s2,string s3,string s4)
	{
		products[0]=s1,products[1]=s2,products[2]=s3,products[3]=s4;
		prices[0]=10,prices[1]=20,prices[2]=5,prices[3]=40;
	}
	void disp_prod()
	{
		int i;
		cout<<"\n\nPRODUCTS :-\n\n";
		for(i=0;i<4;i++)
		{
			cout<<i+1<<"."<<products[i]<<"\n";
		}
	}
	void buy_prod()
	{
		int opt,amt,rem,qty;
		do{
		cout<<"\n\n1.Candies\n2.Chips\n3.Gums\n4.Cookies\n\nEnter option to Buy : ";
		cin>>opt;
		cout<<"\n"<<products[opt-1]<<"\t- Rs."<<prices[opt-1]<<"\n\n";
		cout<<"Enter amount to buy product : ";
		cin>>amt;
		if(amt<prices[opt-1])
			cout<<"\nInsufficient Amount !\n\n";
		else
		{
			rem=amt%prices[opt-1];
			qty=amt/prices[opt-1];
			cout<<"\nHere ! Collect your "<<qty<<" "<<products[opt-1]<<" packets !\n\n";
			cout<<"Also collect Rs."<<rem<<" balance amount!\n";
		}
	}while(amt<prices[opt-1]);
}
};

int main()
{
	Machine m1("Candies","Chips","Gums","Cookies");
	char opt,skip;
	do {
		system("cls");
		cout<<"\n\tCAT - Question - 1\n\nWelcome to Vending machine !\n\n1.Show Products List\n2.Buy Product\n3.Exit\n\nEnter your option : ";
		opt=getche();
		switch(opt)  {
			case '1':
				m1.disp_prod();
				break;
			case '2':
				m1.buy_prod();
				break;
			case '3':
				cout<<"\n\nGoodBye ! Have a Nice Day !\n";
				exit(0);
			default:
				cout<<"\n\nEnter a Valid Option !\n";
		}
		cout<<"\nPress Any Key to Continue ....";
		skip=getche();
	}while(opt!='3');
	return 0;
}
//Created by Pirthvi Hasan.G on 05.05.2020 for OOPs CAT-1
