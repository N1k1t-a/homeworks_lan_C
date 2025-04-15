#include <iostream>
#include "date.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Date a(10, 1, 2024), b;

    cout << "������� ���� ��� b (��.��.����): ";
    cin >> b;

    cout << "a: " << a << ", b: " << b << "\n";

    a += 5;
    cout << "a += 5 ����: " << a << "\n";

    Date c = a + 3;
    cout << "c = a + 3 ���: " << c << "\n";

    cout << "++c: " << ++c << "\n";
    cout << "c++: " << c++ << "\n";
    cout << "����� c++: " << c << "\n";

    cout << "--c: " << --c << "\n";
    cout << "c--: " << c-- << "\n";
    cout << "����� c--: " << c << "\n";

    cout << "��������� a � b:\n";
    if (a == b)
        cout << "a � b �����\n";
    else if (a > b)
        cout << "a ������ b\n";
    else
        cout << "a ������ b\n";

    return 0;
}


//�������� ����� Data � ���������� + (int), +=(int), =, == , != , > ,
//< 
// , >= , <= , ++�--. (int)� ���������� ����.
// ������� � ������� ����
// ������� ����������� �����