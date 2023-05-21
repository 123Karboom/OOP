#include "NhanVien.h"

NhanVien ::NhanVien()
{
    maNV = 0;
    hoTen = "";
    luongCoBan = 0.0;
    luongHangThang = 0.0;
}

NhanVien ::NhanVien(int maNV, string hoTen, long long luongCoBan)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCoBan = luongCoBan;
    this->luongHangThang = 0.0;
}
// Constructor

NhanVien ::~NhanVien() {} // Destructor

// Lấy họ tên
string NhanVien ::gethoTen()
{
    return hoTen;
}

// Lấy mã nhân viên
int NhanVien ::getMaNV()
{
    return maNV;
}

// Lấy lương cơ bản
long long NhanVien ::getLuongCoBan()
{
    return luongCoBan;
}

// Lấy lương hàng tháng
long long NhanVien ::getLuongHangThang()
{
    return luongHangThang;
}

// Cập nhật lương cơ bản
void NhanVien ::capNhatLuongCoBan(long long luongCoBan)
{
    this->luongCoBan = luongCoBan;
}
