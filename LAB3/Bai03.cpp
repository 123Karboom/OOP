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
    NhanVien() {} // Constructor
    NhanVien(int maNV, string hoTen, double luongCoBan)
    {
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->luongCoBan = luongCoBan;
        this->luongHangThang = 0.0;
    }

    virtual void tinhLuong() = 0;
    virtual void inThongTin(){};

    string gethoTen()
    {
        return hoTen;
    }
    int getMaNV()
    {
        return maNV;
    }

    void capNhatLuongCoBan(double luongCoBan)
    {
        this->luongCoBan = luongCoBan;
    }

    double getLuongHangThang()
    {
        return luongHangThang;
    }
};

class NhanVienSanXuat : public NhanVien
{
private:
    int soSanPham;

public:
    NhanVienSanXuat(int maNV, string hoTen, long long luongCoBan, int soSanPham) : NhanVien(maNV, hoTen, luongCoBan)
    {
        this->soSanPham = soSanPham;
    }
    void inThongTin();
    void tinhLuong();
};

void NhanVienSanXuat ::inThongTin()
{
    cout << setw(20) << left << maNV;
    cout << setw(20) << left << hoTen;
    cout << setw(20) << left << luongCoBan;
    cout << setw(20) << left << soSanPham;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

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

class NhanVienVanPhong : public NhanVien
{
private:
    int soNG;

public:
    NhanVienVanPhong(int maNV, string hoTen, long long luongCoBan, int soNG) : NhanVien(maNV, hoTen, luongCoBan)
    {
        this->soNG = soNG;
    }
    void inThongTin();
    void tinhLuong();
};

void NhanVienVanPhong ::inThongTin()
{
    cout << setw(20) << left << maNV;
    cout << setw(20) << left << hoTen;
    cout << setw(20) << left << luongCoBan;
    cout << setw(20) << left << soNG;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

void NhanVienVanPhong ::tinhLuong()
{
    luongHangThang = luongCoBan + soNG * 25000;
    if (soNG < 15)
    {
        luongHangThang += luongHangThang * 0.2;
    }
}

class CongTy
{
private:
    string tenCT;
    int MaCT;
    vector<NhanVien *> danhSachNV;
    int soNVVP;
    int soNVSX;

public:
    CongTy()
    {
        tenCT = "ABC";
        MaCT = 123;
        soNVSX = soNVVP = 0;
    }
    void loadData();                             // 1. Tao du lieu nhan vien
    void inDanhSachNhanVien();                      // 2. Xuat cac nhan vien trong cong ty
    void tinhLuong();                               // 3. Tinh luong nhan vien
    vector<NhanVien *> timNhanVienLuongCaoNhat();   // 4. Tim nhan vien luong cao nhat
    NhanVien *timNhanVienTheoMaNhanVien();          // 6. Tim nhan vien theo ma nhan vien
    void capNhatLuongCoBan();                       // 5. Cap nhat luong co ban
    vector<NhanVien *> timNhanVienCoSoSPThapNhat(); // 7. Tim nhan vien co so san pham thap nhat
    vector<NhanVien *> timTop10NVLuongCaoNhat();    // 8. Top 10 nhan vien luong cao nhat
};

void CongTy ::loadData()
{
    srand(time(0));
    vector<string> danhSachTen = {
        "Hoa My Nguyen", "Quoc Trung Tran", "Thu Huong Hoang", "Bao Ngoc Le", "Minh Tu Nguyen",
        "Anh Tuan Pham", "Van Anh Tran", "Thi Thuy Linh", "Minh Triet Vo", "Thi Hong Nguyen",
        "Quang Minh Le", "Huong Lan Phan", "Van Thanh Nguyen", "Bao Anh Le", "Thi Thu Ha",
        "Trung Hieu Nguyen", "Hai Dang Vo", "Ngoc Trang Le", "Tien Minh Tran", "Quoc Bao Nguyen",
        "Van Khanh Ho", "Thi Thuy Linh", "Tuan Anh Nguyen", "Minh Phuong Tran", "Van Tien Pham",
        "Trung Hau Le", "Thi Thu Huong", "Bao Trang Tran", "Minh Hoang Vo", "Quang Minh Hoang"};
    for (int i = 0; i < 10; i++)
    {
        danhSachNV.push_back(new NhanVienVanPhong(23000 + i, danhSachTen[i], 4000000, rand() % 30 + 5));
        soNVVP++;
    }

    for (int i = 10; i < 30; i++)
    {
        danhSachNV.push_back(new NhanVienSanXuat(23000 + i, danhSachTen[i], 4000000, rand() % 100 + 50));
        soNVSX++;
    }
}

void CongTy ::inDanhSachNhanVien()
{
    cout << "            ==========================================================" << endl;
    cout << "            =               DANH SACH NHAN VIEN VAN PHONG            =" << endl;
    cout << "            ==========================================================" << endl;
    cout << setw(20) << left << "Ma NV: ";
    cout << setw(20) << left << "Ho ten: ";
    cout << setw(20) << left << "Luong Can Ban: ";
    cout << setw(20) << left << "So ngay lam viec: ";
    cout << setw(20) << left << "Luong hang thang: ";
    cout << endl;
    for (int i = 0; i < soNVVP; i++)
    {
        danhSachNV[i]->inThongTin();
    }

    cout << "            ==========================================================" << endl;
    cout << "            =               DANH SACH NHAN ViEN SAN XUAT             =" << endl;
    cout << "            ==========================================================" << endl;
    cout << setw(20) << left << "Ma NV: ";
    cout << setw(20) << left << "Ho ten: ";
    cout << setw(20) << left << "Luong Can Ban: ";
    cout << setw(20) << left << "So san pham: ";
    cout << setw(20) << left << "Luong hang thang: ";
    cout << endl;
    for (int i = soNVVP; i < soNVSX; i++)
    {
        danhSachNV[i]->inThongTin();
    }
}

void CongTy::tinhLuong()
{
    for (int i = 0; i < danhSachNV.size(); i++)
    {
        danhSachNV[i]->tinhLuong();
    }
}

vector<NhanVien *> CongTy ::timNhanVienLuongCaoNhat()
{
    vector<NhanVien *> result;
    double maxLuong = 0;
    for (int i = 0; i < danhSachNV.size(); i++)
    {
        if (danhSachNV[i]->getLuongHangThang() > maxLuong)
        {
            maxLuong = danhSachNV[i]->getLuongHangThang();
        }
    }
    for (int i = 0; i < danhSachNV.size(); i++)
    {
        if (danhSachNV[i]->getLuongHangThang() == maxLuong)
        {
            result.push_back(danhSachNV[i]);
        }
    }
    return result;
}

int main()
{
    CongTy AA;
    AA.loadData();
    AA.tinhLuong();
    AA.inDanhSachNhanVien();
}
