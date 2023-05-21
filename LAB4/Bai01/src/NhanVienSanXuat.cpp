#include "NhanVienSanXuat.h"

NhanVienSanXuat ::NhanVienSanXuat() : NhanVien()
{
    soSanPham = 0;
}

NhanVienSanXuat ::NhanVienSanXuat(int maNV, string hoTen, long long luongCoBan, int soSanPham) : NhanVien(maNV, hoTen, luongCoBan)
{
    this->soSanPham = soSanPham;
}

// Constructor
NhanVienSanXuat ::~NhanVienSanXuat() {}

// In thông tin
void NhanVienSanXuat ::inThongTin()
{
    NhanVien ::inThongTin();
    cout << setw(20) << left << soSanPham;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

// Tính lương
void NhanVienSanXuat ::tinhLuong()
{
    luongHangThang = luongCoBan + soSanPham * 175000;
    if (luongHangThang >= 10000000)
    {
        luongHangThang += luongHangThang * 0.1;
    }
    if (soSanPham < 10)
    {
        luongHangThang += luongHangThang * 0.3;
    }
}

int NhanVienSanXuat ::getSoSP()
{
    return soSanPham;
}
