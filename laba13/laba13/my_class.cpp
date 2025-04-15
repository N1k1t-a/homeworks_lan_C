#include <iostream>
#include "my_class.h"

using namespace std;


Complex::Complex(double r, double i) : real(r), imag(i) {}


Complex::Complex(const Complex& other) {
    real = other.real;
    imag = other.imag;
}


Complex::~Complex() {}


void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}


double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}


void Complex::input() {
    cout << "¬ведите действительную часть: ";
    cin >> real;
    cout << "¬ведите мнимую часть: ";
    cin >> imag;
}


void Complex::output() const {
    cout << real;
    if (imag >= 0)
        cout << " + " << imag << "i";
    else
        cout << " - " << -imag << "i";
    cout << endl;
}


Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}


Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}


Complex Complex::operator*(const Complex& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    double r = (real * other.real + imag * other.imag) / denominator;
    double i = (imag * other.real - real * other.imag) / denominator;
    return Complex(r, i);
}


Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real = other.real;
        imag = other.imag;
    }
    return *this;
}


bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator^(int power) const {
    Complex result(1, 0);     
    Complex base = *this;

    if (power == 0)
        return result;

    for (int i = 0; i < power; ++i) {
        result = result * base;
    }

    return result;
}
