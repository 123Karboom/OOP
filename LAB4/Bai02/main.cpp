#include <bits/stdc++.h>
#include<DaiHoc.h>
using namespace std;

static DaiHoc UIT;

// 1. Tạo danh sách sinh viên
void taoDanhSach()
{
    UIT.taoDanhSach();
    cout << "Tao danh sach thanh cong ! \n";
}

// 2. Xuất danh sách các sinh viên
void xuatDanhSach()
{
    cout << "            ==========================================================" << endl;
    cout << "            =                    DANH SACH SINH VIEN                 =" << endl;
    cout << "            ==========================================================" << endl;
    UIT.xuatDanhSach();
}

// 3. Xét tốt nghiệp
void xetTotNghiep()
{
    UIT.xetTotNghiep();
    cout << "Xet tot nghiep thanh cong ! \n";
}


// 4. Tìm các sinh viên đủ điều kiện tốt nghiệp
void danhSachSVTN()
{
    vector<SinhVien *> ans;
    ans = UIT.SVTotNghiep();
    if (ans.empty())
    {
        cout << "Danh sach trong ! \n";
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =               DANH SACH SINH VIEN TOT NGHIEP           =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i]->xuat();
        cout << endl;
    }
}

// 5. Tìm các sinh viên không đủ điều kiện tốt nghiệp
void danhSachSVKoTN()
{
    vector<SinhVien *> ans;
    ans = UIT.SVKoTotNghiep();
    if (ans.empty())
    {
        cout << "Danh sach trong ! \n";
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =          DANH SACH SINH VIEN KHONG TOT NGHIEP          =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i]->xuat();
        cout << endl;
    }
}

// 6. Tìm sinh viên hệ VB2 có điểm trung bình thấp nhất
void SVVB2CoDiemTBThapNhat()
{
    vector<SinhVien *> ans;
    ans = UIT.SVVB2DiemTBThapNhat();
    if (ans.empty())
    {
        cout << "Danh sach trong !";
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =    DANH SACH SINH VIEN VAN BAN 2 CO DIEM TB THAP NHAT  =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i]->xuat();
        cout << endl;
    }
}

// 7. Sinh viên đại học có điểm trung bình cao nhất
void SVDHCoDiemTBCaoNhat()
{
    vector<SinhVien *> ans;
    ans = UIT.SVDHDiemTBCaoNhat();
    if (ans.empty())
    {
        cout << "Danh sach trong ! \n";
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =      DANH SACH SINH VIEN DAI HOC CO DIEM TB CAO NHAT   =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        ans[i]->xuat();
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
        cout << "1. Tao danh sach sinh vien" << endl;
        cout << "2. Xuat danh sach cac sinh vien" << endl;
        cout << "3. Xet tot nghiep" << endl;
        cout << "4. Tim cac sinh vien du dieu kien tot nghiep" << endl;
        cout << "5. Tim cac sinh vien ko du dieu kien tot nghiep" << endl;
        cout << "6. Tim sinh vien he VB2 co diem trung binh thap nhat" << endl;
        cout << "7. Tim sinh vien dai hoc co diem trung binh cao nhat " << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            taoDanhSach();
            break;
        case 2:
            system("cls");
            xuatDanhSach();
            break;
        case 3:
            system("cls");
            xetTotNghiep();
            break;
        case 4:
            system("cls");
            danhSachSVTN();
            break;
        case 5:
            system("cls");
            danhSachSVKoTN();
            break;
        case 6:
            system("cls");
            SVVB2CoDiemTBThapNhat();
            break;
        case 7:
            system("cls");
            SVDHCoDiemTBCaoNhat();
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

