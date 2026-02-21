#pragma once


class Complex {
private:
	double im;
	double re;

public:

	Complex();
	Complex(double im_val, double re_val);

	void set_re(double val_re);
	void set_im(double val_im);

	double get_im();
	double get_re();

	Complex add(const Complex& other);
};