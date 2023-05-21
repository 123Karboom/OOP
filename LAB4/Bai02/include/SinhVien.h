#ifndef SINHVIEN_H
#define SINHVIEN_H

#pragma once
#include<string>
#include<iostream>
using namespace std;

class SinhVien
{
public:
    SinhVien(); // Constructor
    SinhVien(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB); //Constructor
    virtual ~SinhVien(); // Destructor
    int getMaSo(); // Lấy mã số
    double getdiemTB(); // Lấy điểm trung bình
    string getHoTen(); // Lấy họ tên
    bool getTrangthaiTN(); // Lấy trạng thái tốt nghiệp
    // Xuất thông tin sinh viên
    virtual void xuat() const
    {
        cout << "Thong tin sinh vien: " << endl;
        cout << "   + Ho va ten: " << hoTen << endl;
        cout << "   + Ma so: " << maSo << endl;
        cout << "   + Dia chi: " << diaChi << endl;
        cout << "   + Tong so tin chi: " << soTinChi << endl;
        cout << "   + Diem trung binh: " << diemTB << endl;
    }
    virtual void xetTotNghiep() = 0; // Hàm ảo xét tốt nghiệp
    virtual bool laSVDH() = 0; // Hàm ảo phân loại sinh viên -> true (là sinh viên DH),false (là sinh viên VB2)

protected:
    string hoTen;
    int maSo;
    string diaChi;
    int soTinChi;
    double diemTB;
    bool trangThaiTN = false;
private:
};

#endif // SINHVIEN_H
