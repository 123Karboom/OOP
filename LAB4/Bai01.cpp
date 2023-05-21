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
    NhanVien();
    NhanVien(int maNV, string hoTen, long long luongCoBan);
    ~NhanVien();
    // Constructor & destructor
    virtual void tinhLuong() = 0; // Hàm tính lương ảo
    virtual void inThongTin()     // In thông tin nhân viên
    {
        cout << setw(20) << left << maNV;
        cout << setw(20) << left << hoTen;
        cout << setw(20) << left << luongCoBan;
    };
    string gethoTen(); // Lấy họ tên
    int getMaNV();     // Lấy mã nhân viên
    long long getLuongCoBan();
    long long getLuongHangThang();                // Lấy lương hàng tháng
    void capNhatLuongCoBan(long long luongCoBan); // Cập nhật lương cơ bản cho nhân viên
};

NhanVien ::NhanVien()
{
    maNV = 0;
    hoTen = "";
    luongCoBan = 0.0;
    luongHangThang = 0.0;
}

NhanVien ::NhanVien(int maNV, string hoTen, long long luongCoBan)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->luongCoBan = luongCoBan;
    this->luongHangThang = 0.0;
}
// Constructor

NhanVien ::~NhanVien() {} // Destructor

// Lấy họ tên
string NhanVien ::gethoTen()
{
    return hoTen;
}

// Lấy mã nhân viên
int NhanVien ::getMaNV()
{
    return maNV;
}

// Lấy lương cơ bản
long long NhanVien ::getLuongCoBan()
{
    return luongCoBan;
}

// Lấy lương hàng tháng
long long NhanVien ::getLuongHangThang()
{
    return luongHangThang;
}

// Cập nhật lương cơ bản
void NhanVien ::capNhatLuongCoBan(long long luongCoBan)
{
    this->luongCoBan = luongCoBan;
}

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

NhanVienSanXuat ::NhanVienSanXuat() : NhanVien()
{
    soSanPham = 0;
}

NhanVienSanXuat ::NhanVienSanXuat(int maNV, string hoTen, long long luongCoBan, int soSanPham) : NhanVien(maNV, hoTen, luongCoBan)
{
    this->soSanPham = soSanPham;
}

// Constructor
NhanVienSanXuat ::~NhanVienSanXuat() {}

// In thông tin
void NhanVienSanXuat ::inThongTin()
{
    NhanVien ::inThongTin();
    cout << setw(20) << left << soSanPham;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

// Tính lương
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

int NhanVienSanXuat ::getSoSP()
{
    return soSanPham;
}

class NhanVienVanPhong : public NhanVien
{
private:
    int soNG;

public:
    NhanVienVanPhong();
    NhanVienVanPhong(int maNV, string hoTen, long long luongCoBan, int soNG);
    // Constructor
    ~NhanVienVanPhong(); // Destructor
    void inThongTin();   // In thông tin
    void tinhLuong();    // Tính lương
    int getSoNG();
};

NhanVienVanPhong ::NhanVienVanPhong() : NhanVien()
{
    soNG = 0;
}

NhanVienVanPhong ::NhanVienVanPhong(int maNV, string hoTen, long long luongCoBan, int soNG) : NhanVien(maNV, hoTen, luongCoBan)
{
    this->soNG = soNG;
}
// Constructor

NhanVienVanPhong ::~NhanVienVanPhong() {} // Destructor

// In thông tin
void NhanVienVanPhong ::inThongTin()
{
    NhanVien ::inThongTin();
    cout << setw(20) << left << soNG;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

// Tính lương
void NhanVienVanPhong ::tinhLuong()
{
    luongHangThang = luongCoBan + soNG * 25000;
    if (soNG < 15)
    {
        luongHangThang += luongHangThang * 0.2;
    }
}

int NhanVienVanPhong ::getSoNG()
{
    return soNG;
}

class CongTy
{
private:
    string tenCT;
    int MaCT;
    vector<NhanVien *> danhSachNV;
    vector<NhanVienVanPhong *> danhSachNVVP;
    vector<NhanVienSanXuat *> danhSachNVSX;
    int soNVVP;
    int soNVSX;

public:
    CongTy()
    {
        tenCT = "ABC";
        MaCT = 123;
        soNVSX = soNVVP = 0;
    }
    void loadData(int a, int b);                           // 1. Tao du lieu nhan vien
    void inDanhSachNhanVien() const;                       // 2. Xuat cac nhan vien trong cong ty
    void tinhLuong();                                      // 3. Tinh luong nhan vien
    bool timNhanVienTheoMaNhanVien(int ma, NhanVien *&NV); // 4. Tim nhan vien theo ma nhan vien
    void capNhatLuongCoBan(int ma, long long luong);          // 5. Cap nhat luong co ban
    vector<NhanVien *> NhanVienLuongCaoNhat();             // 6. Tim nhan vien luong cao nhat
    vector<NhanVienSanXuat *> NhanVienCoSoSPThapNhat();    // 7. Tim nhan vien co so san pham thap nhat
    vector<NhanVien *> Top10NVLuongCaoNhat();              // 8. Top 10 nhan vien luong cao nhat
};

// 1. Tao du lieu nhan vien
void CongTy ::loadData(int a, int b)
{
    srand(time(0));
    vector<string> danhSachTen = {
        "Hoa My Nguyen", "Quoc Trung Tran", "Thu Huong Hoang", "Bao Ngoc Le", "Minh Tu Nguyen",
        "Anh Tuan Pham", "Van Anh Tran", "Thi Thuy Linh", "Minh Triet Vo", "Thi Hong Nguyen",
        "Quang Minh Le", "Huong Lan Phan", "Van Thanh Nguyen", "Bao Anh Le", "Thi Thu Ha",
        "Trung Hieu Nguyen", "Hai Dang Vo", "Ngoc Trang Le", "Tien Minh Tran", "Quoc Bao Nguyen",
        "Van Khanh Ho", "Thi Thuy Linh", "Tuan Anh Nguyen", "Minh Phuong Tran", "Van Tien Pham",
        "Trung Hau Le", "Thi Thu Huong", "Bao Trang Tran", "Minh Hoang Vo", "Quang Minh Hoang"};
    soNVVP = a;
    soNVSX = b;
    for (int i = 0; i < soNVVP; i++)
    {
        NhanVienVanPhong *NVVP = new NhanVienVanPhong(23000 + i, danhSachTen[i % 30], 4000000, rand() % 30 + 5);
        danhSachNV.push_back(NVVP);
        danhSachNVVP.push_back(NVVP);
    }

    for (int i = 0; i < soNVSX; i++)
    {
        NhanVienSanXuat *NVSX = new NhanVienSanXuat(24000 + i, danhSachTen[i % 30], 4000000, rand() % 100 + 50);
        danhSachNV.push_back(NVSX);
        danhSachNVSX.push_back(NVSX);
    }
}

// 2. Xuat cac nhan vien trong cong ty
void CongTy ::inDanhSachNhanVien() const
{
    if (danhSachNV.empty())
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =               DANH SACH NHAN VIEN VAN PHONG            =" << endl;
    cout << "            ==========================================================" << endl;
    cout << setw(20) << left << "Ma NV: ";
    cout << setw(20) << left << "Ho ten: ";
    cout << setw(20) << left << "Luong Can Ban: ";
    cout << setw(20) << left << "So ngay lam viec: ";
    cout << setw(20) << left << "Luong hang thang: ";
    cout << endl;
    for (int i = 0; i < danhSachNVVP.size(); i++)
    {
        danhSachNVVP[i]->inThongTin();
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
    for (int i = 0; i < danhSachNVSX.size(); i++)
    {
        danhSachNVSX[i]->inThongTin();
    }
}

// 3. Tính lương cho các nhân viên
void CongTy::tinhLuong()
{
    for (int i = 0; i < danhSachNV.size(); i++)
    {
        danhSachNV[i]->tinhLuong();
    }
}

/*
4. Tìm nhân viên theo mã nhân viên
Input:
    + ma (mã nhân viên)
    + NV (con trỏ NV dùng để lưu thông tin nhân viên tìm được)
    + thuộc tính danhSachNV
Output:
    + true (tìm thấy), false (ko thấy)
*/
bool CongTy ::timNhanVienTheoMaNhanVien(int ma, NhanVien *&NV)
{
    for (int i = 0; i < danhSachNV.size(); i++)
    {
        if (danhSachNV[i]->getMaNV() == ma)
        {
            NV = danhSachNV[i];
            return true;
        }
    }
    return false;
}

// 5. Cập nhật lương cơ bản theo mã nhân viên
void CongTy ::capNhatLuongCoBan(int ma, long long luong)
{
    for (int i = 0; i < danhSachNV.size(); i++)
    {
        if (danhSachNV[i]->getMaNV() == ma)
        {
            danhSachNV[i]->capNhatLuongCoBan(luong);
            cout << "Cap nhat luong thanh cong ! \n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma: " << ma << endl;
}

/* 6. Tim nhan vien luong cao nhat
Input:
    +thuộc tính danhSachNV
Output:
    +return reslt (danh sách gồm những nhân viên có lương cao nhất)
*/
vector<NhanVien *> CongTy ::NhanVienLuongCaoNhat()
{
    vector<NhanVien *> result;
    long long maxLuong = 0;
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

/*
7. Tìm nhân viên có số sản phẩm bán được thấp nhất
Input:
    +thuộc tính danhSachNVSX
Output:
    + return result (danh sách gồm các nhân viên có số sản phẩm bán thấp nhất)
*/
vector<NhanVienSanXuat *> CongTy ::NhanVienCoSoSPThapNhat()
{
    vector<NhanVienSanXuat *> result;
    int minSP = danhSachNVSX[0]->getSoSP();
    for (int i = 0; i < danhSachNVSX.size(); i++)
    {
        if (danhSachNVSX[i]->getSoSP() < minSP)
            minSP = danhSachNVSX[i]->getSoSP();
    }

    for (int i = 0; i < danhSachNVSX.size(); i++)
    {
        if (danhSachNVSX[i]->getSoSP() == minSP)
            result.push_back(danhSachNVSX[i]);
    }
    return result;
}

/*
8. Top 10 nhân viên lương cao nhất
Input:
    + thuộc tính danhSachNV;
Output:
    + return Top10 (danh sách chứa 10 nhân viên lương cao nhất)
*/
vector<NhanVien *> CongTy ::Top10NVLuongCaoNhat()
{
    vector<NhanVien *> Top10;
    sort(danhSachNV.begin(), danhSachNV.end(), [](NhanVien *&a, NhanVien *&b)
         { return a->getLuongHangThang() > b->getLuongHangThang(); });
    for (int i = 0; i < 10; i++)
    {
        Top10.push_back(danhSachNV[i]);
    }
    return Top10;
}

static CongTy FPT;

// 1. Tạo dữ liệu công ty
void taoDulieuCT()
{
    int a, b;
    cout << "Nhap so luong nhan vien van phong: ";
    cin >> a;
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> b;
    FPT.loadData(a, b);
    cout <<"Tao du lieu thanh cong ! \n";
}

// 2. Xuất các nhân viên trong công ty
void xuatDanhSach()
{
    FPT.inDanhSachNhanVien();
}

//3. Tính lương nhân viên trong công ty
void tinhLuong()
{
    FPT.tinhLuong();
}

//4. Tìm nhân viên theo mã nhân viên
void timNhanVien()
{
    int maNV;
    NhanVien *NV;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> maNV;
    if (FPT.timNhanVienTheoMaNhanVien(maNV, NV))
    {
        cout << "Tim thay nhan vien ! \n";
        cout << "Thong tin nhan vien: \n";
        cout << "    +Ma nhan vien: " << NV->getMaNV() << endl;
        cout << "    +Ho ten: " << NV->gethoTen() << endl;
        cout << "    +Luong co ban: " << NV->getLuongCoBan() << endl;
    }
    else
        cout << "Khong tim thay nhan vien co ma: " << maNV << endl;
}

// 5. Cập nhật lương cơ bản theo mã nhân viên
void capNhatLuongCoBan()
{
    long long luong;
    int ma;
    cout << "Nhap ma nhan vien can cap nhat luong: ";
    cin >> ma;
    cout << "Luong cap nhat: ";
    cin >> luong;
    FPT.capNhatLuongCoBan(ma, luong);
}

//6. Tìm nhân viên lương cao nhất
void timNhanVienLuongCaoNhat()
{
    cout << "            ==========================================================" << endl;
    cout << "            =            DANH SACH NHAN VIEN LUONG CAO NHAT          =" << endl;
    cout << "            ==========================================================" << endl;
    vector<NhanVien *> ans;
    ans = FPT.NhanVienLuongCaoNhat();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Thong tin nhan vien: \n";
        cout << "    +Ma nhan vien: " << ans[i]->getMaNV() << endl;
        cout << "    +Ho ten: " << ans[i]->gethoTen() << endl;
        cout << "    +Luong co ban: " << ans[i]->getLuongCoBan() << endl;
        cout << "    +Luong hang thang: " << ans[i]->getLuongHangThang() << endl;
    }
}

// 7. Tìm nhân viên có số sản phẩm bán được thấp nhất
void timNhanVienCoSoSPThapNhat()
{
    vector<NhanVienSanXuat *> ans;
    ans = FPT.NhanVienCoSoSPThapNhat();
    cout << "            ==========================================================" << endl;
    cout << "            = DANH SACH NHAN VIEN CO SO SAN PHAM BAN DUOC THAP NHAT  =" << endl;
    cout << "            ==========================================================" << endl;
    cout << setw(20) << left << "Ma NV: ";
    cout << setw(20) << left << "Ho ten: ";
    cout << setw(20) << left << "Luong Can Ban: ";
    cout << setw(20) << left << "So san pham: ";
    cout << setw(20) << left << "Luong hang thang: ";
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i]->inThongTin();
    }
}

// 8. Tìm 10 nhân viên có lương cao nhất
void timTop10NhanVienLuongCaoNhat()
{
    cout << "            ==========================================================" << endl;
    cout << "            =          DANH SACH 10 NHAN VIEN LUONG CAO NHAT         =" << endl;
    cout << "            ==========================================================" << endl;
    vector<NhanVien *> ans;
    ans = FPT.Top10NVLuongCaoNhat();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Thong tin nhan vien: \n";
        cout << "    +Ma nhan vien: " << ans[i]->getMaNV() << endl;
        cout << "    +Ho ten: " << ans[i]->gethoTen() << endl;
        cout << "    +Luong co ban: " << ans[i]->getLuongCoBan() << endl;
        cout << "    +Luong hang thang: " << ans[i]->getLuongHangThang() << endl;
        cout << endl;
    }
}

int main()
{
    int choice; // Biến lưu lựa chọn của người dùng

    do
    {
        // Hiển thị menu
        cout << "==============================================" << endl;
        cout << "                     MENU                     " << endl;
        cout << "==============================================" << endl;
        cout << "1. Tao du lieu" << endl;
        cout << "2. Hien thi danh sach nhan vien" << endl;
        cout << "3. Tinh luong nhan vien" << endl;
        cout << "4. Tim nhan vien theo ma" << endl;
        cout << "5. Cap nhat luong co ban nhan vien theo ma" << endl;
        cout << "6. Tim nhan vien luong cao nhat" << endl;
        cout << "7. Tim nhan vien co so san pham ban duoc thap nhat " << endl;
        cout << "8. Hien thi top 10 nhan vien co luong cao nhat" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            taoDulieuCT();
            break;
        case 2:
            system("cls");
            xuatDanhSach();
            break;
        case 3:
            system("cls");
            tinhLuong();
            break;
        case 4:
            system("cls");
            timNhanVien();
            break;
        case 5:
            system("cls");
            capNhatLuongCoBan();
            break;
        case 6:
            system("cls");
            timNhanVienLuongCaoNhat();
            break;
        case 7:
            system("cls");
            timNhanVienCoSoSPThapNhat();
            break;
        case 8:
            // Hiển thị top 10 nhân viên có lương cao nhất
            system("cls");
            timTop10NhanVienLuongCaoNhat();
            break;
        case 0:
            // Thoát khỏi chương trình
            system("cls");
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;
        default:
            // Xử lý lựa chọn không hợp lệ
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
