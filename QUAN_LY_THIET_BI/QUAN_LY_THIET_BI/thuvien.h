#pragma once
#define MAX 100

struct ThietBi
{
	string matb;
	string tentb;
	unsigned int namNhap;
	unsigned int TgBaoHanh;
	float tien;
};

typedef  ThietBi MANG[MAX];
void Nhap1TB(ThietBi &tb);

void TieuDe();
void Xuat1TB(ThietBi tb);
void XuatTb(MANG a, int n);


void Nhap1TB(ThietBi& tb)
{
	cout << "nhap ma thiet bi ";
	
		cin.ignore();
		_flushall();
		gets_s(tb.matb);
}

void TieuDe()
{
	cout << setiosflags(ios::left)
		<< setw(15)<<"MA TB"
		<< setw(26)<< "TEN TB"
		<< setw(15) << "NAM NHAP"
		<< setw(15) << "TG BAO HANH "
		<< setw(7) << "GIA TIEN"
		<< endl;
}
void Xuat1TB(ThietBi tb)
{
	cout << setiosflags(ios::left)
		<< setw(15)<<tb.matb
		<< setw(26)<<tb.tentb
		<< setw(15) << tb.namNhap
		<< setw(15) << tb.TgBaoHanh
		<< setw(7) << tb.tien
		<< endl;
}

void XuatTb(MANG a, int n)
{
	TieuDe();

	for (int i = 0; i < n; i++)
	{
		Xuat1TB(a[i]);
	}

}  