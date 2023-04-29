#include <bits/stdc++.h>
using namespace std;

class ToaDo
{
private:
    float x;
    float y;

public:
    // Constructor
    ToaDo(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }
    // Copy Constructor
    ToaDo(const ToaDo &other)
    {
        x = other.x;
        y = other.y;
    }
    void xuatToaDo();       //2. Xuat toa do mot diem
    float getY();      // 3. lay tung do mot diem
    float getX();     // 3. lay hoanh do mot diem
    void thayDoiTungDo(float y); // 4. thay doi tung do
    void thayDoiHoanhDo(float x);// 4. thay doi hoanh do
    void diChuyenDenToaDo(float x, float y); //5. di chuyen den toa do
    float khoangCachHaiDiem(ToaDo p);// 6. tinh khoang cach 2 diem
    ToaDo toaDoTrungDiem(ToaDo p); // 7. tim toa do trung diem khi biet 2 diem
    void xoaToaDo(); // 8. xoa toa do mot diem
    ToaDo saoChepToaDo(); // 9. sao chep diem toa do
    ToaDo toaDoGanTamNhat(ToaDo arr[], int n); // 10. Timm toa do co khoang cach gan tam O nhat
};

void ToaDo ::xuatToaDo()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

float ToaDo ::getY()
{
    return y;
}

float ToaDo ::getX()
{
    return x;
}

void ToaDo ::thayDoiTungDo(float y)
{
    y = y;
}

void ToaDo ::thayDoiHoanhDo(float x)
{
    x = x;
}

void ToaDo ::diChuyenDenToaDo(float x, float y)
{
    x = x;
    y = y;
}
/*6. tinh khoang cach 2 diem
Input:
    + Toa do diem 1: thuoc tinh x, thuoc tinh y
    + Toa do diem 2: p
Output: 
    + khoang cach hai diem
*/
float ToaDo ::khoangCachHaiDiem(ToaDo p)
{
    return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
}

/* 7. tim toa do trung diem khi biet 2 diem
Input: 
    + Toa do diem thu nhat: thuoc tinh x, thuoc tinh y
    + Toa do diem thu hai: p
Output:
    + return ToaDo(x,y) => Toa do trung diem cua 2 diem
*/
ToaDo ToaDo ::toaDoTrungDiem(ToaDo p)
{
    float x = (x + p.x) / 2;
    float y = (y + p.y) / 2;
    return ToaDo(x, y);
}
/* 8. Xoa toa do mot diem
Input:
    + thuoc tinh x
    + thuoc tinh y
*/
void ToaDo ::xoaToaDo()
{
    x = 0;
    y = 0;
}
/* 9. sao chep toa do
Input:
    + thuoc tinh x, thuoc tinh y cua doi tuong goi ham
Ouput:
    return ToaDo(*this) => doi tuong moi giong voi toa do hien tai
*/
ToaDo ToaDo ::saoChepToaDo()
{
    return ToaDo(*this); // Tạo một đối tượng mới bằng cách sử dụng copy constructor
}
/* 10. Timm toa do co khoang cach gan tam O nhat
Input: 
    + mot mang cac toa do: arr
    + so luong phan tu trong mang: n
Output:
    + return toaDoGanTam => Toa do gan tam O nhat 
*/
ToaDo ToaDo ::toaDoGanTamNhat(ToaDo arr[], int n)
{
    ToaDo toaDoGanTam = arr[0];
    float khoangCachMin = khoangCachHaiDiem(arr[0]);
    for (int i = 1; i < n; i++)
    {
        float khoangCach = khoangCachHaiDiem(arr[i]);

        if (khoangCach < khoangCachMin)
        {
            khoangCachMin = khoangCach;
            toaDoGanTam = arr[i];
        }
    }
    return toaDoGanTam;
}

class DuongTron
{
private:
    ToaDo tam;
    float banKinh;

public:
    DuongTron(ToaDo _tam, float _banKinh) : tam(_tam), banKinh(_banKinh) {} // Constructor
    void xuat();                                                            // 2. xuat thong tin duong tron
    float tinhChuVi();                                                      // 3. tinh chu vi
    float tinhDienTich();                                                   // 4. tinh dien tich
    void phongTo(float phanTram);                                           // 5. phong to duong tron theo phan tram
    void thuNho(float phanTram);                                            // 6. thu nho duong trong theo phan tram
    int kiemTraViTri(DuongTron dt);                                         // 7. kiem tra vi tri tuong doi cua hai duong tron
};

void DuongTron ::xuat()
{
    cout << "Tam: (" << tam.getX() << ", " << tam.getY() << ")" << endl;
    cout << "Ban kinh: " << banKinh << endl;
}
/*3. tinh chu vi
Input:
    + thuoc tinh banKinh
Output:
    + return 2 * M_PI * banKinh => chu vi duong tron
*/
float DuongTron ::tinhChuVi()
{
    return 2 * M_PI * banKinh;
}
/*4. tinh dien tich
Input:
    + thuoc tinh banKinh
Output:
    + return M_PI * banKinh * banKinhh => dien tich duong tron
*/
float DuongTron ::tinhDienTich()
{
    return M_PI * banKinh * banKinh;
}

/* 5. phong to duong tron theo phan tram
Input:
    + pham tram phong to: phanTram
*/
void DuongTron ::phongTo(float phanTram)
{
    banKinh *= (1 + phanTram / 100);
}

/* 5. thu nho duong tron theo phan tram
Input:
    + pham tram thu nho: phanTram
*/
void DuongTron ::thuNho(float phanTram)
{
    banKinh *= (1 - phanTram / 100);
}
/* 7. kiem tra vi tri tuong doi cua hai duong tron*/
/*
Input:
    +Duong tron 1: thuoc tinh tam, thuoc tinh banKinh
    +Duong tron 2: dt
Output:
    return => 1(giao nhau), 2(khong giao), 3(Duong tron 2 nam trong duong tron 1), 
    4(Duong trong 1 nam trong duong tron 2), 5(tiep xuc trong), 6(tiep xuc ngoai)
*/
int DuongTron ::kiemTraViTri(DuongTron dt)
{
    double khoangCach = tam.khoangCachHaiDiem(dt.tam);
    double tongBanKinh = banKinh + dt.banKinh;
    double hieuBanKinh = abs(banKinh - dt.banKinh);
    if (hieuBanKinh < khoangCach && khoangCach < tongBanKinh)
        return 1;
    if (khoangCach > tongBanKinh)
        return 2;
    if (khoangCach < hieuBanKinh)
    {
        if (dt.banKinh < banKinh)
            return 3;
        else
            return 4;
    }
    if (khoangCach == hieuBanKinh)
        return 5;
    if (khoangCach == tongBanKinh)
        return 6;
    return 0;
}
int main()
{
    // Tạo hai đường tròn
    DuongTron dt1(ToaDo(0, 5), 10); // Đường tròn 1 với tâm là điểm (0, 0) và bán kính là 5
    DuongTron dt2(ToaDo(0, 1), 8); // Đường tròn 2 với tâm là điểm (10, 0) và bán kính là 3

    cout << "Duong tron 1: " << endl;
    dt1.xuat();
    cout << "Dien tich: " << dt1.tinhDienTich() << endl;
    cout << "Chu vi: " << dt1.tinhChuVi() << endl;
    cout << endl;

    cout << "Duong tron 2: " << endl;
    dt2.xuat();
    cout << "Dien tich: " << dt2.tinhDienTich() << endl;
    cout << "Chu vi: " << dt2.tinhChuVi() << endl;
    cout << endl;

    // Phóng to đường tròn
    dt1.phongTo(50);
    std::cout << "Duong tron 1 sau khi phong to 50%:" << endl;
    dt1.xuat();
    cout << endl;

    // Thu nhỏ đường tròn
    dt1.thuNho(30);
    std::cout << "Duong tron 1 sau khi thu nho 30%:" << endl;
    dt1.xuat();
    cout << endl;

    int check = dt1.kiemTraViTri(dt2);
    switch (check)
    {
    case 1:
        cout << "Hai duong tron giao nhau." << endl;
        break;
    case 2:
        cout << "Hai duong tron khong giao nhau." << endl;
        break;
    case 3:
        cout << "Duong tron 2 nam trong duong tron 1." << endl;
        break;
    case 4:
        cout << "Duong tron 1 nam trong duong tron 2." << endl;
        break;
    case 5:
        cout << "Hai duong tron tiep xuc trong nhau." << endl;
        break;
    case 6:
        cout << "Hai duong tron tiep xuc ngoai nhau." << endl;
        break;
    default:
        break;
    }

    return 0;
}
