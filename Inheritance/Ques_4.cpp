#include<iostream>
#include<conio.h>
using namespace std;

class Shape	{
	protected:
	double x,y;
	public:
	void get_data(double a,double b=3.14)	{
		x=a;
		y=b;
	}	
	virtual void display_area(){
	};
	virtual ~Shape() {}
};

class Rectangle : public Shape	{
	public:
	void display_area()	{
		cout<<"\nArea of Rectangle : "<<x*y<<" units.\n";
	}
};

class Circle : public Shape	{
	public:
	void display_area()	{
		cout<<"\nArea of Circle : "<<y*x*x<<" units.\n";
	}
};

class Triangle : public Shape	{
	public:
	void display_area()	{
		cout<<"\nArea of Triangle : "<<0.5*x*y<<" units.\n";
	}
};

main()	{
	Shape *ptr;
	char opt,wait;
	double a,b;
	do{
		system("cls");
		cout<<"\n1.Area of Rectangle\n2.Area of Circle\n3.Area of Triangle\n4.Exit\n\nEnter your Option : ";
		opt=getche();
		switch(opt)	{
			case '1':
				ptr = new Rectangle;
				cout<<"\n\nEnter Length  : ";
				cin>>a;
				cout<<"\nEnter Breadth : ";
				cin>>b;
				ptr->get_data(a,b);
				ptr->display_area();
				delete ptr;
				break;
			case '2':
				ptr = new Circle;
				cout<<"\n\nEnter Radius : ";
				cin>>a;
				ptr->get_data(a);
				ptr->display_area();
				delete ptr;
				break;
			case '3':
				ptr = new Triangle;
				cout<<"\n\nEnter Base   : ";
				cin>>a;
				cout<<"\nEnter Height : ";
				cin>>b;
				ptr->get_data(a,b);
				ptr->display_area();
				delete ptr;
				break;
			case '4':
				cout<<"\n\nGoodBye ! Have a Nice Day !\n";
				exit(0);
			default:
				cout<<"\n\nEnter a Valid Option !\n";
		}
		cout<<"\n\nPress Any Key to Continue....";
		wait=getche();
	}while(opt!='4');
}
