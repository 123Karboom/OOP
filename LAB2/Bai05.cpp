#include <bits/stdc++.h>
using namespace std;

string danhSachTen[] = {
    "Nguyen Van A", "Tran Thi B", "Le Van C", "Pham Thi D",
    "Vo Van E", "Do Thi F", "Tran Huu L", "Nguyen Thi H",
    "Tran Van I", "Le Thi K", "Pham Van L", "Vo Thi M",
    "Do Van N", "Hoang Thi P", "Nguyen Quoc V", "Tran Thi R",
    "Le Van S", "Pham Thi T", "Hoang V", "Le Thanh T",
    "Ngo Gia T", "Ngo Van X", "Nguyen Quoc V", "Tran Thanh T"};

class NhanVien
{
private:
    int maNhanVien;
    string hoTen;
    int luongCoBan;
    int soSanPhamDaBan;
    int luongHangThang;

public:
    NhanVien(int, string, int, int);
    void nhap();
    void xuatThongTin();
    void tinhLuongHangThang();
    int getMaNhanVien();
    int getSoSanPhamBanDuoc();
    int getLuongHangThang();
    void setLuongCoBan(int luongCB);
};

NhanVien ::NhanVien(int ma, string ten, int luongCB, int sp)
{
    this->maNhanVien = ma;
    this->hoTen = ten;
    this->luongCoBan = luongCB;
    this->soSanPhamDaBan = sp;
    this->luongHangThang = 0.0;
}

void NhanVien::xuatThongTin()
{
    cout << setw(20) << left << maNhanVien;
    cout << setw(20) << left << hoTen;
    cout << setw(20) << left << luongCoBan;
    cout << setw(20) << left << soSanPhamDaBan;
    cout << setw(20) << left << luongHangThang;
    cout << endl;
}

void NhanVien ::tinhLuongHangThang()
{
    luongHangThang = luongCoBan + soSanPhamDaBan * 175000;
    if (luongHangThang >= 10000000)
    {
        luongHangThang += luongHangThang * 0.1;
    }
}

int NhanVien::getMaNhanVien()
{
    return maNhanVien;
}

void NhanVien ::setLuongCoBan(int luongCB)
{
    this->luongCoBan = luongCB;
}

int NhanVien ::getSoSanPhamBanDuoc()
{
    return soSanPhamDaBan;
}

int NhanVien ::getLuongHangThang()
{
    return luongHangThang;
}

class QuanLy
{
private:
    vector<NhanVien> danhSachNhanVien;

public:
    QuanLy() {}
    void taoDuLieu();
    void inDanhSach();
    void tinhLuongNhanVien();
    void timNhanVienTheoMa();
    void capNhatLuongCoBanNhanVien();
    void timNhanVienLuongCaoNhat();
    void timNhanVienSoSanPhamBanItNhat();
    void tim10NhanVienLuongCaoNhat();
};

void QuanLy ::taoDuLieu()
{
    srand(time(NULL));
    int n, luong = 0;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cout << "Nhap luong can ban: ";
    cin >> luong;
    for (int i = 0; i < n; i++)
    {
        int maNV = (int)(rand() % 200 + 10000);
        string ten = danhSachTen[rand() % 24];
        int luongCB = luong;
        int sanPham = (int)(rand() % 100 + 300);
        NhanVien nv(maNV, ten, luongCB, sanPham);
        danhSachNhanVien.push_back(nv);
    }
}

void QuanLy ::inDanhSach()
{
    cout << "----------------------------- DANH SACH NHAN VIEN -----------------------------" << endl;
    cout << setw(20) << left << "Ma Nhan Vien";
    cout << setw(20) << left << "Ho va Ten";
    cout << setw(20) << left << "Luong Co Ban";
    cout << setw(20) << left << "So San Pham";
    cout << setw(20) << left << "Luong ";
    cout << endl;
    for (int i = 0; i < danhSachNhanVien.size(); i++)
    {
        danhSachNhanVien[i].xuatThongTin();
    }
}

void QuanLy ::tinhLuongNhanVien()
{
    for (int i = 0; i < danhSachNhanVien.size(); i++)
    {
        danhSachNhanVien[i].tinhLuongHangThang();
    }
    cout << "Da tinh luong thanh cong!" << endl;
}

void QuanLy ::timNhanVienTheoMa()
{
    int maNV;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> maNV;
    bool found = false;
    for (NhanVien &nv : danhSachNhanVien)
    {
        if (nv.getMaNhanVien() == maNV)
        {
            nv.xuatThongTin();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Khong tim thay nhan vien co ma: " << maNV << endl;
    }
}

void QuanLy ::capNhatLuongCoBanNhanVien()
{
    int maNV, luongCB;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> maNV;
    cout << "Muc luong cap nhat: ";
    cin >> luongCB;
    bool found = false;
    for (NhanVien &nv : danhSachNhanVien)
    {
        if (nv.getMaNhanVien() == maNV)
        {
            nv.setLuongCoBan(luongCB);
            nv.tinhLuongHangThang();
            cout << "Da cap nhat luong co ban thanh cong cho nhan vien co ma: " << maNV << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Khong tim thay nhan vien co ma: " << maNV << endl;
    }
}

void QuanLy ::timNhanVienLuongCaoNhat()
{
    if (danhSachNhanVien.empty())
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }

    int maxLuong = danhSachNhanVien[0].getLuongHangThang();
    NhanVien *nvMaxLuong = &danhSachNhanVien[0];

    for (NhanVien &nv : danhSachNhanVien)
    {
        if (nv.getLuongHangThang() > maxLuong)
        {
            maxLuong = nv.getLuongHangThang();
            nvMaxLuong = &nv;
        }
    }

    cout << "Nhan vien luong cao nhat: " << endl;
    cout << setw(20) << left << "Ma Nhan Vien";
    cout << setw(20) << left << "Ho va Ten";
    cout << setw(20) << left << "Luong Co Ban";
    cout << setw(20) << left << "So San Pham";
    cout << setw(20) << left << "Luong ";
    cout << endl;
    nvMaxLuong->xuatThongTin();
}

void QuanLy ::timNhanVienSoSanPhamBanItNhat()
{
    if (danhSachNhanVien.empty())
    {
        cout << "Danh sách nhân viên trống!" << endl;
        return;
    }

    int minSoSP = danhSachNhanVien[0].getSoSanPhamBanDuoc();
    NhanVien *nvMinSoSP = &danhSachNhanVien[0];

    for (NhanVien &nv : danhSachNhanVien)
    {
        if (nv.getSoSanPhamBanDuoc() < minSoSP)
        {
            minSoSP = nv.getSoSanPhamBanDuoc();
            nvMinSoSP = &nv;
        }
    }

    cout << "Nhan vien co so san pham ban duoc it nhat: " << endl;
    cout << setw(20) << left << "Ma Nhan Vien";
    cout << setw(20) << left << "Ho va Ten";
    cout << setw(20) << left << "Luong Co Ban";
    cout << setw(20) << left << "So San Pham";
    cout << setw(20) << left << "Luong ";
    cout << endl;
    nvMinSoSP->xuatThongTin();
}

void QuanLy ::tim10NhanVienLuongCaoNhat()
{
    if (danhSachNhanVien.empty())
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }

    vector<NhanVien> danhSachNhanVienCopy = danhSachNhanVien;
    sort(danhSachNhanVienCopy.begin(), danhSachNhanVienCopy.end(), [](NhanVien &a, NhanVien &b)
         { return a.getLuongHangThang() > b.getLuongHangThang(); });

    cout << "----------------------------- TOP 10 NHAN VIEN LUONG CAO NHAT -----------------------------" << endl;
    cout << setw(20) << left << "Ma Nhan Vien";
    cout << setw(20) << left << "Ho va Ten";
    cout << setw(20) << left << "Luong Co Ban";
    cout << setw(20) << left << "So San Pham";
    cout << setw(20) << left << "Luong ";
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        danhSachNhanVienCopy[i].xuatThongTin();
    }
    cout << "--------------------------------------------------------------------" << endl;
}
int main()
{
    QuanLy quanLy; // Khởi tạo đối tượng QuanLy để quản lý danh sách nhân viên
    int choice;    // Biến lưu lựa chọn của người dùng

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
            quanLy.taoDuLieu();
            break;
        case 2:
            system("cls");
            quanLy.inDanhSach();
            break;
        case 3:
            system("cls");
            quanLy.tinhLuongNhanVien();
            break;
        case 4:
            system("cls");
            quanLy.timNhanVienTheoMa();
            break;
        case 5:
            system("cls");
            quanLy.capNhatLuongCoBanNhanVien();
            break;
        case 6:
            system("cls");
            quanLy.timNhanVienLuongCaoNhat();
            break;
        case 7:
            system("cls");
            quanLy.timNhanVienSoSanPhamBanItNhat();
            break;
        case 8:
            // Hiển thị top 10 nhân viên có lương cao nhất
            system("cls");
            quanLy.tim10NhanVienLuongCaoNhat();
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
