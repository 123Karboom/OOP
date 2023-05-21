#include "DaiHoc.h"
#include<SinhVienDH.h>
#include<SinhVienVB2.h>
#include<bits/stdc++.h>
using namespace std;

string names[]= {"Nguyen Truong Hoang", "Thi Linh Quoc", "Thien Minh Quang", "Van Nguyen Truong", "Hoang Thi Linh",
                 "Quoc Thien Minh", "Quang Van Nguyen", "Truong Hoang Thi", "Linh Quoc Thien", "Minh Quang Van",
                 "Nguyen Hoang Thi", "Truong Linh Quoc", "Quang Minh Van", "Nguyen Thi Linh", "Hoang Quoc Thien",
                 "Thi Quang Van", "Thien Quoc Minh", "Minh Van Nguyen", "Thi Quoc Hoang", "Linh Quang Van",
                 "Quoc Minh Nguyen", "Minh Quoc Hoang", "Truong Minh Linh", "Hoang Van Nguyen", "Linh Thi Quoc",
                 "Quoc Linh Hoang", "Van Quoc Minh", "Nguyen Linh Quoc", "Hoang Quang Minh", "Quoc Van Nguyen",
                 "Truong Thi Linh", "Thi Quoc Minh", "Thien Linh Quoc", "Minh Quoc Van", "Hoang Minh Quoc",
                 "Quoc Thi Linh", "Thi Minh Van", "Van Hoang Quoc", "Nguyen Minh Quoc", "Truong Quoc Linh",
                 "Quoc Linh Thi", "Van Minh Quoc", "Hoang Quoc Linh", "Linh Hoang Quoc", "Thien Quoc Linh",
                 "Minh Hoang Quoc", "Thi Quoc Linh", "Quoc Hoang Minh", "Van Quoc Linh", "Nguyen Quoc Hoang"
                };

string addresses[] = { "123 Tran Phu, Ho Chi Minh City", "456 Le Hong Phong, Hanoi", "789 Nguyen Du, Da Nang", "321 Le Van Huu, Can Tho",
                       "654 Le Dai Hanh, Hai Phong", "987 Quang Trung, Da Lat", "876 Tran Thi Ky, Hue", "543 Pham Van Dong, Nha Trang",
                       "210 Le Loi, Vung Tau", "135 Tran Quoc Toan, Bien Hoa", "864 Nguyen Tat Thanh, Ha Long", "753 Le Van Tam, Qui Nhon",
                       "246 Tran Cao Van, Phan Thiet", "579 Pham Hong Thai, Tam Ky", "708 Nguyen Trai, Vinh", "951 Le Lai, Tuy Hoa",
                       "384 Tran Hung Dao, Pleiku", "627 Pham Van Dong, Rach Gia", "360 Trung Vuong, Dong Hoi", "495 Tran Thi Ky, Buon Ma Thuot",
                       "732 Nguyen Sinh Sac, Long Xuyen", "159 Le Dai Hanh, Soc Trang", "894 Tran Hung Dao, Ca Mau", "237 Pham Ngoc Thach, Thai Nguyen",
                       "570 Nguyen Van Lung, Yen Bai", "123 Le Quy Don, Ha Giang", "456 Tran Cao Van, Lao Cai", "789 Hung Vuong, Dien Bien",
                       "321 Bach Dang, Son La", "654 Ly Nam De, Lang Son", "987 Nguyen Cu Trinh, Cao Bang", "876 Nguyen Van Troi, Bac Giang",
                       "543 Nguyen Thai Hoc, Bac Ninh", "210 Lac Long Quan, Hai Duong", "135 Hoang Dieu, Hung Yen", "864 Nguyen Thi Minh Khai, Nam Dinh",
                       "753 Ngo Gia Tu, Thai Binh", "246 Ho Xuan Huong Hai Phong", "579 Nguyen Tat Thanh, Ha Noi", "708 Vo Nguyen Giap, Ha Nam",
                       "951 Tran Thi Ky, Ninh Binh", "384 Pham Ngu Lao, Vinh Phuc", "627 Phan Dinh Phung, Quang Ninh", "360 Pham Hong Thai, Hoa Binh",
                       "495 Hai Ba Trung, Thanh Hoa", "732 Huynh Tan Phat, Nghe An", "159 Nguyen Hue, Ha Tinh", "894 Tan Ky Tan Quy, Quang Binh",
                       "237 Cong Hoa, Quang Tri", "570 Kim Dong, Thua Thien Hue"
                     };
DaiHoc::DaiHoc()
{
    //ctor
}

DaiHoc::~DaiHoc()
{
    //dtor
}
// Constructor & Destructor

//1. Tạo danh sách
void DaiHoc ::taoDanhSach()
{
    int n, m;
    cout << "Nhap so luong sinh vien dai hoc: ";
    cin >> n;
    cout << "Nhap so luong sinh vien VB2: ";
    cin >> m;
    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(4.1, 9.9);
        double diemTB = dis(gen);
        double diemLV = dis(gen);
        string tenLV = "LV thu " + to_string(i);
        danhSachSV.push_back(new SinhVienDH(names[i%50], 22520000 + i, addresses[i%50], (rand() % 20) + 110, diemTB, tenLV, diemLV));
    }

    for (int i = 1; i <= m; i++)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(4.1, 9.9);
        double diemTB = dis(gen);
        double diemThi = dis(gen);
        danhSachSV.push_back(new SinhVienVB2(names[i%50], 22530000 + i, addresses[i%50], (rand() % 30) + 70, diemTB, diemThi));
    }
}

// 2. Xuất danh sách
void DaiHoc ::xuatDanhSach()
{
    if(danhSachSV.empty())
    {
        cout <<"Danh sach trong !";
        return;
    }
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        danhSachSV[i]->xuat();
        cout << endl;
    }
}

// 3. Xét tốt nghiệp
void DaiHoc ::xetTotNghiep()
{
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        danhSachSV[i]->xetTotNghiep();
    }
}

/*
4. Tìm các sinh viên đủ điều kiện tốt nghiệp
Input:
    + thuộc tính danhSachSV
Output:
    + return DSSVTotNghiep (danh sách gồm các sinh viên đủ điều kiện tốt nghiệp)
*/
vector<SinhVien *> DaiHoc ::SVTotNghiep()
{
    vector<SinhVien *> DSSVTotNghiep;
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (danhSachSV[i]->getTrangthaiTN())
        {
            DSSVTotNghiep.push_back(danhSachSV[i]);
        }
    }
    return DSSVTotNghiep;
}

/*
5. Tìm các sinh viên ko đủ điều kiện tốt nghiệp
Input:
    + thuộc tính danhSachSV
Output:
    + return DSSVKoTotNghiep (danh sách gồm các sinh viên ko đủ điều kiện tốt nghiệp)
*/
vector<SinhVien *> DaiHoc ::SVKoTotNghiep()
{
    vector<SinhVien *> DSSVKoTotNghiep;
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (!(danhSachSV[i]->getTrangthaiTN()))
        {
            DSSVKoTotNghiep.push_back(danhSachSV[i]);
        }
    }
    return DSSVKoTotNghiep;
}

/*
6. Tìm các sinh viên có điểm TB thấp nhất
Input:
    + thuộc tính danhSachSV
Output:
    + return DSSVVB2DiemTBThapNhat (danh sách gồm các sinh viên có điểm TB thấp nhất)
*/
vector<SinhVien* > DaiHoc ::SVVB2DiemTBThapNhat()
{
    vector<SinhVien* > DSSVVB2DiemTBThapNhat;
    double diemMin = 10.0;
    for(int i = 0; i < danhSachSV.size(); i++)
    {
        if(!danhSachSV[i]->laSVDH() && danhSachSV[i]->getdiemTB() < diemMin)
        {
            diemMin = danhSachSV[i]->getdiemTB();
        }
    }

    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (!danhSachSV[i]->laSVDH() && danhSachSV[i]->getdiemTB() == diemMin)
        {
            DSSVVB2DiemTBThapNhat.push_back(danhSachSV[i]);
        }
    }

    return DSSVVB2DiemTBThapNhat;
}

/*
7. Sinh viên hệ đại học có điểm trung bình cao nhất
Input:
    + thuộc tính danhSachSV
Output:
    +return DSSVDHDiemTBCaoNhat (danh sách gồm các sinh viên DH có điểm trung bình cao nhất)
*/
vector<SinhVien *> DaiHoc ::SVDHDiemTBCaoNhat()
{
    vector<SinhVien *> DSSVDHDiemTBCaoNhat;
    double diemTBmax = 0.0;
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (danhSachSV[i]->getdiemTB() > diemTBmax && danhSachSV[i]->laSVDH())
            diemTBmax = danhSachSV[i]->getdiemTB();
    }

    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (danhSachSV[i]->getdiemTB() == diemTBmax && danhSachSV[i]->laSVDH())
            DSSVDHDiemTBCaoNhat.push_back(danhSachSV[i]);
    }
    return DSSVDHDiemTBCaoNhat;
}
