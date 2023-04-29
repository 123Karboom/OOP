#include <iostream>
using namespace std;

class Time
{
private:
    int hour, minute, second; 
    int to_seconds() const;   // chuyển đổi thời gian sang số giây
public:
    Time(int h = 0, int m = 0, int s = 0);                   // constructor
    friend istream &operator>>(istream &in, Time &t);        // phép toán nhập
    friend ostream &operator<<(ostream &out, const Time &t); // phép toán xuất
    Time operator+(int seconds) const;                       // phép toán cộng
    Time operator-(int seconds) const;                       // phép toán trừ
    Time operator+(const Time &t) const;                     // phép toán cộng hai thời gian
    Time operator-(const Time &t) const;                     // phép toán trừ hai thời gian
    Time operator++(int);                                    // phép toán thêm một giây
    Time operator--(int);                                    // phép toán bớt một giây
    Time &operator++();                                      // phép toán thêm một giây
    Time &operator--();                                      // phép toán bớt một giây
    void convert(int &d, int &h, int &m, int &s) const;      // chuyển đổi thời gian sang ngày, giờ, phút, giây
};

Time::Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

istream &operator>>(istream &in, Time &t)
{
    cout << "Enter time in hh:mm:ss format: ";
    char colon1, colon2;
    in >> t.hour >> colon1 >> t.minute >> colon2 >> t.second;
    return in;
}

ostream &operator<<(ostream &out, const Time &t)
{
    out << t.hour << ":" << t.minute << ":" << t.second;
    return out;
}

Time Time::operator+(int seconds) const
{
    int total_seconds = to_seconds() + seconds;
    return Time(total_seconds / 3600, (total_seconds % 3600) / 60, total_seconds % 60);
}

Time Time::operator-(int seconds) const
{
    int total_seconds = to_seconds() - seconds;
    return Time(total_seconds / 3600, (total_seconds % 3600) / 60, total_seconds % 60);
}

Time Time::operator+(const Time &t) const
{
    int total_seconds = to_seconds() + t.to_seconds();
    return Time(total_seconds / 3600, (total_seconds % 3600) / 60, total_seconds % 60);
}

Time Time::operator-(const Time &t) const
{
    int total_seconds = to_seconds() - t.to_seconds();
    return Time(total_seconds / 3600, (total_seconds % 3600) / 60, total_seconds % 60);
}

Time Time::operator++(int)
{
    Time t(*this);
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
            }
        }
    }
    return t;
}

Time Time::operator--(int)
{
    Time t(*this);
    second--;
    if (second == -1)
    {
        second = 59;
        minute--;
        if (minute == -1)
        {
            minute = 59;
            hour--;
            if (hour == -1)
            {
                hour = 23;
            }
        }
    }
    return t;
}

Time &Time::operator++()
{
    second++;
    if (second == 60)
    {
        second = 0;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                hour = 0;
            }
        }
    }
    return *this;
}

Time &Time::operator--()
{
    second--;
    if (second == -1)
    {
        second = 59;
        minute--;
        if (minute == -1)
        {
            minute = 59;
            hour--;
            if (hour == -1)
            {
                hour = 23;
            }
        }
    }
    return *this;
}
void Time::convert(int &d, int &h, int &m, int &s) const
{
    int total_seconds = to_seconds();
    s = total_seconds % 60;
    total_seconds /= 60;
    m = total_seconds % 60;
    total_seconds /= 60;
    h = total_seconds % 24;
    d = total_seconds / 24;
}

int Time::to_seconds() const
{
    return hour * 3600 + minute * 60 + second;
}

int main()
{
    Time t1, t2, t3;
    Time t4(9, 10, 11);
    cin >> t1;
    cout << "t1 = " << t1 << endl;
    t2 = t1 + t4;
    cout << "t2 = " << t2 << endl;
    t3 = t2 + t2;
    cout << "t3 = " << t3 << endl;
    t1++;
    cout << "t1 = " << t1 << endl;
    t2--;
    cout << "t2 = " << t2 << endl;
    int d, h, m, s;
    t3.convert(d, h, m, s);
    cout << "t3 = " << d << " days, " << h << " hours, " << m << " minutes, " << s << " seconds" << endl;
    return 0;
}
