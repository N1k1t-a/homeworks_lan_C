#include <iostream>
#include "date.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Date a(10, 1, 2024), b;

    cout << "Введите дату для b (дд.мм.гггг): ";
    cin >> b;

    cout << "a: " << a << ", b: " << b << "\n";

    a += 5;
    cout << "a += 5 дней: " << a << "\n";

    Date c = a + 3;
    cout << "c = a + 3 дня: " << c << "\n";

    cout << "++c: " << ++c << "\n";
    cout << "c++: " << c++ << "\n";
    cout << "После c++: " << c << "\n";

    cout << "--c: " << --c << "\n";
    cout << "c--: " << c-- << "\n";
    cout << "После c--: " << c << "\n";

    cout << "Сравнение a и b:\n";
    if (a == b)
        cout << "a и b равны\n";
    else if (a > b)
        cout << "a больше b\n";
    else
        cout << "a меньше b\n";

    return 0;
}


//Создайте класс Data с операциями + (int), +=(int), =, == , != , > ,
//< 
// , >= , <= , ++и--. (int)– количество дней.
// сделать в формате даты
// сделать конструктор копий