#include <bits/stdc++.h>
using namespace std;

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
    SinhVien (string hoTen, int maSo, string diaChi, int soTinChi, double diemTB)
    {
        this->hoTen = hoTen;
        this->diaChi = diaChi;
        this->maSo = maSo;
        this->soTinChi = soTinChi;
        this->diemTB = diemTB;
    }
    virtual void xuat() const
    {
        cout <<"Ho va ten: " << hoTen << endl;
        cout <<"Ma so: " << maSo << endl;
        cout <<"Dia chi: " << diaChi << endl;
        cout <<"Tong so tin chi: " << soTinChi << endl;
        cout <<"Diem trung binh: " << diemTB << endl;
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

    void xuat()
    {
        SinhVien ::xuat();
        cout << "Ten luan van: " << tenLV << endl;
        cout <<"Diem luan van: " << diemLV << endl;
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
    vector<SinhVien*> danhSachSV;
    string tenTruong = "UIT";
public: 
    DaiHoc() {}
    void taoDanhSach();
    void xuatDanhSach();
    void xetTotNghiep();
    vector<SinhVien*> SVTotNghiep();
    vector<SinhVien*> SVKoTotNghiep();
    vector<SinhVien*> SVVB2DiemTBThapNhat();
    vector<SinhVien*> SVDiemTBCaoNhat();
};


int main()
{
    SinhVienVB2 A;
    SinhVienDH B;
}



