#include "date.h"

Date::Date() : day(1), month(1), year(2000) {}


Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}


Date::Date(const Date& other) {
    day = other.day;
    month = other.month;
    year = other.year;
}

Date::~Date() {}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::getDate(int& d, int& m, int& y) const {
    d = day;
    m = month;
    y = year;
}

Date Date::operator+(int d) const {
    Date temp = *this;
    temp.day += d;
    return temp; 
}

Date& Date::operator+=(int d) {
    day += d;
    return *this;
}


bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

bool Date::operator<=(const Date& other) const {
    return !(*this > other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}


Date& Date::operator++() {
    ++day;
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}


Date& Date::operator--() {
    --day;
    return *this;
}


Date Date::operator--(int) {
    Date temp = *this;
    --(*this);
    return temp;
}


std::ostream& operator<<(std::ostream& out, const Date& d) {
    if (d.day < 10) out << "0";
    out << d.day << ".";
    if (d.month < 10) out << "0";
    out << d.month << ".";
    out << d.year;
    return out;
}

std::istream& operator>>(std::istream& in, Date& d) {
    char dot1, dot2;
    int tempDay, tempMonth, tempYear;

    in >> tempDay >> dot1 >> tempMonth >> dot2 >> tempYear;

    if (!d.isValidDate(tempDay, tempMonth, tempYear)) {
        std::cout << "Ошибка: некорректная дата!\n";
    }
    else {
        d.day = tempDay;
        d.month = tempMonth;
        d.year = tempYear;
    }

    return in;
}



bool Date::isLeap(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year) const {
    static const int daysInMonths[] = { 31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeap(year))
        return 29;
    if (month >= 1 && month <= 12)
        return daysInMonths[month - 1];
    return 0;
}

bool Date::isValidDate(int d, int m, int y) const {
    if (y < 1 || m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y))
        return false;
    return true;
}

