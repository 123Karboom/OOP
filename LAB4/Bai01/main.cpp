#include "CongTy.h"

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
    cout <<"Tinh luong thanh cong ! \n";
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
    if (ans.empty())
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
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
    if (ans.empty())
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            = DANH SACH NHAN VIEN CO SO SAN PHAM BAN DUOC THAP NHAT  =" << endl;
    cout << "            ==========================================================" << endl;
    cout << setw(20) << left << "Ma NV: ";
    cout << setw(20) << left << "Ho ten: ";
    cout << setw(20) << left << "Luong Can Ban: ";
    cout << setw(20) << left << "So san pham: ";
    cout << setw(20) << left << "Luong hang thang: ";
    cout << endl;
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
    if (ans.empty())
    {
        cout << "Danh sach nhan vien trong!" << endl;
        return;
    }
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
    }
    while (choice != 0);

    return 0;
}
