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
        cout << "\t+ Ma sach: " << maSach << endl;
        cout << "\t+ Ten sach: " << tenSach << endl;
        cout << "\t+ Nha xuat ban: " << nhaXuatBan << endl;
        cout << "\t+ So luong: " << soLuong << endl;
        cout << "\t+ Don Gia: " << donGia << endl;
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
    bool nhap;

public:
    SachGiaoKhoa();
    SachGiaoKhoa(int, string, string, int, long long, bool);
    ~SachGiaoKhoa();
    long long tinhTien() override;
    void xuat() const override;
    void setNhap();
    bool getNhap();
};

void SachGiaoKhoa ::setNhap()
{
    this->nhap = true;
}

bool SachGiaoKhoa ::getNhap()
{
    return nhap;
}

SachGiaoKhoa ::SachGiaoKhoa() : Sach()
{
    this->tinhTrang = true;
    this->nhap = false;
}

SachGiaoKhoa ::SachGiaoKhoa(int ma, string ten, string nxb, int sl, long long gia, bool tinhTrang) : Sach(ma, ten, nxb, sl, gia)
{
    this->tinhTrang = tinhTrang;
    this->nhap = false;
}

long long SachGiaoKhoa ::tinhTien()
{
    if (tinhTrang)
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
    cout << "\n Thong tin sach giao khoa: \n";
    Sach ::xuat();
    if (tinhTrang)
        cout << "\t + Sach moi";
    else
        cout << "\t+ Sach cu";
    cout << endl;
    cout <<"\t+Nguoi dung nhap: " << nhap << endl;
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
    cout << "\n Thong tin sach tham khao: \n";
    Sach ::xuat();
    cout << "\t+ Tien thue: " << tienThue << endl;
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
    SachGiaoKhoa *sgk = new SachGiaoKhoa(101,"Toan", "NXB Giao Duc", 10, 15000, 0);
    sgk->setNhap();
    dsSach.push_back(sgk);

    SachGiaoKhoa *sgk1 = new SachGiaoKhoa(104,"Sinh Hoc", "NXB Giao Duc", 10, 25000, 1);
    sgk1->setNhap();
    dsSach.push_back(sgk1);
    dsSach.push_back(new SachGiaoKhoa(105,"Hoa hoc", "NXB Giao Duc", 10, 23000, 1));

    dsSach.push_back(new SachThamKhao(203, "9+ Tieng anh", "Ngoc Du", 10, 80000, 30000 ));
    dsSach.push_back(new SachThamKhao(204, "9+ Hoa hoc", "Ngoc Du", 8, 20000, 30000 ));
}

void ThuVien ::xuat()
{
    for (auto x : dsSach)
    {
        x->xuat();
    }
}

vector<Sach *> ThuVien ::sachItTienNhat()
{
    vector<Sach *> book;
    int minTien = INT_MAX;

    for (auto x : dsSach)
    {
        if (x->tinhTien() < minTien)
        {
            minTien = x->tinhTien();
        }
    }

    for (auto x : dsSach)
    {
        if (x->tinhTien() == minTien)
        {
            book.push_back(x);
        }
    }

    return book;
}

void ThuVien ::tinhThanhTien()
{
    for (auto x : dsSach)
    {
        x->tinhTien();
    }

    vector<Sach *> books = sachItTienNhat();
    for (auto x : dsSach)
    {
        x->xuat();
    }
}

vector<Sach *> ThuVien ::timSach()
{
    cout << " SACH DO NGUOI DUNG NHAP VAO: \n";
    vector<Sach *> books;
    for (int i = 0; i < dsSach.size(); i++)
    {
        SachGiaoKhoa *sgk = dynamic_cast<SachGiaoKhoa *>(dsSach[i]);
        if (sgk && sgk->getNhap())
        {
                books.push_back(sgk);
        }
    }
    return books;
}

int main()
{
    ThuVien UIT;
    UIT.nhap();
    UIT.xuat();
    vector<Sach *> ans;
    ans = UIT.timSach();
    for (auto x : ans)
    {
        x->xuat();
    }
}
