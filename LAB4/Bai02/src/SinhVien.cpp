#include "SinhVien.h"
#include<string>
using namespace std;

SinhVien::SinhVien()
{
    hoTen = diaChi = "";
    maSo = soTinChi = 0;
    diemTB = 0;
}

SinhVien::~SinhVien() {}

SinhVien::SinhVien(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB)
{
    this->hoTen = hoTen;
    this->diaChi = diaChi;
    this->maSo = maSo;
    this->soTinChi = soTinChi;
    this->diemTB = diemTB;
}
// Constructor & Destructor

// Lấy họ tên
string SinhVien::getHoTen()
{
    return hoTen;
}

// Lấy mã số
int SinhVien::getMaSo()
{
    return maSo;
}

// Lấy điểm trung bình
double SinhVien::getdiemTB()
{
    return diemTB;
}

// Lấy trạng thái tốt nghiệp
bool SinhVien::getTrangthaiTN()
{
    return trangThaiTN;
}


