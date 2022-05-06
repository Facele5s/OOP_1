#include "Complex.h"

void Complex::output_complex() {
	cout << re;
	if (im > 0) cout << "+";
	if (im > 0 || im < 0) cout << im << "i";
}

double Complex::get_re_complex() {
	return re;
}
double Complex::get_im_complex() {
	return im;
}

void Complex::set_complex(double r, double i) {
	re = r;
	im = i;
}

double Complex::abs() {
	return sqrt(re * re + im * im);
}



