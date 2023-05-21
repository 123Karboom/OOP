#ifndef NHANVIENVANPHONG_H
#define NHANVIENVANPHONG_H

#include <NhanVien.h>


class NhanVienVanPhong : public NhanVien
{
private:
    int soNG;

public:
    NhanVienVanPhong();
    NhanVienVanPhong(int maNV, string hoTen, long long luongCoBan, int soNG);
    // Constructor
    ~NhanVienVanPhong(); // Destructor
    void inThongTin();   // In thông tin
    void tinhLuong();    // Tính lương
    int getSoNG();      //  Lấy số ngày làm viec
};

#endif // NHANVIENVANPHONG_H
