#include<bits/stdc++.h>
using namespace std;

// Lớp kẻ địch
class Enemy
{
private:
    double maxHP;
    double hp;
    double armorPhysical;
    double armorMagical;

public:
    Enemy(double hp, double armorPhysical, double armorMagical)
        : maxHP(hp), hp(hp), armorPhysical(armorPhysical), armorMagical(armorMagical) {}

    double getMaxHP()
    {
        return maxHP;
    }

    double getHP() const
    {
        return hp;
    }

    double getArmorPhysical() const
    {
        return armorPhysical;
    }

    void takeDamage(double damage)
    {
        double effectiveDamage = max(0.0, damage - armorPhysical);
        this->hp = max(0.0, hp - effectiveDamage);
    }

    void takeMagicalDamage(double damage)
    {
        double effectiveDamage = max(0.0, damage - armorMagical);
        this->hp = max(0.0, hp - effectiveDamage);
    }

    void reduceArmorPhysical(double reduction)
    {
        this->armorPhysical = max(0.0, armorPhysical - reduction);
    }
};

// Lớp trụ chung
class Tower
{
protected:
    int id;
    double damage;

public:
    Tower(double id, double damage) : id(id), damage(damage) {}

    virtual void attack(vector<Enemy> &enemies) = 0;
};

// Lớp trụ bắn tên
class ArcherTower : public Tower
{
public:
    ArcherTower(double id, double damage) : Tower(id, damage) {}

    void attack(vector<Enemy> &enemies)
    {
        double minHP = INT_MAX;
        int target = -1;

        // Tìm kẻ địch có HP thấp nhất
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].getHP() < minHP && 0 < enemies[i].getHP())
            {
                minHP = enemies[i].getHP();
                target = i;
            }
        }
        cout <<"before archer hit: " << enemies[target].getHP() << endl;
        // Bắn vào kẻ địch
        if (target != -1)
        {
            enemies[target].takeDamage(damage + enemies[target].getMaxHP() * 0.1);
        }
        cout <<"Archer dame: " << damage + enemies[target].getMaxHP() * 0.1 << endl;
        cout << "Archer hit, HP : " << enemies[target].getHP() << endl;
        cout << endl;
    }
};

// Lớp trụ phép thuật
class ArcaneTower : public Tower
{
public:
    ArcaneTower(int id, double damage) : Tower(id, damage) {}

    void attack(vector<Enemy> &enemies)
    {
        double minHP = INT_MAX;
        int target = -1;

        // Tìm kẻ địch có HP thấp nhất
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].getHP() < minHP && 0 < enemies[i].getHP())
            {
                minHP = enemies[i].getHP();
                target = i;
            }
        }
        cout <<"before arcane hit: "<< enemies[target].getHP() << endl;
        double hpBeforehit = enemies[target].getHP();
        // Bắn vào kẻ địch
        if (target != -1)
        {
            enemies[target].takeMagicalDamage(damage);
            double armor = enemies[target].getArmorPhysical();              // Giáp vật lý
            enemies[target].reduceArmorPhysical(max(0.0, damage)); // Giảm giáp vật lý
        }
        cout <<"Arcane dame: " << hpBeforehit - enemies[target].getHP() << endl;
        cout << "Arcane hit, HP : " << enemies[target].getHP() << endl;
        cout << endl;
    }
};

// Lớp trụ lính
class MilitiaBarrack : public Tower
{
private:
    int numSoldiers;
    int duration;

public:
    MilitiaBarrack(int id, double damage, int numSoldiers, int duration)
        : Tower(id, damage), numSoldiers(numSoldiers), duration(duration) {}

    void attack(vector<Enemy> &enemies)
    {

    }
};

int main()
{
    int numTowers;
    cin >> numTowers;

    vector<Tower *> arcaneTowers;
    vector<Tower *> archerTowers;
    int Tm = 0;
    int Soldiers = 0;
    // Nhập thông tin cho từng trụ
    for (int i = 0; i < numTowers; i++)
    {
        int id;
        double damage;
        cin >> id;
        switch (id)
        {
        case 1:
        {
            cin >> damage;
            archerTowers.push_back(new ArcherTower(id, damage));
            break;
        }
        case 2:
        {
            cin >> damage;
            arcaneTowers.push_back(new ArcaneTower(id, damage));
            break;
        }
        case 3:
        {
            double numSoldiers, duration;
            cin >> numSoldiers >> duration;
            Tm = duration;
            Soldiers += numSoldiers;
            break;
        }
        }
    }

    double numEnemies;
    cin >> numEnemies;

    vector<Enemy> enemies;

    // Nhập thông tin cho từng kẻ địch
    for (double i = 0; i < numEnemies; i++)
    {
        double hp, armorPhysical, armorMagical;
        cin >> hp >> armorPhysical >> armorMagical;

        enemies.push_back(Enemy(hp, armorPhysical, armorMagical));
    }

    if (enemies.size() > Soldiers)
    {
        cout << "FAILD";
        return 0;
    }

    // Tấn công kẻ địch bằng các trụ
    for (double t = 0; t < Tm; t++)
    {
        cout << t + 1 << "s" << endl;
        for (double i = 0; i < arcaneTowers.size(); i++)
        {
            arcaneTowers[i]->attack(enemies);
        }

        for (double i = 0; i < archerTowers.size(); i++)
        {
            archerTowers[i]->attack(enemies);
        }
    }

    // Kiểm tra số lượng kẻ địch còn sống
    double numAlive = 0;
    for (const Enemy &enemy : enemies)
    {
        if (enemy.getHP() > 0)
        {
            numAlive++;
        }
    }

    // Nếu không còn kẻ địch sống thì thoát
    if (numAlive == 0)
    {
        cout << "SUCCESS" << endl;
        return 0;
    }
    // In ra thông tin kẻ địch còn sống
    for (const Enemy &enemy : enemies)
    {
        if (enemy.getHP() > 0)
        {
            cout << enemy.getHP() << endl;
        }
    }

    return 0;
}
/*
3
1 2
2 4
3 10 5
5
3 1 1
4 2 2
10 1 1
5 3 0
7 0 3
*/