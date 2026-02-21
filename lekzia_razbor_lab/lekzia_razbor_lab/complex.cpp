#include "complex.h"

Complex::Complex(double im_val, double re_val) {
	im = im_val;
	re = re_val;
}

Complex::Complex() : re(0), im(0) {}

void Complex::set_re(double re_val) {
	re = re_val;
}

void Complex::set_im(double im_val) {
	im = im_val;
}

double Complex::get_re() {
	return re;
}

double Complex::get_im() {
	return im;
}

Complex Complex::add(const Complex& other) {
	Complex ret;
	ret.re = re + other.re;
	ret.im = im + other.im;

	return ret;
}