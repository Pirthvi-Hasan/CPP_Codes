#include<iostream>
using namespace std;

class Item	{
	int mob_code,mod_no,price;
	char mod_name[20];
	public:
	void get_details()	{
		cout<<"\nEnter Model Name   : ";
		scanf("%*c%[^\n]s",mod_name);
		cout<<"Enter Model Number : ";
		cin>>mod_no;
		cout<<"Enter Item Code    : ";
		cin>>mob_code;
		cout<<"Enter Item Price   : ";
		cin>>price;
	}
};
class SalesPerson	{
	int per_id;
	char per_name[30];
	public:
	int mob_sold;
	void get_data()	{
		cout<<"\nEnter your name : ";
		scanf("%*c%[^\n]s",per_name);
		cout<<"Enter your ID   : ";
		cin>>per_id;
		cout<<"Enter no.of Mobiles Sold : ";
		cin>>mob_sold;
	}
};

class Samsung	{
	static int tot_mob_sold;                            // Static Variable Used....
	class Item *It;
	class SalesPerson *Sp;
	int itm,sal;
	public:
	Samsung(int a,int b)	{
		It = new Item[a];
		Sp = new SalesPerson[b];
		itm = a;
		sal = b;
	}
	void get_details()	{
		int n;
		for(n=0;n<itm;n++)	{
			cout<<"\nItem - "<<n+1<<" :-\n";
			It[n].get_details();
		}
		for(n=0;n<sal;n++)	{
			cout<<"\nSales Person - "<<n+1<<" :-\n";
			Sp[n].get_data();
			this->add_sales(Sp[n].mob_sold);
		}
	}
	static void add_sales(int &x){                        // Static Function Used....
		tot_mob_sold += x;
	}
	void print_sold()	{cout<<"\n\nTotal Mobiles Sold -> "<<tot_mob_sold<<endl;}
};
int Samsung::tot_mob_sold=0;

int main()	{
	int it,sp;
	cout<<"\nEnter no.of Mobile Items in Store_1 : ";
	cin>>it;
	cout<<"\nEnter no.of Sales Person in Store_1 : ";
	cin>>sp;
	Samsung store_1(it,sp);
	store_1.get_details();
	store_1.print_sold();
	return 0;
}
