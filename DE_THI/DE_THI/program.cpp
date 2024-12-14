#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<map>

using namespace std;

#include"thuvien.h"
#include"menu.h"

int main()
{
	MANGVT vt = {
		{"VT1","xi mang",50,"bao",200000},
		{"VT2","xeng",20,"cai",45000},
		{"VT3","gach",1345,"vien",10000},
		{"VT4","voi",50,"bao",24000},
		{"VT5","cat",60,"bao",25000}

	};
	

	
	int sovt = 5;
	

	ChayChuongTrinh(vt,sovt);

	return 1;
}
