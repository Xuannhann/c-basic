#pragma once
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu,MANGVT a, int& n);
void ChayChuongTrinh(MANGVT a, int& n);


void XuatMenu()
{
	cout << endl << "1. nhap vat tu ";
	cout << endl << "2. xuat ds vat tu ";
	cout << endl << "3. tinh tong vat tu co so luong [x,y]";
	cout << endl << "4. tim vi tri vat tu theo ma vat tu ";
	cout << endl << "5. xap sep ds vat tu giam theo don vi tinh ";
	cout << endl << "6. xoa vat tu ci don gia be hon x ";
	cout << endl << "7. chen vat tu sau vat tu co ma vat tu la y cho truoc";
	cout << endl << "8. in bang thong ke so vat tu theo don vi tinh";
	cout << endl << "0.thoat chuong trinh ";

}
int ChonMenu(int soMenu)
{
	int stt;
	system("cls");
	XuatMenu();
	cout << endl << "nhap mot so chon menu ";
	cin >> stt;
	while (stt<0 || stt>soMenu);

	return stt;
}
void XuLyMenu(int menu, MANGVT a, int& n)
{
	int x, y;
	string maVT;
	VATTU vtMoi;
	switch (menu)
	{
	case 1:
		cout << "nhap so luong vat tu muon them vao ";
		cin >> n;
		NhapDSVT(a,n);
		break;
	case 2:
		XuatdsVT(a,n);
		
			break;
	case 3:
		cout << "nhap gia tri dau x";
		cin >> x;
		cout << "nhap gia cuoi y ";
		cin >> y;
		cout << "tong gia tien tat ca cac vat tu la "<<
		TinhTong(x, y, a, n);
		break;
	case 4:
		XuatdsVT(a, n);
		cout <<endl<< "nhap ma vat tu ban muon nhap ";
		cin >> maVT;
	      TimVTVTTheoMa(a, n,maVT );
		if (TimVTVTTheoMa(a, n, maVT) != -1)
		{
			cout << "vi tri cua " << maVT << " la " << TimVTVTTheoMa(a, n, maVT) + 1 << endl;
		}
		else
		{
			cout << "vi tri cua " << maVT << " khong ton tai" << endl;
		}
		break;
	case 5:
		SapXepGiamTheoDonViTinh(a, n);
		cout << "ds vat tu sap xep theo don vi tinh la ";
		XuatdsVT(a, n);
		break;
	case 6:
		XuatdsVT(a, n);
		cout << endl<<"nhap gia tri x ";
		cin >> x;
		XoaVatTu(a, n, x);
		XuatdsVT(a, n);
		break;
	case 7:
		XuatdsVT(a, n);
		cout << endl << "nhap ma vat tu ban muon chen dang sau ";
		cin >> maVT;

		cout << "\nnhap ma vat tu theo chu cai dau vat tu + 3 chu so ";
		cin.ignore();
		getline(cin, vtMoi.maVT);
		cout << "\nnhap ten vat tu ";
		cin.ignore();
		getline(cin, vtMoi.tenVT);
		cout << "\n nhap so luong vat tu ";
		cin >> vtMoi.soLuong;
		cout << "\n nhap don vi tinh vat tu ";
		cin.ignore();
		getline(cin, vtMoi.donViTinh);
		cout << "\n nhap don gia vat tu ";
		cin >> vtMoi.donGia;
		ChenVatTu(a, n, vtMoi, maVT);
		XuatdsVT(a, n);
	case 8:
		InBangThongKeSoVTTheoDVT( a, n);
		break;

	
	default:
		cout << endl << "thoat chuong trinh ";
		break;
	}
	if (menu > 0)
		cout << endl << "nhap mot so bat ki de tiep tuc";
	_getch();
}
void ChayChuongTrinh(MANGVT a, int& n)
{
	int menu, chon = 8;
	do
	{
		menu = ChonMenu(chon);
		XuLyMenu(menu, a,n);
	} while (menu > 0);


}
