#pragma once

#define MAX 100

struct HocVien
{
	char maHV[8];
	char hoHV[10];
	char tenLot[10];
	char tenHV[10];
	char lop[10];
	int namSinh;
	double diemTB;
	int soTC;
};



int Doc_File(char* filename, HocVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maHV;
		in >> a[n].hoHV;
		in >> a[n].tenLot;
		in >> a[n].tenHV;
		in >> a[n].lop;
		in >> a[n].namSinh;
		in >> a[n].diemTB;
		in >> a[n].soTC;
		n++;
	}
	in.close();
	return 1;
}

void XuatDongKe(char kt)
{
	cout << '|';
	for (int i = 1; i <= 110; i++)
		cout << kt;
	cout << '|' << endl;
}

void XuatTieuDe()
{
	XuatDongKe('=');

	cout << setiosflags(ios::left);
	cout << setw(15) << "Ma Hoc Vien"
		<< setw(12) << "Ho"
		<< setw(12) << "Ten lot"
		<< setw(13) << "Ten"
		<< setw(10) << "Lop"
		<< setw(13) << "Nam Sinh"
		<< setw(20) << "Diem trung binh"
		<< setw(12) << "So tin chi";
	cout << endl;

	XuatDongKe('=');
}

void Xuat_1_HocVien(HocVien a)
{
	cout << setiosflags(ios::left);
	cout << setw(14) << a.maHV
		<< setw(13) << a.hoHV
		<< setw(12) << a.tenLot
		<< setw(12) << a.tenHV
		<< setw(12) << a.lop
		<< setw(18) << a.namSinh
		<< setw(17) << a.diemTB
		<< setw(12) << setiosflags(ios::fixed) << setprecision(2) << a.soTC;
	cout << endl;
}

void Xuat_DS_HocVien(HocVien a[MAX], int n)
{
	XuatTieuDe();
	for (int i = 0; i < n; i++)
	{
		Xuat_1_HocVien(a[i]);
	}
}
void HoanVi(HocVien& x, HocVien& y)
{
	HocVien t;
	t = x;
	x = y;
	y = t;
}
void Copy(HocVien b[MAX], HocVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void SapTang_MaHV(HocVien a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (_strcmpi(a[i].maHV, a[j].maHV) > 0)
				HoanVi(a[i], a[j]);

}
void Partition(HocVien a[MAX], int l, int r)
{
	int i, j;
	HocVien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (_strcmpi(x.maHV, a[i].maHV) > 0)
			i++;
		while (_strcmpi(a[j].maHV, x.maHV) > 0)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}
void QuickSort(HocVien a[MAX], int n)
{
	Partition(a, 0, n - 1);
}
void SapTang_MaHVTheoYeuCau(HocVien a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (_strcmpi(a[i].tenHV, a[j].tenHV) > 0)
			{
				HoanVi(a[i], a[j]);
			}
			if (_strcmpi(a[i].tenHV, a[j].tenHV) == 0)
			{
				if (_strcmpi(a[i].hoHV, a[j].hoHV) > 0)
				{
					HoanVi(a[i], a[j]);
				}
			}
			if ((_strcmpi(a[i].tenHV, a[j].tenHV) == 0)&&(_strcmpi(a[i].hoHV, a[j].hoHV) ==0))
			{
				if (_strcmpi(a[i].tenLot, a[j].tenLot) > 0)
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}

}





