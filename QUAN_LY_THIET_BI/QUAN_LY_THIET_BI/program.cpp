#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>


using namespace std;

#include"thuvien.h"
#include"menu.h"

int main()
{
	MANG tb =
	{

		{"DT1205", "Dien Thoai",2021,2,10.50f},
	{"MQ43201", "May Quat", 2020, 1, 200.00},
	{"MT23452","May Tinh DEll",2021,10,30.75f},
		{"TL44432","Tu Lanh",2022,5,50.00f},
	{"MT12332","May Tinh HP",2020,1,200.0f}


	};
	int sotb = 5;
	ChayChuongTrinh(tb, sotb);
		
	return 1;
}