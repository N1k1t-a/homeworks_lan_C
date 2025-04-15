#include <iostream>
#include "my_class.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Complex a(-12.24, -23.44);       
    Complex b(-234.0, 334.0);      
    Complex result;            

    cout << "Число a: ";
    a.output();

    cout << "Число b: ";
    b.output();

    result = a + b;
    cout << "a + b = ";
    result.output();

    result = a - b;
    cout << "a - b = ";
    result.output();

    
    result = a * b;
    cout << "a * b = ";
    result.output();


    result = a / b;
    cout << "a / b = ";
    result.output();

    cout << "Сравнение a и b: " << (a == b ? "равны" : "не равны") << endl;

    Complex powResult = a ^ 3;
    cout << "a в степени 3: ";
    powResult.output();


 
    Complex copy = a;
    cout << "Копия a: ";
    copy.output();


    Complex userInput;
    cout << "Введите комплексное число:\n";
    userInput.input();
    cout << "Вы ввели: ";
    userInput.output();

    return 0;
}


//Создайте класс Complex для выполнения арифметических опе -
//раций с комплексными числами.
// реализоавть операторы сравнения и возведения в степеноь б