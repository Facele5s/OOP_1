#include "Complex.h"
#include <fstream>
#include <vector>
#include <string>

int main() {

	int swtch = 2; // 1 - 1st part of task, 2 - 2nd part of task

	switch (swtch) {
	case 1: { ///// 1st part of task
		Complex a;
		Complex b;
		Complex c;

		double a_r, a_i, b_r, b_i; //Input
		double r, i; //Output
		char oper; //Operator character

		cout << "Input real and imagine parts of A" << endl;
		cin >> a_r;
		cin >> a_i;
		a.set_complex(a_r, a_i);

		cout << "Choost the operation: + - * /" << endl;
		cin >> oper;

		cout << "Input real and imagine parts of B" << endl;
		cin >> b_r;
		cin >> b_i;
		b.set_complex(b_r, b_i);

		cout << endl;


		switch (oper) {
		case '+': {
			r = a.get_re_complex() + b.get_re_complex();
			i = a.get_im_complex() + b.get_im_complex();
			break;
		}
		case '-': {
			r = a.get_re_complex() - b.get_re_complex();
			i = a.get_im_complex() - b.get_im_complex();
			break;
		}
		case '*': {
			r = a.get_re_complex() * b.get_re_complex() - a.get_im_complex() * b.get_im_complex();
			i = a.get_re_complex() * b.get_im_complex() + b.get_re_complex() * a.get_im_complex();
			break;
		}
		case '/': {
			if (b_r * b_r + b_i * b_i == 0) {
				cout << "Cannot to divide";
			}
			else {
				r = (a.get_re_complex() * b.get_re_complex() + a.get_im_complex() * b.get_im_complex()) / (b.get_re_complex() * b.get_re_complex() + b.get_im_complex() * b.get_im_complex());
				i = (b.get_re_complex() * a.get_im_complex() - a.get_re_complex() * b.get_im_complex()) / (b.get_re_complex() * b.get_re_complex() + b.get_im_complex() * b.get_im_complex());
			}
			break;
		}
		default: {
			cout << "Something went wrong";
			break;
		}
		}

		c.set_complex(r, i);
		c.output_complex();

		break;
	}
	case 2: { ///// 2nd part of task //? ????? ???????? ??? ?????????? n, ??? ??? ??? ????????????? ???????? ??? ?????? ?? ?????, ??????? ????????? ???? ?????????? ????? ? ???????????? ?????
		string s;
		ifstream file("complex.txt");

		vector <Complex> p;

		while (getline(file, s)) {
			Complex a;
			int re;
			int im;

			bool im_sign = false; //Imagine part sign (true = plus, false = minus)

			int ind; //Index of imagine part sign
			string real = ""; // Real part in string
			string imagine = ""; //Imagine part in string

			if (s[0] == '-') {
				for (int i = 1; i < s.length() - 1; i++) {
					if (s[i] == '+' || s[i] == '-') {
						ind = i;
						if (s[i] == '+') {
							im_sign = true;
						}
						else {
							im_sign = false;
						}
					}
				}
				for (int i = 1; i < ind; i++) {
					real += s[i];
				}
				for (int i = ind + 1; i < s.length() - 1; i++) {
					imagine += s[i];
				}
				re = -stoi(real);
				im = stoi(imagine);
				if (!im_sign) im = -im;
			}
			else {
				for (int i = 0; i < s.length() - 1; i++) {
					if (s[i] == '+' || s[i] == '-') {
						ind = i;
						if (s[i] == '+') {
							im_sign = true;
						}
						else {
							im_sign = false;
						}
					}
				}
				for (int i = 0; i < ind; i++) {
					real += s[i];
				}
				for (int i = ind + 1; i < s.length() - 1; i++) {
					imagine += s[i];
				}
				re = stoi(real);
				im = stoi(imagine);
				if (!im_sign) im = -im;

			}

			a.set_complex(re, im);
			p.push_back(a);
			
		}

		file.close();

		for (int i = 0; i < p.size(); i++) {
			p[i].output_complex();
			cout << endl;
		}
		
		break;
	}
	}

}



