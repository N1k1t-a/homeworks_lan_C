#include <iostream>
#include "integral.h"

int main() {
    setlocale(LC_ALL, "RU");

    double a = 0.5, b = 0.8;
    double eps_one;

    std::cout << "Введите точность (eps) для нахождения интеграла cos(x) на инт[0.5,0.8]: ";
    std::cin >> eps_one;
    
    if (eps_one < 0)
        std::cout << "точность должна быть положительным числом!" << std::endl;

    else {
        double result_one = trapezoidal_rule_by_cos(a, b, eps_one);
        std::cout << "Приближенное значение интеграла cos(x): " << result_one << std::endl;
    }

    double c = -1;
    double d = 0;
    double eps_two;
    

    std::cout << "Введите точность (eps) для нахождения интеграла sin(x) на интервале [-1, 0]: ";
    std::cin >> eps_two;

    if (eps_two < 0)
        std::cout << "точность должна быть положительным числом!" << std::endl;

    else {
        double result_two = trapezoidal_rule_by_sin(c, d, eps_two);
        std::cout << "Приближенное значение интеграла sin(x): " << result_two << std::endl;
    }

    return 0;
}

