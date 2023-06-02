#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
protected:
    int maNV;
    string hoTen;
    long long luongCB;
    long long luongHT;

public:
    NhanVien();
    NhanVien(int, string, long long);
    int getmaNV() const;
    string getHoTen() const;
    long long getLuongCB() const;
    void setLuongCB(long long);
    virtual long long tinhLuong() = 0;
    virtual void xuat() const
    {
        cout << "\t+Ma nhan vien: " << maNV << endl;
        cout << "\t+Ho va ten: " << hoTen << endl;
        cout << "\t+Luong co ban: " << luongCB << endl;
    }
};

NhanVien ::NhanVien()
{
    maNV = 0;
    hoTen = "";
    luongCB = luongHT = 0;
}

NhanVien ::NhanVien(int maNV, string hoTen, long long luongCB) : maNV(maNV), hoTen(hoTen), luongCB(luongCB), luongHT(0) {}

int NhanVien ::getmaNV() const
{
    return maNV;
}

string NhanVien ::getHoTen() const
{
    return hoTen;
}

long long NhanVien ::getLuongCB() const
{
    return luongCB;
}

void NhanVien ::setLuongCB(long long luongCB)
{
    this->luongCB = luongCB;
}

class LapTrinhVien : public NhanVien
{
private:
    int gioTC;

public:
    LapTrinhVien();
    LapTrinhVien(int, string, long long, int);
    ~LapTrinhVien();
    void xuat() const override;
    long long tinhLuong() override;
};

LapTrinhVien ::LapTrinhVien() : NhanVien()
{
    gioTC = 0;
}

LapTrinhVien ::LapTrinhVien(int maNV, string hoTen, long long luongCB, int gioTC) : NhanVien(maNV, hoTen, luongCB)
{
    this->gioTC = gioTC;
}

LapTrinhVien ::~LapTrinhVien() {}

void LapTrinhVien ::xuat() const
{
    cout << "\nThong tin lap trinh vien: \n";
    NhanVien ::xuat();
    cout << "\t+So gio tang ca: " << gioTC << endl;
    cout << "\t+Luong hang thang: " << luongHT << endl;
}

long long LapTrinhVien ::tinhLuong()
{
    luongHT = luongCB + gioTC * 250000;
    return luongHT;
}

class PhanTichVien : public NhanVien
{
private:
    int gioTC;
    long long phuCap;

public:
    PhanTichVien();
    PhanTichVien(int, string, long long, int, long long);
    ~PhanTichVien();
    void xuat() const override;
    long long tinhLuong() override;
};

PhanTichVien ::PhanTichVien() : NhanVien()
{
    gioTC = 0;
    phuCap = 0;
}

PhanTichVien ::PhanTichVien(int maNV, string hoTen, long long luongCB, int gioTC, long long phuCap) : NhanVien(maNV, hoTen, luongCB)
{
    this->gioTC = gioTC;
    this->phuCap = phuCap;
}

PhanTichVien ::~PhanTichVien() {}

void PhanTichVien ::xuat() const
{
    cout << "\nThong tin phan tich vien: \n";
    NhanVien ::xuat();
    cout << "\t+Gio tang ca: " << gioTC << endl;
    cout << "\t+Phu cap: " << phuCap << endl;
    cout << "\t+Luong hang thang: " << luongHT << endl;
}

long long PhanTichVien ::tinhLuong()
{
    luongHT = (luongCB + gioTC * 250000) * 1.8;
    return luongHT;
}

class NhanVienKiemThu : public NhanVien
{
private:
    int soLoi;

public:
    NhanVienKiemThu();
    NhanVienKiemThu(int, string, long long, int);
    ~NhanVienKiemThu();
    void xuat() const override;
    long long tinhLuong() override;
};

NhanVienKiemThu ::NhanVienKiemThu() : NhanVien()
{
    soLoi = 0;
}

NhanVienKiemThu ::NhanVienKiemThu(int maNV, string hoTen, long long luongCB, int soLoi) : NhanVien(maNV, hoTen, luongCB)
{
    this->soLoi = soLoi;
}

NhanVienKiemThu ::~NhanVienKiemThu() {}

void NhanVienKiemThu ::xuat() const
{
    cout << "\nThong tin nhan vien kiem thu: \n";
    NhanVien ::xuat();
    cout << "\t+So loi phat hien: " << soLoi << endl;
    cout << "\t+Luong hang thang: " << luongHT << endl;
}

long long NhanVienKiemThu ::tinhLuong()
{
    luongHT = luongCB + soLoi * 85000;
    return luongHT;
}

class CongTy
{
private:
    string tenCT;
    string maCT;
    vector<NhanVien *> danhSachNV;

public:
    CongTy();
    CongTy(string, string);
    ~CongTy();
    void loadData();                        // Cau 1. Khoi tao danh sach nhan vien
    void xuat() const;                      // Cau 2. Xuat danh sach nhan vien
    void tinhLuong();                       // Tinh luong cho nhan vien
    long long tinhLuongTB();                // Tinh luong trung binh cua tat ca nhan vien
    vector<NhanVien *> NV();                // Cau 3. Danh sach nhan vien co luong thap hon luong trung binh
    vector<NhanVien *> NVLuongCaoNhat();    // Cau 4. Nhan vien luong cao nhat
    vector<NhanVien *> NVLuongThapNhat();   // Cau 5. Nhan vien luong thap nhat
    vector<NhanVien *> LTVLuongCaoNhat();   // Cau 6. Lap trinh vien co luong cao nhat
    vector<NhanVien *> NVKTLuongThapNhat(); // Cau 7. Nhan vien kiem thu luong thap nhat
    bool capNhatLuongCB(int, long long);    // Cau 8. Cap nhat luong co ban theo ma nhan vien
};

CongTy ::CongTy() {}
CongTy ::CongTy(string ten, string ma) : tenCT(ten), maCT(ma) {}
CongTy ::~CongTy() {}

// Cau 1. Khoi tao danh sach nhan vien
void CongTy ::loadData()
{
    // Thong tin lap trinh vien
    danhSachNV.push_back(new LapTrinhVien(101, "Nguyen A", 4500000, 10));
    danhSachNV.push_back(new LapTrinhVien(102, "Nguyen B", 6870000, 20));
    danhSachNV.push_back(new LapTrinhVien(103, "Nguyen C", 3500000, 15));
    danhSachNV.push_back(new LapTrinhVien(104, "Nguyen D", 7500000, 12));

    // Thong tin phan tich vien
    danhSachNV.push_back(new PhanTichVien(201, "Nguyen E", 3400000, 16, 520000));
    danhSachNV.push_back(new PhanTichVien(201, "Nguyen F", 5300000, 17, 430000));
    danhSachNV.push_back(new PhanTichVien(201, "Nguyen G", 4300000, 12, 200000));
    danhSachNV.push_back(new PhanTichVien(201, "Nguyen H", 5400000, 23, 500000));

    // Thong tin nhan vien kiem thu
    danhSachNV.push_back(new NhanVienKiemThu(301, "Nguyen I", 4200000, 13));
    danhSachNV.push_back(new NhanVienKiemThu(301, "Nguyen J", 4000000, 14));
    danhSachNV.push_back(new NhanVienKiemThu(301, "Nguyen K", 6000000, 12));
    danhSachNV.push_back(new NhanVienKiemThu(301, "Nguyen L", 7000000, 10));
}

// Cau 2. Xuat danh sach nhan vien
void CongTy ::xuat() const
{
    cout << "\t \t THONG TIN NHAN VIEN CONG TY " << tenCT << endl;
    for (auto x : danhSachNV)
    {
        x->xuat();
    }
}
// Tinh luong cho nhan vien
void CongTy ::tinhLuong()
{
    for (auto x : danhSachNV)
    {
        x->tinhLuong();
    }
}

// Tinh luong trung binh cua tat ca nhan vien
long long CongTy ::tinhLuongTB()
{
    long long tongLuong, luongTB;
    tongLuong = 0;
    for (auto x : danhSachNV)
    {
        tongLuong += x->tinhLuong();
    }
    luongTB = tongLuong / danhSachNV.size();
    return luongTB;
}

// Cau 3. Danh sach nhan vien co luong thap hon luong trung binh
vector<NhanVien *> CongTy ::NV()
{
    vector<NhanVien *> nv;
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() < tinhLuongTB())
        {
            nv.push_back(x);
        }
    }
    return nv;
}

// Cau 4. Nhan vien luong cao nhat
vector<NhanVien *> CongTy ::NVLuongCaoNhat()
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

// Cau 5. Nhan vien luong thap nhat
vector<NhanVien *> CongTy ::NVLuongThapNhat()
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

// Cau 6. Lap trinh vien co luong cao nhat
vector<NhanVien *> CongTy ::LTVLuongCaoNhat()
{
    long long maxLuong = INT_MIN;
    vector<NhanVien *> nv;
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() > maxLuong && dynamic_cast<LapTrinhVien *>(x))
        {
            maxLuong = x->tinhLuong();
        }
    }
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() == maxLuong && dynamic_cast<LapTrinhVien *>(x))
        {
            nv.push_back(x);
        }
    }
    return nv;
}

// Cau 7. Nhan vien kiem thu luong thap nhat
vector<NhanVien *> CongTy ::NVKTLuongThapNhat()
{
    long long minLuong = INT_MAX;
    vector<NhanVien *> nv;
    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() < minLuong && dynamic_cast<NhanVienKiemThu *>(x))
        {
            minLuong = x->tinhLuong();
        }
    }

    for (auto x : danhSachNV)
    {
        if (x->tinhLuong() == minLuong && dynamic_cast<NhanVienKiemThu *>(x))
        {
            nv.push_back(x);
        }
    }
    return nv;
}

// Cau 8. Cap nhat luong co ban theo ma nhan vien
bool CongTy ::capNhatLuongCB(int ma, long long luong)
{
    for (auto x : danhSachNV)
    {
        if (x->getmaNV())
        {
            x->setLuongCB(luong);
            return 1;
        }
    }
    return 0;
}

int main()
{
    CongTy MTV("TNHH MTV", "S102");
    MTV.loadData();
    MTV.tinhLuong();
    MTV.xuat();

    cout << "\n      NHAN VIEN CO LUONG THAP HON MUC LUONG TRUNG BINH \n";
    vector<NhanVien *> nv;
    nv = MTV.NV();
    for (auto x : nv)
    {
        x->xuat();
    }

    cout << "\n      NHAN VIEN CO LUONG CAO NHAT \n";
    nv = MTV.NVLuongCaoNhat();
    for (auto x : nv)
    {
        x->xuat();
    }

    cout << "\n      NHAN VIEN CO LUONG THAP NHAT \n";
    nv = MTV.NVLuongThapNhat();
    for (auto x : nv)
    {
        x->xuat();
    }

    cout << "\n      LAP TRINH VIEN CO LUONG CAO NHAT \n";
    nv = MTV.LTVLuongCaoNhat();
    for (auto x : nv)
    {
        x->xuat();
    }

    cout << "\n      NHAN VIEN KIEM THU CO LUONG THAP NHAT\n";
    nv = MTV.NVKTLuongThapNhat();
    for (auto x : nv)
    {
        x->xuat();
    }
}