#include<iostream>
using namespace std;

main () 	{
	float x,y,z;
	int ch;
	do	{
		cout<<"\n\t\t- - - CALCULATOR - - -\n\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit\n\nEnter your choice : ";
		cin>>ch;
		if(ch>0 && ch<5)	{
			cout<<"\nEnter num-1 : ";
			cin>>x;
			cout<<"Enter num-2 : ";
			cin>>y;
			cout<<"\nRESULT :- ";
		}
		switch(ch)	{
			case 1:
				z=x+y;
				break;
			case 2:
    			z=x-y;
				break;
			case 3:
				z=x*y;
				break;
			case 4:
				try {
					if(y==0) throw "Error (Division by Zero) !\n";
    				z=x/y;
				}
				catch (const char *msg)	{
    				cout<<msg<<endl;
    				continue;
				}
				break;
			case 5:
				exit(0);
			default:
				cout<<"\nEnter a valid Option !\n";
				continue;
		}
		cout<<z<<"\n";
	}while(ch!=5);
}
