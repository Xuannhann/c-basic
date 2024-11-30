#pragma once
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, MANG a, int& n);
void ChayChuongTrinh(MANG a, int& n);

void XuatMenu()
{
	cout << endl << "1. nhap mang ";
	cout << endl << "2. xuat mang ";
	cout << endl << "3. sap xep doi cho  ";
	cout << endl << "4. sap xep noi bot ";
	cout << endl << "5. sap xep chen truc tiep ";
	cout << endl << "6. sap xep chon truc tiep ";
	void XuLyMenu(int menu, MANG a, int& m, int& n);
}
int ChonMenu(int soMenu)
{
	int stt;
	do {

		system("cls");
		XuatMenu();
		cout << endl << "nhap mot so chon menu ";
		cin >> stt;

	}while(stt<0 || stt>soMenu);
	return stt;

}
void XuLyMenu(int menu, MANG a, int& n)
{
	switch (menu)
	{
	case 1:
		cout << endl << "nhap mang ";
		cin >> n;
		NhapMang(a, n);
		break;
	case 2:
		XuatMang(a,n);
		break;
	case 3:
		cout << "mang sau khi sap xep la ";
		SapXepDoiCho(a, n);
		break;

	default:cout << endl << "thoat chuong trinh ";
		break;
	}
	if(menu>0)
	{
		cout << endl << "nhan mot phim de tiep tuc ";
		_getch();
	}
}
void ChayChuongTrinh(MANG a, int& n)
{
	int menu, soMenu = 6;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu>0);
}