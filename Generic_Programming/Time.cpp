#include<iostream>
#include<string.h>
using namespace std;

template<typename X>
class Railway	{
	public:
	X h,m;
	void get_time()	{
		do	{
			cout<<"\nEnter Railway_Time (HH:MM) : ";
			scanf("%d:%d",&h,&m);
			if(h<0||h>23||m<0||m>59) cout<<"\nInvalid Time !\n";
		}while(h<0||h>23||m<0||m>59);
	}
};

class Civil	{
	int h,m;
	char fmt[3];
	public:
	operator = (Railway<int> &obj)	{
		strcpy(fmt,"AM");
		this->h=obj.h;
		this->m=obj.m;
		if(obj.h>=12) strcpy(fmt,"PM");
		if(obj.h>12) this->h=obj.h-12;
	}
	void disp_time()	{
		printf("\nEquivalent Civil_Time      : %02d:%02d %s\n",h,m,fmt);
	}
};

main()	{
	Railway<int> rt;
	Civil ct;
	
	rt.get_time();
	ct=rt;
	ct.disp_time();
}
