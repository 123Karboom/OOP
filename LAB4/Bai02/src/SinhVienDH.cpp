#include "SinhVienDH.h"
#include<bits/stdc++.h>
using namespace std;

SinhVienDH::SinhVienDH()
{
    tenLV = "";
    diemLV = 0;
}

SinhVienDH::~SinhVienDH()
{
    //dtor
}

SinhVienDH::SinhVienDH(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB, string tenLV, double diemLV) : SinhVien(hoTen, maSo, diaChi, soTinChi, diemTB)
{
    this->tenLV = tenLV;
    this->diemLV = diemLV;
}
// Constructor & Destructor

// Hàm xuất thông tin
void SinhVienDH::xuat() const
{
    SinhVien ::xuat();
    cout << "   + Ten luan van: " << tenLV << endl;
    cout << "   + Diem luan van: " << diemLV << endl;
}

//Hàm xét tốt nghiệp
void SinhVienDH::xetTotNghiep()
{
    if (soTinChi >= 120 && diemTB >= 5 && diemLV >= 5)
        this->trangThaiTN = true;
}

// Hàm phân loại
bool SinhVienDH::laSVDH()
{
    return true;
}
