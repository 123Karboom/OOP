#include <bits/stdc++.h>
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
                "Minh Hoang Quoc", "Thi Quoc Linh", "Quoc Hoang Minh", "Van Quoc Linh", "Nguyen Quoc Hoang"};

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
                        "237 Cong Hoa, Quang Tri", "570 Kim Dong, Thua Thien Hue" };

class SinhVien
{
protected:
    string hoTen;
    int maSo;
    string diaChi;
    int soTinChi;
    double diemTB;

public:
    SinhVien()
    {
        hoTen = diaChi = "";
        maSo = soTinChi = 0;
        diemTB = 0;
    }
    SinhVien(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB)
    {
        this->hoTen = hoTen;
        this->diaChi = diaChi;
        this->maSo = maSo;
        this->soTinChi = soTinChi;
        this->diemTB = diemTB;
    }

    string getHoTen()
    {
        return hoTen;
    }

    int getMaSo()
    {
        return maSo;
    }

    double getdiemTB()
    {
        return diemTB;
    }

    virtual void xuat() const
    {
        cout << "Ho va ten: " << hoTen << endl;
        cout << "Ma so: " << maSo << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong so tin chi: " << soTinChi << endl;
        cout << "Diem trung binh: " << diemTB << endl;
    }
    virtual bool totNghiep() = 0;
    virtual bool laSVDH() = 0;
};

class SinhVienVB2 : public SinhVien
{
private:
    double diemThi;

public:
    SinhVienVB2() : SinhVien()
    {
        diemThi = 0;
    }

    SinhVienVB2(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB, double diemThi) : SinhVien(hoTen, maSo, diaChi, soTinChi, diemTB)
    {
        this->diemThi = diemThi;
    }

    void xuat() const
    {
        SinhVien ::xuat();
        cout << "Diem thi tot nghiep: " << diemThi << endl;
    }

    bool totNghiep()
    {
        if (soTinChi >= 84 && diemTB >= 5 && diemThi >= 5)
            return true;
        else
            return false;
    }

    bool laSVDH()
    {
        return false;
    }
};

class SinhVienDH : public SinhVien
{
private:
    string tenLV;
    double diemLV;

public:
    SinhVienDH() : SinhVien()
    {
        tenLV = "";
        diemLV = 0;
    }

    SinhVienDH(string hoTen, int maSo, string diaChi, int soTinChi, double diemTB, string tenLV, double diemLV) : SinhVien(hoTen, maSo, diaChi, soTinChi, diemTB)
    {
        this->tenLV = tenLV;
        this->diemLV = diemLV;
    }

    void xuat() const
    {
        SinhVien ::xuat();
        cout << "Ten luan van: " << tenLV << endl;
        cout << "Diem luan van: " << diemLV << endl;
    }

    bool totNghiep()
    {
        if (soTinChi >= 120 && diemTB >= 5 && diemLV >= 5)
            return true;
        else
            return false;
    }

    bool laSVDH()
    {
        return true;
    }
};

class DaiHoc
{
private:
    vector<SinhVien *> danhSachSV;
    string tenTruong = "UIT";

public:
    DaiHoc() {}
    void taoDanhSach();
    void xuatDanhSach();
    // void xetTotNghiep();
    vector<SinhVien *> SVTotNghiep();
    vector<SinhVien *> SVKoTotNghiep();
    vector<SinhVien *> SVVB2DiemTBThapNhat();
    vector<SinhVien *> SVDiemTBCaoNhat();
};

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
        danhSachSV.push_back(new SinhVienDH(names[i], 22520000 + i, addresses[i], (rand() % 20) + 110, diemTB, tenLV, diemLV));
    }

    for (int i = 0; i <= n; i++)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(4.1, 9.9);
        double diemTB = dis(gen);
        double diemThi = dis(gen);
        danhSachSV.push_back(new SinhVienVB2(names[i], 22530000 + i, addresses[i], (rand() % 30) + 70, diemTB, diemThi));
    }
}

void DaiHoc ::xuatDanhSach()
{
    cout << "-----------------------------DANH SACH SINH VIEN-----------------------------\n";
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        danhSachSV[i]->xuat();
        cout << "________________________________________\n";
    }
}

vector<SinhVien *> DaiHoc ::SVTotNghiep()
{
    vector<SinhVien *> DSSVTotNghiep;
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (danhSachSV[i]->totNghiep())
        {
            DSSVTotNghiep.push_back(danhSachSV[i]);
        }
    }
    return DSSVTotNghiep;
}

vector<SinhVien *> DaiHoc ::SVKoTotNghiep()
{
    vector<SinhVien *> DSSVKoTotNghiep;
    for (int i = 0; i < danhSachSV.size(); i++)
    {
        if (!danhSachSV[i]->totNghiep())
        {
            DSSVKoTotNghiep.push_back(danhSachSV[i]);
        }
    }
    return DSSVKoTotNghiep;
}

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


int main()
{
    DaiHoc UIT;
    UIT.taoDanhSach();
    // UIT.xuatDanhSach();
}
