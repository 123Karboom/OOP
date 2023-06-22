#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
protected:
    int maNV;
    string hoTen;
    long long luongCoBan;
    long long luongHT;

public:
    NhanVien()
    {
        maNV = 0;
        luongCoBan = 0;
        luongHT = 0;
        hoTen = "";
    }
    NhanVien(int maNV, string hoTen, long long luongCoBan)
    {
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->luongCoBan = luongCoBan;
        this->luongHT = 0;
    }
    virtual void xuat() const
    {
        cout << "\t+Ho va ten: " << hoTen << endl;
        cout << "\t+Ma nhan vien: " << maNV << endl;
        cout << "\t+Luong co ban: " << luongCoBan << endl;
        cout << "\t+Luong hang thang: " << luongHT << endl;
    }
    virtual long long tinhLuong() = 0;
    int getMaNV() const
    {
        return maNV;
    }
    long long getLuongCoBan() const
    {
        return luongCoBan;
    }
    void setLuongCoBan(long long luongCB)
    {
        this->luongCoBan = luongCB;
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    int thoiGian;
    long long troCap;

public:
    NhanVienVanPhong() : NhanVien()
    {
        thoiGian = 0;
    }
    NhanVienVanPhong(int maNV, string hoTen, long long luongCoBan, int thoiGian) : NhanVien(maNV, hoTen, luongCoBan)
    {
        this->thoiGian = thoiGian;
    }
    void xuat() const override
    {
        cout << "\n Thong tin nhan vien van phong: \n";
        NhanVien ::xuat();
        cout << "\t+So gio lam: " << thoiGian << endl;
    }
    long long tinhLuong() override
    {
        if (thoiGian >= 100)
        {
            luongHT = luongCoBan + thoiGian * 220000 + 5000000;
        }
        else
        {
            luongHT = luongCoBan * thoiGian;
        }
        return luongHT;
    }
};

class NhanVienSanXuat : public NhanVien
{
private:
    int soSP;

public:
    NhanVienSanXuat() : NhanVien()
    {
        this->soSP = 0;
    }
    NhanVienSanXuat(int maNV, string hoTen, long long luongCoBan, int soSP) : NhanVien(maNV, hoTen, luongCoBan)
    {
        this->soSP = soSP;
    }
    void xuat() const override
    {
        cout << "\nThong tin nhan vien san xuat \n";
        NhanVien ::xuat();
        cout << "\t+So san pham: " << soSP << endl;
    }
    long long tinhLuong() override
    {
        luongHT = luongCoBan + soSP * 175000;
        if (soSP > 150)
        {
            luongHT += luongHT * 0.2;
        }
        return luongHT;
    }
};

class NhanVienQuanLy : public NhanVien
{
private:
    float heSoCV;
    long long thuong;

public:
    NhanVienQuanLy() : NhanVien()
    {
        heSoCV = 0.0;
        thuong = 0;
    }
    NhanVienQuanLy(int maNV, string hoTen, long long luongCoBan, float heSoCV, long long thuong) : NhanVien(maNV, hoTen, luongCoBan)
    {
        this->heSoCV = heSoCV;
        this->thuong = thuong;
    }
    void xuat() const override
    {
        cout << "\nThong tin nhan vien quan ly\n";
        NhanVien ::xuat();
        cout << "\t+He so chuc vu: " << heSoCV << endl;
    }
    long long tinhLuong()
    {
        luongHT = luongCoBan * heSoCV + thuong;
        return luongHT;
    }
};

class CongTy
{
private:
    int maCT;
    string tenCT;
    vector<NhanVien *> danhSachNV;

public:
    CongTy() {}
    CongTy(int maCT, string tenCT)
    {
        this->maCT = maCT;
        this->tenCT = tenCT;
    }
    void loadDaTa();                              // Cau 1. Khoi tao du lieu
    void xuatDaTa() const;                        // const // Cau 2. Xuat du lieu
    void tinhLuongHT();                           // Cau 3. Tinh luong cho tung nhan vien
    NhanVien *timNV(int ma);                      // Cau 4. Tim kiem nhan vien theo0 maNV
    long long tinhLuongTB();                      // Cau 5. Tinh luong trung binh hang thang ma dai ly phai tra cho nhan vien
    bool capNhatLuongCB(int ma, long long luong); // Cau 6. Cap nhat luong co ban theo ma nhan vien
    vector<NhanVien *> NVLuongCBCaoNhat();        // Cau 7. Tim nhan vien luong co ban cao nhat
    vector<NhanVien *> NVSXLuongCBCaoNhat();      // Cau 8. Tim nhan vien san xuat co luong co ban cao nhat
    vector<NhanVien *> NVLuongCBThapNhat();       // Cau 9. Tim nhan vien luong co ban thap nhat
};

// Cau 1. Khoi tao du lieu
void CongTy ::loadDaTa()
{
    // Them nhan vien van phong
    danhSachNV.push_back(new NhanVienVanPhong(101, "A", 4500000, 200));
    danhSachNV.push_back(new NhanVienVanPhong(102, "B", 5600000, 100));
    danhSachNV.push_back(new NhanVienVanPhong(103, "C", 8900000, 90));

    // Them nhan vien san xuat
    danhSachNV.push_back(new NhanVienSanXuat(201, "D", 7800000, 250));
    danhSachNV.push_back(new NhanVienSanXuat(202, "E", 4500000, 110));
    danhSachNV.push_back(new NhanVienSanXuat(203, "F", 6600000, 360));

    // Them nhan vien quan ly;
    danhSachNV.push_back(new NhanVienQuanLy(301, "G", 8500000, 1.3, 19500000));
    danhSachNV.push_back(new NhanVienQuanLy(302, "H", 7600000, 1.2, 18600000));
}

// const // Cau 2. Xuat du lieu
void CongTy ::xuatDaTa() const
{
    for (auto x : danhSachNV)
    {
        x->xuat();
    }
}

// Cau 3. Tinh luong cho tung nhan vien
void CongTy ::tinhLuongHT()
{
    for (auto x : danhSachNV)
    {
        x->tinhLuong();
    }
}

// Cau 4. Tim kiem nhan vien theo0 maNV
NhanVien *CongTy ::timNV(int ma)
{
    for (auto x : danhSachNV)
    {
        if (x->getMaNV() == ma)
            return x;
    }
    return NULL;
}

// Cau 5. Tinh luong trung binh hang thang ma dai ly phai tra cho nhan vien
long long CongTy ::tinhLuongTB()
{
    long long luongTB = 0;
    for (auto x : danhSachNV)
    {
        luongTB += x->tinhLuong();
    }
    luongTB = luongTB / danhSachNV.size();
    return luongTB;
}

// Cau 6. Cap nhat luong co ban theo ma nhan vien
bool CongTy ::capNhatLuongCB(int ma, long long luong)
{
    for (auto x : danhSachNV)
    {
        if (x->getMaNV() == ma)
        {
            x->setLuongCoBan(luong);
            return 1;
        }
    }
    return 0;
}

// Cau 7. Tim nhan vien luong co ban cao nhat
vector<NhanVien *> CongTy ::NVLuongCBCaoNhat()
{
    long long maxLuong = INT_MIN;
    vector<NhanVien *> nv;
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() > maxLuong)
        {
            maxLuong = x->tinhLuong();
        }
    }
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() == maxLuong)
        {
            nv.push_back(x);
        }
    }
    return nv;
}

// Cau 8. Tim nhan vien san xuat co luong co ban cao nhat
vector<NhanVien *> CongTy ::NVSXLuongCBCaoNhat()
{
    long long maxLuong = INT_MIN;
    vector<NhanVien *> nv;
    for (auto x : nv)
    {
        if (x->getLuongCoBan() > maxLuong && dynamic_cast<NhanVienSanXuat *>(x))
        {
            maxLuong = x->getLuongCoBan();
        }
    }
    for (auto x : nv)
    {
        if (x->getLuongCoBan() == maxLuong && dynamic_cast<NhanVienSanXuat *>(x))
        {
            nv.push_back(x);
        }
    }
    return nv;
}

// Cau 9. Tim nhan vien luong co ban thap nhat
vector<NhanVien *> CongTy ::NVLuongCBThapNhat()
{
    long long minLuong = INT_MAX;
    vector<NhanVien *> nv;
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() < minLuong)
        {
            minLuong = x->tinhLuong();
        }
    }

    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() == minLuong)
        {
            nv.push_back(x);
        }
    }
    return nv;
}

int main()
{
    CongTy ABC;
    ABC.loadDaTa();
    ABC.tinhLuongHT();
    ABC.xuatDaTa();
}
