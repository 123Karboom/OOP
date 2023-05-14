#include<bits/stdc++.h>
using namespace std;

class BenhNhan;

class BacSi 
{
private: 
    string hoTen;
    int maBS;
    vector<BenhNhan *> DSBenhNhan;
public:
    BacSi()
    {
        hoTen = "";
        maBS = 0;
    }

    BacSi(string hoTen, int maBS)
    {
        this->hoTen = hoTen;
        this->maBS = maBS;
    }

    void themBenhNhan(BenhNhan *BN)
    {
        DSBenhNhan.push_back(BN);
    }

};

class BenhNhan
{
private:
    string hoTen;
    int maBN;
    vector<BacSi *> DSBacSi;
    int tienThuoc;
public:
    BenhNhan()
    {
        hoTen = "";
        maBN = tienThuoc = 0;
    } 
    BenhNhan(string hoTen, int maBN, int tienThuoc) : hoTen(hoTen), maBN(maBN), tienThuoc(tienThuoc) {}
    
    int tinhTienThuoc();
    void themBacSi(BacSi *BS)
    {
        DSBacSi.push_back(BS);
    }

};