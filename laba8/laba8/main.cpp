#include <iostream>
#include "my_lab.h"

int main() {
    setlocale(LC_ALL, "RU");

    char str[32]; 
    long testNumbers[] = { 0, 8, 64, 255, -100, 1024 };
    int numTests = sizeof(testNumbers) / sizeof(testNumbers[0]);
    int my_num;
    int base;

    for (int i = 0; i < numTests; i++) {
        ltoao(testNumbers[i], str);
        std::cout << "����� " << testNumbers[i] << " � ������������ �������: " << str << std::endl;
    }
    for (int i = 0; i < numTests; i++) {
        sixt(testNumbers[i], str);
        std::cout << "����� " << testNumbers[i] << " � ����������������� �������: " << str << std::endl;
    }

    std::cout << "������� �����, ������� ������ ��������: ";
    std::cin >> my_num;
    std::cout << std::endl << "� ����� ������� ��������� ������ ��������� (8/16): ";
    std::cin >> base;
    if (base == 8) {
        ltoao(my_num, str);
        std::cout << "����� " << my_num << " � ������������ �������: " << str << std::endl;
    }

    if (base == 16) {
        sixt(my_num, str);
        std::cout << "����� " << my_num << " � ����������������� �������: " << str << std::endl;
    }

    return 0;
}
