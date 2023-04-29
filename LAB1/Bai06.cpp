#include <bits/stdc++.h>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    } // constructor

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getDaysInMonth() const {
        switch(month) {
            case 2:
                return isLeapYear() ? 29 : 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    }

    void printDate() const {
        cout << day << "/" << month << "/" << year << endl;
    }

    bool isValidDate() const {
        if (month < 1 || month > 12) {
            return false;
        }
        if (day < 1 || day > getDaysInMonth()) {
            return false;
        }
        return true;
    }

    Date getNextDate() const {
        int nextDay = day + 1;
        int nextMonth = month;
        int nextYear = year;
        int daysInMonth = getDaysInMonth();
        if (nextDay > daysInMonth) {
            nextDay = 1;
            nextMonth += 1;
            if (nextMonth > 12) {
                nextMonth = 1;
                nextYear += 1;
            }
        }
        return Date(nextDay, nextMonth, nextYear);
    }
};

int main() {
    int day, month, year;
    cout << "Nhap ngay (dd): ";
    cin >> day;
    cout << "Nhap thang (mm): ";
    cin >> month;
    cout << "Nhap nam (yyyy): ";
    cin >> year;

    Date date(day, month, year);
    if (date.isValidDate()) 
    {
        Date nextDate = date.getNextDate();
        cout << "Ngay ke tiep la: ";
        nextDate.printDate();
    }
    else {
        cout << "Ngay nhap vao khong hop le!" << endl;
    }

    return 0;
}


