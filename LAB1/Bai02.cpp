#include <bits/stdc++.h>
using namespace std;

const string danhSachTen[] = {
    "Nguyen Van A", "Tran Thi B", "Le Van C", "Pham Thi D",
    "Vo Van E", "Do Thi F", "Tran Huu L", "Nguyen Thi H",
    "Tran Van I", "Le Thi K", "Pham Van L", "Vo Thi M",
    "Do Van N", "Hoang Thi P", "Nguyen Quoc V", "Tran Thi R",
    "Le Van S", "Pham Thi T", "Hoang V", "Le Thanh T",
    "Peter Paker", "Uchiha Sasuke", "Naruto", "Tran Thanh"};

// Lớp Sinhvien chứa thông tin của một sinh viên
class Sinhvien
{
public:
    string maSV;
    string hoTen;
    float diemTB;
    string xepLoai;

public:
    Sinhvien()
    {
        maSV = hoTen = xepLoai = "";
        diemTB = 0;
    }
    Sinhvien(string _maSV, string _hoTen, float _diemTB)
    {
        maSV = _maSV;
        hoTen = _hoTen;
        diemTB = _diemTB;
    } // constructor
    // Cập nhật xếp loại học lực cho sinh viên
    void tinhXepLoai();
    // In thông tin của một sinh viên
    void inThongTin();
};

void Sinhvien ::tinhXepLoai()
{
    if (diemTB >= 9)
    {
        xepLoai = "Xuat sac";
    }
    else if (diemTB >= 8)
    {
        xepLoai = "Gioi";
    }
    else if (diemTB >= 7)
    {
        xepLoai = "Kha";
    }
    else if (diemTB >= 5)
    {
        xepLoai = "Trung binh";
    }
    else
    {
        xepLoai = "Yeu";
    }
}

void Sinhvien ::inThongTin()
{
    cout << setw(20) << left << maSV;
    cout << setw(20) << left << hoTen;
    cout << setw(20) << left << diemTB;
    cout << setw(20) << left << xepLoai;
    cout << endl;
}

// Lớp QuanLySinhVien chứa danh sách sinh viên và các phương thức quản lý sinh viên
class QuanLySinhVien
{
private:
    vector<Sinhvien> danhSachSinhVien;

public:
    // Constructor
    QuanLySinhVien();

    // Nhập thông tin n sinh viên từ bàn phím
    void nhapThongTinTuBanPhim();

    // Khởi tạo danh sách sinh viên theo danh sách cho trước
    void khoiTaoTuDanhSach(vector<Sinhvien> ds);

    // Khởi tạo danh sách sinh viên ngẫu nhiên với số lượng cho trước
    void khoiTaoNgauNhien();

    // Xuất thông tin tất cả các sinh viên trong danh sách
    void xuatThongTin();

    // Cập nhật xếp loại học lực cho tất cả các sinh viên trong danh sách
    void capNhatXepLoai();

    // Tìm sinh viên có điểm TB lớn nhất trong danh sách
    Sinhvien SVCoDiemTBLonNhat();

    // Tìm sinh viên theo mã sinh viên
    Sinhvien timSVTheoMaSV(string maSV);

    // Tìm các sinh viên có điểm TB cho trước
    vector<Sinhvien> timSVTheoDiemTB(float diemTB);

    // Tìm 10 sinh viên có điểm TB cao nhất
    vector<Sinhvien> Top10DiemCao();

    // Tìm 10 sinh viên có điểm TB thấp nhất
    vector<Sinhvien> Top10DiemThap();
};

QuanLySinhVien ::QuanLySinhVien()
{
    danhSachSinhVien = vector<Sinhvien>();
}

void QuanLySinhVien ::nhapThongTinTuBanPhim()
{
    {
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        cin.ignore();
        danhSachSinhVien.clear();
        for (int i = 0; i < n; i++)
        {
            string maSV, hoTen;
            float diem;
            cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
            cout << "Ma SV: ";
            getline(cin, maSV);
            cout << "Ho ten: ";
            getline(cin, hoTen);
            cout << "Diem TB: ";
            cin >> diem;
            cin.ignore();
            Sinhvien sv(maSV, hoTen, diem);
            danhSachSinhVien.push_back(sv);
        }
    }
}

void QuanLySinhVien ::khoiTaoTuDanhSach(vector<Sinhvien> ds)
{
    danhSachSinhVien = ds;
}

void QuanLySinhVien ::khoiTaoNgauNhien()
{
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    danhSachSinhVien.clear();
    srand(time(NULL)); // Khởi tạo seed cho hàm rand
    for (int i = 0; i < n; i++)
    {
        string maSV = "SV" + to_string(i + 1);
        string hoTen = danhSachTen[rand() % 20];
        float diemTB = (float)(rand() % 50 + 50) / 10.0; // Điểm TB ngẫu nhiên từ 0.0 đến 10.0
        Sinhvien sv(maSV, hoTen, diemTB);
        danhSachSinhVien.push_back(sv);
    }
}

void QuanLySinhVien ::xuatThongTin()
{
    cout << setw(20) << left << "Ma Sinh Vien ";
    cout << setw(20) << left << "Ho ten ";
    cout << setw(20) << left << "Diem TB ";
    cout << setw(20) << left << "Xep loai ";
    cout << endl;
    for (auto sv : danhSachSinhVien)
    {

        sv.inThongTin();
    }
}

void QuanLySinhVien ::capNhatXepLoai()
{
    for (int i = 0; i < danhSachSinhVien.size(); i++)
    {
        danhSachSinhVien[i].tinhXepLoai();
    }
}

Sinhvien QuanLySinhVien ::SVCoDiemTBLonNhat()
{
    Sinhvien svMax = danhSachSinhVien[0];
    for (int i = 1; i < danhSachSinhVien.size(); i++)
    {
        if (danhSachSinhVien[i].diemTB > svMax.diemTB)
        {
            svMax = danhSachSinhVien[i];
        }
    }
    return svMax;
}

Sinhvien QuanLySinhVien ::timSVTheoMaSV(string maSV)
{
    for (int i = 0; i < danhSachSinhVien.size(); i++)
    {
        if (danhSachSinhVien[i].maSV == maSV)
        {
            return danhSachSinhVien[i];
        }
    }
    // Nếu không tìm thấy sinh viên có mã sinh viên này, trả về một sinh viên rỗng
    return Sinhvien();
}

vector<Sinhvien> QuanLySinhVien ::timSVTheoDiemTB(float diemTB)
{
    vector<Sinhvien> danhSachSV;
    for (int i = 0; i < danhSachSinhVien.size(); i++)
    {
        if (danhSachSinhVien[i].diemTB == diemTB)
        {
            danhSachSV.push_back(danhSachSinhVien[i]);
        }
    }
    return danhSachSV;
}

vector<Sinhvien> QuanLySinhVien ::Top10DiemCao()
{
    vector<Sinhvien> danhSachSV(danhSachSinhVien); // Copy danh sách sinh viên để sắp xếp
    sort(danhSachSV.begin(), danhSachSV.end(), [](Sinhvien a, Sinhvien b)
         { return a.diemTB > b.diemTB; }); // Sắp xếp giảm dần theo điểm TB
    vector<Sinhvien> danhSach10SV;
    int n = min((int)danhSachSV.size(), 10);
    for (int i = 0; i < n; i++)
    {
        danhSach10SV.push_back(danhSachSV[i]);
    }
    return danhSach10SV;
}

vector<Sinhvien> QuanLySinhVien ::Top10DiemThap()
{
    vector<Sinhvien> danhSachSV(danhSachSinhVien); // Copy danh sách sinh viên để sắp xếp
    sort(danhSachSV.begin(), danhSachSV.end(), [](Sinhvien a, Sinhvien b)
         { return a.diemTB < b.diemTB; }); // Sắp xếp tăng dần theo điểm TB
    vector<Sinhvien> danhSach10SV;
    int n = min((int)danhSachSV.size(), 10);
    for (int i = 0; i < n; i++)
    {
        danhSach10SV.push_back(danhSachSV[i]);
    }
    return danhSach10SV;
}

void xuatThongTin(vector<Sinhvien> DS) // ham xuat thong tin tu mang Sinhvien
{
    cout << setw(20) << left << "Ma Sinh Vien ";
    cout << setw(20) << left << "Ho ten ";
    cout << setw(20) << left << "Diem TB ";
    cout << setw(20) << left << "Xep loai ";
    cout << endl;
    for (auto sv : DS)
    {
        sv.inThongTin();
    }
}

int main()
{
    QuanLySinhVien Quanly;
    vector<Sinhvien> danhsach; // danh sach GVTH cung cap

    string maSV;
    float diemTB;
    int choice;
    do
    {
        cout << "=================================== MENU CHUC NANG ===================================" << endl;
        cout << "1. Nhap thong tin sinh vien" << endl;
        cout << "2. Khoi tao danh sach sinh vien theo danh sach cung cap" << endl;
        cout << "3. Khoi tao danh sach sinh vien ngau nhien" << endl;
        cout << "4. Xuat thong tin tat ca sinh vien" << endl;
        cout << "5. Xuat thong tin sinh vien co diem TB cao nhat" << endl;
        cout << "6. Cap nhat xep loai hoc luc cho sinh vien" << endl;
        cout << "7. Tim sinh vien theo ma sinh vien" << endl;
        cout << "8. Tim danh sach sinh vien co diem trung binh cho truoc" << endl;
        cout << "9. Tim 10 sinh vien co diem trung binh cao nhat" << endl;
        cout << "10. Tim 10 sinh vien co diem trung binh thap nhat" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "=========================================================================================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Quanly.nhapThongTinTuBanPhim();
            break;
        case 2:
            Quanly.khoiTaoTuDanhSach(danhsach);
            break;
        case 3:
            Quanly.khoiTaoNgauNhien();
            break;
        case 4:
            Quanly.xuatThongTin();
            break;
        case 5:
            cout << setw(20) << left << "Ma Sinh Vien ";
            cout << setw(20) << left << "Ho ten ";
            cout << setw(20) << left << "Diem TB ";
            cout << setw(20) << left << "Xep loai ";
            Quanly.SVCoDiemTBLonNhat().inThongTin();
            break;
        case 6:
            Quanly.capNhatXepLoai();
            cout << "DA CAP NHAT XONG !" << endl;
            break;
        case 7:
            cout << "Nhap ma sinh vien: " << endl;
            getline(cin, maSV);
            cin.ignore();
            cout << setw(20) << left << "Ma Sinh Vien ";
            cout << setw(20) << left << "Ho ten ";
            cout << setw(20) << left << "Diem TB ";
            cout << setw(20) << left << "Xep loai ";
            Quanly.timSVTheoMaSV(maSV).inThongTin();
            break;
        case 8:
            cout << "Nhap diem trung binh can tim: " << endl;
            cin >> diemTB;
            cin.ignore();
            xuatThongTin(Quanly.timSVTheoDiemTB(diemTB));
            break;
        case 9:
            cout << "----------------- TOP 10 DIEM TRUNG BINH CAO NHAT -----------------" << endl;
            xuatThongTin(Quanly.Top10DiemCao());
            break;
        case 10:
            cout << "----------------- TOP 10 DIEM TRUNG BINH THAP NHAT -----------------" << endl;
            xuatThongTin(Quanly.Top10DiemThap());
            break;
        case 0:
            cout << "Hen gap lai!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le, vui long chon lai!" << endl;
            break;
        }

    } while (choice != 0);
}
