#include <iostream>
#include "my_class.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Complex a(-12.24, -23.44);       
    Complex b(-234.0, 334.0);      
    Complex result;            

    cout << "����� a: ";
    a.output();

    cout << "����� b: ";
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

    cout << "��������� a � b: " << (a == b ? "�����" : "�� �����") << endl;

    Complex powResult = a ^ 3;
    cout << "a � ������� 3: ";
    powResult.output();


 
    Complex copy = a;
    cout << "����� a: ";
    copy.output();


    Complex userInput;
    cout << "������� ����������� �����:\n";
    userInput.input();
    cout << "�� �����: ";
    userInput.output();

    return 0;
}


//�������� ����� Complex ��� ���������� �������������� ��� -
//����� � ������������ �������.
// ����������� ��������� ��������� � ���������� � �������� �