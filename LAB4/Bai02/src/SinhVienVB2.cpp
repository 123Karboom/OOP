#include "SinhVienVB2.h"
#include<bits/stdc++.h>
using namespace std;

SinhVienVB2::SinhVienVB2()
{
    //ctor
    diemThi = 0;
}

SinhVienVB2::~SinhVienVB2()
{
    //dtor
}

SinhVienVB2::SinhVienVB2(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB, double diemThi) : SinhVien(hoTen, maSo, diaChi, soTinChi, diemTB)
{
    this->diemThi = diemThi;
}
// Constructor & Destructor

// Hàm xuất thông tin
void SinhVienVB2::xuat() const
{
    SinhVien ::xuat();
    cout << "   + Diem thi tot nghiep: " << diemThi << endl;
}

//Hàm xét tốt nghiệp
void SinhVienVB2::xetTotNghiep()
{
    if (soTinChi >= 84 && diemTB >= 5 && diemThi >= 5)
        this->trangThaiTN = true;

}

// Hàm phân loại
bool SinhVienVB2::laSVDH()
{
    return false;
}
