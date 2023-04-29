#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
public:
    string hoTen;
    int namSinh;

public:
    virtual void nhap() // ham nhap truu tuong
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore(); // xoa ky tu \n
    }
    virtual void xuat() // ham xuat truu tuong
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
    virtual int tinhLuong() = 0; // ham tinh luong truu tuong
};

class NhanVienSanXuat : public NhanVien
{
private:
    int luongCanBan;
    int soSanPham;

public:
    void nhap()
    {
        NhanVien ::nhap(); // goi phuong thuc nhap tu lop NhanVien
        cout << "Nhap luong can ban: ";
        cin >> luongCanBan;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        cin.ignore(); // xoa ky tu \n
    }
    void xuat()
    {
        NhanVien ::xuat(); // goi phuong thuc xuat tu lop NhanVien
        cout << "Luong can ban: " << luongCanBan << endl;
        cout << "So san pham: " << soSanPham << endl;
    }
    int tinhLuong()
    {
        return luongCanBan + soSanPham * 5000;
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    int soNgayLamViec;

public:
    void nhap()
    {
        NhanVien ::nhap(); // goi phuong thuc nhap tu lop NhanVien
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cin.ignore(); // xoa ky tu \n
    }
    void xuat()
    {
        NhanVien ::xuat(); // goi phuong thuc xuat tu lop NhanVien
        cout << "So ngay lam viec: " << soNgayLamViec << endl;
    }
    int tinhLuong()
    {
        return soNgayLamViec * 100000;
    }
};

class Quanly
{
private:
    string ten = "Thai Bao";
    int MSSV = 22520104;
    vector<NhanVien *> danhSach; // tao mang dong luu tru thong tin cac nhan vien
public:
    void nhapThongTinNVVP();
    void nhapThongTinNVSX();
    void inDanhSachNhanVien();
    void tinhTongLuong();
    void timNhanVienLuongCaoNhat();
    void timNhanVienTreNhatVaLuongCaoNhat();
};

void Quanly ::nhapThongTinNVVP()
{
    int a;
    cout << "Nhap so luong nhan vien van phong: ";
    cin >> a;
    cin.ignore();               // xoa ky tu \n
    for (int i = 0; i < a; i++) // nhap thong tin cua cac nhan vien van phong
    {
        cout << "Nhan Vien Van Phong thu: " << i + 1 << endl;
        NhanVien *nvvp = new NhanVienVanPhong;
        nvvp->nhap();
        danhSach.push_back(nvvp);
        cout << endl;
    }
}

void Quanly :: nhapThongTinNVSX()
{
    int b;
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> b;
    cin.ignore();               // xoa ky tu \n
    for (int i = 0; i < b; i++) // nhap thong tin cua cac nhan vien san xuat
    {
        cout << "Nhan vien san xuat thu: " << i + 1 << endl;
        NhanVien *nvsx = new NhanVienSanXuat;
        nvsx->nhap();
        danhSach.push_back(nvsx);
        cout << endl;
    }
}

void Quanly :: inDanhSachNhanVien()
{
    cout << "---------------- DANH SACH NHAN VIEN ---------------- \n";
    for (int i = 0; i < danhSach.size(); i++) // in thong tin vua nhap cua cac nhan vien
    {
        danhSach[i]->xuat();
        cout << "________________________________________\n";
    }
}

void Quanly ::tinhTongLuong()
{
    int tongLuong = 0;
    for (int i = 0; i < danhSach.size(); i++) // tinh tong luong phai tra cho nhan vien
    {
        tongLuong += danhSach[i]->tinhLuong();
    }
    cout << "Tong luong phai tra cho tat ca nhan vien: " << tongLuong << endl
         << endl;
}

void Quanly ::timNhanVienLuongCaoNhat()
{
    int maxLuong = danhSach[0]->tinhLuong();
    for (int i = 1; i < danhSach.size(); i++) // tim nhan vien co luong cao nhat
    {
        if (danhSach[i]->tinhLuong() > maxLuong)
        {
            maxLuong = danhSach[i]->tinhLuong();
        }
    }

    cout << "   Cac nhan vien co tien luong cao nhat:\n";
    for (int i = 0; i < danhSach.size(); i++) // in ra cac nhan vien luong cao nhat
    {
        if (danhSach[i]->tinhLuong() == maxLuong)
        {
            danhSach[i]->xuat();
            cout << "________________________________________ \n";
        }
    }
}

void Quanly :: timNhanVienTreNhatVaLuongCaoNhat()
{
vector<NhanVien *> nhanVienTreNhat; // danh sach cac nhan vien tre nhat
int minNamSinh = INT_MAX;
int maxLuong = INT_MIN;

for (const auto& nv : danhSach) 
{
    if (nv->namSinh < minNamSinh) 
    {
        minNamSinh = nv->namSinh;
        nhanVienTreNhat.clear();
        nhanVienTreNhat.push_back(nv);
        maxLuong = nv->tinhLuong();
    } 
    else if (nv->namSinh == minNamSinh) 
    {
        int luong = nv->tinhLuong();
        if (luong > maxLuong) 
        {
            maxLuong = luong;
            nhanVienTreNhat.clear();
            nhanVienTreNhat.push_back(nv);
        } 
        else if (luong == maxLuong) 
        {
            nhanVienTreNhat.push_back(nv);
        }
    }
}
    cout <<"    Cac nhan vien tre nhat va luong cao nhat: \n";
    for (int i = 0; i < nhanVienTreNhat.size(); i++) // tim nhan vien tre nhat va luong cao nhat
    {
        if (nhanVienTreNhat[i]->tinhLuong() == maxLuong)
        {
            nhanVienTreNhat[i]->xuat();
            cout << "________________________________________ \n";
        }
    }
}

int main()
{
    Quanly BAO;
    BAO.nhapThongTinNVVP();

    BAO.nhapThongTinNVSX();

    BAO.inDanhSachNhanVien();

    BAO.tinhTongLuong();

    BAO.timNhanVienLuongCaoNhat();

    BAO.timNhanVienTreNhatVaLuongCaoNhat();

    return 0;
}