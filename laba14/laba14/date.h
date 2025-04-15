#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
    bool isLeap(int year) const;
    int daysInMonth(int month, int year) const;
    bool isValidDate(int d, int m, int y) const;


public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& other); 
    ~Date();

    Date& operator=(const Date& other); 


    void setDate(int d, int m, int y);
    void getDate(int& d, int& m, int& y) const;

    Date operator+(int d) const;
    Date& operator+=(int d);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator<=(const Date& other) const;


    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Date& d);
    friend std::istream& operator>>(std::istream& in, Date& d);
};

#endif 
