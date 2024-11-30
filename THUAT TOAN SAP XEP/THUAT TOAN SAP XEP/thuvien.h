#pragma once
typedef int MANG[50];



void NhapMang(MANG a, int& n);
void XuatMang(MANG a, int& n);
void HoanVi(int& i, int& j);
void SapXepDoiCho(MANG a, int& n);
void SapXeoNoiBot(MANG a, int& n);


void NhapMang(MANG a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}
void XuatMang(MANG a, int& n)
{
	cout << endl << "cac phan tu cua mang " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}
void HoanVi(int& a, int& b)
{
	int HV = a;
	a = b;
	b = HV;
}
void SapXepDoiCho(MANG a, int& n)
{
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
			{

				HoanVi(a[i], a[j]);
			}
			
		}
	}
	XuatMang(a, n);
}
void SapXeoNoiBot(MANG a, int& n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = n - 1; j > i; j--) 
		{
			if (a[j] < a[j - 1]) {
				HoanVi(a[j] , a[j - 1]);
			}
		}
	}
	XuatMang(a, n);
}
