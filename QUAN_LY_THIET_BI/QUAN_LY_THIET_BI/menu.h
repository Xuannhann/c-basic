#pragma once
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, MANG a, int& n);
void ChayChuongTrinh(MANG a, int n);

void XuatMenu()
{
	cout << endl << "1. nhap danh sach thiet  bi";
	cout << endl << "2. xuat danh sach thiet bi ";
	cout << endl << "3. tinh tong gia tien thiet bi ";
	cout << endl << "4. tim vi tri thiet bi theo ma thiet bi ";
	cout << endl << "5. sap xep thiet bi giam theo nam nhap ";
	cout << endl << "6. xoa tat ca thiet bi co nam nhap bang x";
	cout << endl << "7.chèn thiết bị sau co ma thiet bi y cho truoc";
	cout << endl << "8. in bang thong ke so thiet bi theo nam nhap";
}

int ChonMenu(int soMenu)
{
	int stt;
	system("cls");
	XuatMenu();
	cout << endl << "nhap mot so chon menu ";
	cin >> stt;
	while(stt<0|| stt>soMenu);

	return stt;

}
void XuLyMenu(int menu, MANG a, int& n)
{

	switch (menu)
	{
	case 1:

		break;
	case 2:
		XuatTb(a, n);
		break;

	default:
		cout << endl << "thoat chuong trinh ";
		break;
	}
	if (menu > 0)
	{
		cout << endl << "nhap mot phim bat ky de tiep tuc ";
		_getch();

	}
}
void ChayChuongTrinh(MANG a, int n)
{
	int menu, soMenu = 8;
	do{
	
	menu = ChonMenu(soMenu);
	XuLyMenu(menu, a, n);
	
          
	} while (menu > 0);

}