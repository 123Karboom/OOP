#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
private:
    int tuSo;
    int mauSo;

public:
    PhanSo(int x = 0, int y = 1) // constructor
    {
        tuSo = x;
        mauSo = y;
    }
    // Copy constructor
    PhanSo(const PhanSo &ps)
    {
        this->tuSo = ps.tuSo;
        this->mauSo = ps.mauSo;
    }

    void xuat();                               // 2. xuat phan so
    void rutGon();                             // 3. rut gon phan so
    int soSanh(PhanSo &ps);                     // 4. so sanh 2 phan so
    PhanSo Cong(PhanSo &ps);                    // 5. cong 2 phan so
    PhanSo Tru(PhanSo &ps);                     // 6. tru 2 phan so
    PhanSo Nhan(PhanSo &ps);                    // 7. nhan 2 phan so
    PhanSo Chia(PhanSo &ps);                    // 8. chia hai phan so
    PhanSo saoChep() const;                    // 9. sao chep 2 phan so
    static PhanSo TimMax(PhanSo arr[], int n); // 10. tim phan so lon nhat
    PhanSo operator+(const PhanSo &ps) const;  // Phep cong hai phan so
    PhanSo operator-(const PhanSo &ps) const;  // Phep tru hai phan so
    PhanSo operator*(const PhanSo &ps) const;  // Phep nhan hai phan so
    PhanSo operator/(const PhanSo &ps) const;  // Phep chia hai phan so
    bool operator==(const PhanSo &ps) const;   // So sanh bang hai phan so
    bool operator<=(const PhanSo &ps) const;   // So sanh nho hon hoac bang hai phan so
    bool operator>=(const PhanSo &ps) const;   // So sanh lon hon hoac bang hai phan so
    bool operator<(const PhanSo &ps) const;    // So sanh nho hon hai phan so
    bool operator>(const PhanSo &ps) const;    // So sanh lon hon hai phan so
};
// Phep cong hai phan so
PhanSo PhanSo ::operator+(const PhanSo &ps) const
{
    PhanSo result;
    result.tuSo = this->tuSo * ps.mauSo + this->mauSo * ps.tuSo;
    result.mauSo = this->mauSo * ps.mauSo;
    result.rutGon();
    return result;
}
// Phep tru hai phan so
PhanSo PhanSo ::operator-(const PhanSo &ps) const
{
    PhanSo result;
    result.tuSo = this->tuSo * ps.mauSo - ps.tuSo * this->mauSo;
    result.mauSo = this->mauSo * ps.mauSo;
    result.rutGon();
    return result;
}
// Phep nhan hai phan so
PhanSo PhanSo ::operator*(const PhanSo &ps) const
{
    PhanSo result;
    result.tuSo = this->tuSo * ps.tuSo;
    result.mauSo = this->mauSo * ps.mauSo;
    result.rutGon();
    return result;
}
// Phep chia hai phan so
PhanSo PhanSo::operator/(const PhanSo &ps) const
{
    PhanSo result;
    result.tuSo = this->tuSo * ps.mauSo;
    result.mauSo = this->mauSo * ps.tuSo;
    result.rutGon();
    return result;
}
// So sanh bang hai phan so
bool PhanSo ::operator==(const PhanSo &ps) const
{
    return this->tuSo * ps.mauSo == ps.tuSo * this->mauSo;
}
// So sanh lon hon hoac bang hai phan so
bool PhanSo::operator>=(const PhanSo &ps) const
{
    return this->tuSo * ps.mauSo >= ps.tuSo * this->mauSo;
}
// So sanh nho hon hoac bang hai phan so
bool PhanSo ::operator<=(const PhanSo &ps) const
{
    return this->tuSo * ps.mauSo <= ps.tuSo * this->mauSo;
}
// So sanh lon hon hai phan so
bool PhanSo ::operator>(const PhanSo &ps) const
{
    return this->tuSo * ps.mauSo > ps.tuSo * this->mauSo;
}
// So sanh nho hon hai phan so
bool PhanSo::operator<(const PhanSo &ps) const
{
    return this->tuSo * ps.mauSo < ps.tuSo * this->mauSo;
}

void PhanSo ::xuat()
{
    cout << tuSo << "/" << mauSo;
}

void PhanSo ::rutGon()
{
    int ucln = gcd(this->tuSo, this->mauSo);
    tuSo = this->tuSo / ucln;
    mauSo = this->mauSo / ucln;
}
/* 4. So sanh hai phan so
Input:
    +phan so thu nhat: ps1
    +phan so thu 2: ps
Output:
    + = 0(hai phan so bang nhau), 1(phan so dau tien lon hon), -1(phan so dau tien be hon)
*/
int PhanSo ::soSanh(PhanSo &ps)
{
    PhanSo ps1(tuSo, mauSo);
    if (ps1 == ps)
        return 0;
    else if (ps1 > ps)
        return 1;
    else
        return -1;
}
/* 5. Cong hai phan so
Input:
    +phan so thu nhat: ps1
    +phan so thu 2: ps
Output:
    +return ketQua => tong 2 phan so
*/
PhanSo PhanSo ::Cong(PhanSo &ps)
{
    PhanSo ps1(tuSo, mauSo);
    PhanSo ketQua = ps + ps1;
    ketQua.rutGon();
    return ketQua;
}
/* 6. Tru hai phan so
Input:
    +phan so thu nhat: ps1
    +phan so thu 2: ps
Output:
    +return ketQua => hieu 2 phan so
*/

PhanSo PhanSo ::Tru(PhanSo &ps)
{
    PhanSo ps1(tuSo, mauSo);
    PhanSo ketQua = ps1 - ps;
    ketQua.rutGon();
    return ketQua;
}
/* 7. Nhan hai phan so
Input:
    +phan so thu nhat: ps1
    +phan so thu 2: ps
Output:
    +return ketQua => tich 2 phan so*/
PhanSo PhanSo ::Nhan(PhanSo &ps)
{
    PhanSo ps1(tuSo, mauSo);
    PhanSo ketQua = ps1 * ps;
    ketQua.rutGon();
    return ketQua;
}
/* 8. Chia hai phan so
Input:
    +phan so thu nhat: ps1
    +phan so thu 2: ps
Output:
    +return ketQua => thuong 2 phan so*/
PhanSo PhanSo ::Chia(PhanSo &ps)
{
    PhanSo ps1(tuSo, mauSo);
    PhanSo ketQua = ps1 / ps;
    return ketQua;
}
/* 9. Sao chep hai phan so
    Input:
        + phan so hien tai
    Output:
        +return result => phan so moi giong voi phan so hien tai
 */
PhanSo PhanSo ::saoChep() const
{
    PhanSo result(*this);
    return result;
}
/* 10. tim phan so lon nhat
Input:
    + mang phan so: ps
    + so phan tu cua mang: n
Output:
    + return max => phan so co gia tri lon nhat
*/
PhanSo PhanSo::TimMax(PhanSo arr[], int n)
{
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    PhanSo ps[5];
    ps[0] = PhanSo(4, 8);
    ps[1] = PhanSo(3, 9);
    ps[2] = PhanSo(14, 21);
    ps[3] = PhanSo(4, 5);
    ps[4] = PhanSo(5, 15);
    for (int i = 0; i < 5; i++)
    {
        cout << "ps" << i + 1 << " = ";
        ps[i].xuat();
        cout << endl;
    }
    // Rut gon phan so
    for (int i = 0; i < 5; i++)
    {
        ps[i].rutGon();
        cout << "ps" << i + 1 << " sau khi rut gon: ";
        ps[i].xuat();
        cout << endl;
    }
    cout << "Tong hai phan so: ps1 + ps2 = ";
    ps[0].Cong(ps[1]).xuat();
    cout << endl;
    cout << "Hieu hai phan so: ps1 - ps2 = ";
    ps[0].Tru(ps[1]).xuat();
    cout << endl;
    cout << "Tich hai phan so: ps1 - ps2 = ";
    ps[0].Nhan(ps[1]).xuat();
    cout << endl;
    cout << "Thuong hai phan so: ps1 - ps2 = ";
    ps[0].Chia(ps[1]).xuat();
    cout << endl;
    cout << "Sao chep phan so 1: ";
    PhanSo ps6 = ps[0];
    ps6.xuat();
    cout << endl;
    cout << "Phan so lon nhat: ";
    PhanSo::TimMax(ps, 5).xuat();
    cout << endl;
}
