#pragma once
typedef int MANG[50];



void NhapMang(MANG a, int& n);
void XuatMang(MANG a, int& n);
void HoanVi(int& a, int& b);
void DuongTang_Sokhac(MANG a, int& n);
void SoKhacDau_0_Cuoi(MANG a, int& n);
void khong_AmGiam_DuongTang(MANG a, int& n);

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
void DuongTang_Sokhac(MANG a, int& n)
{
	int dk;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			dk = (a[i] > 0 && a[j] > 0 && a[i] > a[j]);
			if (dk)
			{

				HoanVi(a[i], a[j]);
			}

		}
	}
	XuatMang(a, n);
}
void SoKhacDau_0_Cuoi(MANG a, int& n)
{
	int dk;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			dk = (a[i] != 0 && a[j] != 0 && a[i] > a[j]) ||
				(a[i] == 0 && a[j] < 0);
				
			if (dk) {
				HoanVi(a[i], a[j]);
			}
		}
	}
	int count = 0; 
	for (int i = 0; i < n; ++i) 
	{ 
		if (a[i] != 0) 
		{
			HoanVi(a[count++], a[i]);
		}
	}
	
	XuatMang(a, n);
}
void khong_AmGiam_DuongTang(MANG a, int& n)
{
	int dk;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			dk = (a[i] < 0 && a[j] < 0 && a[i] < a[j]) || (a[i] > 0 && a[j] >0 && a[i] > a[j]);
			if (dk)
			{

				HoanVi(a[i], a[j]);
			}

		}
	}
	XuatMang(a, n);
}