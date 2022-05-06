#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>

using namespace std;

class Complex {
public:
	double re = 0;
	double im = 0;

	void set_complex(double r, double i);
	double get_re_complex();
	double get_im_complex();
	void output_complex();
	double abs();
};


#endif