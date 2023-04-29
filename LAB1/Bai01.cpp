#include <bits/stdc++.h>
using namespace std;
class PhanSo
{
private:
    int tuSo;
    int mauSo;

public:
    PhanSo()
    {
        tuSo = 0;
        mauSo = 1;
    }
    PhanSo(int ts, int ms)
    {
        tuSo = ts;
        mauSo = ms;
    }

    void Nhap()
    {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do
        {
            cout << "Nhap mau so khac 0: ";
            cin >> mauSo;
        } while (mauSo == 0);
    }

    void Xuat()
    {
        cout << tuSo << "/" << mauSo;
    }

    void RutGon()
    {
        int ucln = UCLN(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
    }

    int SoSanh(PhanSo ps)
    {
        PhanSo ps1 = *this;
        PhanSo ps2 = ps;
        ps1.RutGon();
        ps2.RutGon();
        if (ps1.tuSo * ps2.mauSo < ps2.tuSo * ps1.mauSo)
        {
            return -1;
        }
        else if (ps1.tuSo * ps2.mauSo > ps2.tuSo * ps1.mauSo)
        {
            return 1;
        }
        return 0;
    }

    PhanSo Cong(PhanSo ps)
    {
        int ts = tuSo * ps.mauSo + ps.tuSo * mauSo;
        int ms = mauSo * ps.mauSo;
        PhanSo ketQua(ts, ms);
        ketQua.RutGon();
        return ketQua;
    }

    PhanSo Tru(PhanSo ps)
    {
        int ts = tuSo * ps.mauSo - ps.tuSo * mauSo;
        int ms = mauSo * ps.mauSo;
        PhanSo ketQua(ts, ms);
        ketQua.RutGon();
        return ketQua;
    }

    PhanSo Nhan(PhanSo ps)
    {
        int ts = tuSo * ps.tuSo;
        int ms = mauSo * ps.mauSo;
        PhanSo ketQua(ts, ms);
        ketQua.RutGon();
        return ketQua;
    }

    PhanSo Chia(PhanSo ps)
    {
        int ts = tuSo * ps.mauSo;
        int ms = mauSo * ps.tuSo;
        PhanSo ketQua(ts, ms);
        ketQua.RutGon();
        return ketQua;
    }

    static PhanSo TimMax(PhanSo arr[], int n)
    {
        PhanSo maxPS = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i].SoSanh(maxPS) > 0)
            {
                maxPS = arr[i];
            }
        }
        return maxPS;
    }

    static int UCLN(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (a > 0)
        {
            if (a < b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            a %= b;
        }
        return b;
    }
};

int main()
{
    int choice, n;
    PhanSo ps1, ps2;
    PhanSo arr[100];
    do
    {
        cout << "\n--------------- MENU ---------------\n";
        cout << "1. Nhap phan so\n";
        cout << "2. Xuat phan so\n";
        cout << "3. Rut gon phan so\n";
        cout << "4. So sanh hai phan so\n";
        cout << "5. Cong hai phan so\n";
        cout << "6. Tru hai phan so\n";
        cout << "7. Nhan hai phan so\n";
        cout << "8. Chia hai phan so\n";
        cout << "9. Tim phan so lon nhat trong mang\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "--------------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap phan so thu nhat:\n";
            ps1.Nhap();
            cout << "Nhap phan so thu hai:\n";
            ps2.Nhap();
            break;
        case 2:
            cout << "Phan so thu nhat: ";
            ps1.Xuat();
            cout << "\nPhan so thu hai: ";
            ps2.Xuat();
            cout << endl;
            break;
        case 3:
            cout << "Rut gon phan so thu nhat: ";
            ps1.RutGon();
            ps1.Xuat();
            cout << "\nRut gon phan so thu hai: ";
            ps2.RutGon();
            ps2.Xuat();
            cout << endl;
            break;
        case 4:
            if (ps1.SoSanh(ps2) == -1)
            {
                cout << "Phan so thu nhat nho hon phan so thu hai\n";
            }
            else if (ps1.SoSanh(ps2) == 1)
            {
                cout << "Phan so thu nhat lon hon phan so thu hai\n";
            }
            else
            {
                cout << "Hai phan so bang nhau\n";
            }
            break;
        case 5:
            cout << "Tong hai phan            so la: ";
            (ps1.Cong(ps2)).Xuat();
            cout << endl;
            break;
        case 6:
            cout << "Hieu hai phan so la: ";
            (ps1.Tru(ps2)).Xuat();
            cout << endl;
            break;
        case 7:
            cout << "Tich hai phan so la: ";
            (ps1.Nhan(ps2)).Xuat();
            cout << endl;
            break;
        case 8:
            cout << "Thuong hai phan so la: ";
            (ps1.Chia(ps2)).Xuat();
            cout << endl;
            break;
        case 9:
            cout << "Nhap so luong phan so: ";
            cin >> n;
            cout << "Nhap cac phan so:\n";
            for (int i = 0; i < n; i++)
            {
                arr[i].Nhap();
            }
            cout << "Phan so lon nhat trong mang la: ";
            (PhanSo::TimMax(arr, n)).Xuat();
            cout << endl;
            break;
        case 0:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
            break;
        }
    } while (choice != 0);
    return 0;
}