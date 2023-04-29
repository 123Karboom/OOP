#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
public:
    string maNV;
    string hoTen;
    string phongBan;
    int luongCoBan;
    int thuong;

    NhanVien()
    {
        maNV = hoTen = phongBan = "";
        luongCoBan = thuong = 0;
    }
    NhanVien(string maNV, string hoTen, string phongBan, int luongCoBan, int thuong);
    int thucLanh();
    void nhap();
    void xuat();
};

NhanVien ::NhanVien(string maNV, string hoTen, string phongBan, int luongCoBan, int thuong)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->phongBan = phongBan;
    this->luongCoBan = luongCoBan;
    this->thuong = thuong;
}

int NhanVien ::thucLanh()
{
    return luongCoBan + thuong;
}

void NhanVien ::xuat()
{
    cout << setw(15) << left << maNV;
    cout << setw(15) << left << hoTen;
    cout << setw(15) << left << phongBan;
    cout << setw(15) << left << luongCoBan;
    cout << setw(15) << left << thuong;
    cout << setw(15) << left << thucLanh();
    cout << endl;
}

class QuanLy
{
private:
    list<NhanVien> danhSachNhanVien;

public:
    void nhapDanhSachNhanVien();
    void tinhTongThucLanh();
    void demNVLuongCoBanThapNhat();
    void demNVThuongCao();
    void demThucLanhCaoNhat();
    void sapXep();
};

void QuanLy ::nhapDanhSachNhanVien()
{
    srand(time(NULL));

    // define arrays of possible values for each employee attribute
    string maNV[] = {"NV00001", "NV00002", "NV00003", "NV00004", "NV00005",
                     "NV00006", "NV00007", "NV00008", "NV00009", "NV00010"};
    string hoTen[] = {"Nguyen Van A", "Le Thi B", "Tran Van C", "Pham Thi D", "Do Van E",
                      "Hoang Thi F", "Vu Van G", "Bui Thi H", "Lam Van I", "Ha Thi K"};
    string phongBan[] = {"Phong A", "Phong B", "Phong C", "Phong D", "Phong E",
                         "Phong F", "Phong G", "Phong H", "Phong I", "Phong K"};
    int luongCoBan[] = {5000000, 5500000, 6000000, 6500000, 7000000,
                        7500000, 8000000, 8500000, 9000000, 9500000};
    int thuong[] = {1000000, 1200000, 1400000, 1600000, 1800000,
                    2000000, 2200000, 2400000, 2600000, 2800000};
    cin.ignore();
    for (int i = 0; i < 10; i++)
    {
        string ma = maNV[i];
        string ten = hoTen[i];
        string pb = phongBan[rand() % 10];
        int luongCB = luongCoBan[rand() % 10];
        int th = thuong[rand() % 10];
        danhSachNhanVien.push_back(NhanVien(ma, ten, pb, luongCB, th));
    }
}

void QuanLy ::tinhTongThucLanh()
{
    int tong = 0;
    for (auto nv : danhSachNhanVien)
    {
        tong += nv.thucLanh();
    }
    cout << "____________________________________________\n";
    cout << "Tong thuc lanh cua tat ca nhan vien la: " << tong << endl;
    cout << "____________________________________________\n";
}

void QuanLy ::demNVLuongCoBanThapNhat()
{
    int luongCoBanThapNhat = INT_MAX;
    for (auto nv : danhSachNhanVien)
    {
        if (nv.luongCoBan < luongCoBanThapNhat)
        {
            luongCoBanThapNhat = nv.luongCoBan;
        }
    }

    cout << "---------------- DANH SACH NHAN VIEN CO LUONG CO BAN THAP NHAT ---------------- " << endl;
    cout << setw(15) << left << "Ma Nhan Vien ";
    cout << setw(15) << left <<"Ho va Ten ";
    cout << setw(15) << left <<"Phong Ban ";
    cout << setw(15) << left <<"Luong Co Ban ";
    cout << setw(15) << left <<"Thuong Them ";
    cout << setw(15) << left <<"Thuc Lanh ";
    cout << endl;

    for (auto nv : danhSachNhanVien)
    {
        if (nv.luongCoBan == luongCoBanThapNhat)
        {
            nv.xuat();
        }
    }
}

void QuanLy ::demNVThuongCao()
{
    int soLuongNhanVienCoThuongCao = 0;
    for (auto nv : danhSachNhanVien)
    {
        if (nv.thuong >= 1200000)
        {
            soLuongNhanVienCoThuongCao++;
        }
    }    
    cout << "____________________________________________\n";
    cout << "So luong nhan vien co thuong >= 1200000 la: " << soLuongNhanVienCoThuongCao << endl;
    cout << "____________________________________________\n";
}

void QuanLy ::demThucLanhCaoNhat()
{
    // Sắp xếp danh sách nhân viên theo tiền thực lãnh giảm dần
    danhSachNhanVien.sort([](NhanVien a, NhanVien b)
                          { return a.thucLanh() > b.thucLanh(); });

    // In top 5 nhân viên có tiền thực lãnh lớn nhất
    cout << "---------------- TOP 5 NHAN VIEN CO THUC LANH CAO NHAT ----------------" << endl;
    cout << setw(15) << left << "Ma Nhan Vien ";
    cout << setw(15) << left <<"Ho va Ten ";
    cout << setw(15) << left <<"Phong Ban ";
    cout << setw(15) << left <<"Luong Co Ban ";
    cout << setw(15) << left <<"Thuong Them ";
    cout << setw(15) << left <<"Thuc Lanh ";
    cout << endl;

    int i = 1;
    for (auto nv : danhSachNhanVien)
    {
        nv.xuat();
        if (i == 5)
        {
            break;
        }
        i++;
    }
}

void QuanLy ::sapXep()
{
    // Sắp xếp danh sách nhân viên theo phòng ban tăng dần, nếu phòng ban trùng nhau thì giảm dần theo mã nhân viên
    danhSachNhanVien.sort([](NhanVien a, NhanVien b)
                          {
    if (a.phongBan == b.phongBan) 
    {
        return a.maNV > b.maNV;
    }
    return a.phongBan < b.phongBan; });

    // In danh sách các nhân viên đã được sắp xếp
    cout << "---------------- DANH SACH NHAN VIEN THEO PHONG BAN ----------------" << endl;
    cout << setw(15) << left << "Ma Nhan Vien ";
    cout << setw(15) << left <<"Ho va Ten ";
    cout << setw(15) << left <<"Phong Ban ";
    cout << setw(15) << left <<"Luong Co Ban ";
    cout << setw(15) << left <<"Thuong Them ";
    cout << setw(15) << left <<"Thuc Lanh ";
    cout << endl;

    for (auto nv : danhSachNhanVien)
    {
        nv.xuat();
    }
}
int main()
{
    QuanLy Bao;
    Bao.nhapDanhSachNhanVien();
    Bao.tinhTongThucLanh();
    Bao.demNVThuongCao();
    Bao.demNVLuongCoBanThapNhat();
    Bao.demThucLanhCaoNhat();
    Bao.sapXep();
}