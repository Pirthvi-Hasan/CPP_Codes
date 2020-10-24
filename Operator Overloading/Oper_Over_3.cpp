#include<iostream>
using namespace std;

class Date	{
	int d,m,y;
	public:
	operator << (int x)	{
		d=d-x;
		while(d<1)	{
			m-=1;
			if(m<1) {
				m=12;
				y-=1;
			}
			d=d+30;
		}
	}
	void operator >> (int x)	{
		d=d+x;
		while(d>30)	{
			m+=1;
			if(m>12) {
				m=1;
				y+=1;
			}
			d=d-30;
		}
	}
	void get_date()	{
		do{
			cout<<"\nEnter a Date (dd mm yyyy) : ";
			cin>>d>>m>>y;
			if(d<0 || m<0 || y<0) cout<<"\nNegative Value !\nEnter a Valid Date !\n";
			else if(d>30 || m>12) cout<<"\nThat Date doesn't exist.\nEnter a Valid Date!\n";
		}while(d<0 || m<0 || y<0 || d>31 || m>12);
	}
	void print()	{
		printf("\nDate : %02d/%02d/%02d\n",d,m,y);
	}
};

int main()	{
	cout<<"Consider all months have 30 Days....\n\n";
	Date d1;
	d1.get_date();
	d1>>1234;
	d1.print();
	d1<<5;
	d1.print();
	return 0;
}
