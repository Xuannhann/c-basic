#pragma once
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, MANG a, int& n);
void ChayChuongTrinh(MANG a, int& n);

void XuatMenu()
{
	cout << endl << "1. nhap mang ";
	cout << endl << "2. xuat mang ";
	cout << endl << " 3. duong tang so khac giu nguyen  ";
	cout << endl << "4. khong cuoi mang so khac tang nam dau  ";
	cout << endl << "5. sap khong dau am giam duong tang  ";
	cout << endl << "";
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

	} while (stt<0 || stt>soMenu);
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
		XuatMang(a, n);
		break;
	case 3:
		cout << endl << "thu tu sap xep la ";
		DuongTang_Sokhac(a, n);
		break;
	case 4:
		cout << endl << "thu tu sap Xep la ";
		SoKhacDau_0_Cuoi(a, n);
		break;
	case 5:
		cout << endl << "thu tu sap Xep la ";
		khong_AmGiam_DuongTang(a, n);
		break;

	
	default:cout << endl << "thoat chuong trinh ";
		break;
	}
	if (menu > 0)
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
	} while (menu > 0);
}