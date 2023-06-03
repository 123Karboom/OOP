#include <bits/stdc++.h>
using namespace std;

class Sach
{
protected:
    int maSach;
    string tenSach;
    string nhaXuatBan;
    int soLuong;
    long long donGia;
    long long thanhTien;
public:
    Sach()
    {
        maSach = soLuong = 0;
        tenSach = nhaXuatBan = "";
        donGia = 0;
    }
    Sach(int ma, string ten, string nxb, int sl, long long gia) : maSach(ma), tenSach(ten), nhaXuatBan(nxb), soLuong(sl), donGia(gia) {}
    ~Sach() {}

    virtual long long tinhTien() = 0;
    virtual void xuat() const
    {
        cout <<"\t+ Ma sach: " << maSach << endl;
        cout <<"\t+ Ten sach: " << tenSach << endl;
        cout <<"\t+ Nha xuat ban: " << nhaXuatBan << endl;
        cout <<"\t+ So luong: " << soLuong << endl;
        cout <<"\t+ Don Gia: " << donGia << endl;
    }

    int getMaSach()
    {
        return maSach;
    }

    string getTenSach()
    {
        return tenSach;
    }

    string getNXB()
    {
        return nhaXuatBan;
    }

    int getSoLuong()
    {
        return soLuong;
    }

    long long getDonGia()
    {
        return donGia;
    }

    void setDonGia(long long gia)
    {
        this->donGia = gia;
    }
};

class SachGiaoKhoa : public Sach
{
private:
    bool tinhTrang;
public:
    SachGiaoKhoa();
    SachGiaoKhoa(int, string, string, int, long long, bool);
    ~SachGiaoKhoa();
    long long tinhTien() override;
    void xuat() const override;
};

SachGiaoKhoa ::SachGiaoKhoa() : Sach()
{
    this->tinhTrang = true;
}

SachGiaoKhoa ::SachGiaoKhoa(int ma, string ten, string nxb, int sl, long long gia, bool tinhTrang) : Sach(ma, ten, nxb, sl, gia)
{
    this->tinhTrang = tinhTrang;
}

long long SachGiaoKhoa ::tinhTien()
{
    if(tinhTrang)
    {
        thanhTien = donGia * soLuong;
    }
    else
    {
        thanhTien = donGia * soLuong * 0.5;
    }
    return thanhTien;
}

void SachGiaoKhoa ::xuat() const
{
    cout<<"\n Thong tin sach giao khoa: \n";
    Sach ::xuat();
    cout << (tinhTrang) ? "\t+ Sach moi" : "\t+Sach cu";
    cout << endl;
}

class SachThamKhao : public Sach
{
private:
    long long tienThue;
public:
    SachThamKhao();
    SachThamKhao(int, string, string, int, long long, long long);
    ~SachThamKhao();
    long long tinhTien() override;
    void xuat() const override;
};

SachThamKhao ::SachThamKhao() : Sach()
{
    this->tienThue = 0;
}

SachThamKhao ::SachThamKhao(int ma, string ten, string nxb, int sl, long long gia, long long tienThue) : Sach(ma, ten, nxb, sl, gia)
{
    this->tienThue = tienThue;
}

long long SachThamKhao ::tinhTien()
{
    thanhTien = soLuong * donGia + tienThue;
    return thanhTien;
}

void SachThamKhao ::xuat() const
{
    cout<<"\n Thong tin sach tham khao: \n";
    Sach ::xuat();
    cout <<"\t+ Tien thue: " << tienThue << endl;
}

class ThuVien
{
private:
    vector<Sach *> dsSach;
public:
    void nhap();
    void xuat();
    vector<Sach *> sachItTienNhat();
    void tinhThanhTien();
    vector<Sach *> timSach();
};

void ThuVien ::nhap()
{
    
}
