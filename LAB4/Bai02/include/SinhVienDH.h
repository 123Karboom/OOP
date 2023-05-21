#ifndef SINHVIENDH_H
#define SINHVIENDH_H

#pragma once
#include <SinhVien.h>


class SinhVienDH : public SinhVien
{
public:
    SinhVienDH(); // Constructor
    SinhVienDH(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB, string tenLV, double diemLV); // Constructor
    virtual ~SinhVienDH(); // Destructor
    void xuat() const; // Xuất thông tin
    void xetTotNghiep(); // Xét tốt nghiệp
    bool laSVDH(); // Phân loại sinh viên

protected:

private:
    string tenLV;
    double diemLV;
};

#endif // SINHVIENDH_H
