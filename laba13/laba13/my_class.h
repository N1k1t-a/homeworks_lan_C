#ifndef MY_CLASS_H
#define MY_CLASS_H

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0);

    
    Complex(const Complex& other);

   
    ~Complex();


    void setReal(double r);
    void setImag(double i);


    double getReal() const;
    double getImag() const;


    void input();
    void output() const;


    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    Complex operator^(int power) const;
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex& operator=(const Complex& other);
};

#endif 
