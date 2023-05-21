#include "CongTy.h"

CongTy::CongTy()
{
    //ctor
}

CongTy::~CongTy()
{
    //dtor
}


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
    for (int i = 1; i < danhSachNVSX.size(); i++)
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
