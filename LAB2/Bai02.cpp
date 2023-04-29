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

int main()
{
    // Khởi tạo một điểm
    ToaDo diem(3, 4);

    // Xuất tọa độ của điểm
    cout << "Toa do cua diem A: ";
    diem.xuatToaDo();

    // Lấy tung độ, hoành độ của điểm
    cout << "Hoanh do: " << diem.getX() << endl;
    cout << "Tung do: " << diem.getY() << endl;

    // Thay đổi tung độ, hoành độ của điểm
    diem.thayDoiTungDo(5);
    diem.thayDoiHoanhDo(6);
    cout << "Sau khi thay doi toa do: ";
    diem.xuatToaDo();

    // Di chuyển đến tọa độ
    cout <<"Di chuyen den toa do (1,2): \n";
    diem.diChuyenDenToaDo(1, 2);
    cout << "Sau khi di chuyen den toa do: ";
    diem.xuatToaDo();

    // Tính khoảng cách hai điểm
    ToaDo diem2(7, 8);
    cout <<"Toa do cua diem B: ";
    diem2.xuatToaDo();
    float khoangCach = diem.khoangCachHaiDiem(diem2);
    cout << "Khoang cach hai diem A, B: " << khoangCach << endl;

    // Tìm tọa độ trung điểm khi biết hai điểm
    ToaDo trungDiem = diem.toaDoTrungDiem(diem2);
    cout << "Toa do trung diem: ";
    trungDiem.xuatToaDo();

    // Xóa tọa độ của điểm
    diem.xoaToaDo();
    cout << "Sau khi xoa toa do: ";
    diem.xuatToaDo();

    // Sao chép điểm tọa độ
    ToaDo diem3 = diem.saoChepToaDo();
    cout << "Toa do diem sao chep: ";
    diem3.xuatToaDo();

    // Tìm tọa độ có khoảng cách gần tâm 0 nhất trong nhiều tọa độ
    ToaDo arr[5] = {ToaDo(1, 2), ToaDo(3, 4), ToaDo(5, 6), ToaDo(7, 8), ToaDo(9, 10)};
    int n = 5;
    cout <<"Danh sach toa do: \n";
    for (int i = 0; i < n; i++)
    {
        arr[i].xuatToaDo();
    }
    ToaDo toaDoGanTam = diem.toaDoGanTamNhat(arr, n);
    cout << "Toa do gan tam O nhat: ";
    toaDoGanTam.xuatToaDo();

    return 0;
}
