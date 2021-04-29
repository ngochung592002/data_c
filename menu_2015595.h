#pragma once

void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int sel, char filename[MAX], HocVien a[MAX], int n);
void XuatMenu()
{
    cout << "\n***************************** FUNCTIONAL SYSTEM ************************";
    cout << "\n 0. Thoat khoi chuong trinh";
    cout << "\n 1. Tao danh sach hoc vien";
    cout << "\n 2  Xem danh sach hoc vien";
    cout << "\n 3. sap xep tang theo ma hoc vien chon truc tiep ";
    cout << "\n 4.sap xep tang theo ma hoc vien quicksort";
    cout << "\n 5. sap xep hoc vien theo yeu cau ";
}

int ChonMenu(int soMenu)
{
    int select;

    for (;;)
    {
        system("CLS");
        XuatMenu();
        cout << "\nNhap vao chuc nang tu 0->5, lua chon cua ban = ";
        cin >> select;
        if (0 <= select && select <= soMenu)
            break;
    }
    return select;
}

void XuLyMenu(int sel, char filename[MAX], HocVien a[MAX], int n)
{
    int kq;
    switch (sel)
    {
    case 0:
        cout << "\nThoat khoi chuong trinh";
        break;
    case 1:
        
        cout << " Da tao luc dau moi bat chuong trinh ";
        break;
    case 2:
        cout << "\nXem bang diem mon hoc : " << endl;
        Doc_File(filename, a, n);
        Xuat_DS_HocVien(a, n);
        break;
    case 3:
        cout << "\n 3. sap xep tang theo ma hoc vien chon truc tiep " << endl;;
        SapTang_MaHV(a, n);
        Xuat_DS_HocVien(a, n);
        break;
    case 4:
        cout << "\n 4.sap xep tang theo ma hoc vien quicksort"<<endl;
        QuickSort(a, n);
        Xuat_DS_HocVien(a, n);
        break;
    case 5:
        cout << "\n 5. sap xep hoc vien theo yeu cau " << endl;
        SapTang_MaHVTheoYeuCau(a, n);
        Xuat_DS_HocVien(a, n);
        break;
    }
}

