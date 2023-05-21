#ifndef DAIHOC_H
#define DAIHOC_H

#pragma once
#include<vector>
#include<string>
#include "SinhVien.h"

using namespace std;
class DaiHoc
{
public:
    DaiHoc(); // Constructor
    virtual ~DaiHoc(); // Destructor
    void taoDanhSach(); // 1. Tạo danh sách sinh viên
    void xuatDanhSach();// 2. Xuất danh sách sinh viên
    void xetTotNghiep();// 3. Xét tốt nghiệp
    vector<SinhVien *> SVTotNghiep(); // 4. Tìm các sinh viên đủ điều kiện tốt nghiệp
    vector<SinhVien *> SVKoTotNghiep(); // 5. Tìm các sinh viên không đủ điều kiện tốt nghiệp
    vector<SinhVien *> SVVB2DiemTBThapNhat(); //7. Tìm các sinh viên điểm trung bình thấp nhất
    vector<SinhVien *> SVDHDiemTBCaoNhat(); //8. Sinh viên điểm trung bình cao nhất
protected:

private:
    vector<SinhVien *> danhSachSV;
};

#endif // DAIHOC_H
