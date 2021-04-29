#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include <stdlib.h>
void ChayChuongTrinh();


using namespace std;

#include"thuvien_2015595.h"
#include"menu_2015595.h"

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int sel, soMenu = 5, n = 0;
	char filename[100];
	HocVien a[100];
	int kq;
	do
	{
		cout << "\nNhap ten tap tin : ";
		cin >> filename;
		kq = Doc_File(filename, a, n);
	} while (!kq);
	cout << "\nDa chuyen thanh cong tap tin " << filename << " vao bang diem a.";

	do
	{
		sel = ChonMenu(soMenu);
		XuLyMenu(sel, filename, a, n);
		cout << endl;
		system("PAUSE");
	} while (sel > 0);
	///chan chó qua 
	//pri
}