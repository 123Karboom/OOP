#include <bits/stdc++.h>
using namespace std;

// Lớp cơ sở cổng
class Gate
{
protected:
    int cost; // Đơn giá hoặc chỉ số trí tuệ
public:
    Gate(int _cost) : cost(_cost) {}
    virtual bool canPass(int &value) = 0;
};

// Lớp cổng giao thương
class BusinessGate : public Gate
{
public:
    BusinessGate(int _cost) : Gate(_cost) {}
    bool canPass(int &value)
    {
        if (value >= cost)
        {
            value -= cost;
            return true;
        }
        return false;
    }
};

// Lớp cổng học thuật
class AcademicGate : public Gate
{
public:
    AcademicGate(int _cost) : Gate(_cost) {}
    bool canPass(int &value)
    {
        return value >= cost;
    }
};

// Lớp cổng sức mạnh
class PowerGate : public Gate
{
public:
    PowerGate(int _cost) : Gate(_cost) {}
    bool canPass(int &value)
    {
        if (value >= cost)
        {
            value-= cost;
            return true;
        }
        return false;
    }
};

// Lớp Hoàng tử
class Prince
{
private:
    int money;
    int intellect;
    int strength;

public:
    Prince(int _money, int _intellect, int _strength) : money(_money), intellect(_intellect), strength(_strength) {}

    bool canRescuePrincess(vector<Gate *> &gates)
    {
        for (int i = 0; i < gates.size(); i++)
        {
            int type = getTypeGate(gates[i]);
            switch (type)
            {
            case 1:
                if (!gates[i]->canPass(money))
                    return false;
                break;
            case 2:
                if (!gates[i]->canPass(intellect))
                    return false;
                break;
            case 3:
                if (!gates[i]->canPass(strength))
                    return false;
                break;
            }
        }
        return true;
    }

    int getTypeGate(Gate *gate)
    {
        if (dynamic_cast<BusinessGate *>(gate) != nullptr)
        {
            return 1;
        }
        else if (dynamic_cast<AcademicGate *>(gate) != nullptr)
        {
            return 2;
        }
        else if (dynamic_cast<PowerGate *>(gate) != nullptr)
        {
            return 3;
        }
        return 0;
    }

    void printStatus()
    {
        cout << "Tien: " << money << endl;
        cout << "Tri tue: " << intellect << endl;
        cout << "Suc manh: " << strength << endl;
    }

    void spendMoney(int amount)
    {
        money -= amount;
    }

    void decreaseStrength(int amount)
    {
        strength -= amount;
    }

};

int main()
{
    int N;
    cout << "Nhap so luong cong lau dai: ";
    cin >> N;

    vector<Gate *> gates;
    for (int i = 0; i < N; i++)
    {
        int type, cost;
        cout << "infor:  " << i + 1 << ": (loai, gia) ";
        cin >> type >> cost;

        if (type == 1)
        {
            gates.push_back(new BusinessGate(cost));
        }
        else if (type == 2)
        {
            gates.push_back(new AcademicGate(cost));
        }
        else if (type == 3)
        {
            gates.push_back(new PowerGate(cost));
        }
    }

    int money, intellect, strength;
    cout << "Nhap thong so hoang tu: (tien, IQ, suc manh) ";
    cin >> money >> intellect >> strength;

    Prince prince(money, intellect, strength);
    if (prince.canRescuePrincess(gates))
    {
        cout << "Cuu duoc!" << endl;
        cout << "Thong so con lai:" << endl;
        prince.printStatus();
    }
    else
    {
        cout << "Cut." << endl;
    }

    // Giải phóng bộ nhớ của các đối tượng cổng
    for (int i = 0; i < gates.size(); i++)
    {
        delete gates[i];
    }

    return 0;
}
