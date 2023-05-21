#ifndef SINHVIENVB2_H
#define SINHVIENVB2_H

#pragma once
#include <SinhVien.h>


class SinhVienVB2 : public SinhVien
{
public:
    SinhVienVB2();  // Constructor
    SinhVienVB2(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB, double diemThi);// Constructor
    virtual ~SinhVienVB2(); // Destructor
    void xuat() const; // Xuất thông tin
    void xetTotNghiep(); // Xét tốt nghiệp cho sinh viên
    bool laSVDH();  //
protected:

private:
    double diemThi;
};

#endif // SINHVIENVB2_H
