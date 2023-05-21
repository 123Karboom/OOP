#ifndef NHANVIEN_H
#define NHANVIEN_H


#include <bits/stdc++.h>
using namespace std;

// Khai báo lớp cha Nhân viên
class NhanVien
{
protected:
    int maNV;
    string hoTen;
    long long luongCoBan;
    long long luongHangThang;

public:
    NhanVien();
    NhanVien(int maNV, string hoTen, long long luongCoBan);
    ~NhanVien();
    // Constructor & destructor
    virtual void tinhLuong() = 0; // Hàm tính lương ảo
    virtual void inThongTin()     // In thông tin nhân viên
    {
        cout << setw(20) << left << maNV;
        cout << setw(20) << left << hoTen;
        cout << setw(20) << left << luongCoBan;
    };
    string gethoTen(); // Lấy họ tên
    int getMaNV();     // Lấy mã nhân viên
    long long getLuongCoBan();
    long long getLuongHangThang();                // Lấy lương hàng tháng
    void capNhatLuongCoBan(long long luongCoBan); // Cập nhật lương cơ bản cho nhân viên
};


#endif // NHANVIEN_H
