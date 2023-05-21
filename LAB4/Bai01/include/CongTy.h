#ifndef CONGTY_H
#define CONGTY_H
#include "NhanVien.h"
#include "NhanVienVanPhong.h"
#include "NhanVienSanXuat.h"
#include <bits/stdc++.h>
using namespace std;

class CongTy
{
private:
    string tenCT;
    vector<NhanVien *> danhSachNV;
    vector<NhanVienVanPhong *> danhSachNVVP;
    vector<NhanVienSanXuat *> danhSachNVSX;
    int soNVVP;
    int soNVSX;

public:
    CongTy();
    ~CongTy();
    void loadData(int a, int b);                           // 1. Tao du lieu nhan vien
    void inDanhSachNhanVien() const;                       // 2. Xuat cac nhan vien trong cong ty
    void tinhLuong();                                      // 3. Tinh luong nhan vien
    bool timNhanVienTheoMaNhanVien(int ma, NhanVien *&NV); // 4. Tim nhan vien theo ma nhan vien
    void capNhatLuongCoBan(int ma, long long luong);          // 5. Cap nhat luong co ban
    vector<NhanVien *> NhanVienLuongCaoNhat();             // 6. Tim nhan vien luong cao nhat
    vector<NhanVienSanXuat *> NhanVienCoSoSPThapNhat();    // 7. Tim nhan vien co so san pham thap nhat
    vector<NhanVien *> Top10NVLuongCaoNhat();              // 8. Top 10 nhan vien luong cao nhat
};

#endif // CONGTY_H
