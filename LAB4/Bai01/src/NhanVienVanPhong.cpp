#include "NhanVienVanPhong.h"


NhanVienVanPhong ::NhanVienVanPhong() : NhanVien()
{
    soNG = 0;
}

NhanVienVanPhong ::NhanVienVanPhong(int maNV, string hoTen, long long luongCoBan, int soNG) : NhanVien(maNV, hoTen, luongCoBan)
{
    this->soNG = soNG;
}
// Constructor

NhanVienVanPhong ::~NhanVienVanPhong() {} // Destructor

// In thông tin
void NhanVienVanPhong ::inThongTin()
{
    NhanVien ::inThongTin();
    cout << setw(20) << left << soNG;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

// Tính lương
void NhanVienVanPhong ::tinhLuong()
{
    luongHangThang = luongCoBan + soNG * 25000;
    if (soNG < 15)
    {
        luongHangThang += luongHangThang * 0.2;
    }
}

int NhanVienVanPhong ::getSoNG()
{
    return soNG;
}
