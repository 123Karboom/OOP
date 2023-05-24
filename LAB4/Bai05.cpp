#include <bits/stdc++.h>
using namespace std;

string tenBS[] = {"Nguyen Van A", "Tran Thi Bao", "Le Van Cuong", "Pham Thi Dung", "Hoang Van Eo", "Vo Thi Ha",
                  "Do Van Hau", "Nguyen Thi Huong", "Tran Van Kha", "Le Thi Kim", "Pham Van Long", "Hoang Thi Mai",
                  "Vo Van Minh", "Do Thi Nga", "Nguyen Van Nam", "Tran Thi Oanh", "Le Van Phat", "Pham Thi Quynh",
                  "Hoang Van Sang", "Vo Thi Trang", "Do Van Tuan", "Nguyen Thi Uyen", "Tran Van Vinh", "Le Thi Xuan",
                  "Pham Van Yen", "Hoang Thi Anh", "Vo Van Binh", "Do Thi Cuc", "Nguyen Van Dung", "Tran Thi Em",
                  "Le Van Gia", "Pham Thi Hanh", "Hoang Van Hung", "Vo Thi Hien", "Do Van Hieu", "Nguyen Thi Hong",
                  "Tran Van Khanh", "Le Thi Lan", "Pham Van Minh", "Hoang Thi Nhi", "Vo Van Quang", "Do Thi Que",
                  "Nguyen Van Son", "Tran Thi Tuyet", "Le Van Tung", "Pham Thi Uyen", "Hoang Van Vu", "Vo Thi Xuyen",
                  "Do Van Yen", "Nguyen Thi An", "Tran Van Binh", "Le Thi Chi", "Pham Van Dung"};

string tenBN[] = {"Nguyen Truong Hoang", "Thi Linh Quoc", "Thien Minh Quang", "Van Nguyen Truong", "Hoang Thi Linh",
                  "Quoc Thien Minh", "Quang Van Nguyen", "Truong Hoang Thi", "Linh Quoc Thien", "Minh Quang Van",
                  "Nguyen Hoang Thi", "Truong Linh Quoc", "Quang Minh Van", "Nguyen Thi Linh", "Hoang Quoc Thien",
                  "Thi Quang Van", "Thien Quoc Minh", "Minh Van Nguyen", "Thi Quoc Hoang", "Linh Quang Van",
                  "Quoc Minh Nguyen", "Minh Quoc Hoang", "Truong Minh Linh", "Hoang Van Nguyen", "Linh Thi Quoc",
                  "Quoc Linh Hoang", "Van Quoc Minh", "Nguyen Linh Quoc", "Hoang Quang Minh", "Quoc Van Nguyen",
                  "Truong Thi Linh", "Thi Quoc Minh", "Thien Linh Quoc", "Minh Quoc Van", "Hoang Minh Quoc",
                  "Quoc Thi Linh", "Thi Minh Van", "Van Hoang Quoc", "Nguyen Minh Quoc", "Truong Quoc Linh",
                  "Quoc Linh Thi", "Van Minh Quoc", "Hoang Quoc Linh", "Linh Hoang Quoc", "Thien Quoc Linh",
                  "Minh Hoang Quoc", "Thi Quoc Linh", "Quoc Hoang Minh", "Van Quoc Linh", "Nguyen Quoc Hoang"};

class BenhNhan;

class Nguoi
{
protected:
    string ten;
    int tuoi;
    bool gioiTinh;

public:
    Nguoi();                                    // Constructor
    Nguoi(string ten, int tuoi, bool gioitinh); // Constructor
    ~Nguoi();                                   // Destructor
    virtual void xuat()                         // Ham ao xuat thong tin
    {
        cout << "    + Ho va ten: " << ten << endl;
        cout << "    + Tuoi: " << tuoi << endl;
        cout << "    + Gioi tinh: " << (gioiTinh ? "Nam" : "Nu") << endl;
    }
    string getTen();    // Lay ten
    int getTuoi();      // Lay tuoi
    bool getGioiTinh(); // Lay gioi tinh
};

Nguoi ::Nguoi()
{
    ten = "";
    tuoi = 0;
    srand(time(NULL));
    gioiTinh = rand() % 2;
}

Nguoi ::Nguoi(string ten, int tuoi, bool gioiTinh)
{
    this->ten = ten;
    this->tuoi = tuoi;
    this->gioiTinh = gioiTinh;
}

Nguoi ::~Nguoi() {}

bool Nguoi ::getGioiTinh()
{
    return gioiTinh;
}

string Nguoi ::getTen()
{
    return ten;
}

int Nguoi ::getTuoi()
{
    return tuoi;
}

// Lop BacSi
class BacSi : public Nguoi
{
protected:
    vector<Nguoi *> DSBenhNhan;
    int maBS;
    long long tienCong;

public:
    BacSi();                                              // Constructor
    BacSi(string ten, int tuoi, bool gioiTinh, int maBS); // Constructor
    ~BacSi();                                             // Destructor
    int getMaBS();                                        // Lay ma bac si
    long long getTienCong();                              // Lay tien cong
    void themBenhNhan(Nguoi *BN);                      // Them benh nhan vao danh sach kham benh
    void xuat();                                          // Xuat thong tin bac si
    void tinhTienCong();                                  // Tinh tien cong kham benh
};

BacSi ::BacSi() : Nguoi()
{
    this->maBS = 0;
    this->tienCong = 0;
}

BacSi ::BacSi(string ten, int tuoi, bool gioiTinh, int maBS) : Nguoi(ten, tuoi, gioiTinh)
{
    this->maBS = maBS;
    this->tienCong = 0;
}

BacSi ::~BacSi() {}
// Constructor & Destructor

// Lay ma bac si
int BacSi ::getMaBS()
{
    return maBS;
}

// Lay tien cong
long long BacSi ::getTienCong()
{
    return tienCong;
}

// Them Benh nhan cho bac si
void BacSi ::themBenhNhan(Nguoi *BN)
{
    DSBenhNhan.push_back(BN);
}

// Xuat thong tin bac si
void BacSi ::xuat()
{
    cout << "Thong tin Bac si: " << endl;
    Nguoi ::xuat();
    cout << "    + Ma bac si: " << maBS << endl;
    cout << "    + Tien cong kham benh: " << tienCong << endl;
    cout << "    + Danh sach benh nhan da kham: ";
    for (int i = 0; i < DSBenhNhan.size(); i++)
    {
        cout << DSBenhNhan[i]->getTen() << ", ";
    }
    cout << endl;
}

// Tinh tien cong kham benh cho bac si
void BacSi ::tinhTienCong()
{
    int soBN = DSBenhNhan.size();
    tienCong = soBN * 500000;
    if (soBN >= 10)
    {
        tienCong += tienCong * 0.3;
    }
}

// Lop BenhNhan
class BenhNhan : public Nguoi
{
protected:
    int maBN;
    int soLanKham;
    long long tienThuoc;
    bool baoHiem;
    vector<Nguoi *> DSBacSi;

public:
    BenhNhan();                                                                           // Constructor
    BenhNhan(string ten, int tuoi, bool gioiTinh, int maBN, int soLanKham, bool baoHiem); // Constructor
    ~BenhNhan();                                                                          // Destructor
    int getMaBN();                                                                        // Lay ma benh nhan
    int getSoLanKham();                                                                   // Lay so lan kham benh
    long long getTienThuoc();                                                             // Lay tien thuoc
    bool getBaoHiem();                                                                    // Lay tinh trang bao hiem
    void themBacSi(Nguoi *BS);                                                            // Them bac si vao danh sach
    void tinhTienThuoc();                                                                 // Tinh tien thuoc
    void xuat();                                                                          // Xuat thong tin benh nhan
};

BenhNhan ::BenhNhan() : Nguoi()
{
    maBN = soLanKham = 0;
    tienThuoc = 0;
    baoHiem = false;
}

BenhNhan ::BenhNhan(string ten, int tuoi, bool gioiTinh, int maBN, int soLanKham, bool baoHiem) : Nguoi(ten, tuoi, gioiTinh)
{
    this->maBN = maBN;
    this->soLanKham = soLanKham;
    this->baoHiem = baoHiem;
    this->tienThuoc = 0;
}

BenhNhan ::~BenhNhan() {}
// Constructor & Destructor

// Lay ma benh nhan
int BenhNhan ::getMaBN()
{
    return maBN;
}

// Lay so lan kham
int BenhNhan ::getSoLanKham()
{
    return soLanKham;
}

// Lay tien thuoc
long long BenhNhan ::getTienThuoc()
{
    return tienThuoc;
}

// Lay trang thai bao hiem
bool BenhNhan ::getBaoHiem()
{
    return baoHiem;
}

// Them bac si cho benh nhan
void BenhNhan ::themBacSi(Nguoi *BS)
{
    DSBacSi.push_back(BS);
}

// Tinh tien thuoc cho benh nhan
void BenhNhan ::tinhTienThuoc()
{
    tienThuoc = 100000 * soLanKham;
    if (soLanKham >= 5)
    {
        tienThuoc += (soLanKham - 4) * 70000;
    }

    if (this->baoHiem)
    {
        tienThuoc = tienThuoc - tienThuoc * 0.8;
    }
}

// Xuat thong tin benh nhan
void BenhNhan ::xuat()
{
    cout << "Thong tin benh nhan: " << endl;
    Nguoi ::xuat();
    cout << "    + Ma benh nhan: " << maBN << endl;
    cout << "    + So lan kham benh: " << soLanKham << endl;
    cout << "    + Tien thuoc: " << tienThuoc << endl;
    cout << "    + Tinh trang bao hiem: " << (baoHiem ? "Co" : "Khong co") << endl;
    cout << "    + Danh sach bac si: ";
    for (int i = 0; i < DSBacSi.size(); i++)
    {
        cout << DSBacSi[i]->getTen() << ", ";
    }
    cout << endl;
}

// Lop BenhVien
class BenhVien
{
private:
    string ten;
    string diaChi;
    vector<BacSi *> danhSachBS;
    vector<BenhNhan *> danhSachBN;

public:
    BenhVien();
    ~BenhVien();
    void loadData(int, int);                     // Tao du lieu
    void xuatDanhSachBS();                       // Xuat danh sach bac si
    void xuatDanhSachBN();                       // Xuat danh sach benh nhan
    bool timBacSi(int ma, BacSi *&BS);           // Tim bac si theo ma bac si
    bool timBenhNhan(int ma, BenhNhan *&BN);     // Tim benh nhan theo ma benh nhan
    void tinhTienThuoc();                        // Tinh tien thuoc cho benh nhan
    void tinhTienKhamBenh();                     // Tinh tien cong kham benh cho bac si
    vector<BacSi *> BSCoTienCongLonNhat();       // Tim cac bac si co tien cong kham benh lon nhat
    vector<BenhNhan *> BNCoSoLanKhamNhieuNhat(); // Tim benh nhan co so lan kham benh nhieu nhat
};

BenhVien ::BenhVien() {}
BenhVien ::~BenhVien() {}
// Tao du lieu
void BenhVien ::loadData(int soBS, int soBN)
{
    srand(time(NULL));
    // Tao danh sach bac si
    for (int i = 0; i < soBS; i++)
    {
        BacSi *BS = new BacSi(tenBS[i % 50], (rand() % 30) + 30, rand() % 2, 2000 + i);
        danhSachBS.push_back(BS);
    }
    // Tao danh sach benh nhan
    for (int i = 0; i < soBN; i++)
    {
        BenhNhan *BN = new BenhNhan(tenBN[i % 50], (rand() % 50) + 10, rand() % 2, 1000 + i, (rand() % 7) + 3, rand() % 2);
        danhSachBN.push_back(BN);
    }
    // Them Bac si va benh nhan vao danh sach kham, chua benh cua nhau
    for (int i = 0; i < danhSachBN.size(); i++)
    {
        int k = danhSachBN[i]->getSoLanKham();
        for (int j = 1; j <= k; j++)
        {
            random_device rd;
            mt19937 generator(rd());
            uniform_int_distribution<int> distribution(0, soBS - 2);
            int randBS = distribution(generator);
            danhSachBN[i]->themBacSi(danhSachBS[randBS]);
            danhSachBS[randBS]->themBenhNhan(danhSachBN[i]);
        }
    }
}

// Xuat danh sach bac si
void BenhVien ::xuatDanhSachBS()
{
    if (danhSachBS.empty())
    {
        cout << "Danh sach rong !" << endl;
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =                      DANH SACH BAC SI                  =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < danhSachBS.size(); i++)
    {
        danhSachBS[i]->xuat();
    }
}

// Xuat danh sach benh nhan
void BenhVien ::xuatDanhSachBN()
{
    if (danhSachBN.empty())
    {
        cout << "Danh sach rong !" << endl;
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =                   DANH SACH BENH NHAN                  =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < danhSachBN.size(); i++)
    {
        danhSachBN[i]->xuat();
    }
}

/*
Tim bac si
Input:
    + int ma (ma bac si can tim)
    + thuoc tinh danhSachBS
Output:
    + return -> true (tim thay), false (khong thay)
*/
bool BenhVien ::timBacSi(int ma, BacSi *&BS)
{
    for (int i = 0; i < danhSachBS.size(); i++)
    {
        if (danhSachBS[i]->getMaBS() == ma)
        {
            BS = danhSachBS[i];
            return true;
        }
    }
    return false;
}

/*
Tim benh nhan
Input:
    + int ma (ma benh nhan can tim)
    + thuoc tinh danhSachBN
Output:
    + return -> true (tim thay), false (khong thay)
*/
bool BenhVien ::timBenhNhan(int ma, BenhNhan *&BN)
{
    for (int i = 0; i < danhSachBN.size(); i++)
    {
        if (danhSachBN[i]->getMaBN() == ma)
        {
            BN = danhSachBN[i];
            return true;
        }
    }
    return false;
}

// Tinh tien thuoc cho benh nhan
void BenhVien ::tinhTienThuoc()
{
    for (int i = 0; i < danhSachBN.size(); i++)
    {
        danhSachBN[i]->tinhTienThuoc();
    }
}

// Tinh tien kham benh cho bac si
void BenhVien ::tinhTienKhamBenh()
{
    for (int i = 0; i < danhSachBS.size(); i++)
    {
        danhSachBS[i]->tinhTienCong();
    }
}

/*
Tim cac bac si co tien cong kham benh lon nhat
Input:
    + Thuoc tinh danhSachBS
Output:
    + return DSBacSiTienCongCao (danh sach gom cac bac si co tien cong cao nhat)
*/
vector<BacSi *> BenhVien ::BSCoTienCongLonNhat()
{
    vector<BacSi *> DSBacSiTienCongCao;
    long long tienCongMax = danhSachBS[0]->getTienCong();
    for (int i = 1; i < danhSachBS.size(); i++)
    {
        if (danhSachBS[i]->getTienCong() > tienCongMax)
            tienCongMax = danhSachBS[i]->getTienCong();
    }

    for (int i = 0; i < danhSachBS.size(); i++)
    {
        if (danhSachBS[i]->getTienCong() == tienCongMax)
            DSBacSiTienCongCao.push_back(danhSachBS[i]);
    }
    return DSBacSiTienCongCao;
}

/*
Tim cac benh nhan co so lan kham nhieu nhat
Input:
    + Thuoc tinh danhSachBN
Output:
    + return DSBenhNhanKhamNhieu (danh sach gom cac benh nhan co so lan kham nhieu nhat)
*/
vector<BenhNhan *> BenhVien ::BNCoSoLanKhamNhieuNhat()
{
    vector<BenhNhan *> DSBenhNhanKhamNhieu;
    int solanMax = danhSachBN[0]->getSoLanKham();
    for (int i = 1; i < danhSachBN.size(); i++)
    {
        if (danhSachBN[i]->getSoLanKham() > solanMax)
        {
            solanMax = danhSachBN[i]->getSoLanKham();
        }
    }

    for (int i = 0; i < danhSachBN.size(); i++)
    {
        if (danhSachBN[i]->getSoLanKham() == solanMax)
        {
            DSBenhNhanKhamNhieu.push_back(danhSachBN[i]);
        }
    }
    return DSBenhNhanKhamNhieu;
}

// main

static BenhVien ChoRay;

// Tao du lieu cho benh vien
void taoDuLieu()
{
    int a, b;
    cout << "Nhap so luong bac si: ";
    cin >> a;
    cout << "Nhap so luong benh nhan: ";
    cin >> b;
    ChoRay.loadData(a, b);
    cout << "Tao du lieu thanh cong !" << endl;
}

// In danh sach bac si
void inDSBS()
{
    ChoRay.xuatDanhSachBS();
}

// In danh sach benh nhan
void inDSBN()
{
    ChoRay.xuatDanhSachBN();
}

// Tim bac si theo ma
void timBacSi()
{
    int ma;
    BacSi *BS;
    cout << "Nhap ma bac si can tim: ";
    bool found = ChoRay.timBacSi(ma, BS);
    if (found)
        BS->xuat();
    else
        cout << "Khong tim thay bac si co ma " << ma << " !" << endl;
}

// Tim benh nhan theo ma
void timBenhNhan()
{
    int ma;
    BenhNhan *BN;
    cout << "Nhap ma bac si can tim: ";
    bool found = ChoRay.timBenhNhan(ma, BN);
    if (found)
        BN->xuat();
    else
        cout << "Khong tim thay bac si co ma " << ma << " !";
}

// Tinh tien thuoc
void tinhTienThuoc()
{
    ChoRay.tinhTienThuoc();
    cout << "Tinh tien thuoc thanh cong !" << endl;
}

// Tinh tien kham benh
void tinhTienKhamBenh()
{
    ChoRay.tinhTienKhamBenh();
    cout << "Tinh tien kham benh thanh cong !" << endl;
}
// Cac bac si co tien cong kham benh cao nhat
void BacSiCoTienCongCaoNhat()
{
    vector<BacSi *> result;
    result = ChoRay.BSCoTienCongLonNhat();
    if (result.empty())
    {
        cout << "Danh sach rong !";
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =    DANH SACH BAC SI CO TIEN CONG KHAM BENH CAO NHAT    =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        result[i]->xuat();
    }
}

// Cac benh nhan co so lan kham benh nhieu nhat
void BenhNhanKhamBenhNhieuNhat()
{
    vector<BenhNhan *> result;
    result = ChoRay.BNCoSoLanKhamNhieuNhat();
    if (result.empty())
    {
        cout << "Danh sach rong !";
        return;
    }
    cout << "            ==========================================================" << endl;
    cout << "            =   DANH SACH BENH NHAN CO SO LAN KHAM BENH NHIEU NHAT   =" << endl;
    cout << "            ==========================================================" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        result[i]->xuat();
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
        cout << "2. In danh sach bac si" << endl;
        cout << "3. In danh sach benh nhan" << endl;
        cout << "4. Tim bac si theo ma bac si" << endl;
        cout << "5. Tim benh nhan theo ma benh nhan" << endl;
        cout << "6. Tinh tien thuoc" << endl;
        cout << "7. Tinh tien kham benh " << endl;
        cout << "8. Hien thi cac bac si co tien cong kham benh cao nhat" << endl;
        cout << "9. Hien thi cac benh nhan co so lan kham benh nhieu nhat" << endl;
        cout << "0. Exit" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            taoDuLieu();
            break;
        case 2:
            system("cls");
            inDSBS();
            break;
        case 3:
            system("cls");
            inDSBN();
            break;
        case 4:
            system("cls");
            timBacSi();
            break;
        case 5:
            system("cls");
            timBenhNhan();
            break;
        case 6:
            system("cls");
            tinhTienThuoc();
            break;
        case 7:
            system("cls");
            tinhTienKhamBenh();
            break;
        case 8:
            system("cls");
            BacSiCoTienCongCaoNhat();
            break;
        case 9:
            system("cls");
            BenhNhanKhamBenhNhieuNhat();
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
