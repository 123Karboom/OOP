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
    void xuatToaDo();                          // 2. Xuat toa do mot diem
    float getY();                              // 3. lay tung do mot diem
    float getX();                              // 3. lay hoanh do mot diem
    void thayDoiTungDo(float y);               // 4. thay doi tung do
    void thayDoiHoanhDo(float x);              // 4. thay doi hoanh do
    void diChuyenDenToaDo(float x, float y);   // 5. di chuyen den toa do
    float khoangCachHaiDiem(ToaDo p);          // 6. tinh khoang cach 2 diem
    ToaDo toaDoTrungDiem(ToaDo p);             // 7. tim toa do trung diem khi biet 2 diem
    void xoaToaDo();                           // 8. xoa toa do mot diem
    ToaDo saoChepToaDo();                      // 9. sao chep diem toa do
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
    return ToaDo
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

class TamGiac
{
private:
    ToaDo A, B, C;

public:
    TamGiac(ToaDo _A, ToaDo _B, ToaDo _C) : A(_A), B(_B), C(_C) {} // constructor

    void xuatThongTin(); // 2. xuat thong tin tam giac
    void xetLoaiTamGiac();  // 3. xet loai tam giac
    float tinhChuVi(); // 4. tinh chu vi tam giac
    float tinhDienTich(); // 5. tinh dien tich tam giac
};

void TamGiac::xuatThongTin()
{
    cout << "Toa do diem A: (" << A.getX() << ", " << A.getY() << ")" << endl;
    cout << "Toa do diem B: (" << B.getX() << ", " << B.getY() << ")" << endl;
    cout << "Toa do diem C: (" << C.getX() << ", " << C.getY() << ")" << endl;
}

/*3. xet loai tam giac
Input:
    + thuoc tinh A, B, C
Output:
    + In ra loai cua tam giac
*/
void TamGiac::xetLoaiTamGiac()
{
    float a = A.khoangCachHaiDiem(B);
    float b = A.khoangCachHaiDiem(C);
    float c = B.khoangCachHaiDiem(C);

    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && a == c)
        {
            cout << "Tam giac deu" << endl;
        }
        else if (a == b || a == c || b == c)
        {
            cout << "Tam giac can" << endl;
        }
        else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
        {
            cout << "Tam giac vuong" << endl;
        }
        else
        {
            cout << "Tam giac thuong" << endl;
        }
    }
    else
    {
        cout << "Khong phai tam giac" << endl;
    }
}

/* 4. tinh chu vi tam giac
Input:
    + thuoc tinh A, B, C
Output:
    + return a + b + c => tong 3 canh = chu vi tam giac
*/
float TamGiac::tinhChuVi()
{
    float a = A.khoangCachHaiDiem(B);
    float b = A.khoangCachHaiDiem(C);
    float c = B.khoangCachHaiDiem(C);
    return a + b + c;
}

/* 5. tinh dien tich tam giac
Input:
    + thuoc tinh A, B, C
Output:
    + return dientich => dien tich tam giac
*/
float TamGiac::tinhDienTich()
{
    float a = A.khoangCachHaiDiem(B);
    float b = A.khoangCachHaiDiem(C);
    float c = B.khoangCachHaiDiem(C);
    float p = (a + b + c) / 2;
    float dientich = sqrt(p * (p - a) * (p - b) * (p - c));
    return dientich;
}

int main()
{
    // Khởi tạo tam giác
    ToaDo A(0, 0);
    ToaDo B(3, 0);
    ToaDo C(0, 4);
    TamGiac tamGiac(A, B, C);

    // Xuất thông tin tam giác
    std::cout << "Thong tin tam giac:" << std::endl;
    tamGiac.xuatThongTin();

    // Xét loại tam giác
    std::cout << "Loai tam giac: ";
    tamGiac.xetLoaiTamGiac();

    // Tính chu vi
    float chuVi = tamGiac.tinhChuVi();
    std::cout << "Chu vi tam giac: " << chuVi << std::endl;

    // Tính diện tích
    float dienTich = tamGiac.tinhDienTich();
    std::cout << "Dien tich tam giac: " << dienTich << std::endl;

    return 0;
}
