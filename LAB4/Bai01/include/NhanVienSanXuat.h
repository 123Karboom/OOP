#ifndef NHANVIENSANXUAT_H
#define NHANVIENSANXUAT_H

#include <NhanVien.h>


class NhanVienSanXuat : public NhanVien
{
private:
    int soSanPham;

public:
    NhanVienSanXuat();                                                            // constructor
    NhanVienSanXuat(int maNV, string hoTen, long long luongCoBan, int soSanPham); // constructor
    ~NhanVienSanXuat();                                                           // destructor
    void inThongTin();                                                            // In thông tin
    void tinhLuong();                                                             // Tính lương
    int getSoSP();
};


#endif // NHANVIENSANXUAT_H
