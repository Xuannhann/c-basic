#pragma once
#define MAX 100

struct VATTU
{
	string maVT;
	string tenVT;
	unsigned int soLuong;
	string donViTinh;
	unsigned int donGia;

};
typedef VATTU MANGVT[MAX];

void NhapMotvt(VATTU& vt);
void  NhapDSVT(MANGVT a, int n);
void TieuDe();
void XuatMotVT(VATTU vt);
void XuatdsVT(MANGVT a, int n);
int  TinhTong(int x, int y, MANGVT a, int n);
int TimVTVTTheoMa(MANGVT a, int& n, string& maVT);
void HoanVi(VATTU& a, VATTU& b);
void SapXepGiamTheoDonViTinh(MANGVT a, int n);
void XoaVatTu(MANGVT a, int& n,int x);
void ChenVatTu(MANGVT a, int& n, VATTU b, string maY);
void InBangThongKeSoVTTheoDVT(MANGVT a, int n);

void NhapMotvt(VATTU& vt)
{
	cout << "\nnhap ma vat tu theo chu cai dau vat tu + 3 chu so ";
	cin.ignore();
	getline(cin, vt.maVT);
	cout << "\nnhap ten vat tu ";
	cin.ignore();
	getline(cin, vt.tenVT);
	cout << "\n nhap so luong vat tu ";
	cin >> vt.soLuong;
	cout << "\n nhap don vi tinh vat tu ";
	cin.ignore();
	getline(cin, vt.donViTinh);
	cout << "\n nhap don gia vat tu ";
	cin >> vt.donGia;

}
void  NhapDSVT(MANGVT a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl << "vat tu thu " << i + 1 << " : " << endl;
		NhapMotvt(a[i]);
	}
	cout << " da them vao danh sach nhan so 2 de xem ds ";
}
void TieuDe()
{
	cout <<"\n" <<setiosflags(ios::left)
		 << setw(10) << "MA VT"
		<< setw(15) << "TEN VAT TU"
		<< setw(25) << "SO LUONG VAT TU"
		<< setw(25) << "DON VI TINH "
		<< setw(20) << "GIA TIEN";
}
void XuatMotVT(VATTU vt)
{
	cout << "\n" << setiosflags(ios::left)
		<< setw(10) << vt.maVT
		<< setw(15) << vt.tenVT
		<< setw(25) << vt.soLuong
		<< setw(25) << vt.donViTinh
		<< setw(20) << vt.donGia << "vnd";
	
	
}
void XuatdsVT(MANGVT a, int n)
	{
	TieuDe();
	for (int i = 0; i < n; i++)
	{
		XuatMotVT(a[i]);
	}
	}
int TinhTong(int x, int y, MANGVT a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].soLuong >= x && a[i].soLuong <= y)
		sum += a[i].donGia * a[i].soLuong;
	}
	return sum;
}
int TimVTVTTheoMa(MANGVT a, int& n, string& maVT)
{
	for (int i = 0; i < n; ++i)
	{
		if (a[i].maVT == maVT)
		{
			return i;
		}
		
	}
	return -1;
}
void HoanVi(VATTU& a, VATTU& b)
{
	VATTU temp = a;
	a = b;
	b = temp;
}
void SapXepGiamTheoDonViTinh(MANGVT a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if ((a[i].donViTinh < a[j].donViTinh) || 
				(a[i].donViTinh == a[j].donViTinh) && 
                  (a[i].soLuong > a[j].soLuong))
				HoanVi(a[i], a[j]);
		   
		}
	}
	
}
void XoaVatTu(MANGVT a, int& n, int x)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].donGia >= x)
		{
			a[j++] = a[i];
		}
	}
	n = j;
}
void ChenVatTu(MANGVT a, int& n, VATTU b, string maY)
{
	int viTri = TimVTVTTheoMa(a, n, maY);
	if (viTri != 1)
	{
		for (int i = 1; i > viTri; i--)
		{
			a[i] = a[i - 1];
		}
		a[viTri + 1] = b;
		n++;
	}
	else
		cout << "khong tim thay ma vat tu de chen ";
}
void InBangThongKeSoVTTheoDVT(MANGVT a, int n)
{
	// Tạo một map để lưu số lượng vật tư theo Đơn vị tính
	std::map<string, int> bangThongKe;

	// Duyệt qua tất cả vật tư trong danh sách
	for (int i = 0; i < n; i++)
	{
		// Nếu Đơn vị tính đã có trong map, tăng số lượng
		bangThongKe[a[i].donViTinh]++;
	}
	// In tiêu đề bảng
	cout << "\nBANG THONG KE SO VAT TU THEO DON VI TINH:\n";
	cout << setiosflags(ios::left)
		<< setw(20) << "DON VI TINH"
		<< setw(20) << "SO LUONG VAT TU"
		<< endl;

	// In từng dòng dữ liệu
	for (const auto& item : bangThongKe)
	{
		cout << setw(20) << item.first
			<< setw(20) << item.second
			<< endl;
	}
}